#include "GameObjectManager.h"
#include "AppFrame.h"
#include "CollisionDetect.h"
#include "GameObjectPropertyHash.h"
#include "Renderer.h"
#include "Util/Utility.h"
#include "Util/UtilLua.h"
#include "LuaWrapper/LuaWrapper.h"
#include "XProfiler.h"
#include "Component/ComponentDataAni.h"
#include "LogSystem.h"
#include "XThreadPool.hpp"
#include "../Math/XMath.h"
#include "Symbol/GameObjectSymbol.h"
#include "scripting/lua-bindings/manual/LuaBasicConversions.h"

#define METATABLE_OBJ "mt"

#define error_prop(L, p) luaL_error(L, "invalid argument for property '%s'", p)
#define error_obj(L) luaL_error(L, "invalid luastg game object")
#ifdef min
#undef min
#endif
#ifdef max
#undef max
#endif

using namespace std;
using namespace cocos2d;
using namespace lstg;
using namespace xmath;
using namespace intersect;
using namespace collision;

bool lstg::CollisionCheck(GameObject* p1, GameObject* p2) noexcept
{
	// skip
	if (!p1->colli || !p2->colli)
		return false;
	return p1->cm->collisionCheck(p2->cm);
}

void CreateObjectTable(lua_State* L)
{
	// create a global table to hold game object
	lua_pushlightuserdata(L, (void*)&LAPP);  // p
	lua_createtable(L, LGOBJ_MAXCNT, 0);  // p t

	// get lstg.GetAttr and lstg.SetAttr, create metatable
	lua_newtable(L);  // ... t
	lua_getglobal(L, "lstg");  // ... t t
	lua_pushstring(L, "GetAttr");  // ... t t s
	lua_gettable(L, -2);  // ... t t f(GetAttr)
	lua_pushstring(L, "SetAttr");  // ... t t f(GetAttr) s
	lua_gettable(L, -3);  // ... t t f(GetAttr) f(SetAttr)
	CCASSERT(lua_iscfunction(L, -1) && lua_iscfunction(L, -2), "GameObjectPool: Wrong lua stack.");
	lua_setfield(L, -4, "__newindex");  // ... t t f(GetAttr)
	lua_setfield(L, -3, "__index");  // ... t t
	lua_pop(L, 1);  // ... t(mt)

	// save to register[app]['mt']
	lua_setfield(L, -2, METATABLE_OBJ);  // p t
	lua_settable(L, LUA_REGISTRYINDEX);
}

////////////////////////////////////////////////////////////////////////////////

GameObjectManager::GameObjectManager(lua_State* pL)
	: L(pL), idForLua()
{
	for (auto& cm : cmPool)
	{
		cm.pool = &pool;
	}
	CreateObjectTable(L);
}

GameObjectManager::~GameObjectManager()
{
	ResetPool();
}

void GameObjectManager::ResetLua(lua_State* pL)
{
	L = pL;
	GameClass::clear(pL);
	lightSources.clear();
}

bool GameObjectManager::isDefaultFrame(GameObject* p)
{
	return p->cls->isDefaultFrame;
}

bool GameObjectManager::isDefaultRender(GameObject* p)
{
	return p->cls->isDefaultRender;
}

bool GameObjectManager::isExtProperty(GameObject* p)
{
	return p->cls->extProperty;
}

bool GameObjectManager::isExtProperty3D(GameObject* p)
{
	return p->cls->is3D;
}

// will not erase from objList, expect ot on lua stack
void GameObjectManager::freeObjectInternal(GameObject* p) noexcept
{
	const auto it = objList.find(p);
	//objList.erase(it);
	renderList.erase(p);
	colliList[p->cm->getDataColli()->group].erase(p);
	// delete from obj table, assert there is ot on stack
	lua_pushnil(L);  // ot nil
	lua_rawseti(L, -2, p->luaID + 1);  // ot
	// release resource
	p->ReleaseResource();
	p->cm->releaseComponentsForGameObject();
	if (p->cm->getLightSource())
		lightSources.erase(p);
	p->status = STATUS_FREE;
	// delete from pool
	pool.free(p);
}

GameObject* GameObjectManager::freeObject(GameObject* p) noexcept
{
	const auto it = objList.find(p);
	GameObject* pRet = nullptr;
	const auto next = std::next(it);
	if (next != objList.end())
		pRet = *next;
	objList.erase(it);
	renderList.erase(p);
	colliList[p->cm->getDataColli()->group].erase(p);
	// delete from obj table
	GetObjectTable(L);  // ot
	lua_pushnil(L);  // ot nil
	lua_rawseti(L, -2, p->luaID + 1);  // ot
	lua_pop(L, 1);
	// release resource
	p->ReleaseResource();
	p->cm->releaseComponentsForGameObject();
	if (p->cm->getLightSource())
		lightSources.erase(p);
	p->status = STATUS_FREE;
	// delete from pool
	pool.free(p);
	return pRet;
}

void GameObjectManager::DoFrame() noexcept
{
	inDoFrame = true;
	GetObjectTable(L);  // ot
	uint32_t last_classID = 0;

	for (auto&& p : objList)
	{
		currentObj = p;
		if (p->cls->isDefaultFrame)
		{
			// pass
		}
		else if (p->cls->frameBlock)
		{
			p->cls->frameBlock->exe(p);
		}
		else
		{
			const auto cid = p->cls->id;
			CCASSERT(cid != 0, "internal error");
			if (cid != last_classID)
			{
				lua_settop(L, 1);  // ot
				p->cls->pushLuaFrameFunc(L);  // ot f(frame)
				lua_pushvalue(L, -1);  // ot f(frame) f(frame)
				lua_rawgeti(L, 1, p->luaID + 1);  // ot f(frame) f(frame) obj
				// lua_call is the most slow function here
				lua_call(L, 1, 0);  // ot f(frame)
				last_classID = cid;
			}
			else
			{
				lua_pushvalue(L, -1);  // ot f(frame) f(frame)
				lua_rawgeti(L, 1, p->luaID + 1);  // ot f(frame) f(frame) obj
				lua_call(L, 1, 0);  // ot f(frame)
			}
		}		
	}
	currentObj = nullptr;

	//XProfiler::getInstance()->tic("updateTransform");
	if (LTHP.empty())
	{
		pool.update(0, pool.size());
		for (auto j = 0u; j < pool.size(); j++)
			pool.at(j)->cm->updateParticle();
	}
	else
	{
		deployThreadTaskAndWait(pool.size(), LTHP.size() + 1, [this](int start, int end, int)
		{
			pool.update(start, end);
			for (auto j = start; j < end; j++)
				pool.at(j)->cm->updateParticle();
		});
	}
	//XProfiler::getInstance()->toc("updateTransform");

	lua_pop(L, 1);
	inDoFrame = false;
}

