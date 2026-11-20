#include "lua_TextInput_manual.hpp"

#include "base/Director.h"
#include "base/Macros.h"
#include "platform/GLView.h"
#include "platform/TextInputIndex.h"
#include "platform/TextInputService.h"

extern "C"
{
#include "lua.h"
#include "lauxlib.h"
}

#include <charconv>
#include <cmath>
#include <limits>
#include <new>
#include <string_view>
#include <type_traits>
#include <utility>

namespace
{
	using namespace cc;

	constexpr char sessionType[] = "lstg.TextInputSession";
	char sessionsKey;
	char mainStateKey;
	constexpr lua_Number maxExactInteger = 9007199254740991.0;

	struct LuaSession
	{
		TextInputSession* native = nullptr;
	};

	void pushRegistry(lua_State* L, const void* key)
	{
		lua_pushlightuserdata(L, const_cast<void*>(key));
		lua_rawget(L, LUA_REGISTRYINDEX);
	}

	void readField(lua_State* L, int index, const char* name)
	{
		lua_pushstring(L, name);
		lua_rawget(L, index);
	}

	std::string_view readString(lua_State* L, int index)
	{
		size_t size = 0;
		if (lua_type(L, index) == LUA_TSTRING)
		{
			const char* data = lua_tolstring(L, index, &size);
			return {data, size};
		}
		return {};
	}

	template<class Enum, size_t N>
	bool readEnum(lua_State* L, int table, const char* field, Enum& out, const char* const (&names)[N])
	{
		readField(L, table, field);
		const bool optional = lua_isnil(L, -1);
		const auto value = readString(L, -1);
		lua_pop(L, 1);
		if (optional)
			return true;
		for (size_t i = 0; i < N; ++i)
		{
			if (value == names[i])
			{
				out = static_cast<Enum>(i);
				return true;
			}
		}
		return false;
	}

	template<class Bool>
	bool readBool(lua_State* L, int table, const char* field, Bool& out)
	{
		readField(L, table, field);
		const int type = lua_type(L, -1);
		if (type == LUA_TBOOLEAN)
			out = lua_toboolean(L, -1) != 0;
		lua_pop(L, 1);
		return type == LUA_TNIL || type == LUA_TBOOLEAN;
	}

	template<class UInt>
	bool readInteger(lua_State* L, int index, UInt& out)
	{
		const auto number = lua_tonumber(L, index);
		if (lua_type(L, index) != LUA_TNUMBER || !std::isfinite(number) ||
			number < 0 || number > maxExactInteger ||
			number > static_cast<lua_Number>(std::numeric_limits<UInt>::max()) ||
			number != std::floor(number))
			return false;
		out = static_cast<UInt>(number);
		return true;
	}

	template<class UInt>
	bool readIntegerField(lua_State* L, int table, const char* name, UInt& out)
	{
		readField(L, table, name);
		const bool valid = readInteger(L, -1, out);
		lua_pop(L, 1);
		return valid;
	}

	bool readToken(lua_State* L, int index, std::uint64_t& out)
	{
		const auto value = readString(L, index);
		if (value.empty())
			return false;
		const auto end = value.data() + value.size();
		const auto result = std::from_chars(value.data(), end, out);
		return result.ec == std::errc{} && result.ptr == end && out != 0;
	}

	bool readOptions(lua_State* L, int index, TextInputOptions& options)
	{
		static constexpr const char* purposes[] = {"text", "name", "email", "url", "phone", "number", "decimal", "password"};
		static constexpr const char* capitalizations[] = {"unspecified", "none", "sentences", "words", "characters"};
		static constexpr const char* returnActions[] = {"unspecified", "done", "search", "send", "next", "go"};
		return lua_isnoneornil(L, index) ||
			(lua_istable(L, index) &&
				readEnum(L, index, "purpose", options.purpose, purposes) &&
				readEnum(L, index, "capitalization", options.capitalization, capitalizations) &&
				readEnum(L, index, "returnAction", options.returnAction, returnActions) &&
				readBool(L, index, "multiline", options.multiline) &&
				readBool(L, index, "autocorrect", options.autocorrect) &&
				readBool(L, index, "observePreedit", options.observePreedit) &&
				readBool(L, index, "rangeEdit", options.rangeEdit));
	}

	bool readRect(lua_State* L, int index, TextInputRect& rect)
	{
		if (!lua_istable(L, index))
			return false;

		const auto read = [L, index](const char* name, double& out) {
			readField(L, index, name);
			out = lua_tonumber(L, -1);
			const auto valid = lua_type(L, -1) == LUA_TNUMBER && std::isfinite(out);
			lua_pop(L, 1);
			return valid;
		};
		return read("x", rect.x) && read("y", rect.y) &&
			read("width", rect.width) && read("height", rect.height);
	}

