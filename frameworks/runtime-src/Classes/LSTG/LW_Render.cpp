#include "LW_Render.h"
#include "AppFrame.h"
#include "LuaWrapper.h"
#include "Utility.h"
#include "Renderer.h"
#include "UtilLua.h"
#include "UtilLuaRes.h"

using namespace std;
using namespace lstg;
using lua::luaval_to_c4b;
using lua::_luaval_to_color4b;

inline int error_render(lua_State* L, int lo)
{
	return luaL_error(L, "can't render '%s'", lua_tostring(L, lo));
}

static int RenderTexture_(lua_State* L) noexcept
{
	//static auto CheckUV = [](float x) { return 0.f <= x&&x <= 1.f + FLT_EPSILON; };
	auto tex = lua::toTexture2D(L, 1);
	if (!tex)
		return luaL_error(L, "can't find texture '%s'", lua_tostring(L, 1));
	const auto blend = TranslateBlendMode(L, 2);
	const auto h = tex->getPixelsHigh();
	const auto w = tex->getPixelsWide();
	auto v = LMP.getQuad();
	auto vi = (cocos2d::V3F_C4B_T2F*)v;
	for (auto i = 0; i < 4; ++i)
	{
		lua_pushinteger(L, 1);
		lua_gettable(L, 3 + i);
		vi[i].vertices.x = float(lua_tonumber(L, -1));
		lua_pushinteger(L, 2);
		lua_gettable(L, 3 + i);
		vi[i].vertices.y = float(lua_tonumber(L, -1));
		lua_pushinteger(L, 3);
		lua_gettable(L, 3 + i);
		vi[i].vertices.z = float(lua_tonumber(L, -1));
		lua_pushinteger(L, 4);
		lua_gettable(L, 3 + i);
		vi[i].texCoords.u = float(lua_tonumber(L, -1)) / w;
		lua_pushinteger(L, 5);
		lua_gettable(L, 3 + i);
		vi[i].texCoords.v = float(lua_tonumber(L, -1)) / h;
		lua_pushinteger(L, 6);
		lua_gettable(L, 3 + i);
		//vi[i].colors = luaval_to_fcycolor_to_c4b(L, -1);
		_luaval_to_color4b(L, -1, &vi[i].colors);

		lua_pop(L, 6);

		//if(!CheckUV(vi[i].texCoords.u)||!CheckUV(vi[i].texCoords.v))
		//{
		//	lua_settop(L, 0);
		//	return luaL_error(L, "got wrong uv value");
		//}
	}
	// note: lua中是顺时针顺序
	std::swap(vi[2], vi[3]);
	if (blend)
		LRR.updateBlendMode(blend);
	if (!LRR.renderTexture(tex, v))
		return error_render(L, 1);
	return 0;
}
static int RenderSector(lua_State* L) noexcept
{
	auto p = lua::toResSprite(L, 1);
	if (!p)
		return luaL_error(L, "can't find image '%s'.", lua_tostring(L, 1));
	auto x = luaL_checknumber(L, 2);
	auto y = luaL_checknumber(L, 3);
	static const float d2r = LDEGREE2RAD;
	static const float d2r_ = d2r*(1 + 2e-7f);
	//static const float d2r_ = d2r*(1 + FLT_EPSILON);
	auto start = luaL_checknumber(L, 4)*d2r;
	auto end = luaL_checknumber(L, 5)*d2r_;
	auto r1 = luaL_checknumber(L, 6);//inner
	auto r2 = luaL_checknumber(L, 7);//outer
	auto nSec = luaL_optnumber(L, 8, 60.);
	if (nSec < 1)
	{
		return luaL_error(L, "argument #8 should larger than 0");
	}
	auto dth = d2r * 180 / nSec;
	int n = floor(abs(end - start) / dth);
	if (n < 1)return 0;
	if (end < start)dth = -dth;

	LRR.updateBlendMode(p->getBlendMode());
	auto tex = p->getSprite()->getTexture();

	const int nBlocks = n / LGOBJ_MAXLASERNODE + 1;
	for (int j = 0; j < nBlocks; ++j)
	{
		int nj = j*LGOBJ_MAXLASERNODE;
		int vCount = LGOBJ_MAXLASERNODE;
		if (j == nBlocks - 1)
			vCount = n - nj;

		auto quads = LMP.getLaserQuads()->data();
		fill_n(quads, vCount, p->getVertex());
		auto vecs = new cocos2d::Vec3[(vCount + 1) * 2];
		for (int i = 0; i < vCount + 1; ++i)
		{
			float th = start + (i + nj)*dth;
			float s = sin(th);
			float c = cos(th);
			vecs[i * 2].set(r2*c + x, r2*s + y, 0.5f);
			vecs[i * 2 + 1].set(r1*c + x, r1*s + y, 0.5f);
		}

		for (int i = 0; i < vCount; ++i)
		{
			quads[i].tr.vertices.set(vecs[i * 2]);
			quads[i].br.vertices.set(vecs[i * 2 + 1]);
			quads[i].tl.vertices.set(vecs[(i + 1) * 2]);
			quads[i].bl.vertices.set(vecs[(i + 1) * 2 + 1]);
		}
		cocos2d::TrianglesCommand::Triangles tri{ nullptr,nullptr,0,0 };
		tri.indexCount = vCount * 6;
		tri.vertCount = vCount * 4;
		tri.indices = XRenderer::quadIndices512;
		tri.verts = (cocos2d::V3F_C4B_T2F*)quads;
		LRR.renderTexture(tex, tri);
		delete[] vecs;
	}
	return 0;
}
static int DrawGroupCollider(lua_State* L) noexcept
{
	const int group_id = luaL_checkinteger(L, 1);
	const auto color = luaval_to_c4b(L, 2);
	const auto off_x = luaL_checknumber(L, 3);
	const auto off_y = luaL_checknumber(L, 4);
	LAPP.GetGameObjectPool().DrawGroupCollider(group_id, color, cocos2d::Vec2(off_x, off_y));
	return 0;
}

vector<luaL_Reg> lstg::LW_Render()
{
	vector<luaL_Reg> ret = {
		{ "RenderTexture", &RenderTexture_ },

		{ "RenderSector", &RenderSector },
		{ "DrawGroupCollider", &DrawGroupCollider },
	};
	return ret;
}