void GameObjectManager::DoRender()
{
	inDoRender = true;
	//XProfiler::getInstance()->tic("updateTransformMat");
	if (LTHP.empty())
	{
		for (auto&& p : renderList)
		{
			// TODO: will waste, should make a flag for p
			if (!p->hide/*&&p->isDefaultRender*/)
				p->cm->updateTransformMat();
		}
	}
	else
	{
		static vector<GameObject*> to_render;
		to_render.clear();
		to_render.reserve(GetObjectCount());
		for (auto&& p : renderList)
		{
			// TODO: will waste, should make a flag for p
			if (!p->hide/*&&p->isDefaultRender*/)
				to_render.push_back(p);
		}
		const auto dat = to_render.data();
		deployThreadTaskAndWait(to_render.size(), LTHP.size() + 1, [=](int start, int end, int)
		{
			for (auto j = start; j < end; j++)
				dat[j]->cm->updateTransformMat();
		});
	}
	//XProfiler::getInstance()->toc("updateTransformMat");

	// collect light sources
	vector<BaseLight*> lights;
	for (auto& o : lightSources)
	{
		if (o->cm->getLightSource())
			lights.push_back(o->cm->getLightSource());
	}

	GetObjectTable(L);  // ot

	uint32_t last_classID = 0;
	for (auto&& p : renderList)
	{
		if (!p->hide)
		{
			currentObj = p;
			if (p->cls->isDefaultRender)
			{
				p->cm->applyLights(lights);// only enable light here
				DoDefaultRender(p);
			}
			else
			{
				const auto cid = p->cls->id;
				if (cid != last_classID)
				{
					lua_settop(L, 1);  // ot
					p->cls->pushLuaRenderFunc(L);  // ot f(render)
					if (lua_isnil(L, -1))
					{
						DoDefaultRender(p);
					}
					else
					{
						lua_pushvalue(L, -1);  // ot f(render) f(render)
						lua_rawgeti(L, 1, p->luaID + 1);  // ot f(render) f(render) obj
						lua_call(L, 1, 0);  // ot f(render)
					}
					last_classID = cid;
				}
				else
				{
					// ot f(render)
					if (lua_isnil(L, -1))
					{
						DoDefaultRender(p);
					}
					else
					{
						lua_pushvalue(L, -1);  // ot f(render) f(render)
						lua_rawgeti(L, 1, p->luaID + 1);  // ot f(render) f(render) obj
						lua_call(L, 1, 0);  // ot f(render)
					}
				}
			}
		}
	}
	lua_pop(L, 1);
	currentObj = nullptr;
	inDoRender = false;
}

void GameObjectManager::SetBound(lua_Number l, lua_Number r, lua_Number b, lua_Number t) noexcept
{
	_boundLeft = l;
	_boundRight = r;
	_boundBottom = b;
	_boundTop = t;
}

void GameObjectManager::BoundCheck() noexcept
{
	GetObjectTable(L);  // ot
	const auto ot_idx = lua_gettop(L);
	if (LTHP.empty())
	{
		for(auto&& p : objList)
		{
			if (p->bound && !p->cm->boundCheck(_boundLeft, _boundRight, _boundBottom, _boundTop))
			{
				p->status = STATUS_DEL;
				callBack(L, p, LGOBJ_CC_DEL, ot_idx);
			}
		}
	}
	else
	{
		const auto size = pool.size();
		auto result = new bool[size];//TODO:
		pool.boundCheck(_boundLeft, _boundRight, _boundBottom, _boundTop, result);
		for (auto i = 0u; i < size; ++i)
		{
			if (result[i])
			{
				const auto p = pool.at(i);
				p->status = STATUS_DEL;
				callBack(L, p, LGOBJ_CC_DEL, ot_idx);
			}
		}
		delete[] result;
	}
	lua_pop(L, 1);
}

void GameObjectManager::CollisionCheck(size_t groupA, size_t groupB)
{
	if (!checkGroupID(groupA) || !checkGroupID(groupB))
		luaL_error(L, "Invalid collision group.");

	GetObjectTable(L);  // groupA groupB ot
	const auto ot_idx = lua_gettop(L);

	if (groupA != groupB)
	{
		if (LTHP.empty())
		{
			for (auto&& pA : colliList[groupA])
			{
				for(auto&& pB: colliList[groupB])
				{
					if (::CollisionCheck(pA, pB))
						callBack(L, pA, pB, LGOBJ_CC_COLLI, ot_idx);
				}
			}
		}
		else
		{
			static vector<GameObject*> to_colli_lhs;
			static vector<GameObject*> to_colli_rhs;
			const auto nobj = GetObjectCount();
			to_colli_lhs.clear();
			to_colli_lhs.reserve(nobj);
			to_colli_rhs.clear();
			to_colli_rhs.reserve(nobj);
			// store objects to check
			for (auto&& pA : colliList[groupA])
			{
				if (pA->colli)
				{
					for (auto&& pB : colliList[groupB])
					{
						if (pB->colli)
						{
							to_colli_lhs.push_back(pA);
							to_colli_rhs.push_back(pB);
						}
					}
				}
			}
			// note that order should be kept
			const auto size = to_colli_lhs.size();
			auto dat_l = to_colli_lhs.data();
			auto dat_r = to_colli_rhs.data();
			const auto nThr = LTHP.size() + 1;
			using _result_t = std::pair<vector<GameObject*>, vector<GameObject*>>;
			auto futures = deployThreadTaskFuture(size, nThr, [=](int start, int end, int)
			{
				vector<GameObject*> lhs;
				vector<GameObject*> rhs;
				for (auto j = start; j < end; j++)
				{
					if (::CollisionCheck(dat_l[j], dat_r[j]))
					{
						lhs.push_back(dat_l[j]);
						rhs.push_back(dat_r[j]);
					}
				}
				return make_shared<_result_t>(std::make_pair(lhs, rhs));
			});
			for (auto& fu : futures)
			{
				auto ptr = static_pointer_cast<_result_t>(fu.get());
				auto& lhs = ptr->first;
				auto& rhs = ptr->second;
				const auto sz = lhs.size();
				for (auto j = 0u; j < sz; ++j)
				{
					callBack(L, lhs[j], rhs[j], LGOBJ_CC_COLLI, ot_idx);
				}
			}
		}
		lua_pop(L, 1);
	}
	else
	{
		for (auto&& pA : colliList[groupA])
		{
			for (auto&& pB : colliList[groupB])
			{
				if (::CollisionCheck(pA, pB) && pA != pB)
					callBack(L, pA, pB, LGOBJ_CC_COLLI, ot_idx);
			}
		}
		lua_pop(L, 1);
	}
}

void GameObjectManager::CollisionCheck(GameObject* objectA, size_t groupB) noexcept
{
	if (!objectA)
		return;
	const auto groupA = objectA->cm->getDataColli()->group;
	if (!checkGroupID(groupA) || !checkGroupID(groupB))
		luaL_error(L, "Invalid collision group.");
	const auto pA = objectA;
	GetObjectTable(L);  // ot
	lua_rawgeti(L, -1, pA->luaID + 1);  // ot objA
	lua_rawgeti(L, -1, 1);  // ot objA cls
	lua_rawgeti(L, -1, LGOBJ_CC_COLLI);  // ot objA cls f(colli)
	lua_remove(L, -2);  // ot objA f(colli)
	for (auto&& pB : colliList[groupB])
	{
		if (::CollisionCheck(pA, pB) && pA != pB)
		{
			lua_pushvalue(L, -1);  // ot objA f(colli) f(colli)
			lua_pushvalue(L, -3);  // ot objA f(colli) f(colli) objA
			lua_rawgeti(L, -5, pB->luaID + 1);  // ot objA f(colli) f(colli) objA objB
			lua_call(L, 2, 0);  // ot objA f(colli)
		}
	}
	lua_pop(L, 3);
}

void GameObjectManager::CollisionCheck(size_t groupA, GameObject* objectB) noexcept
{
	if (!objectB)
		return;
	const auto groupB = objectB->cm->getDataColli()->group;
	if (!checkGroupID(groupA) || !checkGroupID(groupB))
		luaL_error(L, "Invalid collision group.");
	const auto pB = objectB;
	GetObjectTable(L);  // ot
	lua_rawgeti(L, -1, pB->luaID + 1);  // ot objB
	for (auto&& pA : colliList[groupA])
	{
		if (::CollisionCheck(pA, pB) && pA != pB)
		{
			// id -> lua table -> class -> collifunc
			lua_rawgeti(L, -2, pA->luaID + 1);  // ot objB objA
			lua_rawgeti(L, -1, 1);  // ot objB objA cls
			lua_rawgeti(L, -1, LGOBJ_CC_COLLI);  // ot objB objA cls f(colli)
			lua_pushvalue(L, -3);  // ot objB objA cls f(colli) objA
			lua_pushvalue(L, -5);  // ot objB objA cls f(colli) objA objB
			lua_call(L, 2, 0);  // ot objB objA cls
			lua_pop(L, 2);  // ot objB
		}
	}
	lua_pop(L, 1);
}

