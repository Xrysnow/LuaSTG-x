#pragma once
#include "ComponentData.h"
#include "cocos2d.h"
#include "RenderMode.h"

namespace lstg
{	
	class ComponentDataBlend : public ComponentData
	{
	public:
		CREATE_FUNC(ComponentDataBlend);
		RenderMode* renderMode = nullptr;
		cc::Color4B blendColor = cc::Color4B::WHITE;
		bool useColor = false;
	};
}
