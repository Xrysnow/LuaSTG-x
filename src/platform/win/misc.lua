---
--- sys_misc.lua
---
--- Copyright (C) 2018-2020 Xrysnow. All rights reserved.
---

--
local M = {}

local ffi = require('ffi')
local imm32 = ffi.load('Imm32')
local u32 = ffi.load('User32')
local DECLARE_HANDLE = require('platform.windows._util').DECLARE_HANDLE

--DECLARE_HANDLE('HKL')
DECLARE_HANDLE('HIMC')

ffi.cdef [[
BOOL ImmDisableIME(
  DWORD idThread
);

HKL LoadKeyboardLayout(
  LPCTSTR pwszKLID,
  UINT    Flags
);

HIMC ImmGetContext(
  HWND hWnd
);
]]

function M.ImmDisableIME()
    return imm32.ImmDisableIME(-1)
end

function M.LoadKeyboardLayout(pwszKLID, Flags)
    return u32.LoadKeyboardLayout(pwszKLID, Flags)
end

return M
