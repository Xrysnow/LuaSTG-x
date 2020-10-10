#pragma once
#include "Component/ComponentManager.h"
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
		ComponentManager* cm = nullptr;
		Resource* res = nullptr;   // resource for render
		lua_Integer timer = 0;     // frame timer
		lua_Integer ani_timer = 0; // ani timer (for compatibility)
		lua_Number layer = 0.0;    // render layer
		GameClass* cls = nullptr;

		GAMEOBJECTSTATUS status = STATUS_FREE;   // status
		size_t id = 0;             // (internal) id in pool
		size_t luaID = 0;          // (internal) id in lua pool
		int64_t uid = 0;           // (internal) uid

		bool colli = false;        // need collision check
		bool bound = false;        // auto del when out of bound
		bool hide = false;         // skip render
		// only for allocateObject
		void _Reset();

		void ReleaseResource();

		bool ChangeResource(Resource* r);

		void UpdateXY();
		// only for ex+ compatibility
		void OnDoFrame();

		void CopyAttrFrom(GameObject* other);

		cocos2d::Vec2 getPosition() const;
		float getRotation() const;
	};
}
