#include "ComponentDataLabel.h"
using namespace lstg;
using namespace cocos2d;

bool ComponentDataLabel::init(ResFont* res)
{
	if (!res)return false;
	label = res->createLabel();
	if (!label)
		return false;
	label->retain();
	return true;
}

ComponentDataLabel::~ComponentDataLabel()
{
	CC_SAFE_RELEASE_NULL(label);
}

lstg::ComponentDataLabel* lstg::ComponentDataLabel::create(ResFont* res)
{
	ComponentDataLabel* pRet = new(std::nothrow) ComponentDataLabel();
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
