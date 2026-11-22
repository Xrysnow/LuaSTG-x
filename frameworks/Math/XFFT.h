#pragma once
#include <array>
#include <cmath>

namespace xmath
{
	namespace fft
	{
		enum class WindowType
		{
			Triangular,
			Bartlett,
			Parzen,
			GeneralCosine,
			GeneralHamming,
			GeneralGaussian,
			Hann,
			Hamming,
			Blackman,
			Nuttall,
			BlackmanHarris,
			Flattop,
			Gaussian,
			WindowTypeNum
		};

		void getTriangularWindow(size_t N, float* window);
		void getBartlettWindow(size_t N, float* window);
		void getParzenWindow(size_t N, float* window);

		/** Coefficients use the centered cosine phase [-pi, pi] (typically all positive). */
		void getGeneralCosineWindow(size_t N, float* window, size_t Nparam, float* param);
		void getGeneralHammingWindow(size_t N, float* window, float alpha);
		void getGeneralGaussianWindow(size_t N, float* window, float p, float sigma);

		void getHannWindow(size_t N, float* window);
		void getHammingWindow(size_t N, float* window);

		void getBlackmanWindow(size_t N, float* window);
		void getNuttallWindow(size_t N, float* window);
		void getBlackmanHarrisWindow(size_t N, float* window);
		void getFlattopWindow(size_t N, float* window);

		void getGaussianWindow(size_t N, float* window, float sigma);

		void getWindow(size_t N, float* window, WindowType type = WindowType::Hann,
			size_t Nparam = 0, float* param = nullptr);

		size_t getNeededWorksetSize(size_t N);
		/** in[N], outComplex[N*2] */
		void fft(size_t N, void* workset, float* in, float* outComplex);
		/** in[N], outComplex[N*2], outNorm[N/2]; outNorm[k] = abs(X[k])/N for k < N/2.
		 * Nyquist is excluded from outNorm and stored in outComplex[1]. */
		void fft(size_t N, void* workset, float* in, float* outComplex, float* outNorm);
	}
}
