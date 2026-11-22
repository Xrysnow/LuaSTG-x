---
--- EventGroup.lua
---
--- Copyright (C) 2018 Xrysnow. All rights reserved.
---

local mbg = require('util.mbg.main')
local String = require('util.mbg.String')

---@class mbg.EventGroup
local EventGroup = {}
mbg.EventGroup = EventGroup

local function _EventGroup()
    local ret = {}
    ret.Name = ''
    ret.Interval = 0
    ret.IntervalIncrement = 0
    ---@type mbg.Event[]
    ret.Events = {}
    return ret
end

local mt = {
    __call = function()
        return _EventGroup()
    end
}
setmetatable(EventGroup, mt)

---ParseFrom
---@param c mbg.String
---@return mbg.EventGroup
function EventGroup.ParseFrom(c)
    local eg = mbg.EventGroup()
    eg.Name = mbg.ReadString(c, '|')
    eg.Interval = mbg.ReadUInt(c, '|')
    eg.IntervalIncrement = mbg.ReadUInt(c, '|')
    eg.Events = mbg.Event.ParseEvents(c)
    return eg
end

---ParseEventGroups
---@param c mbg.String
---@return mbg.EventGroup[]
function EventGroup.ParseEventGroups(c)
    if not c or c:isempty() then
        return nil
    else
        local ret = {}
        local egs = c:split('&')
        for _, v in ipairs(egs) do
            if v ~= '' then
                table.insert(ret, EventGroup.ParseFrom(String(v)))
            end
        end
        return ret
    end
end

