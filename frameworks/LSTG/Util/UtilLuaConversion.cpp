#include "UtilLuaConversion.h"
#include "tolua_fix.h"

using namespace std;
using namespace lstg::lua;

#if 0
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

	TEST(cc::Vec2);
	TEST(cc::Vec3);
	TEST(cc::Vec4);
	TEST(cc::Size);
	TEST(cc::Rect);
	TEST(cc::Color3B);
	TEST(cc::Color4B);
	TEST(cc::Color4F);
	TEST(cc::Mat4);
	TEST(cc::AffineTransform);
	TEST(cc::FontDefinition);
	TEST(cc::BlendFunc);
	TEST(cc::TTFConfig);
	TEST(cc::Value);
	TEST(cc::MeshVertexAttrib);
	TEST(cc::Quaternion);
	TEST(cc::Texture2D::TexParams);

	TEST(cc::V3F_C4B_T2F_Quad);
	TEST(lstg::RenderMode*);
	TEST(XColliderType);

	TEST(cc::Vector<cc::Node*>);
	TEST(std::vector<cc::Vec2>);
	TEST(std::set<cc::Node*>);
	TEST(std::bitset<8>);
	{ using type = std::array<std::string, 2>; TEST(type); }
	{ using type = cc::Map<std::string, cc::Node*>; TEST(type); }
	{ using type = std::map<cc::Label::LabelType, cc::Color4B>; TEST(type); }
	{ using type = std::unordered_map<cc::Node*, cc::Color4B>; TEST(type); }
	{ using type = std::pair<cc::Node*, cc::Color4B>; TEST(type); }
	{ using type = std::tuple<>; TEST(type); }
	{ using type = std::tuple<cc::Node*>; TEST(type); }
	{ using type = std::tuple<cc::Node*, cc::Color4B>; TEST(type); }
	{ using type = std::function<void()>; { type v; to_native<type>::F(L, 1, &v); }; }
	{ using type = std::function<std::string()>; { type v; to_native<type>::F(L, 1, &v); }; }
	{ using type = std::function<void(const std::string&)>; type v; to_native<type>::F(L, 1, &v); }
	{ using type = std::function<int(const std::string&,int)>; type v; to_native<type>::F(L, 1, &v); }
}
#endif
