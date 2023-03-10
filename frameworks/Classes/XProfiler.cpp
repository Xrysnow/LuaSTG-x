#include "XProfiler.h"

using namespace std;
using namespace lstg;

XProfiler* XProfiler::getInstance()
{
	static XProfiler instance;
	return &instance;
}

void XProfiler::setEnabled(bool b)
{
	enable = b;
}

bool XProfiler::isEnabled() const
{
	return enable;
}

void XProfiler::tic(const string& name)
{
	if(enable)
		timers[name].tic();
}

double XProfiler::toc(const string& name)
{
	if (!enable)
		return 0.0;
	const auto it = timers.find(name);
	if (it == timers.end())
		return 0.0;
	return it->second.toc();
}

double XProfiler::getAverageTime(const string& name)
{
	const auto it = timers.find(name);
	if (it == timers.end())
		return 0.0;
	return it->second.avg;
}

double XProfiler::getMinTime(const string& name)
{
	const auto it = timers.find(name);
	if (it == timers.end())
		return 0.0;
	return it->second.min;
}

double XProfiler::getMaxTime(const string& name)
{
	const auto it = timers.find(name);
	if (it == timers.end())
		return 0.0;
	return it->second.max;
}

double XProfiler::getTime(const string& name)
{
	const auto it = timers.find(name);
	if (it == timers.end())
		return 0.0;
	return it->second.que.back().time;
}

size_t XProfiler::getCount(const std::string& name)
{
	const auto it = timers.find(name);
	if (it == timers.end())
		return 0.0;
	return it->second.que.back().count;
}

void XProfiler::next()
{
	for (auto&& t : timers)
		t.second.next();
}

void XProfiler::next(const std::string& name)
{
	const auto it = timers.find(name);
	if (it != timers.end())
		it->second.next();
}

void XProfiler::reset()
{
	for (auto&& t : timers)
		t.second.reset();
}

void XProfiler::reset(const string& name)
{
	const auto it = timers.find(name);
	if (it != timers.end())
		it->second.reset();
}

void XProfiler::clear()
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
	if (_toc)
		return 0.0;
	_toc = true;
	const auto dt = sw.get();
	current += dt;
	count++;
	return dt;
}

void XProfiler::ProfileTimer::next()
{
	if (!_toc)
		toc();
	if (que.full())
		sum -= que.queue({current, count}).time;
	else
		que.queue({ current, count });
	sum += current;
	avg = sum / que.size();
	if (current < min)
		min = current;
	if (current > max)
		max = current;
	count = 0;
	current = 0;
}

void XProfiler::ProfileTimer::reset()
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
	const auto it = timers.find(name);
	if (it != timers.end())
		return &it->second;
	return nullptr;
}

void lstg::ProfilingBegin(const std::string& name)
{
	XProfiler::getInstance()->tic(name);
}

double lstg::ProfilingEnd(const std::string& name)
{
	return XProfiler::getInstance()->toc(name);
}
