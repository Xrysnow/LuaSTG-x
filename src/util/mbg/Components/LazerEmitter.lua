---
--- LazerEmitter.lua
---
--- Copyright (C) 2018 Xrysnow. All rights reserved.
---

local mbg = require('util.mbg.main')

---@class mbg.LazerEmitter
local LazerEmitter = {}
mbg.LazerEmitter = LazerEmitter

local function _LazerEmitter()
    ---@type mbg.LazerEmitter
    local ret = {}
    ret['ID'] = 0
    ret['层ID'] = 0
    ret['绑定状态'] = mbg.BindState()
    ret['位置坐标'] = mbg.Position()
    ret['生命'] = mbg.Life()
    ret['半径'] = mbg.ValueWithRand()
    ret['半径方向'] = mbg.ValueWithRand()
    ret['半径方向_坐标指定'] = mbg.Position()
    ret['条数'] = mbg.ValueWithRand()
    ret['周期'] = mbg.ValueWithRand()
    ret['发射角度'] = mbg.ValueWithRand()
    ret['发射角度_坐标指定'] = mbg.Position()
    ret['范围'] = mbg.ValueWithRand()
    ret['发射器运动'] = mbg.MotionWithPosition(mbg.ValueWithRand)
    ret['子弹生命'] = 0
    ret['类型'] = 0
    ret['宽比'] = 0
    ret['长度'] = 0
    ret['不透明度'] = 0
    ret['子弹运动'] = mbg.MotionWithPosition(mbg.ValueWithRand)
    ret['横比'] = 0
    ret['纵比'] = 0
    ret['高光效果'] = false
    ret['出屏即消'] = false
    ret['无敌状态'] = false
    ---@type mbg.EventGroup[]
    ret['发射器事件组'] = {}
    ---@type mbg.EventGroup[]
    ret['子弹事件组'] = {}
    ret['启用射线激光'] = false
    return ret
end

local mt = {
    __call = function()
        return _LazerEmitter()
    end
}
setmetatable(LazerEmitter, mt)

---ParseFrom
---@param c mbg.String
---@param layer mbg.Layer
---@return mbg.LazerEmitter,fun()
function LazerEmitter.ParseFrom(c, layer)
    local tmp = {}
    local l = mbg.LazerEmitter()
    l['ID'] = mbg.ReadUInt(c)
    l['层ID'] = mbg.ReadUInt(c)
    --可能已废弃
    tmp['绑定状态'] = mbg.ReadBool(c)
    tmp['绑定ID'] = mbg.ReadInt(c)
    tmp['相对方向'] = mbg.ReadBool(c)
    mbg.ReadString(c)  --TODO:CrazyStorm未描述此格数据内容
    l['位置坐标'].X = mbg.ReadDouble(c)
    l['位置坐标'].Y = mbg.ReadDouble(c)

    l['生命'].Begin = mbg.ReadUInt(c)
    l['生命'].LifeTime = mbg.ReadUInt(c)

    l['半径'].BaseValue = mbg.ReadDouble(c)
    l['半径方向'].BaseValue = mbg.ReadDouble(c)
    l['半径方向_坐标指定'] = mbg.ReadPosition(c)
    l['条数'].BaseValue = mbg.ReadDouble(c)
    l['周期'].BaseValue = mbg.ReadDouble(c)
    l['发射角度'].BaseValue = mbg.ReadDouble(c)
    l['发射角度_坐标指定'] = mbg.ReadPosition(c)
    l['范围'].BaseValue = mbg.ReadDouble(c)

    l['发射器运动'].Motion.Speed.BaseValue = mbg.ReadDouble(c)
    l['发射器运动'].Motion.SpeedDirection.BaseValue = mbg.ReadDouble(c)
    l['发射器运动'].SpeedDirectionPosition = mbg.ReadPosition(c)
    l['发射器运动'].Motion.Acceleration.BaseValue = mbg.ReadDouble(c)
    l['发射器运动'].Motion.AccelerationDirection.BaseValue = mbg.ReadDouble(c)
    l['发射器运动'].AccelerationDirectionPosition = mbg.ReadPosition(c)

    l['子弹生命'] = mbg.ReadUInt(c)
    l['类型'] = mbg.ReadUInt(c)
    l['宽比'] = mbg.ReadDouble(c)
    l['长度'] = mbg.ReadDouble(c)
    l['不透明度'] = mbg.ReadDouble(c)
    l['启用射线激光'] = mbg.ReadBool(c)

    l['子弹运动'].Motion.Speed.BaseValue = mbg.ReadDouble(c)
    l['子弹运动'].Motion.SpeedDirection.BaseValue = mbg.ReadDouble(c)
    l['子弹运动'].SpeedDirectionPosition = mbg.ReadPosition(c)
    l['子弹运动'].Motion.Acceleration.BaseValue = mbg.ReadDouble(c)
    l['子弹运动'].Motion.AccelerationDirection.BaseValue = mbg.ReadDouble(c)
    l['子弹运动'].AccelerationDirectionPosition = mbg.ReadPosition(c)

    l['横比'] = mbg.ReadDouble(c)
    l['纵比'] = mbg.ReadDouble(c)
    l['高光效果'] = mbg.ReadBool(c)
    l['出屏即消'] = mbg.ReadBool(c)
    l['无敌状态'] = mbg.ReadBool(c)
    mbg.ReadString(c)
    l['发射器事件组'] = mbg.EventGroup.ParseEventGroups(mbg.ReadString(c))
    l['子弹事件组'] = mbg.EventGroup.ParseEventGroups(mbg.ReadString(c))
    l['半径'].RandValue = mbg.ReadDouble(c)
    l['半径方向'].RandValue = mbg.ReadDouble(c)
    l['条数'].RandValue = mbg.ReadDouble(c)
    l['周期'].RandValue = mbg.ReadDouble(c)
    l['发射角度'].RandValue = mbg.ReadDouble(c)
    l['范围'].RandValue = mbg.ReadDouble(c)

    l['发射器运动'].Motion.Speed.RandValue = mbg.ReadDouble(c)
    l['发射器运动'].Motion.SpeedDirection.RandValue = mbg.ReadDouble(c)
    l['发射器运动'].Motion.Acceleration.RandValue = mbg.ReadDouble(c)
    l['发射器运动'].Motion.AccelerationDirection.RandValue = mbg.ReadDouble(c)

    l['子弹运动'].Motion.Speed.RandValue = mbg.ReadDouble(c)
    l['子弹运动'].Motion.SpeedDirection.RandValue = mbg.ReadDouble(c)
    l['子弹运动'].Motion.Acceleration.RandValue = mbg.ReadDouble(c)
    l['子弹运动'].Motion.AccelerationDirection.RandValue = mbg.ReadDouble(c)

    tmp['深度绑定'] = mbg.ReadBool(c)
    local binder = function()
    end
    if tmp['绑定ID'] ~= -1 then
        binder = function()
            l['绑定状态'] = layer
                    :FindBulletEmitterByID(tmp['绑定ID'])
                    :Bind(l, tmp['深度绑定'], tmp['相对方向'])
        end
    end
    if not c:isempty() then
        error("激光发射器解析后剩余字符串：" .. c:tostring())
    end
    return l, binder
end

