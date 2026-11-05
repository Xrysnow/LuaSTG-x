#include "lua_video_auto.hpp"
#include "lua_conversion/lua_conversion.hpp"
#include "lua_video_types.hpp"
#include "video/VideoPlayer.h"

int lua_video_Decoder_getAudioBitRate(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("video.Decoder", "video.Decoder:getAudioBitRate");
	LUA_TRY_INVOKE_R(1, static_cast<int64_t(video::Decoder::*)(int)const>(&video::Decoder::getAudioBitRate));
	LUA_TRY_INVOKE_R(0, [](const video::Decoder* obj){{return obj->getAudioBitRate();}});
	LUA_INVOKE_FOOTER("0,1");
}
int lua_video_Decoder_getAudioChannelCount(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("video.Decoder", "video.Decoder:getAudioChannelCount");
	LUA_TRY_INVOKE_R(1, static_cast<int(video::Decoder::*)(int)const>(&video::Decoder::getAudioChannelCount));
	LUA_TRY_INVOKE_R(0, [](const video::Decoder* obj){{return obj->getAudioChannelCount();}});
	LUA_INVOKE_FOOTER("0,1");
}
int lua_video_Decoder_getAudioChannelLayoutName(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("video.Decoder", "video.Decoder:getAudioChannelLayoutName");
	LUA_TRY_INVOKE_R(1, static_cast<std::string(video::Decoder::*)(int)const>(&video::Decoder::getAudioChannelLayoutName));
	LUA_TRY_INVOKE_R(0, [](const video::Decoder* obj){{return obj->getAudioChannelLayoutName();}});
	LUA_INVOKE_FOOTER("0,1");
}
int lua_video_Decoder_getAudioDecoderName(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("video.Decoder", "video.Decoder:getAudioDecoderName");
	LUA_TRY_INVOKE_R(0, static_cast<std::string(video::Decoder::*)()const>(&video::Decoder::getAudioDecoderName));
	LUA_INVOKE_FOOTER("0");
}
int lua_video_Decoder_getAudioFrameCount(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("video.Decoder", "video.Decoder:getAudioFrameCount");
	LUA_TRY_INVOKE_R(1, static_cast<int64_t(video::Decoder::*)(int)const>(&video::Decoder::getAudioFrameCount));
	LUA_TRY_INVOKE_R(0, [](const video::Decoder* obj){{return obj->getAudioFrameCount();}});
	LUA_INVOKE_FOOTER("0,1");
}
int lua_video_Decoder_getAudioSampleRate(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("video.Decoder", "video.Decoder:getAudioSampleRate");
	LUA_TRY_INVOKE_R(1, static_cast<int(video::Decoder::*)(int)const>(&video::Decoder::getAudioSampleRate));
	LUA_TRY_INVOKE_R(0, [](const video::Decoder* obj){{return obj->getAudioSampleRate();}});
	LUA_INVOKE_FOOTER("0,1");
}
int lua_video_Decoder_getAudioStreamCount(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("video.Decoder", "video.Decoder:getAudioStreamCount");
	LUA_TRY_INVOKE_R(0, static_cast<size_t(video::Decoder::*)()const>(&video::Decoder::getAudioStreamCount));
	LUA_INVOKE_FOOTER("0");
}
int lua_video_Decoder_getAudioTimeBase(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("video.Decoder", "video.Decoder:getAudioTimeBase");
	LUA_TRY_INVOKE_R(1, static_cast<AVRational(video::Decoder::*)(int)const>(&video::Decoder::getAudioTimeBase));
	LUA_TRY_INVOKE_R(0, [](const video::Decoder* obj){{return obj->getAudioTimeBase();}});
	LUA_INVOKE_FOOTER("0,1");
}
int lua_video_Decoder_getContainerBitRate(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("video.Decoder", "video.Decoder:getContainerBitRate");
	LUA_TRY_INVOKE_R(0, static_cast<int64_t(video::Decoder::*)()const>(&video::Decoder::getContainerBitRate));
	LUA_INVOKE_FOOTER("0");
}
int lua_video_Decoder_getContainerDuration(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("video.Decoder", "video.Decoder:getContainerDuration");
	LUA_TRY_INVOKE_R(0, static_cast<double(video::Decoder::*)()const>(&video::Decoder::getContainerDuration));
	LUA_INVOKE_FOOTER("0");
}
int lua_video_Decoder_getContainerStartTime(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("video.Decoder", "video.Decoder:getContainerStartTime");
	LUA_TRY_INVOKE_R(0, static_cast<double(video::Decoder::*)()const>(&video::Decoder::getContainerStartTime));
	LUA_INVOKE_FOOTER("0");
}
int lua_video_Decoder_getVideoBitRate(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("video.Decoder", "video.Decoder:getVideoBitRate");
	LUA_TRY_INVOKE_R(1, static_cast<int64_t(video::Decoder::*)(int)const>(&video::Decoder::getVideoBitRate));
	LUA_TRY_INVOKE_R(0, [](const video::Decoder* obj){{return obj->getVideoBitRate();}});
	LUA_INVOKE_FOOTER("0,1");
}
int lua_video_Decoder_getVideoDecoderHardwareFormat(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("video.Decoder", "video.Decoder:getVideoDecoderHardwareFormat");
	LUA_TRY_INVOKE_R(0, static_cast<AVPixelFormat(video::Decoder::*)()const>(&video::Decoder::getVideoDecoderHardwareFormat));
	LUA_INVOKE_FOOTER("0");
}
int lua_video_Decoder_getVideoDecoderName(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("video.Decoder", "video.Decoder:getVideoDecoderName");
	LUA_TRY_INVOKE_R(0, static_cast<std::string(video::Decoder::*)()const>(&video::Decoder::getVideoDecoderName));
	LUA_INVOKE_FOOTER("0");
}
int lua_video_Decoder_getVideoDecoderSoftwareFormat(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("video.Decoder", "video.Decoder:getVideoDecoderSoftwareFormat");
	LUA_TRY_INVOKE_R(0, static_cast<AVPixelFormat(video::Decoder::*)()const>(&video::Decoder::getVideoDecoderSoftwareFormat));
	LUA_INVOKE_FOOTER("0");
}
int lua_video_Decoder_getVideoFormat(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("video.Decoder", "video.Decoder:getVideoFormat");
	LUA_TRY_INVOKE_R(1, static_cast<AVPixelFormat(video::Decoder::*)(int)const>(&video::Decoder::getVideoFormat));
	LUA_TRY_INVOKE_R(0, [](const video::Decoder* obj){{return obj->getVideoFormat();}});
	LUA_INVOKE_FOOTER("0,1");
}
int lua_video_Decoder_getVideoFormatName(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("video.Decoder", "video.Decoder:getVideoFormatName");
	LUA_TRY_INVOKE_R(1, static_cast<std::string(video::Decoder::*)(int)const>(&video::Decoder::getVideoFormatName));
	LUA_TRY_INVOKE_R(0, [](const video::Decoder* obj){{return obj->getVideoFormatName();}});
	LUA_INVOKE_FOOTER("0,1");
}
int lua_video_Decoder_getVideoFrameCount(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("video.Decoder", "video.Decoder:getVideoFrameCount");
	LUA_TRY_INVOKE_R(1, static_cast<int64_t(video::Decoder::*)(int)const>(&video::Decoder::getVideoFrameCount));
	LUA_TRY_INVOKE_R(0, [](const video::Decoder* obj){{return obj->getVideoFrameCount();}});
	LUA_INVOKE_FOOTER("0,1");
}
int lua_video_Decoder_getVideoFrameRate(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("video.Decoder", "video.Decoder:getVideoFrameRate");
	LUA_TRY_INVOKE_R(1, static_cast<AVRational(video::Decoder::*)(int)const>(&video::Decoder::getVideoFrameRate));
	LUA_TRY_INVOKE_R(0, [](const video::Decoder* obj){{return obj->getVideoFrameRate();}});
	LUA_INVOKE_FOOTER("0,1");
}
int lua_video_Decoder_getVideoSize(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("video.Decoder", "video.Decoder:getVideoSize");
	LUA_TRY_INVOKE_R(1, static_cast<cocos2d::Size(video::Decoder::*)(int)const>(&video::Decoder::getVideoSize));
	LUA_TRY_INVOKE_R(0, [](const video::Decoder* obj){{return obj->getVideoSize();}});
	LUA_INVOKE_FOOTER("0,1");
}
int lua_video_Decoder_getVideoStreamCount(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("video.Decoder", "video.Decoder:getVideoStreamCount");
	LUA_TRY_INVOKE_R(0, static_cast<size_t(video::Decoder::*)()const>(&video::Decoder::getVideoStreamCount));
	LUA_INVOKE_FOOTER("0");
}
int lua_video_Decoder_getVideoTargetSize(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("video.Decoder", "video.Decoder:getVideoTargetSize");
	LUA_TRY_INVOKE_R(0, static_cast<cocos2d::Size(video::Decoder::*)()const>(&video::Decoder::getVideoTargetSize));
	LUA_INVOKE_FOOTER("0");
}
int lua_video_Decoder_getVideoTimeBase(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("video.Decoder", "video.Decoder:getVideoTimeBase");
	LUA_TRY_INVOKE_R(1, static_cast<AVRational(video::Decoder::*)(int)const>(&video::Decoder::getVideoTimeBase));
	LUA_TRY_INVOKE_R(0, [](const video::Decoder* obj){{return obj->getVideoTimeBase();}});
	LUA_INVOKE_FOOTER("0,1");
}
int lua_video_Decoder_isVideoDecoderHardware(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("video.Decoder", "video.Decoder:isVideoDecoderHardware");
	LUA_TRY_INVOKE_R(0, static_cast<bool(video::Decoder::*)()const>(&video::Decoder::isVideoDecoderHardware));
	LUA_INVOKE_FOOTER("0");
}
int lua_video_Decoder_tell(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("video.Decoder", "video.Decoder:tell");
	LUA_TRY_INVOKE_R(0, static_cast<int64_t(video::Decoder::*)()const>(&video::Decoder::tell));
	LUA_INVOKE_FOOTER("0");
}
int lua_video_Decoder_getAllDecoderNames(lua_State* lua_S)
{
	LUA_SINVOKE_HEADER("video.Decoder", "video.Decoder:getAllDecoderNames");
	LUA_TRY_INVOKE_R(0, static_cast<std::vector<std::string>(*)()>(&video::Decoder::getAllDecoderNames));
	LUA_SINVOKE_FOOTER("0");
}
int lua_video_Decoder_getPixelFormatName(lua_State* lua_S)
{
	LUA_SINVOKE_HEADER("video.Decoder", "video.Decoder:getPixelFormatName");
	LUA_TRY_INVOKE_R(1, static_cast<std::string(*)(AVPixelFormat)>(&video::Decoder::getPixelFormatName));
	LUA_SINVOKE_FOOTER("1");
}
int lua_video_Decoder_queryDecoderID(lua_State* lua_S)
{
	LUA_SINVOKE_HEADER("video.Decoder", "video.Decoder:queryDecoderID");
	LUA_TRY_INVOKE_R(1, static_cast<std::string(*)(const std::string&)>(&video::Decoder::queryDecoderID));
	LUA_SINVOKE_FOOTER("1");
}
int lua_video_Decoder_queryDecoderLongName(lua_State* lua_S)
{
	LUA_SINVOKE_HEADER("video.Decoder", "video.Decoder:queryDecoderLongName");
	LUA_TRY_INVOKE_R(1, static_cast<std::string(*)(const std::string&)>(&video::Decoder::queryDecoderLongName));
	LUA_SINVOKE_FOOTER("1");
}
int lua_video_Decoder_queryDecoderSupportsHardware(lua_State* lua_S)
{
	LUA_SINVOKE_HEADER("video.Decoder", "video.Decoder:queryDecoderSupportsHardware");
	LUA_TRY_INVOKE_R(1, static_cast<bool(*)(const std::string&)>(&video::Decoder::queryDecoderSupportsHardware));
	LUA_SINVOKE_FOOTER("1");
}
int lua_video_Decoder_queryDecoderType(lua_State* lua_S)
{
	LUA_SINVOKE_HEADER("video.Decoder", "video.Decoder:queryDecoderType");
	LUA_TRY_INVOKE_R(1, static_cast<std::string(*)(const std::string&)>(&video::Decoder::queryDecoderType));
	LUA_SINVOKE_FOOTER("1");
}
int luaReg_cc_video_videoDecoder(lua_State* lua_S)
{
	LUA_ENTRY("video");
	LUA_CLS_DEF_BASE(video::Decoder, "Decoder", "video.Decoder",
		cocos2d::Ref, "cc.Ref",
		nullptr, nullptr);
	LUA_METHOD("getAudioBitRate", lua_video_Decoder_getAudioBitRate);
	LUA_METHOD("getAudioChannelCount", lua_video_Decoder_getAudioChannelCount);
	LUA_METHOD("getAudioChannelLayoutName", lua_video_Decoder_getAudioChannelLayoutName);
	LUA_METHOD("getAudioDecoderName", lua_video_Decoder_getAudioDecoderName);
	LUA_METHOD("getAudioFrameCount", lua_video_Decoder_getAudioFrameCount);
	LUA_METHOD("getAudioSampleRate", lua_video_Decoder_getAudioSampleRate);
	LUA_METHOD("getAudioStreamCount", lua_video_Decoder_getAudioStreamCount);
	LUA_METHOD("getAudioTimeBase", lua_video_Decoder_getAudioTimeBase);
	LUA_METHOD("getContainerBitRate", lua_video_Decoder_getContainerBitRate);
	LUA_METHOD("getContainerDuration", lua_video_Decoder_getContainerDuration);
	LUA_METHOD("getContainerStartTime", lua_video_Decoder_getContainerStartTime);
	LUA_METHOD("getVideoBitRate", lua_video_Decoder_getVideoBitRate);
	LUA_METHOD("getVideoDecoderHardwareFormat", lua_video_Decoder_getVideoDecoderHardwareFormat);
	LUA_METHOD("getVideoDecoderName", lua_video_Decoder_getVideoDecoderName);
	LUA_METHOD("getVideoDecoderSoftwareFormat", lua_video_Decoder_getVideoDecoderSoftwareFormat);
	LUA_METHOD("getVideoFormat", lua_video_Decoder_getVideoFormat);
	LUA_METHOD("getVideoFormatName", lua_video_Decoder_getVideoFormatName);
	LUA_METHOD("getVideoFrameCount", lua_video_Decoder_getVideoFrameCount);
	LUA_METHOD("getVideoFrameRate", lua_video_Decoder_getVideoFrameRate);
	LUA_METHOD("getVideoSize", lua_video_Decoder_getVideoSize);
	LUA_METHOD("getVideoStreamCount", lua_video_Decoder_getVideoStreamCount);
	LUA_METHOD("getVideoTargetSize", lua_video_Decoder_getVideoTargetSize);
	LUA_METHOD("getVideoTimeBase", lua_video_Decoder_getVideoTimeBase);
	LUA_METHOD("isVideoDecoderHardware", lua_video_Decoder_isVideoDecoderHardware);
	LUA_METHOD("tell", lua_video_Decoder_tell);
	LUA_METHOD("getAllDecoderNames", lua_video_Decoder_getAllDecoderNames);
	LUA_METHOD("getPixelFormatName", lua_video_Decoder_getPixelFormatName);
	LUA_METHOD("queryDecoderID", lua_video_Decoder_queryDecoderID);
	LUA_METHOD("queryDecoderLongName", lua_video_Decoder_queryDecoderLongName);
	LUA_METHOD("queryDecoderSupportsHardware", lua_video_Decoder_queryDecoderSupportsHardware);
	LUA_METHOD("queryDecoderType", lua_video_Decoder_queryDecoderType);
	LUA_CLS_END();
	LUA_ENTRY_END(1);
	return 0;
}
int luaReg_cc_video_videoPlayerPlayMode(lua_State* lua_S)
{
	LUA_ENUM_DEF("PlayMode");
	LUA_ENUM_ENTRY("STEP", video::Player::PlayMode::STEP);
	LUA_ENUM_ENTRY("REALTIME", video::Player::PlayMode::REALTIME);
	LUA_ENUM_ENTRY("FRAME", video::Player::PlayMode::FRAME);
	LUA_ENUM_ENTRY("MANUAL", video::Player::PlayMode::MANUAL);
	LUA_ENUM_END();
	return 0;
}
int lua_video_Player_getDecoder(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("video.Player", "video.Player:getDecoder");
	LUA_TRY_INVOKE_R(0, static_cast<video::Decoder*(video::Player::*)()const>(&video::Player::getDecoder));
	LUA_INVOKE_FOOTER("0");
}
int lua_video_Player_saveCurrentFrame(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("video.Player", "video.Player:saveCurrentFrame");
	LUA_TRY_INVOKE(1, static_cast<void(video::Player::*)(const std::string&)>(&video::Player::saveCurrentFrame));
	LUA_INVOKE_FOOTER("1");
}
int lua_video_Player_seek(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("video.Player", "video.Player:seek");
	LUA_TRY_INVOKE(1, static_cast<void(video::Player::*)(uint32_t)>(&video::Player::seek));
	LUA_INVOKE_FOOTER("1");
}
int lua_video_Player_setAutoRemove(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("video.Player", "video.Player:setAutoRemove");
	LUA_TRY_INVOKE(1, static_cast<void(video::Player::*)(bool)>(&video::Player::setAutoRemove));
	LUA_INVOKE_FOOTER("1");
}
int lua_video_Player_setPlayMode(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("video.Player", "video.Player:setPlayMode");
	LUA_TRY_INVOKE(1, static_cast<void(video::Player::*)(video::Player::PlayMode)>(&video::Player::setPlayMode));
	LUA_INVOKE_FOOTER("1");
}
int lua_video_Player_setStep(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("video.Player", "video.Player:setStep");
	LUA_TRY_INVOKE(1, static_cast<void(video::Player::*)(double)>(&video::Player::setStep));
	LUA_INVOKE_FOOTER("1");
}
int lua_video_Player_setVideoEndCallback(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("video.Player", "video.Player:setVideoEndCallback");
	LUA_TRY_INVOKE(1, static_cast<void(video::Player::*)(const std::function<void ()>&)>(&video::Player::setVideoEndCallback));
	LUA_INVOKE_FOOTER("1");
}
int lua_video_Player_vpause(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("video.Player", "video.Player:vpause");
	LUA_TRY_INVOKE(0, static_cast<void(video::Player::*)()>(&video::Player::vpause));
	LUA_INVOKE_FOOTER("0");
}
int lua_video_Player_vplay(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("video.Player", "video.Player:vplay");
	LUA_TRY_INVOKE(0, static_cast<void(video::Player::*)()>(&video::Player::vplay));
	LUA_INVOKE_FOOTER("0");
}
int lua_video_Player_vresume(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("video.Player", "video.Player:vresume");
	LUA_TRY_INVOKE(0, static_cast<void(video::Player::*)()>(&video::Player::vresume));
	LUA_INVOKE_FOOTER("0");
}
int lua_video_Player_vstop(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("video.Player", "video.Player:vstop");
	LUA_TRY_INVOKE(0, static_cast<void(video::Player::*)()>(&video::Player::vstop));
	LUA_INVOKE_FOOTER("0");
}
int lua_video_Player_create(lua_State* lua_S)
{
	LUA_SINVOKE_HEADER("video.Player", "video.Player:create");
	LUA_TRY_INVOKE_R(1, static_cast<video::Player*(*)(const std::string&)>(&video::Player::create));
	LUA_SINVOKE_FOOTER("1");
}
int luaReg_cc_video_videoPlayer(lua_State* lua_S)
{
	LUA_ENTRY("video");
	LUA_CLS_DEF_BASE(video::Player, "Player", "video.Player",
		cocos2d::Sprite, "cc.Sprite",
		nullptr, nullptr);
	LUA_METHOD("getDecoder", lua_video_Player_getDecoder);
	LUA_METHOD("saveCurrentFrame", lua_video_Player_saveCurrentFrame);
	LUA_METHOD("seek", lua_video_Player_seek);
	LUA_METHOD("setAutoRemove", lua_video_Player_setAutoRemove);
	LUA_METHOD("setPlayMode", lua_video_Player_setPlayMode);
	LUA_METHOD("setStep", lua_video_Player_setStep);
	LUA_METHOD("setVideoEndCallback", lua_video_Player_setVideoEndCallback);
	LUA_METHOD("vpause", lua_video_Player_vpause);
	LUA_METHOD("vplay", lua_video_Player_vplay);
	LUA_METHOD("vresume", lua_video_Player_vresume);
	LUA_METHOD("vstop", lua_video_Player_vstop);
	LUA_METHOD("create", lua_video_Player_create);
	luaReg_cc_video_videoPlayerPlayMode(lua_S);
	LUA_CLS_END();
	LUA_ENTRY_END(1);
	return 0;
}

int register_all_cc_video(lua_State* lua_S)
{
	luaReg_cc_video_videoDecoder(lua_S);
	luaReg_cc_video_videoPlayer(lua_S);
	return 0;
}
