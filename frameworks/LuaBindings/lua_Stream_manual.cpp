#include "lua_Stream_manual.hpp"
#include "LuaBindings.h"
#include "XBuffer.h"
#include "io/BufferedStream.h"
#include "io/FileStream.h"
#include "io/MemoryStream.h"
#include <algorithm>
#include <cmath>
#include <functional>
#include <limits>
#include <memory>
#include <new>
#include <stdexcept>
#include <string>
#include <vector>

namespace
{
namespace io = cocos2d::io;
using cocos2d::Ref;
using cocos2d::RefPtr;
using lstg::Buffer;
char streamCacheKey;
char integerValidatorKey;

// This class is deliberately private to the binding. Its borrowed memory views
// are synchronous, refreshed after every possible Buffer reallocation, and never
// leave the scripting thread. No old C++ Stream interface remains.
class LuaStreamHandle final : public Ref
{
public:
    io::StreamPtr stream;
    RefPtr<Buffer> buffer;
    int64_t position = 0;
    bool sharedBuffer = false;
    bool ownsStream = false;
    bool closed = false;
    bool locked = false;
    bool memoryType = false;

    ~LuaStreamHandle() override { unlock(); }

    bool isOpen() const { return !closed && (sharedBuffer || (stream && stream->isOpen())); }
    bool writable() const
    {
        return isOpen() && (sharedBuffer ? buffer->isWritable() :
            io::hasCapability(stream->capabilities(), io::Capability::Write));
    }
    bool resizable() const
    {
        return isOpen() && (sharedBuffer ? buffer->isResizable() :
            io::hasCapability(stream->capabilities(), io::Capability::Resize));
    }
    const void* identity() const
    {
        return sharedBuffer ? static_cast<const void*>(buffer.get()) :
            stream ? stream->cursorIdentity() : this;
    }
    // An external Buffer can shrink between calls. Clamp before using its view.
    void clampPosition()
    {
        if (sharedBuffer && static_cast<uint64_t>(position) > buffer->size())
            position = static_cast<int64_t>(buffer->size());
    }
    io::Status refresh()
    {
        if (!isOpen()) return io::Status::failure({io::ErrorCode::Closed});
        if (!sharedBuffer) return io::Status::success();
        clampPosition();
        auto view = buffer->isWritable()
            ? io::MemoryStream::borrowWritable(buffer->data(), buffer->size())
            : io::MemoryStream::borrow(buffer->data(), buffer->size());
        if (!view) return io::Status::failure(view.error);
        auto status = view.value->seek(io::SeekOrigin::Begin, position);
        if (!status) return status;
        stream = std::move(view.value);
        return io::Status::success();
    }
    io::IoResult read(void* out, size_t length)
    {
        const auto status = refresh();
        if (!status) return io::IoResult::failure(status.error);
        auto result = stream->readExact(out, length);
        if (sharedBuffer) position = stream->tell().value;
        return result;
    }
    io::IoResult write(const void* data, size_t length)
    {
        if (!isOpen()) return io::IoResult::failure({io::ErrorCode::Closed});
        if (sharedBuffer)
        {
            clampPosition();
            if (!buffer->isWritable()) return io::IoResult::failure({io::ErrorCode::PermissionDenied});
            if (length > static_cast<uint64_t>(INT64_MAX - position))
                return io::IoResult::failure({io::ErrorCode::Overflow});
            const auto target = static_cast<uint64_t>(position) + length;
            if (target > buffer->size() && buffer->isResizable())
            {
                if (target > std::numeric_limits<size_t>::max())
                    return io::IoResult::failure({io::ErrorCode::Overflow});
                stream.reset();
                buffer->resize(static_cast<size_t>(target));
            }
        }
        const auto status = refresh();
        if (!status) return io::IoResult::failure(status.error);
        auto result = stream->writeAll(data, length);
        if (sharedBuffer) position = stream->tell().value;
        return result;
    }
    io::Status seek(io::SeekOrigin origin, int64_t offset)
    {
        const auto status = refresh();
        if (!status) return status;
        const auto result = stream->seek(origin, offset);
        if (sharedBuffer && result) position = stream->tell().value;
        return result;
    }
    io::Status resize(int64_t length)
    {
        if (!isOpen()) return io::Status::failure({io::ErrorCode::Closed});
        if (!sharedBuffer) return stream->resize(length);
        if (!resizable()) return io::Status::failure({io::ErrorCode::NotSupported});
        if (static_cast<uint64_t>(length) > std::numeric_limits<size_t>::max())
            return io::Status::failure({io::ErrorCode::Overflow});
        stream.reset();
        buffer->resize(static_cast<size_t>(length));
        clampPosition();
        return refresh();
    }
    io::Status flush()
    {
        if (!isOpen()) return io::Status::failure({io::ErrorCode::Closed});
        return sharedBuffer ? io::Status::success() : stream->flush();
    }
    io::Status close()
    {
        if (closed) return io::Status::success();
        if (ownsStream && stream)
        {
            const auto status = stream->close();
            if (!status) return status;
        }
        unlock();
        stream.reset();
        closed = true;
        return io::Status::success();
    }
    bool tryLock()
    {
        if (locked || closed || (!sharedBuffer && !stream)) return false;
        if (!sharedBuffer)
        {
            if (!stream->tryLock()) return false;
            if (!stream->isOpen()) { stream->unlock(); return false; }
        }
        locked = true;
        return true;
    }
    bool lock()
    {
        if (closed || (!sharedBuffer && !stream)) return false;
        if (!sharedBuffer)
        {
            stream->lock();
            if (!stream->isOpen()) { stream->unlock(); return false; }
        }
        locked = true;
        return true;
    }
    void unlock()
    {
        if (!locked) return;
        if (!sharedBuffer && stream) stream->unlock();
        locked = false;
    }
};

// Pin the source while holding its lock, including close/detach operations.
class OperationLock
{
public:
    explicit OperationLock(LuaStreamHandle* handle)
    {
        if (!handle->sharedBuffer && !handle->locked && handle->stream)
        {
            _stream = handle->stream;
            _stream->lock();
        }
    }
    ~OperationLock() { if (_stream) _stream->unlock(); }
private:
    io::StreamPtr _stream;
};

void checkCount(lua_State* L, int minimum, int maximum = -1)
{
    const int count = lua_gettop(L) - 1;
    if (maximum < 0) maximum = minimum;
    if (count < minimum || count > maximum)
        luaL_error(L, "invalid number of arguments to Stream method");
}

LuaStreamHandle* checkHandle(lua_State* L, int index = 1)
{
    // Resolve a .c_instance copy, preserving the original receiver for fluent
    // lock/unlock and Ref methods.
    lua_pushvalue(L, index);
    const bool valid = lua::isusertype(L, -1, "lstg.Stream") != 0;
    auto* result = valid ? static_cast<LuaStreamHandle*>(tolua_tousertype(L, -1, nullptr)) : nullptr;
    lua_pop(L, 1);
    if (!result) luaL_error(L, "invalid Stream object");
    return result;
}

Buffer* checkBuffer(lua_State* L, int index, bool allowNil)
{
    if (allowNil && lua_isnil(L, index)) return nullptr;
    Buffer* result = nullptr;
    lua_pushvalue(L, index);
    const bool valid = lua::luaval_to_native(L, -1, &result) && result;
    lua_pop(L, 1);
    if (!valid) luaL_error(L, "expected lstg.Buffer");
    return result;
}

bool isIntegerCdata(lua_State* L, int index)
{
    // The general binding converter intentionally truncates/wraps numbers. I/O
    // offsets must reject float cdata and uint64 values outside signed range.
    lua_pushlightuserdata(L, &integerValidatorKey);
    lua_rawget(L, LUA_REGISTRYINDEX);
    if (lua_isnil(L, -1))
    {
        lua_pop(L, 1);
        constexpr const char* validator =
            "local ffi=require('ffi'); local istype=ffi.istype; "
            "local signed=ffi.typeof('int64_t'); local unsigned=ffi.typeof('uint64_t'); "
            "local maximum=ffi.new(unsigned,2147483647)*4294967296+4294967295; "
            "local small={}; for _,t in ipairs({'char','int8_t','uint8_t','int16_t','uint16_t','int32_t','uint32_t'}) do "
            "small[#small+1]=ffi.typeof(t) end; "
            "return function(value) if istype(signed,value) then return true end; "
            "if istype(unsigned,value) then return value<=maximum end; "
            "for _,t in ipairs(small) do if istype(t,value) then return true end end; return false end";
        if (luaL_loadstring(L, validator) != 0 || lua_pcall(L, 0, 1, 0) != 0)
        {
            lua_pop(L, 1);
            return false;
        }
        lua_pushlightuserdata(L, &integerValidatorKey);
        lua_pushvalue(L, -2);
        lua_rawset(L, LUA_REGISTRYINDEX);
    }
    lua_pushvalue(L, index);
    if (lua_pcall(L, 1, 1, 0) != 0) { lua_pop(L, 1); return false; }
    const bool valid = lua_toboolean(L, -1) != 0;
    lua_pop(L, 1);
    return valid;
}

int64_t checkInteger(lua_State* L, int index, bool nonnegative)
{
    int64_t result = 0;
    if (lua_type(L, index) == LUA_TNUMBER)
    {
        const double value = lua_tonumber(L, index);
        // Lua numbers outside this range cannot express every byte offset.
        constexpr double exactLimit = 9007199254740991.0;
        if (!std::isfinite(value) || std::floor(value) != value ||
            value < -exactLimit || value > exactLimit)
            luaL_error(L, "expected an exact integer byte count or offset");
        result = static_cast<int64_t>(value);
    }
    else if (lua_type(L, index) != lua::LUA_TCDATA || !isIntegerCdata(L, index) ||
        !lua::luaval_to_native(L, index, &result))
        luaL_error(L, "expected an integer byte count or offset");
    if (nonnegative && result < 0) luaL_error(L, "byte count must not be negative");
    return result;
}

size_t checkSize(lua_State* L, int index)
{
    const auto value = checkInteger(L, index, true);
    if (static_cast<uint64_t>(value) > std::numeric_limits<size_t>::max())
        luaL_error(L, "byte count does not fit this platform");
    return static_cast<size_t>(value);
}

bool checkBoolean(lua_State* L, int index)
{
    if (!lua_isboolean(L, index) && !lua_isnil(L, index))
        luaL_error(L, "expected a boolean");
    return lua_toboolean(L, index) != 0;
}

int pushBoolean(lua_State* L, bool value) { lua_pushboolean(L, value); return 1; }
int pushSelf(lua_State* L) { lua_settop(L, 1); return 1; }

const char* statusName(io::IoStatus status)
{
    switch (status)
    {
    case io::IoStatus::Ok: return "ok";
    case io::IoStatus::EndOfStream: return "eof";
    case io::IoStatus::WouldBlock: return "would_block";
    case io::IoStatus::Cancelled: return "cancelled";
    case io::IoStatus::Timeout: return "timeout";
    default: return "error";
    }
}

void clearGcOwnership(lua_State* L, void* handle)
{
    lua_getfield(L, LUA_REGISTRYINDEX, "tolua_gc");
    lua_pushlightuserdata(L, handle);
    lua_pushnil(L);
    lua_rawset(L, -3);
    lua_pop(L, 1);
}

int collectHandle(lua_State* L)
{
    auto** slot = static_cast<LuaStreamHandle**>(lua_touserdata(L, 1));
    if (slot && *slot)
    {
        auto* handle = *slot;
        *slot = nullptr;
        // Also works with an independent Lua state (no ScriptEngine singleton).
        toluafix_remove_ccobject_by_refid(L, handle->_luaID);
        handle->_luaID = 0;
        handle->unlock();
        handle->release();
    }
    return 0;
}

int pushHandle(lua_State* L, LuaStreamHandle* handle, const char* type)
{
    if (!handle) { lua_pushnil(L); return 1; }
    toluafix_pushusertype_ccobject(L, static_cast<int>(handle->_ID), &handle->_luaID, handle, type);
    // Ref conversion roots userdata, but this object is owned by Lua GC. A
    // manually destroyed predecessor may have used this address; clear its old
    // registration before adopting the new owning reference.
    clearGcOwnership(L, handle);
    tolua_register_gc(L, lua_gettop(L));
    tolua_remove_value_from_root(L, handle);
    return 1;
}

template<int (*Function)(lua_State*)>
int guarded(lua_State* L)
{
    const char* failure = nullptr;
    try { return Function(L); }
    catch (const std::bad_alloc&) { failure = "Stream allocation failed"; }
    catch (const std::length_error&) { failure = "Stream allocation limit exceeded"; }
    catch (const std::exception&) { failure = "Stream operation failed"; }
    // All native exception objects and RAII locals have unwound before longjmp.
    return luaL_error(L, "%s", failure);
}

int createMemory(lua_State* L)
{
    checkCount(L, 0, 2);
    auto* source = lua_gettop(L) >= 2 ? checkBuffer(L, 2, true) : nullptr;
    const bool copy = lua_gettop(L) == 3 && checkBoolean(L, 3);
    std::unique_ptr<LuaStreamHandle> handle(new LuaStreamHandle);
    handle->buffer = source ? (copy ? source->clone() : source) : Buffer::create();
    if (!handle->buffer) { lua_pushnil(L); return 1; }
    handle->sharedBuffer = true;
    handle->memoryType = true;
    return pushHandle(L, handle.release(), "lstg.StreamMemory");
}

int createFile(lua_State* L)
{
    checkCount(L, 2);
    if (lua_type(L, 2) != LUA_TSTRING) return luaL_error(L, "expected a file path string");
    size_t size = 0;
    const char* path = lua_tolstring(L, 2, &size);
    const bool writable = checkBoolean(L, 3);
    io::FileOpenOptions options;
    options.access = writable ? io::FileAccess::ReadWrite : io::FileAccess::Read;
    options.creation = io::FileCreation::OpenExisting;
    const std::string_view name(path, size);
    cocos2d::FileStream::Mode mode;
    auto* files = cocos2d::FileUtils::getInstance();
    if (name.empty() || name.find('\0') != std::string_view::npos || !files ||
        !cocos2d::FileStream::encodeOpenOptions(options, mode))
    { lua_pushnil(L); return 1; }
    // Preserve the old fstream's native-path semantics. Host FileUtils resource
    // lookup classifies package entries as virtual directories, even when an
    // ordinary disk file of the same name exists. The native backend rejects
    // actual directories and still honors the virtual opening hook.
    auto file = io::FileStream::fromBackend(files->openFileStream(name, mode), options);
    if (!file) { lua_pushnil(L); return 1; }
    auto buffered = io::BufferedStream::create(std::move(file.value));
    if (!buffered) { lua_pushnil(L); return 1; }
    std::unique_ptr<LuaStreamHandle> handle(new LuaStreamHandle);
    handle->stream = std::move(buffered.value);
    handle->ownsStream = true;
    return pushHandle(L, handle.release(), "lstg.StreamFile");
}

int getBuffer(lua_State* L)
{
    checkCount(L, 0);
    auto* handle = checkHandle(L);
    if (!handle->memoryType) return luaL_error(L, "getBuffer requires a memory stream");
    OperationLock lock(handle);
    if (!handle->buffer && handle->isOpen())
    {
        const auto* memory = dynamic_cast<io::MemoryStream*>(handle->stream.get());
        if (memory)
        {
            const auto size = memory->size();
            if (size && size.value)
            {
                const auto length = static_cast<size_t>(*size.value);
                // This is a detached snapshot. Even resetting its permission
                // flags cannot mutate an immutable resource cache's storage.
                const std::string bytes(length ? reinterpret_cast<const char*>(memory->data()) : "", length);
                handle->buffer = Buffer::createFromString(bytes);
                if (handle->buffer)
                {
                    handle->buffer->setWritable(false);
                    handle->buffer->setResizable(false);
                }
            }
        }
    }
    lua::native_to_luaval(L, handle->buffer.get());
    return 1;
}

int isOpen(lua_State* L)
{
    checkCount(L, 0); auto* h = checkHandle(L); OperationLock lock(h);
    return pushBoolean(L, h->isOpen());
}
int isWritable(lua_State* L)
{
    checkCount(L, 0); auto* h = checkHandle(L); OperationLock lock(h);
    return pushBoolean(L, h->writable());
}
int isResizable(lua_State* L)
{
    checkCount(L, 0); auto* h = checkHandle(L); OperationLock lock(h);
    return pushBoolean(L, h->resizable());
}
int size(lua_State* L)
{
    checkCount(L, 0); auto* h = checkHandle(L); OperationLock lock(h);
    int64_t value = 0;
    if (h->isOpen())
    {
        if (h->sharedBuffer) value = static_cast<int64_t>(h->buffer->size());
        else { auto result = h->stream->size(); if (result && result.value) value = *result.value; }
    }
    lua_pushnumber(L, static_cast<lua_Number>(value)); return 1;
}
int tell(lua_State* L)
{
    checkCount(L, 0); auto* h = checkHandle(L); OperationLock lock(h);
    int64_t value = 0;
    if (h->isOpen())
    {
        if (h->sharedBuffer) { h->clampPosition(); value = h->position; }
        else { auto result = h->stream->tell(); if (result) value = result.value; }
    }
    lua_pushnumber(L, static_cast<lua_Number>(value)); return 1;
}
int seek(lua_State* L)
{
    checkCount(L, 2); auto* h = checkHandle(L);
    const auto origin = checkInteger(L, 2, false);
    const auto offset = checkInteger(L, 3, false);
    if (origin < 0 || origin > 2) return pushBoolean(L, false);
    OperationLock lock(h);
    return pushBoolean(L, static_cast<bool>(h->seek(static_cast<io::SeekOrigin>(origin), offset)));
}
int resize(lua_State* L)
{
    checkCount(L, 1); auto* h = checkHandle(L); const auto length = checkSize(L, 2);
    OperationLock lock(h);
    return pushBoolean(L, static_cast<bool>(h->resize(static_cast<int64_t>(length))));
}
int flush(lua_State* L)
{
    checkCount(L, 0); auto* h = checkHandle(L); OperationLock lock(h);
    return pushBoolean(L, static_cast<bool>(h->flush()));
}
int close(lua_State* L)
{
    checkCount(L, 0); auto* h = checkHandle(L); OperationLock lock(h);
    return pushBoolean(L, static_cast<bool>(h->close()));
}
int read(lua_State* L)
{
    checkCount(L, 1); auto* h = checkHandle(L); const auto count = checkSize(L, 2);
    OperationLock lock(h);
    std::string result(count, '\0');
    const auto transfer = h->read(result.data(), count);
    result.resize(transfer.transferred);
    lua_pushlstring(L, result.data(), result.size());
    lua_pushstring(L, statusName(transfer.status));
    lua_pushinteger(L, static_cast<int>(transfer.error.code));
    return 3;
}
int write(lua_State* L)
{
    checkCount(L, 1); auto* h = checkHandle(L);
    if (lua_type(L, 2) != LUA_TSTRING) return luaL_error(L, "expected a binary string");
    size_t count = 0; const auto* bytes = lua_tolstring(L, 2, &count);
    OperationLock lock(h);
    const auto transfer = h->write(bytes, count);
    lua_pushnumber(L, static_cast<lua_Number>(transfer.transferred));
    lua_pushstring(L, statusName(transfer.status));
    lua_pushinteger(L, static_cast<int>(transfer.error.code));
    return 3;
}

int fill(lua_State* L)
{
    checkCount(L, 3); auto* source = checkHandle(L); auto* target = checkHandle(L, 2);
    const auto length = static_cast<uint64_t>(checkInteger(L, 3, true));
    auto* scratch = checkBuffer(L, 4, true);
    if (source->identity() == target->identity() ||
        (scratch && (scratch->empty() || !scratch->isWritable() ||
            scratch == source->buffer.get() || scratch == target->buffer.get())))
        return pushBoolean(L, false);
    const bool sourceFirst = std::less<const void*>{}(source->identity(), target->identity());
    OperationLock first(sourceFirst ? source : target);
    OperationLock second(sourceFirst ? target : source);
    if (!source->isOpen() || !target->isOpen()) return pushBoolean(L, false);
    std::vector<uint8_t> fallback;
    if (!scratch) fallback.resize(4096);
    auto* bytes = scratch ? scratch->data() : fallback.data();
    const auto capacity = scratch ? scratch->size() : fallback.size();
    uint64_t total = 0;
    while (total < length)
    {
        const auto wanted = static_cast<size_t>(std::min<uint64_t>(capacity, length - total));
        const auto input = source->read(bytes, wanted);
        if (input.transferred)
        {
            const auto output = target->write(bytes, input.transferred);
            total += output.transferred;
            if (output.status != io::IoStatus::Ok || output.transferred != input.transferred)
                return pushBoolean(L, false);
        }
        if (total == length && !input.error &&
            (input.status == io::IoStatus::Ok || input.status == io::IoStatus::EndOfStream))
            return pushBoolean(L, true);
        if (input.status != io::IoStatus::Ok || input.transferred == 0)
            return pushBoolean(L, false);
    }
    return pushBoolean(L, true);
}

int setBufferSize(lua_State* L)
{
    checkCount(L, 1, 2); auto* h = checkHandle(L);
    const auto readSize = checkSize(L, 2);
    const auto writeSize = lua_gettop(L) == 3 ? checkSize(L, 3) : readSize;
    OperationLock lock(h);
    auto* buffered = dynamic_cast<io::BufferedStream*>(h->stream.get());
    return pushBoolean(L, buffered && static_cast<bool>(buffered->setBufferOptions({readSize, writeSize})));
}
int getBufferSize(lua_State* L)
{
    checkCount(L, 0); auto* h = checkHandle(L); OperationLock lock(h);
    const auto* buffered = dynamic_cast<io::BufferedStream*>(h->stream.get());
    const auto options = buffered ? buffered->getBufferOptions() : io::BufferOptions{0, 0};
    lua_pushnumber(L, static_cast<lua_Number>(options.readCapacity));
    lua_pushnumber(L, static_cast<lua_Number>(options.writeCapacity));
    return 2;
}
int lock(lua_State* L)
{
    checkCount(L, 0); auto* h = checkHandle(L);
    if (h->locked || !h->lock()) return luaL_error(L, "Stream is closed or already locked");
    return pushSelf(L);
}
int tryLock(lua_State* L) { checkCount(L, 0); return pushBoolean(L, checkHandle(L)->tryLock()); }
int unlock(lua_State* L) { checkCount(L, 0); checkHandle(L)->unlock(); return pushSelf(L); }
int retain(lua_State* L) { checkCount(L, 0); checkHandle(L)->retain(); return pushSelf(L); }
int release(lua_State* L)
{
    checkCount(L, 0); auto* h = checkHandle(L);
    if (h->getReferenceCount() == 1)
    {
        clearGcOwnership(L, h);
        toluafix_remove_ccobject_by_refid(L, h->_luaID);
        h->_luaID = 0;
    }
    h->release(); return pushSelf(L);
}
int autorelease(lua_State* L)
{
    checkCount(L, 0); checkHandle(L);
    // GC already owns the automatic release. Scheduling an additional pool
    // release would race with explicit release/GC before that pool drains.
    return pushSelf(L);
}

void registerClass(lua_State* L, const char* name, const char* fullName, const char* base)
{
    tolua_usertype(L, fullName);
    tolua_cclass(L, name, fullName, base, collectHandle);
    tolua_beginmodule(L, name);
}
} // namespace

