#pragma once
#include "../LSTG/ResourceMgr.h"

class LabelPool
{
public:
	LabelPool();
	~LabelPool();

	cc::Label* getWithResFont(lstg::ResFont* res, const std::string& str);
	void onResFontRemove(lstg::ResFont* res);
	void restore();
	void clear();
private:

	std::unordered_map<void*, cc::Vector<cc::Label*>> pool;
	std::unordered_map<void*, cc::Vector<cc::Label*>> idle;
};
