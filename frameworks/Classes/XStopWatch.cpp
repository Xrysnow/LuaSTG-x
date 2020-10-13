#include "XStopWatch.h"
#include "platform/CCPlatformDefine.h"

using namespace lstg;

#define QUERY(t) QueryPerformanceCounter((LARGE_INTEGER*)&(t))

#if CC_TARGET_PLATFORM == CC_PLATFORM_WIN32
//#if 0

// this is faster on windows
#include <Windows.h>

StopWatch::StopWatch()
{
	QueryPerformanceFrequency((LARGE_INTEGER*)&freq);
	reset();
}

StopWatch::~StopWatch()
{
}

void StopWatch::pause()
{
	QUERY(fixStart);
}

void StopWatch::resume()
{
	uint64_t tNow;
	QUERY(tNow);
	fixAll += tNow - fixStart;
}

void StopWatch::reset()
{
	fixAll = 0;
	QUERY(last);
}

double StopWatch::get()
{
	uint64_t tNow;
	QUERY(tNow);
	return double(tNow - last - fixAll) / double(freq);
}

#else

#include <chrono>

#define TIME_NOW high_resolution_clock::now().time_since_epoch().count()

using namespace std;
using namespace chrono;
static auto _t = high_resolution_clock::now();
static auto _t1 = _t.time_since_epoch().count();
static auto _t2 = time_point_cast<nanoseconds>(_t).time_since_epoch().count();
static auto factor = double(nanoseconds::period::num) / nanoseconds::period::den * (double(_t2) / _t1);

StopWatch::StopWatch()
{
	reset();
}

StopWatch::~StopWatch()
{
}

void StopWatch::pause()
{
	fixStart = (uint64_t)TIME_NOW;
}

void StopWatch::resume()
{
	fixAll += (uint64_t)TIME_NOW - fixStart;
}

void StopWatch::reset()
{
	fixAll = 0;
	last = (uint64_t)TIME_NOW;
}

double StopWatch::get()
{
	return double((uint64_t)TIME_NOW - last - fixAll) * factor;
}
#endif
