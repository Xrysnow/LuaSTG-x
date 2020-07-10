#include "ComponentDataAni.h"
using namespace lstg;

bool ComponentDataAni::init(ResAnimation* res)
{
	if (res)
		interval = res->getInterval();
	return true;
}

ComponentDataAni* ComponentDataAni::create(ResAnimation* res)
{
	ComponentDataAni *pRet = new(std::nothrow) ComponentDataAni();
	if (pRet && pRet->init(res))
	{
		pRet->autorelease(); return pRet;
	}
	else
	{
		delete pRet;
		pRet = nullptr;
		return nullptr;
	}
}
