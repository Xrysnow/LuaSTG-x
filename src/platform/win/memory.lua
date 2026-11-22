---
--- memory.lua
---
--- Copyright (C) 2018-2020 Xrysnow. All rights reserved.
---

--
local M = {}
local ffi = require('ffi')
local k32 = ffi.load('kernel32')

ffi.cdef [[
typedef struct _PROCESS_MEMORY_COUNTERS {
    DWORD cb;
    DWORD PageFaultCount;
    SIZE_T PeakWorkingSetSize;
    SIZE_T WorkingSetSize;
    SIZE_T QuotaPeakPagedPoolUsage;
    SIZE_T QuotaPagedPoolUsage;
    SIZE_T QuotaPeakNonPagedPoolUsage;
    SIZE_T QuotaNonPagedPoolUsage;
    SIZE_T PagefileUsage;
    SIZE_T PeakPagefileUsage;
} PROCESS_MEMORY_COUNTERS;
typedef PROCESS_MEMORY_COUNTERS *PPROCESS_MEMORY_COUNTERS;

BOOL K32GetProcessMemoryInfo(
    HANDLE Process,
    PPROCESS_MEMORY_COUNTERS ppsmemCounters,
    DWORD cb
);
]]

local pmc_size = ffi.sizeof('PROCESS_MEMORY_COUNTERS')

function M.GetProcessMemoryInfo()
    local ppsmemCounters = ffi.new('PROCESS_MEMORY_COUNTERS[1]')
    k32.K32GetProcessMemoryInfo(
            require('platform.win.process').GetCurrentProcess(), ppsmemCounters, pmc_size)
    return ppsmemCounters[0]
end

--------------------------------------------------
-- High Level Interface
--------------------------------------------------

local _factor = 1024 * 1024

--- Get working set size of this process in MB.
---@return number
function M.GetWorkingSetSize()
    local info = M.GetProcessMemoryInfo()
    -- to MB
    return tonumber(info.WorkingSetSize / _factor)
end

return M
