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
		cc::TrianglesCommand::Triangles tri;
		static cc::IntrusivePtr<ComponentDataVertex> create(ResTexture* res);
	protected:
		bool init(ResTexture* res);
	};
}
