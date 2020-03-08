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
	random.setSeed(seed);
}

uint32_t Random::getSeed()
{
	return random.getSeed();
}

int32_t Random::randInt(int32_t a, int32_t b)
{
	return a + int32_t(random.getRandUInt(uint32_t(b - a)));
}

float Random::randFloat(float a, float b)
{
	return random.getRandFloat(a, b);
}

int32_t Random::randSign()
{
	return random.getRandUInt(1) * 2 - 1;
}

double Random::_rand()
{
	return random.getRandFloat();
}

Random::Random()
{
}

Random::~Random()
{
}
