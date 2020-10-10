#pragma once
#include "ComponentData.h"
#include "cocos2d.h"
#include "../Math/XCollision.h"

namespace lstg
{	
	class ComponentDataColli : public lstg::ComponentData
	{
		bool init() override;
	public:
		CREATE_FUNC(ComponentDataColli);
		void reset();

		xmath::collision::ColliderType type;
		float a;
		float b;
		float col_r;
		int32_t group;
	};
}
