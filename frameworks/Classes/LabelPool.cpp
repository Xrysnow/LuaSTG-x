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

Label* LabelPool::getWithResFont(ResFont* res, const std::string& str)
{
	if (!res)
		return nullptr;
	const auto it = idle.find(res);
	if (it != idle.end())
	{
		if (!it->second.empty())
		{
			auto ret = it->second.back();
			it->second.popBack();
			ResFont::syncLabelSetting(res->getLabel(), ret);
			return ret;
		}
	}
	auto ret = res->createLabel();
	if(ret)
		pool[res].pushBack(ret);
	return ret;
}

void LabelPool::onResFontRemove(ResFont* res)
{
	if (!res)
		return;
	idle.erase(res);
	pool.erase(res);
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
