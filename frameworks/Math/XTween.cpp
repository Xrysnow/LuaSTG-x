#include "XTween.h"
#include "XConstant.h"
#include <cmath>
#include <limits>

using namespace xmath;

float tween::linear(float t)
{
	return t;
}

float tween::quadIn(float t)
{
	return t * t;
}

float tween::quadOut(float t)
{
	return -t * (t - 2);
}

float tween::quadInOut(float t)
{
	t *= 2;
	if (t < 1)
		return t * t / 2;
	t -= 1;
	return -(t * (t - 2) - 1) / 2;
}

float tween::cubicIn(float t)
{
	return t * t * t;
}

float tween::cubicOut(float t)
{
	t -= 1;
	return t * t * t + 1;
}

float tween::cubicInOut(float t)
{
	t *= 2;
	if (t < 1)
		return t * t * t / 2;
	t -= 2;
	return (t * t * t + 2) / 2;
}

float tween::powIn(float t, float p)
{
	p = std::abs(p);
	return std::pow(t, p);
}

float tween::powOut(float t, float p)
{
	p = std::abs(p);
	t = 1 - t;
	return 1 - std::pow(t, p);
}

float tween::powInOut(float t, float p)
{
	p = std::abs(p);
	t *= 2;
	if (t < 1)
		return std::pow(t, p) / 2;
	t = 2 - t;
	return 1 - std::pow(t, p) / 2;
}

float tween::sineIn(float t)
{
	return 1 - std::cos((float)pi_2 * t);
}

float tween::sineOut(float t)
{
	return std::sin((float)pi_2 * t);
}

float tween::sineInOut(float t)
{
	return (1 - std::cos((float)pi * t)) / 2;
}

float tween::expoIn(float t, float b)
{
	if (!(b > 0) || !std::isfinite(b))
		return std::numeric_limits<float>::quiet_NaN();
	if (b == 1 || t == 0 || t == 1)
		return t;
	const double base = b;
	return static_cast<float>(std::expm1(double(t) * std::log(base)) / (base - 1));
}

float tween::expoOut(float t, float b)
{
	if (!(b > 0) || !std::isfinite(b))
		return std::numeric_limits<float>::quiet_NaN();
	if (b == 1 || t == 0 || t == 1)
		return t;
	const double base = b;
	return static_cast<float>(-base * std::expm1(-double(t) * std::log(base)) / (base - 1));
}

float tween::expoInOut(float t, float b)
{
	t *= 2;
	if (t < 1)
		return tween::expoIn(t, b) / 2;
	t = 2 - t;
	return 1 - tween::expoIn(t, b) / 2;
}

float tween::circIn(float t)
{
	return 1 - std::sqrt(1 - t * t);
}

float tween::circOut(float t)
{
	t = 1 - t;
	return std::sqrt(1 - t * t);
}

float tween::circInOut(float t)
{
	t *= 2;
	if (t < 1)
		return tween::circIn(t) / 2;
	t = 2 - t;
	return 1 - tween::circIn(t) / 2;
}

float tween::elasticIn(float t, float a, float p)
{
	if (t == 0)
		return 0;
	float s;
	if (a < 1)
	{
		a = 1;
		s = p / 4;
	}
	else
	{
		s = p / (float)pix2 * std::asin(1 / a);
	}
	t = t - 1;
	return -(a * (float)std::pow(2, 10 * t) * std::sin((t - s) * (float)pix2 / p));
}

float tween::elasticOut(float t, float a, float p)
{
	if (t == 0)
		return 0;
	if (t == 1)
		return 1;
	return 1 - tween::elasticIn(1 - t, a, p);
}

float tween::elasticInOut(float t, float a, float p)
{
	t *= 2;
	if (t < 1)
		return tween::elasticIn(t, a, p) / 2;
	t = 2 - t;
	return 1 - tween::elasticIn(t, a, p) / 2;
}

float tween::backIn(float t, float s)
{
	return t * t * (t * (s + 1) - s);
}

float tween::backOut(float t, float s)
{
	return 1 - tween::backIn(1 - t, s);
}

float tween::backInOut(float t, float s)
{
	t *= 2;
	if (t < 1)
		return tween::backIn(t, s) / 2;
	t = 2 - t;
	return 1 - tween::backIn(t, s) / 2;
}

float tween::bounceIn(float t)
{
	return 1 - tween::bounceOut(1 - t);
}

