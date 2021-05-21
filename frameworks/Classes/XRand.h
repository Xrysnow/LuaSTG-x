#pragma once
#include "cocos2d.h"
#include "../Math/XRandom.h"
#include "RandomWELL512.h"

namespace lstg
{
	class Random : public xmath::random::Random
	{
	public:
		enum class GeneratorType
		{
			well512,
			minstd_rand0, minstd_rand,
			mt19937, mt19937_64,
			ranlux24_base, ranlux48_base,
			ranlux24, ranlux48,
			knuth_b
		};

		static uint32_t getDeviceSeed();

		void setSeed(uint32_t seed) override;
		uint32_t getSeed() override;

		/** get random int32 in range [a, b] */
		int32_t randInt(int32_t a, int32_t b);
		/** get random float in range [a, b] */
		float randFloat(float a, float b);
		/** get random 1 or -1 */
		int32_t randSign();

		int64_t uniform_int(int64_t a, int64_t b);
		/** produces bool values on a Bernoulli distribution. */
		bool bernoulli(double p);
		/** produces integer values on a binomial distribution. */
		int32_t binomial(int32_t t, double p);
		/** produces integer values on a negative binomial distribution. */
		int32_t negative_binomial(int32_t k, double p);
		/** produces integer values on a geometric distribution. */
		int32_t geometric(double p);

		/** produces integer values on a poisson distribution. */
		int32_t poisson(double mean);
		/** produces real values on an extreme value distribution. */
		double extreme_value(double a, double b);

		/** produces real values on a chi-squared distribution. */
		double chi_squared(double n);
		/** produces real values on a Cauchy distribution. */
		double cauchy(double a, double b);
		/** produces real values on a Fisher's F-distribution. */
		double fisher_f(double m, double n);
		/** produces real values on a Student's t-distribution. */
		double student_t(double n);

		/** produces random integers on a discrete distribution. */
		int32_t discrete(const std::vector<double>& weights);
		/** produces real values distributed on constant subintervals. */
		double piecewise_constant(
			const std::vector<double>& sequence,
			const std::vector<double>& weights);
		/** produces real values distributed on defined subintervals. */
		double piecewise_linear(
			const std::vector<double>& sequence,
			const std::vector<double>& weights);

		Random(uint32_t seed = 0, GeneratorType type = GeneratorType::well512);
		Random(const Random &) = delete;
		Random &operator =(const Random &) = delete;

	protected:
		double _rand() override;

		union
		{
			RandomWELL512 well512;
			std::minstd_rand0 minstd_rand0;
			std::minstd_rand minstd_rand;
			std::mt19937 mt19937;
			std::mt19937_64 mt19937_64;
			std::ranlux24_base ranlux24_base;
			std::ranlux48_base ranlux48_base;
			std::ranlux24 ranlux24;
			std::ranlux48 ranlux48;
			std::knuth_b knuth_b;
		};
		GeneratorType _type;
		uint32_t _seed = 0;
		std::uniform_real_distribution<double> uniform_real;
		std::uniform_real_distribution<double> uniform_real1;

	};
}
