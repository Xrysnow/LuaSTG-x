local base = require('imgui.Widget')

---@class im.Window:im.Widget
local M = class('imgui.window', base)

function M:ctor(...)
    base.ctor(self, ...)
end

function M:setName(name)
    base.setName(self, name)
    self:setParam(1, name)
    return self
end

function M:setOpen(b)
    self:setParam(2, b)
    return self
end

function M:isOpen()
    return self:getParam(2)
end

function M:setFlags(flag, ...)
    self:setParam(3, bit.bor(flag, ...))
    return self
end

function M:getFlags()
    return self:getParam(3)
end

function M:setPosition(x, y)
    self._pos = cc.p(x, y)
    base.setPosition(self, x, y)
    return self
end

function M:getPosition()
    local pos = self._pos_
    if pos then
        return cc.p(pos.x, pos.y)
    else
        return base.getPosition(self)
    end
end

function M:setContentSize(size)
    self._size = imgui.size(size)
    base.setContentSize(self, size)
    return self
end

function M:getContentSize()
    local size = self._size_
    if size then
        return cc.p(size.x, size.y)
    else
        return base.getContentSize(self)
    end
end

function M:setCollapsed(b)
    self._collapsed = b
end

function M:setFocus()
    self._focus = true
end

function M:isAppearing()
    return self._Appearing
end

function M:setSizeConstraints(min, max)
    if not min or not max then
        self._sizeConstraints = nil
    else
        self._sizeConstraints = { min, max }
    end
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
    local imgui = imgui
    if self._pos then
        imgui.setNextWindowPos(self._pos)
        self._pos = nil
    end
    if self._size then
        imgui.setNextWindowSize(self._size)
        self._size = nil
    end
    if self._collapsed ~= nil then
        imgui.setNextWindowCollapsed(self._collapsed)
        self._collapsed = nil
    end
    if self._focus then
        imgui.setNextWindowFocus()
        self._focus = false
    end
    local cons = self._sizeConstraints
    if cons then
        imgui.setNextWindowSizeConstraints(cons[1], cons[2])
    end

    local ret = { imgui.begin(imgui.unpack(self._param)) }
    self._ret = ret
    if ret[1] then
        self._pos_ = imgui.getWindowPos()
        self._size_ = imgui.getWindowSize()
        self._Appearing = imgui.isWindowAppearing()
        self._Collapsed = imgui.isWindowCollapsed()
        self._Focused = imgui.isWindowFocused()
        self._Hovered = imgui.isWindowHovered()

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
    imgui.endToLua()
end

return M
