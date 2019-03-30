#pragma once
#include "ComponentData.h"
#include "cocos2d.h"

namespace lstg
{
	class ComponentDataTrasform2D : public ComponentData
	{
		bool init() override;
	public:
		CREATE_FUNC(ComponentDataTrasform2D);
		void reset();
		// update by derivatives
		void update();

		cocos2d::Vec2 anchor;
		float hscale = 1.f;
		float vscale = 1.f;
		float x = 0.f;
		float y = 0.f;
		float z = 0.f;
		float vx = 0.f;
		float vy = 0.f;
		float ax = 0.f;
		float ay = 0.f;
		float rot = 0.f;
		float omega = 0.f;
		float lastx = 0.f;
		float lasty = 0.f;
		float dx = 0.f;
		float dy = 0.f;
		bool navi = false;

		bool is3D = false;
		cocos2d::Vec3 rotAxis;
		float vz = 0.f;
		float az = 0.f;
		float lastz = 0.f;
		float dz = 0.f;
		float zscale = 1.f;
	};
}
