#include "XProfiler.h"

using namespace std;
using namespace lstg;

bool XProfiler::enable = true;

XProfiler* XProfiler::getInstance()
{
	static XProfiler instance;
	return &instance;
}

void XProfiler::setEnable(bool b)
{
	enable = b;
}

void XProfiler::tic(const string& name)
{
	if(enable)
		timers[name].tic();
}

double XProfiler::toc(const string& name)
{
	if (!enable)return 0.0;
	auto it = timers.find(name);
	if (it == timers.end())return 0.0;
	return it->second.toc();
}

CirularQueue<double, 60>* XProfiler::getQueue(const string& name)
{
	auto it = timers.find(name);
	if (it == timers.end())return nullptr;
	return &it->second.que;
}

double XProfiler::getAverage(const string& name)
{
	auto it = timers.find(name);
	if (it == timers.end())return 0.0;
	return it->second.avg;
}

double XProfiler::getMin(const string& name)
{
	auto it = timers.find(name);
	if (it == timers.end())return 0.0;
	return it->second.min;
}

double XProfiler::getMax(const string& name)
{
	auto it = timers.find(name);
	if (it == timers.end())return 0.0;
	return it->second.max;
}

double XProfiler::getLast(const string& name)
{
	auto it = timers.find(name);
	if (it == timers.end())return 0.0;
	return it->second.que.back();
}

unordered_map<string, double> XProfiler::getAllLast()
{
	unordered_map<string, double> ret;
	for (auto& it : timers)
		ret[it.first] = it.second.que.back();
	return ret;
}

void XProfiler::clear(const string& name)
{
	auto it = timers.find(name);
	if (it != timers.end())
		it->second.clear();
}

void XProfiler::clearAll()
{
	timers.clear();
}

void XProfiler::ProfileTimer::tic()
{
	sw.reset();
	_toc = false;
}

double XProfiler::ProfileTimer::toc()
{
	if (_toc)return 0.0;
	_toc = true;
	const auto dt = sw.get();
	if (que.isFull())
		sum -= que.Queue(dt);
	else
		que.Queue(dt);
	sum += dt;
	avg = sum / que.size();
	if (dt < min)min = dt;
	if (dt > max)max = dt;
	return dt;
}

void XProfiler::ProfileTimer::clear()
{
	sw.reset();
	sum = 0.0;
	avg = 0.0;
	min = 1e10;
	max = 0.0;
	_toc = false;
	que.clear();
}

XProfiler::ProfileTimer* XProfiler::getTimer(const std::string& name)
{
	auto it = timers.find(name);
	if (it != timers.end())
		return &it->second;
	return nullptr;
}
