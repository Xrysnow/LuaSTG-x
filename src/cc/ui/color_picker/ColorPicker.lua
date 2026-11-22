---@class ui.ColorPicker:ccui.Layout
local M = class('ui.ColorPicker', ccui.Layout)
local sz = cc.size(420, 512)
local path = 'ui/color_picker/'
local eb_sz = cc.size(52, 24)

function M:ctor(init_val, onConfirm, onCancel)
    init_val = init_val or cc.c4b(255, 255, 255, 255)
    self.c4b = init_val
    self:setContentSize(sz)
    self:setBackGroundColorType(1):setBackGroundColor(cc.c3b(63, 63, 63))

    local yy = sz.height
    local cir_w = ccui.Layout:create()
    cir_w:addTo(self):setContentSize(cc.size(256, 256)):setPosition(cc.p(50, yy - 220 - 128))
    --cir_w:setBackGroundColorType(1):setBackGroundColor(cc.c3b(0, 0, 127))
    cir_w:setTouchEnabled(true):setSwallowTouches(true)
    cir_w:addTouchEventListener(function(...)
        self:_onCircleTouch(...)
    end)
    self.cir_w = cir_w
    --cir_w:addClickEventListener(function()
    --    Print('click')
    --end)

    local cir = cc.Sprite:create(path .. 'hsv_circle.png')
    cir:addTo(cir_w):setScale(0.5):setPosition(cc.p(128, 128))
    self.cir = cir

    local hinter = cc.Sprite:create(path .. 'hinter.png')
    hinter:addTo(cir_w)
    self.cir_hinter = hinter

    self._rgb = require('cc.ui.color_picker.EditRGB')(eb_sz, std.bind(self._onRGBEdit, self))
    self._rgb:addTo(self):setPosition(40, 128)

    self._a = require('cc.ui.color_picker.EditAlpha')(eb_sz, std.bind(self._onAlphaEdit, self))
    self._a:addTo(self):setPosition(292, 128)

    self._sa = require('cc.ui.color_picker.SliderAlpha')(std.bind(self._onAlphaSlide, self))
    self._sa:addTo(self):setPosition(360, yy - 220)

    self._sg = require('cc.ui.color_picker.SliderGray')(std.bind(self._onBrightnessSlide, self))
    self._sg:addTo(self):setPosition(330, yy - 220)

    self._hex = require('cc.ui.color_picker.EditHex')(nil, std.bind(self._onHexEdit, self))
    self._hex:addTo(self):setPosition(40, 84)

    --self.lb = require('ui.label').create('_')
    --self.lb:addTo(self):setPosition(64, 300)
    self._pr = require('cc.ui.color_picker.Present')(init_val)
    self._pr:addTo(self):setPosition(48, yy - 72)

    self._cap = require('cc.ui.Caption')('Select Color', nil, sz.width, 22)
    self._cap:addTo(self):setPosition(0, sz.height - 22)

    self._onConfirm = onConfirm
    self._onCancel = onCancel
    self._bt1 = require('cc.ui.button').Button1(cc.size(71, 24), function()
        if self._onConfirm then
            self._onConfirm()
        end
    end)
    self._bt1:setTitleText('OK'):setTitleFontSize(16):addTo(self):setPosition(200, 24 + 20)

    self._bt2 = require('cc.ui.button').Button1(cc.size(71, 24), function()
        if self._onCancel then
            self._onCancel()
        end
    end)
    self._bt2:setTitleText('Cancel'):setTitleFontSize(16):addTo(self):setPosition(300, 24 + 20)

    self:syncValue()
end

function M:setOnConfirm(f)
    self._onConfirm = f
end

function M:setOnCancel(f)
    self._onCancel = f
end

function M:getBrightness()
    return self._sg:getValue()
end

function M:getAlpha()
    return self._sa:getValue()
end

function M:getValue()
    return self.c4b
end