int pushLuaStream(lua_State* L, cocos2d::io::StreamPtr stream)
{
    if (!stream) { lua_pushnil(L); return 1; }
    // One live handle per native stream keeps getter identity and explicit lock
    // state coherent. Weak values do not extend Lua ownership or pin the stream.
    lua_pushlightuserdata(L, &streamCacheKey);
    lua_rawget(L, LUA_REGISTRYINDEX);
    if (lua_isnil(L, -1))
    {
        lua_pop(L, 1);
        lua_newtable(L);
        lua_newtable(L);
        lua_pushliteral(L, "v"); lua_setfield(L, -2, "__mode");
        lua_setmetatable(L, -2);
        lua_pushlightuserdata(L, &streamCacheKey);
        lua_pushvalue(L, -2);
        lua_rawset(L, LUA_REGISTRYINDEX);
    }
    lua_pushlightuserdata(L, stream.get());
    lua_rawget(L, -2);
    auto* existing = lua::isusertype(L, -1, "lstg.Stream")
        ? static_cast<LuaStreamHandle*>(tolua_tousertype(L, -1, nullptr)) : nullptr;
    if (existing && !existing->closed && existing->stream.get() == stream.get())
    {
        lua_remove(L, -2);
        return 1;
    }
    lua_pop(L, 1);
    const auto* key = stream.get();
    try
    {
        auto handle = std::make_unique<LuaStreamHandle>();
        handle->memoryType = dynamic_cast<io::MemoryStream*>(stream.get()) != nullptr;
        handle->stream = std::move(stream);
        const char* type = handle->memoryType ? "lstg.StreamMemory" : "lstg.Stream";
        pushHandle(L, handle.release(), type);
        lua_pushlightuserdata(L, const_cast<io::Stream*>(key));
        lua_pushvalue(L, -2);
        lua_rawset(L, -4);
        lua_remove(L, -2);
        return 1;
    }
    catch (const std::bad_alloc&) { lua_pop(L, 1); lua_pushnil(L); return 1; }
}

