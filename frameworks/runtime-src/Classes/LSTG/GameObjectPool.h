#pragma once
#include "Global.h"
#include "ObjectPool.hpp"
#include "ComponentManager.h"
#include "GameClass.h"

namespace lstg
{
	namespace symbol
	{
		class Block;
	}
	class GameClass;

	// GameObject status
	enum GAMEOBJECTSTATUS
	{
		STATUS_FREE = 0, // for list header
		STATUS_DEFAULT,  // normal
		STATUS_KILL,     // set by kill event
		STATUS_DEL       // set by del event
	};

	struct GameObject
	{
		// list feild
		GameObject *pObjectPrev, *pObjectNext;
		GameObject *pRenderPrev, *pRenderNext;
		GameObject *pCollisionPrev, *pCollisionNext;
		ComponentManager* cm = nullptr;
		Resource* res = nullptr;   // resource for render
		lua_Integer timer = 0;     // frame timer
		lua_Integer ani_timer = 0; // ani timer (for compatibility)
		lua_Number layer = 0.0;    // render layer
		GameClass* cls = nullptr;

		GAMEOBJECTSTATUS status;   // status
		size_t id;                 // (internal) id in pool
		int64_t uid;               // (internal) uid

		bool colli;                // need collision check
		bool bound;                // auto del when out of bound
		bool hide;                 // skip render
		// only for allocateObject
		void _Reset();

		void ReleaseResource();

		bool ChangeResource(Resource* r);

		void UpdateXY();
		// only for ex+ compatibility
		void OnDoFrame();

		void CopyAttrFrom(GameObject* other);

		void removeFromList();
	};

	bool CollisionCheck(GameObject* p1, GameObject* p2)noexcept;

	class GameObjectPool
	{
	private:
		lua_State* L = nullptr;
		size_t maxObjectCount;
		size_t maxGroupCount;

		FixedObjectPool<GameObject, LGOBJ_MAXCNT> _objectPool;
		std::array<ComponentManager, LGOBJ_MAXCNT> cmPool;
		std::array<uint32_t, LGOBJ_MAXCNT> idForLua;

		uint64_t _iUid = 0;
		// list header and tail
		GameObject m_pObjectListHeader, m_pObjectListTail;
		GameObject m_pRenderListHeader, m_pRenderListTail;
		GameObject m_pCollisionListHeader[LGOBJ_GROUPCNT], m_pCollisionListTail[LGOBJ_GROUPCNT];

		// bound
		lua_Number _boundLeft = -100.f;
		lua_Number _boundRight = 100.f;
		lua_Number _boundTop = 100.f;
		lua_Number _boundBottom = -100.f;

		GameObject* currentObj = nullptr;
		GameObject* renderMid = nullptr;
		bool inDoFrame = false;
		bool inDoRender = false;

		std::unordered_set<GameObject*> lightSources;

		GameObject* freeObjectInternal(GameObject* p)noexcept;
	public:
		static bool isDefaultFrame(GameObject* p);
		static bool isDefaultRender(GameObject* p);
		static bool isExtProperty(GameObject* p);
		static bool isExtProperty3D(GameObject* p);

		GameObject* freeObject(GameObject* p)noexcept;

		GameObject* getCurrentObject() const { return currentObj; }

		bool CheckIsMainThread(lua_State* pL) const noexcept { return pL == L; }

		size_t GetObjectCount()noexcept { return _objectPool.Size(); }
		
		GameObject* GetPooledObject(size_t i)noexcept { return _objectPool.Data(i); }

		// invoke frame callback on all game objects
		void DoFrame()noexcept;

		// invoke render callback on all game objects
		void DoRender()noexcept;

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

		void CollisionCheck(size_t groupA, size_t groupB)noexcept;
		void CollisionCheck(GameObject* objectA, size_t groupB)noexcept;
		void CollisionCheck(size_t groupA, GameObject* objectB)noexcept;
		void CollisionCheck(GameObject* objectA, GameObject* objectB)noexcept;

		void CollisionCheck3D(size_t groupA, size_t groupB)noexcept;

		void UpdateXY()noexcept;

		// update timer, gc
		void AfterFrame()noexcept;

		int RawNew(lua_State* L)noexcept;

		// allocate and push a new object, invoke init callback
		int New(lua_State* L)noexcept;

		// clone object at idx and put result at stack top
		int Clone(lua_State* L, int idx)noexcept;

	private:
		static void callBack(lua_State* L, GameObject* p, int callBack, bool hasParam);
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
		 * set BlendMode and color of the resource bind on object */
		bool SetImgState(size_t id, BlendMode* m, const cocos2d::Color4B& c)noexcept;

		// check if object is in given bound
		bool BoxCheck(size_t id, double left, double right, double bottom, double top, bool& ret)noexcept;

		void ResetPool()noexcept;

		static void UpdateParticle(GameObject* p)noexcept;
		bool UpdateParticle(size_t id)noexcept;

		bool DoDefaultRender(size_t id)noexcept;
		static bool DoDefaultRender(GameObject* p)noexcept;

		// get id of next object, return -1 when failed
		int NextObject(int groupId, int id)noexcept;
		int NextObject(lua_State* L)noexcept;

		// get id of first object in group, return -1 when failed
		int FirstObject(int groupId)noexcept;

		// __index metamethod for game object
		int GetAttr(lua_State* L)noexcept;

		// __newindex metamethod for game object
		int SetAttr(lua_State* L)noexcept;

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

		void setObjectLayer(GameObject* p, lua_Number layer);
		void setObjectGroup(GameObject* p, lua_Integer group);
		bool setObjectResource(GameObject* p, lua_State* L, int idx);

		size_t updateIDForLua();
		void pushIDForLua(lua_State* L);
	private:

		void insertBeforeObjectList(GameObject* p);
		void insertBeforeRenderList(GameObject* p);
		void insertBeforeCollisionList(GameObject* p, uint32_t group);

		void sortRenderList(GameObject* p);
		static void sortCollisionList(GameObject* p);

	public:
		GameObjectPool& operator=(const GameObjectPool&) = delete;
		GameObjectPool(const GameObjectPool&) = delete;
		explicit GameObjectPool(lua_State* pL);
		~GameObjectPool();

		void ResetLua(lua_State* pL);
	};
}
