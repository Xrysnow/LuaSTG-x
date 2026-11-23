#include "lua_audio_manual.hpp"
#include "lua_conversion/lua_conversion.hpp"
#include "../Classes/XAudioIO.h"
#include "cocos/audio/AudioEngine.h"
#include "cocos/audio/AudioSoundData.h"
#include "LuaBasicConversions.h"
#include <array>
#include <charconv>
#include <cmath>
#include <limits>
#include <new>
#include <string_view>

namespace
{

using namespace cc;

constexpr char directPlaybackType[] = "cc.AudioDirectPlayback";
constexpr std::array channelNames{
	std::pair{AudioChannelPosition::FrontLeft, "frontLeft"},
	std::pair{AudioChannelPosition::FrontRight, "frontRight"},
	std::pair{AudioChannelPosition::FrontCenter, "frontCenter"},
	std::pair{AudioChannelPosition::Lfe, "lfe"},
	std::pair{AudioChannelPosition::RearLeft, "rearLeft"},
	std::pair{AudioChannelPosition::RearRight, "rearRight"},
	std::pair{AudioChannelPosition::SideLeft, "sideLeft"},
	std::pair{AudioChannelPosition::SideRight, "sideRight"},
};

struct LuaDirectPlayback
{
	alignas(AudioDirectPlayback) unsigned char storage[sizeof(AudioDirectPlayback)];
	AudioDirectPlayback* value = nullptr;
};

const char* errorName(AudioOutputError error)
{
	switch (error)
	{
	case AudioOutputError::None: return "None";
	case AudioOutputError::InvalidArgument: return "InvalidArgument";
	case AudioOutputError::Unsupported: return "Unsupported";
	case AudioOutputError::Disconnected: return "Disconnected";
	case AudioOutputError::ChannelManaged: return "ChannelManaged";
	case AudioOutputError::Busy: return "Busy";
	case AudioOutputError::QueueFull: return "QueueFull";
	case AudioOutputError::BackendFailure: return "BackendFailure";
	}
	return "BackendFailure";
}

const char* stateName(AudioPlaybackState state)
{
	switch (state)
	{
	case AudioPlaybackState::Ready: return "ready";
	case AudioPlaybackState::Buffering: return "buffering";
	case AudioPlaybackState::Playing: return "playing";
	case AudioPlaybackState::Paused: return "paused";
	case AudioPlaybackState::Stopped: return "stopped";
	case AudioPlaybackState::Ended: return "ended";
	case AudioPlaybackState::Failed: return "failed";
	case AudioPlaybackState::Closed: return "closed";
	}
	return "failed";
}

int pushControlResult(lua_State* L, AudioOutputError error)
{
	if (error == AudioOutputError::None)
	{
		lua_pushboolean(L, true);
		return 1;
	}
	lua_pushnil(L);
	lua_pushstring(L, errorName(error));
	return 2;
}

AudioDirectPlayback* getPlayback(lua_State* L)
{
	const auto userdata = static_cast<LuaDirectPlayback*>(luaL_testudata(L, 1, directPlaybackType));
	return userdata ? userdata->value : nullptr;
}

int destroyPlayback(lua_State* L)
{
	if (const auto userdata = static_cast<LuaDirectPlayback*>(luaL_testudata(L, 1, directPlaybackType)))
	{
		if (auto playback = std::exchange(userdata->value, nullptr))
			playback->~AudioDirectPlayback();
	}
	return 0;
}

template<AudioOutputError (AudioDirectPlayback::*Method)()>
int controlPlayback(lua_State* L)
{
	auto playback = getPlayback(L);
	return pushControlResult(L, playback ? (playback->*Method)() : AudioOutputError::InvalidArgument);
}

int seekPlayback(lua_State* L)
{
	auto playback = getPlayback(L);
	if (!playback || lua_type(L, 2) != LUA_TNUMBER)
		return pushControlResult(L, AudioOutputError::InvalidArgument);
	return pushControlResult(L, playback->seekTime(lua_tonumber(L, 2)));
}

int setPlaybackLooping(lua_State* L)
{
	auto playback = getPlayback(L);
	if (!playback || !lua_isboolean(L, 2))
		return pushControlResult(L, AudioOutputError::InvalidArgument);
	return pushControlResult(L, playback->setLooping(lua_toboolean(L, 2) != 0));
}

int setPlaybackGain(lua_State* L)
{
	auto playback = getPlayback(L);
	if (!playback || lua_type(L, 2) != LUA_TNUMBER)
		return pushControlResult(L, AudioOutputError::InvalidArgument);
	const auto gain = lua_tonumber(L, 2);
	if (!(gain >= 0 && gain <= std::numeric_limits<float>::max()))
		return pushControlResult(L, AudioOutputError::InvalidArgument);
	return pushControlResult(L, playback->setGain(static_cast<float>(gain)));
}

int closePlayback(lua_State* L)
{
	const auto playback = getPlayback(L);
	if (!playback)
		return pushControlResult(L, AudioOutputError::InvalidArgument);
	playback->close();
	return pushControlResult(L, AudioOutputError::None);
}

int playbackSnapshot(lua_State* L)
{
	const auto playback = getPlayback(L);
	if (!playback)
		return pushControlResult(L, AudioOutputError::InvalidArgument);
	const auto snapshot = playback->snapshot();
	lua_createtable(L, 0, 7);
	lua_pushstring(L, stateName(snapshot.state)); lua_setfield(L, -2, "state");
	lua_pushstring(L, errorName(snapshot.error)); lua_setfield(L, -2, "error");
	lua_pushnumber(L, snapshot.positionSeconds); lua_setfield(L, -2, "positionSeconds");
	if (snapshot.durationSeconds)
	{
		lua_pushnumber(L, *snapshot.durationSeconds);
		lua_setfield(L, -2, "durationSeconds");
	}
	lua_pushnumber(L, snapshot.gain); lua_setfield(L, -2, "gain");
	lua_pushboolean(L, snapshot.looping); lua_setfield(L, -2, "looping");
	lua_pushboolean(L, snapshot.seekable); lua_setfield(L, -2, "seekable");
	return 1;
}

void registerDirectPlayback(lua_State* L)
{
	const luaL_Reg methods[] = {
		{"play", controlPlayback<&AudioDirectPlayback::play>},
		{"pause", controlPlayback<&AudioDirectPlayback::pause>},
		{"resume", controlPlayback<&AudioDirectPlayback::resume>},
		{"stop", controlPlayback<&AudioDirectPlayback::stop>},
		{"seekTime", seekPlayback}, {"setLooping", setPlaybackLooping}, {"setGain", setPlaybackGain},
		{"snapshot", playbackSnapshot}, {"close", closePlayback}, {}
	};
	luaL_newmetatable(L, directPlaybackType);
	lua_pushcfunction(L, destroyPlayback);
	lua_setfield(L, -2, "__gc");
	lua_pushliteral(L, "cc.AudioDirectPlayback");
	lua_setfield(L, -2, "__metatable");
	lua_newtable(L);
	luaL_register(L, nullptr, methods);
	lua_setfield(L, -2, "__index");
	lua_pop(L, 1);
}

void pushEndpointId(lua_State* L, AudioEndpointId id)
{
	constexpr char digits[] = "0123456789abcdef";
	char encoded[16];
	auto value = static_cast<uint64_t>(id);
	for (auto index = sizeof(encoded); index > 0; value >>= 4)
		encoded[--index] = digits[value & 15];
	lua_pushlstring(L, encoded, sizeof(encoded));
}

std::optional<AudioEndpointId> readEndpointId(lua_State* L, int index)
{
	if (lua_type(L, index) != LUA_TSTRING)
		return {};
	size_t size = 0;
	const auto text = lua_tolstring(L, index, &size);
	if (size != 16)
		return {};
	uint64_t number = 0;
	const auto parsed = std::from_chars(text, text + size, number, 16);
	if (parsed.ec != std::errc{} || parsed.ptr != text + size)
		return {};
	return static_cast<AudioEndpointId>(number);
}

std::optional<AudioChannelRoute> readRoute(lua_State* L)
{
	if (!lua_istable(L, -1))
		return {};
	lua_pushliteral(L, "input");
	lua_rawget(L, -2);
	const bool isNumber = lua_type(L, -1) == LUA_TNUMBER;
	const auto input = lua_tonumber(L, -1);
	lua_pop(L, 1);
	if (!isNumber || !(input >= 1 && input <= std::numeric_limits<unsigned>::max()) || std::floor(input) != input)
		return {};
	lua_pushliteral(L, "output");
	lua_rawget(L, -2);
	std::optional<AudioChannelRoute> route;
	if (lua_type(L, -1) == LUA_TSTRING)
	{
		size_t size = 0;
		const char* output = lua_tolstring(L, -1, &size);
		for (const auto& [position, name] : channelNames)
			if (std::string_view(output, size) == name)
				route = AudioChannelRoute{static_cast<unsigned>(input) - 1, position};
	}
	lua_pop(L, 1);
	return route;
}

int getOutputEndpoints(lua_State* L)
{
	tolua_Error typeError{};
	if (lua_gettop(L) != 1 || !tolua_isusertable(L, 1, "cc.AudioEngine", 0, &typeError))
		return pushControlResult(L, AudioOutputError::InvalidArgument);
	const auto endpoints = AudioEngine::getOutputEndpoints();
	if (!endpoints)
		return pushControlResult(L, endpoints.error());
	lua_createtable(L, static_cast<int>(endpoints.value().size()), 0);
	int outputIndex = 0;
	for (const auto& output : endpoints.value())
	{
		lua_createtable(L, 0, 4);
		pushEndpointId(L, output.id); lua_setfield(L, -2, "id");
		lua_pushlstring(L, output.name.data(), output.name.size()); lua_setfield(L, -2, "name");
		lua_pushboolean(L, output.isDefault); lua_setfield(L, -2, "isDefault");
		lua_createtable(L, static_cast<int>(output.channels.size()), 0);
		int channelIndex = 0;
		for (const auto& channel : output.channels)
		{
			for (const auto& [position, name] : channelNames)
			{
				if (channel.position != position)
					continue;
				lua_createtable(L, 0, 2);
				lua_pushstring(L, name); lua_setfield(L, -2, "position");
				lua_pushboolean(L, channel.managed); lua_setfield(L, -2, "managed");
				lua_rawseti(L, -2, ++channelIndex);
				break;
			}
		}
		lua_setfield(L, -2, "channels");
		lua_rawseti(L, -2, ++outputIndex);
	}
	return 1;
}

int createDirectPlayback(lua_State* L)
{
	AudioSource* source = nullptr;
	tolua_Error typeError{};
	if (lua_gettop(L) != 4 || !tolua_isusertable(L, 1, "cc.AudioEngine", 0, &typeError) ||
		!luaval_to_object(L, 2, "cc.AudioSource", &source, "cc.AudioEngine:createDirectPlayback") ||
		!source || !lua_istable(L, 4))
		return pushControlResult(L, AudioOutputError::InvalidArgument);
	const auto id = readEndpointId(L, 3);
	const size_t count = lua_objlen(L, 4);
	if (!id || count == 0 || count > channelNames.size())
		return pushControlResult(L, AudioOutputError::InvalidArgument);
	std::array<AudioChannelRoute, channelNames.size()> routes{};
	size_t seen = 0;
	lua_pushnil(L);
	while (lua_next(L, 4))
	{
		const auto index = lua_tonumber(L, -2);
		if (lua_type(L, -2) != LUA_TNUMBER || !(index >= 1 && index <= count) || std::floor(index) != index)
			return pushControlResult(L, AudioOutputError::InvalidArgument);
		const auto route = readRoute(L);
		if (!route)
			return pushControlResult(L, AudioOutputError::InvalidArgument);
		routes[static_cast<size_t>(index) - 1] = *route;
		++seen;
		lua_pop(L, 1);
	}
	if (seen != count)
		return pushControlResult(L, AudioOutputError::InvalidArgument);
	auto userdata = new (lua_newuserdata(L, sizeof(LuaDirectPlayback))) LuaDirectPlayback;
	luaL_getmetatable(L, directPlaybackType);
	lua_setmetatable(L, -2);
	try
	{
		auto result = AudioEngine::createDirectPlayback(*source, *id, {routes.begin(), routes.begin() + count});
		if (!result)
			return pushControlResult(L, result.error());
		userdata->value = new (userdata->storage) AudioDirectPlayback(std::move(result).value());
		return 1;
	}
	catch (const std::bad_alloc&)
	{
		return pushControlResult(L, AudioOutputError::BackendFailure);
	}
}

cc::IntrusivePtr<cc::AudioStream> luaAudioInput(lstg::AudioInputResult result)
{
    return result ? std::move(result.value).asRef() : nullptr;
}

cc::IntrusivePtr<cc::AudioDecoder> luaAudioDecoder(lstg::AudioDecodeResult result)
{
    return result ? std::move(result.value) : nullptr;
}

int lua_audio_Stream_createFromStringData(lua_State* lua_S)
{
	LUA_SINVOKE_HEADER("cc.AudioStream", "cc.AudioStream:createFromStringData");
	LUA_TRY_INVOKE_R(1, [](const std::string& bytes) {
		return luaAudioInput(lstg::createAudioInputFromStringData(bytes));
	});
	LUA_SINVOKE_FOOTER("1");
}

int lua_audio_Stream_createFromSoundData(lua_State* lua_S)
{
	LUA_SINVOKE_HEADER("cc.AudioStream", "cc.AudioStream:createFromSoundData");
	LUA_TRY_INVOKE_R(1, [](cc::AudioSoundData* data) {
		return luaAudioInput(lstg::createAudioInputFromSoundData(data));
	});
	LUA_SINVOKE_FOOTER("1");
}

int lua_audio_Decoder_createFromStringData(lua_State* lua_S)
{
	LUA_SINVOKE_HEADER("cc.AudioDecoder", "cc.AudioDecoder:createFromStringData");
	LUA_TRY_INVOKE_R(3, [](const std::string& bytes, size_t bufferSize, cc::AudioDecoder::DecoderType type) {
		return luaAudioDecoder(lstg::decodeAudioStringData(bytes, bufferSize, type));
	});
	LUA_SINVOKE_FOOTER("3");
}

int lua_audio_Decoder_createFromSoundData(lua_State* lua_S)
{
	LUA_SINVOKE_HEADER("cc.AudioDecoder", "cc.AudioDecoder:createFromSoundData");
	LUA_TRY_INVOKE_R(3, [](cc::AudioSoundData* data, size_t bufferSize, cc::AudioDecoder::DecoderType type) {
		return luaAudioDecoder(lstg::decodeAudioSoundData(data, bufferSize, type));
	});
	LUA_SINVOKE_FOOTER("3");
}

}

