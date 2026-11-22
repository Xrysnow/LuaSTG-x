local base = require('imgui.Widget')

---@class im.ChildWindow:im.Widget
local M = class('im.ChildWindow', base)

function M:ctor(...)
    base.ctor(self, ...)
end

function M:setID(id)
    self:setParam(1, id)
end

function M:getID()
    return self:getParam(1)
end

function M:setContentSize(size)
    base.setContentSize(self, size)
    self:setParam(2, imgui.size(size))
    return self
end

function M:getContentSize()
    local sz = self:getParam(2)
    return cc.p(sz.x, sz.y)
end

function M:setBorder(b)
    self:setParam(3, b)
    return self
end

function M:getBorder()
    return self:getParam(3)
end

function M:setFlags(flag, ...)
    self:setParam(4, bit.bor(flag, ...))
    return self
end

function M:getFlags()
    return self:getParam(4)
end

function M:getPosition()
    local pos = self._pos_
    if pos then
        return cc.p(pos.x, pos.y)
    else
        return base.getPosition(self)
    end
end

function M:isAppearing()
    return self._Appearing
end

function M:setScrollX(x)
    self._scrx = x
end

function M:setScrollY(y)
    self._scry = y
end

function M:getScrollX()
    return self._scrx_ or 0
end

function M:getScrollY()
    return self._scry_ or 0
end

function M:getScrollMaxX()
    return self._scrmaxx_ or 0
end

function M:getScrollMaxY()
    return self._scrmaxy_ or 0
end

function M:setAutoScrollX(b)
    self._autoScrX = b
end

function M:setAutoScrollY(b)
    self._autoScrY = b
end

function M:_handler()
    imgui.pushID(tostring(self))
    local ret = { imgui.beginChild(unpack(self._param)) }
    self._ret = ret
    if ret[1] then
        --self._pos_ = imgui.getWindowPos()
        --self._size_ = imgui.getWindowSize()
        --self._Appearing = imgui.isWindowAppearing()
        --self._Collapsed = imgui.isWindowCollapsed()
        --self._Focused = imgui.isWindowFocused()
        --self._Hovered = imgui.isWindowHovered()

        -- scroll get
        self._scrmaxx_ = imgui.getScrollMaxX()
        self._scrmaxy_ = imgui.getScrollMaxY()
        -- scroll set
        if self._autoScrX then
            imgui.setScrollX(self._scrmaxx_)
        elseif self._scrx then
            imgui.setScrollX(self._scrx)
            self._scrx = nil
        end
        if self._autoScrY then
            imgui.setScrollY(self._scrmaxy_)
        elseif self._scry then
            imgui.setScrollY(self._scry)
            self._scry = nil
        end
        -- scroll get
        self._scrx_ = imgui.getScrollX()
        self._scry_ = imgui.getScrollY()

        base._handler(self)
    end
    imgui.endChild()
    imgui.popID()
end

return M
