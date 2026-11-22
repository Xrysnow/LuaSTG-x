local std = std

local pairs = pairs
local setmetatable = setmetatable

---@class x.EventDispatcher
local EventDispatcher = {}
---@class x.EventListener
local _listener = {
    handle   = function()
    end,
    priority = 0,
    tag      = '',
    event    = '',
}

function EventDispatcher:_init()
    ---@type std.list[]
    self._listeners = {}
    ---@type x.EventListener[]
    self._tagged = {}
    self._enabled = true
end

---addListener
---@param event string
---@param handle function
---@param priority number
---@param tag string
function EventDispatcher:addListener(event, handle, priority, tag)
    local group = self._listeners[event]
    if not group then
        self._listeners[event] = std.list()
        group = self._listeners[event]
    end
    priority = priority or 1
    tag = tag or ''
    --assert(type(handle) == 'function')
    local listener = { handle = handle, priority = priority, tag = tag, event = event }
    if tag ~= '' then
        self._tagged[tag] = listener
    end
    group:insert_if(listener, function(v1, v2)
        if v1 == nil and v2 == nil then
            return true
        end
        if v1 == nil then
            return priority < v2.priority
        end
        if v2 == nil then
            return priority >= v1.priority
        end
        return priority >= v1.priority and priority < v2.priority
    end)
end

---@return x.EventListener
function EventDispatcher:getListenerByTag(tag)
    return self._tagged[tag]
end

function EventDispatcher:removeListener(event)
    self._listeners[event] = nil
    for k, v in pairs(self._tagged) do
        if v.event == event then
            self._tagged[k] = nil
        end
    end
end

function EventDispatcher:removeListenerByTag(tag)
    for _, v in pairs(self._listeners) do
        v:remove_if(function(val)
            return val.tag == tag
        end)
    end
    self._tagged[tag] = nil
end

function EventDispatcher:removeAllListeners()
    self._listeners = {}
    self._tagged = {}
end

function EventDispatcher:setEnabled(isEnabled)
    if isEnabled then
        self._enabled = true
    else
        self._enabled = false
    end
end

function EventDispatcher:isEnabled()
    return self._enabled
end

function EventDispatcher:dispatchEvent(event, param)
    if not self._enabled then
        return
    end
    local group = self._listeners[event]
    if group then
        for _, v in std.list_iter(group) do
            v.handle(param)
        end
    end
end

local M = {}

---@return x.EventDispatcher
function M.create()
    local ret = {}
    setmetatable(ret, { __index = EventDispatcher })
    ret:_init()
    return ret
end
--[[
function M.test()
    local e = M.create()
    local h1 = function()
        SystemLog('h1')
    end
    local h2 = function()
        SystemLog('h2')
    end
    local h3 = function()
        SystemLog('h3')
    end
    e:addEventListener('e1', h1, 5)
    e:addEventListener('e1', h2, 3)
    e:addEventListener('e1', h3, 7)
    e:dispatchEvent('e1')
end
]]
return M

