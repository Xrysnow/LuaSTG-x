#include "Randomizer.h"
//#include <cmath>

using namespace lstg;

XRandom* XRandom::create()
{
	auto ret = new (std::nothrow) XRandom();
	if (ret)
	{
		return ret;
	}
	CC_SAFE_DELETE(ret);
	return nullptr;
}

XRandom* XRandom::create(uint32_t seed)
{
	auto ret = new (std::nothrow) XRandom();
	if (ret)
	{
		ret->setSeed(seed);
		return ret;
	}
	CC_SAFE_DELETE(ret);
	return nullptr;
}

void XRandom::setSeed(uint32_t seed)
{
	random.SetSeed(seed);
}

uint32_t XRandom::getSeed()
{
	return random.GetRandSeed();
}

int32_t XRandom::randInt(int32_t a, int32_t b)
{
	return a + int32_t(random.GetRandUInt(uint32_t(b - a)));
}

float XRandom::randFloat(float a, float b)
{
	return random.GetRandFloat(a, b);
}

int32_t XRandom::randSign()
{
	return random.GetRandUInt(1) * 2 - 1;
}

double XRandom::_rand()
{
	return random.GetRandFloat();
}

XRandom::XRandom()
{
}

XRandom::~XRandom()
{
}
