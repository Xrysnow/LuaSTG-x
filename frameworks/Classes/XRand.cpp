#include "XRand.h"

#define SWITCH_TYPE(T, DIST)\
	switch (T) {\
	case GeneratorType::well512: return DIST(well512);\
	case GeneratorType::minstd_rand0: return DIST(minstd_rand0);\
	case GeneratorType::minstd_rand: return DIST(minstd_rand);\
	case GeneratorType::mt19937: return DIST(mt19937);\
	case GeneratorType::mt19937_64: return DIST(mt19937_64);\
	case GeneratorType::ranlux24_base: return DIST(ranlux24_base);\
	case GeneratorType::ranlux48_base: return DIST(ranlux48_base);\
	case GeneratorType::ranlux24: return DIST(ranlux24);\
	case GeneratorType::ranlux48: return DIST(ranlux48);\
	case GeneratorType::knuth_b: return DIST(knuth_b);\
	default:; }

using namespace lstg;

uint32_t Random::getDeviceSeed()
{
	static std::random_device device;
	return device();
}

void Random::setSeed(uint32_t seed)
{
	switch (_type)
	{
	case GeneratorType::well512: well512.seed(seed); break;
	case GeneratorType::minstd_rand0: minstd_rand0.seed(seed); break;
	case GeneratorType::minstd_rand: minstd_rand.seed(seed); break;
	case GeneratorType::mt19937: mt19937.seed(seed); break;
	case GeneratorType::mt19937_64: mt19937_64.seed(seed); break;
	case GeneratorType::ranlux24_base: ranlux24_base.seed(seed); break;
	case GeneratorType::ranlux48_base: ranlux48_base.seed(seed); break;
	case GeneratorType::ranlux24: ranlux24.seed(seed); break;
	case GeneratorType::ranlux48: ranlux48.seed(seed); break;
	case GeneratorType::knuth_b: knuth_b.seed(seed); break;
	default:;
	}
	_seed = seed;
}

uint32_t Random::getSeed()
{
	return _seed;
}

int32_t Random::randInt(int32_t a, int32_t b)
{
	if (_type == GeneratorType::well512)
		return a + int32_t(well512.getRandUInt(uint32_t(b - a)));
	if (a > b)
		std::swap(a, b);
	std::uniform_int_distribution<int32_t> uniform_int(a, b);
	SWITCH_TYPE(_type, uniform_int);
	return 0;
}

float Random::randFloat(float a, float b)
{
	double v = 0;
	switch (_type)
	{
	case GeneratorType::well512: return well512.getRandFloat(a, b);
	case GeneratorType::minstd_rand0: v = uniform_real1(minstd_rand0); break;
	case GeneratorType::minstd_rand: v = uniform_real1(minstd_rand); break;
	case GeneratorType::mt19937: v = uniform_real1(mt19937); break;
	case GeneratorType::mt19937_64: v = uniform_real1(mt19937_64); break;
	case GeneratorType::ranlux24_base: v = uniform_real1(ranlux24_base); break;
	case GeneratorType::ranlux48_base: v = uniform_real1(ranlux48_base); break;
	case GeneratorType::ranlux24: v = uniform_real1(ranlux24); break;
	case GeneratorType::ranlux48: v = uniform_real1(ranlux48); break;
	case GeneratorType::knuth_b: v = uniform_real1(knuth_b); break;
	default:;
	}
	return v * (b - a) + a;
}

int32_t Random::randSign()
{
	if (_type == GeneratorType::well512)
		return well512.getRandUInt(1) * 2 - 1;
	return randInt(0, 1) * 2 - 1;
}

int64_t Random::uniform_int(int64_t a, int64_t b)
{
	std::uniform_int_distribution<int64_t> dist(a, b);
	SWITCH_TYPE(_type, dist);
	return 0;
}

bool Random::bernoulli(double p)
{
	std::bernoulli_distribution dist(p);
	SWITCH_TYPE(_type, dist);
	return false;
}

int32_t Random::binomial(int32_t t, double p)
{
	std::binomial_distribution<int32_t> dist(t, p);
	SWITCH_TYPE(_type, dist);
	return 0;
}

