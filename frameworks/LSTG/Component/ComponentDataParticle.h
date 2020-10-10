#pragma once
#include "ComponentData.h"
#include "cocos2d.h"
#include "Resource/ResParticle.h"

namespace lstg
{
	class ComponentDataParticle : public ComponentData
	{
		bool init(ResParticle* res);
	public:
		ComponentDataParticle();
		~ComponentDataParticle();
		static ComponentDataParticle* create(ResParticle* res);
		ResParticle::ParticlePool* pool;
	};
}
