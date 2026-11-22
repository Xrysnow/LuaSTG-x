---@class ui.SplitViewH:ccui.Layout
local M = class('ui.SplitViewH', ccui.Layout)

function M:ctor(left, right, param)
    param = param or {}
    table.deploy(self, param, {
        color  = cc.WHITE,
        size   = cc.size(100, 100),
        margin = {
            l = 0,
            r = 0,
            b = 0,
            t = 0,
            m = 0 },
    })
    ---@type ccui.Widget
    self._left = left
    ---@type ccui.Widget
    self._right = right
    if self._left then
        self._left:addTo(self)
    end
    if self._right then
        self._right:addTo(self)
    end
    self:setBackGroundColorType(1):setBackGroundColor(self.color)
    self._lparam = param.lparam or {}
    self._rparam = param.rparam or {}
    self:setContentSize(self.size)
end

function M:setLeft(widget, param)
    CC_SET_PROP_CHILDREN(self, '_left', widget)
    if param then
        self._lparam = require('cc.ui.helper').parseConstrainParam(param)
    end
    self:updateLayout()
end

function M:setRight(widget, param)
    CC_SET_PROP_CHILDREN(self, '_right', widget)
    if param then
        self._rparam = require('cc.ui.helper').parseConstrainParam(param)
    end
    self:updateLayout()
end

function M:setMargin(l, r, b, t, m)
    l = l or 0
    r = r or l
    b = b or l
    t = t or l
    m = m or l
    self.margin = {
        l = l,
        r = r,
        b = b,
        t = t,
        m = m }
end

function M:_setSize(lw, rw, h)
    local xx = self.margin.l
    local yy = self.margin.t
    if self._left then
        self._left:setContentSize(cc.size(lw, h)):alignLeft(xx):alignTop(yy)
    end
    xx = xx + lw + self.margin.m
    if self._right then
        self._right:setContentSize(cc.size(rw, h)):alignLeft(xx):alignTop(yy)
    end
end

local function _to_px(val, total)
    if val and val <= 1 then
        return val * total
    end
    return val
end

---@param size size_table
function M:setContentSize(size)
    self.super.setContentSize(self, size)
    local measured = self.super.getContentSize(self)
    self.size = cc.size(measured.x, measured.y)
    local ww, hh = measured.x, measured.y
    ww = ww - self.margin.l - self.margin.r - self.margin.m
    hh = hh - self.margin.b - self.margin.t
    if ww < 0 then
        ww = 0
    end
    if hh < 0 then
        hh = 0
    end
    local lpref = _to_px(self._lparam.preffered, ww)
    local rpref = _to_px(self._rparam.preffered, ww)
    local lmin = _to_px(self._lparam.min, ww) or lpref or 0
    local lmax = _to_px(self._lparam.max, ww) or lpref or ww
    local rmin = _to_px(self._rparam.min, ww) or rpref or 0
    local rmax = _to_px(self._rparam.max, ww) or rpref or ww
    if lpref then
        lpref = math.clamp(lpref, lmin, lmax)
    end
    if rpref then
        rpref = math.clamp(rpref, rmin, rmax)
    end
    local lw, rw = require('cc.ui.helper').solveConstrain(ww, lpref, lmin, lmax, rpref, rmin, rmax)
    self:_setSize(lw, rw, hh)
    return self
end

function M:updateLayout()
    self:setContentSize(self:getContentSize())
end

return M
