#include "LabelPool.h"

using namespace std;
using namespace cocos2d;
using namespace lstg;

LabelPool::LabelPool()
{
}

LabelPool::~LabelPool()
{
	clear();
}

Label* LabelPool::getWithResFont(ResFont* res)
{
	const auto name = res->getName();
	Label* ret;
	const auto it = idle.find(name);
	if (it != idle.end())
	{
		if (!it->second.empty())
		{
			ret = it->second.back();
			it->second.popBack();
			ResFont::syncLabelSetting(res->getLabel(), ret);
			return ret;
		}
	}
	ret = res->createLabel();
	if(ret)
		pool[name].pushBack(ret);
	return ret;
}

void LabelPool::restore()
{
	for (auto& p : pool)
	{
		idle[p.first] = p.second;
	}
}

void LabelPool::clear()
{
	pool.clear();
	idle.clear();
}