void GameObjectManager::CollisionCheck(GameObject* objectA, GameObject* objectB) noexcept
{
	if (!objectA || !objectB)
		return;
	if (::CollisionCheck(objectA, objectB) && objectA != objectB)
	{
		GetObjectTable(L);  // ot
		lua_rawgeti(L, -1, objectA->luaID + 1);  // ot objA
		lua_rawgeti(L, -1, 1);  // ot objA cls
		lua_rawgeti(L, -1, LGOBJ_CC_COLLI);  // ot objA cls f(colli)
		lua_pushvalue(L, -3);  // ot objA cls f(colli) objA
		lua_rawgeti(L, -5, objectB->luaID + 1);  // ot objA cls f(colli) objA objB
		lua_call(L, 2, 0);  // ot objA cls
		lua_pop(L, 3);
	}
}

void GameObjectManager::CollisionCheck3D(size_t groupA, size_t groupB) noexcept
{
	if (!checkGroupID(groupA) || !checkGroupID(groupB))
		luaL_error(L, "Invalid collision group.");
	GetObjectTable(L);  // ot
	if (groupA != groupB)
	{
		for (auto&& pA : colliList[groupA])
		{
			for (auto&& pB : colliList[groupB])
			{
				if (pA->colli && pB->colli && pA->cm->collisionCheck3D(pB->cm))
				{
					// id -> lua table -> class -> collifunc
					lua_rawgeti(L, -1, pA->luaID + 1);  // ot obj
					lua_rawgeti(L, -1, 1);  // ot obj cls
					lua_rawgeti(L, -1, LGOBJ_CC_COLLI);  // ot obj cls f(colli)
					lua_pushvalue(L, -3);  // ot obj cls f(colli) obj
					lua_rawgeti(L, -5, pB->luaID + 1);  // ot obj cls f(colli) obj obj
					lua_call(L, 2, 0);  // ot obj cls
					lua_pop(L, 2);  // ot
				}
			}
		}
		lua_pop(L, 1);
	}
	else
	{
		for (auto&& pA : colliList[groupA])
		{
			for (auto&& pB : colliList[groupB])
			{
				if (pA->colli && pB->colli && pA->cm->collisionCheck3D(pB->cm) && pA != pB)
				{
					// id -> lua table -> class -> collifunc
					lua_rawgeti(L, -1, pA->luaID + 1);  // ot obj
					lua_rawgeti(L, -1, 1);  // ot obj cls
					lua_rawgeti(L, -1, LGOBJ_CC_COLLI);  // ot obj cls f(colli)
					lua_pushvalue(L, -3);  // ot obj cls f(colli) obj
					lua_rawgeti(L, -5, pB->luaID + 1);  // ot obj cls f(colli) obj obj
					lua_call(L, 2, 0);  // ot obj cls
					lua_pop(L, 2);  // ot
				}
			}
		}
		lua_pop(L, 1);
	}
}

void GameObjectManager::UpdateXY() noexcept
{
}

void GameObjectManager::AfterFrame() noexcept
{
	GetObjectTable(L);
	for (auto it = objList.begin(); it != objList.end();)
	{
		const auto p = *it;
		p->timer++;
		p->cm->updateAni();
		p->ani_timer++;
		if (p->status != STATUS_DEFAULT)
		{
			freeObjectInternal(p);
			it = objList.erase(it);
		}
		else
			++it;
	}
	lua_pop(L, 1);
}

int GameObjectManager::RawNew(lua_State* L) noexcept
{
	if (!checkClass(L, 1))
		return luaL_error(L, "invalid argument #1, luastg object class required for 'RawNew'.");

	const auto p = allocateObject();
	if (!p)
		return luaL_error(L, "can't alloc object, object pool may be full.");

	const auto cid = getClassID(L, 1);
	p->cls = GameClass::getByID(cid);
	if (!p->cls)
		return luaL_error(L, "invalid luastg game class");
	p->cm->getDataTrasform()->is3D = isExtProperty3D(p);
	// obj[1]=class
	// obj[2]=id
	// setmetatable(obj, ot["mt"])
	// ot[id+1]=obj
	GetObjectTable(L);  // cls ... ot
	lua_createtable(L, 2, 0);  // cls ... ot obj
	lua_pushvalue(L, 1);  // cls ... ot obj cls
	lua_rawseti(L, -2, 1);  // cls ... ot obj  // set class
	lua_pushinteger(L, lua_Integer(p->luaID));  // cls ... ot obj id
	lua_rawseti(L, -2, 2);  // cls ... ot obj  // set id
	lua_getfield(L, -2, METATABLE_OBJ);  // cls ... ot obj mt
	lua_setmetatable(L, -2);  // cls ... ot obj  // set metatable
	lua_pushvalue(L, -1);  // cls ... ot obj obj
	lua_rawseti(L, -3, p->luaID + 1);  // cls ... ot obj  // store in ot

	lua_insert(L, 1);  // obj cls ... ot
	lua_settop(L, 1);  // obj

	const auto id = p->id;
	pool.lastx[id] = pool.x[id];
	pool.lasty[id] = pool.y[id];
	return 1;
}

int GameObjectManager::New(lua_State* L) noexcept
{
	if (!checkClass(L, 1))
		return luaL_error(L, "invalid argument #1, luastg object class required for 'New'.");

	auto p = allocateObject();
	if (!p)
		return luaL_error(L, "can't alloc object, object pool may be full.");

	const auto cid = getClassID(L, 1);
	p->cls = GameClass::getByID(cid);
	if (!p->cls)
		return luaL_error(L, "invalid luastg game class");
	p->cm->getDataTrasform()->is3D = isExtProperty3D(p);

	// obj[1]=class
	// obj[2]=id
	// setmetatable(obj, ot["mt"])
	// ot[id+1]=obj
	// class.init(obj, ...)

	GetObjectTable(L);  // cls ... ot
	lua_createtable(L, 2, 0);  // cls ... ot obj
	lua_pushvalue(L, 1);  // cls ... ot obj cls
	lua_rawseti(L, -2, 1);  // cls ... ot obj  // set class
	lua_pushinteger(L, lua_Integer(p->luaID));  // cls ... ot obj id
	lua_rawseti(L, -2, 2);  // cls ... ot obj  // set id
	lua_getfield(L, -2, METATABLE_OBJ);  // cls ... ot obj mt
	lua_setmetatable(L, -2);  // cls ... ot obj  // set metatable
	lua_pushvalue(L, -1);  // cls ... ot obj obj
	lua_rawseti(L, -3, p->luaID + 1);  // cls ... ot obj  // store in ot
	lua_insert(L, 1);  // obj cls ... ot
	lua_pop(L, 1);  // obj cls ...
	lua_rawgeti(L, 2, LGOBJ_CC_INIT);  // obj cls ... f(init)
	lua_insert(L, 3);  // obj cls f(init) ...
	lua_pushvalue(L, 1);  // obj cls f(init) ... obj
	lua_insert(L, 4);  // obj cls f(init) obj ...
	lua_call(L, lua_gettop(L) - 3, 0);  // obj cls  // init callback

	//note: f(init) may change class
	lua_pop(L, 1);

	const auto id = p->id;
	pool.lastx[id] = pool.x[id];
	pool.lasty[id] = pool.y[id];
	return 1;
}
//TODO:
int GameObjectManager::Clone(lua_State* L, int idx) noexcept { return 0; }

