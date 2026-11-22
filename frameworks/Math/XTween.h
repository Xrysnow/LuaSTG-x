#pragma once
#include <cstdint>
#include <cstdlib>

namespace xmath
{
	namespace tween
	{
		float linear(float t);
		float quadIn(float t);
		float quadOut(float t);
		float quadInOut(float t);
		float cubicIn(float t);
		float cubicOut(float t);
		float cubicInOut(float t);
		float powIn(float t, float p = 1);
		float powOut(float t, float p = 1);
		float powInOut(float t, float p = 1);
		float sineIn(float t);
		float sineOut(float t);
		float sineInOut(float t);
		float expoIn(float t, float b = 2);
		float expoOut(float t, float b = 2);
		float expoInOut(float t, float b = 2);
		float circIn(float t);
		float circOut(float t);
		float circInOut(float t);
		float elasticIn(float t, float a = 1, float p = 0.3);
		float elasticOut(float t, float a = 1, float p = 0.3);
		float elasticInOut(float t, float a = 1, float p = 0.45);
		float backIn(float t, float s = 1.70158);
		float backOut(float t, float s = 1.70158);
		float backInOut(float t, float s = 1.70158 * 1.525);
		float bounceIn(float t);
		float bounceOut(float t);
		float bounceInOut(float t);

		void linear(float v0, float v1, size_t n, float* out);
		void quadIn(float v0, float v1, size_t n, float* out);
		void quadOut(float v0, float v1, size_t n, float* out);
		void quadInOut(float v0, float v1, size_t n, float* out);
		void cubicIn(float v0, float v1, size_t n, float* out);
		void cubicOut(float v0, float v1, size_t n, float* out);
		void cubicInOut(float v0, float v1, size_t n, float* out);
		void powIn(float v0, float v1, size_t n, float* out, float p = 1);
		void powOut(float v0, float v1, size_t n, float* out, float p = 1);
		void powInOut(float v0, float v1, size_t n, float* out, float p = 1);
		void sineIn(float v0, float v1, size_t n, float* out);
		void sineOut(float v0, float v1, size_t n, float* out);
		void sineInOut(float v0, float v1, size_t n, float* out);
		void expoIn(float v0, float v1, size_t n, float* out, float b = 2);
		void expoOut(float v0, float v1, size_t n, float* out, float b = 2);
		void expoInOut(float v0, float v1, size_t n, float* out, float b = 2);
		void circIn(float v0, float v1, size_t n, float* out);
		void circOut(float v0, float v1, size_t n, float* out);
		void circInOut(float v0, float v1, size_t n, float* out);
		void elasticIn(float v0, float v1, size_t n, float* out, float a = 1, float p = 0.3);
		void elasticOut(float v0, float v1, size_t n, float* out, float a = 1, float p = 0.3);
		void elasticInOut(float v0, float v1, size_t n, float* out, float a = 1, float p = 0.45);
		void backIn(float v0, float v1, size_t n, float* out, float s = 1.70158);
		void backOut(float v0, float v1, size_t n, float* out, float s = 1.70158);
		void backInOut(float v0, float v1, size_t n, float* out, float s = 1.70158 * 1.525);
		void bounceIn(float v0, float v1, size_t n, float* out);
		void bounceOut(float v0, float v1, size_t n, float* out);
		void bounceInOut(float v0, float v1, size_t n, float* out);
	}
}
