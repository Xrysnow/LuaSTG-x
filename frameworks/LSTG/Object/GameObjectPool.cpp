#include "GameObjectPool.h"
#include "Util/Utility.h"
#include "AppFrame.h"

using namespace std;
using namespace lstg;

#ifdef CC_PLATFORM_PC
#define MT_OPT
#endif // CC_PLATFORM_PC

void getTransform(const cocos2d::Vec2& anchorPointInPoints,
	float x, float y, float rot, float hscale, float vscale, float z, cocos2d::Mat4* _transform)
{
	float zz2_;
	float wz2;
	// assert that most rot are 0
	if (rot == 0.f)
	{
		zz2_ = 1.0f;
		wz2 = 0;
	}
	else
	{
		const float halfRadz = -(.5f * 0.01745329252f*rot);
		const float qz = std::sin(halfRadz);
		const float qw = std::cos(halfRadz);
		const float z2 = qz + qz;
		zz2_ = 1.0f - qz * z2;
		wz2 = qw * z2;
	}

	_transform->m[0] = zz2_ * hscale;
	_transform->m[1] = wz2 * hscale;
	_transform->m[2] = 0.0f;
	_transform->m[3] = 0.0f;

	_transform->m[4] = -wz2 * vscale;
	_transform->m[5] = zz2_ * vscale;
	_transform->m[6] = 0.0f;
	_transform->m[7] = 0.0f;

	_transform->m[8] = 0.0f;
	_transform->m[9] = 0.0f;
	_transform->m[10] = 1.0f;
	_transform->m[11] = 0.0f;

	_transform->m[12] = x - _transform->m[0] * anchorPointInPoints.x - _transform->m[4] * anchorPointInPoints.y;
	_transform->m[13] = y - _transform->m[1] * anchorPointInPoints.x - _transform->m[5] * anchorPointInPoints.y;
	_transform->m[14] = z;
	_transform->m[15] = 1.0f;
}

GameObjectPool::GameObjectPool(size_t capacity)
{
	_size = 0;
	_capacity = capacity;
	_obj = new GameObject[_capacity];
	obj = new GameObject*[_capacity];
	for (auto i = 0u; i < _capacity; ++i)
	{
		obj[i] = _obj + i;
		_obj[i].luaID = i;
	}
	anchor = new cocos2d::Vec2[_capacity];
	hscale = new float[_capacity];
	vscale = new float[_capacity];
	x = new float[_capacity];
	y = new float[_capacity];
	vx = new float[_capacity];
	vy = new float[_capacity];
	ax = new float[_capacity];
	ay = new float[_capacity];
	rot = new float[_capacity];
	omega = new float[_capacity];
	lastx = new float[_capacity];
	lasty = new float[_capacity];
	dx = new float[_capacity];
	dy = new float[_capacity];
	navi = new bool[_capacity];
}

GameObjectPool::~GameObjectPool()
{
	delete[] obj;
	delete[] anchor;
	delete[] hscale;
	delete[] vscale;
	delete[] x;
	delete[] y;
	delete[] vx;
	delete[] vy;
	delete[] ax;
	delete[] ay;
	delete[] rot;
	delete[] omega;
	delete[] lastx;
	delete[] lasty;
	delete[] dx;
	delete[] dy;
	delete[] navi;
}

void GameObjectPool::copyAttr(size_t src, size_t dst)
{
	anchor[dst] = anchor[src];
	hscale[dst] = hscale[src];
	vscale[dst] = vscale[src];
	x[dst] = x[src];
	y[dst] = y[src];
	vx[dst] = vx[src];
	vy[dst] = vy[src];
	ax[dst] = ax[src];
	ay[dst] = ay[src];
	rot[dst] = rot[src];
	omega[dst] = omega[src];
	lastx[dst] = lastx[src];
	lasty[dst] = lasty[src];
	dx[dst] = dx[src];
	dy[dst] = dy[src];
	navi[dst] = navi[src];
}

GameObject* GameObjectPool::alloc()
{
	if (_size == _capacity)
		return nullptr;
	anchor[_size] = cocos2d::Vec2::ANCHOR_MIDDLE;
	hscale[_size] = 1.f;
	vscale[_size] = 1.f;
	x[_size] = 0.f;
	y[_size] = 0.f;
	vx[_size] = 0.f;
	vy[_size] = 0.f;
	ax[_size] = 0.f;
	ay[_size] = 0.f;
	rot[_size] = 0.f;
	omega[_size] = 0.f;
	lastx[_size] = 0.f;
	lasty[_size] = 0.f;
	dx[_size] = 0.f;
	dy[_size] = 0.f;
	navi[_size] = false;
	const auto ret = obj[_size];
	ret->id = _size;
	++_size;
	return ret;
}

