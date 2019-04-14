#include "CollisionDetect.h"
#include "Global.h"

using namespace std;
using namespace lstg;
using namespace cocos2d;

struct _BezierNode
{
	Vec2 pos;
	Vec2 pin;
	Vec2 pout;
};
_BezierNode g_NodeCache[256];
int lstg::SampleBezierA1(int count, float length, float rate,
	const std::vector<Vec2>& in_pos, vector<Vec2>& out_pos, vector<float>& out_rot) noexcept
{
	if (count < 2)
		return 0;
	// allocate
	_BezierNode *cache = count > 256 ? new _BezierNode[count] : g_NodeCache;
	// fill
	int i;
	for (i = 0; i < count; i++) {
		cache[i].pos = in_pos[i];
	}
	// calc connection dir
	for (i = 1; i < count; i++) {
		cache[i].pin = cache[i].pos - cache[i - 1].pos;
		cache[i - 1].pout = cache[i].pin;
	}
	cache[0].pin = cache[0].pout;
	cache[count - 1].pout = cache[count - 1].pin;
	// calc local dir
	Vec2 dir;
	for (i = 0; i < count; i++) {
		dir = cache[i].pin + cache[i].pout;
		dir = dir.getNormalized()*rate;
		cache[i].pin = dir * (-cache[i].pin.length()) + cache[i].pos;
		cache[i].pout = dir * (cache[i].pout.length()) + cache[i].pos;
	}
	float left = 0;
	int flag;
	int newcount = 0;

	for (i = 0; i < count - 1; i++) {
		const auto A = cache[i].pos;
		const auto B = cache[i].pout;
		const auto C = cache[i + 1].pin;
		const auto D = cache[i + 1].pos;

		const auto R2 = (D - A + B * 3 - C * 3) * 3;
		const auto R1 = (A - B * 2 + C) * 6;
		const auto R0 = (B - A) * 3;

		float t = 0.f;

		do
		{
			flag = 0;
			dir = R2 * t*t + R1 * t + R0;
			const float speed = dir.length();
			float dt = speed ? left / speed : 0.2;
			if (dt > 0.2) {
				dt = 0.2;
				flag = 1;
			}
			if (dt + t > 1) {
				dt = 1 - t;
				flag = 2;
			}
			if (left <= 0) {
				float l = (1 - t);
				// calc pos
				const auto P = A * (l*l*l) + B * (3 * l*l*t) + C * (3 * l* t *t) + D * (t*t*t);
				const float angle = dir.getAngle()*LRAD2DEGREE;

				out_pos.push_back(P);
				out_rot.push_back(angle);
				newcount++;
				left = length;
				flag = 1;
			}
			// step
			float simulated_length = speed * dt;
			if (flag == 0 || left < simulated_length) {
				left = 0;
			}
			else {
				left = left - simulated_length;
			}
			t = t + dt;
		} while (flag != 2);
	}
	// release
	if (cache != g_NodeCache) {
		delete[] cache;
	}
	return newcount;
}
