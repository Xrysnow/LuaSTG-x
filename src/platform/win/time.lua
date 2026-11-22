---
--- time.lua
---
--- Copyright (C) 2018-2020 Xrysnow. All rights reserved.
---

--
local M = {}
local ffi = require('ffi')
local k32 = ffi.load('kernel32')

ffi.cdef [[
BOOL QueryPerformanceFrequency(
  LARGE_INTEGER *lpFrequency
);
BOOL QueryPerformanceCounter(
  LARGE_INTEGER *lpPerformanceCount
);
void Sleep(
  DWORD dwMilliseconds
);
]]
ffi.cdef [[
typedef struct _SYSTEMTIME {
  WORD wYear;
  WORD wMonth;
  WORD wDayOfWeek;
  WORD wDay;
  WORD wHour;
  WORD wMinute;
  WORD wSecond;
  WORD wMilliseconds;
} SYSTEMTIME, *PSYSTEMTIME;

void GetLocalTime(
  PSYSTEMTIME lpSystemTime
);
//void GetSystemTime(
//  PSYSTEMTIME lpSystemTime
//);
void GetSystemTimeAsFileTime(
  PFILETIME lpSystemTimeAsFileTime
);
void GetSystemTimeAsPreciseFileTime(
  PFILETIME lpSystemTimeAsFileTime
);
]]

function M.QueryPerformanceFrequency()
    local lpFrequency = ffi.new('LARGE_INTEGER[1]')
    k32.QueryPerformanceFrequency(lpFrequency)
    return lpFrequency[0]
end

function M.QueryPerformanceCounter()
    local lpPerformanceCount = ffi.new('LARGE_INTEGER[1]')
    k32.QueryPerformanceFrequency(lpPerformanceCount)
    return lpPerformanceCount[0]
end

function M.Sleep(ms)
    assert(ms >= 0)
    k32.Sleep(ms)
end

local cpu_counters, pdh
local function getProcesserTimePath(n)
    if n then
        return string.format([[\Processor Information(0,%d)\]], n) .. "% Processor Time"
    else
        return [[\Processor Information(_Total)\% Processor Time]]
    end
end

--- QueryCPUTime
--- This function should be called at a interval of at least 1 second.
function M.QueryCPUTime()
    pdh = pdh or require('platform.windows.pdh')
    if not cpu_counters then
        cpu_counters = {}
        cpu_counters[-1] = pdh.PdhAddCounter(getProcesserTimePath())
        for i = 0, 7 do
            cpu_counters[i] = pdh.PdhAddCounter(getProcesserTimePath(i))
        end
    end
    pdh.PdhCollectQueryData()
    M.Sleep(1000)
    pdh.PdhCollectQueryData()
    local ret = {}
    for i = -1, 7 do
        local val = pdh.PdhGetFormattedCounterValue(cpu_counters[i], { 'double' }).doubleValue
        ret[i] = val
    end
    return ret
end

return M
