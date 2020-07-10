#pragma once
#include "../LSTG/ResourceMgr.h"

class LabelPool
{
public:
	LabelPool();
	~LabelPool();

	cocos2d::Label* getWithResFont(lstg::ResFont* res);
	void restore();
	void clear();
private:

	std::unordered_map<std::string, cocos2d::Vector<cocos2d::Label*>> pool;
	std::unordered_map<std::string, cocos2d::Vector<cocos2d::Label*>> idle;
};
