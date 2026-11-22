---
--- BindState.lua
---
--- Copyright (C) 2018 Xrysnow. All rights reserved.
---

local mbg = require('util.mbg.main')

---@class mbg.BindState
local BindState = {}
mbg.BindState = BindState

local function _BindState()
    ---@type mbg.BindState
    local ret = {}
    ret.Parent = nil
    ret.Child = nil
    ret.Depth = false
    ret.Relative = false
    return ret
end

local mt = {
    __call = function()
        return _BindState()
    end
}
setmetatable(BindState, mt)

