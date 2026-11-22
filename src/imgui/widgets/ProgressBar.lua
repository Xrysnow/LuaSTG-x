local base = require('imgui.Widget')

---@class im.ProgressBar:im.Widget
local M = class('im.ProgressBar', base)

function M:ctor(...)
    base.ctor(self, ...)
end

function M:setFraction(fraction)
    self:setParam(1, fraction)
    return self
end

function M:getFraction()
    return self:getParam(1)
end

function M:setSize(size)
    self:setParam(2, imgui.size(size))
    return self
end

function M:getSize()
    return imgui.toccsize(self:getParam(2))
end

function M:setOverlay(overlay)
    self:setParam(3, overlay)
    return self
end

function M:getOverlay()
    return self:getParam(3)
end

function M:_handler()
    imgui.progressBar(unpack(self._param))
    base._handler(self)
end

return M
