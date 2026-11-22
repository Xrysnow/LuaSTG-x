---
--- GlobalEvents.lua
---
--- Copyright (C) 2018 Xrysnow. All rights reserved.
---

local mbg = require('util.mbg.main')

---@class mbg.GlobalEvents
local GlobalEvents = {}
mbg.GlobalEvents = GlobalEvents

local function _GlobalEvents()
    ---@type mbg.GlobalEvents
    local ret = {}
    ret.Frame = 0
    ret.JumpEnabled = false
    ret.JumpTarget = 0
    ret.JumpTimes = 0
    ret.VibrateEnabled = false
    ret.VibrateForce = 0
    ret.VibrateTime = 0
    ret.SleepEnabled = false
    ret.SleepTime = 0
    ret.SleepType = 0
    return ret
end

local mt = {
    __call = function()
        return _GlobalEvents()
    end
}
setmetatable(GlobalEvents, mt)

GlobalEvents.SleepModeType = {
    Tween = 0,
    Full  = 1
}

---ParseFrom
---@param c mbg.String
---@return mbg.GlobalEvents
function GlobalEvents.ParseFrom(c)
    local ge = GlobalEvents()
    ge.Frame = mbg.ReadUInt(c, '_');
    mbg.ReadString(c, '_');
    mbg.ReadString(c, '_');
    mbg.ReadString(c, '_');

    ge.JumpEnabled = mbg.ReadBool(c, '_');
    ge.JumpTimes = mbg.ReadUInt(c, '_');
    ge.JumpTarget = mbg.ReadUInt(c, '_');

    mbg.ReadString(c, '_');
    mbg.ReadString(c, '_');
    mbg.ReadString(c, '_');

    ge.VibrateEnabled = mbg.ReadBool(c, '_');
    ge.VibrateTime = mbg.ReadUInt(c, '_');
    ge.VibrateForce = mbg.ReadDouble(c, '_');

    mbg.ReadString(c, '_');
    mbg.ReadString(c, '_');
    mbg.ReadString(c, '_');

    ge.SleepEnabled = mbg.ReadBool(c, '_');
    ge.SleepTime = mbg.ReadUInt(c, '_');
    ge.SleepType = mbg.ReadUInt(c, '_');

    if not c:isempty() then
        error("全局帧事件字符串解析剩余：" .. c:tostring())
    end
    return ge
end

---ParseEvents
---@param title mbg.String
---@param _mbg mbg.String
---@return table
function GlobalEvents.ParseEvents(title, _mbg)
    local ret = {}
    local soundCount = title
            :sub(1, title:find('GlobalEvents') - 1)
            :trim()
            :toint()
    for i = 1, soundCount do
        table.insert(ret, GlobalEvents.ParseFrom(_mbg:readline()))
    end
    return ret
end

