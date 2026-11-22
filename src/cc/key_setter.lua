---@class KeySetter
local M = class('KeySetter')

local director = cc.Director:getInstance()
local _event_key = cc.EventKeyboard
local function sendKeyEvent(keyCode, isPressed)
    local e = _event_key:new(keyCode, isPressed)
    director:getRunningScene():getEventDispatcher():dispatchEvent(e);
end

function M:ctor(keys)
    self._keys = {}
    for i, v in ipairs(keys) do
        self._keys[v] = false
    end
end

function M:set(keyCode, isPressed)
    assert(isPressed ~= nil)
    if self._keys[keyCode] == nil then
        error('invalid keycode')
    else
        isPressed = isPressed and true or false
        -- only set when different
        if self._keys[keyCode] ~= isPressed then
            sendKeyEvent(keyCode, isPressed)
            self._keys[keyCode] = isPressed
        end
    end
end

function M:flip(keyCode)
    if self._keys[keyCode] == nil then
        error('invalid keycode')
    else
        sendKeyEvent(keyCode, not self._keys[keyCode])
        self._keys[keyCode] = not self._keys[keyCode]
    end
end
function M:setMulti(states)
    for k, v in pairs(states) do
        self:set(k, v)
    end
end
function M:setAll(isPressed)
    isPressed = isPressed and true or false
    for k, _ in pairs(self._keys) do
        self:set(k, isPressed)
    end
end
function M:clearAll()
    self:setAll(false)
end
function M:get(keyCode)
    return self._keys[keyCode]
end

return M
