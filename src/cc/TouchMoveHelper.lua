local M = {}
local listener
local loc_begin
local loc_end
--M.LastMove = { x = 0, y = 0 }
local tasks = {}

local director = cc.Director:getInstance()

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
            for k, v in pairs(tasks) do
                v(loc_begin, loc, dx, dy)
            end
            --M.LastMove = { x = dx, y = dy }
            return true
        end, cc.Handler.EVENT_TOUCH_ENDED)

        local scene = director:getRunningScene()
        scene:getEventDispatcher():addEventListenerWithFixedPriority(listener, 1)
    end
end

function M.addHandler(name, f)
    tasks[name] = f
end

function M.removeHandler(name)
    tasks[name] = nil
end

function M.finish()
    if listener then
        director:getRunningScene():getEventDispatcher():removeEventListener(listener)
        listener = nil
    end
end

return M
