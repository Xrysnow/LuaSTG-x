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

		float z = 0.f;
		bool is3D = false;
		cocos2d::Vec3 rotAxis;
		float vz = 0.f;
		float az = 0.f;
		float lastz = 0.f;
		float dz = 0.f;
		float zscale = 1.f;
	};
}
