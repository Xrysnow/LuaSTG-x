---
--- Common.lua
---
--- Copyright (C) 2018 Xrysnow. All rights reserved.
---

local mbg = require('util.mbg.main')

local function Template(table, T)
    local ret = table
    if T then
        assert(type(T) ~= 'table')
        if type(T) == 'function' then
            for k, v in pairs(ret) do
                ret[k] = T()
            end
        else
            for k, v in pairs(ret) do
                ret[k] = T
            end
        end
    end
    return ret
end

---@return mbg.Position
function mbg.Position(T)
    local ret = { X = 0, Y = 0 }
    return Template(ret, T)
end

---@return mbg.Motion
function mbg.Motion(T)
    local ret = {
        Speed          = 0, Acceleration = 0,
        SpeedDirection = 0, AccelerationDirection = 0
    }
    return Template(ret, T)
end

---@return mbg.MotionWithPosition
function mbg.MotionWithPosition(T, U)
    return {
        Motion   = mbg.Motion(T),
        Position = mbg.Position(U)
    }
end

---@return mbg.ValueWithRand
function mbg.ValueWithRand()
    return { BaseValue = 0, RandValue = 0 }
end

---@return mbg.Life
function mbg.Life()
    return { Begin = 0, LifeTime = 0 }
end

---@return mbg.Color
function mbg.Color()
    return { R = 0, G = 0, B = 0, A = 0 }
end

mbg.ControlType = { All = 0, ID = 1 }

mbg.TweenFunctionType = {
    Proportional = 0,
    Fixed        = 1,
    Sin          = 2
}

mbg.OperatorType = {
    ChangeTo    = 0,
    Add         = 1,
    Subtraction = 2
}