	bool readArea(lua_State* L, int index, std::optional<TextInputArea>& out)
	{
		if (lua_isnoneornil(L, index))
			return true;
		if (!lua_istable(L, index))
			return false;

		auto& area = out.emplace();
		static constexpr const char* spaces[] = {"window", "design"};
		const auto read = [L, index](const char* name, TextInputRect& rect) {
			readField(L, index, name);
			const bool valid = readRect(L, lua_gettop(L), rect);
			lua_pop(L, 1);
			return valid;
		};
		if (!read("caret", area.caret) || !read("line", area.line) ||
			!readEnum(L, index, "space", area.space, spaces))
			return false;

		readField(L, index, "clip");
		const bool valid = lua_isnil(L, -1) || readRect(L, lua_gettop(L), area.clip.emplace());
		lua_pop(L, 1);
		return valid;
	}

	bool readSnapshot(lua_State* L, int index, TextInputSnapshot& snapshot)
	{
		if (!lua_istable(L, index) ||
			!readIntegerField(L, index, "revision", snapshot.revision) ||
			!readIntegerField(L, index, "origin", snapshot.origin) ||
			!readIntegerField(L, index, "anchor", snapshot.anchor) ||
			!readIntegerField(L, index, "focus", snapshot.focus))
			return false;

		readField(L, index, "utf8");
		const bool validText = lua_type(L, -1) == LUA_TSTRING;
		if (validText)
			snapshot.utf8 = readString(L, -1);
		lua_pop(L, 1);
		if (!validText)
			return false;

		readField(L, index, "acknowledgedTransaction");
		const bool valid = lua_isnil(L, -1) || readToken(L, -1, snapshot.acknowledgedTransaction.emplace());
		lua_pop(L, 1);
		return valid;
	}

	int pushFailure(lua_State* L, TextInputError error)
	{
		lua_pushnil(L);
		lua_pushstring(L, textInputErrorName(error));
		return 2;
	}

	int pushResult(lua_State* L, TextInputError error)
	{
		lua_pushboolean(L, error == TextInputError::none);
		if (error == TextInputError::none)
			return 1;
		lua_pushstring(L, textInputErrorName(error));
		return 2;
	}

	void pushToken(lua_State* L, std::uint64_t value)
	{
		char text[20];
		const auto end = std::to_chars(text, text + sizeof(text), value).ptr;
		lua_pushlstring(L, text, end - text);
	}

	void setValue(lua_State* L, const char* field, const char* value)
	{
		lua_pushstring(L, value);
		lua_setfield(L, -2, field);
	}

	void setValue(lua_State* L, const char* field, const std::string& value)
	{
		lua_pushlstring(L, value.data(), value.size());
		lua_setfield(L, -2, field);
	}

	void setNumber(lua_State* L, const char* field, lua_Number value)
	{
		lua_pushnumber(L, value);
		lua_setfield(L, -2, field);
	}

	void setBool(lua_State* L, const char* field, bool value)
	{
		lua_pushboolean(L, value);
		lua_setfield(L, -2, field);
	}

	void setKnowledge(lua_State* L, const char* field, TextInputKnowledge knowledge)
	{
		if (knowledge == TextInputKnowledge::unknown)
			setValue(L, field, "unknown");
		else
			setBool(L, field, knowledge == TextInputKnowledge::yes);
	}

	void setToken(lua_State* L, const char* field, std::uint64_t value)
	{
		pushToken(L, value);
		lua_setfield(L, -2, field);
	}

	void setRect(lua_State* L, const char* field, const TextInputRect& rect)
	{
		lua_createtable(L, 0, 4);
		setNumber(L, "x", rect.x);
		setNumber(L, "y", rect.y);
		setNumber(L, "width", rect.width);
		setNumber(L, "height", rect.height);
		lua_setfield(L, -2, field);
	}

	void pushState(lua_State* L, const TextInputState& state)
	{
		lua_createtable(L, 0, 5);
		setBool(L, "active", state.active);
		setKnowledge(L, "composing", state.composing);
		setKnowledge(L, "imeOpen", state.imeOpen);
		setKnowledge(L, "keyboardVisible", state.keyboardVisible);
		if (state.occlusion)
			setRect(L, "occlusion", *state.occlusion);
	}

