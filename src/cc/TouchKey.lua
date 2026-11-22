---@class TouchKey:cc.Sprite
local TouchKey = class("TouchKey", function(texture)
    return cc.Sprite:createWithTexture(texture)
end)

TouchKey.__index = TouchKey

local StateGrabbed = 0
local StateUngrabbed = 1

TouchKey._state = StateGrabbed

function TouchKey:rect()
    local s = self:getTexture():getContentSize()
    return cc.rect(-s.x / 2, -s.y / 2, s.x, s.y)
end

function TouchKey:containsTouchLocation(x, y)
    local p = self:convertToNodeSpace(cc.p(x, y))
    local s = self:getContentSize()
    return cc.rectContainsPoint(cc.rect(0, 0, s.x, s.y), p)
end

---@param aTexture cc.Texture2D
---@param keyCode number
---@return TouchKey
function TouchKey:create(aTexture, keyCode, isLock)
    local tk = TouchKey(aTexture)
    tk._state = StateUngrabbed
    tk._keyCode = keyCode
    tk._isLock = isLock
    tk.__isLock = isLock
    tk:registerScriptHandler(function(tag)
        if "enter" == tag then
            tk:onEnter()
        elseif "exit" == tag then
            tk._touchId = nil
            if tk._setInactive then
                tk._setInactive()
            end
            for _, listener in ipairs(tk._listeners or {}) do
                tk:getEventDispatcher():removeEventListener(listener)
            end
            tk._listeners = nil
            tk:unscheduleUpdate()
        end
    end)
    return tk
end

local director = cc.Director:getInstance()
local function sendKeyEvent(keyCode, isPressed)
    -- Restricted Ref construction: research/lua-binding-convergence_2026-11-01/core/callers.md
    local e = cc.EventKeyboard:new(keyCode, isPressed)
    director:getRunningScene():getEventDispatcher():dispatchEvent(e);
end

local _color_inactive = cc.c3b(255, 255, 255)
local _color_active = cc.c3b(255, 255, 0)

function TouchKey:onEnter()
    --self:setOpacity(127)
    local listener = cc.EventListenerTouchOneByOne:create()
    listener:setSwallowTouches(true)
    local setActive = function()
        if self._state == StateGrabbed then return end
        self._state = StateGrabbed
        sendKeyEvent(self._keyCode, true)
        self:setColor(_color_active)
        --print('TouchKey: sendKeyEvent true.')
    end
    local setInactive = function()
        if self._state == StateUngrabbed then return end
        self._state = StateUngrabbed
        sendKeyEvent(self._keyCode, false)
        self:setColor(_color_inactive)
        --print('TouchKey: sendKeyEvent true.')
    end
    setInactive()
    self._setActive = setActive
    self._setInactive = setInactive
    listener:registerScriptHandler(function(touch, event)
        if self._touchId ~= nil then return false end
        local loc = touch:getLocation()
        if self._isLock then
            if not self:containsTouchLocation(loc.x, loc.y) then
                return false
            end
            if self._state == StateUngrabbed then
                setActive()
            else
                setInactive()
            end
        else
            if (self._state ~= StateUngrabbed) then
                return false
            end
            if not self:containsTouchLocation(loc.x, loc.y) then
                return false
            end
            setActive()
        end
        self._touchId = touch:getId()
        return true
    end, cc.Handler.EVENT_TOUCH_BEGAN)

    listener:registerScriptHandler(function(touch, event)
        self._touchId = nil
        if not self._isLock then
            setInactive()
        end
        return true
    end, cc.Handler.EVENT_TOUCH_ENDED)
    listener:registerScriptHandler(function()
        self._touchId = nil
        setInactive()
    end, cc.Handler.EVENT_TOUCH_CANCELLED)

    local eventDispatcher = self:getEventDispatcher()
    eventDispatcher:addEventListenerWithSceneGraphPriority(listener, self)
    self._listeners = { listener }
    for _, name in ipairs({ 'event_come_to_background', cc.Director.EVENT_PROJECTION_CHANGED }) do
        local reset = cc.EventListenerCustom:create(name, setInactive)
        eventDispatcher:addEventListenerWithSceneGraphPriority(reset, self)
        table.insert(self._listeners, reset)
    end
    if self._isLock then
        self:scheduleUpdateWithPriorityLua(function()
            self:update()
        end, 0)
    end
end

function TouchKey:setLockMode(isLock)
    self._isLock = isLock
end

function TouchKey:update()
    if not ext then
        return
    end
    if ext.pause_menu and self._isLock then
        self._isLock = false
        self._setInactive()
    elseif (not ext.pause_menu) and (not self._isLock) then
        self._isLock = true
    end
end

return TouchKey
