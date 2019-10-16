#include "UtilLuaConversion.h"

using namespace std;
using namespace lstg::lua;

#define TEST(_T) { _T v; to_native<_T>::F(L, 1, &v); to_lua<_T>::F(L, v); }

void test(lua_State* L)
{
	TEST(int8_t);
	TEST(int16_t);
	TEST(int32_t);
	TEST(int64_t);
	TEST(uint8_t);
	TEST(uint16_t);
	TEST(uint32_t);
	TEST(uint64_t);

	TEST(bool);
	TEST(float);
	TEST(double);

	TEST(bool*);
	TEST(char*);
	TEST(float*);

	TEST(const char*);
	TEST(std::string);

	TEST(cocos2d::Vec2);
	TEST(cocos2d::Vec3);
	TEST(cocos2d::Vec4);
	TEST(cocos2d::Size);
	TEST(cocos2d::Rect);
	TEST(cocos2d::Color3B);
	TEST(cocos2d::Color4B);
	TEST(cocos2d::Color4F);
	TEST(cocos2d::Mat4);
	TEST(cocos2d::AffineTransform);
	TEST(cocos2d::FontDefinition);
	TEST(cocos2d::BlendFunc);
	TEST(cocos2d::TTFConfig);
	TEST(cocos2d::Uniform);
	TEST(cocos2d::VertexAttrib);
	TEST(cocos2d::Value);
	TEST(cocos2d::MeshVertexAttrib);
	TEST(cocos2d::Quaternion);
	TEST(cocos2d::Texture2D::TexParams);

	TEST(cocos2d::V3F_C4B_T2F_Quad);
	TEST(lstg::BlendMode*);
	TEST(XColliderType);

	TEST(cocos2d::Vector<cocos2d::Node*>);
	TEST(std::vector<cocos2d::Vec2>);
	TEST(std::set<cocos2d::Node*>);
	TEST(std::bitset<8>);
	{ using type = std::array<std::string, 2>; TEST(type); }
	{ using type = cocos2d::Map<std::string, cocos2d::Node*>; TEST(type); }
	{ using type = std::map<cocos2d::Label::LabelType, cocos2d::Color4B>; TEST(type); }
	{ using type = std::unordered_map<cocos2d::Node*, cocos2d::Color4B>; TEST(type); }
	{ using type = std::pair<cocos2d::Node*, cocos2d::Color4B>; TEST(type); }
	{ using type = std::tuple<>; TEST(type); }
	{ using type = std::tuple<cocos2d::Node*>; TEST(type); }
	{ using type = std::tuple<cocos2d::Node*, cocos2d::Color4B>; TEST(type); }
}
