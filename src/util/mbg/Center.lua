---
--- Center.lua
---
--- Copyright (C) 2018 Xrysnow. All rights reserved.
---

local mbg = require('util.mbg.main')

---@class mbg.Center
local Center = {}
mbg.Center = Center

local function _Center()
    ---@type mbg.Center
    local ret = {}
    ret.Position = mbg.Position()
    ret.Motion = mbg.Motion()
    ---@type mbg.Event[]
    ret.Events = {}
    return ret
end

local mt = {
    __call = function()
        return _Center()
    end
}
setmetatable(Center, mt)

---ParseFromContent
---@param content mbg.String
---@return mbg.Center
function Center.ParseFromContent(content)
    if content:equalto("False") then
        return nil
    else
        local center = Center()
        local ReadString = mbg.ReadString

        center.Position.X = ReadString(content):tonumber()
        center.Position.Y = ReadString(content):tonumber()

        center.Motion.Speed = ReadString(content):tonumber()
        center.Motion.SpeedDirection = ReadString(content):tonumber()

        center.Motion.Acceleration = ReadString(content):tonumber()
        center.Motion.AccelerationDirection = ReadString(content):tonumber()

        center.Events = nil
        if not content:isempty() then
            center.Events = mbg.Event.ParseEvents(ReadString(content))
        end

        return center
    end
end

return Center
