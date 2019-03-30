#include "ComponentDataParticle.h"

bool lstg::ComponentDataParticle::init(ResParticle* res)
{
	if (!res)return false;
	pool = res->AllocInstance();
	return true;
}

lstg::ComponentDataParticle::ComponentDataParticle()
{
}

lstg::ComponentDataParticle::~ComponentDataParticle()
{
	if (pool)
	{
		pool->getResource()->FreeInstance(pool);
		pool = nullptr;
	}
}

lstg::ComponentDataParticle* lstg::ComponentDataParticle::create(ResParticle* res)
{
	ComponentDataParticle* pRet = new(std::nothrow) ComponentDataParticle();
	if (pRet && pRet->init(res))
	{
		pRet->autorelease();
		return pRet;
	}
	else
	{
		delete pRet;
		pRet = nullptr;
		return nullptr;
	}
}
