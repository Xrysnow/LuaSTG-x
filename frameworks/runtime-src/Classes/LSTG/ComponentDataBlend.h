#pragma once
#include "ComponentData.h"
#include "cocos2d.h"
#include "BlendMode.h"

namespace lstg
{	
	class ComponentDataBlend : public ComponentData
	{
	public:
		CREATE_FUNC(ComponentDataBlend);
		BlendMode* blendMode = nullptr;
		cocos2d::Color4B blendColor;
		bool useColor = false;
	};
}