void GameObjectPool::free(GameObject* p)
{
	const auto id = p->id;
	const auto tail = _size - 1;
	if (id != tail)
	{
		copyAttr(_size - 1, id);
		std::swap(obj[tail]->id, obj[id]->id);
		//std::swap(obj[tail]->cm->id, obj[id]->cm->id);
		obj[id] = obj[tail];
		obj[tail] = p;
	}
	--_size;
}

GameObject* GameObjectPool::at(size_t id) const
{
	if (id >= _size)
		return nullptr;
	return obj[id];
}

GameObject* GameObjectPool::atLua(size_t luaID) const
{
	if (luaID >= _capacity)
		return nullptr;
	return _obj + luaID;
}

void GameObjectPool::clear()
{
	_size = 0;
	for (auto i = 0u; i < _capacity; ++i)
		obj[i] = _obj + i;
}

void GameObjectPool::update()
{
	if (LTHP.empty())
	{
		update(0, _size);
	}
	else
	{
		deployThreadTaskAndWait(_size, LTHP.size() + 1,
			[=](int start, int end, int)
		{
			update(start, end);
		});
	}
}

void GameObjectPool::update(size_t begin, size_t end)
{
	for (auto i = begin; i < end; ++i)
		vx[i] += ax[i];
	for (auto i = begin; i < end; ++i)
		vy[i] += ay[i];
	for (auto i = begin; i < end; ++i)
		x[i] += vx[i];
	for (auto i = begin; i < end; ++i)
		y[i] += vy[i];
	for (auto i = begin; i < end; ++i)
		rot[i] += omega[i];
	for (auto i = begin; i < end; ++i)
		dx[i] = x[i] - lastx[i];
	for (auto i = begin; i < end; ++i)
		dy[i] = y[i] - lasty[i];
	for (auto i = begin; i < end; ++i)
		lastx[i] = x[i];
	for (auto i = begin; i < end; ++i)
		lasty[i] = y[i];
	for (auto i = begin; i < end; ++i)
		if (navi[i] && (dx[i] != 0 || dy[i] != 0))
			rot[i] = atan2(dy[i], dx[i]);
}

cocos2d::Vec2 GameObjectPool::getPosition(size_t id) const
{
	return { x[id],y[id] };
}

void GameObjectPool::getTransformMat(size_t id, cocos2d::Mat4* mat)
{
	getTransform(anchor[id], x[id], y[id], -rot[id] * LRAD2DEGREE,
		hscale[id], vscale[id], 0.f, mat);
}

void GameObjectPool::getTransformMat(size_t id, float factor, float z, cocos2d::Mat4* mat)
{
	getTransform(anchor[id], x[id], y[id], -rot[id] * LRAD2DEGREE,
		hscale[id] * factor, vscale[id] * factor, z, mat);
}

void GameObjectPool::boundCheck(float l, float r, float b, float t, bool* out)
{
	if (LTHP.empty())
	{
		deployThreadTaskAndWait(size(), LTHP.size() + 1,
			[=](int start, int end, int)
		{
			boundCheck(start, end, l, r, b, t, out + start);
		});
	}
	else
	{
		boundCheck(0, _size, l, r, b, t, out);
	}
}

void GameObjectPool::boundCheck(size_t begin, size_t end, float l, float r, float b, float t, bool* out) const
{
	for (auto i = begin; i < end; ++i)
	{
		out[i - begin] = obj[i]->bound && !(x[i] > l&&x[i]<r&&y[i]>b&&y[i] < t);
	}
}

bool GameObjectPool::boxCheck(size_t id, float l, float r, float b, float t) const
{
	return x[id] > l && x[id] < r && y[id] > b && y[id] < t;
}

void GameObjectPool::test()
{
	const int N = 1000;
	const int M = 3e4;
	const float l = -1;
	const float r = 1;
	const float b = -1;
	const float t = 1;
	auto cmp = new ComponentManager[M];
	for (int i = 0; i < M; ++i)
	{
		auto p = alloc();
		p->bound = false;
		p->cm = cmp + i;
		p->cm->pool = this;
		p->cm->getOrCreateTrasform2D();
	}
	auto ret = new bool[M];
	memset(ret, 0, M * sizeof(bool));
	StopWatch sw;
	sw.reset();

	for (int j = 0; j < N; ++j)
	{
		//memset(ret, 0, M * sizeof(bool));
		for (int i = 0; i < M; ++i)
		{
			ret[i] = obj[i]->bound && !(x[i] > l&&x[i]<r&&y[i]>b&&y[i] < t);
		}
	}
	auto t1 = sw.get();
	sw.reset();

	for (int j = 0; j < N; ++j)
	{
		boundCheck(l, r, b, t, ret);
	}
	auto t2 = sw.get();
	sw.reset();

	auto t3 = sw.get();
	sw.reset();

	cocos2d::log("-----\n  %f, %f, %f", t1, t2, t3);
}