	void pushSelection(lua_State* L, const char* field, const TextInputSelection& selection)
	{
		lua_createtable(L, 0, 2);
		setNumber(L, "anchor", static_cast<lua_Number>(selection.anchor));
		setNumber(L, "focus", static_cast<lua_Number>(selection.focus));
		lua_setfield(L, -2, field);
	}

	void pushEvent(lua_State* L, const TextInputEvent& event)
	{
		lua_createtable(L, 0, 8);
		setToken(L, "window", event.window);
		setToken(L, "session", event.session);
		setToken(L, "sequence", event.sequence);
		std::visit([L](const auto& payload) {
			using Payload = std::decay_t<decltype(payload)>;
			if constexpr (std::is_same_v<Payload, TextInputCommit>)
			{
				setValue(L, "kind", "commit");
				setValue(L, "text", payload.text);
			}
			else if constexpr (std::is_same_v<Payload, TextInputEdit>)
			{
				setValue(L, "kind", "edit");
				setNumber(L, "baseRevision", static_cast<lua_Number>(payload.baseRevision));
				setToken(L, "transactionId", payload.transactionId);
				pushSelection(L, "selectionAfter", payload.selectionAfter);
				lua_createtable(L, static_cast<int>(payload.operations.size()), 0);
				int index = 1;
				for (const auto& operation : payload.operations)
				{
					lua_createtable(L, 0, 3);
					setNumber(L, "start", static_cast<lua_Number>(operation.start));
					setNumber(L, "end", static_cast<lua_Number>(operation.end));
					setValue(L, "utf8", operation.utf8);
					lua_rawseti(L, -2, index++);
				}
				lua_setfield(L, -2, "operations");
			}
			else if constexpr (std::is_same_v<Payload, TextInputPreedit>)
			{
				static constexpr const char* phases[] = {"began", "updated", "ended"};
				setValue(L, "kind", "preedit");
				setValue(L, "text", payload.text);
				setValue(L, "phase", phases[static_cast<size_t>(payload.phase)]);
				if (payload.selection)
					pushSelection(L, "selection", *payload.selection);
			}
			else if constexpr (std::is_same_v<Payload, TextInputCommand>)
			{
				static constexpr const char* commands[] = {
					"backspace", "deleteForward", "left", "right", "up", "down", "lineStart", "lineEnd",
					"selectAll", "insertNewline", "done", "search", "send", "next", "go", "cancel"};
				setValue(L, "kind", "command");
				setValue(L, "action", commands[static_cast<size_t>(payload.action)]);
			}
			else if constexpr (std::is_same_v<Payload, TextInputStateChanged>)
			{
				setValue(L, "kind", "stateChanged");
				pushState(L, payload.state);
				lua_setfield(L, -2, "state");
				if (payload.targetOcclusion)
					setRect(L, "targetOcclusion", *payload.targetOcclusion);
				if (payload.animationDuration)
					setNumber(L, "animationDuration", *payload.animationDuration);
			}
			else if constexpr (std::is_same_v<Payload, TextInputClosed>)
			{
				static constexpr const char* reasons[] = {
					"requested", "replaced", "focusLost", "activationFailed", "nativeEnded"};
				setValue(L, "kind", "closed");
				setValue(L, "reason", reasons[static_cast<size_t>(payload.reason)]);
			}
		}, event.payload);
	}

	void clearCallback(lua_State* L, int holder)
	{
		lua_getfenv(L, holder);
		lua_pushnil(L);
		lua_rawseti(L, -2, 1);
		lua_pop(L, 1);
	}

	struct Dispatch
	{
		LuaSession* key;
		const TextInputEvent& event;
	};

	int dispatchEvent(lua_State* L)
	{
		const auto& dispatch = *static_cast<Dispatch*>(lua_touserdata(L, 1));
		pushRegistry(L, &sessionsKey);
		lua_pushlightuserdata(L, dispatch.key);
		lua_rawget(L, 2);
		const auto* holder = static_cast<LuaSession*>(lua_touserdata(L, 3));
		if (!holder || !holder->native || holder->native->id() != dispatch.event.session)
			return 0;

		lua_getfenv(L, 3);
		lua_rawgeti(L, -1, 1);
		if (std::holds_alternative<TextInputClosed>(dispatch.event.payload))
		{
			clearCallback(L, 3);
			lua_pushlightuserdata(L, dispatch.key);
			lua_pushnil(L);
			lua_rawset(L, 2);
		}
		if (lua_isfunction(L, -1))
		{
			pushEvent(L, dispatch.event);
			lua_call(L, 1, 0);
		}
		return 0;
	}

