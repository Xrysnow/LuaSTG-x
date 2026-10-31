#include "lua_cc_configuration_auto.hpp"
#include "lua_cc_configuration_compat.hpp"
#include "base/CCConfiguration.h"

int lua_cocos2d_Configuration_checkForGLExtension(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("cc.Configuration", "cc.Configuration:checkForGLExtension");
	LUA_TRY_INVOKE_R(1, static_cast<bool(cocos2d::Configuration::*)(std::string_view)const>(&cocos2d::Configuration::checkForGLExtension));
	LUA_INVOKE_FOOTER("1");
}
int lua_cocos2d_Configuration_gatherGPUInfo(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("cc.Configuration", "cc.Configuration:gatherGPUInfo");
	LUA_TRY_INVOKE(0, static_cast<void(cocos2d::Configuration::*)()>(&cocos2d::Configuration::gatherGPUInfo));
	LUA_INVOKE_FOOTER("0");
}
int lua_cocos2d_Configuration_getAnimate3DQuality(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("cc.Configuration", "cc.Configuration:getAnimate3DQuality");
	LUA_TRY_INVOKE_R(0, static_cast<cocos2d::Animate3DQuality(cocos2d::Configuration::*)()const>(&cocos2d::Configuration::getAnimate3DQuality));
	LUA_INVOKE_FOOTER("0");
}
int lua_cocos2d_Configuration_getInfo(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("cc.Configuration", "cc.Configuration:getInfo");
	LUA_TRY_INVOKE_R(0, static_cast<std::basic_string<char>(cocos2d::Configuration::*)()const>(&cocos2d::Configuration::getInfo));
	LUA_INVOKE_FOOTER("0");
}
int lua_cocos2d_Configuration_getMaxAttributes(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("cc.Configuration", "cc.Configuration:getMaxAttributes");
	LUA_TRY_INVOKE_R(0, static_cast<int(cocos2d::Configuration::*)()const>(&cocos2d::Configuration::getMaxAttributes));
	LUA_INVOKE_FOOTER("0");
}
int lua_cocos2d_Configuration_getMaxModelviewStackDepth(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("cc.Configuration", "cc.Configuration:getMaxModelviewStackDepth");
	LUA_TRY_INVOKE_R(0, static_cast<int(cocos2d::Configuration::*)()const>(&cocos2d::Configuration::getMaxModelviewStackDepth));
	LUA_INVOKE_FOOTER("0");
}
int lua_cocos2d_Configuration_getMaxSupportDirLightInShader(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("cc.Configuration", "cc.Configuration:getMaxSupportDirLightInShader");
	LUA_TRY_INVOKE_R(0, static_cast<int(cocos2d::Configuration::*)()const>(&cocos2d::Configuration::getMaxSupportDirLightInShader));
	LUA_INVOKE_FOOTER("0");
}
int lua_cocos2d_Configuration_getMaxSupportPointLightInShader(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("cc.Configuration", "cc.Configuration:getMaxSupportPointLightInShader");
	LUA_TRY_INVOKE_R(0, static_cast<int(cocos2d::Configuration::*)()const>(&cocos2d::Configuration::getMaxSupportPointLightInShader));
	LUA_INVOKE_FOOTER("0");
}
int lua_cocos2d_Configuration_getMaxSupportSpotLightInShader(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("cc.Configuration", "cc.Configuration:getMaxSupportSpotLightInShader");
	LUA_TRY_INVOKE_R(0, static_cast<int(cocos2d::Configuration::*)()const>(&cocos2d::Configuration::getMaxSupportSpotLightInShader));
	LUA_INVOKE_FOOTER("0");
}
int lua_cocos2d_Configuration_getMaxTextureSize(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("cc.Configuration", "cc.Configuration:getMaxTextureSize");
	LUA_TRY_INVOKE_R(0, static_cast<int(cocos2d::Configuration::*)()const>(&cocos2d::Configuration::getMaxTextureSize));
	LUA_INVOKE_FOOTER("0");
}
int lua_cocos2d_Configuration_getMaxTextureUnits(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("cc.Configuration", "cc.Configuration:getMaxTextureUnits");
	LUA_TRY_INVOKE_R(0, static_cast<int(cocos2d::Configuration::*)()const>(&cocos2d::Configuration::getMaxTextureUnits));
	LUA_INVOKE_FOOTER("0");
}
int lua_cocos2d_Configuration_init(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("cc.Configuration", "cc.Configuration:init");
	LUA_TRY_INVOKE_R(0, static_cast<bool(cocos2d::Configuration::*)()>(&cocos2d::Configuration::init));
	LUA_INVOKE_FOOTER("0");
}
int lua_cocos2d_Configuration_loadConfigFile(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("cc.Configuration", "cc.Configuration:loadConfigFile");
	LUA_TRY_INVOKE(1, static_cast<void(cocos2d::Configuration::*)(std::string_view)>(&cocos2d::Configuration::loadConfigFile));
	LUA_INVOKE_FOOTER("1");
}
int lua_cocos2d_Configuration_supportsATITC(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("cc.Configuration", "cc.Configuration:supportsATITC");
	LUA_TRY_INVOKE_R(0, static_cast<bool(cocos2d::Configuration::*)()const>(&cocos2d::Configuration::supportsATITC));
	LUA_INVOKE_FOOTER("0");
}
int lua_cocos2d_Configuration_supportsBGRA8888(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("cc.Configuration", "cc.Configuration:supportsBGRA8888");
	LUA_TRY_INVOKE_R(0, static_cast<bool(cocos2d::Configuration::*)()const>(&cocos2d::Configuration::supportsBGRA8888));
	LUA_INVOKE_FOOTER("0");
}
int lua_cocos2d_Configuration_supportsDiscardFramebuffer(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("cc.Configuration", "cc.Configuration:supportsDiscardFramebuffer");
	LUA_TRY_INVOKE_R(0, static_cast<bool(cocos2d::Configuration::*)()const>(&cocos2d::Configuration::supportsDiscardFramebuffer));
	LUA_INVOKE_FOOTER("0");
}
int lua_cocos2d_Configuration_supportsETC(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("cc.Configuration", "cc.Configuration:supportsETC");
	LUA_TRY_INVOKE_R(0, static_cast<bool(cocos2d::Configuration::*)()const>(&cocos2d::Configuration::supportsETC1));
	LUA_INVOKE_FOOTER("0");
}
int lua_cocos2d_Configuration_supportsMapBuffer(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("cc.Configuration", "cc.Configuration:supportsMapBuffer");
	LUA_TRY_INVOKE_R(0, static_cast<bool(cocos2d::Configuration::*)()const>(&cocos2d::Configuration::supportsMapBuffer));
	LUA_INVOKE_FOOTER("0");
}
int lua_cocos2d_Configuration_supportsNPOT(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("cc.Configuration", "cc.Configuration:supportsNPOT");
	LUA_TRY_INVOKE_R(0, static_cast<bool(cocos2d::Configuration::*)()const>(&cocos2d::Configuration::supportsNPOT));
	LUA_INVOKE_FOOTER("0");
}
int lua_cocos2d_Configuration_supportsOESDepth24(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("cc.Configuration", "cc.Configuration:supportsOESDepth24");
	LUA_TRY_INVOKE_R(0, static_cast<bool(cocos2d::Configuration::*)()const>(&cocos2d::Configuration::supportsOESDepth24));
	LUA_INVOKE_FOOTER("0");
}
int lua_cocos2d_Configuration_supportsOESPackedDepthStencil(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("cc.Configuration", "cc.Configuration:supportsOESPackedDepthStencil");
	LUA_TRY_INVOKE_R(0, static_cast<bool(cocos2d::Configuration::*)()const>(&cocos2d::Configuration::supportsOESPackedDepthStencil));
	LUA_INVOKE_FOOTER("0");
}
int lua_cocos2d_Configuration_supportsPVRTC(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("cc.Configuration", "cc.Configuration:supportsPVRTC");
	LUA_TRY_INVOKE_R(0, static_cast<bool(cocos2d::Configuration::*)()const>(&cocos2d::Configuration::supportsPVRTC));
	LUA_INVOKE_FOOTER("0");
}
int lua_cocos2d_Configuration_supportsS3TC(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("cc.Configuration", "cc.Configuration:supportsS3TC");
	LUA_TRY_INVOKE_R(0, static_cast<bool(cocos2d::Configuration::*)()const>(&cocos2d::Configuration::supportsS3TC));
	LUA_INVOKE_FOOTER("0");
}
int lua_cocos2d_Configuration_supportsShareableVAO(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("cc.Configuration", "cc.Configuration:supportsShareableVAO");
	LUA_TRY_INVOKE_R(0, static_cast<bool(cocos2d::Configuration::*)()const>(&cocos2d::Configuration::supportsShareableVAO));
	LUA_INVOKE_FOOTER("0");
}
int lua_cocos2d_Configuration_getInstance(lua_State* lua_S)
{
	LUA_SINVOKE_HEADER("cc.Configuration", "cc.Configuration:getInstance");
	LUA_TRY_INVOKE_R(0, static_cast<cocos2d::Configuration*(*)()>(&cocos2d::Configuration::getInstance));
	LUA_SINVOKE_FOOTER("0");
}
int luaReg_cc_configuration_ccConfiguration(lua_State* lua_S)
{
	LUA_ENTRY("cc");
	LUA_CLS_DEF(cocos2d::Configuration, "Configuration", "cc.Configuration",
		nullptr, nullptr);
	LUA_METHOD("checkForGLExtension", lua_cocos2d_Configuration_checkForGLExtension);
	LUA_METHOD("gatherGPUInfo", lua_cocos2d_Configuration_gatherGPUInfo);
	LUA_METHOD("getAnimate3DQuality", lua_cocos2d_Configuration_getAnimate3DQuality);
	LUA_METHOD("getInfo", lua_cocos2d_Configuration_getInfo);
	LUA_METHOD("getMaxAttributes", lua_cocos2d_Configuration_getMaxAttributes);
	LUA_METHOD("getMaxModelviewStackDepth", lua_cocos2d_Configuration_getMaxModelviewStackDepth);
	LUA_METHOD("getMaxSupportDirLightInShader", lua_cocos2d_Configuration_getMaxSupportDirLightInShader);
	LUA_METHOD("getMaxSupportPointLightInShader", lua_cocos2d_Configuration_getMaxSupportPointLightInShader);
	LUA_METHOD("getMaxSupportSpotLightInShader", lua_cocos2d_Configuration_getMaxSupportSpotLightInShader);
	LUA_METHOD("getMaxTextureSize", lua_cocos2d_Configuration_getMaxTextureSize);
	LUA_METHOD("getMaxTextureUnits", lua_cocos2d_Configuration_getMaxTextureUnits);
	LUA_METHOD("init", lua_cocos2d_Configuration_init);
	LUA_METHOD("loadConfigFile", lua_cocos2d_Configuration_loadConfigFile);
	LUA_METHOD("supportsATITC", lua_cocos2d_Configuration_supportsATITC);
	LUA_METHOD("supportsBGRA8888", lua_cocos2d_Configuration_supportsBGRA8888);
	LUA_METHOD("supportsDiscardFramebuffer", lua_cocos2d_Configuration_supportsDiscardFramebuffer);
	LUA_METHOD("supportsETC", lua_cocos2d_Configuration_supportsETC);
	LUA_METHOD("supportsMapBuffer", lua_cocos2d_Configuration_supportsMapBuffer);
	LUA_METHOD("supportsNPOT", lua_cocos2d_Configuration_supportsNPOT);
	LUA_METHOD("supportsOESDepth24", lua_cocos2d_Configuration_supportsOESDepth24);
	LUA_METHOD("supportsOESPackedDepthStencil", lua_cocos2d_Configuration_supportsOESPackedDepthStencil);
	LUA_METHOD("supportsPVRTC", lua_cocos2d_Configuration_supportsPVRTC);
	LUA_METHOD("supportsS3TC", lua_cocos2d_Configuration_supportsS3TC);
	LUA_METHOD("supportsShareableVAO", lua_cocos2d_Configuration_supportsShareableVAO);
	LUA_METHOD("getInstance", lua_cocos2d_Configuration_getInstance);
	LUA_CLS_END();
	LUA_ENTRY_END(1);
	return 0;
}

int register_all_cc_configuration(lua_State* lua_S)
{
	luaReg_cc_configuration_ccConfiguration(lua_S);
	return register_all_cc_configuration_manual(lua_S);
}
