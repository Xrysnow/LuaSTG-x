#include "MemPoolManager.h"
#include "Utility.h"

using namespace std;
using namespace lstg;
using namespace cocos2d;
using namespace backend;

MemPoolManager* MemPoolManager::getInstance()
{
	static MemPoolManager ins;
	return &ins;
}

Mat4* MemPoolManager::getMat4(float x, float y, float z,
	float rot, float hscale, float vscale, const Vec2& anchorPointInPoints)
{
	const auto _transform = getMat4();
	getNodeTransform(anchorPointInPoints, x, y, rot, hscale, vscale, z, _transform);
	return _transform;
}

void MemPoolManager::trim()
{
	xtcmdPool.trim();
	ccmdPool.trim();
	quadsPool.trim();
	matPool.trim();
	laserQuadsPool.trim();
	for (auto&it : statePool)
		it.second->trim();
	clearArrays();
}

void MemPoolManager::reset()
{
	xtcmdPool.reset();
	ccmdPool.reset();
	quadsPool.reset();
	matPool.reset();
	laserQuadsPool.reset();
	for (auto&it : statePool)
		it.second->reset();
	clearArrays();
}

void MemPoolManager::clear()
{
	xtcmdPool.clear();
	ccmdPool.clear();
	quadsPool.clear();
	matPool.clear();
	laserQuadsPool.clear();
	for (auto&it : statePool)
		it.second->clear();
	statePool.clear();
	clearArrays();
}

void MemPoolManager::clearArrays()
{
	arrays.clear();
}

std::shared_ptr<ProgramStatePool> MemPoolManager::getProgramStatePool(Program* program)
{
	const auto it = statePool.find(program);
	if (it != statePool.end())
		return it->second;
	if (!program)
		return nullptr;
	const auto p = std::make_shared<ProgramStatePool>(program);
	statePool[program] = p;
	return p;
}

void MemPoolManager::removeProgramStatePool(Program* program)
{
	//const auto it = statePool.find(program);
	//if (it != statePool.end())
	//	statePool.erase(it);
}

void ProgramStatePool::alloc_()
{
	auto p = std::make_shared<Vector<ProgramState*>>();
	for (size_t i = 0; i < ProgramStatePoolBlockSize; ++i)
	{
		const auto s = new ProgramState(_program);
		s->autorelease();
		p->pushBack(s);
	}
	blocks.emplace_back(p);
}

ProgramState* ProgramStatePool::get()
{
	check_size();
	assert(blocks[idx_b]->size() > idx_a);
	return blocks[idx_b]->at(idx_a++);
}

ProgramStatePool::ProgramStatePool(Program* program)
{
	_program = program;
	CC_SAFE_RETAIN(_program);
	on_alloc = [this] { alloc_(); };
	clear();
}

ProgramStatePool::~ProgramStatePool()
{
	CC_SAFE_RELEASE(_program);
}
