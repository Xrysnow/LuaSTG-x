#pragma once
#include "ComponentManager.h"
#include "GameClass.h"

namespace lstg
{
	// GameObject status
	enum GAMEOBJECTSTATUS
	{
		STATUS_FREE = 0, // for list header
		STATUS_DEFAULT,  // normal
		STATUS_KILL,     // set by kill event
		STATUS_DEL       // set by del event
	};

	class GameClass;
	class ComponentManager;

	struct GameObject
	{
		// list field
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
		size_t luaID;              // (internal) id in lua pool
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

		cocos2d::Vec2 getPosition() const;
		float getRotation() const;
	};
}
