--
local M = {}

local dir = cc.Director:getInstance()
local _running
local listeners = {}

local function process()
    if not _running then
        return
    end
    local cam = cc.Camera:getVisitingCamera() or dir:getRunningScene():getDefaultCamera()
    if not cam then
        return
    end
    local xx, yy = lstg.GetMousePosition()
    local p = cc.p(xx, yy)
    ---@param k ccui.Widget
    for k, v in pairs(listeners) do
        if k:hitTest(p, cam) then
            if v[1] then
                v[1]()
            end
        else
            if v[2] then
                v[2]()
            end
        end
    end
end

---@param attachNode cc.Node
function M.start(attachNode)
    attachNode:scheduleUpdateWithPriorityLua(function()
        process()
    end, 1)
    _running = true
end

function M.stop(attachNode)
    if attachNode then
        attachNode:unscheduleUpdate()
    end
    listeners = {}
    _running = false
end

function M.pause()
    _running = false
end

function M.resume()
    _running = true
end

function M.clear()
    listeners = {}
end

function M.addListener(widget, onHover, onUnhover)
    listeners[widget] = { onHover, onUnhover }
end

function M.removeListener(widget)
    listeners[widget] = nil
end

---@param widget ccui.Widget
function M.register(widget, onHover, onUnhover)
    widget:onNodeEvent('enter', function()
        M.addListener(widget, onHover, onUnhover)
    end)
    widget:onNodeEvent('exit', function()
        M.removeListener(widget)
    end)
end

return M
