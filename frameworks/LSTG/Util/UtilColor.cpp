#include "UtilColor.h"

using namespace std;
using namespace cocos2d;
#define CLAMP(v) std::min(std::max(0, (int32_t)(v)), 0xff)
#define CLAMP_UP(v) std::min((int32_t)(v), 0xff)
#define CLAMP_DOWN(v) std::max(0, (int32_t)(v))

Color4B& operator+=(Color4B& lhs, const Color4B& rhs) {
	lhs.r = CLAMP_UP(lhs.r + rhs.r);
	lhs.g = CLAMP_UP(lhs.g + rhs.g);
	lhs.b = CLAMP_UP(lhs.b + rhs.b);
	lhs.a = CLAMP_UP(lhs.a + rhs.a);
	return lhs;
}
Color4B operator+(Color4B lhs, const Color4B& rhs) {
	return lhs += rhs;
}
Color4B& operator+=(Color4B& lhs, uint8_t rhs)
{
	lhs.r = CLAMP_UP(lhs.r + rhs);
	lhs.g = CLAMP_UP(lhs.g + rhs);
	lhs.b = CLAMP_UP(lhs.b + rhs);
	lhs.a = CLAMP_UP(lhs.a + rhs);
	return lhs;
}
Color4B operator+(Color4B lhs, uint8_t rhs)
{
	return lhs += rhs;
}

Color4B& operator-=(Color4B& lhs, const Color4B& rhs) {
	lhs.r = CLAMP_DOWN(lhs.r - rhs.r);
	lhs.g = CLAMP_DOWN(lhs.g - rhs.g);
	lhs.b = CLAMP_DOWN(lhs.b - rhs.b);
	lhs.a = CLAMP_DOWN(lhs.a - rhs.a);
	return lhs;
}
Color4B operator-(Color4B lhs, const Color4B& rhs) {
	return lhs -= rhs;
}
Color4B& operator-=(Color4B& lhs, uint8_t rhs)
{
	lhs.r = CLAMP_DOWN(lhs.r - rhs);
	lhs.g = CLAMP_DOWN(lhs.g - rhs);
	lhs.b = CLAMP_DOWN(lhs.b - rhs);
	lhs.a = CLAMP_DOWN(lhs.a - rhs);
	return lhs;
}
Color4B operator-(Color4B lhs, uint8_t rhs)
{
	return lhs -= rhs;
}

Color4B& operator*=(Color4B& lhs, const Color4B& rhs) {
	lhs.r = float(lhs.r) * rhs.r / 0xff;
	lhs.g = float(lhs.g) * rhs.g / 0xff;
	lhs.b = float(lhs.b) * rhs.b / 0xff;
	lhs.a = float(lhs.a) * rhs.a / 0xff;
	return lhs;
}
Color4B& operator*=(Color4B& lhs, float rhs) {
	lhs.r = CLAMP(float(lhs.r) * rhs);// / 0xff;
	lhs.g = CLAMP(float(lhs.g) * rhs);// / 0xff;
	lhs.b = CLAMP(float(lhs.b) * rhs);// / 0xff;
	lhs.a = CLAMP(float(lhs.a) * rhs);// / 0xff;
	return lhs;
}
Color4B operator*(Color4B lhs, const Color4B& rhs) {
	return lhs *= rhs;
}
Color4B operator*(Color4B lhs, float rhs) {
	return lhs *= rhs;
}

Color4B& operator/=(Color4B& lhs, const Color4B& rhs) {
	lhs.r = CLAMP_UP(float(lhs.r) / rhs.r * 0xff);
	lhs.g = CLAMP_UP(float(lhs.g) / rhs.g * 0xff);
	lhs.b = CLAMP_UP(float(lhs.b) / rhs.b * 0xff);
	lhs.a = CLAMP_UP(float(lhs.a) / rhs.a * 0xff);
	return lhs;
}
Color4B& operator/=(Color4B& lhs, float rhs) {
	lhs.r = CLAMP(lhs.r / rhs);// * 0xff;
	lhs.g = CLAMP(lhs.g / rhs);// * 0xff;
	lhs.b = CLAMP(lhs.b / rhs);// * 0xff;
	lhs.a = CLAMP(lhs.a / rhs);// * 0xff;
	return lhs;
}
Color4B operator/(Color4B lhs, const Color4B& rhs) {
	return lhs /= rhs;
}
Color4B operator/(Color4B lhs, float rhs) {
	return lhs /= rhs;
}
