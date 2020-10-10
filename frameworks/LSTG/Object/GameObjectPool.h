#pragma once
#include "cocos2d.h"
#include "GameObject.h"

namespace lstg
{
	struct GameObject;

	class GameObjectPool
	{
	public:
		GameObjectPool(size_t capacity);
		~GameObjectPool();
	private:
		size_t _capacity;
		size_t _size;
		GameObject* _obj;
		GameObject** obj;
	public:
		cocos2d::Vec2* anchor;
		float* hscale;
		float* vscale;
		float* x;
		float* y;
		float* vx;
		float* vy;
		float* ax;
		float* ay;
		float* rot;
		float* omega;
		float* lastx;
		float* lasty;
		float* dx;
		float* dy;
		bool* navi;

		void copyAttr(size_t src, size_t dst);

		GameObject* alloc();
		void free(GameObject* p);
		GameObject* at(size_t id) const;
		GameObject* atLua(size_t luaID) const;
		size_t size() const { return _size; }
		size_t capacity() const { return _capacity; }
		void clear();

		void update();
		void update(size_t begin, size_t end);

		cocos2d::Vec2 getPosition(size_t id) const;
		void getTransformMat(size_t id, cocos2d::Mat4* mat);
		void getTransformMat(size_t id, float factor, float z, cocos2d::Mat4* mat);

		void boundCheck(float l, float r, float b, float t, bool* out);
		void boundCheck(size_t begin, size_t end, float l, float r, float b, float t, bool* out) const;

		bool boxCheck(size_t id, float l, float r, float b, float t) const;

		static void test();
		static void test(int N, int M);
	};
}