//int GameObjectPool::Clone(lua_State* L, int idx) noexcept
//{
//	auto p = checkObject(L, idx);
//	if (!p)
//		return luaL_error(L, "not a valid luastg object for 'Clone'.");
//	const auto pNew = allocateObject();
//	if (!pNew)
//		return luaL_error(L, "can't alloc object, object pool may be full.");
//	pNew->CopyAttrFrom(p);
//	pNew->layer++;
//	pNew->group++;
//	setObjectLayer(pNew, p->layer);
//	setObjectGroup(pNew, p->group);
//	if (pNew->res)
//	{
//		if (pNew->res->getType() == ResourceType::Particle)
//		{
//			pNew->ps = dynamic_cast<ResParticle*>(pNew->res)->AllocInstance();
//			pNew->ps->setInactive();
//			pNew->ps->setCenter(Vec2(float(pNew->x), float(pNew->y)));
//			pNew->ps->setRotation(float(pNew->rot));
//			pNew->ps->setActive();
//		}
//		pNew->res->retain();
//	}
//
//	// obj[1]=class
//	// obj[2]=id
//	// setmetatable(obj, ot["mt"])
//	// ot[id+1]=obj
//
//	GetObjectTable(L);  // ... ot
//	lua_createtable(L, 2, 0);  // ... ot obj
//	if (idx < 0)idx = idx - 2;
//	lua_rawgeti(L, idx, 1);  // ... ot obj class
//	lua_rawseti(L, -2, 1);  // ... ot obj
//
//	lua_pushinteger(L, lua_Integer(pNew->luaID));  // ... ot obj id
//	lua_rawseti(L, -2, 2);  // ... ot obj
//
//	lua_getfield(L, -2, METATABLE_OBJ);  // ... ot obj mt
//	lua_setmetatable(L, -2);  // ... ot obj
//
//	lua_pushvalue(L, -1);  // ... ot obj obj
//	lua_rawseti(L, -3, pNew->luaID + 1);  // ... ot obj
//
//	lua_remove(L, -2);  // ... obj
//	return 1;
//}

void GameObjectManager::callBack(lua_State* L, int callBack, bool hasParam)
{
	//if (!p) return;
	// note: prepare stack
	if (hasParam)
	{
		// obj ...
		lua_rawgeti(L, 1, 1);  // obj ... class
		lua_rawgeti(L, -1, callBack);  // obj ... class f
		lua_insert(L, 1);  // f obj ... class
		lua_pop(L, 1);  // f obj ...
		lua_call(L, lua_gettop(L) - 1, 0); //
	}
	else
	{
		// ... obj
		lua_rawgeti(L, -1, 1);  // ... obj class
		lua_rawgeti(L, -1, callBack);  // ... obj class f
		lua_insert(L, -3);  // ... f obj class
		lua_pop(L, 1);     // ... f obj
		lua_call(L, 1, 0); // ...
	}
}

void GameObjectManager::callBack(lua_State* L, GameObject* p, int callBack, int objTableIndex)
{
	// id -> lua table -> class -> func
	lua_rawgeti(L, objTableIndex, p->luaID + 1);  // ... obj
	lua_rawgeti(L, -1, 1);  // ... obj cls
	lua_rawgeti(L, -1, callBack);  // ... obj cls f
	lua_pushvalue(L, -3);  // ... obj cls f obj
	lua_call(L, 1, 0);  // ... obj cls
	lua_pop(L, 2);  // ...
}

void GameObjectManager::callBack(lua_State* L, GameObject* pA, GameObject* pB, int callBack, int objTableIndex)
{
	// id -> lua table -> class -> func
	lua_rawgeti(L, objTableIndex, pA->luaID + 1);  // ... A
	lua_rawgeti(L, -1, 1);  // ... A cls
	lua_rawgeti(L, -1, callBack);  // ... A cls f
	lua_pushvalue(L, -3);  // ... A cls f A
	lua_rawgeti(L, objTableIndex, pB->luaID + 1);  // ... A cls f A B
	lua_call(L, 2, 0);  // ... A cls
	lua_pop(L, 2);  // ...
}

int GameObjectManager::del_or_kill(lua_State* L, GAMEOBJECTSTATUS status, int callBackIdx)
{
	const auto type = lua_type(L, 1);
	if (type == LUA_TTABLE)
	{
		lua_rawgeti(L, 1, 2);
		const auto type2 = lua_type(L, -1);
		if (type2 == LUA_TNUMBER) // F(obj)
		{
			// obj ... id
			auto p = pool.atLua(size_t(luaL_checknumber(L, -1)));
			lua_pop(L, 1);  // obj ...
			if (!p)
				return error_obj(L);
			if (p->status == STATUS_DEFAULT)
			{
				p->status = status;
				callBack(L, callBackIdx, true);
			}
			return 0;
		}
		else // F({obj})
		{
			lua_settop(L, 1);
			// t
			const auto num = lua_objlen(L, 1);
			for (auto i = 1u; i <= num; ++i)
			{
				lua_rawgeti(L, 1, i); // t obj
				lua_rawgeti(L, 1, 2); // t obj id
				auto p = pool.atLua(size_t(luaL_checknumber(L, -1)));
				lua_pop(L, 1);  // t obj
				if (!p)
					return error_obj(L);
				if (p->status == STATUS_DEFAULT)
				{
					p->status = status;
					callBack(L, callBackIdx, false); // t
				}
			}
			return 0;
		}
	}
	else if (type == LUA_TNUMBER) // F(group)
	{
		const auto group = lua_tointeger(L, 1);
		if (!checkGroupID(group))
			return luaL_error(L, "invalid collision group %d", group);
		// note: no extra param
		lua_settop(L, 0);
		GetObjectTable(L); // ot
		for (auto&&p : colliList[group])
		{
			if (p->status == STATUS_DEFAULT)
			{
				p->status = status;
				lua_rawgeti(L, -1, p->luaID + 1); // ot obj
				callBack(L, callBackIdx, false); // ot
			}
		}
		return 0;
	}
	return luaL_error(L, "invalid argument #1");
}

int GameObjectManager::Del(lua_State* L) noexcept
{
	return del_or_kill(L, STATUS_DEL, LGOBJ_CC_DEL);
}

int GameObjectManager::Kill(lua_State* L) noexcept
{
	return del_or_kill(L, STATUS_KILL, LGOBJ_CC_KILL);
}

int GameObjectManager::IsValid(lua_State* L) noexcept
{
	lua_pushboolean(L, checkObject(L, -1) ? 1 : 0);
	return 1;
}

bool GameObjectManager::Angle(size_t idA, size_t idB, double& out) noexcept
{
	const auto pA = pool.atLua(idA);
	const auto pB = pool.atLua(idB);
	if (!pA || !pB)
		return false;
	out = (double)LRAD2DEGREE * atan2(pool.y[pB->id] - pool.y[pA->id], pool.x[pB->id] - pool.x[pA->id]);
	return true;
}

bool GameObjectManager::Dist(size_t idA, size_t idB, double& out) noexcept
{
	const auto pA = pool.atLua(idA);
	const auto pB = pool.atLua(idB);
	if (!pA || !pB)
		return false;
	const auto dx = pool.x[pB->id] - pool.x[pA->id];
	const auto dy = pool.y[pB->id] - pool.y[pA->id];
	out = sqrt(dx * dx + dy * dy);
	return true;
}

bool GameObjectManager::GetV(size_t id, double& v, double& a) noexcept
{
	const auto p = pool.atLua(id);
	if (!p)
		return false;
	id = p->id;
	v = sqrt(pool.vx[id] * pool.vx[id] + pool.vy[id] * pool.vy[id]);
	a = (double)LRAD2DEGREE * atan2(pool.vy[id], pool.vx[id]);
	return true;
}

bool GameObjectManager::SetV(size_t id, double v, double a, bool updateRot) noexcept
{
	const auto p = pool.atLua(id);
	if (!p)
		return false;
	const auto rad = a * LDEGREE2RAD;
	id = p->id;
	pool.vx[id] = v * cos(rad);
	pool.vy[id] = v * sin(rad);
	if (updateRot)
	{
		pool.rot[id] = rad;
		p->cm->setTransformDirty(true);
	}
	return true;
}

bool GameObjectManager::GetLastXY(size_t id, double& x, double& y) noexcept
{
	const auto p = pool.atLua(id);
	if (!p)
		return false;
	id = p->id;
	x = pool.lastx[id];
	y = pool.lasty[id];
	return true;
}

