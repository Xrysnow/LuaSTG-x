#include "ComponentDataParticle.h"

bool lstg::ComponentDataParticle::init(ResParticle* res)
{
	if (!res)return false;
	pool = res->newPool();
	return true;
}

lstg::ComponentDataParticle::ComponentDataParticle()
{
}

lstg::ComponentDataParticle::~ComponentDataParticle()
{
	if (pool)
	{
		pool->release();
		pool = nullptr;
	}
}

cc::IntrusivePtr<lstg::ComponentDataParticle> lstg::ComponentDataParticle::create(ResParticle* res)
{
	cc::IntrusivePtr<ComponentDataParticle> pRet{new(std::nothrow) ComponentDataParticle()};
	if (pRet && pRet->init(res))
	{

		return pRet;
	}
	else
	{

		return nullptr;
	}
}
