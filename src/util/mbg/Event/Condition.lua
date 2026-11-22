---
--- Condition.lua
---
--- Copyright (C) 2018 Xrysnow. All rights reserved.
---

local mbg = require('util.mbg.main')
local String = require('util.mbg.String')

---@class mbg.Condition
local Condition = {}
mbg.Condition = Condition
---@class mbg.Condition.Expression
local Expression = {}
Condition.Expression = Expression

local mt_Expression = {
    __call = function()
        ---@type mbg.Condition.Expression
        local ret = {}
        ret.LValue = ''
        ret.Operator = 0
        ret.RValue = 0
        return ret
    end
}
setmetatable(Expression, mt_Expression)

Expression.OpType = {
    Greater = 0,
    Less    = 1,
    Equals  = 2
}

---ParseFrom
---@param c mbg.String
---@return mbg.Condition.Expression
function Expression.ParseFrom(c)
    local e = Expression()
    if c:contains('>') then
        e.Operator = Expression.OpType.Greater
    elseif c:contains('<') then
        e.Operator = Expression.OpType.Less
    elseif c:contains('=') then
        e.Operator = Expression.OpType.Equals
    else
        error("未能解析表达式")
    end
    local values = c:split('>', '<', '=')
    e.LValue = values[1]
    e.RValue = tonumber(values[2])
    return e
end

---@class mbg.Condition.SecondCondition
local SecondCondition = {}
Condition.SecondCondition = SecondCondition

SecondCondition.LogicOpType = {
    And = 0,
    Or  = 1
}

local mt_SecondCondition = {
    __call = function()
        ---@type mbg.Condition.SecondCondition
        local ret = {}
        ret.LogicOp = 0
        ret.Expr = Expression()
        return ret
    end
}
setmetatable(SecondCondition, mt_SecondCondition)

local mt_Condition = {
    __call = function()
        ---@type mbg.Condition
        local ret = {}
        ret.First = Expression()
        ret.Second = SecondCondition()
        return ret
    end
}
setmetatable(Condition, mt_Condition)

---ParseFrom
---@param c mbg.String
---@return mbg.Condition
function Condition.ParseFrom(c)
    local op
    if c:contains('且') then
        op = SecondCondition.LogicOpType.And
    elseif c:contains('或') then
        op = SecondCondition.LogicOpType.Or
    end
    local condition = Condition()
    if not op then
        condition.First = Expression.ParseFrom(c)
        condition.Second = nil
    else
        local exprs = c:split('且', '或')
        condition.First = Expression.ParseFrom(String(exprs[1]))
        condition.Second = SecondCondition()
        condition.Second.LogicOp = op
        condition.Second.Expr = Expression.ParseFrom(String(exprs[2]))
    end
    return condition
end

