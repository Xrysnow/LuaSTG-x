#include "lua_Resource_auto.hpp"
#include "Resource/GameResources.h"

int lua_lstg_Resource_getInfo(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("lstg.Resource", "lstg.Resource:getInfo");
	LUA_TRY_INVOKE_R(0, &lstg::Resource::getInfo);
	LUA_INVOKE_FOOTER("0");
}
int lua_lstg_Resource_getMemorySize(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("lstg.Resource", "lstg.Resource:getMemorySize");
	LUA_TRY_INVOKE_R(0, &lstg::Resource::getMemorySize);
	LUA_INVOKE_FOOTER("0");
}
int lua_lstg_Resource_getName(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("lstg.Resource", "lstg.Resource:getName");
	LUA_TRY_INVOKE_R(0, &lstg::Resource::getName);
	LUA_INVOKE_FOOTER("0");
}
int lua_lstg_Resource_getPath(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("lstg.Resource", "lstg.Resource:getPath");
	LUA_TRY_INVOKE_R(0, &lstg::Resource::getPath);
	LUA_INVOKE_FOOTER("0");
}
int lua_lstg_Resource_getType(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("lstg.Resource", "lstg.Resource:getType");
	LUA_TRY_INVOKE_R(0, &lstg::Resource::getType);
	LUA_INVOKE_FOOTER("0");
}
int lua_lstg_Resource_destroyInstances(lua_State* lua_S)
{
	LUA_SINVOKE_HEADER("lstg.Resource", "lstg.Resource:destroyInstances");
	LUA_TRY_INVOKE(0, &lstg::Resource::destroyInstances);
	LUA_SINVOKE_FOOTER("0");
}
int lua_lstg_Resource_getTotalMemorySize(lua_State* lua_S)
{
	LUA_SINVOKE_HEADER("lstg.Resource", "lstg.Resource:getTotalMemorySize");
	LUA_TRY_INVOKE_R(0, &lstg::Resource::getTotalMemorySize);
	LUA_SINVOKE_FOOTER("0");
}
int luaReg_Resource_lstgResource(lua_State* lua_S)
{
	LUA_ENTRY("lstg");
	LUA_CLS_DEF_BASE(lstg::Resource, "Resource", "lstg.Resource",
		cocos2d::Ref, "cc.Ref",
		nullptr, nullptr);
	LUA_METHOD("getInfo", lua_lstg_Resource_getInfo);
	LUA_METHOD("getMemorySize", lua_lstg_Resource_getMemorySize);
	LUA_METHOD("getName", lua_lstg_Resource_getName);
	LUA_METHOD("getPath", lua_lstg_Resource_getPath);
	LUA_METHOD("getType", lua_lstg_Resource_getType);
	LUA_METHOD("destroyInstances", lua_lstg_Resource_destroyInstances);
	LUA_METHOD("getTotalMemorySize", lua_lstg_Resource_getTotalMemorySize);
	LUA_CLS_END();
	LUA_ENTRY_END(1);
	return 0;
}
int lua_lstg_ResourceColliable_getColliderType(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("lstg.ResourceColliable", "lstg.ResourceColliable:getColliderType");
	LUA_TRY_INVOKE_R(0, &lstg::ResourceColliable::getColliderType);
	LUA_INVOKE_FOOTER("0");
}
int lua_lstg_ResourceColliable_getHalfSizeX(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("lstg.ResourceColliable", "lstg.ResourceColliable:getHalfSizeX");
	LUA_TRY_INVOKE_R(0, &lstg::ResourceColliable::getHalfSizeX);
	LUA_INVOKE_FOOTER("0");
}
int lua_lstg_ResourceColliable_getHalfSizeY(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("lstg.ResourceColliable", "lstg.ResourceColliable:getHalfSizeY");
	LUA_TRY_INVOKE_R(0, &lstg::ResourceColliable::getHalfSizeY);
	LUA_INVOKE_FOOTER("0");
}
int luaReg_Resource_lstgResourceColliable(lua_State* lua_S)
{
	LUA_ENTRY("lstg");
	LUA_CLS_DEF_BASE(lstg::ResourceColliable, "ResourceColliable", "lstg.ResourceColliable",
		lstg::Resource, "lstg.Resource",
		nullptr, nullptr);
	LUA_METHOD("getColliderType", lua_lstg_ResourceColliable_getColliderType);
	LUA_METHOD("getHalfSizeX", lua_lstg_ResourceColliable_getHalfSizeX);
	LUA_METHOD("getHalfSizeY", lua_lstg_ResourceColliable_getHalfSizeY);
	LUA_CLS_END();
	LUA_ENTRY_END(1);
	return 0;
}
int lua_lstg_ResourceQuad_getColor(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("lstg.ResourceQuad", "lstg.ResourceQuad:getColor");
	LUA_TRY_INVOKE_R(1, static_cast<cocos2d::Color4B(lstg::ResourceQuad::*)(int)const>(&lstg::ResourceQuad::getColor));
	LUA_TRY_INVOKE_R(0, [](lstg::ResourceQuad* obj){{return obj->getColor();}});
	LUA_INVOKE_FOOTER("0,1");
}
int lua_lstg_ResourceQuad_getRenderMode(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("lstg.ResourceQuad", "lstg.ResourceQuad:getRenderMode");
	LUA_TRY_INVOKE_R(0, &lstg::ResourceQuad::getRenderMode);
	LUA_INVOKE_FOOTER("0");
}
int lua_lstg_ResourceQuad_getVertex(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("lstg.ResourceQuad", "lstg.ResourceQuad:getVertex");
	LUA_TRY_INVOKE_R(0, &lstg::ResourceQuad::getVertex);
	LUA_INVOKE_FOOTER("0");
}
int lua_lstg_ResourceQuad_setAlpha(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("lstg.ResourceQuad", "lstg.ResourceQuad:setAlpha");
	LUA_TRY_INVOKE(1, &lstg::ResourceQuad::setAlpha);
	LUA_INVOKE_FOOTER("1");
}
int lua_lstg_ResourceQuad_setColor(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("lstg.ResourceQuad", "lstg.ResourceQuad:setColor");
	LUA_TRY_INVOKE(2, static_cast<void(lstg::ResourceQuad::*)(const cocos2d::Color4B&, int)>(&lstg::ResourceQuad::setColor));
	LUA_TRY_INVOKE(1, static_cast<void(lstg::ResourceQuad::*)(const cocos2d::Color4B&)>(&lstg::ResourceQuad::setColor));
	LUA_INVOKE_FOOTER("1,2");
}
int lua_lstg_ResourceQuad_setRenderMode(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("lstg.ResourceQuad", "lstg.ResourceQuad:setRenderMode");
	LUA_TRY_INVOKE(1, &lstg::ResourceQuad::setRenderMode);
	LUA_INVOKE_FOOTER("1");
}
int lua_lstg_ResourceQuad_setVertex(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("lstg.ResourceQuad", "lstg.ResourceQuad:setVertex");
	LUA_TRY_INVOKE(1, &lstg::ResourceQuad::setVertex);
	LUA_INVOKE_FOOTER("1");
}
int luaReg_Resource_lstgResourceQuad(lua_State* lua_S)
{
	LUA_ENTRY("lstg");
	LUA_CLS_DEF_BASE(lstg::ResourceQuad, "ResourceQuad", "lstg.ResourceQuad",
		lstg::ResourceColliable, "lstg.ResourceColliable",
		nullptr, nullptr);
	LUA_METHOD("getColor", lua_lstg_ResourceQuad_getColor);
	LUA_METHOD("getRenderMode", lua_lstg_ResourceQuad_getRenderMode);
	LUA_METHOD("getVertex", lua_lstg_ResourceQuad_getVertex);
	LUA_METHOD("setAlpha", lua_lstg_ResourceQuad_setAlpha);
	LUA_METHOD("setColor", lua_lstg_ResourceQuad_setColor);
	LUA_METHOD("setRenderMode", lua_lstg_ResourceQuad_setRenderMode);
	LUA_METHOD("setVertex", lua_lstg_ResourceQuad_setVertex);
	LUA_CLS_END();
	LUA_ENTRY_END(1);
	return 0;
}
int lua_lstg_ResTexture_getTexture(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("lstg.ResTexture", "lstg.ResTexture:getTexture");
	LUA_TRY_INVOKE_R(0, &lstg::ResTexture::getTexture);
	LUA_INVOKE_FOOTER("0");
}
int lua_lstg_ResTexture_getTriangles(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("lstg.ResTexture", "lstg.ResTexture:getTriangles");
	LUA_TRY_INVOKE_R(0, &lstg::ResTexture::getTriangles);
	LUA_INVOKE_FOOTER("0");
}
int lua_lstg_ResTexture_isTextureFlipped(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("lstg.ResTexture", "lstg.ResTexture:isTextureFlipped");
	LUA_TRY_INVOKE_R(0, &lstg::ResTexture::isTextureFlipped);
	LUA_INVOKE_FOOTER("0");
}
int lua_lstg_ResTexture_render(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("lstg.ResTexture", "lstg.ResTexture:render");
	LUA_TRY_INVOKE_R(2, static_cast<bool(lstg::ResTexture::*)(lstg::RenderMode*, const cocos2d::V3F_C4B_T2F_Quad&)>(&lstg::ResTexture::render));
	LUA_TRY_INVOKE_R(1, static_cast<bool(lstg::ResTexture::*)(const cocos2d::V3F_C4B_T2F_Quad&)>(&lstg::ResTexture::render));
	LUA_INVOKE_FOOTER("1,2");
}
int lua_lstg_ResTexture_setTriangles(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("lstg.ResTexture", "lstg.ResTexture:setTriangles");
	LUA_TRY_INVOKE(1, &lstg::ResTexture::setTriangles);
	LUA_INVOKE_FOOTER("1");
}
int lua_lstg_ResTexture_create(lua_State* lua_S)
{
	LUA_SINVOKE_HEADER("lstg.ResTexture", "lstg.ResTexture:create");
	LUA_TRY_INVOKE_R(2, &lstg::ResTexture::create);
	LUA_SINVOKE_FOOTER("2");
}
int lua_lstg_ResTexture_createWithTexture(lua_State* lua_S)
{
	LUA_SINVOKE_HEADER("lstg.ResTexture", "lstg.ResTexture:createWithTexture");
	LUA_TRY_INVOKE_R(2, &lstg::ResTexture::createWithTexture);
	LUA_SINVOKE_FOOTER("2");
}
int luaReg_Resource_lstgResTexture(lua_State* lua_S)
{
	LUA_ENTRY("lstg");
	LUA_CLS_DEF_BASE(lstg::ResTexture, "ResTexture", "lstg.ResTexture",
		lstg::Resource, "lstg.Resource",
		nullptr, nullptr);
	LUA_METHOD("getTexture", lua_lstg_ResTexture_getTexture);
	LUA_METHOD("getTriangles", lua_lstg_ResTexture_getTriangles);
	LUA_METHOD("isTextureFlipped", lua_lstg_ResTexture_isTextureFlipped);
	LUA_METHOD("render", lua_lstg_ResTexture_render);
	LUA_METHOD("setTriangles", lua_lstg_ResTexture_setTriangles);
	LUA_METHOD("create", lua_lstg_ResTexture_create);
	LUA_METHOD("createWithTexture", lua_lstg_ResTexture_createWithTexture);
	LUA_CLS_END();
	LUA_ENTRY_END(1);
	return 0;
}
int lua_lstg_ResAnimation_getCount(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("lstg.ResAnimation", "lstg.ResAnimation:getCount");
	LUA_TRY_INVOKE_R(0, &lstg::ResAnimation::getCount);
	LUA_INVOKE_FOOTER("0");
}
int lua_lstg_ResAnimation_getInterval(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("lstg.ResAnimation", "lstg.ResAnimation:getInterval");
	LUA_TRY_INVOKE_R(0, &lstg::ResAnimation::getInterval);
	LUA_INVOKE_FOOTER("0");
}
int lua_lstg_ResAnimation_getSprite(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("lstg.ResAnimation", "lstg.ResAnimation:getSprite");
	LUA_TRY_INVOKE_R(1, &lstg::ResAnimation::getSprite);
	LUA_INVOKE_FOOTER("1");
}
int lua_lstg_ResAnimation_getVertex(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("lstg.ResAnimation", "lstg.ResAnimation:getVertex");
	LUA_TRY_INVOKE_R(1, static_cast<cocos2d::V3F_C4B_T2F_Quad&(lstg::ResAnimation::*)(size_t)>(&lstg::ResAnimation::getVertex));
	LUA_TRY_INVOKE_R(0, static_cast<cocos2d::V3F_C4B_T2F_Quad&(lstg::ResAnimation::*)()>(&lstg::ResAnimation::getVertex));
	LUA_INVOKE_FOOTER("0,1");
}
int lua_lstg_ResAnimation_newCocosAnimation(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("lstg.ResAnimation", "lstg.ResAnimation:newCocosAnimation");
	LUA_TRY_INVOKE_R(0, &lstg::ResAnimation::newCocosAnimation);
	LUA_INVOKE_FOOTER("0");
}
int lua_lstg_ResAnimation_render(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("lstg.ResAnimation", "lstg.ResAnimation:render");
	LUA_TRY_INVOKE_R(6, static_cast<bool(lstg::ResAnimation::*)(int, float, float, float, float, float)>(&lstg::ResAnimation::render));
	LUA_TRY_INVOKE_R(5, [](lstg::ResAnimation* obj, int arg0,float arg1,float arg2,float arg3,float arg4){{return obj->render(std::move(arg0),std::move(arg1),std::move(arg2),std::move(arg3),std::move(arg4));}});
	LUA_TRY_INVOKE_R(4, [](lstg::ResAnimation* obj, int arg0,float arg1,float arg2,float arg3){{return obj->render(std::move(arg0),std::move(arg1),std::move(arg2),std::move(arg3));}});
	LUA_TRY_INVOKE_R(3, [](lstg::ResAnimation* obj, int arg0,float arg1,float arg2){{return obj->render(std::move(arg0),std::move(arg1),std::move(arg2));}});
	LUA_INVOKE_FOOTER("3,4,5,6");
}
int lua_lstg_ResAnimation_setInterval(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("lstg.ResAnimation", "lstg.ResAnimation:setInterval");
	LUA_TRY_INVOKE(1, &lstg::ResAnimation::setInterval);
	LUA_INVOKE_FOOTER("1");
}
int lua_lstg_ResAnimation_setVertex(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("lstg.ResAnimation", "lstg.ResAnimation:setVertex");
	LUA_TRY_INVOKE(2, static_cast<void(lstg::ResAnimation::*)(const cocos2d::V3F_C4B_T2F_Quad&, size_t)>(&lstg::ResAnimation::setVertex));
	LUA_TRY_INVOKE(1, static_cast<void(lstg::ResAnimation::*)(const cocos2d::V3F_C4B_T2F_Quad&)>(&lstg::ResAnimation::setVertex));
	LUA_INVOKE_FOOTER("1,2");
}
int lua_lstg_ResAnimation_create(lua_State* lua_S)
{
	LUA_SINVOKE_HEADER("lstg.ResAnimation", "lstg.ResAnimation:create");
	LUA_TRY_INVOKE_R(12, &lstg::ResAnimation::create);
	LUA_SINVOKE_FOOTER("12");
}
int luaReg_Resource_lstgResAnimation(lua_State* lua_S)
{
	LUA_ENTRY("lstg");
	LUA_CLS_DEF_BASE(lstg::ResAnimation, "ResAnimation", "lstg.ResAnimation",
		lstg::ResourceQuad, "lstg.ResourceQuad",
		nullptr, nullptr);
	LUA_METHOD("getCount", lua_lstg_ResAnimation_getCount);
	LUA_METHOD("getInterval", lua_lstg_ResAnimation_getInterval);
	LUA_METHOD("getSprite", lua_lstg_ResAnimation_getSprite);
	LUA_METHOD("getVertex", lua_lstg_ResAnimation_getVertex);
	LUA_METHOD("newCocosAnimation", lua_lstg_ResAnimation_newCocosAnimation);
	LUA_METHOD("render", lua_lstg_ResAnimation_render);
	LUA_METHOD("setInterval", lua_lstg_ResAnimation_setInterval);
	LUA_METHOD("setVertex", lua_lstg_ResAnimation_setVertex);
	LUA_METHOD("create", lua_lstg_ResAnimation_create);
	LUA_CLS_END();
	LUA_ENTRY_END(1);
	return 0;
}
int lua_lstg_ResSprite_clone(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("lstg.ResSprite", "lstg.ResSprite:clone");
	LUA_TRY_INVOKE_R(1, &lstg::ResSprite::clone);
	LUA_INVOKE_FOOTER("1");
}
int lua_lstg_ResSprite_getNormalMap(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("lstg.ResSprite", "lstg.ResSprite:getNormalMap");
	LUA_TRY_INVOKE_R(0, &lstg::ResSprite::getNormalMap);
	LUA_INVOKE_FOOTER("0");
}
int lua_lstg_ResSprite_getSprite(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("lstg.ResSprite", "lstg.ResSprite:getSprite");
	LUA_TRY_INVOKE_R(0, &lstg::ResSprite::getSprite);
	LUA_INVOKE_FOOTER("0");
}
int lua_lstg_ResSprite_getTexture(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("lstg.ResSprite", "lstg.ResSprite:getTexture");
	LUA_TRY_INVOKE_R(0, &lstg::ResSprite::getTexture);
	LUA_INVOKE_FOOTER("0");
}
int lua_lstg_ResSprite_render(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("lstg.ResSprite", "lstg.ResSprite:render");
	LUA_TRY_INVOKE_R(6, static_cast<bool(lstg::ResSprite::*)(float, float, float, float, float, float)>(&lstg::ResSprite::render));
	LUA_TRY_INVOKE_R(5, [](lstg::ResSprite* obj, float arg0,float arg1,float arg2,float arg3,float arg4){{return obj->render(std::move(arg0),std::move(arg1),std::move(arg2),std::move(arg3),std::move(arg4));}});
	LUA_TRY_INVOKE_R(4, [](lstg::ResSprite* obj, float arg0,float arg1,float arg2,float arg3){{return obj->render(std::move(arg0),std::move(arg1),std::move(arg2),std::move(arg3));}});
	LUA_TRY_INVOKE_R(3, [](lstg::ResSprite* obj, float arg0,float arg1,float arg2){{return obj->render(std::move(arg0),std::move(arg1),std::move(arg2));}});
	LUA_TRY_INVOKE_R(2, [](lstg::ResSprite* obj, float arg0,float arg1){{return obj->render(std::move(arg0),std::move(arg1));}});
	LUA_INVOKE_FOOTER("2,3,4,5,6");
}
int lua_lstg_ResSprite_render4v(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("lstg.ResSprite", "lstg.ResSprite:render4v");
	LUA_TRY_INVOKE_R(12, &lstg::ResSprite::render4v);
	LUA_INVOKE_FOOTER("12");
}
int lua_lstg_ResSprite_renderRect(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("lstg.ResSprite", "lstg.ResSprite:renderRect");
	LUA_TRY_INVOKE_R(4, &lstg::ResSprite::renderRect);
	LUA_INVOKE_FOOTER("4");
}
int lua_lstg_ResSprite_setNormalMap(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("lstg.ResSprite", "lstg.ResSprite:setNormalMap");
	LUA_TRY_INVOKE(1, &lstg::ResSprite::setNormalMap);
	LUA_INVOKE_FOOTER("1");
}
int lua_lstg_ResSprite_create(lua_State* lua_S)
{
	LUA_SINVOKE_HEADER("lstg.ResSprite", "lstg.ResSprite:create");
	LUA_TRY_INVOKE_R(9, &lstg::ResSprite::create);
	LUA_SINVOKE_FOOTER("9");
}
int lua_lstg_ResSprite_createWithSprite(lua_State* lua_S)
{
	LUA_SINVOKE_HEADER("lstg.ResSprite", "lstg.ResSprite:createWithSprite");
	LUA_TRY_INVOKE_R(5, &lstg::ResSprite::createWithSprite);
	LUA_SINVOKE_FOOTER("5");
}
int luaReg_Resource_lstgResSprite(lua_State* lua_S)
{
	LUA_ENTRY("lstg");
	LUA_CLS_DEF_BASE(lstg::ResSprite, "ResSprite", "lstg.ResSprite",
		lstg::ResourceQuad, "lstg.ResourceQuad",
		nullptr, nullptr);
	LUA_METHOD("clone", lua_lstg_ResSprite_clone);
	LUA_METHOD("getNormalMap", lua_lstg_ResSprite_getNormalMap);
	LUA_METHOD("getSprite", lua_lstg_ResSprite_getSprite);
	LUA_METHOD("getTexture", lua_lstg_ResSprite_getTexture);
	LUA_METHOD("render", lua_lstg_ResSprite_render);
	LUA_METHOD("render4v", lua_lstg_ResSprite_render4v);
	LUA_METHOD("renderRect", lua_lstg_ResSprite_renderRect);
	LUA_METHOD("setNormalMap", lua_lstg_ResSprite_setNormalMap);
	LUA_METHOD("create", lua_lstg_ResSprite_create);
	LUA_METHOD("createWithSprite", lua_lstg_ResSprite_createWithSprite);
	LUA_CLS_END();
	LUA_ENTRY_END(1);
	return 0;
}
int luaReg_Resource_lstgResParticleParticlePoolStatus(lua_State* lua_S)
{
	LUA_ENUM_DEF("Status");
	LUA_ENUM_ENTRY("Alive", lstg::ResParticle::ParticlePool::Status::Alive);
	LUA_ENUM_ENTRY("Sleep", lstg::ResParticle::ParticlePool::Status::Sleep);
	LUA_ENUM_END();
	return 0;
}
int lua_lstg_ResParticle_ParticlePool_getAliveCount(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("lstg.ResParticle.ParticlePool", "lstg.ResParticle.ParticlePool:getAliveCount");
	LUA_TRY_INVOKE_R(0, &lstg::ResParticle::ParticlePool::getAliveCount);
	LUA_INVOKE_FOOTER("0");
}
int lua_lstg_ResParticle_ParticlePool_getAlphaVar(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("lstg.ResParticle.ParticlePool", "lstg.ResParticle.ParticlePool:getAlphaVar");
	LUA_TRY_INVOKE_R(0, &lstg::ResParticle::ParticlePool::getAlphaVar);
	LUA_INVOKE_FOOTER("0");
}
int lua_lstg_ResParticle_ParticlePool_getCenter(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("lstg.ResParticle.ParticlePool", "lstg.ResParticle.ParticlePool:getCenter");
	LUA_TRY_INVOKE_R(0, &lstg::ResParticle::ParticlePool::getCenter);
	LUA_INVOKE_FOOTER("0");
}
int lua_lstg_ResParticle_ParticlePool_getColorEnd(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("lstg.ResParticle.ParticlePool", "lstg.ResParticle.ParticlePool:getColorEnd");
	LUA_TRY_INVOKE_R(0, &lstg::ResParticle::ParticlePool::getColorEnd);
	LUA_INVOKE_FOOTER("0");
}
int lua_lstg_ResParticle_ParticlePool_getColorStart(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("lstg.ResParticle.ParticlePool", "lstg.ResParticle.ParticlePool:getColorStart");
	LUA_TRY_INVOKE_R(0, &lstg::ResParticle::ParticlePool::getColorStart);
	LUA_INVOKE_FOOTER("0");
}
int lua_lstg_ResParticle_ParticlePool_getColorVar(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("lstg.ResParticle.ParticlePool", "lstg.ResParticle.ParticlePool:getColorVar");
	LUA_TRY_INVOKE_R(0, &lstg::ResParticle::ParticlePool::getColorVar);
	LUA_INVOKE_FOOTER("0");
}
int lua_lstg_ResParticle_ParticlePool_getDirection(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("lstg.ResParticle.ParticlePool", "lstg.ResParticle.ParticlePool:getDirection");
	LUA_TRY_INVOKE_R(0, &lstg::ResParticle::ParticlePool::getDirection);
	LUA_INVOKE_FOOTER("0");
}
int lua_lstg_ResParticle_ParticlePool_getEmissionFreq(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("lstg.ResParticle.ParticlePool", "lstg.ResParticle.ParticlePool:getEmissionFreq");
	LUA_TRY_INVOKE_R(0, &lstg::ResParticle::ParticlePool::getEmissionFreq);
	LUA_INVOKE_FOOTER("0");
}
int lua_lstg_ResParticle_ParticlePool_getGravityMax(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("lstg.ResParticle.ParticlePool", "lstg.ResParticle.ParticlePool:getGravityMax");
	LUA_TRY_INVOKE_R(0, &lstg::ResParticle::ParticlePool::getGravityMax);
	LUA_INVOKE_FOOTER("0");
}
int lua_lstg_ResParticle_ParticlePool_getGravityMin(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("lstg.ResParticle.ParticlePool", "lstg.ResParticle.ParticlePool:getGravityMin");
	LUA_TRY_INVOKE_R(0, &lstg::ResParticle::ParticlePool::getGravityMin);
	LUA_INVOKE_FOOTER("0");
}
int lua_lstg_ResParticle_ParticlePool_getLifeMax(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("lstg.ResParticle.ParticlePool", "lstg.ResParticle.ParticlePool:getLifeMax");
	LUA_TRY_INVOKE_R(0, &lstg::ResParticle::ParticlePool::getLifeMax);
	LUA_INVOKE_FOOTER("0");
}
int lua_lstg_ResParticle_ParticlePool_getLifeMin(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("lstg.ResParticle.ParticlePool", "lstg.ResParticle.ParticlePool:getLifeMin");
	LUA_TRY_INVOKE_R(0, &lstg::ResParticle::ParticlePool::getLifeMin);
	LUA_INVOKE_FOOTER("0");
}
int lua_lstg_ResParticle_ParticlePool_getLifetime(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("lstg.ResParticle.ParticlePool", "lstg.ResParticle.ParticlePool:getLifetime");
	LUA_TRY_INVOKE_R(0, &lstg::ResParticle::ParticlePool::getLifetime);
	LUA_INVOKE_FOOTER("0");
}
int lua_lstg_ResParticle_ParticlePool_getRadialAccelMax(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("lstg.ResParticle.ParticlePool", "lstg.ResParticle.ParticlePool:getRadialAccelMax");
	LUA_TRY_INVOKE_R(0, &lstg::ResParticle::ParticlePool::getRadialAccelMax);
	LUA_INVOKE_FOOTER("0");
}
int lua_lstg_ResParticle_ParticlePool_getRadialAccelMin(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("lstg.ResParticle.ParticlePool", "lstg.ResParticle.ParticlePool:getRadialAccelMin");
	LUA_TRY_INVOKE_R(0, &lstg::ResParticle::ParticlePool::getRadialAccelMin);
	LUA_INVOKE_FOOTER("0");
}
int lua_lstg_ResParticle_ParticlePool_getRelative(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("lstg.ResParticle.ParticlePool", "lstg.ResParticle.ParticlePool:getRelative");
	LUA_TRY_INVOKE_R(0, &lstg::ResParticle::ParticlePool::getRelative);
	LUA_INVOKE_FOOTER("0");
}
int lua_lstg_ResParticle_ParticlePool_getRenderMode(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("lstg.ResParticle.ParticlePool", "lstg.ResParticle.ParticlePool:getRenderMode");
	LUA_TRY_INVOKE_R(0, &lstg::ResParticle::ParticlePool::getRenderMode);
	LUA_INVOKE_FOOTER("0");
}
int lua_lstg_ResParticle_ParticlePool_getResource(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("lstg.ResParticle.ParticlePool", "lstg.ResParticle.ParticlePool:getResource");
	LUA_TRY_INVOKE_R(0, &lstg::ResParticle::ParticlePool::getResource);
	LUA_INVOKE_FOOTER("0");
}
int lua_lstg_ResParticle_ParticlePool_getRotation(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("lstg.ResParticle.ParticlePool", "lstg.ResParticle.ParticlePool:getRotation");
	LUA_TRY_INVOKE_R(0, &lstg::ResParticle::ParticlePool::getRotation);
	LUA_INVOKE_FOOTER("0");
}
int lua_lstg_ResParticle_ParticlePool_getSeed(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("lstg.ResParticle.ParticlePool", "lstg.ResParticle.ParticlePool:getSeed");
	LUA_TRY_INVOKE_R(0, &lstg::ResParticle::ParticlePool::getSeed);
	LUA_INVOKE_FOOTER("0");
}
int lua_lstg_ResParticle_ParticlePool_getSizeEnd(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("lstg.ResParticle.ParticlePool", "lstg.ResParticle.ParticlePool:getSizeEnd");
	LUA_TRY_INVOKE_R(0, &lstg::ResParticle::ParticlePool::getSizeEnd);
	LUA_INVOKE_FOOTER("0");
}
int lua_lstg_ResParticle_ParticlePool_getSizeStart(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("lstg.ResParticle.ParticlePool", "lstg.ResParticle.ParticlePool:getSizeStart");
	LUA_TRY_INVOKE_R(0, &lstg::ResParticle::ParticlePool::getSizeStart);
	LUA_INVOKE_FOOTER("0");
}
int lua_lstg_ResParticle_ParticlePool_getSizeVar(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("lstg.ResParticle.ParticlePool", "lstg.ResParticle.ParticlePool:getSizeVar");
	LUA_TRY_INVOKE_R(0, &lstg::ResParticle::ParticlePool::getSizeVar);
	LUA_INVOKE_FOOTER("0");
}
int lua_lstg_ResParticle_ParticlePool_getSpeedMax(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("lstg.ResParticle.ParticlePool", "lstg.ResParticle.ParticlePool:getSpeedMax");
	LUA_TRY_INVOKE_R(0, &lstg::ResParticle::ParticlePool::getSpeedMax);
	LUA_INVOKE_FOOTER("0");
}
int lua_lstg_ResParticle_ParticlePool_getSpeedMin(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("lstg.ResParticle.ParticlePool", "lstg.ResParticle.ParticlePool:getSpeedMin");
	LUA_TRY_INVOKE_R(0, &lstg::ResParticle::ParticlePool::getSpeedMin);
	LUA_INVOKE_FOOTER("0");
}
int lua_lstg_ResParticle_ParticlePool_getSpinEnd(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("lstg.ResParticle.ParticlePool", "lstg.ResParticle.ParticlePool:getSpinEnd");
	LUA_TRY_INVOKE_R(0, &lstg::ResParticle::ParticlePool::getSpinEnd);
	LUA_INVOKE_FOOTER("0");
}
int lua_lstg_ResParticle_ParticlePool_getSpinStart(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("lstg.ResParticle.ParticlePool", "lstg.ResParticle.ParticlePool:getSpinStart");
	LUA_TRY_INVOKE_R(0, &lstg::ResParticle::ParticlePool::getSpinStart);
	LUA_INVOKE_FOOTER("0");
}
int lua_lstg_ResParticle_ParticlePool_getSpinVar(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("lstg.ResParticle.ParticlePool", "lstg.ResParticle.ParticlePool:getSpinVar");
	LUA_TRY_INVOKE_R(0, &lstg::ResParticle::ParticlePool::getSpinVar);
	LUA_INVOKE_FOOTER("0");
}
int lua_lstg_ResParticle_ParticlePool_getSpread(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("lstg.ResParticle.ParticlePool", "lstg.ResParticle.ParticlePool:getSpread");
	LUA_TRY_INVOKE_R(0, &lstg::ResParticle::ParticlePool::getSpread);
	LUA_INVOKE_FOOTER("0");
}
int lua_lstg_ResParticle_ParticlePool_getTangentialAccelMax(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("lstg.ResParticle.ParticlePool", "lstg.ResParticle.ParticlePool:getTangentialAccelMax");
	LUA_TRY_INVOKE_R(0, &lstg::ResParticle::ParticlePool::getTangentialAccelMax);
	LUA_INVOKE_FOOTER("0");
}
int lua_lstg_ResParticle_ParticlePool_getTangentialAccelMin(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("lstg.ResParticle.ParticlePool", "lstg.ResParticle.ParticlePool:getTangentialAccelMin");
	LUA_TRY_INVOKE_R(0, &lstg::ResParticle::ParticlePool::getTangentialAccelMin);
	LUA_INVOKE_FOOTER("0");
}
int lua_lstg_ResParticle_ParticlePool_isActive(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("lstg.ResParticle.ParticlePool", "lstg.ResParticle.ParticlePool:isActive");
	LUA_TRY_INVOKE_R(0, &lstg::ResParticle::ParticlePool::isActive);
	LUA_INVOKE_FOOTER("0");
}
int lua_lstg_ResParticle_ParticlePool_setActive(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("lstg.ResParticle.ParticlePool", "lstg.ResParticle.ParticlePool:setActive");
	LUA_TRY_INVOKE(1, &lstg::ResParticle::ParticlePool::setActive);
	LUA_INVOKE_FOOTER("1");
}
int lua_lstg_ResParticle_ParticlePool_setAlphaVar(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("lstg.ResParticle.ParticlePool", "lstg.ResParticle.ParticlePool:setAlphaVar");
	LUA_TRY_INVOKE(1, &lstg::ResParticle::ParticlePool::setAlphaVar);
	LUA_INVOKE_FOOTER("1");
}
int lua_lstg_ResParticle_ParticlePool_setCenter(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("lstg.ResParticle.ParticlePool", "lstg.ResParticle.ParticlePool:setCenter");
	LUA_TRY_INVOKE(1, &lstg::ResParticle::ParticlePool::setCenter);
	LUA_INVOKE_FOOTER("1");
}
int lua_lstg_ResParticle_ParticlePool_setColorEnd(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("lstg.ResParticle.ParticlePool", "lstg.ResParticle.ParticlePool:setColorEnd");
	LUA_TRY_INVOKE(1, &lstg::ResParticle::ParticlePool::setColorEnd);
	LUA_INVOKE_FOOTER("1");
}
int lua_lstg_ResParticle_ParticlePool_setColorStart(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("lstg.ResParticle.ParticlePool", "lstg.ResParticle.ParticlePool:setColorStart");
	LUA_TRY_INVOKE(1, &lstg::ResParticle::ParticlePool::setColorStart);
	LUA_INVOKE_FOOTER("1");
}
int lua_lstg_ResParticle_ParticlePool_setColorVar(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("lstg.ResParticle.ParticlePool", "lstg.ResParticle.ParticlePool:setColorVar");
	LUA_TRY_INVOKE(1, &lstg::ResParticle::ParticlePool::setColorVar);
	LUA_INVOKE_FOOTER("1");
}
int lua_lstg_ResParticle_ParticlePool_setDirection(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("lstg.ResParticle.ParticlePool", "lstg.ResParticle.ParticlePool:setDirection");
	LUA_TRY_INVOKE(1, &lstg::ResParticle::ParticlePool::setDirection);
	LUA_INVOKE_FOOTER("1");
}
int lua_lstg_ResParticle_ParticlePool_setEmissionFreq(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("lstg.ResParticle.ParticlePool", "lstg.ResParticle.ParticlePool:setEmissionFreq");
	LUA_TRY_INVOKE(1, &lstg::ResParticle::ParticlePool::setEmissionFreq);
	LUA_INVOKE_FOOTER("1");
}
int lua_lstg_ResParticle_ParticlePool_setGravityMax(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("lstg.ResParticle.ParticlePool", "lstg.ResParticle.ParticlePool:setGravityMax");
	LUA_TRY_INVOKE(1, &lstg::ResParticle::ParticlePool::setGravityMax);
	LUA_INVOKE_FOOTER("1");
}
int lua_lstg_ResParticle_ParticlePool_setGravityMin(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("lstg.ResParticle.ParticlePool", "lstg.ResParticle.ParticlePool:setGravityMin");
	LUA_TRY_INVOKE(1, &lstg::ResParticle::ParticlePool::setGravityMin);
	LUA_INVOKE_FOOTER("1");
}
int lua_lstg_ResParticle_ParticlePool_setLifeMax(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("lstg.ResParticle.ParticlePool", "lstg.ResParticle.ParticlePool:setLifeMax");
	LUA_TRY_INVOKE(1, &lstg::ResParticle::ParticlePool::setLifeMax);
	LUA_INVOKE_FOOTER("1");
}
int lua_lstg_ResParticle_ParticlePool_setLifeMin(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("lstg.ResParticle.ParticlePool", "lstg.ResParticle.ParticlePool:setLifeMin");
	LUA_TRY_INVOKE(1, &lstg::ResParticle::ParticlePool::setLifeMin);
	LUA_INVOKE_FOOTER("1");
}
int lua_lstg_ResParticle_ParticlePool_setLifetime(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("lstg.ResParticle.ParticlePool", "lstg.ResParticle.ParticlePool:setLifetime");
	LUA_TRY_INVOKE(1, &lstg::ResParticle::ParticlePool::setLifetime);
	LUA_INVOKE_FOOTER("1");
}
int lua_lstg_ResParticle_ParticlePool_setRadialAccelMax(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("lstg.ResParticle.ParticlePool", "lstg.ResParticle.ParticlePool:setRadialAccelMax");
	LUA_TRY_INVOKE(1, &lstg::ResParticle::ParticlePool::setRadialAccelMax);
	LUA_INVOKE_FOOTER("1");
}
int lua_lstg_ResParticle_ParticlePool_setRadialAccelMin(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("lstg.ResParticle.ParticlePool", "lstg.ResParticle.ParticlePool:setRadialAccelMin");
	LUA_TRY_INVOKE(1, &lstg::ResParticle::ParticlePool::setRadialAccelMin);
	LUA_INVOKE_FOOTER("1");
}
int lua_lstg_ResParticle_ParticlePool_setRelative(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("lstg.ResParticle.ParticlePool", "lstg.ResParticle.ParticlePool:setRelative");
	LUA_TRY_INVOKE(1, &lstg::ResParticle::ParticlePool::setRelative);
	LUA_INVOKE_FOOTER("1");
}
int lua_lstg_ResParticle_ParticlePool_setRenderMode(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("lstg.ResParticle.ParticlePool", "lstg.ResParticle.ParticlePool:setRenderMode");
	LUA_TRY_INVOKE(1, &lstg::ResParticle::ParticlePool::setRenderMode);
	LUA_INVOKE_FOOTER("1");
}
int lua_lstg_ResParticle_ParticlePool_setRotation(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("lstg.ResParticle.ParticlePool", "lstg.ResParticle.ParticlePool:setRotation");
	LUA_TRY_INVOKE(1, &lstg::ResParticle::ParticlePool::setRotation);
	LUA_INVOKE_FOOTER("1");
}
int lua_lstg_ResParticle_ParticlePool_setSeed(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("lstg.ResParticle.ParticlePool", "lstg.ResParticle.ParticlePool:setSeed");
	LUA_TRY_INVOKE(1, &lstg::ResParticle::ParticlePool::setSeed);
	LUA_INVOKE_FOOTER("1");
}
int lua_lstg_ResParticle_ParticlePool_setSizeEnd(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("lstg.ResParticle.ParticlePool", "lstg.ResParticle.ParticlePool:setSizeEnd");
	LUA_TRY_INVOKE(1, &lstg::ResParticle::ParticlePool::setSizeEnd);
	LUA_INVOKE_FOOTER("1");
}
int lua_lstg_ResParticle_ParticlePool_setSizeStart(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("lstg.ResParticle.ParticlePool", "lstg.ResParticle.ParticlePool:setSizeStart");
	LUA_TRY_INVOKE(1, &lstg::ResParticle::ParticlePool::setSizeStart);
	LUA_INVOKE_FOOTER("1");
}
int lua_lstg_ResParticle_ParticlePool_setSizeVar(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("lstg.ResParticle.ParticlePool", "lstg.ResParticle.ParticlePool:setSizeVar");
	LUA_TRY_INVOKE(1, &lstg::ResParticle::ParticlePool::setSizeVar);
	LUA_INVOKE_FOOTER("1");
}
int lua_lstg_ResParticle_ParticlePool_setSpeedMax(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("lstg.ResParticle.ParticlePool", "lstg.ResParticle.ParticlePool:setSpeedMax");
	LUA_TRY_INVOKE(1, &lstg::ResParticle::ParticlePool::setSpeedMax);
	LUA_INVOKE_FOOTER("1");
}
int lua_lstg_ResParticle_ParticlePool_setSpeedMin(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("lstg.ResParticle.ParticlePool", "lstg.ResParticle.ParticlePool:setSpeedMin");
	LUA_TRY_INVOKE(1, &lstg::ResParticle::ParticlePool::setSpeedMin);
	LUA_INVOKE_FOOTER("1");
}
int lua_lstg_ResParticle_ParticlePool_setSpinEnd(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("lstg.ResParticle.ParticlePool", "lstg.ResParticle.ParticlePool:setSpinEnd");
	LUA_TRY_INVOKE(1, &lstg::ResParticle::ParticlePool::setSpinEnd);
	LUA_INVOKE_FOOTER("1");
}
int lua_lstg_ResParticle_ParticlePool_setSpinStart(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("lstg.ResParticle.ParticlePool", "lstg.ResParticle.ParticlePool:setSpinStart");
	LUA_TRY_INVOKE(1, &lstg::ResParticle::ParticlePool::setSpinStart);
	LUA_INVOKE_FOOTER("1");
}
int lua_lstg_ResParticle_ParticlePool_setSpinVar(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("lstg.ResParticle.ParticlePool", "lstg.ResParticle.ParticlePool:setSpinVar");
	LUA_TRY_INVOKE(1, &lstg::ResParticle::ParticlePool::setSpinVar);
	LUA_INVOKE_FOOTER("1");
}
int lua_lstg_ResParticle_ParticlePool_setSpread(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("lstg.ResParticle.ParticlePool", "lstg.ResParticle.ParticlePool:setSpread");
	LUA_TRY_INVOKE(1, &lstg::ResParticle::ParticlePool::setSpread);
	LUA_INVOKE_FOOTER("1");
}
int lua_lstg_ResParticle_ParticlePool_setTangentialAccelMax(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("lstg.ResParticle.ParticlePool", "lstg.ResParticle.ParticlePool:setTangentialAccelMax");
	LUA_TRY_INVOKE(1, &lstg::ResParticle::ParticlePool::setTangentialAccelMax);
	LUA_INVOKE_FOOTER("1");
}
int lua_lstg_ResParticle_ParticlePool_setTangentialAccelMin(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("lstg.ResParticle.ParticlePool", "lstg.ResParticle.ParticlePool:setTangentialAccelMin");
	LUA_TRY_INVOKE(1, &lstg::ResParticle::ParticlePool::setTangentialAccelMin);
	LUA_INVOKE_FOOTER("1");
}
int luaReg_Resource_lstgResParticleParticlePool(lua_State* lua_S)
{
	LUA_ENTRY("lstg");
	LUA_ENTRY("ResParticle");
	LUA_CLS_DEF_BASE(lstg::ResParticle::ParticlePool, "ParticlePool", "lstg.ResParticle.ParticlePool",
		cocos2d::Ref, "cc.Ref",
		nullptr, nullptr);
	LUA_METHOD("getAliveCount", lua_lstg_ResParticle_ParticlePool_getAliveCount);
	LUA_METHOD("getAlphaVar", lua_lstg_ResParticle_ParticlePool_getAlphaVar);
	LUA_METHOD("getCenter", lua_lstg_ResParticle_ParticlePool_getCenter);
	LUA_METHOD("getColorEnd", lua_lstg_ResParticle_ParticlePool_getColorEnd);
	LUA_METHOD("getColorStart", lua_lstg_ResParticle_ParticlePool_getColorStart);
	LUA_METHOD("getColorVar", lua_lstg_ResParticle_ParticlePool_getColorVar);
	LUA_METHOD("getDirection", lua_lstg_ResParticle_ParticlePool_getDirection);
	LUA_METHOD("getEmissionFreq", lua_lstg_ResParticle_ParticlePool_getEmissionFreq);
	LUA_METHOD("getGravityMax", lua_lstg_ResParticle_ParticlePool_getGravityMax);
	LUA_METHOD("getGravityMin", lua_lstg_ResParticle_ParticlePool_getGravityMin);
	LUA_METHOD("getLifeMax", lua_lstg_ResParticle_ParticlePool_getLifeMax);
	LUA_METHOD("getLifeMin", lua_lstg_ResParticle_ParticlePool_getLifeMin);
	LUA_METHOD("getLifetime", lua_lstg_ResParticle_ParticlePool_getLifetime);
	LUA_METHOD("getRadialAccelMax", lua_lstg_ResParticle_ParticlePool_getRadialAccelMax);
	LUA_METHOD("getRadialAccelMin", lua_lstg_ResParticle_ParticlePool_getRadialAccelMin);
	LUA_METHOD("getRelative", lua_lstg_ResParticle_ParticlePool_getRelative);
	LUA_METHOD("getRenderMode", lua_lstg_ResParticle_ParticlePool_getRenderMode);
	LUA_METHOD("getResource", lua_lstg_ResParticle_ParticlePool_getResource);
	LUA_METHOD("getRotation", lua_lstg_ResParticle_ParticlePool_getRotation);
	LUA_METHOD("getSeed", lua_lstg_ResParticle_ParticlePool_getSeed);
	LUA_METHOD("getSizeEnd", lua_lstg_ResParticle_ParticlePool_getSizeEnd);
	LUA_METHOD("getSizeStart", lua_lstg_ResParticle_ParticlePool_getSizeStart);
	LUA_METHOD("getSizeVar", lua_lstg_ResParticle_ParticlePool_getSizeVar);
	LUA_METHOD("getSpeedMax", lua_lstg_ResParticle_ParticlePool_getSpeedMax);
	LUA_METHOD("getSpeedMin", lua_lstg_ResParticle_ParticlePool_getSpeedMin);
	LUA_METHOD("getSpinEnd", lua_lstg_ResParticle_ParticlePool_getSpinEnd);
	LUA_METHOD("getSpinStart", lua_lstg_ResParticle_ParticlePool_getSpinStart);
	LUA_METHOD("getSpinVar", lua_lstg_ResParticle_ParticlePool_getSpinVar);
	LUA_METHOD("getSpread", lua_lstg_ResParticle_ParticlePool_getSpread);
	LUA_METHOD("getTangentialAccelMax", lua_lstg_ResParticle_ParticlePool_getTangentialAccelMax);
	LUA_METHOD("getTangentialAccelMin", lua_lstg_ResParticle_ParticlePool_getTangentialAccelMin);
	LUA_METHOD("isActive", lua_lstg_ResParticle_ParticlePool_isActive);
	LUA_METHOD("setActive", lua_lstg_ResParticle_ParticlePool_setActive);
	LUA_METHOD("setAlphaVar", lua_lstg_ResParticle_ParticlePool_setAlphaVar);
	LUA_METHOD("setCenter", lua_lstg_ResParticle_ParticlePool_setCenter);
	LUA_METHOD("setColorEnd", lua_lstg_ResParticle_ParticlePool_setColorEnd);
	LUA_METHOD("setColorStart", lua_lstg_ResParticle_ParticlePool_setColorStart);
	LUA_METHOD("setColorVar", lua_lstg_ResParticle_ParticlePool_setColorVar);
	LUA_METHOD("setDirection", lua_lstg_ResParticle_ParticlePool_setDirection);
	LUA_METHOD("setEmissionFreq", lua_lstg_ResParticle_ParticlePool_setEmissionFreq);
	LUA_METHOD("setGravityMax", lua_lstg_ResParticle_ParticlePool_setGravityMax);
	LUA_METHOD("setGravityMin", lua_lstg_ResParticle_ParticlePool_setGravityMin);
	LUA_METHOD("setLifeMax", lua_lstg_ResParticle_ParticlePool_setLifeMax);
	LUA_METHOD("setLifeMin", lua_lstg_ResParticle_ParticlePool_setLifeMin);
	LUA_METHOD("setLifetime", lua_lstg_ResParticle_ParticlePool_setLifetime);
	LUA_METHOD("setRadialAccelMax", lua_lstg_ResParticle_ParticlePool_setRadialAccelMax);
	LUA_METHOD("setRadialAccelMin", lua_lstg_ResParticle_ParticlePool_setRadialAccelMin);
	LUA_METHOD("setRelative", lua_lstg_ResParticle_ParticlePool_setRelative);
	LUA_METHOD("setRenderMode", lua_lstg_ResParticle_ParticlePool_setRenderMode);
	LUA_METHOD("setRotation", lua_lstg_ResParticle_ParticlePool_setRotation);
	LUA_METHOD("setSeed", lua_lstg_ResParticle_ParticlePool_setSeed);
	LUA_METHOD("setSizeEnd", lua_lstg_ResParticle_ParticlePool_setSizeEnd);
	LUA_METHOD("setSizeStart", lua_lstg_ResParticle_ParticlePool_setSizeStart);
	LUA_METHOD("setSizeVar", lua_lstg_ResParticle_ParticlePool_setSizeVar);
	LUA_METHOD("setSpeedMax", lua_lstg_ResParticle_ParticlePool_setSpeedMax);
	LUA_METHOD("setSpeedMin", lua_lstg_ResParticle_ParticlePool_setSpeedMin);
	LUA_METHOD("setSpinEnd", lua_lstg_ResParticle_ParticlePool_setSpinEnd);
	LUA_METHOD("setSpinStart", lua_lstg_ResParticle_ParticlePool_setSpinStart);
	LUA_METHOD("setSpinVar", lua_lstg_ResParticle_ParticlePool_setSpinVar);
	LUA_METHOD("setSpread", lua_lstg_ResParticle_ParticlePool_setSpread);
	LUA_METHOD("setTangentialAccelMax", lua_lstg_ResParticle_ParticlePool_setTangentialAccelMax);
	LUA_METHOD("setTangentialAccelMin", lua_lstg_ResParticle_ParticlePool_setTangentialAccelMin);
	luaReg_Resource_lstgResParticleParticlePoolStatus(lua_S);
	LUA_CLS_END();
	LUA_ENTRY_END(2);
	return 0;
}
int lua_lstg_ResParticle_getBindSprite(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("lstg.ResParticle", "lstg.ResParticle:getBindSprite");
	LUA_TRY_INVOKE_R(0, &lstg::ResParticle::getBindSprite);
	LUA_INVOKE_FOOTER("0");
}
int lua_lstg_ResParticle_getRenderMode(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("lstg.ResParticle", "lstg.ResParticle:getRenderMode");
	LUA_TRY_INVOKE_R(0, &lstg::ResParticle::getRenderMode);
	LUA_INVOKE_FOOTER("0");
}
int lua_lstg_ResParticle_newCocosParticle(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("lstg.ResParticle", "lstg.ResParticle:newCocosParticle");
	LUA_TRY_INVOKE_R(0, &lstg::ResParticle::newCocosParticle);
	LUA_INVOKE_FOOTER("0");
}
int lua_lstg_ResParticle_create(lua_State* lua_S)
{
	LUA_SINVOKE_HEADER("lstg.ResParticle", "lstg.ResParticle:create");
	LUA_TRY_INVOKE_R(6, &lstg::ResParticle::create);
	LUA_SINVOKE_FOOTER("6");
}
int luaReg_Resource_lstgResParticle(lua_State* lua_S)
{
	LUA_ENTRY("lstg");
	LUA_CLS_DEF_BASE(lstg::ResParticle, "ResParticle", "lstg.ResParticle",
		lstg::ResourceColliable, "lstg.ResourceColliable",
		nullptr, nullptr);
	LUA_METHOD("getBindSprite", lua_lstg_ResParticle_getBindSprite);
	LUA_METHOD("getRenderMode", lua_lstg_ResParticle_getRenderMode);
	LUA_METHOD("newCocosParticle", lua_lstg_ResParticle_newCocosParticle);
	LUA_METHOD("create", lua_lstg_ResParticle_create);
	LUA_CLS_END();
	LUA_ENTRY_END(1);
	luaReg_Resource_lstgResParticleParticlePool(lua_S);
	return 0;
}
int lua_lstg_ResFont_calcSize(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("lstg.ResFont", "lstg.ResFont:calcSize");
	LUA_TRY_INVOKE_R(1, &lstg::ResFont::calcSize);
	LUA_INVOKE_FOOTER("1");
}
int lua_lstg_ResFont_createLabel(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("lstg.ResFont", "lstg.ResFont:createLabel");
	LUA_TRY_INVOKE_R(0, &lstg::ResFont::createLabel);
	LUA_INVOKE_FOOTER("0");
}
int lua_lstg_ResFont_disableAllEffects(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("lstg.ResFont", "lstg.ResFont:disableAllEffects");
	LUA_TRY_INVOKE(0, &lstg::ResFont::disableAllEffects);
	LUA_INVOKE_FOOTER("0");
}
int lua_lstg_ResFont_disableBold(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("lstg.ResFont", "lstg.ResFont:disableBold");
	LUA_TRY_INVOKE(0, &lstg::ResFont::disableBold);
	LUA_INVOKE_FOOTER("0");
}
int lua_lstg_ResFont_disableGlow(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("lstg.ResFont", "lstg.ResFont:disableGlow");
	LUA_TRY_INVOKE(0, &lstg::ResFont::disableGlow);
	LUA_INVOKE_FOOTER("0");
}
int lua_lstg_ResFont_disableItalics(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("lstg.ResFont", "lstg.ResFont:disableItalics");
	LUA_TRY_INVOKE(0, &lstg::ResFont::disableItalics);
	LUA_INVOKE_FOOTER("0");
}
int lua_lstg_ResFont_disableOutline(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("lstg.ResFont", "lstg.ResFont:disableOutline");
	LUA_TRY_INVOKE(0, &lstg::ResFont::disableOutline);
	LUA_INVOKE_FOOTER("0");
}
int lua_lstg_ResFont_disableShadow(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("lstg.ResFont", "lstg.ResFont:disableShadow");
	LUA_TRY_INVOKE(0, &lstg::ResFont::disableShadow);
	LUA_INVOKE_FOOTER("0");
}
int lua_lstg_ResFont_disableStrikethrough(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("lstg.ResFont", "lstg.ResFont:disableStrikethrough");
	LUA_TRY_INVOKE(0, &lstg::ResFont::disableStrikethrough);
	LUA_INVOKE_FOOTER("0");
}
int lua_lstg_ResFont_disableUnderline(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("lstg.ResFont", "lstg.ResFont:disableUnderline");
	LUA_TRY_INVOKE(0, &lstg::ResFont::disableUnderline);
	LUA_INVOKE_FOOTER("0");
}
int lua_lstg_ResFont_enableBold(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("lstg.ResFont", "lstg.ResFont:enableBold");
	LUA_TRY_INVOKE(0, &lstg::ResFont::enableBold);
	LUA_INVOKE_FOOTER("0");
}
int lua_lstg_ResFont_enableGlow(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("lstg.ResFont", "lstg.ResFont:enableGlow");
	LUA_TRY_INVOKE(1, &lstg::ResFont::enableGlow);
	LUA_INVOKE_FOOTER("1");
}
int lua_lstg_ResFont_enableItalics(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("lstg.ResFont", "lstg.ResFont:enableItalics");
	LUA_TRY_INVOKE(0, &lstg::ResFont::enableItalics);
	LUA_INVOKE_FOOTER("0");
}
int lua_lstg_ResFont_enableOutline(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("lstg.ResFont", "lstg.ResFont:enableOutline");
	LUA_TRY_INVOKE(2, static_cast<void(lstg::ResFont::*)(const cocos2d::Color4B&, int)>(&lstg::ResFont::enableOutline));
	LUA_TRY_INVOKE(1, [](lstg::ResFont* obj, const cocos2d::Color4B& arg0){{return obj->enableOutline(arg0);}});
	LUA_INVOKE_FOOTER("1,2");
}
int lua_lstg_ResFont_enableShadow(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("lstg.ResFont", "lstg.ResFont:enableShadow");
	LUA_TRY_INVOKE(3, static_cast<void(lstg::ResFont::*)(const cocos2d::Color4B&, const cocos2d::Size&, int)>(&lstg::ResFont::enableShadow));
	LUA_TRY_INVOKE(2, [](lstg::ResFont* obj, const cocos2d::Color4B& arg0,const cocos2d::Size& arg1){{return obj->enableShadow(arg0,arg1);}});
	LUA_TRY_INVOKE(1, [](lstg::ResFont* obj, const cocos2d::Color4B& arg0){{return obj->enableShadow(arg0);}});
	LUA_TRY_INVOKE(0, [](lstg::ResFont* obj){{return obj->enableShadow();}});
	LUA_INVOKE_FOOTER("0,1,2,3");
}
int lua_lstg_ResFont_enableStrikethrough(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("lstg.ResFont", "lstg.ResFont:enableStrikethrough");
	LUA_TRY_INVOKE(0, &lstg::ResFont::enableStrikethrough);
	LUA_INVOKE_FOOTER("0");
}
int lua_lstg_ResFont_enableUnderline(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("lstg.ResFont", "lstg.ResFont:enableUnderline");
	LUA_TRY_INVOKE(0, &lstg::ResFont::enableUnderline);
	LUA_INVOKE_FOOTER("0");
}
int lua_lstg_ResFont_getColor(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("lstg.ResFont", "lstg.ResFont:getColor");
	LUA_TRY_INVOKE_R(0, &lstg::ResFont::getColor);
	LUA_INVOKE_FOOTER("0");
}
int lua_lstg_ResFont_getFontAscender(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("lstg.ResFont", "lstg.ResFont:getFontAscender");
	LUA_TRY_INVOKE_R(0, &lstg::ResFont::getFontAscender);
	LUA_INVOKE_FOOTER("0");
}
int lua_lstg_ResFont_getGlowColor(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("lstg.ResFont", "lstg.ResFont:getGlowColor");
	LUA_TRY_INVOKE_R(0, &lstg::ResFont::getGlowColor);
	LUA_INVOKE_FOOTER("0");
}
int lua_lstg_ResFont_getHAlign(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("lstg.ResFont", "lstg.ResFont:getHAlign");
	LUA_TRY_INVOKE_R(0, &lstg::ResFont::getHAlign);
	LUA_INVOKE_FOOTER("0");
}
int lua_lstg_ResFont_getLabel(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("lstg.ResFont", "lstg.ResFont:getLabel");
	LUA_TRY_INVOKE_R(0, &lstg::ResFont::getLabel);
	LUA_INVOKE_FOOTER("0");
}
int lua_lstg_ResFont_getLabelType(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("lstg.ResFont", "lstg.ResFont:getLabelType");
	LUA_TRY_INVOKE_R(0, &lstg::ResFont::getLabelType);
	LUA_INVOKE_FOOTER("0");
}
int lua_lstg_ResFont_getOutlineColor(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("lstg.ResFont", "lstg.ResFont:getOutlineColor");
	LUA_TRY_INVOKE_R(0, &lstg::ResFont::getOutlineColor);
	LUA_INVOKE_FOOTER("0");
}
int lua_lstg_ResFont_getOutlineSize(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("lstg.ResFont", "lstg.ResFont:getOutlineSize");
	LUA_TRY_INVOKE_R(0, &lstg::ResFont::getOutlineSize);
	LUA_INVOKE_FOOTER("0");
}
int lua_lstg_ResFont_getRenderMode(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("lstg.ResFont", "lstg.ResFont:getRenderMode");
	LUA_TRY_INVOKE_R(0, &lstg::ResFont::getRenderMode);
	LUA_INVOKE_FOOTER("0");
}
int lua_lstg_ResFont_getShadowBlurRadius(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("lstg.ResFont", "lstg.ResFont:getShadowBlurRadius");
	LUA_TRY_INVOKE_R(0, &lstg::ResFont::getShadowBlurRadius);
	LUA_INVOKE_FOOTER("0");
}
int lua_lstg_ResFont_getShadowColor(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("lstg.ResFont", "lstg.ResFont:getShadowColor");
	LUA_TRY_INVOKE_R(0, &lstg::ResFont::getShadowColor);
	LUA_INVOKE_FOOTER("0");
}
int lua_lstg_ResFont_getShadowOffset(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("lstg.ResFont", "lstg.ResFont:getShadowOffset");
	LUA_TRY_INVOKE_R(0, &lstg::ResFont::getShadowOffset);
	LUA_INVOKE_FOOTER("0");
}
int lua_lstg_ResFont_getTTFConfig(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("lstg.ResFont", "lstg.ResFont:getTTFConfig");
	LUA_TRY_INVOKE_R(0, &lstg::ResFont::getTTFConfig);
	LUA_INVOKE_FOOTER("0");
}
int lua_lstg_ResFont_getVAlign(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("lstg.ResFont", "lstg.ResFont:getVAlign");
	LUA_TRY_INVOKE_R(0, &lstg::ResFont::getVAlign);
	LUA_INVOKE_FOOTER("0");
}
int lua_lstg_ResFont_isBold(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("lstg.ResFont", "lstg.ResFont:isBold");
	LUA_TRY_INVOKE_R(0, &lstg::ResFont::isBold);
	LUA_INVOKE_FOOTER("0");
}
int lua_lstg_ResFont_isGlowed(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("lstg.ResFont", "lstg.ResFont:isGlowed");
	LUA_TRY_INVOKE_R(0, &lstg::ResFont::isGlowed);
	LUA_INVOKE_FOOTER("0");
}
int lua_lstg_ResFont_isItalics(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("lstg.ResFont", "lstg.ResFont:isItalics");
	LUA_TRY_INVOKE_R(0, &lstg::ResFont::isItalics);
	LUA_INVOKE_FOOTER("0");
}
int lua_lstg_ResFont_isOutlined(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("lstg.ResFont", "lstg.ResFont:isOutlined");
	LUA_TRY_INVOKE_R(0, &lstg::ResFont::isOutlined);
	LUA_INVOKE_FOOTER("0");
}
int lua_lstg_ResFont_isShadowed(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("lstg.ResFont", "lstg.ResFont:isShadowed");
	LUA_TRY_INVOKE_R(0, &lstg::ResFont::isShadowed);
	LUA_INVOKE_FOOTER("0");
}
int lua_lstg_ResFont_isStrikethrough(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("lstg.ResFont", "lstg.ResFont:isStrikethrough");
	LUA_TRY_INVOKE_R(0, &lstg::ResFont::isStrikethrough);
	LUA_INVOKE_FOOTER("0");
}
int lua_lstg_ResFont_isUnderlined(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("lstg.ResFont", "lstg.ResFont:isUnderlined");
	LUA_TRY_INVOKE_R(0, &lstg::ResFont::isUnderlined);
	LUA_INVOKE_FOOTER("0");
}
int lua_lstg_ResFont_render(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("lstg.ResFont", "lstg.ResFont:render");
	LUA_TRY_INVOKE_R(7, static_cast<bool(lstg::ResFont::*)(const std::string&, float, float, float, float, float, float)>(&lstg::ResFont::render));
	LUA_TRY_INVOKE_R(6, [](lstg::ResFont* obj, const std::string& arg0,float arg1,float arg2,float arg3,float arg4,float arg5){{return obj->render(arg0,std::move(arg1),std::move(arg2),std::move(arg3),std::move(arg4),std::move(arg5));}});
	LUA_TRY_INVOKE_R(5, [](lstg::ResFont* obj, const std::string& arg0,float arg1,float arg2,float arg3,float arg4){{return obj->render(arg0,std::move(arg1),std::move(arg2),std::move(arg3),std::move(arg4));}});
	LUA_TRY_INVOKE_R(4, [](lstg::ResFont* obj, const std::string& arg0,float arg1,float arg2,float arg3){{return obj->render(arg0,std::move(arg1),std::move(arg2),std::move(arg3));}});
	LUA_TRY_INVOKE_R(3, [](lstg::ResFont* obj, const std::string& arg0,float arg1,float arg2){{return obj->render(arg0,std::move(arg1),std::move(arg2));}});
	LUA_INVOKE_FOOTER("3,4,5,6,7");
}
int lua_lstg_ResFont_setColor(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("lstg.ResFont", "lstg.ResFont:setColor");
	LUA_TRY_INVOKE(1, &lstg::ResFont::setColor);
	LUA_INVOKE_FOOTER("1");
}
int lua_lstg_ResFont_setHAlign(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("lstg.ResFont", "lstg.ResFont:setHAlign");
	LUA_TRY_INVOKE(1, &lstg::ResFont::setHAlign);
	LUA_INVOKE_FOOTER("1");
}
int lua_lstg_ResFont_setOutlineColor(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("lstg.ResFont", "lstg.ResFont:setOutlineColor");
	LUA_TRY_INVOKE(1, &lstg::ResFont::setOutlineColor);
	LUA_INVOKE_FOOTER("1");
}
int lua_lstg_ResFont_setOutlineSize(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("lstg.ResFont", "lstg.ResFont:setOutlineSize");
	LUA_TRY_INVOKE(1, &lstg::ResFont::setOutlineSize);
	LUA_INVOKE_FOOTER("1");
}
int lua_lstg_ResFont_setRenderMode(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("lstg.ResFont", "lstg.ResFont:setRenderMode");
	LUA_TRY_INVOKE(1, &lstg::ResFont::setRenderMode);
	LUA_INVOKE_FOOTER("1");
}
int lua_lstg_ResFont_setTTFConfig(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("lstg.ResFont", "lstg.ResFont:setTTFConfig");
	LUA_TRY_INVOKE(1, &lstg::ResFont::setTTFConfig);
	LUA_INVOKE_FOOTER("1");
}
int lua_lstg_ResFont_setVAlign(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("lstg.ResFont", "lstg.ResFont:setVAlign");
	LUA_TRY_INVOKE(1, &lstg::ResFont::setVAlign);
	LUA_INVOKE_FOOTER("1");
}
int lua_lstg_ResFont_HGE2BMF(lua_State* lua_S)
{
	LUA_SINVOKE_HEADER("lstg.ResFont", "lstg.ResFont:HGE2BMF");
	LUA_TRY_INVOKE_R(2, &lstg::ResFont::HGE2BMF);
	LUA_SINVOKE_FOOTER("2");
}
int lua_lstg_ResFont_createBMF(lua_State* lua_S)
{
	LUA_SINVOKE_HEADER("lstg.ResFont", "lstg.ResFont:createBMF");
	LUA_TRY_INVOKE_R(2, &lstg::ResFont::createBMF);
	LUA_SINVOKE_FOOTER("2");
}
int lua_lstg_ResFont_createHGE(lua_State* lua_S)
{
	LUA_SINVOKE_HEADER("lstg.ResFont", "lstg.ResFont:createHGE");
	LUA_TRY_INVOKE_R(2, &lstg::ResFont::createHGE);
	LUA_SINVOKE_FOOTER("2");
}
int lua_lstg_ResFont_createTTF(lua_State* lua_S)
{
	LUA_SINVOKE_HEADER("lstg.ResFont", "lstg.ResFont:createTTF");
	LUA_TRY_INVOKE_R(3, &lstg::ResFont::createTTF);
	LUA_SINVOKE_FOOTER("3");
}
int luaReg_Resource_lstgResFont(lua_State* lua_S)
{
	LUA_ENTRY("lstg");
	LUA_CLS_DEF_BASE(lstg::ResFont, "ResFont", "lstg.ResFont",
		lstg::Resource, "lstg.Resource",
		nullptr, nullptr);
	LUA_METHOD("calcSize", lua_lstg_ResFont_calcSize);
	LUA_METHOD("createLabel", lua_lstg_ResFont_createLabel);
	LUA_METHOD("disableAllEffects", lua_lstg_ResFont_disableAllEffects);
	LUA_METHOD("disableBold", lua_lstg_ResFont_disableBold);
	LUA_METHOD("disableGlow", lua_lstg_ResFont_disableGlow);
	LUA_METHOD("disableItalics", lua_lstg_ResFont_disableItalics);
	LUA_METHOD("disableOutline", lua_lstg_ResFont_disableOutline);
	LUA_METHOD("disableShadow", lua_lstg_ResFont_disableShadow);
	LUA_METHOD("disableStrikethrough", lua_lstg_ResFont_disableStrikethrough);
	LUA_METHOD("disableUnderline", lua_lstg_ResFont_disableUnderline);
	LUA_METHOD("enableBold", lua_lstg_ResFont_enableBold);
	LUA_METHOD("enableGlow", lua_lstg_ResFont_enableGlow);
	LUA_METHOD("enableItalics", lua_lstg_ResFont_enableItalics);
	LUA_METHOD("enableOutline", lua_lstg_ResFont_enableOutline);
	LUA_METHOD("enableShadow", lua_lstg_ResFont_enableShadow);
	LUA_METHOD("enableStrikethrough", lua_lstg_ResFont_enableStrikethrough);
	LUA_METHOD("enableUnderline", lua_lstg_ResFont_enableUnderline);
	LUA_METHOD("getColor", lua_lstg_ResFont_getColor);
	LUA_METHOD("getFontAscender", lua_lstg_ResFont_getFontAscender);
	LUA_METHOD("getGlowColor", lua_lstg_ResFont_getGlowColor);
	LUA_METHOD("getHAlign", lua_lstg_ResFont_getHAlign);
	LUA_METHOD("getLabel", lua_lstg_ResFont_getLabel);
	LUA_METHOD("getLabelType", lua_lstg_ResFont_getLabelType);
	LUA_METHOD("getOutlineColor", lua_lstg_ResFont_getOutlineColor);
	LUA_METHOD("getOutlineSize", lua_lstg_ResFont_getOutlineSize);
	LUA_METHOD("getRenderMode", lua_lstg_ResFont_getRenderMode);
	LUA_METHOD("getShadowBlurRadius", lua_lstg_ResFont_getShadowBlurRadius);
	LUA_METHOD("getShadowColor", lua_lstg_ResFont_getShadowColor);
	LUA_METHOD("getShadowOffset", lua_lstg_ResFont_getShadowOffset);
	LUA_METHOD("getTTFConfig", lua_lstg_ResFont_getTTFConfig);
	LUA_METHOD("getVAlign", lua_lstg_ResFont_getVAlign);
	LUA_METHOD("isBold", lua_lstg_ResFont_isBold);
	LUA_METHOD("isGlowed", lua_lstg_ResFont_isGlowed);
	LUA_METHOD("isItalics", lua_lstg_ResFont_isItalics);
	LUA_METHOD("isOutlined", lua_lstg_ResFont_isOutlined);
	LUA_METHOD("isShadowed", lua_lstg_ResFont_isShadowed);
	LUA_METHOD("isStrikethrough", lua_lstg_ResFont_isStrikethrough);
	LUA_METHOD("isUnderlined", lua_lstg_ResFont_isUnderlined);
	LUA_METHOD("render", lua_lstg_ResFont_render);
	LUA_METHOD("setColor", lua_lstg_ResFont_setColor);
	LUA_METHOD("setHAlign", lua_lstg_ResFont_setHAlign);
	LUA_METHOD("setOutlineColor", lua_lstg_ResFont_setOutlineColor);
	LUA_METHOD("setOutlineSize", lua_lstg_ResFont_setOutlineSize);
	LUA_METHOD("setRenderMode", lua_lstg_ResFont_setRenderMode);
	LUA_METHOD("setTTFConfig", lua_lstg_ResFont_setTTFConfig);
	LUA_METHOD("setVAlign", lua_lstg_ResFont_setVAlign);
	LUA_METHOD("HGE2BMF", lua_lstg_ResFont_HGE2BMF);
	LUA_METHOD("createBMF", lua_lstg_ResFont_createBMF);
	LUA_METHOD("createHGE", lua_lstg_ResFont_createHGE);
	LUA_METHOD("createTTF", lua_lstg_ResFont_createTTF);
	LUA_CLS_END();
	LUA_ENTRY_END(1);
	return 0;
}
int lua_lstg_ResAudio_getFFTSize(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("lstg.ResAudio", "lstg.ResAudio:getFFTSize");
	LUA_TRY_INVOKE_R(0, &lstg::ResAudio::getFFTSize);
	LUA_INVOKE_FOOTER("0");
}
int lua_lstg_ResAudio_getSource(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("lstg.ResAudio", "lstg.ResAudio:getSource");
	LUA_TRY_INVOKE_R(0, &lstg::ResAudio::getSource);
	LUA_INVOKE_FOOTER("0");
}
int lua_lstg_ResAudio_getStream(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("lstg.ResAudio", "lstg.ResAudio:getStream");
	LUA_TRY_INVOKE_R(0, &lstg::ResAudio::getStream);
	LUA_INVOKE_FOOTER("0");
}
int lua_lstg_ResAudio_isPlaying(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("lstg.ResAudio", "lstg.ResAudio:isPlaying");
	LUA_TRY_INVOKE_R(0, &lstg::ResAudio::isPlaying);
	LUA_INVOKE_FOOTER("0");
}
int lua_lstg_ResAudio_isStopped(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("lstg.ResAudio", "lstg.ResAudio:isStopped");
	LUA_TRY_INVOKE_R(0, &lstg::ResAudio::isStopped);
	LUA_INVOKE_FOOTER("0");
}
int lua_lstg_ResAudio_pause(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("lstg.ResAudio", "lstg.ResAudio:pause");
	LUA_TRY_INVOKE(0, &lstg::ResAudio::pause);
	LUA_INVOKE_FOOTER("0");
}
int lua_lstg_ResAudio_play(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("lstg.ResAudio", "lstg.ResAudio:play");
	LUA_TRY_INVOKE(2, static_cast<void(lstg::ResAudio::*)(float, float)>(&lstg::ResAudio::play));
	LUA_TRY_INVOKE(1, [](lstg::ResAudio* obj, float arg0){{return obj->play(std::move(arg0));}});
	LUA_TRY_INVOKE(0, static_cast<void(lstg::ResAudio::*)()>(&lstg::ResAudio::play));
	LUA_INVOKE_FOOTER("0,1,2");
}
int lua_lstg_ResAudio_resume(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("lstg.ResAudio", "lstg.ResAudio:resume");
	LUA_TRY_INVOKE(0, &lstg::ResAudio::resume);
	LUA_INVOKE_FOOTER("0");
}
int lua_lstg_ResAudio_stop(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("lstg.ResAudio", "lstg.ResAudio:stop");
	LUA_TRY_INVOKE(0, &lstg::ResAudio::stop);
	LUA_INVOKE_FOOTER("0");
}
int luaReg_Resource_lstgResAudio(lua_State* lua_S)
{
	LUA_ENTRY("lstg");
	LUA_CLS_DEF_BASE(lstg::ResAudio, "ResAudio", "lstg.ResAudio",
		lstg::Resource, "lstg.Resource",
		nullptr, nullptr);
	LUA_METHOD("getFFTSize", lua_lstg_ResAudio_getFFTSize);
	LUA_METHOD("getSource", lua_lstg_ResAudio_getSource);
	LUA_METHOD("getStream", lua_lstg_ResAudio_getStream);
	LUA_METHOD("isPlaying", lua_lstg_ResAudio_isPlaying);
	LUA_METHOD("isStopped", lua_lstg_ResAudio_isStopped);
	LUA_METHOD("pause", lua_lstg_ResAudio_pause);
	LUA_METHOD("play", lua_lstg_ResAudio_play);
	LUA_METHOD("resume", lua_lstg_ResAudio_resume);
	LUA_METHOD("stop", lua_lstg_ResAudio_stop);
	LUA_CLS_END();
	LUA_ENTRY_END(1);
	return 0;
}
int lua_lstg_ResSound_create(lua_State* lua_S)
{
	LUA_SINVOKE_HEADER("lstg.ResSound", "lstg.ResSound:create");
	LUA_TRY_INVOKE_R(2, &lstg::ResSound::create);
	LUA_SINVOKE_FOOTER("2");
}
int luaReg_Resource_lstgResSound(lua_State* lua_S)
{
	LUA_ENTRY("lstg");
	LUA_CLS_DEF_BASE(lstg::ResSound, "ResSound", "lstg.ResSound",
		lstg::ResAudio, "lstg.ResAudio",
		nullptr, nullptr);
	LUA_METHOD("create", lua_lstg_ResSound_create);
	LUA_CLS_END();
	LUA_ENTRY_END(1);
	return 0;
}
int lua_lstg_ResMusic_create(lua_State* lua_S)
{
	LUA_SINVOKE_HEADER("lstg.ResMusic", "lstg.ResMusic:create");
	LUA_TRY_INVOKE_R(4, &lstg::ResMusic::create);
	LUA_SINVOKE_FOOTER("4");
}
int luaReg_Resource_lstgResMusic(lua_State* lua_S)
{
	LUA_ENTRY("lstg");
	LUA_CLS_DEF_BASE(lstg::ResMusic, "ResMusic", "lstg.ResMusic",
		lstg::ResAudio, "lstg.ResAudio",
		nullptr, nullptr);
	LUA_METHOD("create", lua_lstg_ResMusic_create);
	LUA_CLS_END();
	LUA_ENTRY_END(1);
	return 0;
}
int lua_lstg_ResFX_getProgram(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("lstg.ResFX", "lstg.ResFX:getProgram");
	LUA_TRY_INVOKE_R(0, &lstg::ResFX::getProgram);
	LUA_INVOKE_FOOTER("0");
}
int lua_lstg_ResFX_getProgramState(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("lstg.ResFX", "lstg.ResFX:getProgramState");
	LUA_TRY_INVOKE_R(0, &lstg::ResFX::getProgramState);
	LUA_INVOKE_FOOTER("0");
}
int lua_lstg_ResFX_getRenderMode(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("lstg.ResFX", "lstg.ResFX:getRenderMode");
	LUA_TRY_INVOKE_R(0, &lstg::ResFX::getRenderMode);
	LUA_INVOKE_FOOTER("0");
}
int lua_lstg_ResFX_getUniformNames(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("lstg.ResFX", "lstg.ResFX:getUniformNames");
	LUA_TRY_INVOKE_R(0, &lstg::ResFX::getUniformNames);
	LUA_INVOKE_FOOTER("0");
}
int lua_lstg_ResFX_setColor(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("lstg.ResFX", "lstg.ResFX:setColor");
	LUA_TRY_INVOKE(2, &lstg::ResFX::setColor);
	LUA_INVOKE_FOOTER("2");
}
int lua_lstg_ResFX_setFloat(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("lstg.ResFX", "lstg.ResFX:setFloat");
	LUA_TRY_INVOKE(2, &lstg::ResFX::setFloat);
	LUA_INVOKE_FOOTER("2");
}
int lua_lstg_ResFX_setMat4(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("lstg.ResFX", "lstg.ResFX:setMat4");
	LUA_TRY_INVOKE(2, &lstg::ResFX::setMat4);
	LUA_INVOKE_FOOTER("2");
}
int lua_lstg_ResFX_setScreenSize(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("lstg.ResFX", "lstg.ResFX:setScreenSize");
	LUA_TRY_INVOKE(1, &lstg::ResFX::setScreenSize);
	LUA_INVOKE_FOOTER("1");
}
int lua_lstg_ResFX_setTexture(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("lstg.ResFX", "lstg.ResFX:setTexture");
	LUA_TRY_INVOKE(3, static_cast<void(lstg::ResFX::*)(const std::string&, cocos2d::Texture2D*, uint32_t)>(&lstg::ResFX::setTexture));
	LUA_TRY_INVOKE(2, [](lstg::ResFX* obj, const std::string& arg0,cocos2d::Texture2D* arg1){{return obj->setTexture(arg0,arg1);}});
	LUA_INVOKE_FOOTER("2,3");
}
int lua_lstg_ResFX_setVec2(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("lstg.ResFX", "lstg.ResFX:setVec2");
	LUA_TRY_INVOKE(2, &lstg::ResFX::setVec2);
	LUA_INVOKE_FOOTER("2");
}
int lua_lstg_ResFX_setVec3(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("lstg.ResFX", "lstg.ResFX:setVec3");
	LUA_TRY_INVOKE(2, &lstg::ResFX::setVec3);
	LUA_INVOKE_FOOTER("2");
}
int lua_lstg_ResFX_setVec4(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("lstg.ResFX", "lstg.ResFX:setVec4");
	LUA_TRY_INVOKE(2, &lstg::ResFX::setVec4);
	LUA_INVOKE_FOOTER("2");
}
int lua_lstg_ResFX_setViewport(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("lstg.ResFX", "lstg.ResFX:setViewport");
	LUA_TRY_INVOKE(1, &lstg::ResFX::setViewport);
	LUA_INVOKE_FOOTER("1");
}
int lua_lstg_ResFX_create(lua_State* lua_S)
{
	LUA_SINVOKE_HEADER("lstg.ResFX", "lstg.ResFX:create");
	LUA_TRY_INVOKE_R(3, &lstg::ResFX::create);
	LUA_SINVOKE_FOOTER("3");
}
int lua_lstg_ResFX_createWithProgram(lua_State* lua_S)
{
	LUA_SINVOKE_HEADER("lstg.ResFX", "lstg.ResFX:createWithProgram");
	LUA_TRY_INVOKE_R(2, &lstg::ResFX::createWithProgram);
	LUA_SINVOKE_FOOTER("2");
}
int lua_lstg_ResFX_createWithString(lua_State* lua_S)
{
	LUA_SINVOKE_HEADER("lstg.ResFX", "lstg.ResFX:createWithString");
	LUA_TRY_INVOKE_R(3, &lstg::ResFX::createWithString);
	LUA_SINVOKE_FOOTER("3");
}
int luaReg_Resource_lstgResFX(lua_State* lua_S)
{
	LUA_ENTRY("lstg");
	LUA_CLS_DEF_BASE(lstg::ResFX, "ResFX", "lstg.ResFX",
		lstg::Resource, "lstg.Resource",
		nullptr, nullptr);
	LUA_METHOD("getProgram", lua_lstg_ResFX_getProgram);
	LUA_METHOD("getProgramState", lua_lstg_ResFX_getProgramState);
	LUA_METHOD("getRenderMode", lua_lstg_ResFX_getRenderMode);
	LUA_METHOD("getUniformNames", lua_lstg_ResFX_getUniformNames);
	LUA_METHOD("setColor", lua_lstg_ResFX_setColor);
	LUA_METHOD("setFloat", lua_lstg_ResFX_setFloat);
	LUA_METHOD("setMat4", lua_lstg_ResFX_setMat4);
	LUA_METHOD("setScreenSize", lua_lstg_ResFX_setScreenSize);
	LUA_METHOD("setTexture", lua_lstg_ResFX_setTexture);
	LUA_METHOD("setVec2", lua_lstg_ResFX_setVec2);
	LUA_METHOD("setVec3", lua_lstg_ResFX_setVec3);
	LUA_METHOD("setVec4", lua_lstg_ResFX_setVec4);
	LUA_METHOD("setViewport", lua_lstg_ResFX_setViewport);
	LUA_METHOD("create", lua_lstg_ResFX_create);
	LUA_METHOD("createWithProgram", lua_lstg_ResFX_createWithProgram);
	LUA_METHOD("createWithString", lua_lstg_ResFX_createWithString);
	LUA_CLS_END();
	LUA_ENTRY_END(1);
	return 0;
}
int lua_lstg_ResRenderTarget_copyTexture(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("lstg.ResRenderTarget", "lstg.ResRenderTarget:copyTexture");
	LUA_TRY_INVOKE_R(1, static_cast<cocos2d::Texture2D*(lstg::ResRenderTarget::*)(bool)>(&lstg::ResRenderTarget::copyTexture));
	LUA_TRY_INVOKE_R(0, [](lstg::ResRenderTarget* obj){{return obj->copyTexture();}});
	LUA_INVOKE_FOOTER("0,1");
}
int lua_lstg_ResRenderTarget_getClearColor(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("lstg.ResRenderTarget", "lstg.ResRenderTarget:getClearColor");
	LUA_TRY_INVOKE_R(0, &lstg::ResRenderTarget::getClearColor);
	LUA_INVOKE_FOOTER("0");
}
int lua_lstg_ResRenderTarget_getTarget(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("lstg.ResRenderTarget", "lstg.ResRenderTarget:getTarget");
	LUA_TRY_INVOKE_R(0, &lstg::ResRenderTarget::getTarget);
	LUA_INVOKE_FOOTER("0");
}
int lua_lstg_ResRenderTarget_getTexture(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("lstg.ResRenderTarget", "lstg.ResRenderTarget:getTexture");
	LUA_TRY_INVOKE_R(0, &lstg::ResRenderTarget::getTexture);
	LUA_INVOKE_FOOTER("0");
}
int lua_lstg_ResRenderTarget_isNeedBlendFix(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("lstg.ResRenderTarget", "lstg.ResRenderTarget:isNeedBlendFix");
	LUA_TRY_INVOKE_R(0, &lstg::ResRenderTarget::isNeedBlendFix);
	LUA_INVOKE_FOOTER("0");
}
int lua_lstg_ResRenderTarget_pop(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("lstg.ResRenderTarget", "lstg.ResRenderTarget:pop");
	LUA_TRY_INVOKE_R(0, &lstg::ResRenderTarget::pop);
	LUA_INVOKE_FOOTER("0");
}
int lua_lstg_ResRenderTarget_push(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("lstg.ResRenderTarget", "lstg.ResRenderTarget:push");
	LUA_TRY_INVOKE_R(0, &lstg::ResRenderTarget::push);
	LUA_INVOKE_FOOTER("0");
}
int lua_lstg_ResRenderTarget_render(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("lstg.ResRenderTarget", "lstg.ResRenderTarget:render");
	LUA_TRY_INVOKE_R(2, &lstg::ResRenderTarget::render);
	LUA_INVOKE_FOOTER("2");
}
int lua_lstg_ResRenderTarget_setClearColor(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("lstg.ResRenderTarget", "lstg.ResRenderTarget:setClearColor");
	LUA_TRY_INVOKE(1, &lstg::ResRenderTarget::setClearColor);
	LUA_INVOKE_FOOTER("1");
}
int lua_lstg_ResRenderTarget_setNeedBlendFix(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("lstg.ResRenderTarget", "lstg.ResRenderTarget:setNeedBlendFix");
	LUA_TRY_INVOKE(1, &lstg::ResRenderTarget::setNeedBlendFix);
	LUA_INVOKE_FOOTER("1");
}
int lua_lstg_ResRenderTarget_create(lua_State* lua_S)
{
	LUA_SINVOKE_HEADER("lstg.ResRenderTarget", "lstg.ResRenderTarget:create");
	LUA_TRY_INVOKE_R(1, &lstg::ResRenderTarget::create);
	LUA_SINVOKE_FOOTER("1");
}
int luaReg_Resource_lstgResRenderTarget(lua_State* lua_S)
{
	LUA_ENTRY("lstg");
	LUA_CLS_DEF_BASE(lstg::ResRenderTarget, "ResRenderTarget", "lstg.ResRenderTarget",
		lstg::Resource, "lstg.Resource",
		nullptr, nullptr);
	LUA_METHOD("copyTexture", lua_lstg_ResRenderTarget_copyTexture);
	LUA_METHOD("getClearColor", lua_lstg_ResRenderTarget_getClearColor);
	LUA_METHOD("getTarget", lua_lstg_ResRenderTarget_getTarget);
	LUA_METHOD("getTexture", lua_lstg_ResRenderTarget_getTexture);
	LUA_METHOD("isNeedBlendFix", lua_lstg_ResRenderTarget_isNeedBlendFix);
	LUA_METHOD("pop", lua_lstg_ResRenderTarget_pop);
	LUA_METHOD("push", lua_lstg_ResRenderTarget_push);
	LUA_METHOD("render", lua_lstg_ResRenderTarget_render);
	LUA_METHOD("setClearColor", lua_lstg_ResRenderTarget_setClearColor);
	LUA_METHOD("setNeedBlendFix", lua_lstg_ResRenderTarget_setNeedBlendFix);
	LUA_METHOD("create", lua_lstg_ResRenderTarget_create);
	LUA_CLS_END();
	LUA_ENTRY_END(1);
	return 0;
}
