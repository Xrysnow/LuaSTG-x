---
--- Event.lua
---
--- Copyright (C) 2018 Xrysnow. All rights reserved.
---

local mbg = require('util.mbg.main')
local String = require('util.mbg.String')

---@class mbg.Event
local Event = {}
mbg.Event = Event

local function _Event()
    ---@type mbg.Event
    local ret = {}
    ---@type mbg.Condition
    ret.Condition = nil
    ---@type mbg.DataOperateAction|mbg.CommandAction|mbg.ReflexBoardAction
    ret.Action = nil
    return ret
end

local mt = {
    __call = function()
        return _Event()
    end
}
setmetatable(Event, mt)

---ParseFrom
---@param c mbg.String
---@return mbg.Event
function Event.ParseFrom(c)
    local e = Event()
    e.Condition = mbg.Condition.ParseFrom(mbg.ReadString(c, '：'))
    e.Action = mbg.ActionHelper.ParseFrom(c)
    return e
end

---ParseEvents
---@param c mbg.String
---@return mbg.Event[]
function Event.ParseEvents(c)
    if not c or c:isempty() then
        return nil
    else
        local ret = {}
        local events = c:split(';')
        for _, v in pairs(events) do
            if v ~= '' then
                table.insert(ret, Event.ParseFrom(String(v)))
            end
        end
        return ret
    end
end