	LuaSession* checkSession(lua_State* L)
	{
		return static_cast<LuaSession*>(luaL_checkudata(L, 1, sessionType));
	}

	int collectSession(lua_State* L)
	{
		auto* holder = checkSession(L);
		delete std::exchange(holder->native, nullptr);
		return 0;
	}

	int setArea(lua_State* L)
	{
		auto* session = checkSession(L)->native;
		std::optional<TextInputArea> area;
		if (!session)
			return pushResult(L, TextInputError::staleSession);
		if (!readArea(L, 2, area))
			return pushResult(L, TextInputError::invalidArea);
		return pushResult(L, session->setArea(area));
	}

	int updateState(lua_State* L)
	{
		auto* session = checkSession(L)->native;
		TextInputSnapshot snapshot;
		if (!session)
			return pushResult(L, TextInputError::staleSession);
		if (!readSnapshot(L, 2, snapshot))
			return pushResult(L, TextInputError::invalidSnapshot);
		return pushResult(L, session->updateState(std::move(snapshot)));
	}

	int capabilities(lua_State* L)
	{
		auto* session = checkSession(L)->native;
		const auto caps = session ? session->capabilities() : TextInputCapabilities{};
		lua_createtable(L, 0, 8);
		setBool(L, "anchor", caps.anchor);
		setBool(L, "observePreedit", caps.observePreedit);
		setBool(L, "rangeEdit", caps.rangeEdit);
		setBool(L, "reconversion", caps.reconversion);
		setBool(L, "keyboardVisibility", caps.keyboardVisibility);
		setBool(L, "keyboardOcclusion", caps.keyboardOcclusion);
		setBool(L, "requestKeyboard", caps.requestKeyboard);
		setBool(L, "cancelComposition", caps.cancelComposition);
		return 1;
	}

	int state(lua_State* L)
	{
		auto* session = checkSession(L)->native;
		pushState(L, session ? session->state() : TextInputState{});
		return 1;
	}

	int requestKeyboard(lua_State* L)
	{
		auto* session = checkSession(L)->native;
		if (!session)
			return pushResult(L, TextInputError::staleSession);
		if (lua_type(L, 2) != LUA_TBOOLEAN)
			return pushResult(L, TextInputError::invalidArgument);
		return pushResult(L, session->requestKeyboard(lua_toboolean(L, 2) != 0));
	}

	int cancelComposition(lua_State* L)
	{
		auto* session = checkSession(L)->native;
		return pushResult(L, session ? session->cancelComposition() : TextInputError::staleSession);
	}

	int close(lua_State* L)
	{
		auto* session = checkSession(L)->native;
		return pushResult(L, session ? session->close() : TextInputError::none);
	}

	int mainWindow(lua_State* L)
	{
		auto* view = Director::getInstance()->getOpenGLView();
		const auto window = view ? view->getTextInputWindow() : 0;
		if (!window)
			return pushFailure(L, TextInputError::invalidWindow);
		pushToken(L, window);
		return 1;
	}

	int begin(lua_State* L)
	{
		auto* view = Director::getInstance()->getOpenGLView();
		if (!view)
			return pushFailure(L, TextInputError::invalidWindow);

		auto window = view->getTextInputWindow();
		if (!lua_isnoneornil(L, 1) && !readToken(L, 1, window))
			return pushFailure(L, TextInputError::invalidWindow);
		TextInputOptions options;
		if (!lua_isfunction(L, 3) || !readOptions(L, 2, options))
			return pushFailure(L, TextInputError::invalidArgument);

		TextInputInitialState initial;
		if (!lua_isnoneornil(L, 4))
		{
			if (!lua_istable(L, 4))
				return pushFailure(L, TextInputError::invalidArgument);
			readField(L, 4, "area");
			const bool validArea = readArea(L, lua_gettop(L), initial.area);
			lua_pop(L, 1);
			if (!validArea)
				return pushFailure(L, TextInputError::invalidArea);
			readField(L, 4, "snapshot");
			const bool validSnapshot = lua_isnil(L, -1) || readSnapshot(L, lua_gettop(L), initial.snapshot.emplace());
			lua_pop(L, 1);
			if (!validSnapshot)
				return pushFailure(L, TextInputError::invalidSnapshot);
		}

		auto* holder = new (lua_newuserdata(L, sizeof(LuaSession))) LuaSession;
		const auto holderIndex = lua_gettop(L);
		luaL_getmetatable(L, sessionType);
		lua_setmetatable(L, holderIndex);
		// Keep the callback owned by the userdata so a closure can capture its own session.
		lua_createtable(L, 1, 0);
		lua_pushvalue(L, 3);
		lua_rawseti(L, -2, 1);
		lua_setfenv(L, holderIndex);

		pushRegistry(L, &sessionsKey);
		lua_pushlightuserdata(L, holder);
		lua_pushvalue(L, holderIndex);
		lua_rawset(L, -3);
		lua_pop(L, 1);

		pushRegistry(L, &mainStateKey);
		auto* main = static_cast<lua_State*>(lua_touserdata(L, -1));
		lua_pop(L, 1);
		auto result = view->getTextInputService().begin(window, options,
			[main, holder](const TextInputEvent& event) {
				Dispatch data{holder, event};
				if (lua_cpcall(main, dispatchEvent, &data) != 0)
				{
					const auto* error = lua_type(main, -1) == LUA_TSTRING ? lua_tostring(main, -1) : nullptr;
					cc::log("lstg.TextInput callback: %s", error ? error : "Lua error");
					lua_pop(main, 1);
				}
			}, std::move(initial));
		if (!result)
		{
			clearCallback(L, holderIndex);
			return pushFailure(L, result.error);
		}
		holder->native = new TextInputSession(std::move(result.session));
		return 1;
	}