int luaReg_Stream_manual(lua_State* L)
{
    tolua_module(L, "lstg", 0);
    tolua_beginmodule(L, "lstg");
    registerClass(L, "Stream", "lstg.Stream", "cc.Ref");
#define STREAM_METHOD(Name) tolua_function(L, #Name, guarded<Name>)
    STREAM_METHOD(isOpen); STREAM_METHOD(isWritable); STREAM_METHOD(isResizable);
    STREAM_METHOD(size); STREAM_METHOD(tell); STREAM_METHOD(seek); STREAM_METHOD(resize);
    STREAM_METHOD(fill); STREAM_METHOD(read); STREAM_METHOD(write);
    STREAM_METHOD(flush); STREAM_METHOD(close);
    STREAM_METHOD(setBufferSize); STREAM_METHOD(getBufferSize);
    STREAM_METHOD(lock); STREAM_METHOD(tryLock); STREAM_METHOD(unlock);
    STREAM_METHOD(retain); STREAM_METHOD(release); STREAM_METHOD(autorelease);
    tolua_module(L, "SeekOrigin", 0);
    tolua_beginmodule(L, "SeekOrigin");
    tolua_constant(L, "BEG", 0); tolua_constant(L, "CUR", 1); tolua_constant(L, "END", 2);
    tolua_endmodule(L);
    tolua_endmodule(L);
    registerClass(L, "StreamMemory", "lstg.StreamMemory", "lstg.Stream");
    tolua_function(L, "create", guarded<createMemory>);
    STREAM_METHOD(getBuffer);
    tolua_endmodule(L);
    registerClass(L, "StreamFile", "lstg.StreamFile", "lstg.Stream");
    tolua_function(L, "create", guarded<createFile>);
    tolua_endmodule(L);
#undef STREAM_METHOD
    tolua_endmodule(L);
    return 0;
}
