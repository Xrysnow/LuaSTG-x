#pragma once
#include "ComponentData.h"
#include "cocos2d.h"
#include "ResAnimation.h"

namespace lstg
{
	class ComponentDataAni : public lstg::ComponentData
	{
		bool init(ResAnimation* res);
	public:
		static ComponentDataAni* create(ResAnimation* res);

		float interval = 1.f;
		int32_t timer = 0;
	};
}
