#pragma once
#include "Global.h"
#include "GameObject.h"
#include "ComponentManager.h"
#include "GameClass.h"
#include "GameObjectPool.h"

namespace lstg
{
	namespace symbol
	{
		class Block;
	}
	class GameClass;
	//struct GameObject;

	bool CollisionCheck(GameObject* p1, GameObject* p2)noexcept;

	struct less_obj
	{
		bool operator()(GameObject* p1, GameObject* p2) const
		{
			return p1->uid < p2->uid;
		}
	};

	struct less_render
	{
		bool operator()(GameObject* p1, GameObject* p2) const
		{
			return (p1->layer < p2->layer) || ((p1->layer == p2->layer) && (p1->uid < p2->uid));
		}
	};

	class GameObjectManager
	{
	private:
		lua_State* L = nullptr;

		GameObjectPool pool{ LGOBJ_MAXCNT };
		std::array<ComponentManager, LGOBJ_MAXCNT> cmPool;
		std::array<uint32_t, LGOBJ_MAXCNT> idForLua;

		uint64_t _iUid = 0;
		std::set<GameObject*, less_obj> objList;
		std::set<GameObject*, less_render> renderList;
		std::array<std::set<GameObject*, less_obj>, LGOBJ_GROUPCNT> colliList;

		// bound
		lua_Number _boundLeft = -100.f;
		lua_Number _boundRight = 100.f;
		lua_Number _boundTop = 100.f;
		lua_Number _boundBottom = -100.f;

		GameObject* currentObj = nullptr;
		bool inDoFrame = false;
		bool inDoRender = false;

		std::unordered_set<GameObject*> lightSources;

	public:
		explicit GameObjectManager(lua_State* pL);
		~GameObjectManager();

		void ResetLua(lua_State* pL);

		static bool isDefaultFrame(GameObject* p);
		static bool isDefaultRender(GameObject* p);
		static bool isExtProperty(GameObject* p);
		static bool isExtProperty3D(GameObject* p);
	private:

		void freeObjectInternal(GameObject* p) noexcept;
	public:

		GameObject* freeObject(GameObject* p)noexcept;

		GameObject* getCurrentObject() const { return currentObj; }

		bool CheckIsMainThread(lua_State* pL) const noexcept { return pL == L; }

		size_t GetObjectCount()noexcept { return pool.size(); }

		GameObject* GetPooledObject(size_t i)noexcept { return pool.atLua(i); }

		// invoke frame callback on all game objects
		void DoFrame()noexcept;

		// invoke render callback on all game objects
		void DoRender();

		bool IsInBound(float x, float y) const noexcept
		{
			return _boundLeft < x&&x < _boundRight&&_boundBottom < y&&y < _boundTop;
		}

		void SetBound(lua_Number l, lua_Number r, lua_Number b, lua_Number t)noexcept
		{
			_boundLeft = l;
			_boundRight = r;
			_boundBottom = b;
			_boundTop = t;
		}

		// invoke del callback on all game objects that oob
		void BoundCheck()noexcept;

		/* collision check between two groups, will invoke callback of
		 * object in groupA and pass object in groupB as parameter */
		void CollisionCheck(size_t groupA, size_t groupB);
		void CollisionCheck(GameObject* objectA, size_t groupB)noexcept;
		void CollisionCheck(size_t groupA, GameObject* objectB)noexcept;
		void CollisionCheck(GameObject* objectA, GameObject* objectB)noexcept;

		void CollisionCheck3D(size_t groupA, size_t groupB)noexcept;

		// @deprecated
		void UpdateXY()noexcept;

		// update timer, gc
		void AfterFrame()noexcept;

		int RawNew(lua_State* L)noexcept;

		// allocate and push a new object, invoke init callback
		int New(lua_State* L)noexcept;

		// clone object at idx and put result at stack top
		int Clone(lua_State* L, int idx)noexcept;

	private:

		static void callBack(lua_State* L, int callBack, bool hasParam);
		static void callBack(lua_State* L, GameObject* p, int callBack, int objTableIndex);
		// note: objTableIndex should be positive
		static void callBack(lua_State* L, GameObject* pA, GameObject* pB, int callBack, int objTableIndex);
		int del_or_kill(lua_State* L, GAMEOBJECTSTATUS status, int callBackIdx);
	public:
		// trigger del event on object
		int Del(lua_State* L)noexcept;
		// trigger kill event on object
		int Kill(lua_State* L)noexcept;

	public:
		// check if object is valid
		int IsValid(lua_State* L)noexcept;

		// get angle of two objects
		bool Angle(size_t idA, size_t idB, double& out)noexcept;

		// get distance of two objects
		bool Dist(size_t idA, size_t idB, double& out)noexcept;

		// get norm and angle of velocity
		bool GetV(size_t id, double& v, double& a)noexcept;

		// set norm and angle of velocity
		bool SetV(size_t id, double v, double a, bool updateRot)noexcept;

		bool GetLastXY(size_t id, double& x, double& y)noexcept;

		bool SetLastXY(size_t id, double x, double y)noexcept;

		/* @deprecated (only for compatibility)
		 * set RenderMode and color of the resource bind on object */
		bool SetImgState(size_t id, RenderMode* m, const cocos2d::Color4B& c)noexcept;

		// check if object is in given bound
		bool BoxCheck(size_t id, double left, double right, double bottom, double top, bool& ret)noexcept;

		void ResetPool()noexcept;

		static void UpdateParticle(GameObject* p)noexcept;
		bool UpdateParticle(size_t id)noexcept;

		bool DoDefaultRender(size_t id);
		static bool DoDefaultRender(GameObject* p);

		// get id of next object, return -1 when failed
		int NextObject(int groupId, int id)noexcept;
		int NextObject(lua_State* L)noexcept;

		// get id of first object in group, return -1 when failed
		int FirstObject(int groupId)noexcept;

		// __index metamethod for game object
		int GetAttr(lua_State* L)noexcept;

		// __newindex metamethod for game object
		int SetAttr(lua_State* L);

		// bind a cocos2d::Node instance on the game object
		int BindNode(lua_State* L)noexcept;

		// push internal object table
		int GetObjectTable(lua_State* L)noexcept;

		// for operations of particle pool on object
		int GetParticlePool(lua_State* L)noexcept;
	public:

		void DrawGroupCollider(int groupId, const cocos2d::Color4B& fillColor,
			const cocos2d::Vec2& offset);
		void DrawGroupCollider(int groupId, const cocos2d::Color4B& fillColor)
		{
			DrawGroupCollider(groupId, fillColor, cocos2d::Vec2::ZERO);
		}

		GameObject* allocateObject();
		void pushObject(GameObject* obj);
		void pushObject(lua_State* L, GameObject* obj);
		void pushGroup(lua_State* L, size_t group);

		int RegistClass(lua_State* L);

		static bool checkClass(lua_State* L, int idx);
		static uint32_t getClassID(lua_State* L, int idx);
		GameObject* checkObject(lua_State* L, int idx);
		GameObject* checkObjectFast(lua_State* L, int idx);
		bool checkGroupID(int groupID) const;

		void setObjectLayer(GameObject* p, lua_Number layer);
		void setObjectGroup(GameObject* p, lua_Integer group);
		bool setObjectResource(GameObject* p, lua_State* L, int idx);

		size_t updateIDForLua();
		void pushIDForLua(lua_State* L);
	public:

		GameObjectManager& operator=(const GameObjectManager&) = delete;
		GameObjectManager(const GameObjectManager&) = delete;
	};
}