bool GameObjectManager::SetLastXY(size_t id, double x, double y) noexcept
{
	auto p = pool.atLua(id);
	if (!p)
		return false;
	id = p->id;
	pool.lastx[id] = x;
	pool.lasty[id] = y;
	return true;
}

bool GameObjectManager::SetImgState(size_t id, RenderMode* m, const Color4B& c) noexcept
{
	GameObject* p = pool.atLua(id);
	if (!p)
		return false;
	if (p->res)
	{
		switch (p->res->getType())
		{
		case ResourceType::Sprite:
		{
			auto s = static_cast<ResSprite*>(p->res);
			s->setRenderMode(m);
			s->setColor(c);
		}
		break;
		case ResourceType::Animation:
		{
			auto ani = static_cast<ResAnimation*>(p->res);
			ani->setRenderMode(m);
			ani->setColor(c);
		}
		break;
		default:
			break;
		}
	}
	return true;
}

bool GameObjectManager::BoxCheck(size_t id,
	double left, double right, double bottom, double top, bool& ret) noexcept
{
	const auto p = pool.atLua(id);
	if (!p)
		return false;
	ret = pool.boxCheck(p->id, left, right, bottom, top);
	return true;
}

void GameObjectManager::ResetPool() noexcept
{
	GetObjectTable(L);
	for (auto&& p : objList)
	{
		freeObjectInternal(p);
	}
	objList.clear();
	if (!renderList.empty())
	{
		XERROR("render list is not properly cleaned!");
		renderList.clear();
	}
	for (auto&& s : colliList)
	{
		if (!s.empty())
		{
			XERROR("collision list is not properly cleaned!");
			s.clear();
		}
	}
	lua_pop(L, 1);
}

void GameObjectManager::UpdateParticle(GameObject* p) noexcept
{
	if (!p)
		return;
	p->cm->updateParticle();
}

bool GameObjectManager::UpdateParticle(size_t id) noexcept
{
	auto p = pool.atLua(id);
	if (!p)
		return false;
	UpdateParticle(p);
	return true;
}

bool GameObjectManager::DoDefaultRender(size_t id)
{
	return DoDefaultRender(pool.atLua(id));
}

using QUEUE_GROUP = RenderQueue::QUEUE_GROUP;
bool GameObjectManager::DoDefaultRender(GameObject* p)
{
	if (!p)
		return false;
	if (p->res)
	{
		if (p->cm->isTransformDirty())
			p->cm->updateTransformMat();
		switch (p->res->getType())
		{
		case ResourceType::Sprite:
			p->cm->renderSprite((ResSprite*)p->res);
			break;
		case ResourceType::Animation:
			p->cm->renderAnimation((ResAnimation*)p->res);
			break;
		case ResourceType::Particle:
			p->cm->renderParticle();
			break;
		case ResourceType::Font:
			p->cm->renderLabel();
			break;
		case ResourceType::Texture:
			p->cm->renderTexture((ResTexture*)p->res);
			break;
		default:
			break;
		}
	}
	if (p->cm->getBindNode())
	{
		LRR.flushTriangles();
		LRR.updateRenderMode(RenderMode::getDefault());
		//LRR.pushDummyCommand();
		const auto node = p->cm->getBindNode();
		const auto sp3d = dynamic_cast<Sprite3D*>(node);
		const auto zorder = node->getGlobalZOrder();
		if (zorder != 0.f || sp3d)
		{
			const auto vp_store = LMP.applyArray<Viewport, 1>();
			const auto proj_store = LMP.getMat4();
			auto vp = LRR.getCurrentViewport();
			const auto mt = LRR.getCurrentProjection();
			const auto f1 = [=]() {
				vp_store->at(0) = Director::getInstance()->getRenderer()->getViewport();
				*proj_store = Director::getInstance()->getMatrix(MATRIX_STACK_TYPE::MATRIX_STACK_PROJECTION);

				Director::getInstance()->getRenderer()->setViewPort(vp.x, vp.y, vp.w, vp.h);
				Director::getInstance()->loadMatrix(MATRIX_STACK_TYPE::MATRIX_STACK_PROJECTION, mt);
			};
			const auto f2 = [=]() {
				auto& v = vp_store->at(0);
				Director::getInstance()->getRenderer()->setViewPort(v.x, v.y, v.w, v.h);
				Director::getInstance()->loadMatrix(MATRIX_STACK_TYPE::MATRIX_STACK_PROJECTION, *proj_store);
			};
			if (zorder != 0.f)
			{
				LRR.pushCallbackCommand(QUEUE_GROUP::GLOBALZ_NEG, zorder, f1);
				node->visit();
				LRR.pushCallbackCommand(QUEUE_GROUP::GLOBALZ_NEG, zorder, f2);
			}
			else
			{
				LRR.pushCallbackCommand(QUEUE_GROUP::OPAQUE_3D, zorder, f1);
				LRR.pushCallbackCommand(QUEUE_GROUP::TRANSPARENT_3D, zorder, f1);
				node->visit();
				LRR.pushCallbackCommand(QUEUE_GROUP::OPAQUE_3D, zorder, f2);
				LRR.pushCallbackCommand(QUEUE_GROUP::TRANSPARENT_3D, zorder, f2);
			}
		}
		else
		{
			node->visit();
		}
	}
	return true;
}

int GameObjectManager::NextObject(int groupId, int id) noexcept
{
	if (id < 0)
		return -1;

	GameObject* p = pool.atLua(static_cast<size_t>(id));
	if (!p)
		return -1;

	// traverse all if not a valid group
	if (!checkGroupID(groupId))
	{
		auto it = objList.find(p);
		if (it == objList.end())
		{
			XERROR("can't find GameObject in objList!");
			return -1;
		}
		++it;
		if (it == objList.end())
			return -1;
		return static_cast<int>((*it)->luaID);
	}
	else
	{
		if (p->cm->getDataColli()->group != groupId)
		{
			XERROR("got inconsistent group id!");
			return -1;
		}
		auto it = colliList[groupId].find(p);
		if (it == colliList[groupId].end())
		{
			XERROR("can't find GameObject in colliList %d!", groupId);
			return -1;
		}
		++it;
		if (it == colliList[groupId].end())
			return -1;
		return static_cast<int>((*it)->luaID);
	}
}

int GameObjectManager::NextObject(lua_State* L) noexcept
{
	int g = luaL_checkinteger(L, 1);  // i(groupId)
	const int id = luaL_checkinteger(L, 2);  // id
	if (id < 0)
		return 0;

	lua_pushinteger(L, NextObject(g, id));  // ??? i(next)
	GetObjectTable(L);  // ??? i(next) ot
	lua_rawgeti(L, -1, id + 1);  // ??? i(next) ot obj
	lua_remove(L, -2);  // ??? i(next) obj
	return 2;
}

int GameObjectManager::FirstObject(int groupId) noexcept
{
	// traverse all if not a valid group
	if (!checkGroupID(groupId))
	{
		const auto it = objList.begin();
		if (it == objList.end())
			return -1;
		return static_cast<int>((*it)->luaID);
	}
	else
	{
		const auto it = colliList[groupId].begin();
		if (it == colliList[groupId].end())
			return -1;
		return static_cast<int>((*it)->luaID);
	}
}

