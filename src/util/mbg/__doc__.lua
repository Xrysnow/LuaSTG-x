---
--- __doc__.lua
---
--- Copyright (C) 2018 Xrysnow. All rights reserved.
---

local mbg = require('util.mbg.main')

---@class mbg.Position
local _Position = { X = 0, Y = 0 }

---@class mbg.Motion
local _Motion = {
    Speed          = 0, Acceleration = 0,
    SpeedDirection = 0, AccelerationDirection = 0
}

---@class mbg.MotionWithPosition
local _MotionWithPosition = {
    Motion   = mbg.Motion(),
    Position = mbg.Position()
}

---@class mbg.ValueWithRand
local _ValueWithRand = { BaseValue = 0, RandValue = 0 }

---@class mbg.Life
local _Life = { Begin = 0, LifeTime = 0 }

---@class mbg.Color
local _Color = { R = 0, G = 0, B = 0, A = 0 }

---@class mbg.IAction
local _IAction = {}

