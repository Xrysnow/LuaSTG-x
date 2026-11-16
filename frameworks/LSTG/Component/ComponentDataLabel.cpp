#include "ComponentDataLabel.h"
using namespace lstg;
using namespace cocos2d;

bool ComponentDataLabel::init(ResFont* res)
{
	if (!res)return false;
	label = res->createLabel().detach();
	if (!label)
		return false;
	return true;
}

ComponentDataLabel::~ComponentDataLabel()
{
	CC_SAFE_RELEASE_NULL(label);
}

cc::IntrusivePtr<lstg::ComponentDataLabel> lstg::ComponentDataLabel::create(ResFont* res)
{
	cc::IntrusivePtr<ComponentDataLabel> pRet{new(std::nothrow) ComponentDataLabel()};
	if (pRet && pRet->init(res))
	{

		return pRet;
	}
	else
	{

		return nullptr;
	}
}
