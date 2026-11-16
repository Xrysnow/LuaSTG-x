#include "ComponentDataAni.h"
using namespace lstg;

bool ComponentDataAni::init(ResAnimation* res)
{
	if (res)
		interval = res->getInterval();
	return true;
}

cc::IntrusivePtr<ComponentDataAni> ComponentDataAni::create(ResAnimation* res)
{
	cc::IntrusivePtr pRet{new(std::nothrow) ComponentDataAni()};
	if (pRet && pRet->init(res))
	{
		return pRet;
	}
	else
	{

		return nullptr;
	}
}
