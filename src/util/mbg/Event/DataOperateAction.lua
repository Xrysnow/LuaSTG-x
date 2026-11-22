---
--- DataOperateAction.lua
---
--- Copyright (C) 2018 Xrysnow. All rights reserved.
---

local mbg = require('util.mbg.main')
local String = require('util.mbg.String')

---@class mbg.DataOperateAction:mbg.IAction
local DataOperateAction = {}
mbg.DataOperateAction = DataOperateAction

local function _DataOperateAction()
    ---@type mbg.DataOperateAction
    local ret = {}
    ret.LValue = ''
    ret.TweenTime = 0
    ret.Times = 0
    ret.RValue = ''
    ret.TweenFunction = 0
    ret.Operator = 0
    return ret
end

local mt = {
    __call = function()
        return _DataOperateAction()
    end
}
setmetatable(DataOperateAction, mt)

DataOperateAction.TweenFunctionType = {
    Proportional = 0,
    Fixed        = 1,
    Sin          = 2,
}
local TweenFunctionType = DataOperateAction.TweenFunctionType

DataOperateAction.OperatorType = {
    ChangeTo    = 0,
    Add         = 1,
    Subtraction = 2,
}

---ParseFrom
---@param c mbg.String
---@return mbg.DataOperateAction
function DataOperateAction.ParseFrom(c)
    local sents = c:split('，')
    ---@type mbg.DataOperateAction
    local d = mbg.DataOperateAction()
    mbg.ActionHelper.ParseFirstSentence(String(sents[1]), d)
    local str = sents[2]
    if str == '固定' then
        d.TweenFunction = TweenFunctionType.Fixed
    elseif str == '正比' then
        d.TweenFunction = TweenFunctionType.Proportional
    elseif str == '正弦' then
        d.TweenFunction = TweenFunctionType.Sin
    else
        error("无法解析变化曲线名称: " .. sents[2])
    end
    local s3 = String(sents[3])
    local tweenTimeEnd = s3:find('帧')
    d.TweenTime = s3:sub(1, tweenTimeEnd - 1):toint()
    d.Times = nil
    local timesL = s3:findlast('%(')
    local timesR = s3:findlast('%)')
    if timesL ~= -1 and timesR ~= -1 then
        d.Times = s3:sub(timesL + 1, timesR - 1):toint()
    end
    return d
end

