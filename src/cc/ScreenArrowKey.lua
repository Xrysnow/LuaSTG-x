local M = {}
local listener
local loc_begin
local loc_end
local keytosend
local keysent
M.LastMove = { x = 0, y = 0 }

local director = cc.Director:getInstance()
local function sendKeyEvent(keyCode, isPressed)
    -- Restricted Ref construction: research/lua-binding-convergence_2026-11-01/core/callers.md
    local e = cc.EventKeyboard:new(keyCode, isPressed)
    director:getRunningScene():getEventDispatcher():dispatchEvent(e)
end

local function sendKey(keyCode)
    if keytosend or keysent then
        return
    end
    keytosend = keyCode
    keysent = false
end

function M.start()
    if not listener then
        listener = cc.EventListenerTouchOneByOne:create()
        listener:setSwallowTouches(false)

        listener:registerScriptHandler(function(touch, event)
            local loc = touch:getLocation()
            loc_begin = loc
            return true
        end, cc.Handler.EVENT_TOUCH_BEGAN)

        listener:registerScriptHandler(function(touch, event)
            if not loc_begin then
                return false
            end
            local loc = touch:getLocation()
            loc_end = loc
            local dx, dy = loc_end.x - loc_begin.x, loc_end.y - loc_begin.y
            local adx, ady = math.abs(dx), math.abs(dy)
            if adx > 10 or ady > 10 then
                if adx > ady then
                    if dx > 0 then
                        sendKey(setting.keys.right)
                    else
                        sendKey(setting.keys.left)
                    end
                else
                    if dy > 0 then
                        sendKey(setting.keys.up)
                    else
                        sendKey(setting.keys.down)
                    end
                end
            end
            M.LastMove = { x = dx, y = dy }
            return true
        end, cc.Handler.EVENT_TOUCH_ENDED)

        local scene = director:getRunningScene()
        scene:getEventDispatcher():addEventListenerWithFixedPriority(listener, 1)

        scene:scheduleUpdateWithPriorityLua(function(dt)
            M.update()
        end, 0)
    end
end

function M.finish()
    if listener then
        director:getRunningScene():getEventDispatcher():removeEventListener(listener)
        listener = nil
        keytosend = nil
    end
end

function M.update()
    if keytosend then
        if not keysent then
            sendKeyEvent(keytosend, true)
            keysent = true
        else
            sendKeyEvent(keytosend, false)
            keytosend = nil
            keysent = false
        end
    end
end

return M
