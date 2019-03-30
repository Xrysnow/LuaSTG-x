#include "MemPoolManager.h"
#include "Utility.h"

using namespace std;
using namespace cocos2d;


MemPoolManager* MemPoolManager::getInstance()
{
	static MemPoolManager ins;
	return &ins;
}

Mat4* MemPoolManager::getMat4(float x, float y, float z,
	float rot, float hscale, float vscale, const Vec2& anchorPointInPoints)
{
	const auto _transform = getMat4();
	lstg::getNodeTransform(anchorPointInPoints, x, y, rot, hscale, vscale, z, _transform);
	return _transform;
}

void MemPoolManager::trim()
{
	xtcmdPool.trim();
	ccmdPool.trim();
	quadsPool.trim();
	matPool.trim();
	laserQuadsPool.trim();
	clearArrays();
}

void MemPoolManager::reset()
{
	xtcmdPool.reset();
	ccmdPool.reset();
	quadsPool.reset();
	matPool.reset();
	laserQuadsPool.reset();
	clearArrays();
}

void MemPoolManager::clear()
{
	xtcmdPool.clear();
	ccmdPool.clear();
	quadsPool.clear();
	matPool.clear();
	laserQuadsPool.clear();
	clearArrays();
}

void MemPoolManager::clearArrays()
{
	arrays.clear();
}
