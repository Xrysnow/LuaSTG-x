#include "lua_audio_auto.hpp"
#include "lua_conversion/lua_conversion.hpp"
#include "cocos/audio/AudioEngine.h"
#include "lua_audio_manual.hpp"

int lua_cocos2d_AudioSource_clone(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("cc.AudioSource", "cc.AudioSource:clone");
	LUA_TRY_INVOKE_R(0, &cc::AudioSource::clone);
	LUA_INVOKE_FOOTER("0");
}
int lua_cocos2d_AudioSource_getActiveEffects(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("cc.AudioSource", "cc.AudioSource:getActiveEffects");
	LUA_TRY_INVOKE_R(0, &cc::AudioSource::getActiveEffects);
	LUA_INVOKE_FOOTER("0");
}
int lua_cocos2d_AudioSource_getAirAbsorptionFactor(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("cc.AudioSource", "cc.AudioSource:getAirAbsorptionFactor");
	LUA_TRY_INVOKE_R(0, &cc::AudioSource::getAirAbsorptionFactor);
	LUA_INVOKE_FOOTER("0");
}
int lua_cocos2d_AudioSource_getBitDepth(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("cc.AudioSource", "cc.AudioSource:getBitDepth");
	LUA_TRY_INVOKE_R(0, &cc::AudioSource::getBitDepth);
	LUA_INVOKE_FOOTER("0");
}
int lua_cocos2d_AudioSource_getBytesPerFrame(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("cc.AudioSource", "cc.AudioSource:getBytesPerFrame");
	LUA_TRY_INVOKE_R(0, &cc::AudioSource::getBytesPerFrame);
	LUA_INVOKE_FOOTER("0");
}
int lua_cocos2d_AudioSource_getChannelCount(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("cc.AudioSource", "cc.AudioSource:getChannelCount");
	LUA_TRY_INVOKE_R(0, &cc::AudioSource::getChannelCount);
	LUA_INVOKE_FOOTER("0");
}
int lua_cocos2d_AudioSource_getCone(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("cc.AudioSource", "cc.AudioSource:getCone");
	LUA_TRY_INVOKE_R(0, &cc::AudioSource::getCone);
	LUA_INVOKE_FOOTER("0");
}
int lua_cocos2d_AudioSource_getDirection(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("cc.AudioSource", "cc.AudioSource:getDirection");
	LUA_TRY_INVOKE_R(0, &cc::AudioSource::getDirection);
	LUA_INVOKE_FOOTER("0");
}
int lua_cocos2d_AudioSource_getEffect(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("cc.AudioSource", "cc.AudioSource:getEffect");
	LUA_TRY_INVOKE_R(1, &cc::AudioSource::getEffect);
	LUA_INVOKE_FOOTER("1");
}
int lua_cocos2d_AudioSource_getFilter(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("cc.AudioSource", "cc.AudioSource:getFilter");
	LUA_TRY_INVOKE_R(0, &cc::AudioSource::getFilter);
	LUA_INVOKE_FOOTER("0");
}
int lua_cocos2d_AudioSource_getFreeBufferCount(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("cc.AudioSource", "cc.AudioSource:getFreeBufferCount");
	LUA_TRY_INVOKE_R(0, &cc::AudioSource::getFreeBufferCount);
	LUA_INVOKE_FOOTER("0");
}
int lua_cocos2d_AudioSource_getLastError(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("cc.AudioSource", "cc.AudioSource:getLastError");
	LUA_TRY_INVOKE_R(0, &cc::AudioSource::getLastError);
	LUA_INVOKE_FOOTER("0");
}
int lua_cocos2d_AudioSource_getLoopingEnd(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("cc.AudioSource", "cc.AudioSource:getLoopingEnd");
	LUA_TRY_INVOKE_R(0, &cc::AudioSource::getLoopingEnd);
	LUA_INVOKE_FOOTER("0");
}
int lua_cocos2d_AudioSource_getLoopingStart(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("cc.AudioSource", "cc.AudioSource:getLoopingStart");
	LUA_TRY_INVOKE_R(0, &cc::AudioSource::getLoopingStart);
	LUA_INVOKE_FOOTER("0");
}
int lua_cocos2d_AudioSource_getMaxDistance(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("cc.AudioSource", "cc.AudioSource:getMaxDistance");
	LUA_TRY_INVOKE_R(0, &cc::AudioSource::getMaxDistance);
	LUA_INVOKE_FOOTER("0");
}
int lua_cocos2d_AudioSource_getMaxVolume(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("cc.AudioSource", "cc.AudioSource:getMaxVolume");
	LUA_TRY_INVOKE_R(0, &cc::AudioSource::getMaxVolume);
	LUA_INVOKE_FOOTER("0");
}
int lua_cocos2d_AudioSource_getMinVolume(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("cc.AudioSource", "cc.AudioSource:getMinVolume");
	LUA_TRY_INVOKE_R(0, &cc::AudioSource::getMinVolume);
	LUA_INVOKE_FOOTER("0");
}
int lua_cocos2d_AudioSource_getPitch(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("cc.AudioSource", "cc.AudioSource:getPitch");
	LUA_TRY_INVOKE_R(0, &cc::AudioSource::getPitch);
	LUA_INVOKE_FOOTER("0");
}
int lua_cocos2d_AudioSource_getPosition(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("cc.AudioSource", "cc.AudioSource:getPosition");
	LUA_TRY_INVOKE_R(0, &cc::AudioSource::getPosition);
	LUA_INVOKE_FOOTER("0");
}
int lua_cocos2d_AudioSource_getReferenceDistance(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("cc.AudioSource", "cc.AudioSource:getReferenceDistance");
	LUA_TRY_INVOKE_R(0, &cc::AudioSource::getReferenceDistance);
	LUA_INVOKE_FOOTER("0");
}
int lua_cocos2d_AudioSource_getRolloffFactor(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("cc.AudioSource", "cc.AudioSource:getRolloffFactor");
	LUA_TRY_INVOKE_R(0, &cc::AudioSource::getRolloffFactor);
	LUA_INVOKE_FOOTER("0");
}
int lua_cocos2d_AudioSource_getSampleRate(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("cc.AudioSource", "cc.AudioSource:getSampleRate");
	LUA_TRY_INVOKE_R(0, &cc::AudioSource::getSampleRate);
	LUA_INVOKE_FOOTER("0");
}
int lua_cocos2d_AudioSource_getTime(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("cc.AudioSource", "cc.AudioSource:getTime");
	LUA_TRY_INVOKE_R(0, &cc::AudioSource::getTime);
	LUA_INVOKE_FOOTER("0");
}
int lua_cocos2d_AudioSource_getTotalFrames(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("cc.AudioSource", "cc.AudioSource:getTotalFrames");
	LUA_TRY_INVOKE_R(0, &cc::AudioSource::getTotalFrames);
	LUA_INVOKE_FOOTER("0");
}
int lua_cocos2d_AudioSource_getTotalTime(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("cc.AudioSource", "cc.AudioSource:getTotalTime");
	LUA_TRY_INVOKE_R(0, &cc::AudioSource::getTotalTime);
	LUA_INVOKE_FOOTER("0");
}
int lua_cocos2d_AudioSource_getType(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("cc.AudioSource", "cc.AudioSource:getType");
	LUA_TRY_INVOKE_R(0, &cc::AudioSource::getType);
	LUA_INVOKE_FOOTER("0");
}
int lua_cocos2d_AudioSource_getVelocity(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("cc.AudioSource", "cc.AudioSource:getVelocity");
	LUA_TRY_INVOKE_R(0, &cc::AudioSource::getVelocity);
	LUA_INVOKE_FOOTER("0");
}
int lua_cocos2d_AudioSource_getVolume(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("cc.AudioSource", "cc.AudioSource:getVolume");
	LUA_TRY_INVOKE_R(0, &cc::AudioSource::getVolume);
	LUA_INVOKE_FOOTER("0");
}
int lua_cocos2d_AudioSource_isFinished(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("cc.AudioSource", "cc.AudioSource:isFinished");
	LUA_TRY_INVOKE_R(0, &cc::AudioSource::isFinished);
	LUA_INVOKE_FOOTER("0");
}
int lua_cocos2d_AudioSource_isLooping(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("cc.AudioSource", "cc.AudioSource:isLooping");
	LUA_TRY_INVOKE_R(0, &cc::AudioSource::isLooping);
	LUA_INVOKE_FOOTER("0");
}
int lua_cocos2d_AudioSource_isPlaying(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("cc.AudioSource", "cc.AudioSource:isPlaying");
	LUA_TRY_INVOKE_R(0, &cc::AudioSource::isPlaying);
	LUA_INVOKE_FOOTER("0");
}
int lua_cocos2d_AudioSource_isRelative(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("cc.AudioSource", "cc.AudioSource:isRelative");
	LUA_TRY_INVOKE_R(0, &cc::AudioSource::isRelative);
	LUA_INVOKE_FOOTER("0");
}
int lua_cocos2d_AudioSource_isSupportLoopingPoint(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("cc.AudioSource", "cc.AudioSource:isSupportLoopingPoint");
	LUA_TRY_INVOKE_R(0, &cc::AudioSource::isSupportLoopingPoint);
	LUA_INVOKE_FOOTER("0");
}
int lua_cocos2d_AudioSource_pause(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("cc.AudioSource", "cc.AudioSource:pause");
	LUA_TRY_INVOKE(0, &cc::AudioSource::pause);
	LUA_INVOKE_FOOTER("0");
}
int lua_cocos2d_AudioSource_play(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("cc.AudioSource", "cc.AudioSource:play");
	LUA_TRY_INVOKE_R(0, &cc::AudioSource::play);
	LUA_INVOKE_FOOTER("0");
}
int lua_cocos2d_AudioSource_queue(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("cc.AudioSource", "cc.AudioSource:queue");
	LUA_TRY_INVOKE_R(3, &cc::AudioSource::queue);
	LUA_TRY_INVOKE_R(2, ([](cc::AudioSource* obj,cc::AudioSoundData* arg0,ssize_t arg1){{return obj->queue(arg0,std::move(arg1));}}));
	LUA_TRY_INVOKE_R(1, ([](cc::AudioSource* obj,cc::AudioSoundData* arg0){{return obj->queue(arg0);}}));
	LUA_INVOKE_FOOTER("1,2,3");
}
int lua_cocos2d_AudioSource_removeEffect(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("cc.AudioSource", "cc.AudioSource:removeEffect");
	LUA_TRY_INVOKE_R(1, &cc::AudioSource::removeEffect);
	LUA_INVOKE_FOOTER("1");
}
int lua_cocos2d_AudioSource_removeFilter(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("cc.AudioSource", "cc.AudioSource:removeFilter");
	LUA_TRY_INVOKE_R(0, &cc::AudioSource::removeFilter);
	LUA_INVOKE_FOOTER("0");
}
int lua_cocos2d_AudioSource_seek(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("cc.AudioSource", "cc.AudioSource:seek");
	LUA_TRY_INVOKE(1, &cc::AudioSource::seek);
	LUA_INVOKE_FOOTER("1");
}
int lua_cocos2d_AudioSource_setAirAbsorptionFactor(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("cc.AudioSource", "cc.AudioSource:setAirAbsorptionFactor");
	LUA_TRY_INVOKE(1, &cc::AudioSource::setAirAbsorptionFactor);
	LUA_INVOKE_FOOTER("1");
}
int lua_cocos2d_AudioSource_setCone(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("cc.AudioSource", "cc.AudioSource:setCone");
	LUA_TRY_INVOKE(4, (static_cast<void(cc::AudioSource::*)(float, float, float, float)>(&cc::AudioSource::setCone)));
	LUA_TRY_INVOKE(1, (static_cast<void(cc::AudioSource::*)(const std::array<float, 4>&)>(&cc::AudioSource::setCone)));
	LUA_INVOKE_FOOTER("1,4");
}
int lua_cocos2d_AudioSource_setDirection(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("cc.AudioSource", "cc.AudioSource:setDirection");
	LUA_TRY_INVOKE(1, &cc::AudioSource::setDirection);
	LUA_INVOKE_FOOTER("1");
}
int lua_cocos2d_AudioSource_setEffect(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("cc.AudioSource", "cc.AudioSource:setEffect");
	LUA_TRY_INVOKE_R(2, (static_cast<bool(cc::AudioSource::*)(const std::string&, const cc::AudioFilter::ParamMap&)>(&cc::AudioSource::setEffect)));
	LUA_TRY_INVOKE_R(1, static_cast<bool(cc::AudioSource::*)(const std::string&)>(&cc::AudioSource::setEffect));
	LUA_INVOKE_FOOTER("1,2");
}
int lua_cocos2d_AudioSource_setFilter(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("cc.AudioSource", "cc.AudioSource:setFilter");
	LUA_TRY_INVOKE_R(1, &cc::AudioSource::setFilter);
	LUA_INVOKE_FOOTER("1");
}
int lua_cocos2d_AudioSource_setLooping(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("cc.AudioSource", "cc.AudioSource:setLooping");
	LUA_TRY_INVOKE(1, &cc::AudioSource::setLooping);
	LUA_INVOKE_FOOTER("1");
}
int lua_cocos2d_AudioSource_setLoopingPoint(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("cc.AudioSource", "cc.AudioSource:setLoopingPoint");
	LUA_TRY_INVOKE(2, &cc::AudioSource::setLoopingPoint);
	LUA_INVOKE_FOOTER("2");
}
int lua_cocos2d_AudioSource_setMaxDistance(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("cc.AudioSource", "cc.AudioSource:setMaxDistance");
	LUA_TRY_INVOKE(1, &cc::AudioSource::setMaxDistance);
	LUA_INVOKE_FOOTER("1");
}
int lua_cocos2d_AudioSource_setMaxVolume(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("cc.AudioSource", "cc.AudioSource:setMaxVolume");
	LUA_TRY_INVOKE(1, &cc::AudioSource::setMaxVolume);
	LUA_INVOKE_FOOTER("1");
}
int lua_cocos2d_AudioSource_setMinVolume(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("cc.AudioSource", "cc.AudioSource:setMinVolume");
	LUA_TRY_INVOKE(1, &cc::AudioSource::setMinVolume);
	LUA_INVOKE_FOOTER("1");
}
int lua_cocos2d_AudioSource_setPitch(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("cc.AudioSource", "cc.AudioSource:setPitch");
	LUA_TRY_INVOKE(1, &cc::AudioSource::setPitch);
	LUA_INVOKE_FOOTER("1");
}
int lua_cocos2d_AudioSource_setPosition(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("cc.AudioSource", "cc.AudioSource:setPosition");
	LUA_TRY_INVOKE(1, &cc::AudioSource::setPosition);
	LUA_INVOKE_FOOTER("1");
}
int lua_cocos2d_AudioSource_setReferenceDistance(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("cc.AudioSource", "cc.AudioSource:setReferenceDistance");
	LUA_TRY_INVOKE(1, &cc::AudioSource::setReferenceDistance);
	LUA_INVOKE_FOOTER("1");
}
int lua_cocos2d_AudioSource_setRelative(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("cc.AudioSource", "cc.AudioSource:setRelative");
	LUA_TRY_INVOKE(1, &cc::AudioSource::setRelative);
	LUA_INVOKE_FOOTER("1");
}
int lua_cocos2d_AudioSource_setRolloffFactor(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("cc.AudioSource", "cc.AudioSource:setRolloffFactor");
	LUA_TRY_INVOKE(1, &cc::AudioSource::setRolloffFactor);
	LUA_INVOKE_FOOTER("1");
}
int lua_cocos2d_AudioSource_setTime(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("cc.AudioSource", "cc.AudioSource:setTime");
	LUA_TRY_INVOKE(1, &cc::AudioSource::setTime);
	LUA_INVOKE_FOOTER("1");
}
int lua_cocos2d_AudioSource_setVelocity(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("cc.AudioSource", "cc.AudioSource:setVelocity");
	LUA_TRY_INVOKE(1, &cc::AudioSource::setVelocity);
	LUA_INVOKE_FOOTER("1");
}
int lua_cocos2d_AudioSource_setVolume(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("cc.AudioSource", "cc.AudioSource:setVolume");
	LUA_TRY_INVOKE(1, &cc::AudioSource::setVolume);
	LUA_INVOKE_FOOTER("1");
}
int lua_cocos2d_AudioSource_stop(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("cc.AudioSource", "cc.AudioSource:stop");
	LUA_TRY_INVOKE(0, &cc::AudioSource::stop);
	LUA_INVOKE_FOOTER("0");
}
int lua_cocos2d_AudioSource_tell(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("cc.AudioSource", "cc.AudioSource:tell");
	LUA_TRY_INVOKE_R(0, &cc::AudioSource::tell);
	LUA_INVOKE_FOOTER("0");
}
int lua_cocos2d_AudioSource_create(lua_State* lua_S)
{
	LUA_SINVOKE_HEADER("cc.AudioSource", "cc.AudioSource:create");
	LUA_TRY_INVOKE_R(4, &cc::AudioSource::create);
	LUA_SINVOKE_FOOTER("4");
}
int lua_cocos2d_AudioSource_createFromDecoder(lua_State* lua_S)
{
	LUA_SINVOKE_HEADER("cc.AudioSource", "cc.AudioSource:createFromDecoder");
	LUA_TRY_INVOKE_R(1, &cc::AudioSource::createFromDecoder);
	LUA_SINVOKE_FOOTER("1");
}
int lua_cocos2d_AudioSource_createFromSoundData(lua_State* lua_S)
{
	LUA_SINVOKE_HEADER("cc.AudioSource", "cc.AudioSource:createFromSoundData");
	LUA_TRY_INVOKE_R(1, &cc::AudioSource::createFromSoundData);
	LUA_SINVOKE_FOOTER("1");
}
int lua_cocos2d_AudioSource_pauseAll(lua_State* lua_S)
{
	LUA_SINVOKE_HEADER("cc.AudioSource", "cc.AudioSource:pauseAll");
	LUA_TRY_INVOKE_R(0, &cc::AudioSource::pauseAll);
	LUA_SINVOKE_FOOTER("0");
}
int lua_cocos2d_AudioSource_pauseBatch(lua_State* lua_S)
{
	LUA_SINVOKE_HEADER("cc.AudioSource", "cc.AudioSource:pauseBatch");
	LUA_TRY_INVOKE(1, &cc::AudioSource::pauseBatch);
	LUA_SINVOKE_FOOTER("1");
}
int lua_cocos2d_AudioSource_playBatch(lua_State* lua_S)
{
	LUA_SINVOKE_HEADER("cc.AudioSource", "cc.AudioSource:playBatch");
	LUA_TRY_INVOKE_R(1, &cc::AudioSource::playBatch);
	LUA_SINVOKE_FOOTER("1");
}
int lua_cocos2d_AudioSource_stopAll(lua_State* lua_S)
{
	LUA_SINVOKE_HEADER("cc.AudioSource", "cc.AudioSource:stopAll");
	LUA_TRY_INVOKE(0, &cc::AudioSource::stopAll);
	LUA_SINVOKE_FOOTER("0");
}
int lua_cocos2d_AudioSource_stopBatch(lua_State* lua_S)
{
	LUA_SINVOKE_HEADER("cc.AudioSource", "cc.AudioSource:stopBatch");
	LUA_TRY_INVOKE(1, &cc::AudioSource::stopBatch);
	LUA_SINVOKE_FOOTER("1");
}
int luaReg_audio_ccAudioSource(lua_State* lua_S)
{
	LUA_ENTRY("cc");
	LUA_CLS_DEF_BASE(cc::AudioSource, "AudioSource", "cc.AudioSource",
		cc::Ref, "cc.Ref",
		nullptr, nullptr);
	LUA_METHOD("clone", lua_cocos2d_AudioSource_clone);
	LUA_METHOD("getActiveEffects", lua_cocos2d_AudioSource_getActiveEffects);
	LUA_METHOD("getAirAbsorptionFactor", lua_cocos2d_AudioSource_getAirAbsorptionFactor);
	LUA_METHOD("getBitDepth", lua_cocos2d_AudioSource_getBitDepth);
	LUA_METHOD("getBytesPerFrame", lua_cocos2d_AudioSource_getBytesPerFrame);
	LUA_METHOD("getChannelCount", lua_cocos2d_AudioSource_getChannelCount);
	LUA_METHOD("getCone", lua_cocos2d_AudioSource_getCone);
	LUA_METHOD("getDirection", lua_cocos2d_AudioSource_getDirection);
	LUA_METHOD("getEffect", lua_cocos2d_AudioSource_getEffect);
	LUA_METHOD("getFilter", lua_cocos2d_AudioSource_getFilter);
	LUA_METHOD("getFreeBufferCount", lua_cocos2d_AudioSource_getFreeBufferCount);
	LUA_METHOD("getLastError", lua_cocos2d_AudioSource_getLastError);
	LUA_METHOD("getLoopingEnd", lua_cocos2d_AudioSource_getLoopingEnd);
	LUA_METHOD("getLoopingStart", lua_cocos2d_AudioSource_getLoopingStart);
	LUA_METHOD("getMaxDistance", lua_cocos2d_AudioSource_getMaxDistance);
	LUA_METHOD("getMaxVolume", lua_cocos2d_AudioSource_getMaxVolume);
	LUA_METHOD("getMinVolume", lua_cocos2d_AudioSource_getMinVolume);
	LUA_METHOD("getPitch", lua_cocos2d_AudioSource_getPitch);
	LUA_METHOD("getPosition", lua_cocos2d_AudioSource_getPosition);
	LUA_METHOD("getReferenceDistance", lua_cocos2d_AudioSource_getReferenceDistance);
	LUA_METHOD("getRolloffFactor", lua_cocos2d_AudioSource_getRolloffFactor);
	LUA_METHOD("getSampleRate", lua_cocos2d_AudioSource_getSampleRate);
	LUA_METHOD("getTime", lua_cocos2d_AudioSource_getTime);
	LUA_METHOD("getTotalFrames", lua_cocos2d_AudioSource_getTotalFrames);
	LUA_METHOD("getTotalTime", lua_cocos2d_AudioSource_getTotalTime);
	LUA_METHOD("getType", lua_cocos2d_AudioSource_getType);
	LUA_METHOD("getVelocity", lua_cocos2d_AudioSource_getVelocity);
	LUA_METHOD("getVolume", lua_cocos2d_AudioSource_getVolume);
	LUA_METHOD("isFinished", lua_cocos2d_AudioSource_isFinished);
	LUA_METHOD("isLooping", lua_cocos2d_AudioSource_isLooping);
	LUA_METHOD("isPlaying", lua_cocos2d_AudioSource_isPlaying);
	LUA_METHOD("isRelative", lua_cocos2d_AudioSource_isRelative);
	LUA_METHOD("isSupportLoopingPoint", lua_cocos2d_AudioSource_isSupportLoopingPoint);
	LUA_METHOD("pause", lua_cocos2d_AudioSource_pause);
	LUA_METHOD("play", lua_cocos2d_AudioSource_play);
	LUA_METHOD("queue", lua_cocos2d_AudioSource_queue);
	LUA_METHOD("removeEffect", lua_cocos2d_AudioSource_removeEffect);
	LUA_METHOD("removeFilter", lua_cocos2d_AudioSource_removeFilter);
	LUA_METHOD("seek", lua_cocos2d_AudioSource_seek);
	LUA_METHOD("setAirAbsorptionFactor", lua_cocos2d_AudioSource_setAirAbsorptionFactor);
	LUA_METHOD("setCone", lua_cocos2d_AudioSource_setCone);
	LUA_METHOD("setDirection", lua_cocos2d_AudioSource_setDirection);
	LUA_METHOD("setEffect", lua_cocos2d_AudioSource_setEffect);
	LUA_METHOD("setFilter", lua_cocos2d_AudioSource_setFilter);
	LUA_METHOD("setLooping", lua_cocos2d_AudioSource_setLooping);
	LUA_METHOD("setLoopingPoint", lua_cocos2d_AudioSource_setLoopingPoint);
	LUA_METHOD("setMaxDistance", lua_cocos2d_AudioSource_setMaxDistance);
	LUA_METHOD("setMaxVolume", lua_cocos2d_AudioSource_setMaxVolume);
	LUA_METHOD("setMinVolume", lua_cocos2d_AudioSource_setMinVolume);
	LUA_METHOD("setPitch", lua_cocos2d_AudioSource_setPitch);
	LUA_METHOD("setPosition", lua_cocos2d_AudioSource_setPosition);
	LUA_METHOD("setReferenceDistance", lua_cocos2d_AudioSource_setReferenceDistance);
	LUA_METHOD("setRelative", lua_cocos2d_AudioSource_setRelative);
	LUA_METHOD("setRolloffFactor", lua_cocos2d_AudioSource_setRolloffFactor);
	LUA_METHOD("setTime", lua_cocos2d_AudioSource_setTime);
	LUA_METHOD("setVelocity", lua_cocos2d_AudioSource_setVelocity);
	LUA_METHOD("setVolume", lua_cocos2d_AudioSource_setVolume);
	LUA_METHOD("stop", lua_cocos2d_AudioSource_stop);
	LUA_METHOD("tell", lua_cocos2d_AudioSource_tell);
	LUA_METHOD("create", lua_cocos2d_AudioSource_create);
	LUA_METHOD("createFromDecoder", lua_cocos2d_AudioSource_createFromDecoder);
	LUA_METHOD("createFromSoundData", lua_cocos2d_AudioSource_createFromSoundData);
	LUA_METHOD("pauseAll", lua_cocos2d_AudioSource_pauseAll);
	LUA_METHOD("pauseBatch", lua_cocos2d_AudioSource_pauseBatch);
	LUA_METHOD("playBatch", lua_cocos2d_AudioSource_playBatch);
	LUA_METHOD("stopAll", lua_cocos2d_AudioSource_stopAll);
	LUA_METHOD("stopBatch", lua_cocos2d_AudioSource_stopBatch);
	LUA_CLS_END();
	LUA_ENTRY_END(1);
	return 0;
}
int lua_cocos2d_AudioStream_lock(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("cc.AudioStream", "cc.AudioStream:lock");
	LUA_TRY_INVOKE(0, &cc::AudioStream::lock);
	LUA_INVOKE_FOOTER("0");
}
int lua_cocos2d_AudioStream_seek(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("cc.AudioStream", "cc.AudioStream:seek");
	LUA_TRY_INVOKE_R(2, &cc::AudioStream::seek);
	LUA_INVOKE_FOOTER("2");
}
int lua_cocos2d_AudioStream_size(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("cc.AudioStream", "cc.AudioStream:size");
	LUA_TRY_INVOKE_R(0, &cc::AudioStream::size);
	LUA_INVOKE_FOOTER("0");
}
int lua_cocos2d_AudioStream_tell(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("cc.AudioStream", "cc.AudioStream:tell");
	LUA_TRY_INVOKE_R(0, &cc::AudioStream::tell);
	LUA_INVOKE_FOOTER("0");
}
int lua_cocos2d_AudioStream_unlock(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("cc.AudioStream", "cc.AudioStream:unlock");
	LUA_TRY_INVOKE(0, &cc::AudioStream::unlock);
	LUA_INVOKE_FOOTER("0");
}
int lua_cocos2d_AudioStream_createFromFile(lua_State* lua_S)
{
	LUA_SINVOKE_HEADER("cc.AudioStream", "cc.AudioStream:createFromFile");
	LUA_TRY_INVOKE_R(1, &cc::AudioStream::createFromFile);
	LUA_SINVOKE_FOOTER("1");
}
int lua_cocos2d_AudioStream_createFromLocalFile(lua_State* lua_S)
{
	LUA_SINVOKE_HEADER("cc.AudioStream", "cc.AudioStream:createFromLocalFile");
	LUA_TRY_INVOKE_R(1, &cc::AudioStream::createFromLocalFile);
	LUA_SINVOKE_FOOTER("1");
}
int luaReg_audio_ccAudioStream(lua_State* lua_S)
{
	LUA_ENTRY("cc");
	LUA_CLS_DEF_BASE(cc::AudioStream, "AudioStream", "cc.AudioStream",
		cc::Ref, "cc.Ref",
		nullptr, nullptr);
	LUA_METHOD("lock", lua_cocos2d_AudioStream_lock);
	LUA_METHOD("seek", lua_cocos2d_AudioStream_seek);
	LUA_METHOD("size", lua_cocos2d_AudioStream_size);
	LUA_METHOD("tell", lua_cocos2d_AudioStream_tell);
	LUA_METHOD("unlock", lua_cocos2d_AudioStream_unlock);
	LUA_METHOD("createFromFile", lua_cocos2d_AudioStream_createFromFile);
	LUA_METHOD("createFromLocalFile", lua_cocos2d_AudioStream_createFromLocalFile);
	LUA_CLS_END();
	LUA_ENTRY_END(1);
	return 0;
}
int lua_cocos2d_AudioDecoder_DEFAULT_BIT_DEPTH_getter(lua_State* lua_S)
{
	LUA_CUR_FNAME("cc.AudioDecoder.DEFAULT_BIT_DEPTH/getter");
	LUA_PUSH_NATIVE(cc::AudioDecoder::DEFAULT_BIT_DEPTH);
	return 1;
}
int lua_cocos2d_AudioDecoder_DEFAULT_BUFFER_SIZE_getter(lua_State* lua_S)
{
	LUA_CUR_FNAME("cc.AudioDecoder.DEFAULT_BUFFER_SIZE/getter");
	LUA_PUSH_NATIVE(cc::AudioDecoder::DEFAULT_BUFFER_SIZE);
	return 1;
}
int lua_cocos2d_AudioDecoder_DEFAULT_CHANNELS_getter(lua_State* lua_S)
{
	LUA_CUR_FNAME("cc.AudioDecoder.DEFAULT_CHANNELS/getter");
	LUA_PUSH_NATIVE(cc::AudioDecoder::DEFAULT_CHANNELS);
	return 1;
}
int lua_cocos2d_AudioDecoder_DEFAULT_SAMPLE_RATE_getter(lua_State* lua_S)
{
	LUA_CUR_FNAME("cc.AudioDecoder.DEFAULT_SAMPLE_RATE/getter");
	LUA_PUSH_NATIVE(cc::AudioDecoder::DEFAULT_SAMPLE_RATE);
	return 1;
}
int lua_cocos2d_AudioDecoder_clone(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("cc.AudioDecoder", "cc.AudioDecoder:clone");
	LUA_TRY_INVOKE_R(0, &cc::AudioDecoder::clone);
	LUA_INVOKE_FOOTER("0");
}
int lua_cocos2d_AudioDecoder_getBitDepth(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("cc.AudioDecoder", "cc.AudioDecoder:getBitDepth");
	LUA_TRY_INVOKE_R(0, &cc::AudioDecoder::getBitDepth);
	LUA_INVOKE_FOOTER("0");
}
int lua_cocos2d_AudioDecoder_getBufferSize(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("cc.AudioDecoder", "cc.AudioDecoder:getBufferSize");
	LUA_TRY_INVOKE_R(0, &cc::AudioDecoder::getBufferSize);
	LUA_INVOKE_FOOTER("0");
}
int lua_cocos2d_AudioDecoder_getBytesPerFrame(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("cc.AudioDecoder", "cc.AudioDecoder:getBytesPerFrame");
	LUA_TRY_INVOKE_R(0, &cc::AudioDecoder::getBytesPerFrame);
	LUA_INVOKE_FOOTER("0");
}
int lua_cocos2d_AudioDecoder_getChannelCount(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("cc.AudioDecoder", "cc.AudioDecoder:getChannelCount");
	LUA_TRY_INVOKE_R(0, &cc::AudioDecoder::getChannelCount);
	LUA_INVOKE_FOOTER("0");
}
int lua_cocos2d_AudioDecoder_getDuration(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("cc.AudioDecoder", "cc.AudioDecoder:getDuration");
	LUA_TRY_INVOKE_R(0, &cc::AudioDecoder::getDuration);
	LUA_INVOKE_FOOTER("0");
}
int lua_cocos2d_AudioDecoder_getLoopingEnd(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("cc.AudioDecoder", "cc.AudioDecoder:getLoopingEnd");
	LUA_TRY_INVOKE_R(0, &cc::AudioDecoder::getLoopingEnd);
	LUA_INVOKE_FOOTER("0");
}
int lua_cocos2d_AudioDecoder_getLoopingStart(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("cc.AudioDecoder", "cc.AudioDecoder:getLoopingStart");
	LUA_TRY_INVOKE_R(0, &cc::AudioDecoder::getLoopingStart);
	LUA_INVOKE_FOOTER("0");
}
int lua_cocos2d_AudioDecoder_getSampleRate(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("cc.AudioDecoder", "cc.AudioDecoder:getSampleRate");
	LUA_TRY_INVOKE_R(0, &cc::AudioDecoder::getSampleRate);
	LUA_INVOKE_FOOTER("0");
}
int lua_cocos2d_AudioDecoder_getTotalFrames(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("cc.AudioDecoder", "cc.AudioDecoder:getTotalFrames");
	LUA_TRY_INVOKE_R(0, &cc::AudioDecoder::getTotalFrames);
	LUA_INVOKE_FOOTER("0");
}
int lua_cocos2d_AudioDecoder_isFinished(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("cc.AudioDecoder", "cc.AudioDecoder:isFinished");
	LUA_TRY_INVOKE_R(0, &cc::AudioDecoder::isFinished);
	LUA_INVOKE_FOOTER("0");
}
int lua_cocos2d_AudioDecoder_isSeekable(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("cc.AudioDecoder", "cc.AudioDecoder:isSeekable");
	LUA_TRY_INVOKE_R(0, &cc::AudioDecoder::isSeekable);
	LUA_INVOKE_FOOTER("0");
}
int lua_cocos2d_AudioDecoder_rewind(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("cc.AudioDecoder", "cc.AudioDecoder:rewind");
	LUA_TRY_INVOKE_R(0, &cc::AudioDecoder::rewind);
	LUA_INVOKE_FOOTER("0");
}
int lua_cocos2d_AudioDecoder_seek(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("cc.AudioDecoder", "cc.AudioDecoder:seek");
	LUA_TRY_INVOKE_R(1, &cc::AudioDecoder::seek);
	LUA_INVOKE_FOOTER("1");
}
int lua_cocos2d_AudioDecoder_seekTime(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("cc.AudioDecoder", "cc.AudioDecoder:seekTime");
	LUA_TRY_INVOKE_R(1, &cc::AudioDecoder::seekTime);
	LUA_INVOKE_FOOTER("1");
}
int lua_cocos2d_AudioDecoder_tell(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("cc.AudioDecoder", "cc.AudioDecoder:tell");
	LUA_TRY_INVOKE_R(0, &cc::AudioDecoder::tell);
	LUA_INVOKE_FOOTER("0");
}
int lua_cocos2d_AudioDecoder_createFromFile(lua_State* lua_S)
{
	LUA_SINVOKE_HEADER("cc.AudioDecoder", "cc.AudioDecoder:createFromFile");
	LUA_TRY_INVOKE_R(3, &cc::AudioDecoder::createFromFile);
	LUA_TRY_INVOKE_R(2, ([](const std::string& arg0,size_t arg1){{return cc::AudioDecoder::createFromFile(arg0,std::move(arg1));}}));
	LUA_SINVOKE_FOOTER("2,3");
}
int lua_cocos2d_AudioDecoder_createFromLocalFile(lua_State* lua_S)
{
	LUA_SINVOKE_HEADER("cc.AudioDecoder", "cc.AudioDecoder:createFromLocalFile");
	LUA_TRY_INVOKE_R(3, &cc::AudioDecoder::createFromLocalFile);
	LUA_TRY_INVOKE_R(2, ([](const std::string& arg0,size_t arg1){{return cc::AudioDecoder::createFromLocalFile(arg0,std::move(arg1));}}));
	LUA_SINVOKE_FOOTER("2,3");
}
int lua_cocos2d_AudioDecoder_createFromStream(lua_State* lua_S)
{
	LUA_SINVOKE_HEADER("cc.AudioDecoder", "cc.AudioDecoder:createFromStream");
	LUA_TRY_INVOKE_R(3, &cc::AudioDecoder::createFromStream);
	LUA_SINVOKE_FOOTER("3");
}
int lua_cocos2d_AudioDecoder_getDecoderTypeFromPath(lua_State* lua_S)
{
	LUA_SINVOKE_HEADER("cc.AudioDecoder", "cc.AudioDecoder:getDecoderTypeFromPath");
	LUA_TRY_INVOKE_R(1, &cc::AudioDecoder::getDecoderTypeFromPath);
	LUA_SINVOKE_FOOTER("1");
}
int luaReg_audio_ccAudioDecoder(lua_State* lua_S)
{
	LUA_ENTRY("cc");
	LUA_CLS_DEF_BASE(cc::AudioDecoder, "AudioDecoder", "cc.AudioDecoder",
		cc::Ref, "cc.Ref",
		nullptr, nullptr);
	LUA_SFIELD("DEFAULT_BIT_DEPTH", lua_cocos2d_AudioDecoder_DEFAULT_BIT_DEPTH_getter, nullptr);
	LUA_SFIELD("DEFAULT_BUFFER_SIZE", lua_cocos2d_AudioDecoder_DEFAULT_BUFFER_SIZE_getter, nullptr);
	LUA_SFIELD("DEFAULT_CHANNELS", lua_cocos2d_AudioDecoder_DEFAULT_CHANNELS_getter, nullptr);
	LUA_SFIELD("DEFAULT_SAMPLE_RATE", lua_cocos2d_AudioDecoder_DEFAULT_SAMPLE_RATE_getter, nullptr);
	LUA_METHOD("clone", lua_cocos2d_AudioDecoder_clone);
	LUA_METHOD("getBitDepth", lua_cocos2d_AudioDecoder_getBitDepth);
	LUA_METHOD("getBufferSize", lua_cocos2d_AudioDecoder_getBufferSize);
	LUA_METHOD("getBytesPerFrame", lua_cocos2d_AudioDecoder_getBytesPerFrame);
	LUA_METHOD("getChannelCount", lua_cocos2d_AudioDecoder_getChannelCount);
	LUA_METHOD("getDuration", lua_cocos2d_AudioDecoder_getDuration);
	LUA_METHOD("getLoopingEnd", lua_cocos2d_AudioDecoder_getLoopingEnd);
	LUA_METHOD("getLoopingStart", lua_cocos2d_AudioDecoder_getLoopingStart);
	LUA_METHOD("getSampleRate", lua_cocos2d_AudioDecoder_getSampleRate);
	LUA_METHOD("getTotalFrames", lua_cocos2d_AudioDecoder_getTotalFrames);
	LUA_METHOD("isFinished", lua_cocos2d_AudioDecoder_isFinished);
	LUA_METHOD("isSeekable", lua_cocos2d_AudioDecoder_isSeekable);
	LUA_METHOD("rewind", lua_cocos2d_AudioDecoder_rewind);
	LUA_METHOD("seek", lua_cocos2d_AudioDecoder_seek);
	LUA_METHOD("seekTime", lua_cocos2d_AudioDecoder_seekTime);
	LUA_METHOD("tell", lua_cocos2d_AudioDecoder_tell);
	LUA_METHOD("createFromFile", lua_cocos2d_AudioDecoder_createFromFile);
	LUA_METHOD("createFromLocalFile", lua_cocos2d_AudioDecoder_createFromLocalFile);
	LUA_METHOD("createFromStream", lua_cocos2d_AudioDecoder_createFromStream);
	LUA_METHOD("getDecoderTypeFromPath", lua_cocos2d_AudioDecoder_getDecoderTypeFromPath);
	LUA_CLS_END();
	LUA_ENTRY_END(1);
	return 0;
}
int lua_cocos2d_AudioSoundData_clone(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("cc.AudioSoundData", "cc.AudioSoundData:clone");
	LUA_TRY_INVOKE_R(0, &cc::AudioSoundData::clone);
	LUA_INVOKE_FOOTER("0");
}
int lua_cocos2d_AudioSoundData_getBitDepth(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("cc.AudioSoundData", "cc.AudioSoundData:getBitDepth");
	LUA_TRY_INVOKE_R(0, &cc::AudioSoundData::getBitDepth);
	LUA_INVOKE_FOOTER("0");
}
int lua_cocos2d_AudioSoundData_getChannelCount(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("cc.AudioSoundData", "cc.AudioSoundData:getChannelCount");
	LUA_TRY_INVOKE_R(0, &cc::AudioSoundData::getChannelCount);
	LUA_INVOKE_FOOTER("0");
}
int lua_cocos2d_AudioSoundData_getDuration(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("cc.AudioSoundData", "cc.AudioSoundData:getDuration");
	LUA_TRY_INVOKE_R(0, &cc::AudioSoundData::getDuration);
	LUA_INVOKE_FOOTER("0");
}
int lua_cocos2d_AudioSoundData_getLastError(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("cc.AudioSoundData", "cc.AudioSoundData:getLastError");
	LUA_TRY_INVOKE_R(0, &cc::AudioSoundData::getLastError);
	LUA_INVOKE_FOOTER("0");
}
int lua_cocos2d_AudioSoundData_getSample(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("cc.AudioSoundData", "cc.AudioSoundData:getSample");
	LUA_TRY_INVOKE_R(2, (static_cast<float(cc::AudioSoundData::*)(int, int)>(&cc::AudioSoundData::getSample)));
	LUA_TRY_INVOKE_R(1, static_cast<float(cc::AudioSoundData::*)(int)>(&cc::AudioSoundData::getSample));
	LUA_INVOKE_FOOTER("1,2");
}
int lua_cocos2d_AudioSoundData_getSampleCount(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("cc.AudioSoundData", "cc.AudioSoundData:getSampleCount");
	LUA_TRY_INVOKE_R(0, &cc::AudioSoundData::getSampleCount);
	LUA_INVOKE_FOOTER("0");
}
int lua_cocos2d_AudioSoundData_getSampleRate(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("cc.AudioSoundData", "cc.AudioSoundData:getSampleRate");
	LUA_TRY_INVOKE_R(0, &cc::AudioSoundData::getSampleRate);
	LUA_INVOKE_FOOTER("0");
}
int lua_cocos2d_AudioSoundData_getSize(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("cc.AudioSoundData", "cc.AudioSoundData:getSize");
	LUA_TRY_INVOKE_R(0, &cc::AudioSoundData::getSize);
	LUA_INVOKE_FOOTER("0");
}
int lua_cocos2d_AudioSoundData_setSample(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("cc.AudioSoundData", "cc.AudioSoundData:setSample");
	LUA_TRY_INVOKE(3, (static_cast<void(cc::AudioSoundData::*)(int, int, float)>(&cc::AudioSoundData::setSample)));
	LUA_TRY_INVOKE(2, (static_cast<void(cc::AudioSoundData::*)(int, float)>(&cc::AudioSoundData::setSample)));
	LUA_INVOKE_FOOTER("2,3");
}
int luaReg_audio_ccAudioSoundData(lua_State* lua_S)
{
	LUA_ENTRY("cc");
	LUA_CLS_DEF(cc::AudioSoundData, "AudioSoundData", "cc.AudioSoundData",
		nullptr, nullptr);
	LUA_METHOD("clone", lua_cocos2d_AudioSoundData_clone);
	LUA_METHOD("getBitDepth", lua_cocos2d_AudioSoundData_getBitDepth);
	LUA_METHOD("getChannelCount", lua_cocos2d_AudioSoundData_getChannelCount);
	LUA_METHOD("getDuration", lua_cocos2d_AudioSoundData_getDuration);
	LUA_METHOD("getLastError", lua_cocos2d_AudioSoundData_getLastError);
	LUA_METHOD("getSample", lua_cocos2d_AudioSoundData_getSample);
	LUA_METHOD("getSampleCount", lua_cocos2d_AudioSoundData_getSampleCount);
	LUA_METHOD("getSampleRate", lua_cocos2d_AudioSoundData_getSampleRate);
	LUA_METHOD("getSize", lua_cocos2d_AudioSoundData_getSize);
	LUA_METHOD("setSample", lua_cocos2d_AudioSoundData_setSample);
	LUA_CLS_END();
	LUA_ENTRY_END(1);
	return 0;
}
int lua_cocos2d_AudioRecordingDevice_DEFAULT_BIT_DEPTH_getter(lua_State* lua_S)
{
	LUA_CUR_FNAME("cc.AudioRecordingDevice.DEFAULT_BIT_DEPTH/getter");
	LUA_PUSH_NATIVE(cc::AudioRecordingDevice::DEFAULT_BIT_DEPTH);
	return 1;
}
int lua_cocos2d_AudioRecordingDevice_DEFAULT_CHANNELS_getter(lua_State* lua_S)
{
	LUA_CUR_FNAME("cc.AudioRecordingDevice.DEFAULT_CHANNELS/getter");
	LUA_PUSH_NATIVE(cc::AudioRecordingDevice::DEFAULT_CHANNELS);
	return 1;
}
int lua_cocos2d_AudioRecordingDevice_DEFAULT_SAMPLES_getter(lua_State* lua_S)
{
	LUA_CUR_FNAME("cc.AudioRecordingDevice.DEFAULT_SAMPLES/getter");
	LUA_PUSH_NATIVE(cc::AudioRecordingDevice::DEFAULT_SAMPLES);
	return 1;
}
int lua_cocos2d_AudioRecordingDevice_DEFAULT_SAMPLE_RATE_getter(lua_State* lua_S)
{
	LUA_CUR_FNAME("cc.AudioRecordingDevice.DEFAULT_SAMPLE_RATE/getter");
	LUA_PUSH_NATIVE(cc::AudioRecordingDevice::DEFAULT_SAMPLE_RATE);
	return 1;
}
int lua_cocos2d_AudioRecordingDevice_getBitDepth(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("cc.AudioRecordingDevice", "cc.AudioRecordingDevice:getBitDepth");
	LUA_TRY_INVOKE_R(0, &cc::AudioRecordingDevice::getBitDepth);
	LUA_INVOKE_FOOTER("0");
}
int lua_cocos2d_AudioRecordingDevice_getChannelCount(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("cc.AudioRecordingDevice", "cc.AudioRecordingDevice:getChannelCount");
	LUA_TRY_INVOKE_R(0, &cc::AudioRecordingDevice::getChannelCount);
	LUA_INVOKE_FOOTER("0");
}
int lua_cocos2d_AudioRecordingDevice_getData(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("cc.AudioRecordingDevice", "cc.AudioRecordingDevice:getData");
	LUA_TRY_INVOKE_R(0, &cc::AudioRecordingDevice::getData);
	LUA_INVOKE_FOOTER("0");
}
int lua_cocos2d_AudioRecordingDevice_getMaxSamples(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("cc.AudioRecordingDevice", "cc.AudioRecordingDevice:getMaxSamples");
	LUA_TRY_INVOKE_R(0, &cc::AudioRecordingDevice::getMaxSamples);
	LUA_INVOKE_FOOTER("0");
}
int lua_cocos2d_AudioRecordingDevice_getName(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("cc.AudioRecordingDevice", "cc.AudioRecordingDevice:getName");
	LUA_TRY_INVOKE_R(0, &cc::AudioRecordingDevice::getName);
	LUA_INVOKE_FOOTER("0");
}
int lua_cocos2d_AudioRecordingDevice_getSampleCount(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("cc.AudioRecordingDevice", "cc.AudioRecordingDevice:getSampleCount");
	LUA_TRY_INVOKE_R(0, &cc::AudioRecordingDevice::getSampleCount);
	LUA_INVOKE_FOOTER("0");
}
int lua_cocos2d_AudioRecordingDevice_getSampleRate(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("cc.AudioRecordingDevice", "cc.AudioRecordingDevice:getSampleRate");
	LUA_TRY_INVOKE_R(0, &cc::AudioRecordingDevice::getSampleRate);
	LUA_INVOKE_FOOTER("0");
}
int lua_cocos2d_AudioRecordingDevice_isRecording(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("cc.AudioRecordingDevice", "cc.AudioRecordingDevice:isRecording");
	LUA_TRY_INVOKE_R(0, &cc::AudioRecordingDevice::isRecording);
	LUA_INVOKE_FOOTER("0");
}
int lua_cocos2d_AudioRecordingDevice_start(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("cc.AudioRecordingDevice", "cc.AudioRecordingDevice:start");
	LUA_TRY_INVOKE_R(4, &cc::AudioRecordingDevice::start);
	LUA_INVOKE_FOOTER("4");
}
int lua_cocos2d_AudioRecordingDevice_stop(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("cc.AudioRecordingDevice", "cc.AudioRecordingDevice:stop");
	LUA_TRY_INVOKE(0, &cc::AudioRecordingDevice::stop);
	LUA_INVOKE_FOOTER("0");
}
int luaReg_audio_ccAudioRecordingDevice(lua_State* lua_S)
{
	LUA_ENTRY("cc");
	LUA_CLS_DEF_BASE(cc::AudioRecordingDevice, "AudioRecordingDevice", "cc.AudioRecordingDevice",
		cc::Ref, "cc.Ref",
		nullptr, nullptr);
	LUA_SFIELD("DEFAULT_BIT_DEPTH", lua_cocos2d_AudioRecordingDevice_DEFAULT_BIT_DEPTH_getter, nullptr);
	LUA_SFIELD("DEFAULT_CHANNELS", lua_cocos2d_AudioRecordingDevice_DEFAULT_CHANNELS_getter, nullptr);
	LUA_SFIELD("DEFAULT_SAMPLES", lua_cocos2d_AudioRecordingDevice_DEFAULT_SAMPLES_getter, nullptr);
	LUA_SFIELD("DEFAULT_SAMPLE_RATE", lua_cocos2d_AudioRecordingDevice_DEFAULT_SAMPLE_RATE_getter, nullptr);
	LUA_METHOD("getBitDepth", lua_cocos2d_AudioRecordingDevice_getBitDepth);
	LUA_METHOD("getChannelCount", lua_cocos2d_AudioRecordingDevice_getChannelCount);
	LUA_METHOD("getData", lua_cocos2d_AudioRecordingDevice_getData);
	LUA_METHOD("getMaxSamples", lua_cocos2d_AudioRecordingDevice_getMaxSamples);
	LUA_METHOD("getName", lua_cocos2d_AudioRecordingDevice_getName);
	LUA_METHOD("getSampleCount", lua_cocos2d_AudioRecordingDevice_getSampleCount);
	LUA_METHOD("getSampleRate", lua_cocos2d_AudioRecordingDevice_getSampleRate);
	LUA_METHOD("isRecording", lua_cocos2d_AudioRecordingDevice_isRecording);
	LUA_METHOD("start", lua_cocos2d_AudioRecordingDevice_start);
	LUA_METHOD("stop", lua_cocos2d_AudioRecordingDevice_stop);
	LUA_CLS_END();
	LUA_ENTRY_END(1);
	return 0;
}
int lua_cocos2d_AudioEngine_getActiveEffects(lua_State* lua_S)
{
	LUA_SINVOKE_HEADER("cc.AudioEngine", "cc.AudioEngine:getActiveEffects");
	LUA_TRY_INVOKE_R(0, &cc::AudioEngine::getActiveEffects);
	LUA_SINVOKE_FOOTER("0");
}
int lua_cocos2d_AudioEngine_getActiveSourceCount(lua_State* lua_S)
{
	LUA_SINVOKE_HEADER("cc.AudioEngine", "cc.AudioEngine:getActiveSourceCount");
	LUA_TRY_INVOKE_R(0, &cc::AudioEngine::getActiveSourceCount);
	LUA_SINVOKE_FOOTER("0");
}
int lua_cocos2d_AudioEngine_getDistanceModel(lua_State* lua_S)
{
	LUA_SINVOKE_HEADER("cc.AudioEngine", "cc.AudioEngine:getDistanceModel");
	LUA_TRY_INVOKE_R(0, &cc::AudioEngine::getDistanceModel);
	LUA_SINVOKE_FOOTER("0");
}
int lua_cocos2d_AudioEngine_getDopplerScale(lua_State* lua_S)
{
	LUA_SINVOKE_HEADER("cc.AudioEngine", "cc.AudioEngine:getDopplerScale");
	LUA_TRY_INVOKE_R(0, &cc::AudioEngine::getDopplerScale);
	LUA_SINVOKE_FOOTER("0");
}
int lua_cocos2d_AudioEngine_getEffect(lua_State* lua_S)
{
	LUA_SINVOKE_HEADER("cc.AudioEngine", "cc.AudioEngine:getEffect");
	LUA_TRY_INVOKE_R(1, &cc::AudioEngine::getEffect);
	LUA_SINVOKE_FOOTER("1");
}
int lua_cocos2d_AudioEngine_getEffectID(lua_State* lua_S)
{
	LUA_SINVOKE_HEADER("cc.AudioEngine", "cc.AudioEngine:getEffectID");
	LUA_TRY_INVOKE_R(2, &cc::AudioEngine::getEffectID);
	LUA_SINVOKE_FOOTER("2");
}
int lua_cocos2d_AudioEngine_getFormat(lua_State* lua_S)
{
	LUA_SINVOKE_HEADER("cc.AudioEngine", "cc.AudioEngine:getFormat");
	LUA_TRY_INVOKE_R(2, &cc::AudioEngine::getFormat);
	LUA_SINVOKE_FOOTER("2");
}
int lua_cocos2d_AudioEngine_getLastError(lua_State* lua_S)
{
	LUA_SINVOKE_HEADER("cc.AudioEngine", "cc.AudioEngine:getLastError");
	LUA_TRY_INVOKE_R(0, &cc::AudioEngine::getLastError);
	LUA_SINVOKE_FOOTER("0");
}
int lua_cocos2d_AudioEngine_getMaxEffectCount(lua_State* lua_S)
{
	LUA_SINVOKE_HEADER("cc.AudioEngine", "cc.AudioEngine:getMaxEffectCount");
	LUA_TRY_INVOKE_R(0, &cc::AudioEngine::getMaxEffectCount);
	LUA_SINVOKE_FOOTER("0");
}
int lua_cocos2d_AudioEngine_getMaxSourceCount(lua_State* lua_S)
{
	LUA_SINVOKE_HEADER("cc.AudioEngine", "cc.AudioEngine:getMaxSourceCount");
	LUA_TRY_INVOKE_R(0, &cc::AudioEngine::getMaxSourceCount);
	LUA_SINVOKE_FOOTER("0");
}
int lua_cocos2d_AudioEngine_getMaxSourceEffectCount(lua_State* lua_S)
{
	LUA_SINVOKE_HEADER("cc.AudioEngine", "cc.AudioEngine:getMaxSourceEffectCount");
	LUA_TRY_INVOKE_R(0, &cc::AudioEngine::getMaxSourceEffectCount);
	LUA_SINVOKE_FOOTER("0");
}
int lua_cocos2d_AudioEngine_getOrientation(lua_State* lua_S)
{
	LUA_SINVOKE_HEADER("cc.AudioEngine", "cc.AudioEngine:getOrientation");
	LUA_TRY_INVOKE_R(0, &cc::AudioEngine::getOrientation);
	LUA_SINVOKE_FOOTER("0");
}
int lua_cocos2d_AudioEngine_getPosition(lua_State* lua_S)
{
	LUA_SINVOKE_HEADER("cc.AudioEngine", "cc.AudioEngine:getPosition");
	LUA_TRY_INVOKE_R(0, &cc::AudioEngine::getPosition);
	LUA_SINVOKE_FOOTER("0");
}
int lua_cocos2d_AudioEngine_getRecordingDevices(lua_State* lua_S)
{
	LUA_SINVOKE_HEADER("cc.AudioEngine", "cc.AudioEngine:getRecordingDevices");
	LUA_TRY_INVOKE_R(0, &cc::AudioEngine::getRecordingDevices);
	LUA_SINVOKE_FOOTER("0");
}
int lua_cocos2d_AudioEngine_getVelocity(lua_State* lua_S)
{
	LUA_SINVOKE_HEADER("cc.AudioEngine", "cc.AudioEngine:getVelocity");
	LUA_TRY_INVOKE_R(0, &cc::AudioEngine::getVelocity);
	LUA_SINVOKE_FOOTER("0");
}
int lua_cocos2d_AudioEngine_getVolume(lua_State* lua_S)
{
	LUA_SINVOKE_HEADER("cc.AudioEngine", "cc.AudioEngine:getVolume");
	LUA_TRY_INVOKE_R(0, &cc::AudioEngine::getVolume);
	LUA_SINVOKE_FOOTER("0");
}
int lua_cocos2d_AudioEngine_isEffectSupported(lua_State* lua_S)
{
	LUA_SINVOKE_HEADER("cc.AudioEngine", "cc.AudioEngine:isEffectSupported");
	LUA_TRY_INVOKE_R(0, &cc::AudioEngine::isEffectSupported);
	LUA_SINVOKE_FOOTER("0");
}
int lua_cocos2d_AudioEngine_isValid(lua_State* lua_S)
{
	LUA_SINVOKE_HEADER("cc.AudioEngine", "cc.AudioEngine:isValid");
	LUA_TRY_INVOKE_R(0, &cc::AudioEngine::isValid);
	LUA_SINVOKE_FOOTER("0");
}
int lua_cocos2d_AudioEngine_onEnterBackground(lua_State* lua_S)
{
	LUA_SINVOKE_HEADER("cc.AudioEngine", "cc.AudioEngine:onEnterBackground");
	LUA_TRY_INVOKE(0, &cc::AudioEngine::onEnterBackground);
	LUA_SINVOKE_FOOTER("0");
}
int lua_cocos2d_AudioEngine_onEnterForeground(lua_State* lua_S)
{
	LUA_SINVOKE_HEADER("cc.AudioEngine", "cc.AudioEngine:onEnterForeground");
	LUA_TRY_INVOKE(0, &cc::AudioEngine::onEnterForeground);
	LUA_SINVOKE_FOOTER("0");
}
int lua_cocos2d_AudioEngine_pause(lua_State* lua_S)
{
	LUA_SINVOKE_HEADER("cc.AudioEngine", "cc.AudioEngine:pause");
	LUA_TRY_INVOKE(1, static_cast<void(*)(const std::vector<cc::AudioSource *>&)>(&cc::AudioEngine::pause));
	LUA_TRY_INVOKE_R(0, static_cast<std::vector<cc::AudioSource *>(*)()>(&cc::AudioEngine::pause));
	LUA_SINVOKE_FOOTER("0,1");
}
int lua_cocos2d_AudioEngine_play(lua_State* lua_S)
{
	LUA_SINVOKE_HEADER("cc.AudioEngine", "cc.AudioEngine:play");
	LUA_TRY_INVOKE_R(1, &cc::AudioEngine::play);
	LUA_SINVOKE_FOOTER("1");
}
int lua_cocos2d_AudioEngine_removeEffect(lua_State* lua_S)
{
	LUA_SINVOKE_HEADER("cc.AudioEngine", "cc.AudioEngine:removeEffect");
	LUA_TRY_INVOKE_R(1, &cc::AudioEngine::removeEffect);
	LUA_SINVOKE_FOOTER("1");
}
int lua_cocos2d_AudioEngine_setDistanceModel(lua_State* lua_S)
{
	LUA_SINVOKE_HEADER("cc.AudioEngine", "cc.AudioEngine:setDistanceModel");
	LUA_TRY_INVOKE(1, &cc::AudioEngine::setDistanceModel);
	LUA_SINVOKE_FOOTER("1");
}
int lua_cocos2d_AudioEngine_setDopplerScale(lua_State* lua_S)
{
	LUA_SINVOKE_HEADER("cc.AudioEngine", "cc.AudioEngine:setDopplerScale");
	LUA_TRY_INVOKE(1, &cc::AudioEngine::setDopplerScale);
	LUA_SINVOKE_FOOTER("1");
}
int lua_cocos2d_AudioEngine_setEffect(lua_State* lua_S)
{
	LUA_SINVOKE_HEADER("cc.AudioEngine", "cc.AudioEngine:setEffect");
	LUA_TRY_INVOKE_R(2, &cc::AudioEngine::setEffect);
	LUA_SINVOKE_FOOTER("2");
}
int lua_cocos2d_AudioEngine_setOrientation(lua_State* lua_S)
{
	LUA_SINVOKE_HEADER("cc.AudioEngine", "cc.AudioEngine:setOrientation");
	LUA_TRY_INVOKE(2, &cc::AudioEngine::setOrientation);
	LUA_SINVOKE_FOOTER("2");
}
int lua_cocos2d_AudioEngine_setPosition(lua_State* lua_S)
{
	LUA_SINVOKE_HEADER("cc.AudioEngine", "cc.AudioEngine:setPosition");
	LUA_TRY_INVOKE(1, &cc::AudioEngine::setPosition);
	LUA_SINVOKE_FOOTER("1");
}
int lua_cocos2d_AudioEngine_setVelocity(lua_State* lua_S)
{
	LUA_SINVOKE_HEADER("cc.AudioEngine", "cc.AudioEngine:setVelocity");
	LUA_TRY_INVOKE(1, &cc::AudioEngine::setVelocity);
	LUA_SINVOKE_FOOTER("1");
}
int lua_cocos2d_AudioEngine_setVolume(lua_State* lua_S)
{
	LUA_SINVOKE_HEADER("cc.AudioEngine", "cc.AudioEngine:setVolume");
	LUA_TRY_INVOKE(1, &cc::AudioEngine::setVolume);
	LUA_SINVOKE_FOOTER("1");
}
int lua_cocos2d_AudioEngine_stop(lua_State* lua_S)
{
	LUA_SINVOKE_HEADER("cc.AudioEngine", "cc.AudioEngine:stop");
	LUA_TRY_INVOKE(1, static_cast<void(*)(const std::vector<cc::AudioSource *>&)>(&cc::AudioEngine::stop));
	LUA_TRY_INVOKE(0, static_cast<void(*)()>(&cc::AudioEngine::stop));
	LUA_SINVOKE_FOOTER("0,1");
}
int luaReg_audio_ccAudioEngine(lua_State* lua_S)
{
	LUA_ENTRY("cc");
	LUA_CLS_DEF(cc::AudioEngine, "AudioEngine", "cc.AudioEngine",
		nullptr, nullptr);
	LUA_METHOD("getActiveEffects", lua_cocos2d_AudioEngine_getActiveEffects);
	LUA_METHOD("getActiveSourceCount", lua_cocos2d_AudioEngine_getActiveSourceCount);
	LUA_METHOD("getDistanceModel", lua_cocos2d_AudioEngine_getDistanceModel);
	LUA_METHOD("getDopplerScale", lua_cocos2d_AudioEngine_getDopplerScale);
	LUA_METHOD("getEffect", lua_cocos2d_AudioEngine_getEffect);
	LUA_METHOD("getEffectID", lua_cocos2d_AudioEngine_getEffectID);
	LUA_METHOD("getFormat", lua_cocos2d_AudioEngine_getFormat);
	LUA_METHOD("getLastError", lua_cocos2d_AudioEngine_getLastError);
	LUA_METHOD("getMaxEffectCount", lua_cocos2d_AudioEngine_getMaxEffectCount);
	LUA_METHOD("getMaxSourceCount", lua_cocos2d_AudioEngine_getMaxSourceCount);
	LUA_METHOD("getMaxSourceEffectCount", lua_cocos2d_AudioEngine_getMaxSourceEffectCount);
	LUA_METHOD("getOrientation", lua_cocos2d_AudioEngine_getOrientation);
	LUA_METHOD("getPosition", lua_cocos2d_AudioEngine_getPosition);
	LUA_METHOD("getRecordingDevices", lua_cocos2d_AudioEngine_getRecordingDevices);
	LUA_METHOD("getVelocity", lua_cocos2d_AudioEngine_getVelocity);
	LUA_METHOD("getVolume", lua_cocos2d_AudioEngine_getVolume);
	LUA_METHOD("isEffectSupported", lua_cocos2d_AudioEngine_isEffectSupported);
	LUA_METHOD("isValid", lua_cocos2d_AudioEngine_isValid);
	LUA_METHOD("onEnterBackground", lua_cocos2d_AudioEngine_onEnterBackground);
	LUA_METHOD("onEnterForeground", lua_cocos2d_AudioEngine_onEnterForeground);
	LUA_METHOD("pause", lua_cocos2d_AudioEngine_pause);
	LUA_METHOD("play", lua_cocos2d_AudioEngine_play);
	LUA_METHOD("removeEffect", lua_cocos2d_AudioEngine_removeEffect);
	LUA_METHOD("setDistanceModel", lua_cocos2d_AudioEngine_setDistanceModel);
	LUA_METHOD("setDopplerScale", lua_cocos2d_AudioEngine_setDopplerScale);
	LUA_METHOD("setEffect", lua_cocos2d_AudioEngine_setEffect);
	LUA_METHOD("setOrientation", lua_cocos2d_AudioEngine_setOrientation);
	LUA_METHOD("setPosition", lua_cocos2d_AudioEngine_setPosition);
	LUA_METHOD("setVelocity", lua_cocos2d_AudioEngine_setVelocity);
	LUA_METHOD("setVolume", lua_cocos2d_AudioEngine_setVolume);
	LUA_METHOD("stop", lua_cocos2d_AudioEngine_stop);
	LUA_CLS_END();
	LUA_ENTRY_END(1);
	return 0;
}

int register_all_cc_audio_manual(lua_State* lua_S);

int register_all_cc_audio(lua_State* lua_S)
{
	luaReg_audio_ccAudioSource(lua_S);
	luaReg_audio_ccAudioStream(lua_S);
	luaReg_audio_ccAudioDecoder(lua_S);
	luaReg_audio_ccAudioSoundData(lua_S);
	luaReg_audio_ccAudioRecordingDevice(lua_S);
	luaReg_audio_ccAudioEngine(lua_S);
	return register_all_cc_audio_manual(lua_S);
}
