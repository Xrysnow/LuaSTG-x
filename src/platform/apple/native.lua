--
local M = {}
local ffi = require('ffi')
ffi.cdef([[
int32_t NSVersionOfRunTimeLibrary(const char* libraryName);
int32_t NSVersionOfLinkTimeLibrary(const char* libraryName);

int _NSGetExecutablePath(char* buf, uint32_t* bufsize);

double kCFCoreFoundationVersionNumber;

//typedef unsigned char Boolean;
typedef unsigned long CFTypeID;
typedef unsigned long CFOptionFlags;
typedef unsigned long CFHashCode;
typedef signed long CFIndex;

typedef void* CFTypeRef;
typedef void* CFBundleRef;
typedef void* CFURLRef;
typedef void* CFStringRef;
typedef uint32_t CFStringEncoding;

typedef struct {
    CFIndex location;
    CFIndex length;
} CFRange;

void CFRelease(CFTypeRef cf);

CFBundleRef CFBundleGetMainBundle();
CFURLRef CFBundleCopyBundleURL(CFBundleRef bundle);
uint32_t CFBundleGetVersionNumber(CFBundleRef bundle);
CFURLRef CFBundleCopyResourcesDirectoryURL(CFBundleRef bundle);

CFStringRef CFURLGetString(CFURLRef anURL);
bool CFURLGetFileSystemRepresentation(CFURLRef url, bool resolveAgainstBase, uint8_t *buffer, CFIndex maxBufLen);

CFStringRef CFStringCreateWithBytes(
    void* alloc,
    const char *bytes,
    CFIndex numBytes,
    CFStringEncoding encoding,
    bool isExternalRepresentation);
CFIndex CFStringGetBytes(
    CFStringRef theString,
    CFRange range,
    CFStringEncoding encoding,
    uint8_t lossByte,
    bool isExternalRepresentation,
    uint8_t *buffer,
    CFIndex maxBufLen,
    CFIndex *usedBufLen);
CFIndex CFStringGetLength(CFStringRef theString);
]])

function M.getExecutablePath()
    local path = ffi.new('char[512]')
    local size = ffi.new('uint32_t[1]')
    size[0] = 512
    ffi.C._NSGetExecutablePath(path, size)
    return ffi.string(path)
end

function M.getCoreFoundationVersionNumber()
    return ffi.C.kCFCoreFoundationVersionNumber
end

function M.getVersionOfRunTimeLibrary(libraryName)
    assert(type(libraryName) == 'string')
    return ffi.C.NSVersionOfRunTimeLibrary(libraryName)
end

function M.getVersionOfLinkTimeLibrary(libraryName)
    assert(type(libraryName) == 'string')
    return ffi.C.NSVersionOfLinkTimeLibrary(libraryName)
end

local kCFStringEncodingUTF8 = 0x08000100

local function toCFString(s)
    return ffi.C.CFStringCreateWithBytes(nil, s, #s, kCFStringEncodingUTF8, false)
end
local function fromCFString(p)
    assert(p)
    local length = ffi.C.CFStringGetLength(p)
    local range = ffi.new('CFRange')
    range.location = 0
    range.length = length
    local need = ffi.new('CFIndex[1]')
    local ret = ffi.C.CFStringGetBytes(p, range, kCFStringEncodingUTF8, 0, false, nil, 0, need)
    if ret <= 0 then
        -- failed
        return ''
    end
    local size = need[0]
    local buf = ffi.new('uint8_t[?]', size)
    ffi.C.CFStringGetBytes(p, range, kCFStringEncodingUTF8, 0, false, buf, size, need)
    return ffi.string(buf, size)
end

function M.getBundleVersionNumber()
    local b = ffi.C.CFBundleGetMainBundle()
    return ffi.C.CFBundleGetVersionNumber(b)
end

function M.getBundleResourcesDirectory()
    local b = ffi.C.CFBundleGetMainBundle()
    local url = ffi.C.CFBundleCopyResourcesDirectoryURL(b)
    local buf_size = 1024
    local buf = ffi.new('uint8_t[?]', buf_size)
    local ok = ffi.C.CFURLGetFileSystemRepresentation(url, true, buf, buf_size)
    if not ok then
        return ''
    end
    return ffi.string(buf)
end

return M
