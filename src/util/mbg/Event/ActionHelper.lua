---
--- ActionHelper.lua
---
--- Copyright (C) 2018 Xrysnow. All rights reserved.
---

local mbg = require('util.mbg.main')

---@class mbg.ActionHelper
local ActionHelper = {}
mbg.ActionHelper = ActionHelper

---ParseFrom
---@param c mbg.String
---@return mbg.IAction
function ActionHelper.ParseFrom(c)
    if c:contains('变化到') or c:contains('增加') or c:contains('减少') then
        return mbg.DataOperateAction.ParseFrom(c)
    else
        return mbg.CommandAction.ParseFrom(c)
    end
end

local action_op

---ParseFirstSentence
---@param firstSentence mbg.String
---@param action mbg.IAction
function ActionHelper.ParseFirstSentence(firstSentence, action)
    local pos1 = -1
    local pos2
    action_op = action_op or {
        ['变化到'] = mbg.OperatorType.ChangeTo,
        ['增加']  = mbg.OperatorType.Add,
        ['减少']  = mbg.OperatorType.Subtraction,
    }
    for k, v in pairs(action_op) do
        pos1, pos2 = firstSentence:find(k)
        if pos1 ~= -1 then
            action.Operator = v
            break
        end
    end
    assert(pos1 ~= -1, '无法解析操作符于: ' .. firstSentence:tostring())
    action.LValue = firstSentence:sub(1, pos1 - 1)
    action.RValue = firstSentence:sub(pos2 + 1)
end

