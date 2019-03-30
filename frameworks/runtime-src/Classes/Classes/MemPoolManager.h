#pragma once
#include "cocos2d.h"
#include "ArrayObjectPool.hpp"
#include "XTrianglesCommand.h"
#include "GameObjectBentLaser.h"

#define LMP (*MemPoolManager::getInstance())

// note: pointer get from this class only avalible for one frame
class MemPoolManager
{
public:
	static MemPoolManager* getInstance();

	using LaserQuads = std::array<cocos2d::V3F_C4B_T2F_Quad, LGOBJ_MAXLASERNODE>;

	XTrianglesCommand* getXTrianglesCommand() { return xtcmdPool.get(); }
	cocos2d::CustomCommand* getCustomCommand() { return ccmdPool.get(); }
	cocos2d::V3F_C4B_T2F_Quad* getQuad() { return quadsPool.get(); }
	cocos2d::Mat4* getMat4() { return matPool.get(); }
	cocos2d::Mat4* getMat4(float x, float y, float z,
		float rot, float hscale, float vscale, const cocos2d::Vec2& anchorPointInPoints);
	LaserQuads* getLaserQuads() { return laserQuadsPool.get(); }

	void trim();
	void reset();
	void clear();

	template<typename T, size_t N>
	std::shared_ptr<std::array<T, N>> applyArray();
	void clearArrays();
private:
	ArrayObjectPool<XTrianglesCommand, 4096> xtcmdPool;
	ArrayObjectPool<cocos2d::CustomCommand, 4096> ccmdPool;
	ArrayObjectPool<cocos2d::V3F_C4B_T2F_Quad, 4096> quadsPool;
	ArrayObjectPool<cocos2d::Mat4, 4096> matPool;
	ArrayObjectPool<LaserQuads, 1> laserQuadsPool;

	std::vector<std::shared_ptr<void>> arrays;

	MemPoolManager() = default;
};

template <typename T, size_t N>
std::shared_ptr<std::array<T, N>> MemPoolManager::applyArray()
{
	auto ret = std::make_shared<std::array<T, N>>();
	arrays.push_back(ret);
	return ret;
}
