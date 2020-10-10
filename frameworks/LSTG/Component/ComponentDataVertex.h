#pragma once
#include "ComponentData.h"
#include "cocos2d.h"
#include "Resource/ResTexture.h"

namespace lstg
{
	class ComponentDataVertex : public ComponentData
	{
		ComponentDataVertex();
	public:
		~ComponentDataVertex();
		cocos2d::TrianglesCommand::Triangles tri;
		static ComponentDataVertex* create(ResTexture* res);
	protected:
		bool init(ResTexture* res);
	};
}
