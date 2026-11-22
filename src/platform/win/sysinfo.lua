---
--- cpuinfo.lua
---
--- Copyright (C) 2018-2020 Xrysnow. All rights reserved.
---

--
local M = {}

local ffi = require('ffi')
local k32 = ffi.load('kernel32')

ffi.cdef [[
typedef struct _SYSTEM_INFO {
  union {
    DWORD  dwOemId;
    struct {
      WORD wProcessorArchitecture;
      WORD wReserved;
    };
  };
  DWORD     dwPageSize;
  LPVOID    lpMinimumApplicationAddress;
  LPVOID    lpMaximumApplicationAddress;
  DWORD_PTR dwActiveProcessorMask;
  DWORD     dwNumberOfProcessors;
  DWORD     dwProcessorType;
  DWORD     dwAllocationGranularity;
  WORD      wProcessorLevel;
  WORD      wProcessorRevision;
} SYSTEM_INFO;
typedef SYSTEM_INFO *LPSYSTEM_INFO;

void GetNativeSystemInfo(
  LPSYSTEM_INFO lpSystemInfo
);
void GetSystemInfo(
  LPSYSTEM_INFO lpSystemInfo
);
]]

function M.GetNativeSystemInfo()
    local info = ffi.new('SYSTEM_INFO')
    k32.GetNativeSystemInfo(info)
    return info
end

function M.GetSystemInfo()
    local info = ffi.new('SYSTEM_INFO')
    k32.GetSystemInfo(info)
    return info
end

local info = M.GetNativeSystemInfo()
M.ProcessorArchitecture = info.wProcessorArchitecture
M.PageSize = info.dwPageSize
M.NumberOfProcessors = info.dwNumberOfProcessors
M.ProcessorType = info.dwProcessorType
M.AllocationGranularity = info.dwAllocationGranularity
M.ProcessorLevel = info.wProcessorLevel
M.ProcessorRevision = info.wProcessorRevision

return M