int32_t Random::negative_binomial(int32_t k, double p)
{
	std::negative_binomial_distribution<int32_t> dist(k, p);
	SWITCH_TYPE(_type, dist);
	return 0;
}

int32_t Random::geometric(double p)
{
	std::geometric_distribution<int32_t> dist(p);
	SWITCH_TYPE(_type, dist);
	return 0;
}

int32_t Random::poisson(double mean)
{
	std::poisson_distribution<int32_t> dist(mean);
	SWITCH_TYPE(_type, dist);
	return 0;
}

double Random::extreme_value(double a, double b)
{
	std::extreme_value_distribution<double> dist(a, b);
	SWITCH_TYPE(_type, dist);
	return 0;
}

double Random::chi_squared(double n)
{
	std::chi_squared_distribution<double> dist(n);
	SWITCH_TYPE(_type, dist);
	return 0;
}

double Random::cauchy(double a, double b)
{
	std::cauchy_distribution<double> dist(a, b);
	SWITCH_TYPE(_type, dist);
	return 0;
}

double Random::fisher_f(double m, double n)
{
	std::fisher_f_distribution<double> dist(m, n);
	SWITCH_TYPE(_type, dist);
	return 0;
}

double Random::student_t(double n)
{
	std::student_t_distribution<double> dist(n);
	SWITCH_TYPE(_type, dist);
	return 0;
}

int32_t Random::discrete(const std::vector<double>& weights)
{
	std::discrete_distribution<int32_t> dist(weights.begin(), weights.end());
	SWITCH_TYPE(_type, dist);
	return 0;
}

double Random::piecewise_constant(const std::vector<double>& sequence, const std::vector<double>& weights)
{
	if (sequence.size() != weights.size() + 1)
		return 0;
	std::piecewise_constant_distribution<double> dist(sequence.begin(), sequence.end(), weights.begin());
	SWITCH_TYPE(_type, dist);
	return 0;
}

double Random::piecewise_linear(const std::vector<double>& sequence, const std::vector<double>& weights)
{
	if (sequence.size() != weights.size())
		return 0;
	std::piecewise_linear_distribution<double> dist(sequence.begin(), sequence.end(), weights.begin());
	SWITCH_TYPE(_type, dist);
	return 0;
}

Random::Random(uint32_t seed, GeneratorType type)
	: _type(type), uniform_real(0.0, 1.0), uniform_real1(0.0, std::nextafter(1.0, 2.0))
{
	switch (_type)
	{
	case GeneratorType::well512: well512 = {}; break;
	case GeneratorType::minstd_rand0: minstd_rand0 = std::minstd_rand0{0}; break;
	case GeneratorType::minstd_rand: minstd_rand = std::minstd_rand{0}; break;
	case GeneratorType::mt19937: mt19937 = std::mt19937{0}; break;
	case GeneratorType::mt19937_64: mt19937_64 = std::mt19937_64{0}; break;
	case GeneratorType::ranlux24_base: ranlux24_base = std::ranlux24_base{0}; break;
	case GeneratorType::ranlux48_base: ranlux48_base = std::ranlux48_base{0}; break;
	case GeneratorType::ranlux24: ranlux24 = std::ranlux24{0}; break;
	case GeneratorType::ranlux48: ranlux48 = std::ranlux48{0}; break;
	case GeneratorType::knuth_b: knuth_b = std::knuth_b{0}; break;
	default: ;
	}
	Random::setSeed(seed);
}

double Random::_rand()
{
	switch (_type)
	{
	case GeneratorType::well512: return uniform_real(well512);
	case GeneratorType::minstd_rand0: return uniform_real(minstd_rand0);
	case GeneratorType::minstd_rand: return uniform_real(minstd_rand);
	case GeneratorType::mt19937: return uniform_real(mt19937);
	case GeneratorType::mt19937_64: return uniform_real(mt19937_64);
	case GeneratorType::ranlux24_base: return uniform_real(ranlux24_base);
	case GeneratorType::ranlux48_base: return uniform_real(ranlux48_base);
	case GeneratorType::ranlux24: return uniform_real(ranlux24);
	case GeneratorType::ranlux48: return uniform_real(ranlux48);
	case GeneratorType::knuth_b: return uniform_real(knuth_b);
	default: ;
	}
	return 0.0;
}