float tween::bounceOut(float t)
{
	if (t < 1.0 / 2.75)
		return t * t * 7.5625f;
	if (t < 2.0 / 2.75)
	{
		t = t - 1.5f / 2.75f;
		return t * t * 7.5625f + 0.75f;
	}
	if (t < 2.5 / 2.75)
	{
		t = t - 2.25f / 2.75f;
		return t * t * 7.5625f + 0.9375f;
	}
	t = t - 2.625f / 2.75f;
	return t * t * 7.5625f + 0.984375f;
}

float tween::bounceInOut(float t)
{
	t *= 2;
	if (t < 1)
		return tween::bounceIn(t) / 2;
	t = 2 - t;
	return 1 - tween::bounceIn(t) / 2;
}

#define TWEEN(F, ...)\
	if(!out || n < 2) return;\
	const auto d = v1 - v0;\
	const auto m = n - 1;\
	for (size_t i = 0; i < n; ++i) {\
		out[i] = F((float)i / m, ##__VA_ARGS__) * d + v0;\
	}

void tween::linear(float v0, float v1, size_t n, float* out) {
	TWEEN(linear);
}
void tween::quadIn(float v0, float v1, size_t n, float* out) {
	TWEEN(quadIn);
}
void tween::quadOut(float v0, float v1, size_t n, float* out) {
	TWEEN(quadOut);
}
void tween::quadInOut(float v0, float v1, size_t n, float* out) {
	TWEEN(quadInOut);
}
void tween::cubicIn(float v0, float v1, size_t n, float* out) {
	TWEEN(cubicIn);
}
void tween::cubicOut(float v0, float v1, size_t n, float* out) {
	TWEEN(cubicOut);
}
void tween::cubicInOut(float v0, float v1, size_t n, float* out) {
	TWEEN(cubicInOut);
}
void tween::powIn(float v0, float v1, size_t n, float* out, float p) {
	TWEEN(powIn, p);
}
void tween::powOut(float v0, float v1, size_t n, float* out, float p) {
	TWEEN(powOut, p);
}
void tween::powInOut(float v0, float v1, size_t n, float* out, float p) {
	TWEEN(powInOut, p);
}
void tween::sineIn(float v0, float v1, size_t n, float* out) {
	TWEEN(sineIn);
}
void tween::sineOut(float v0, float v1, size_t n, float* out) {
	TWEEN(sineOut);
}
void tween::sineInOut(float v0, float v1, size_t n, float* out) {
	TWEEN(sineInOut);
}
void tween::expoIn(float v0, float v1, size_t n, float* out, float b) {
	TWEEN(expoIn, b);
}
void tween::expoOut(float v0, float v1, size_t n, float* out, float b) {
	TWEEN(expoOut, b);
}
void tween::expoInOut(float v0, float v1, size_t n, float* out, float b) {
	TWEEN(expoInOut, b);
}
void tween::circIn(float v0, float v1, size_t n, float* out) {
	TWEEN(circIn);
}
void tween::circOut(float v0, float v1, size_t n, float* out) {
	TWEEN(circOut);
}
void tween::circInOut(float v0, float v1, size_t n, float* out) {
	TWEEN(circInOut);
}
void tween::elasticIn(float v0, float v1, size_t n, float* out, float a, float p) {
	TWEEN(elasticIn, a, p);
}
void tween::elasticOut(float v0, float v1, size_t n, float* out, float a, float p) {
	TWEEN(elasticOut, a, p);
}
void tween::elasticInOut(float v0, float v1, size_t n, float* out, float a, float p) {
	TWEEN(elasticInOut, a, p);
}
void tween::backIn(float v0, float v1, size_t n, float* out, float s) {
	TWEEN(backIn, s);
}
void tween::backOut(float v0, float v1, size_t n, float* out, float s) {
	TWEEN(backOut, s);
}
void tween::backInOut(float v0, float v1, size_t n, float* out, float s) {
	TWEEN(backInOut, s);
}
void tween::bounceIn(float v0, float v1, size_t n, float* out) {
	TWEEN(bounceIn);
}
void tween::bounceOut(float v0, float v1, size_t n, float* out) {
	TWEEN(bounceOut);
}
void tween::bounceInOut(float v0, float v1, size_t n, float* out) {
	TWEEN(bounceInOut);
}