int GameObjectManager::GetAttr(lua_State* L) noexcept
{
	lua_rawgeti(L, 1, 2);  // obj s(key) ... i(id)
	auto id = size_t(lua_tonumber(L, -1));
	lua_pop(L, 1);  // obj s(key)
	GameObject* p = pool.atLua(id);
	if (!p)
		return luaL_error(L, "invalid lstg object for '__index' meta operation.");

	id = p->id;
	// property
	size_t strlen;
	const char* key = luaL_checklstring(L, 2, &strlen);

	// shortcut for x, y
	if (key[0] == 'x' && key[1] == '\0')
	{
		lua_pushnumber(L, pool.x[id]);
		return 1;
	}
	if (key[0] == 'y' && key[1] == '\0')
	{
		lua_pushnumber(L, pool.y[id]);
		return 1;
	}
	// others
	const auto cm = p->cm;
	switch (GameObjectPropertyHash(key))
	{
	case GameObjectProperty::ROT:
		lua_pushnumber(L, pool.rot[id] * LRAD2DEGREE_D);
		break;
	case GameObjectProperty::OMEGA:
		lua_pushnumber(L, pool.omega[id] * LRAD2DEGREE_D);
		break;
	case GameObjectProperty::TIMER:
		lua_pushinteger(L, p->timer);
		break;
	case GameObjectProperty::DX:
		lua_pushnumber(L, pool.dx[id]);
		break;
	case GameObjectProperty::DY:
		lua_pushnumber(L, pool.dy[id]);
		break;
	case GameObjectProperty::VX:
		lua_pushnumber(L, pool.vx[id]);
		break;
	case GameObjectProperty::VY:
		lua_pushnumber(L, pool.vy[id]);
		break;
	case GameObjectProperty::AX:
		lua_pushnumber(L, pool.ax[id]);
		break;
	case GameObjectProperty::AY:
		lua_pushnumber(L, pool.ay[id]);
		break;
	case GameObjectProperty::LAYER:
		lua_pushnumber(L, p->layer);
		break;
	case GameObjectProperty::GROUP:
		lua_pushinteger(L, cm->getDataColli()->group);
		break;
	case GameObjectProperty::HIDE:
		lua_pushboolean(L, p->hide);
		break;
	case GameObjectProperty::BOUND:
		lua_pushboolean(L, p->bound);
		break;
	case GameObjectProperty::NAVI:
		lua_pushboolean(L, pool.navi[id]);
		break;
	case GameObjectProperty::COLLI:
		lua_pushboolean(L, p->colli);
		break;
	case GameObjectProperty::STATUS:
		switch (p->status)
		{
		case STATUS_DEFAULT:
			lua_pushstring(L, "normal");
			break;
		case STATUS_KILL:
			lua_pushstring(L, "kill");
			break;
		case STATUS_DEL:
			lua_pushstring(L, "del");
			break;
		default:
			lua_pushnil(L);
			break;
		}
		break;
	case GameObjectProperty::HSCALE:
		lua_pushnumber(L, pool.hscale[id]);
		break;
	case GameObjectProperty::VSCALE:
		lua_pushnumber(L, pool.vscale[id]);
		break;
	case GameObjectProperty::CLASS:
		lua_rawgeti(L, 1, 1);
		break;
	case GameObjectProperty::A:
		lua_pushnumber(L, cm->getDataColli()->a / colliderScale);
		break;
	case GameObjectProperty::B:
		lua_pushnumber(L, cm->getDataColli()->b / colliderScale);
		break;
	case GameObjectProperty::RECT:
		lua::ColliderType_to_luaval(L, cm->getDataColli()->type);
		break;
	case GameObjectProperty::IMG:
		if (p->res)
			lua_pushstring(L, p->res->getName().c_str());
		else
			lua_pushnil(L);
		break;
	case GameObjectProperty::ANI:
		lua_pushinteger(L, cm->getAniTimer());
		break;
	case GameObjectProperty::RES:
		if (isExtProperty(p))
		{
			if (p->res)
				p->res->pushLua(L);
			else
				lua_pushnil(L);
		}
		else
			lua_pushnil(L);
		break;
	case GameObjectProperty::RES_COMPONENT:
		if (isExtProperty(p))
		{
			if (p->res)
				p->cm->pushLua(L, p->res);
			else
				lua_pushnil(L);
		}
		else
			lua_pushnil(L);
		break;
	case GameObjectProperty::RENDERMODE:
		if (isExtProperty(p))
		{
			const auto dat = p->cm->getDataBlend();
			if (dat)
				object_to_luaval(L, "lstg.RenderMode", dat->renderMode);
			else
				lua_pushnil(L);
		}
		else
			lua_pushnil(L);
		break;
	case GameObjectProperty::COLOR:
		if (isExtProperty(p))
		{
			const auto dat = p->cm->getDataBlend();
			if (dat)
				lua::_color4b_to_luaval(L, dat->blendColor);
			else
				lua_pushnil(L);
		}
		else
			lua_pushnil(L);
		break;
	case GameObjectProperty::_A:
		if (isExtProperty(p))
			lua_pushinteger(L, p->cm->getColorA());
		else
			lua_pushnil(L);
		break;
	case GameObjectProperty::_R:
		if (isExtProperty(p))
			lua_pushinteger(L, p->cm->getColorR());
		else
			lua_pushnil(L);
		break;
	case GameObjectProperty::_G:
		if (isExtProperty(p))
			lua_pushinteger(L, p->cm->getColorG());
		else
			lua_pushnil(L);
		break;
	case GameObjectProperty::_B:
		if (isExtProperty(p))
			lua_pushinteger(L, p->cm->getColorB());
		else
			lua_pushnil(L);
		break;
	case GameObjectProperty::LIGHT:
		if (isExtProperty(p))
		{
			// 1.light source 2.light flag 3.nil
			const auto lightSource = p->cm->getLightSource();
			if (lightSource)
			{
				lua::BaseLight_to_luaval(L, lightSource);
				break;
			}
			const auto data = p->cm->getDataLight();
			if (data)
			{
				lua_pushnumber(L, data->lightFlag);
				break;
			}
			lua_pushnil(L);
		}
		else
			lua_pushnil(L);
		break;

#define GET_3D_VALUE(_P) if (isExtProperty3D(p))\
		lua_pushnumber(L, cm->getDataTrasform()->_P);\
		else lua_pushnil(L); break;

	case GameObjectProperty::Z:
		GET_3D_VALUE(z);
	case GameObjectProperty::DZ:
		GET_3D_VALUE(dz);
	case GameObjectProperty::VZ:
		GET_3D_VALUE(vz);
	case GameObjectProperty::AZ:
		GET_3D_VALUE(az);
	case GameObjectProperty::ZSCALE:
		GET_3D_VALUE(zscale);
	case GameObjectProperty::QUAT:
		if (isExtProperty3D(p))
		{
			Quaternion q;
			Quaternion::createFromAxisAngle(
				p->cm->getOrCreateTrasform2D()->rotAxis, pool.rot[id], &q);
			quaternion_to_luaval(L, q);
		}
		else
			lua_pushnil(L);
		break;
	case GameObjectProperty::X:
	case GameObjectProperty::Y:
	default:
#if 0
		// not very useful
		if (isExtProperty(p))
		{
			p->cls->pushLua(L); // obj s ... cls
			lua_pushvalue(L, 2); // obj s ... cls s
			lua_gettable(L, -2); // obj s ... cls v
		}
		else
#endif
			lua_pushnil(L);
		break;
	}
	return 1;
}

