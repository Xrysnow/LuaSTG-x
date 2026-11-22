---@class ui.SplitViewV:ccui.Layout
local M = class('ui.SplitViewV', ccui.Layout)

function M:ctor(top, bottom, param)
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
    self._top = top
    ---@type ccui.Widget
    self._bottom = bottom
    if self._top then
        self._top:addTo(self)
    end
    if self._bottom then
        self._bottom:addTo(self)
    end
    self:setBackGroundColorType(1):setBackGroundColor(self.color)
    self._tparam = param.tparam or {}
    self._bparam = param.bparam or {}
    self:setContentSize(self.size)
end

function M:setTop(widget, param)
    CC_SET_PROP_CHILDREN(self, '_top', widget)
    if param then
        self._tparam = require('cc.ui.helper').parseConstrainParam(param)
    end
    self:updateLayout()
end

function M:setBottom(widget, param)
    CC_SET_PROP_CHILDREN(self, '_bottom', widget)
    if param then
        self._bparam = require('cc.ui.helper').parseConstrainParam(param)
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

function M:_setSize(th, bh, w)
    local xx = self.margin.l
    local yy = self.margin.t
    if self._top then
        self._top:setContentSize(cc.size(w, th)):alignLeft(xx):alignTop(yy)
    end
    yy = yy + th + self.margin.m
    if self._bottom then
        self._bottom:setContentSize(cc.size(w, bh)):alignLeft(xx):alignTop(yy)
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
    ww = ww - self.margin.l - self.margin.r
    hh = hh - self.margin.b - self.margin.t - self.margin.m
    if ww < 0 then
        ww = 0
    end
    if hh < 0 then
        hh = 0
    end
    local tpref = _to_px(self._tparam.preffered, ww)
    local bpref = _to_px(self._bparam.preffered, ww)
    local tmin = _to_px(self._tparam.min, ww) or tpref or 0
    local tmax = _to_px(self._tparam.max, ww) or tpref or ww
    local bmin = _to_px(self._bparam.min, ww) or bpref or 0
    local bmax = _to_px(self._bparam.max, ww) or bpref or ww
    if tpref then
        tpref = math.clamp(tpref, tmin, tmax)
    end
    if bpref then
        bpref = math.clamp(bpref, bmin, bmax)
    end
    local th, bh = require('cc.ui.helper').solveConstrain(hh, tpref, tmin, tmax, bpref, bmin, bmax)
    self:_setSize(th, bh, ww)
end

function M:updateLayout()
    self:setContentSize(self:getContentSize())
end

return M
