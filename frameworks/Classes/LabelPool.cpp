#include "LabelPool.h"

using namespace std;
using namespace cc;
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
	if (it != idle.end() && !it->second.empty())
	{
		auto ret = it->second.back();
		it->second.popBack();
		CC_ASSERT(ret->getRasterMode() == res->getRasterMode());
		res->syncLabelSetting(ret);
		ret->setString(str);
		return ret;
	}
	auto ret = res->createLabel();
	if (ret)
	{
		ret->setString(str);
		pool[res].pushBack(ret);
	}
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
	for (auto& entry : idle)
		for (auto* label : entry.second)
			label->setString("");
	idle = pool;
}

void LabelPool::clear()
{
	pool.clear();
	idle.clear();
}
