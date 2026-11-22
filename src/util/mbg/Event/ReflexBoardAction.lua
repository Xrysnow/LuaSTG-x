---
--- ReflexBoardAction.lua
---
--- Copyright (C) 2018 Xrysnow. All rights reserved.
---

local mbg = require('util.mbg.main')
local String = require('util.mbg.String')

---@class mbg.ReflexBoardAction:mbg.IAction
local ReflexBoardAction = {}
mbg.ReflexBoardAction = ReflexBoardAction

local function _ReflexBoardAction()
    ---@type mbg.ReflexBoardAction
    local ret = {}
    ret.LValue = ''
    ret.RValue = ''
    ret.Operator = 0
    return ret
end

local mt = {
    __call = function()
        return _ReflexBoardAction()
    end
}
setmetatable(ReflexBoardAction, mt)

---ParseFrom
---@param c mbg.String
---@return mbg.ReflexBoardAction
function ReflexBoardAction.ParseFrom(c)
    local r = ReflexBoardAction()
    mbg.ActionHelper.ParseFirstSentence(c, r)
    return r
end

---ParseActions
---@param c mbg.String
---@return mbg.ReflexBoardAction[]
function ReflexBoardAction.ParseActions(c)
    if not c or c:isempty() then
        return nil
    else
        local ret = {}
        local actions = c:split('&')
        for _, v in ipairs(actions) do
            if v ~= '' then
                table.insert(ret, ReflexBoardAction.ParseFrom(String(v)))
            end
        end
        return ret
    end
end

