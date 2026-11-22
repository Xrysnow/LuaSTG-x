---
--- directory.lua
---
--- Copyright (C) 2018-2020 Xrysnow. All rights reserved.
---

--
local M = {}
local ffi = require('ffi')
local k32 = ffi.load('kernel32')
local util = require('platform.win.util')
local checknz = util.checknz
local wcs = require('platform.win.wcs')

ffi.cdef [[
int SetCurrentDirectoryW(const wchar_t* lpPathName);
int GetCurrentDirectoryW(int nBufferLength, wchar_t* lpPathName);
]]

function M.SetCurrentDirectory(path)
    return k32.SetCurrentDirectoryW(wcs.wcs(path))
end

function M.GetCurrentDirectory()
    local sz = checknz(k32.GetCurrentDirectoryW(0, nil))
    local buffer = ffi.new('wchar_t[?]', sz)
    checknz(k32.GetCurrentDirectoryW(sz, buffer))
    return wcs.mbs(buffer)
end

return M
