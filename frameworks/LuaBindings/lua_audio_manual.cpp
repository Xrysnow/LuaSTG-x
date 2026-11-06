#include "lua_audio_manual.hpp"
#include "lua_conversion/lua_conversion.hpp"
#include "../Classes/XAudioIO.h"
#include "cocos/audio/AudioSoundData.h"

namespace
{

cocos2d::AudioStream* luaAudioInput(lstg::AudioInputResult result)
{
	if (!result)
		return nullptr;
	// Only the AudioStream adapter enters Lua. Its generic io stream has no Lua
	// metadata. Transfer an additional reference to the main-thread pool before
	// the owning result leaves scope; the regular Ref converter then handles Lua.
	auto raw = result.value.get();
	raw->retain();
	raw->autorelease();
	return raw;
}

cocos2d::AudioDecoder* luaAudioDecoder(lstg::AudioDecodeResult result)
{
	// Core decoder creation already registered one pool reference. The new host
	// factory added an independent owning reference, released with this result.
	return result ? result.value.get() : nullptr;
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
	LUA_TRY_INVOKE_R(1, [](cocos2d::AudioSoundData* data) {
		return luaAudioInput(lstg::createAudioInputFromSoundData(data));
	});
	LUA_SINVOKE_FOOTER("1");
}

int lua_audio_Decoder_createFromStringData(lua_State* lua_S)
{
	LUA_SINVOKE_HEADER("cc.AudioDecoder", "cc.AudioDecoder:createFromStringData");
	LUA_TRY_INVOKE_R(3, [](const std::string& bytes, size_t bufferSize, cocos2d::AudioDecoder::DecoderType type) {
		return luaAudioDecoder(lstg::decodeAudioStringData(bytes, bufferSize, type));
	});
	LUA_SINVOKE_FOOTER("3");
}

int lua_audio_Decoder_createFromSoundData(lua_State* lua_S)
{
	LUA_SINVOKE_HEADER("cc.AudioDecoder", "cc.AudioDecoder:createFromSoundData");
	LUA_TRY_INVOKE_R(3, [](cocos2d::AudioSoundData* data, size_t bufferSize, cocos2d::AudioDecoder::DecoderType type) {
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
	lua_getglobal(lua_S, "cc");
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