int GameObjectManager::SetAttr(lua_State* L)
{
	lua_rawgeti(L, 1, 2);  // obj s(key) any(v) i(id)
	auto id = static_cast<size_t>(lua_tonumber(L, -1));
	lua_pop(L, 1);  // obj s(key) any(v)

	GameObject* p = pool.atLua(id);
	if (!p)
		return luaL_error(L, "invalid lstg object for '__newindex' meta operation.");

	id = p->id;
	// property
	size_t strlen;
	const char* key = luaL_checklstring(L, 2, &strlen);

	// shortcut for x, y
	if (key[0] == 'x' && key[1] == '\0')
	{
		p->cm->setX(luaL_checknumber(L, 3));
		return 0;
	}
	if (key[0] == 'y' && key[1] == '\0')
	{
		p->cm->setY(luaL_checknumber(L, 3));
		return 0;
	}
	// others
	const auto cm = p->cm;
	switch (GameObjectPropertyHash(key))
	{
	case GameObjectProperty::DX:
		return luaL_error(L, "property 'dx' is readonly");
	case GameObjectProperty::DY:
		return luaL_error(L, "property 'dy' is readonly");
	case GameObjectProperty::ROT:
		p->cm->setRot(luaL_checknumber(L, 3) * LDEGREE2RAD);
		break;
	case GameObjectProperty::OMEGA:
		pool.omega[id] = luaL_checknumber(L, 3) * LDEGREE2RAD;
		break;
	case GameObjectProperty::TIMER:
		p->timer = luaL_checkinteger(L, 3);
		break;
	case GameObjectProperty::VX:
		pool.vx[id] = luaL_checknumber(L, 3);
		break;
	case GameObjectProperty::VY:
		pool.vy[id] = luaL_checknumber(L, 3);
		break;
	case GameObjectProperty::AX:
		pool.ax[id] = luaL_checknumber(L, 3);
		break;
	case GameObjectProperty::AY:
		pool.ay[id] = luaL_checknumber(L, 3);
		break;
	case GameObjectProperty::LAYER:
		setObjectLayer(p, luaL_checknumber(L, 3));
		break;
	case GameObjectProperty::GROUP:
		setObjectGroup(p, luaL_checkinteger(L, 3));
		break;
	case GameObjectProperty::HIDE:
		p->hide = lua_toboolean(L, 3) != 0;
		break;
	case GameObjectProperty::BOUND:
		p->bound = lua_toboolean(L, 3) != 0;
		break;
	case GameObjectProperty::NAVI:
		pool.navi[id] = lua_toboolean(L, 3) != 0;
		break;
	case GameObjectProperty::COLLI:
		p->colli = lua_toboolean(L, 3) != 0;
		break;
	case GameObjectProperty::STATUS:
		do {
			const char* val = luaL_checkstring(L, 3);
			if (strcmp(val, "normal") == 0)
				p->status = STATUS_DEFAULT;
			else if (strcmp(val, "del") == 0)
				p->status = STATUS_DEL;
			else if (strcmp(val, "kill") == 0)
				p->status = STATUS_KILL;
			else
				return error_prop(L, "status");
		} while (false);
		break;
	case GameObjectProperty::HSCALE:
		p->cm->setHScale(luaL_checknumber(L, 3));
		break;
	case GameObjectProperty::VSCALE:
		p->cm->setVScale(luaL_checknumber(L, 3));
		break;
	case GameObjectProperty::CLASS:
		{
			// obj s(key) cls
			lua_rawgeti(L, -1, 7);// obj s(key) cls cid
			const auto cid = luaL_checkinteger(L, -1);
			const auto cls = GameClass::getByID(cid);
			if (!cls)
				return error_prop(L, "class");
			p->cls = cls;
			lua_pop(L, 1);
			lua_rawseti(L, 1, 1);
			p->cm->getDataTrasform()->is3D = isExtProperty3D(p);
		}
		break;
	case GameObjectProperty::A:
		{
			const auto v = luaL_checknumber(L, 3);
			if (!cm->setColliA((float)v * colliderScale))
				return luaL_error(L, "invalid negative value for property 'a': %f", v);
		}
		break;
	case GameObjectProperty::B:
		{
			const auto v = luaL_checknumber(L, 3);
			if (!cm->setColliB((float)v * colliderScale))
				return luaL_error(L, "invalid negative value for property 'b': %f", v);
		}
		break;
	case GameObjectProperty::RECT:
		if (!lua::luaval_to_ColliderType(L, 3, &cm->getDataColli()->type))
			return error_prop(L, "rect");
		cm->updateColli();
		break;
	case GameObjectProperty::IMG:
		if (!setObjectResource(p, L, 3))
			return luaL_error(L, "can't set resource");
		break;
	case GameObjectProperty::ANI:
		cm->setAniTimer(luaL_checkinteger(L, 3));
		break;
	case GameObjectProperty::RES:
		if (!setObjectResource(p, L, 3))
			return luaL_error(L, "can't set resource");
		break;
	case GameObjectProperty::RES_COMPONENT:
		if (isExtProperty(p))
		{
			// readonly
		}
		else
			lua_rawset(L, 1);
		break;
	case GameObjectProperty::RENDERMODE:
		if (isExtProperty(p))
		{
			RenderMode* v = nullptr;
			lua::luaval_to_RenderMode(L, 3, &v);
			if (!v)
				return error_prop(L, "rm");
			const auto blend = p->cm->getOrCreateBlend();
			blend->renderMode = v;
		}
		else
			lua_rawset(L, 1);
		break;
	case GameObjectProperty::COLOR:
		if (isExtProperty(p))
		{
			Color4B c;
			if (lua_type(L, 3) == LUA_TNUMBER)
			{
				const uint32_t val = luaL_checkinteger(L, 3);
				c.a = val >> 24;
				c.r = val >> 16;
				c.g = val >> 8;
				c.b = val;
			}
			else if (!lua::_luaval_to_color4b(L, 3, &c))
			{
				return error_prop(L, "color");
			}
			const auto blend = p->cm->getOrCreateBlend();
			blend->blendColor = c;
			blend->useColor = true;
		}
		else
			lua_rawset(L, 1);
		break;

#define  SET_COLOR_VALUE(_P)\
	if (isExtProperty(p)){\
		p->cm->setColor##_P(luaL_checkinteger(L, 3));\
	} else lua_rawset(L, 1); break;

	case GameObjectProperty::_A:
		SET_COLOR_VALUE(A);
	case GameObjectProperty::_R:
		SET_COLOR_VALUE(R);
	case GameObjectProperty::_G:
		SET_COLOR_VALUE(G);
	case GameObjectProperty::_B:
		SET_COLOR_VALUE(B);
	case GameObjectProperty::LIGHT:
		if (isExtProperty(p))
		{
			const auto type = lua_type(L, 3);
			if (type == LUA_TNUMBER)
			{
				const auto flag = luaL_checkinteger(L, 3);
				if (flag == 0)
				{
					p->cm->setDataLight(nullptr);
				}
				else
				{
					const auto data = p->cm->getOrCreateLight();
					data->lightFlag = luaL_checknumber(L, 3);
				}
			}
			else if (type == LUA_TUSERDATA)
			{
				const auto source = lua::tousertype<BaseLight>(L, 3, "cc.BaseLight");
				if (source)
				{
					p->cm->setLightSource(source);
					lightSources.insert(p);
				}
			}
			else if (type == LUA_TNIL)
			{
				p->cm->setLightSource(nullptr);
				lightSources.erase(p);
			}
		}
		else
			lua_rawset(L, 1);
		break;

#define SET_3D_VALUE(_P) if (isExtProperty3D(p))\
		cm->getDataTrasform()->_P = luaL_checknumber(L, 3);\
		else lua_rawset(L, 1); break;

	case GameObjectProperty::Z:
		if (isExtProperty3D(p))
		{
			p->cm->setZ(luaL_checknumber(L, 3));
		}
		else
			lua_rawset(L, 1);
		break;
	case GameObjectProperty::DZ:
		if (isExtProperty3D(p))
			return luaL_error(L, "property 'dz' is readonly");
		else
			lua_rawset(L, 1);
		break;
	case GameObjectProperty::VZ:
		SET_3D_VALUE(vz);
	case GameObjectProperty::AZ:
		SET_3D_VALUE(az);
	case GameObjectProperty::ZSCALE:
		if (isExtProperty3D(p))
		{
			p->cm->setZScale(luaL_checknumber(L, 3));
		}
		else
			lua_rawset(L, 1);
		break;
	case GameObjectProperty::QUAT:
		if (isExtProperty3D(p))
		{
			const auto type = lua_type(L, 3);
			if (type == LUA_TTABLE)
			{
				lua_pushstring(L, "w");
				lua_rawget(L, 3);
				if (lua_type(L, -1) == LUA_TNUMBER)
				{
					Quaternion q;
					luaval_to_quaternion(L, 3, &q);
					pool.rot[id] =
						q.toAxisAngle(&(cm->getOrCreateTrasform2D()->rotAxis));
				}
				else
				{
					luaval_to_vec3(L, 3, &(cm->getOrCreateTrasform2D()->rotAxis));
					cm->getOrCreateTrasform2D()->rotAxis.normalize();
				}
				p->cm->setTransformDirty(true);
			}
			else
				return error_prop(L, "quat");
		}
		else
			lua_rawset(L, 1);
		break;
	case GameObjectProperty::X:
	case GameObjectProperty::Y:
		break;
	default:
		lua_rawset(L, 1);
		break;
	}
	return 0;
}

