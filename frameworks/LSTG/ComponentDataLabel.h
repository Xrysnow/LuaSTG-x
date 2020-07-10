#pragma once
#include "ComponentData.h"
#include "cocos2d.h"
#include "ResFont.h"

namespace lstg
{
	class ComponentDataLabel : public lstg::ComponentData
	{
		bool init(ResFont* res);
	public:
		~ComponentDataLabel();
		static ComponentDataLabel* create(ResFont* res);
		cocos2d::Label* label;
	};
}
