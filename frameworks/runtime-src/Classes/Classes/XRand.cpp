#include "XRand.h"

using namespace lstg;

Random* Random::create()
{
	auto ret = new (std::nothrow) Random();
	if (ret)
	{
		return ret;
	}
	CC_SAFE_DELETE(ret);
	return nullptr;
}

Random* Random::create(uint32_t seed)
{
	auto ret = new (std::nothrow) Random();
	if (ret)
	{
		ret->setSeed(seed);
		return ret;
	}
	CC_SAFE_DELETE(ret);
	return nullptr;
}

void Random::setSeed(uint32_t seed)
{
	random.SetSeed(seed);
}

uint32_t Random::getSeed()
{
	return random.GetRandSeed();
}

int32_t Random::randInt(int32_t a, int32_t b)
{
	return a + int32_t(random.GetRandUInt(uint32_t(b - a)));
}

float Random::randFloat(float a, float b)
{
	return random.GetRandFloat(a, b);
}

int32_t Random::randSign()
{
	return random.GetRandUInt(1) * 2 - 1;
}

double Random::_rand()
{
	return random.GetRandFloat();
}

Random::Random()
{
}

Random::~Random()
{
}
