#pragma once
#include "cocos2d.h"

namespace lstg
{
	class ComponentData : public cocos2d::Ref
	{
	protected:
		virtual bool init();
	public:
		virtual ~ComponentData(){}
		ComponentData* clone() { return nullptr; }
	};
}

#include "ComponentDataAni.h"
#include "ComponentDataBlend.h"
#include "ComponentDataColli.h"
#include "ComponentDataLabel.h"
#include "ComponentDataParticle.h"
#include "ComponentDataTrasform.h"
#include "ComponentDataVertex.h"
#include "ComponentDataLight.h"
