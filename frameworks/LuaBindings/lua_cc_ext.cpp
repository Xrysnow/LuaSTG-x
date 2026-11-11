#include "lua_cc_ext.hpp"
#include "2d/CCSprite.h"
#include "base/CCRefPtr.h"
#include "platform/CCImage.h"
#include "renderer/CCTexture2D.h"
#include "../Classes/XBuffer.h"
#include "Util/Utility.h"
#include "lua_conversion/lua_conversion.hpp"

namespace
{
template <class RasterSize>
cocos2d::Sprite* createSVGSprite(const std::string& path, const RasterSize& size)
{
    using namespace cocos2d;
    RefPtr<Image> image(ReferencedObject<Image>{new Image()});
    if (!lstg::initImageWithSVG(image.get(), path, size))
        return nullptr;
    RefPtr<Texture2D> texture(ReferencedObject<Texture2D>{new Texture2D()});
    if (!texture->initWithImage(image.get()))
        return nullptr;
    return Sprite::createWithTexture(texture.get());
}
}

// These adapters describe buffers and readback regions. Conversion, overload
// checks, diagnostics and self returns use the shared binding implementation.
int lua_cc_ext_Image_initWithImageData(lua_State* lua_S)
{
    LUA_INVOKE_HEADER("cc.Image", "cc.Image:initWithImageData");
    LUA_TRY_INVOKE_R(1, [](cocos2d::Image* image, lstg::Buffer* data) {
        return data && image->initWithImageData(data->data(), data->size());
    });
    LUA_INVOKE_FOOTER("1");
}

int lua_cc_ext_Image_initWithRawData(lua_State* lua_S)
{
    LUA_INVOKE_HEADER("cc.Image", "cc.Image:initWithRawData");
    LUA_TRY_INVOKE_R(4, [](cocos2d::Image* image, lstg::Buffer* data,
        int width, int height, int bitsPerComponent) {
        return data && image->initWithRawData(data->data(), data->size(), width, height, bitsPerComponent);
    });
    LUA_TRY_INVOKE_R(5, [](cocos2d::Image* image, lstg::Buffer* data,
        int width, int height, int bitsPerComponent, bool premultiplied) {
        return data && image->initWithRawData(data->data(), data->size(), width, height, bitsPerComponent, premultiplied);
    });
    LUA_INVOKE_FOOTER("4,5");
}

int lua_cc_ext_Image_initWithSVGFile(lua_State* lua_S)
{
    LUA_INVOKE_HEADER("cc.Image", "cc.Image:initWithSVGFile");
    LUA_TRY_INVOKE_R(1, [](cocos2d::Image* image, const std::string& path) {
        return lstg::initImageWithSVG(image, path, cocos2d::Size());
    });
    LUA_TRY_INVOKE_R_OVERLOAD(2, [](cocos2d::Image* image, const std::string& path, float scale) {
        return lstg::initImageWithSVG(image, path, scale);
    });
    LUA_TRY_INVOKE_R_OVERLOAD(2, [](cocos2d::Image* image, const std::string& path, const cocos2d::Size& size) {
        return lstg::initImageWithSVG(image, path, size);
    });
    LUA_TRY_INVOKE_R(3, [](cocos2d::Image* image, const std::string& path, float scale, const std::string& units) {
        return lstg::initImageWithSVG(image, path, scale, units);
    });
    LUA_TRY_INVOKE_R(4, [](cocos2d::Image* image, const std::string& path, float scale, const std::string& units, float dpi) {
        return lstg::initImageWithSVG(image, path, scale, units, dpi);
    });
    LUA_INVOKE_FOOTER("1,2,3,4");
}

int lua_cc_ext_Texture2D_newImage(lua_State* lua_S)
{
    LUA_INVOKE_HEADER("cc.Texture2D", "cc.Texture2D:newImage");
    LUA_TRY_INVOKE_R(0, [](cocos2d::Texture2D* texture) {
        return lstg::getTextureImage(texture);
    });
    LUA_TRY_INVOKE_R(1, [](cocos2d::Texture2D* texture, bool flip) {
        return lstg::getTextureImage(texture, flip);
    });
    LUA_TRY_INVOKE_R(4, [](cocos2d::Texture2D* texture, size_t x, size_t y, size_t width, size_t height) {
        return lstg::getTextureImage(texture, x, y, width, height);
    });
    LUA_TRY_INVOKE_R(5, [](cocos2d::Texture2D* texture, size_t x, size_t y, size_t width, size_t height, bool flip) {
        return lstg::getTextureImage(texture, x, y, width, height, flip);
    });
    LUA_INVOKE_FOOTER("0,1,4,5");
}

int lua_cc_ext_Sprite_newImage(lua_State* lua_S)
{
    LUA_INVOKE_HEADER("cc.Sprite", "cc.Sprite:newImage");
    LUA_TRY_INVOKE_R(0, [](cocos2d::Sprite* sprite) {
        return lstg::getSpriteImage(sprite);
    });
    LUA_TRY_INVOKE_R(1, [](cocos2d::Sprite* sprite, bool flip) {
        return lstg::getSpriteImage(sprite, flip);
    });
    LUA_INVOKE_FOOTER("0,1");
}

int lua_cc_ext_Sprite_createWithSVGFile(lua_State* lua_S)
{
    // The old Lua helper omitted a nil size through unpack({path, size}).
    if (lua_gettop(lua_S) == 3 && lua_isnil(lua_S, 3))
        lua_pop(lua_S, 1);
    LUA_SINVOKE_HEADER("cc.Sprite", "cc.Sprite:createWithSVGFile");
    LUA_TRY_INVOKE_R(1, [](const std::string& path) {
        return createSVGSprite(path, cocos2d::Size());
    });
    LUA_TRY_INVOKE_R_OVERLOAD(2, [](const std::string& path, float scale) {
        return createSVGSprite(path, scale);
    });
    LUA_TRY_INVOKE_R_OVERLOAD(2, [](const std::string& path, const cocos2d::Size& size) {
        return createSVGSprite(path, size);
    });
    LUA_SINVOKE_FOOTER("1,2");
}

int register_all_cc_ext(lua_State* tolua_S)
{
    if (nullptr == tolua_S)
        return 0;
    lua_pushstring(tolua_S, "cc.Image");
    lua_rawget(tolua_S, LUA_REGISTRYINDEX);
    if (lua_istable(tolua_S, -1))
    {
        tolua_function(tolua_S, "initWithImageData", lua_cc_ext_Image_initWithImageData);
        tolua_function(tolua_S, "initWithRawData", lua_cc_ext_Image_initWithRawData);
        tolua_function(tolua_S, "initWithSVGFile", lua_cc_ext_Image_initWithSVGFile);
    }
    lua_pop(tolua_S, 1);

    lua_pushstring(tolua_S, "cc.Texture2D");
    lua_rawget(tolua_S, LUA_REGISTRYINDEX);
    if (lua_istable(tolua_S, -1))
        tolua_function(tolua_S, "newImage", lua_cc_ext_Texture2D_newImage);
    lua_pop(tolua_S, 1);

    lua_pushstring(tolua_S, "cc.Sprite");
    lua_rawget(tolua_S, LUA_REGISTRYINDEX);
    if (lua_istable(tolua_S, -1))
    {
        tolua_function(tolua_S, "newImage", lua_cc_ext_Sprite_newImage);
        tolua_function(tolua_S, "createWithSVGFile", lua_cc_ext_Sprite_createWithSVGFile);
    }
    lua_pop(tolua_S, 1);
    return 0;
}
