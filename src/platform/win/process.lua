---
--- process.lua
---
--- Copyright (C) 2018-2020 Xrysnow. All rights reserved.
---

--
local M = {}
local ffi = require('ffi')
local k32 = ffi.load('kernel32')

local killByName = [[taskkill /fi "imagename eq %s.exe"]]
local killByNameForce = [[taskkill /f /fi "imagename eq %s.exe"]]
local killById = [[taskkill /fi "pid eq %d"]]
local killByIdForce = [[taskkill /f /fi "pid eq %d"]]

---KillProcessByName
---@param name string
---@param force boolean
function M.KillProcessByName(name, force)
    local cmd
    if force then
        cmd = string.format(killByNameForce, name)
    else
        cmd = string.format(killByName, name)
    end
    return os.execute(cmd)
end

---KillProcessById
---@param pid number
---@param force boolean
function M.KillProcessById(pid, force)
    local cmd
    if force then
        cmd = string.format(killByIdForce, pid)
    else
        cmd = string.format(killById, pid)
    end
    return os.execute(cmd)
end

---Do 'double click'
---@param path string @file path
function M.Start(path)
    return os.execute(string.format('start %s', path))
end

ffi.cdef [[
HANDLE GetCurrentProcess();
]]

function M.GetCurrentProcess()
    return k32.GetCurrentProcess()
end

return M
