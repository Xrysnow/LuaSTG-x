---
--- sys_pdh.lua
---
--- Copyright (C) 2018-2020 Xrysnow. All rights reserved.
---

--
local M = {}

local ffi = require('ffi')

local PDH = ffi.load('Pdh')

ffi.def = [[
typedef void* HQUERY;
typedef void* PDH_HQUERY;
typedef void* PDH_HCOUNTER;
typedef long PDH_STATUS;

typedef struct _PDH_FMT_COUNTERVALUE {
    DWORD    CStatus;
    union {
        LONG        longValue;
        double      doubleValue;
        LONGLONG    largeValue;
        LPCSTR      AnsiStringValue;
        LPCWSTR     WideStringValue;
    };
} PDH_FMT_COUNTERVALUE;
typedef PDH_FMT_COUNTERVALUE* PPDH_FMT_COUNTERVALUE;

PDH_STATUS PdhOpenQueryA(
  const char*    szDataSource,
  unsigned long  dwUserData,
  HQUERY *phQuery
);
PDH_STATUS PdhAddCounterA(
  PDH_HQUERY   hQuery,
  const char*      szFullCounterPath,
  DWORD_PTR    dwUserData,
  PDH_HCOUNTER *phCounter
);
PDH_STATUS PdhCollectQueryData(
  PDH_HQUERY hQuery
);
PDH_STATUS PdhGetFormattedCounterValue(
  PDH_HCOUNTER          hCounter,
  DWORD                 dwFormat,
  LPDWORD               lpdwType,
  PPDH_FMT_COUNTERVALUE pValue
);
PDH_STATUS PdhCloseQuery(
  PDH_HQUERY hQuery
);
]]

local LPCSTR = ffi.typeof('const char*')
local DWORD = ffi.typeof('unsigned long')
---dwFormat flag values
local format = {
    PDH_FMT_RAW          = DWORD(0x00000010),
    PDH_FMT_ANSI         = DWORD(0x00000020),
    PDH_FMT_UNICODE      = DWORD(0x00000040),
    PDH_FMT_LONG         = DWORD(0x00000100),
    PDH_FMT_DOUBLE       = DWORD(0x00000200),
    PDH_FMT_LARGE        = DWORD(0x00000400),
    PDH_FMT_NOSCALE      = DWORD(0x00001000),
    PDH_FMT_1000         = DWORD(0x00002000),
    PDH_FMT_NODATA       = DWORD(0x00004000),
    PDH_FMT_NOCAP100     = DWORD(0x00008000),
    PERF_DETAIL_COSTLY   = DWORD(0x00010000),
    PERF_DETAIL_STANDARD = DWORD(0x0000FFFF),
}

local query = ffi.new('HQUERY[1]')
local nullptr = ffi.cast('void*', 0)

---PdhOpenQuery
---Return true if no error.
---@return boolean
function M.PdhOpenQuery()
    return PDH.PdhOpenQueryA(nullptr, 0, query) == 0
end

---PdhAddCounter
---Return the counter if no error.
---@param path string
function M.PdhAddCounter(path)
    local counter = ffi.new('PDH_HCOUNTER[1]')
    local ret = PDH.PdhAddCounterA(query[0], LPCSTR(path), nullptr, counter)
    if ret == 0 then
        return counter[0]
    end
end

---PdhCollectQueryData
---Return true if no error.
---@return boolean
function M.PdhCollectQueryData()
    return PDH.PdhCollectQueryData(query[0]) == 0
end

---PdhGetFormattedCounterValue
---Return the result if no error.
---@param flags table
function M.PdhGetFormattedCounterValue(counter, flags)
    local flag = 0
    for i = 1, #flags do
        flag = flag + format['PDH_FMT_' .. string.upper(flags[i])]
    end
    local val = ffi.new('PDH_FMT_COUNTERVALUE[1]')
    local type = ffi.new('DWORD[1]')
    local ret = PDH.PdhGetFormattedCounterValue(counter, flag, type, val)
    if ret == 0 then
        return val[0]
    else
        print(bit.tohex(tonumber(flag)))
        print(bit.tohex(ret))
        print(counter)
        error('error in PdhGetFormattedCounterValue')
    end
end

---PdhCloseQuery
function M.PdhCloseQuery()
    PDH.PdhCloseQuery(query[0])
end

--------------------------------------------------

assert(M.PdhOpenQuery())

--TODO: PdhCloseQuery

return M