	template<TextInputIndexResult (TextInputIndex::*convert)(std::size_t) const>
	int convertOffset(lua_State* L)
	{
		size_t position = 0;
		if (lua_type(L, 1) != LUA_TSTRING || !readInteger(L, 2, position))
			return pushFailure(L, TextInputError::invalidArgument);

		const TextInputIndex index(readString(L, 1));
		const auto result = (index.*convert)(position);
		if (result)
		{
			lua_pushnumber(L, static_cast<lua_Number>(result.offset));
			return 1;
		}
		static constexpr const char* errors[] = {"", "invalidUtf8", "outOfRange", "notBoundary"};
		lua_pushnil(L);
		lua_pushstring(L, errors[static_cast<size_t>(result.error)]);
		return 2;
	}
}

int lstg::registerLuaTextInput(lua_State* L)
{
	static const luaL_Reg sessionMethods[] = {
		{"setArea", setArea},
		{"updateState", updateState},
		{"capabilities", capabilities},
		{"state", state},
		{"requestKeyboard", requestKeyboard},
		{"cancelComposition", cancelComposition},
		{"close", close},
		{nullptr, nullptr}
	};
	static const luaL_Reg moduleMethods[] = {
		{"begin", begin},
		{"mainWindow", mainWindow},
		{"utf8FromScalar", convertOffset<&TextInputIndex::utf8FromScalar>},
		{"scalarFromUtf8", convertOffset<&TextInputIndex::scalarFromUtf8>},
		{nullptr, nullptr}
	};

	pushRegistry(L, &sessionsKey);
	if (lua_isnil(L, -1))
	{
		lua_pushlightuserdata(L, &sessionsKey);
		lua_newtable(L);
		lua_createtable(L, 0, 1);
		lua_pushliteral(L, "v");
		lua_setfield(L, -2, "__mode");
		lua_setmetatable(L, -2);
		lua_rawset(L, LUA_REGISTRYINDEX);

		lua_pushlightuserdata(L, &mainStateKey);
		lua_pushlightuserdata(L, L);
		lua_rawset(L, LUA_REGISTRYINDEX);
	}
	lua_pop(L, 1);

	luaL_newmetatable(L, sessionType);
	lua_pushcfunction(L, collectSession);
	lua_setfield(L, -2, "__gc");
	lua_pushliteral(L, "lstg.TextInputSession");
	lua_setfield(L, -2, "__metatable");
	lua_newtable(L);
	luaL_register(L, nullptr, sessionMethods);
	lua_setfield(L, -2, "__index");
	lua_pop(L, 1);

	luaL_register(L, "lstg.TextInput", moduleMethods);
	lua_pop(L, 1);
	return 0;
}

void lstg::resetLuaTextInput(lua_State* L)
{
	if (!L)
		return;
	pushRegistry(L, &sessionsKey);
	if (lua_istable(L, -1))
	{
		lua_pushnil(L);
		while (lua_next(L, -2))
		{
			auto* holder = static_cast<LuaSession*>(lua_touserdata(L, -1));
			delete std::exchange(holder->native, nullptr);
			clearCallback(L, lua_gettop(L));
			lua_pop(L, 1);
		}
	}
	lua_pop(L, 1);
}
