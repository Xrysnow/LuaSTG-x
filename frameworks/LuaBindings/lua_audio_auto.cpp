#include "lua_audio_auto.hpp"
#include "lua_conversion/lua_conversion.hpp"
#include "cocos/audio/AudioEngine.h"
#include "lua_audio_manual.hpp"

int lua_cocos2d_AudioSource_clone(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("cc.AudioSource", "cc.AudioSource:clone");
	LUA_TRY_INVOKE_R(0, &cocos2d::AudioSource::clone);
	LUA_INVOKE_FOOTER("0");
}
int lua_cocos2d_AudioSource_getActiveEffects(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("cc.AudioSource", "cc.AudioSource:getActiveEffects");
	LUA_TRY_INVOKE_R(0, &cocos2d::AudioSource::getActiveEffects);
	LUA_INVOKE_FOOTER("0");
}
int lua_cocos2d_AudioSource_getAirAbsorptionFactor(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("cc.AudioSource", "cc.AudioSource:getAirAbsorptionFactor");
	LUA_TRY_INVOKE_R(0, &cocos2d::AudioSource::getAirAbsorptionFactor);
	LUA_INVOKE_FOOTER("0");
}
int lua_cocos2d_AudioSource_getBitDepth(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("cc.AudioSource", "cc.AudioSource:getBitDepth");
	LUA_TRY_INVOKE_R(0, &cocos2d::AudioSource::getBitDepth);
	LUA_INVOKE_FOOTER("0");
}
int lua_cocos2d_AudioSource_getBytesPerFrame(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("cc.AudioSource", "cc.AudioSource:getBytesPerFrame");
	LUA_TRY_INVOKE_R(0, &cocos2d::AudioSource::getBytesPerFrame);
	LUA_INVOKE_FOOTER("0");
}
int lua_cocos2d_AudioSource_getChannelCount(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("cc.AudioSource", "cc.AudioSource:getChannelCount");
	LUA_TRY_INVOKE_R(0, &cocos2d::AudioSource::getChannelCount);
	LUA_INVOKE_FOOTER("0");
}
int lua_cocos2d_AudioSource_getCone(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("cc.AudioSource", "cc.AudioSource:getCone");
	LUA_TRY_INVOKE_R(0, &cocos2d::AudioSource::getCone);
	LUA_INVOKE_FOOTER("0");
}
int lua_cocos2d_AudioSource_getDirection(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("cc.AudioSource", "cc.AudioSource:getDirection");
	LUA_TRY_INVOKE_R(0, &cocos2d::AudioSource::getDirection);
	LUA_INVOKE_FOOTER("0");
}
int lua_cocos2d_AudioSource_getEffect(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("cc.AudioSource", "cc.AudioSource:getEffect");
	LUA_TRY_INVOKE_R(1, &cocos2d::AudioSource::getEffect);
	LUA_INVOKE_FOOTER("1");
}
int lua_cocos2d_AudioSource_getFilter(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("cc.AudioSource", "cc.AudioSource:getFilter");
	LUA_TRY_INVOKE_R(0, &cocos2d::AudioSource::getFilter);
	LUA_INVOKE_FOOTER("0");
}
int lua_cocos2d_AudioSource_getFreeBufferCount(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("cc.AudioSource", "cc.AudioSource:getFreeBufferCount");
	LUA_TRY_INVOKE_R(0, &cocos2d::AudioSource::getFreeBufferCount);
	LUA_INVOKE_FOOTER("0");
}
int lua_cocos2d_AudioSource_getLastError(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("cc.AudioSource", "cc.AudioSource:getLastError");
	LUA_TRY_INVOKE_R(0, &cocos2d::AudioSource::getLastError);
	LUA_INVOKE_FOOTER("0");
}
int lua_cocos2d_AudioSource_getLoopingEnd(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("cc.AudioSource", "cc.AudioSource:getLoopingEnd");
	LUA_TRY_INVOKE_R(0, &cocos2d::AudioSource::getLoopingEnd);
	LUA_INVOKE_FOOTER("0");
}
int lua_cocos2d_AudioSource_getLoopingStart(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("cc.AudioSource", "cc.AudioSource:getLoopingStart");
	LUA_TRY_INVOKE_R(0, &cocos2d::AudioSource::getLoopingStart);
	LUA_INVOKE_FOOTER("0");
}
int lua_cocos2d_AudioSource_getMaxDistance(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("cc.AudioSource", "cc.AudioSource:getMaxDistance");
	LUA_TRY_INVOKE_R(0, &cocos2d::AudioSource::getMaxDistance);
	LUA_INVOKE_FOOTER("0");
}
int lua_cocos2d_AudioSource_getMaxVolume(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("cc.AudioSource", "cc.AudioSource:getMaxVolume");
	LUA_TRY_INVOKE_R(0, &cocos2d::AudioSource::getMaxVolume);
	LUA_INVOKE_FOOTER("0");
}
int lua_cocos2d_AudioSource_getMinVolume(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("cc.AudioSource", "cc.AudioSource:getMinVolume");
	LUA_TRY_INVOKE_R(0, &cocos2d::AudioSource::getMinVolume);
	LUA_INVOKE_FOOTER("0");
}
int lua_cocos2d_AudioSource_getPitch(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("cc.AudioSource", "cc.AudioSource:getPitch");
	LUA_TRY_INVOKE_R(0, &cocos2d::AudioSource::getPitch);
	LUA_INVOKE_FOOTER("0");
}
int lua_cocos2d_AudioSource_getPosition(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("cc.AudioSource", "cc.AudioSource:getPosition");
	LUA_TRY_INVOKE_R(0, &cocos2d::AudioSource::getPosition);
	LUA_INVOKE_FOOTER("0");
}
int lua_cocos2d_AudioSource_getReferenceDistance(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("cc.AudioSource", "cc.AudioSource:getReferenceDistance");
	LUA_TRY_INVOKE_R(0, &cocos2d::AudioSource::getReferenceDistance);
	LUA_INVOKE_FOOTER("0");
}
int lua_cocos2d_AudioSource_getRolloffFactor(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("cc.AudioSource", "cc.AudioSource:getRolloffFactor");
	LUA_TRY_INVOKE_R(0, &cocos2d::AudioSource::getRolloffFactor);
	LUA_INVOKE_FOOTER("0");
}
int lua_cocos2d_AudioSource_getSampleRate(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("cc.AudioSource", "cc.AudioSource:getSampleRate");
	LUA_TRY_INVOKE_R(0, &cocos2d::AudioSource::getSampleRate);
	LUA_INVOKE_FOOTER("0");
}
int lua_cocos2d_AudioSource_getTime(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("cc.AudioSource", "cc.AudioSource:getTime");
	LUA_TRY_INVOKE_R(0, &cocos2d::AudioSource::getTime);
	LUA_INVOKE_FOOTER("0");
}
int lua_cocos2d_AudioSource_getTotalFrames(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("cc.AudioSource", "cc.AudioSource:getTotalFrames");
	LUA_TRY_INVOKE_R(0, &cocos2d::AudioSource::getTotalFrames);
	LUA_INVOKE_FOOTER("0");
}
int lua_cocos2d_AudioSource_getTotalTime(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("cc.AudioSource", "cc.AudioSource:getTotalTime");
	LUA_TRY_INVOKE_R(0, &cocos2d::AudioSource::getTotalTime);
	LUA_INVOKE_FOOTER("0");
}
int lua_cocos2d_AudioSource_getType(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("cc.AudioSource", "cc.AudioSource:getType");
	LUA_TRY_INVOKE_R(0, &cocos2d::AudioSource::getType);
	LUA_INVOKE_FOOTER("0");
}
int lua_cocos2d_AudioSource_getVelocity(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("cc.AudioSource", "cc.AudioSource:getVelocity");
	LUA_TRY_INVOKE_R(0, &cocos2d::AudioSource::getVelocity);
	LUA_INVOKE_FOOTER("0");
}
int lua_cocos2d_AudioSource_getVolume(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("cc.AudioSource", "cc.AudioSource:getVolume");
	LUA_TRY_INVOKE_R(0, &cocos2d::AudioSource::getVolume);
	LUA_INVOKE_FOOTER("0");
}
int lua_cocos2d_AudioSource_isFinished(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("cc.AudioSource", "cc.AudioSource:isFinished");
	LUA_TRY_INVOKE_R(0, &cocos2d::AudioSource::isFinished);
	LUA_INVOKE_FOOTER("0");
}
int lua_cocos2d_AudioSource_isLooping(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("cc.AudioSource", "cc.AudioSource:isLooping");
	LUA_TRY_INVOKE_R(0, &cocos2d::AudioSource::isLooping);
	LUA_INVOKE_FOOTER("0");
}
int lua_cocos2d_AudioSource_isPlaying(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("cc.AudioSource", "cc.AudioSource:isPlaying");
	LUA_TRY_INVOKE_R(0, &cocos2d::AudioSource::isPlaying);
	LUA_INVOKE_FOOTER("0");
}
int lua_cocos2d_AudioSource_isRelative(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("cc.AudioSource", "cc.AudioSource:isRelative");
	LUA_TRY_INVOKE_R(0, &cocos2d::AudioSource::isRelative);
	LUA_INVOKE_FOOTER("0");
}
int lua_cocos2d_AudioSource_isSupportLoopingPoint(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("cc.AudioSource", "cc.AudioSource:isSupportLoopingPoint");
	LUA_TRY_INVOKE_R(0, &cocos2d::AudioSource::isSupportLoopingPoint);
	LUA_INVOKE_FOOTER("0");
}
int lua_cocos2d_AudioSource_pause(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("cc.AudioSource", "cc.AudioSource:pause");
	LUA_TRY_INVOKE(0, &cocos2d::AudioSource::pause);
	LUA_INVOKE_FOOTER("0");
}
int lua_cocos2d_AudioSource_play(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("cc.AudioSource", "cc.AudioSource:play");
	LUA_TRY_INVOKE_R(0, &cocos2d::AudioSource::play);
	LUA_INVOKE_FOOTER("0");
}
int lua_cocos2d_AudioSource_queue(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("cc.AudioSource", "cc.AudioSource:queue");
	LUA_TRY_INVOKE_R(3, &cocos2d::AudioSource::queue);
	LUA_TRY_INVOKE_R(2, ([](cocos2d::AudioSource* obj,cocos2d::AudioSoundData* arg0,ssize_t arg1){{return obj->queue(arg0,std::move(arg1));}}));
	LUA_TRY_INVOKE_R(1, ([](cocos2d::AudioSource* obj,cocos2d::AudioSoundData* arg0){{return obj->queue(arg0);}}));
	LUA_INVOKE_FOOTER("1,2,3");
}
int lua_cocos2d_AudioSource_removeEffect(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("cc.AudioSource", "cc.AudioSource:removeEffect");
	LUA_TRY_INVOKE_R(1, &cocos2d::AudioSource::removeEffect);
	LUA_INVOKE_FOOTER("1");
}
int lua_cocos2d_AudioSource_removeFilter(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("cc.AudioSource", "cc.AudioSource:removeFilter");
	LUA_TRY_INVOKE_R(0, &cocos2d::AudioSource::removeFilter);
	LUA_INVOKE_FOOTER("0");
}
int lua_cocos2d_AudioSource_seek(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("cc.AudioSource", "cc.AudioSource:seek");
	LUA_TRY_INVOKE(1, &cocos2d::AudioSource::seek);
	LUA_INVOKE_FOOTER("1");
}
int lua_cocos2d_AudioSource_setAirAbsorptionFactor(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("cc.AudioSource", "cc.AudioSource:setAirAbsorptionFactor");
	LUA_TRY_INVOKE(1, &cocos2d::AudioSource::setAirAbsorptionFactor);
	LUA_INVOKE_FOOTER("1");
}
int lua_cocos2d_AudioSource_setCone(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("cc.AudioSource", "cc.AudioSource:setCone");
	LUA_TRY_INVOKE(4, (static_cast<void(cocos2d::AudioSource::*)(float, float, float, float)>(&cocos2d::AudioSource::setCone)));
	LUA_TRY_INVOKE(1, (static_cast<void(cocos2d::AudioSource::*)(const std::array<float, 4>&)>(&cocos2d::AudioSource::setCone)));
	LUA_INVOKE_FOOTER("1,4");
}
int lua_cocos2d_AudioSource_setDirection(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("cc.AudioSource", "cc.AudioSource:setDirection");
	LUA_TRY_INVOKE(1, &cocos2d::AudioSource::setDirection);
	LUA_INVOKE_FOOTER("1");
}
int lua_cocos2d_AudioSource_setEffect(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("cc.AudioSource", "cc.AudioSource:setEffect");
	LUA_TRY_INVOKE_R(2, (static_cast<bool(cocos2d::AudioSource::*)(const std::string&, const cocos2d::AudioFilter::ParamMap&)>(&cocos2d::AudioSource::setEffect)));
	LUA_TRY_INVOKE_R(1, static_cast<bool(cocos2d::AudioSource::*)(const std::string&)>(&cocos2d::AudioSource::setEffect));
	LUA_INVOKE_FOOTER("1,2");
}
int lua_cocos2d_AudioSource_setFilter(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("cc.AudioSource", "cc.AudioSource:setFilter");
	LUA_TRY_INVOKE_R(1, &cocos2d::AudioSource::setFilter);
	LUA_INVOKE_FOOTER("1");
}
int lua_cocos2d_AudioSource_setLooping(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("cc.AudioSource", "cc.AudioSource:setLooping");
	LUA_TRY_INVOKE(1, &cocos2d::AudioSource::setLooping);
	LUA_INVOKE_FOOTER("1");
}
int lua_cocos2d_AudioSource_setLoopingPoint(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("cc.AudioSource", "cc.AudioSource:setLoopingPoint");
	LUA_TRY_INVOKE(2, &cocos2d::AudioSource::setLoopingPoint);
	LUA_INVOKE_FOOTER("2");
}
int lua_cocos2d_AudioSource_setMaxDistance(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("cc.AudioSource", "cc.AudioSource:setMaxDistance");
	LUA_TRY_INVOKE(1, &cocos2d::AudioSource::setMaxDistance);
	LUA_INVOKE_FOOTER("1");
}
int lua_cocos2d_AudioSource_setMaxVolume(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("cc.AudioSource", "cc.AudioSource:setMaxVolume");
	LUA_TRY_INVOKE(1, &cocos2d::AudioSource::setMaxVolume);
	LUA_INVOKE_FOOTER("1");
}
int lua_cocos2d_AudioSource_setMinVolume(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("cc.AudioSource", "cc.AudioSource:setMinVolume");
	LUA_TRY_INVOKE(1, &cocos2d::AudioSource::setMinVolume);
	LUA_INVOKE_FOOTER("1");
}
int lua_cocos2d_AudioSource_setPitch(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("cc.AudioSource", "cc.AudioSource:setPitch");
	LUA_TRY_INVOKE(1, &cocos2d::AudioSource::setPitch);
	LUA_INVOKE_FOOTER("1");
}
int lua_cocos2d_AudioSource_setPosition(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("cc.AudioSource", "cc.AudioSource:setPosition");
	LUA_TRY_INVOKE(1, &cocos2d::AudioSource::setPosition);
	LUA_INVOKE_FOOTER("1");
}
int lua_cocos2d_AudioSource_setReferenceDistance(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("cc.AudioSource", "cc.AudioSource:setReferenceDistance");
	LUA_TRY_INVOKE(1, &cocos2d::AudioSource::setReferenceDistance);
	LUA_INVOKE_FOOTER("1");
}
int lua_cocos2d_AudioSource_setRelative(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("cc.AudioSource", "cc.AudioSource:setRelative");
	LUA_TRY_INVOKE(1, &cocos2d::AudioSource::setRelative);
	LUA_INVOKE_FOOTER("1");
}
int lua_cocos2d_AudioSource_setRolloffFactor(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("cc.AudioSource", "cc.AudioSource:setRolloffFactor");
	LUA_TRY_INVOKE(1, &cocos2d::AudioSource::setRolloffFactor);
	LUA_INVOKE_FOOTER("1");
}
int lua_cocos2d_AudioSource_setTime(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("cc.AudioSource", "cc.AudioSource:setTime");
	LUA_TRY_INVOKE(1, &cocos2d::AudioSource::setTime);
	LUA_INVOKE_FOOTER("1");
}
int lua_cocos2d_AudioSource_setVelocity(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("cc.AudioSource", "cc.AudioSource:setVelocity");
	LUA_TRY_INVOKE(1, &cocos2d::AudioSource::setVelocity);
	LUA_INVOKE_FOOTER("1");
}
int lua_cocos2d_AudioSource_setVolume(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("cc.AudioSource", "cc.AudioSource:setVolume");
	LUA_TRY_INVOKE(1, &cocos2d::AudioSource::setVolume);
	LUA_INVOKE_FOOTER("1");
}
int lua_cocos2d_AudioSource_stop(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("cc.AudioSource", "cc.AudioSource:stop");
	LUA_TRY_INVOKE(0, &cocos2d::AudioSource::stop);
	LUA_INVOKE_FOOTER("0");
}
int lua_cocos2d_AudioSource_tell(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("cc.AudioSource", "cc.AudioSource:tell");
	LUA_TRY_INVOKE_R(0, &cocos2d::AudioSource::tell);
	LUA_INVOKE_FOOTER("0");
}
int lua_cocos2d_AudioSource_create(lua_State* lua_S)
{
	LUA_SINVOKE_HEADER("cc.AudioSource", "cc.AudioSource:create");
	LUA_TRY_INVOKE_R(4, &cocos2d::AudioSource::create);
	LUA_SINVOKE_FOOTER("4");
}
int lua_cocos2d_AudioSource_createFromDecoder(lua_State* lua_S)
{
	LUA_SINVOKE_HEADER("cc.AudioSource", "cc.AudioSource:createFromDecoder");
	LUA_TRY_INVOKE_R(1, &cocos2d::AudioSource::createFromDecoder);
	LUA_SINVOKE_FOOTER("1");
}
int lua_cocos2d_AudioSource_createFromSoundData(lua_State* lua_S)
{
	LUA_SINVOKE_HEADER("cc.AudioSource", "cc.AudioSource:createFromSoundData");
	LUA_TRY_INVOKE_R(1, &cocos2d::AudioSource::createFromSoundData);
	LUA_SINVOKE_FOOTER("1");
}
int lua_cocos2d_AudioSource_pauseAll(lua_State* lua_S)
{
	LUA_SINVOKE_HEADER("cc.AudioSource", "cc.AudioSource:pauseAll");
	LUA_TRY_INVOKE_R(0, &cocos2d::AudioSource::pauseAll);
	LUA_SINVOKE_FOOTER("0");
}
int lua_cocos2d_AudioSource_pauseBatch(lua_State* lua_S)
{
	LUA_SINVOKE_HEADER("cc.AudioSource", "cc.AudioSource:pauseBatch");
	LUA_TRY_INVOKE(1, &cocos2d::AudioSource::pauseBatch);
	LUA_SINVOKE_FOOTER("1");
}
int lua_cocos2d_AudioSource_playBatch(lua_State* lua_S)
{
	LUA_SINVOKE_HEADER("cc.AudioSource", "cc.AudioSource:playBatch");
	LUA_TRY_INVOKE_R(1, &cocos2d::AudioSource::playBatch);
	LUA_SINVOKE_FOOTER("1");
}
int lua_cocos2d_AudioSource_stopAll(lua_State* lua_S)
{
	LUA_SINVOKE_HEADER("cc.AudioSource", "cc.AudioSource:stopAll");
	LUA_TRY_INVOKE(0, &cocos2d::AudioSource::stopAll);
	LUA_SINVOKE_FOOTER("0");
}
int lua_cocos2d_AudioSource_stopBatch(lua_State* lua_S)
{
	LUA_SINVOKE_HEADER("cc.AudioSource", "cc.AudioSource:stopBatch");
	LUA_TRY_INVOKE(1, &cocos2d::AudioSource::stopBatch);
	LUA_SINVOKE_FOOTER("1");
}
int luaReg_audio_ccAudioSource(lua_State* lua_S)
{
	LUA_ENTRY("cc");
	LUA_CLS_DEF_BASE(cocos2d::AudioSource, "AudioSource", "cc.AudioSource",
		cocos2d::Ref, "cc.Ref",
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
	LUA_TRY_INVOKE(0, &cocos2d::AudioStream::lock);
	LUA_INVOKE_FOOTER("0");
}
int lua_cocos2d_AudioStream_seek(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("cc.AudioStream", "cc.AudioStream:seek");
	LUA_TRY_INVOKE_R(2, &cocos2d::AudioStream::seek);
	LUA_INVOKE_FOOTER("2");
}
int lua_cocos2d_AudioStream_size(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("cc.AudioStream", "cc.AudioStream:size");
	LUA_TRY_INVOKE_R(0, &cocos2d::AudioStream::size);
	LUA_INVOKE_FOOTER("0");
}
int lua_cocos2d_AudioStream_tell(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("cc.AudioStream", "cc.AudioStream:tell");
	LUA_TRY_INVOKE_R(0, &cocos2d::AudioStream::tell);
	LUA_INVOKE_FOOTER("0");
}
int lua_cocos2d_AudioStream_unlock(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("cc.AudioStream", "cc.AudioStream:unlock");
	LUA_TRY_INVOKE(0, &cocos2d::AudioStream::unlock);
	LUA_INVOKE_FOOTER("0");
}
int lua_cocos2d_AudioStream_createFromFile(lua_State* lua_S)
{
	LUA_SINVOKE_HEADER("cc.AudioStream", "cc.AudioStream:createFromFile");
	LUA_TRY_INVOKE_R(1, &cocos2d::AudioStream::createFromFile);
	LUA_SINVOKE_FOOTER("1");
}
int lua_cocos2d_AudioStream_createFromLocalFile(lua_State* lua_S)
{
	LUA_SINVOKE_HEADER("cc.AudioStream", "cc.AudioStream:createFromLocalFile");
	LUA_TRY_INVOKE_R(1, &cocos2d::AudioStream::createFromLocalFile);
	LUA_SINVOKE_FOOTER("1");
}
int luaReg_audio_ccAudioStream(lua_State* lua_S)
{
	LUA_ENTRY("cc");
	LUA_CLS_DEF_BASE(cocos2d::AudioStream, "AudioStream", "cc.AudioStream",
		cocos2d::Ref, "cc.Ref",
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
	LUA_PUSH_NATIVE(cocos2d::AudioDecoder::DEFAULT_BIT_DEPTH);
	return 1;
}
int lua_cocos2d_AudioDecoder_DEFAULT_BUFFER_SIZE_getter(lua_State* lua_S)
{
	LUA_CUR_FNAME("cc.AudioDecoder.DEFAULT_BUFFER_SIZE/getter");
	LUA_PUSH_NATIVE(cocos2d::AudioDecoder::DEFAULT_BUFFER_SIZE);
	return 1;
}
int lua_cocos2d_AudioDecoder_DEFAULT_CHANNELS_getter(lua_State* lua_S)
{
	LUA_CUR_FNAME("cc.AudioDecoder.DEFAULT_CHANNELS/getter");
	LUA_PUSH_NATIVE(cocos2d::AudioDecoder::DEFAULT_CHANNELS);
	return 1;
}
int lua_cocos2d_AudioDecoder_DEFAULT_SAMPLE_RATE_getter(lua_State* lua_S)
{
	LUA_CUR_FNAME("cc.AudioDecoder.DEFAULT_SAMPLE_RATE/getter");
	LUA_PUSH_NATIVE(cocos2d::AudioDecoder::DEFAULT_SAMPLE_RATE);
	return 1;
}
int lua_cocos2d_AudioDecoder_clone(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("cc.AudioDecoder", "cc.AudioDecoder:clone");
	LUA_TRY_INVOKE_R(0, &cocos2d::AudioDecoder::clone);
	LUA_INVOKE_FOOTER("0");
}
int lua_cocos2d_AudioDecoder_getBitDepth(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("cc.AudioDecoder", "cc.AudioDecoder:getBitDepth");
	LUA_TRY_INVOKE_R(0, &cocos2d::AudioDecoder::getBitDepth);
	LUA_INVOKE_FOOTER("0");
}
int lua_cocos2d_AudioDecoder_getBufferSize(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("cc.AudioDecoder", "cc.AudioDecoder:getBufferSize");
	LUA_TRY_INVOKE_R(0, &cocos2d::AudioDecoder::getBufferSize);
	LUA_INVOKE_FOOTER("0");
}
int lua_cocos2d_AudioDecoder_getBytesPerFrame(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("cc.AudioDecoder", "cc.AudioDecoder:getBytesPerFrame");
	LUA_TRY_INVOKE_R(0, &cocos2d::AudioDecoder::getBytesPerFrame);
	LUA_INVOKE_FOOTER("0");
}
int lua_cocos2d_AudioDecoder_getChannelCount(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("cc.AudioDecoder", "cc.AudioDecoder:getChannelCount");
	LUA_TRY_INVOKE_R(0, &cocos2d::AudioDecoder::getChannelCount);
	LUA_INVOKE_FOOTER("0");
}
int lua_cocos2d_AudioDecoder_getDuration(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("cc.AudioDecoder", "cc.AudioDecoder:getDuration");
	LUA_TRY_INVOKE_R(0, &cocos2d::AudioDecoder::getDuration);
	LUA_INVOKE_FOOTER("0");
}
int lua_cocos2d_AudioDecoder_getLoopingEnd(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("cc.AudioDecoder", "cc.AudioDecoder:getLoopingEnd");
	LUA_TRY_INVOKE_R(0, &cocos2d::AudioDecoder::getLoopingEnd);
	LUA_INVOKE_FOOTER("0");
}
int lua_cocos2d_AudioDecoder_getLoopingStart(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("cc.AudioDecoder", "cc.AudioDecoder:getLoopingStart");
	LUA_TRY_INVOKE_R(0, &cocos2d::AudioDecoder::getLoopingStart);
	LUA_INVOKE_FOOTER("0");
}
int lua_cocos2d_AudioDecoder_getSampleRate(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("cc.AudioDecoder", "cc.AudioDecoder:getSampleRate");
	LUA_TRY_INVOKE_R(0, &cocos2d::AudioDecoder::getSampleRate);
	LUA_INVOKE_FOOTER("0");
}
int lua_cocos2d_AudioDecoder_getTotalFrames(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("cc.AudioDecoder", "cc.AudioDecoder:getTotalFrames");
	LUA_TRY_INVOKE_R(0, &cocos2d::AudioDecoder::getTotalFrames);
	LUA_INVOKE_FOOTER("0");
}
int lua_cocos2d_AudioDecoder_isFinished(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("cc.AudioDecoder", "cc.AudioDecoder:isFinished");
	LUA_TRY_INVOKE_R(0, &cocos2d::AudioDecoder::isFinished);
	LUA_INVOKE_FOOTER("0");
}
int lua_cocos2d_AudioDecoder_isSeekable(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("cc.AudioDecoder", "cc.AudioDecoder:isSeekable");
	LUA_TRY_INVOKE_R(0, &cocos2d::AudioDecoder::isSeekable);
	LUA_INVOKE_FOOTER("0");
}
int lua_cocos2d_AudioDecoder_rewind(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("cc.AudioDecoder", "cc.AudioDecoder:rewind");
	LUA_TRY_INVOKE_R(0, &cocos2d::AudioDecoder::rewind);
	LUA_INVOKE_FOOTER("0");
}
int lua_cocos2d_AudioDecoder_seek(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("cc.AudioDecoder", "cc.AudioDecoder:seek");
	LUA_TRY_INVOKE_R(1, &cocos2d::AudioDecoder::seek);
	LUA_INVOKE_FOOTER("1");
}
int lua_cocos2d_AudioDecoder_seekTime(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("cc.AudioDecoder", "cc.AudioDecoder:seekTime");
	LUA_TRY_INVOKE_R(1, &cocos2d::AudioDecoder::seekTime);
	LUA_INVOKE_FOOTER("1");
}
int lua_cocos2d_AudioDecoder_tell(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("cc.AudioDecoder", "cc.AudioDecoder:tell");
	LUA_TRY_INVOKE_R(0, &cocos2d::AudioDecoder::tell);
	LUA_INVOKE_FOOTER("0");
}
int lua_cocos2d_AudioDecoder_createFromFile(lua_State* lua_S)
{
	LUA_SINVOKE_HEADER("cc.AudioDecoder", "cc.AudioDecoder:createFromFile");
	LUA_TRY_INVOKE_R(3, &cocos2d::AudioDecoder::createFromFile);
	LUA_TRY_INVOKE_R(2, ([](const std::string& arg0,size_t arg1){{return cocos2d::AudioDecoder::createFromFile(arg0,std::move(arg1));}}));
	LUA_SINVOKE_FOOTER("2,3");
}
int lua_cocos2d_AudioDecoder_createFromLocalFile(lua_State* lua_S)
{
	LUA_SINVOKE_HEADER("cc.AudioDecoder", "cc.AudioDecoder:createFromLocalFile");
	LUA_TRY_INVOKE_R(3, &cocos2d::AudioDecoder::createFromLocalFile);
	LUA_TRY_INVOKE_R(2, ([](const std::string& arg0,size_t arg1){{return cocos2d::AudioDecoder::createFromLocalFile(arg0,std::move(arg1));}}));
	LUA_SINVOKE_FOOTER("2,3");
}
int lua_cocos2d_AudioDecoder_createFromStream(lua_State* lua_S)
{
	LUA_SINVOKE_HEADER("cc.AudioDecoder", "cc.AudioDecoder:createFromStream");
	LUA_TRY_INVOKE_R(3, &cocos2d::AudioDecoder::createFromStream);
	LUA_SINVOKE_FOOTER("3");
}
int lua_cocos2d_AudioDecoder_getDecoderTypeFromPath(lua_State* lua_S)
{
	LUA_SINVOKE_HEADER("cc.AudioDecoder", "cc.AudioDecoder:getDecoderTypeFromPath");
	LUA_TRY_INVOKE_R(1, &cocos2d::AudioDecoder::getDecoderTypeFromPath);
	LUA_SINVOKE_FOOTER("1");
}
int luaReg_audio_ccAudioDecoder(lua_State* lua_S)
{
	LUA_ENTRY("cc");
	LUA_CLS_DEF_BASE(cocos2d::AudioDecoder, "AudioDecoder", "cc.AudioDecoder",
		cocos2d::Ref, "cc.Ref",
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
	LUA_TRY_INVOKE_R(0, &cocos2d::AudioSoundData::clone);
	LUA_INVOKE_FOOTER("0");
}
int lua_cocos2d_AudioSoundData_getBitDepth(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("cc.AudioSoundData", "cc.AudioSoundData:getBitDepth");
	LUA_TRY_INVOKE_R(0, &cocos2d::AudioSoundData::getBitDepth);
	LUA_INVOKE_FOOTER("0");
}
int lua_cocos2d_AudioSoundData_getChannelCount(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("cc.AudioSoundData", "cc.AudioSoundData:getChannelCount");
	LUA_TRY_INVOKE_R(0, &cocos2d::AudioSoundData::getChannelCount);
	LUA_INVOKE_FOOTER("0");
}
int lua_cocos2d_AudioSoundData_getDuration(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("cc.AudioSoundData", "cc.AudioSoundData:getDuration");
	LUA_TRY_INVOKE_R(0, &cocos2d::AudioSoundData::getDuration);
	LUA_INVOKE_FOOTER("0");
}
int lua_cocos2d_AudioSoundData_getLastError(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("cc.AudioSoundData", "cc.AudioSoundData:getLastError");
	LUA_TRY_INVOKE_R(0, &cocos2d::AudioSoundData::getLastError);
	LUA_INVOKE_FOOTER("0");
}
int lua_cocos2d_AudioSoundData_getSample(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("cc.AudioSoundData", "cc.AudioSoundData:getSample");
	LUA_TRY_INVOKE_R(2, (static_cast<float(cocos2d::AudioSoundData::*)(int, int)>(&cocos2d::AudioSoundData::getSample)));
	LUA_TRY_INVOKE_R(1, static_cast<float(cocos2d::AudioSoundData::*)(int)>(&cocos2d::AudioSoundData::getSample));
	LUA_INVOKE_FOOTER("1,2");
}
int lua_cocos2d_AudioSoundData_getSampleCount(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("cc.AudioSoundData", "cc.AudioSoundData:getSampleCount");
	LUA_TRY_INVOKE_R(0, &cocos2d::AudioSoundData::getSampleCount);
	LUA_INVOKE_FOOTER("0");
}
int lua_cocos2d_AudioSoundData_getSampleRate(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("cc.AudioSoundData", "cc.AudioSoundData:getSampleRate");
	LUA_TRY_INVOKE_R(0, &cocos2d::AudioSoundData::getSampleRate);
	LUA_INVOKE_FOOTER("0");
}
int lua_cocos2d_AudioSoundData_getSize(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("cc.AudioSoundData", "cc.AudioSoundData:getSize");
	LUA_TRY_INVOKE_R(0, &cocos2d::AudioSoundData::getSize);
	LUA_INVOKE_FOOTER("0");
}
int lua_cocos2d_AudioSoundData_setSample(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("cc.AudioSoundData", "cc.AudioSoundData:setSample");
	LUA_TRY_INVOKE(3, (static_cast<void(cocos2d::AudioSoundData::*)(int, int, float)>(&cocos2d::AudioSoundData::setSample)));
	LUA_TRY_INVOKE(2, (static_cast<void(cocos2d::AudioSoundData::*)(int, float)>(&cocos2d::AudioSoundData::setSample)));
	LUA_INVOKE_FOOTER("2,3");
}
int luaReg_audio_ccAudioSoundData(lua_State* lua_S)
{
	LUA_ENTRY("cc");
	LUA_CLS_DEF(cocos2d::AudioSoundData, "AudioSoundData", "cc.AudioSoundData",
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
	LUA_PUSH_NATIVE(cocos2d::AudioRecordingDevice::DEFAULT_BIT_DEPTH);
	return 1;
}
int lua_cocos2d_AudioRecordingDevice_DEFAULT_CHANNELS_getter(lua_State* lua_S)
{
	LUA_CUR_FNAME("cc.AudioRecordingDevice.DEFAULT_CHANNELS/getter");
	LUA_PUSH_NATIVE(cocos2d::AudioRecordingDevice::DEFAULT_CHANNELS);
	return 1;
}
int lua_cocos2d_AudioRecordingDevice_DEFAULT_SAMPLES_getter(lua_State* lua_S)
{
	LUA_CUR_FNAME("cc.AudioRecordingDevice.DEFAULT_SAMPLES/getter");
	LUA_PUSH_NATIVE(cocos2d::AudioRecordingDevice::DEFAULT_SAMPLES);
	return 1;
}
int lua_cocos2d_AudioRecordingDevice_DEFAULT_SAMPLE_RATE_getter(lua_State* lua_S)
{
	LUA_CUR_FNAME("cc.AudioRecordingDevice.DEFAULT_SAMPLE_RATE/getter");
	LUA_PUSH_NATIVE(cocos2d::AudioRecordingDevice::DEFAULT_SAMPLE_RATE);
	return 1;
}
int lua_cocos2d_AudioRecordingDevice_getBitDepth(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("cc.AudioRecordingDevice", "cc.AudioRecordingDevice:getBitDepth");
	LUA_TRY_INVOKE_R(0, &cocos2d::AudioRecordingDevice::getBitDepth);
	LUA_INVOKE_FOOTER("0");
}
int lua_cocos2d_AudioRecordingDevice_getChannelCount(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("cc.AudioRecordingDevice", "cc.AudioRecordingDevice:getChannelCount");
	LUA_TRY_INVOKE_R(0, &cocos2d::AudioRecordingDevice::getChannelCount);
	LUA_INVOKE_FOOTER("0");
}
int lua_cocos2d_AudioRecordingDevice_getData(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("cc.AudioRecordingDevice", "cc.AudioRecordingDevice:getData");
	LUA_TRY_INVOKE_R(0, &cocos2d::AudioRecordingDevice::getData);
	LUA_INVOKE_FOOTER("0");
}
int lua_cocos2d_AudioRecordingDevice_getMaxSamples(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("cc.AudioRecordingDevice", "cc.AudioRecordingDevice:getMaxSamples");
	LUA_TRY_INVOKE_R(0, &cocos2d::AudioRecordingDevice::getMaxSamples);
	LUA_INVOKE_FOOTER("0");
}
int lua_cocos2d_AudioRecordingDevice_getName(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("cc.AudioRecordingDevice", "cc.AudioRecordingDevice:getName");
	LUA_TRY_INVOKE_R(0, &cocos2d::AudioRecordingDevice::getName);
	LUA_INVOKE_FOOTER("0");
}
int lua_cocos2d_AudioRecordingDevice_getSampleCount(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("cc.AudioRecordingDevice", "cc.AudioRecordingDevice:getSampleCount");
	LUA_TRY_INVOKE_R(0, &cocos2d::AudioRecordingDevice::getSampleCount);
	LUA_INVOKE_FOOTER("0");
}
int lua_cocos2d_AudioRecordingDevice_getSampleRate(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("cc.AudioRecordingDevice", "cc.AudioRecordingDevice:getSampleRate");
	LUA_TRY_INVOKE_R(0, &cocos2d::AudioRecordingDevice::getSampleRate);
	LUA_INVOKE_FOOTER("0");
}
int lua_cocos2d_AudioRecordingDevice_isRecording(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("cc.AudioRecordingDevice", "cc.AudioRecordingDevice:isRecording");
	LUA_TRY_INVOKE_R(0, &cocos2d::AudioRecordingDevice::isRecording);
	LUA_INVOKE_FOOTER("0");
}
int lua_cocos2d_AudioRecordingDevice_start(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("cc.AudioRecordingDevice", "cc.AudioRecordingDevice:start");
	LUA_TRY_INVOKE_R(4, &cocos2d::AudioRecordingDevice::start);
	LUA_INVOKE_FOOTER("4");
}
int lua_cocos2d_AudioRecordingDevice_stop(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("cc.AudioRecordingDevice", "cc.AudioRecordingDevice:stop");
	LUA_TRY_INVOKE(0, &cocos2d::AudioRecordingDevice::stop);
	LUA_INVOKE_FOOTER("0");
}
int luaReg_audio_ccAudioRecordingDevice(lua_State* lua_S)
{
	LUA_ENTRY("cc");
	LUA_CLS_DEF_BASE(cocos2d::AudioRecordingDevice, "AudioRecordingDevice", "cc.AudioRecordingDevice",
		cocos2d::Ref, "cc.Ref",
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
	LUA_TRY_INVOKE_R(0, &cocos2d::AudioEngine::getActiveEffects);
	LUA_SINVOKE_FOOTER("0");
}
int lua_cocos2d_AudioEngine_getActiveSourceCount(lua_State* lua_S)
{
	LUA_SINVOKE_HEADER("cc.AudioEngine", "cc.AudioEngine:getActiveSourceCount");
	LUA_TRY_INVOKE_R(0, &cocos2d::AudioEngine::getActiveSourceCount);
	LUA_SINVOKE_FOOTER("0");
}
int lua_cocos2d_AudioEngine_getDistanceModel(lua_State* lua_S)
{
	LUA_SINVOKE_HEADER("cc.AudioEngine", "cc.AudioEngine:getDistanceModel");
	LUA_TRY_INVOKE_R(0, &cocos2d::AudioEngine::getDistanceModel);
	LUA_SINVOKE_FOOTER("0");
}
int lua_cocos2d_AudioEngine_getDopplerScale(lua_State* lua_S)
{
	LUA_SINVOKE_HEADER("cc.AudioEngine", "cc.AudioEngine:getDopplerScale");
	LUA_TRY_INVOKE_R(0, &cocos2d::AudioEngine::getDopplerScale);
	LUA_SINVOKE_FOOTER("0");
}
int lua_cocos2d_AudioEngine_getEffect(lua_State* lua_S)
{
	LUA_SINVOKE_HEADER("cc.AudioEngine", "cc.AudioEngine:getEffect");
	LUA_TRY_INVOKE_R(1, &cocos2d::AudioEngine::getEffect);
	LUA_SINVOKE_FOOTER("1");
}
int lua_cocos2d_AudioEngine_getEffectID(lua_State* lua_S)
{
	LUA_SINVOKE_HEADER("cc.AudioEngine", "cc.AudioEngine:getEffectID");
	LUA_TRY_INVOKE_R(2, &cocos2d::AudioEngine::getEffectID);
	LUA_SINVOKE_FOOTER("2");
}
int lua_cocos2d_AudioEngine_getFormat(lua_State* lua_S)
{
	LUA_SINVOKE_HEADER("cc.AudioEngine", "cc.AudioEngine:getFormat");
	LUA_TRY_INVOKE_R(2, &cocos2d::AudioEngine::getFormat);
	LUA_SINVOKE_FOOTER("2");
}
int lua_cocos2d_AudioEngine_getLastError(lua_State* lua_S)
{
	LUA_SINVOKE_HEADER("cc.AudioEngine", "cc.AudioEngine:getLastError");
	LUA_TRY_INVOKE_R(0, &cocos2d::AudioEngine::getLastError);
	LUA_SINVOKE_FOOTER("0");
}
int lua_cocos2d_AudioEngine_getMaxEffectCount(lua_State* lua_S)
{
	LUA_SINVOKE_HEADER("cc.AudioEngine", "cc.AudioEngine:getMaxEffectCount");
	LUA_TRY_INVOKE_R(0, &cocos2d::AudioEngine::getMaxEffectCount);
	LUA_SINVOKE_FOOTER("0");
}
int lua_cocos2d_AudioEngine_getMaxSourceCount(lua_State* lua_S)
{
	LUA_SINVOKE_HEADER("cc.AudioEngine", "cc.AudioEngine:getMaxSourceCount");
	LUA_TRY_INVOKE_R(0, &cocos2d::AudioEngine::getMaxSourceCount);
	LUA_SINVOKE_FOOTER("0");
}
int lua_cocos2d_AudioEngine_getMaxSourceEffectCount(lua_State* lua_S)
{
	LUA_SINVOKE_HEADER("cc.AudioEngine", "cc.AudioEngine:getMaxSourceEffectCount");
	LUA_TRY_INVOKE_R(0, &cocos2d::AudioEngine::getMaxSourceEffectCount);
	LUA_SINVOKE_FOOTER("0");
}
int lua_cocos2d_AudioEngine_getOrientation(lua_State* lua_S)
{
	LUA_SINVOKE_HEADER("cc.AudioEngine", "cc.AudioEngine:getOrientation");
	LUA_TRY_INVOKE_R(0, &cocos2d::AudioEngine::getOrientation);
	LUA_SINVOKE_FOOTER("0");
}
int lua_cocos2d_AudioEngine_getPosition(lua_State* lua_S)
{
	LUA_SINVOKE_HEADER("cc.AudioEngine", "cc.AudioEngine:getPosition");
	LUA_TRY_INVOKE_R(0, &cocos2d::AudioEngine::getPosition);
	LUA_SINVOKE_FOOTER("0");
}
int lua_cocos2d_AudioEngine_getRecordingDevices(lua_State* lua_S)
{
	LUA_SINVOKE_HEADER("cc.AudioEngine", "cc.AudioEngine:getRecordingDevices");
	LUA_TRY_INVOKE_R(0, &cocos2d::AudioEngine::getRecordingDevices);
	LUA_SINVOKE_FOOTER("0");
}
int lua_cocos2d_AudioEngine_getVelocity(lua_State* lua_S)
{
	LUA_SINVOKE_HEADER("cc.AudioEngine", "cc.AudioEngine:getVelocity");
	LUA_TRY_INVOKE_R(0, &cocos2d::AudioEngine::getVelocity);
	LUA_SINVOKE_FOOTER("0");
}
int lua_cocos2d_AudioEngine_getVolume(lua_State* lua_S)
{
	LUA_SINVOKE_HEADER("cc.AudioEngine", "cc.AudioEngine:getVolume");
	LUA_TRY_INVOKE_R(0, &cocos2d::AudioEngine::getVolume);
	LUA_SINVOKE_FOOTER("0");
}
int lua_cocos2d_AudioEngine_isEffectSupported(lua_State* lua_S)
{
	LUA_SINVOKE_HEADER("cc.AudioEngine", "cc.AudioEngine:isEffectSupported");
	LUA_TRY_INVOKE_R(0, &cocos2d::AudioEngine::isEffectSupported);
	LUA_SINVOKE_FOOTER("0");
}
int lua_cocos2d_AudioEngine_isValid(lua_State* lua_S)
{
	LUA_SINVOKE_HEADER("cc.AudioEngine", "cc.AudioEngine:isValid");
	LUA_TRY_INVOKE_R(0, &cocos2d::AudioEngine::isValid);
	LUA_SINVOKE_FOOTER("0");
}
int lua_cocos2d_AudioEngine_onEnterBackground(lua_State* lua_S)
{
	LUA_SINVOKE_HEADER("cc.AudioEngine", "cc.AudioEngine:onEnterBackground");
	LUA_TRY_INVOKE(0, &cocos2d::AudioEngine::onEnterBackground);
	LUA_SINVOKE_FOOTER("0");
}
int lua_cocos2d_AudioEngine_onEnterForeground(lua_State* lua_S)
{
	LUA_SINVOKE_HEADER("cc.AudioEngine", "cc.AudioEngine:onEnterForeground");
	LUA_TRY_INVOKE(0, &cocos2d::AudioEngine::onEnterForeground);
	LUA_SINVOKE_FOOTER("0");
}
int lua_cocos2d_AudioEngine_pause(lua_State* lua_S)
{
	LUA_SINVOKE_HEADER("cc.AudioEngine", "cc.AudioEngine:pause");
	LUA_TRY_INVOKE(1, static_cast<void(*)(const std::vector<cocos2d::AudioSource *>&)>(&cocos2d::AudioEngine::pause));
	LUA_TRY_INVOKE_R(0, static_cast<std::vector<cocos2d::AudioSource *>(*)()>(&cocos2d::AudioEngine::pause));
	LUA_SINVOKE_FOOTER("0,1");
}
int lua_cocos2d_AudioEngine_play(lua_State* lua_S)
{
	LUA_SINVOKE_HEADER("cc.AudioEngine", "cc.AudioEngine:play");
	LUA_TRY_INVOKE_R(1, &cocos2d::AudioEngine::play);
	LUA_SINVOKE_FOOTER("1");
}
int lua_cocos2d_AudioEngine_removeEffect(lua_State* lua_S)
{
	LUA_SINVOKE_HEADER("cc.AudioEngine", "cc.AudioEngine:removeEffect");
	LUA_TRY_INVOKE_R(1, &cocos2d::AudioEngine::removeEffect);
	LUA_SINVOKE_FOOTER("1");
}
int lua_cocos2d_AudioEngine_setDistanceModel(lua_State* lua_S)
{
	LUA_SINVOKE_HEADER("cc.AudioEngine", "cc.AudioEngine:setDistanceModel");
	LUA_TRY_INVOKE(1, &cocos2d::AudioEngine::setDistanceModel);
	LUA_SINVOKE_FOOTER("1");
}
int lua_cocos2d_AudioEngine_setDopplerScale(lua_State* lua_S)
{
	LUA_SINVOKE_HEADER("cc.AudioEngine", "cc.AudioEngine:setDopplerScale");
	LUA_TRY_INVOKE(1, &cocos2d::AudioEngine::setDopplerScale);
	LUA_SINVOKE_FOOTER("1");
}
int lua_cocos2d_AudioEngine_setEffect(lua_State* lua_S)
{
	LUA_SINVOKE_HEADER("cc.AudioEngine", "cc.AudioEngine:setEffect");
	LUA_TRY_INVOKE_R(2, &cocos2d::AudioEngine::setEffect);
	LUA_SINVOKE_FOOTER("2");
}
int lua_cocos2d_AudioEngine_setOrientation(lua_State* lua_S)
{
	LUA_SINVOKE_HEADER("cc.AudioEngine", "cc.AudioEngine:setOrientation");
	LUA_TRY_INVOKE(2, &cocos2d::AudioEngine::setOrientation);
	LUA_SINVOKE_FOOTER("2");
}
int lua_cocos2d_AudioEngine_setPosition(lua_State* lua_S)
{
	LUA_SINVOKE_HEADER("cc.AudioEngine", "cc.AudioEngine:setPosition");
	LUA_TRY_INVOKE(1, &cocos2d::AudioEngine::setPosition);
	LUA_SINVOKE_FOOTER("1");
}
int lua_cocos2d_AudioEngine_setVelocity(lua_State* lua_S)
{
	LUA_SINVOKE_HEADER("cc.AudioEngine", "cc.AudioEngine:setVelocity");
	LUA_TRY_INVOKE(1, &cocos2d::AudioEngine::setVelocity);
	LUA_SINVOKE_FOOTER("1");
}
int lua_cocos2d_AudioEngine_setVolume(lua_State* lua_S)
{
	LUA_SINVOKE_HEADER("cc.AudioEngine", "cc.AudioEngine:setVolume");
	LUA_TRY_INVOKE(1, &cocos2d::AudioEngine::setVolume);
	LUA_SINVOKE_FOOTER("1");
}
int lua_cocos2d_AudioEngine_stop(lua_State* lua_S)
{
	LUA_SINVOKE_HEADER("cc.AudioEngine", "cc.AudioEngine:stop");
	LUA_TRY_INVOKE(1, static_cast<void(*)(const std::vector<cocos2d::AudioSource *>&)>(&cocos2d::AudioEngine::stop));
	LUA_TRY_INVOKE(0, static_cast<void(*)()>(&cocos2d::AudioEngine::stop));
	LUA_SINVOKE_FOOTER("0,1");
}
int luaReg_audio_ccAudioEngine(lua_State* lua_S)
{
	LUA_ENTRY("cc");
	LUA_CLS_DEF(cocos2d::AudioEngine, "AudioEngine", "cc.AudioEngine",
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
