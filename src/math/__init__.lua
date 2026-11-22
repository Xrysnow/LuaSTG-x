---
--- __init__.lua
---
--- Copyright (C) 2018-2020 Xrysnow. All rights reserved.
---

for _, n in ipairs({ 'math', 'math_const', 'math_types' }) do
    require('math.' .. n)
end

math.Vec2 = require('math.vec2')
math.Vec3 = require('math.vec3')
math.Vec4 = require('math.vec4')
math.Mat4 = require('math.mat4')
math.Quat = require('math.quaternion')

---@return math.vec2
function math.vec2(...)
    return math.Vec2(...)
end

---@return math.vec3
function math.vec3(...)
    return math.Vec3(...)
end

---@return math.vec4
function math.vec4(...)
    return math.Vec4(...)
end

---@return math.mat4
function math.mat4(...)
    return math.Mat4(...)
end

---@return math.quaternion
function math.quat(...)
    return math.Quat(...)
end

local util = require('math._util')
util.swizzleVec(math.Vec2, 'x', 'y')
util.swizzleVec(math.Vec3, 'x', 'y', 'z')
util.swizzleVec(math.Vec4, 'x', 'y', 'z', 'w')

math.collision = require('math.collision')
math.complex = require('math.complex')
math.intersection = require('math.intersection')
math.spline = require('math.spline')
math.tween = require('math.tween')
