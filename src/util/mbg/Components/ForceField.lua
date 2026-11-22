---
--- ForceField.lua
---
--- Copyright (C) 2018 Xrysnow. All rights reserved.
---

local mbg = require('util.mbg.main')

---@class mbg.ForceField
local ForceField = {}
mbg.ForceField = ForceField

local function _ForceField()
    ---@type mbg.ForceField
    local ret = {}
    ret['ID'] = 0
    ret['层ID'] = 0
    ret['位置坐标'] = mbg.Position()
    ret['生命'] = mbg.Life()
    ret['半宽'] = 0
    ret['半高'] = 0
    ret['启用圆形'] = false
    ret['类型'] = mbg.ControlType.All
    ret['控制ID'] = 0
    ret['运动'] = mbg.Motion(mbg.ValueWithRand)
    ret['力场加速度'] = 0
    ret['力场加速度方向'] = 0
    ret['中心吸力'] = false
    ret['中心斥力'] = false
    ret['影响速度'] = 0
    return ret
end

local mt = {
    __call = function()
        return _ForceField()
    end
}
setmetatable(ForceField, mt)

---ParseFrom
---@param content mbg.String
---@return mbg.ForceField
function ForceField.ParseFrom(content)
    local f = mbg.ForceField()
    f['ID'] = mbg.ReadUInt(content)
    f['层ID'] = mbg.ReadUInt(content)
    f['位置坐标'].X = mbg.ReadDouble(content)
    f['位置坐标'].Y = mbg.ReadDouble(content)

    f['生命'].Begin = mbg.ReadUInt(content)
    f['生命'].LifeTime = mbg.ReadUInt(content)

    f['半宽'] = mbg.ReadDouble(content)
    f['半高'] = mbg.ReadDouble(content)
    f['启用圆形'] = mbg.ReadBool(content)
    f['类型'] = mbg.ReadUInt(content)
    f['控制ID'] = mbg.ReadUInt(content)
    f['运动'].Speed.BaseValue = mbg.ReadDouble(content)
    f['运动'].SpeedDirection.BaseValue = mbg.ReadDouble(content)
    f['运动'].Acceleration.BaseValue = mbg.ReadDouble(content)
    f['运动'].AccelerationDirection.BaseValue = mbg.ReadDouble(content)
    f['力场加速度'] = mbg.ReadDouble(content)
    f['力场加速度方向'] = mbg.ReadDouble(content)
    f['中心吸力'] = mbg.ReadBool(content)
    f['中心斥力'] = mbg.ReadBool(content)
    f['影响速度'] = mbg.ReadDouble(content)
    f['运动'].Speed.RandValue = mbg.ReadDouble(content)
    f['运动'].SpeedDirection.RandValue = mbg.ReadDouble(content)
    f['运动'].Acceleration.RandValue = mbg.ReadDouble(content)
    f['运动'].AccelerationDirection.RandValue = mbg.ReadDouble(content)
    if not content:isempty() then
        error("力场解析后剩余字符串：" .. content:tostring())
    end
    return f
end