function M:setValue(v)
    assert(v.a and v.r and v.g and v.b)
    self.c4b = v
    self:syncValue()
end

function M:syncValue()
    if self._sync then
        return
    end
    self._sync = true
    local c = self.c4b
    self._rgb:setValue(c)
    self._a:setValue(c.a)
    self._sa:setValue(c.a)
    self._sa:setHintColor(c)
    local hsv = color.toHSV(c)
    self._sg:setValue(hsv.v * 255)
    self:_setHinterPos(self:_calcHinterPosFromColor())
    self._hex:setValue(c)
    self._pr:setValue(c)
    --local str = string.format('%.1f, %.1f, %.1f, %.1f', c.a, c.r, c.g, c.b)
    --self.lb:setString(str)
    self._sync = false
end

function M:_setTransColor(c)
    self._sa:setHintColor(c)
end

function M:_onBrightnessSlide()
    local b = self:getBrightness()
    self.cir:setColor(cc.c3b(b, b, b))
    self.c4b = self:_calcColorFromHinterPos(self:_getHinterPos())
    self:syncValue()
end

function M:_onAlphaSlide()
    self.c4b.a = self:getAlpha()
    self:syncValue()
end

function M:_onHexEdit()
    self.c4b = self._hex:getValue()
    self:syncValue()
end

function M:_onRGBEdit()
    local c = self._rgb:getValue()
    for k, v in pairs(c) do
        assert(0 <= v and v <= 255, 'got ' .. v)
        self.c4b[k] = v
    end
    self:syncValue()
end

function M:_onAlphaEdit()
    self.c4b.a = self._a:getValue()
    self:syncValue()
end

local R = 128
local o = cc.p(R, R)

function M:_calcHinterPosFromColor()
    local c = color.toHSV(self.c4b)
    local d = c.s * R
    return cc.pMul(cc.pForAngle(c.h), d)
end

function M:_calcColorFromHinterPos(p)
    local th = math.atan2(p.y, p.x)
    if th < 0 then
        th = th + math.pi * 2
    end
    local r, g, b = color.fromHSV({ h = th, s = cc.pGetLength(p) / R, v = self:getBrightness() / 255 })
    r, g, b = color.normBytes(r * 255, g * 255, b * 255)
    return cc.c4b(r, g, b, self.c4b.a)
end

function M:_setHinterPos(p)
    if cc.pGetDistance(p, self:_getHinterPos()) < 1e-2 then
        return
    end
    self.cir_hinter:setPosition(cc.pAdd(p, o))
    self.c4b = self:_calcColorFromHinterPos(p)
    self:syncValue()
end

function M:_getHinterPos()
    local position = self.cir_hinter:getPosition()
    local x, y = position.x, position.y
    return cc.pSub(cc.p(x, y), o)
end

function M:_onCircleTouch(sender, event)
    local pos = sender:getTouchMovePosition()
    if event == ccui.TouchEventType.began then
        pos = sender:getTouchBeganPosition()
    elseif event == ccui.TouchEventType.moved then
        pos = sender:getTouchMovePosition()
    elseif event == ccui.TouchEventType.ended then
        pos = sender:getTouchEndPosition()
    end
    if pos then
        local p = self.cir_w:convertToNodeSpace(pos)
        local d = cc.pGetDistance(p, o)
        if d <= 128 then
            self:_setHinterPos(cc.pSub(p, o))
        else
            local dp = cc.pSub(p, o)
            local th = math.atan2(dp.y, dp.x)
            self:_setHinterPos(cc.pMul(cc.pForAngle(th), R))
        end
    end
end

function M:_createEditBox(size, min, max, cb)
    local eb = require('cc.ui.property_input.common').integer
    local ret = eb({ min = min, max = max }, size)
    if cb then
        table.insert(ret._eb.handler.ended, function()
            cb(ret:getValue())
        end)
    end
    ret._eb:setFontColor(cc.c3b(255, 255, 255))
    return ret
end

return M
