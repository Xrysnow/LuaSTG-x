#include "XFFT.h"
#include "meow_fft.h"
#include "XConstant.h"

#define CHECK_N if (N == 0)return; else if (N == 1) { window[0] = 1.f; return; }

constexpr float HammingParam = 25.0 / 46;
static float BlackmanParam[] = { 0.42, 0.50, 0.08 };
static float NuttallParam[] = { 0.3635819, 0.4891775, 0.1365995, 0.0106411 };
static float BlackmanHarrisParam[] = { 0.35875, 0.48829, 0.14128, 0.01168 };
static float FlattopParam[] = { 0.21557895, 0.41663158, 0.277263158, 0.083578947, 0.006947368 };

void xmath::fft::getTriangularWindow(size_t N, float* window)
{
	CHECK_N;
	size_t i = 0;
	for (; i <= (N - 1) / 2; ++i)
		window[i] = float(2 * i + 1) / N;
	for (; i < N; ++i)
		window[i] = 2 - float(2 * i + 1) / N;
}

void xmath::fft::getBartlettWindow(size_t N, float* window)
{
	CHECK_N;
	size_t i = 0;
	const auto N1 = N - 1;
	for (; i <= (N - 1) / 2; ++i)
		window[i] = float(2 * i) / N1;
	for (; i < N; ++i)
		window[i] = 2 - float(2 * i) / N1;
}

void xmath::fft::getParzenWindow(size_t N, float* window)
{
	CHECK_N;
	const auto halfN = float(N) / 2;
	const auto p = float(N - 1) / N / 2;
	for (size_t i = 0; i < N; ++i)
	{
		const auto n = i - float(N - 1) / 2;
		const auto t = std::abs(n) / halfN;
		if (t <= p)
			window[i] = 1 - 6 * t*t*(1 - t);
		else
			window[i] = 2 * (1 - t)*(1 - t)*(1 - t);
	}
}

void xmath::fft::getGeneralCosineWindow(size_t N, float* window, size_t Nparam, float* param)
{
	CHECK_N;
	const auto N1 = N - 1;
	for (size_t i = 0; i < N; ++i)
	{
		window[i] = param[0];
		for (size_t j = 1; j < Nparam; ++j)
			window[i] += param[j] * std::cos((float(pix2)*i / N1 - float(pi))*j);
	}
}

void xmath::fft::getGeneralHammingWindow(size_t N, float* window, float alpha)
{
	CHECK_N;
	const auto N1 = N - 1;
	for (size_t i = 0; i < N; ++i)
		window[i] = alpha - (1 - alpha)*std::cos(float(pix2)*i / N1);
}

void xmath::fft::getGeneralGaussianWindow(size_t N, float* window, float p, float sigma)
{
	CHECK_N;
	const auto mid = float(N - 1) / 2;
	for (size_t i = 0; i < N; ++i)
		window[i] = std::exp(-0.5f * std::pow(std::abs((i - mid) / sigma), p * 2));
}

void xmath::fft::getHannWindow(size_t N, float* window)
{
	getGeneralHammingWindow(N, window, 0.5f);
}

void xmath::fft::getHammingWindow(size_t N, float* window)
{
	getGeneralHammingWindow(N, window, HammingParam);
}

void xmath::fft::getBlackmanWindow(size_t N, float* window)
{
	getGeneralCosineWindow(N, window, 3, BlackmanParam);
}

void xmath::fft::getNuttallWindow(size_t N, float* window)
{
	getGeneralCosineWindow(N, window, 4, NuttallParam);
}

void xmath::fft::getBlackmanHarrisWindow(size_t N, float* window)
{
	getGeneralCosineWindow(N, window, 4, BlackmanHarrisParam);
}

void xmath::fft::getFlattopWindow(size_t N, float* window)
{
	getGeneralCosineWindow(N, window, 5, FlattopParam);
}

void xmath::fft::getGaussianWindow(size_t N, float* window, float sigma)
{
	getGeneralGaussianWindow(N, window, 1.f, sigma);
}

void xmath::fft::getWindow(size_t N, float* window, WindowType type, size_t Nparam, float* param)
{
	switch (type) {
	case WindowType::Triangular: getTriangularWindow(N, window); break;
	case WindowType::Bartlett: getBartlettWindow(N, window); break;
	case WindowType::Parzen: getParzenWindow(N, window); break;
	case WindowType::GeneralCosine: getGeneralCosineWindow(N, window, Nparam, param); break;
	case WindowType::GeneralHamming: if(param&&Nparam == 1)getGeneralHammingWindow(N, window, param[0]); break;
	case WindowType::GeneralGaussian: if (param&&Nparam == 2)getGeneralGaussianWindow(N, window, param[0], param[1]); break;
	case WindowType::Hann: getHannWindow(N, window); break;
	case WindowType::Hamming: getHammingWindow(N, window); break;
	case WindowType::Blackman: getBlackmanWindow(N, window); break;
	case WindowType::Nuttall: getNuttallWindow(N, window); break;
	case WindowType::BlackmanHarris: getBlackmanHarrisWindow(N, window); break;
	case WindowType::Flattop: getFlattopWindow(N, window); break;
	case WindowType::Gaussian: if (param&&Nparam == 1)getGaussianWindow(N, window, param[0]); break;
	default: ;
	}
}

size_t xmath::fft::getNeededWorksetSize(size_t N)
{
	return meow_fft_generate_workset_real(N, nullptr);
}

void xmath::fft::fft(size_t N, void* workset, float* in, float* outComplex)
{
	meow_fft_generate_workset_real(N, (Meow_FFT_Workset_Real*)workset);
	meow_fft_real((Meow_FFT_Workset_Real*)workset, in, (Meow_FFT_Complex*)outComplex);
}

void xmath::fft::fft(size_t N, void* workset, float* in, float* outComplex, float* outNorm)
{
	const auto out = (Meow_FFT_Complex*)outComplex;
	meow_fft_generate_workset_real(N, (Meow_FFT_Workset_Real*)workset);
	meow_fft_real((Meow_FFT_Workset_Real*)workset, in, out);
	if (outNorm)
	{
		const int halfN = N / 2;
		outNorm[0] = std::abs(out[0].r) / N;
		for (auto i = 1; i < halfN; ++i)
		{
			const float r = out[i].r;
			const float j = out[i].j;
			outNorm[i] = sqrt(r * r + j * j) / N;
		}
	}
}