int register_all_cc_audio_manual(lua_State* lua_S)
{
	// Extend the registered classes before sharing their tables with audio.*.
	// No second tolua_cclass/userdata type is created for the project aliases.
	const int top = lua_gettop(lua_S);
	registerDirectPlayback(lua_S);
	lua_getglobal(lua_S, "cc");
	lua_getfield(lua_S, -1, "AudioEngine");
	tolua_function(lua_S, "getOutputEndpoints", getOutputEndpoints);
	tolua_function(lua_S, "createDirectPlayback", createDirectPlayback);
	lua_pop(lua_S, 1);
	lua_getfield(lua_S, -1, "AudioStream");
	tolua_function(lua_S, "createFromStringData", lua_audio_Stream_createFromStringData);
	tolua_function(lua_S, "createFromSoundData", lua_audio_Stream_createFromSoundData);
	lua_pop(lua_S, 1);
	lua_getfield(lua_S, -1, "AudioDecoder");
	tolua_function(lua_S, "createFromStringData", lua_audio_Decoder_createFromStringData);
	tolua_function(lua_S, "createFromSoundData", lua_audio_Decoder_createFromSoundData);
	lua_pop(lua_S, 1);

	lua_getglobal(lua_S, "audio");
	if (!lua_istable(lua_S, -1))
	{
		lua_pop(lua_S, 1);
		lua_newtable(lua_S);
		lua_pushvalue(lua_S, -1);
		lua_setglobal(lua_S, "audio");
	}
	const char* names[] = { "Engine", "Source", "Decoder", "Stream", "SoundData", "RecordingDevice" };
	for (const char* name : names)
	{
		const std::string formalName = std::string("Audio") + name;
		lua_getfield(lua_S, -2, formalName.c_str());
		lua_setfield(lua_S, -2, name);
	}
	lua_settop(lua_S, top);
	return 0;
}
