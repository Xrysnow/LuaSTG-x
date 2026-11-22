---
--- _util.lua
---
--- Copyright (C) 2018-2020 Xrysnow. All rights reserved.
---

--
local M = {}
local ffi = ffi or require('ffi')

function M.DECLARE_HANDLE(name)
    ffi.cdef(string.format('typedef void *%s;', name))
end

return M