int GameObjectManager::BindNode(lua_State* L) noexcept
{
	const auto p = checkObjectFast(L, 1);
	if (!p)
		return error_obj(L);
	p->cm->setBindNode(lua::tousertype<Node>(L, 2, "cc.Node"));
	return 0;
}

int GameObjectManager::GetObjectTable(lua_State* L) noexcept
{
	lua_pushlightuserdata(L, (void*)&LAPP);
	lua_gettable(L, LUA_REGISTRYINDEX);
#if 0
	if (!lua_istable(L, -1))
		return luaL_error(L, "invalid object table");
#endif
	return 1;
}

int GameObjectManager::GetParticlePool(lua_State* L) noexcept
{
	const auto p = checkObjectFast(L, 1);
	if (!p)
		return 0;
	const auto data = p->cm->getDataParticle();
	if (data && data->pool)
	{
		object_to_luaval(L, "lstg.ResParticle::ParticlePool", data->pool);
		return 1;
	}
	return 0;
}

void GameObjectManager::DrawGroupCollider(int groupId, const Color4B& fillColor, const Vec2& offset)
{
	if (!checkGroupID(groupId))
		return;
	for(auto&& p : colliList[groupId])
	{
		if (p->colli)
		{
			p->cm->drawCollider(fillColor);
		}
	}
}

bool GameObjectManager::checkClass(lua_State* L, int idx)
{
	if (!lua_istable(L, idx))
		return false;
	lua_getfield(L, idx, "is_class");  // ... is_class
	const auto v = lua_toboolean(L, -1);
	lua_pop(L, 1);  // ...
	return v;
}

GameObject* GameObjectManager::allocateObject()
{
	// allocate
	const auto p = pool.alloc();
	if (!p)
		return nullptr;

	// initial setting
	p->_Reset();
	p->status = STATUS_DEFAULT;
	p->uid = _iUid++;

	if (p->cm&&p->cm != &cmPool[p->luaID])
	{
		LERROR("error");
	}
	p->cm = &cmPool[p->luaID];
	p->cm->getOrCreateTrasform2D();
	p->cm->getOrCreateColli();
	p->cm->reset();
	p->cm->obj = p;
	//p->cm->id = p->id;

	// insert to list
	objList.insert(p);
	renderList.insert(p);
	// already set to 0 in p->cm->reset()
	//p->cm->getDataColli()->group = 0;
	colliList[0].insert(p);
	return p;
}

void GameObjectManager::pushObject(GameObject* obj)
{
	if (L)
		pushObject(L, obj);
}

void GameObjectManager::pushObject(lua_State* L, GameObject* obj)
{
	if (obj&&obj->status != STATUS_FREE)
	{
		GetObjectTable(L);
		lua_rawgeti(L, -1, obj->luaID + 1);
		lua_remove(L, -2);
	}
	else
		lua_pushnil(L);
}

void GameObjectManager::pushGroup(lua_State* L, size_t group)
{
	if (!checkGroupID(group))
	{
		//lua_createtable(L, 0, 0);
		lua_pushnil(L);
	}
	else
	{
		GetObjectTable(L);
		lua_createtable(L, GetObjectCount() / 2, 0); // ... ot t
		size_t idx = 1;
		for (auto&& p : colliList[group])
		{
			lua_rawgeti(L, -1, p->luaID + 1); // ... ot t obj
			lua_rawseti(L, -2, idx); // ... ot t
			++idx;
		}
	}
}

int GameObjectManager::RegistClass(lua_State* L)
{
	const auto cls = GameClass::registerClass(L);
	if (!cls)
		return luaL_error(L, "failed when register class");
	return 0;
}

uint32_t GameObjectManager::getClassID(lua_State* L, int idx)
{
	lua_rawgeti(L, idx, 7);  // cls ... cid
	const uint32_t cid = lua_tointeger(L, -1);
	lua_pop(L, 1);  // cls ...
	return cid;
}

GameObject* GameObjectManager::checkObject(lua_State* L, int idx)
{
	if (!lua_istable(L, idx))
		return nullptr;
	lua_rawgeti(L, idx, 2);  // ... id
	if (!lua_isnumber(L, -1))
		return nullptr;
	// check in pool
	const auto id = size_t(lua_tonumber(L, -1));
	lua_pop(L, 1);  // ...
	const auto p = pool.atLua(id);
	if (!p)
		return nullptr;

	GetObjectTable(L);  // ... ot
	lua_rawgeti(L, -1, lua_Integer(id + 1));  // ... ot obj
	if (idx < 0)
		idx = idx - 2;
	const bool eq = lua_rawequal(L, -1, idx) != 0;
	lua_pop(L, 2);  // ...
	return eq ? p : nullptr;
}

GameObject* GameObjectManager::checkObjectFast(lua_State* L, int idx)
{
	if (!lua_istable(L, idx))
		return nullptr;
	lua_rawgeti(L, idx, 2);  // ... id
	if (!lua_isnumber(L, -1))
		return nullptr;
	// check in pool
	const auto id = size_t(lua_tonumber(L, -1));
	lua_pop(L, 1);  // ...
	return pool.atLua(id);
}

bool GameObjectManager::checkGroupID(int groupID) const
{
	return 0 <= groupID && groupID < colliList.size();
}

void GameObjectManager::setObjectLayer(GameObject* p, lua_Number layer)
{
	if (layer == p->layer)
		return;
	renderList.erase(p);
	p->layer = layer;
	renderList.insert(p);
}

void GameObjectManager::setObjectGroup(GameObject* p, lua_Integer group)
{
	const auto old = p->cm->getDataColli()->group;
	if (group == old)
		return;
	// remove from old
	if (checkGroupID(old))
	{
		colliList[old].erase(p);
	}
	p->cm->getDataColli()->group = group;
	// insert to new
	if (checkGroupID(group))
	{
		colliList[group].insert(p);
	}
}

bool GameObjectManager::setObjectResource(GameObject* p, lua_State* L, int idx)
{
	const auto type = lua_type(L, idx);
	Resource* res = nullptr;
	if (type == LUA_TSTRING)
	{
		// search name in lua
		const auto name = lua_tostring(L, idx);
		lua_getglobal(L, LFUNC_FINDRES);
		if (!lua_isfunction(L, -1))
		{
			lua_pop(L, 1);
			return false;
		}
		else
		{
			lua_pushstring(L, name);
			lua_pcall(L, 1, 1, 0);
			if (lua_isnil(L, -1))
			{
				lua_pop(L, 1);
				return false;
			}
			res = lua::tousertype<Resource>(L, -1, "lstg.Resource");
			lua_pop(L, 1);
			if (!res)
				return false;
		}
	}
	else if (type == LUA_TUSERDATA)
	{
		for (auto& t : {
			ResourceType::Sprite,
			ResourceType::Animation,
			ResourceType::Particle,
			ResourceType::Font,
			ResourceType::Texture,
		})
		{
			if (!res)
				res = Resource::fromLua(L, idx, t);
			else
				break;
		}
		if (!res)
			return false;
	}
	else if (type == LUA_TNIL)
	{
		p->ReleaseResource();
		return true;
	}

	if (res)
	{
		p->ChangeResource(res);
		return true;
	}
	return false;
}

size_t GameObjectManager::updateIDForLua()
{
	size_t idx = 0;
	for (auto&& p : objList)
	{
		idForLua[idx] = p->luaID + 1;
		idx++;
	}
	return idx;
}

void GameObjectManager::pushIDForLua(lua_State* L)
{
	lua::cptr_to_luaval(L, idForLua.data(), "uint32_t*");
}
