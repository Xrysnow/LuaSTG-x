local base = require('imgui.Widget')
---@class xe.ImageViewer:im.Widget
local M = class('xe.ImageViewer', base)
local im = imgui
local wi = base
local TITLE_DIVIDE = 'Divide'
local TITLE_ADDRECT = 'Add rect'

local function getBG()
    local data = ''
    data = data .. '\x33\x33\x33\xff'
    data = data .. '\x66\x66\x66\xff'
    data = data .. '\x66\x66\x66\xff'
    data = data .. '\x33\x33\x33\xff'
    local buf = lstg.Buffer:createFromString(data)
    -- Restricted Ref construction: research/lua-binding-convergence_2026-11-01/core/callers.md
    local img = cc.Image()
    if not img:initWithRawData(buf, 2, 2, 4) then
        return nil
    end
    -- Restricted Ref construction: research/lua-binding-convergence_2026-11-01/core/callers.md
    local tex = cc.Texture2D()
    if not tex:initWithImage(img) then
        return nil
    end
    tex:setTexParameters({
            minFilter = ccb.SamplerFilter.NEAREST,
            magFilter = ccb.SamplerFilter.NEAREST,
            sAddressMode = ccb.SamplerAddressMode.REPEAT,
            tAddressMode = ccb.SamplerAddressMode.REPEAT,
    })
    return cc.Sprite:createWithTexture(tex)
end

local function getIcons()
    local names = {
        "ActualSize",
        "AdjustWindowSize",
        "AutoZoom",
        "Checkerboard",
        "Convert",
        "Delete",
        --"Edit",
        "FlipHorz",
        "FlipVert",
        "FullScreen",
        "GoToFirst",
        "GoToImage",
        "GotoLast",
        "LockRatio",
        "Menu",
        "OpenFile",
        --"Print",
        "Refresh",
        "RotateLeft",
        "RotateRight",
        "ScaleToFill",
        "ScaleToFit",
        "ScaleToHeight",
        "ScaleToWidth",
        --"Slideshow",
        --"ThumbnailBar",
        --"ViewNextImage",
        --"ViewPreviousImage",
        --"ZoomIn",
        --"ZoomOut",
    }
    local cache = cc.Director:getInstance():getTextureCache()
    ---@type table<string,cc.Sprite>
    local ret = {}
    for i, v in ipairs(names) do
        local path = ('xe/iv/%s.png'):format(v)
        local tex = cache:addImage(path)
        --local sp = cc.Sprite:createWithTexture(tex, cc.rect(0, 0, tex:getPixelsWide(), tex:getPixelsHigh()))
        local sp = cc.Sprite:createWithTexture(tex)
        ret[v] = sp
    end
    return ret
end

function M:ctor(img_info)
    base.ctor(self)
    assert(img_info)
    -- path, name, sprite, size
    self._img = img_info
    --
    local icons = getIcons()
    self._icons = icons
    for k, v in pairs(icons) do
        self:addChild(v)
        v:setVisible(false)
    end

    -- rects are in texture coord
    self._rects = self._img.rects or {}
    self._img.rects = self._rects
    self._divide = { 0, 0, l = 0, r = 0, b = 0, t = 0, crop = false }
    self._clear_before_divide = true
    -- divide
    self._tool_divide_show = false
    local tool_divide = wi.Widget(function()
        self:_renderToolDivide()
    end)
    self:addChild(function()
        if im.imageButton(self._icons.Checkerboard) then
            self._tool_divide_show = true
            im.openPopup(TITLE_DIVIDE)
        end
        if im.isItemHovered() then
            im.setTooltip('Divide')
        end
    end)
    self:addChild(tool_divide)
    -- add rect
    self:addChild(im.sameLine)
    self._addrect = cc.rect(0, 0, 1, 1)
    self._tool_addrect_show = false
    local tool_addrect = wi.Widget(function()
        self:_renderToolAddRect()
    end)
    self:addChild(tool_addrect)
    self:addChild(function()
        if im.imageButton(self._icons.AdjustWindowSize) then
            self._tool_addrect_show = true
            im.openPopup(TITLE_ADDRECT)
        end
        if im.isItemHovered() then
            im.setTooltip('Add rect')
        end
    end)
    -- clear
    self:addChild(im.sameLine)
    self:addChild(function()
        if im.imageButton(self._icons.Refresh) then
            self:clearRects()
        end
        if im.isItemHovered() then
            im.setTooltip('Clear rects')
        end
    end)
    -- save
    --[[
    self:addChild(im.sameLine)
    self:addChild(function()
        if im.imageButton(self._icons.Convert) then
            self:_save()
        end
        if im.isItemHovered() then
            im.setTooltip('Save result')
        end
    end)
    --]]
    -- scale 1:1
    self:addChild(im.sameLine)
    self:addChild(function()
        if im.imageButton(self._icons.ActualSize) then
            self._img_sc = 1
        end
        if im.isItemHovered() then
            im.setTooltip('Scale to 1:1')
        end
    end)
    -- scale fit
    self:addChild(im.sameLine)
    self:addChild(function()
        if im.imageButton(self._icons.ScaleToFit) then
            self._img_sc = -2
        end
        if im.isItemHovered() then
            im.setTooltip('Scale to fit')
        end
    end)
    --
    local combo = wi.Combo('BG', { 'Grid', 'Black', 'White', 'Gray', 'None' }, 1)
    combo:setOnChange(function(_, s, idx)
        self._bg_type = s
    end)
    self:addChild(combo)
    -- show scale
    self:addChild(function()
        im.text(('scale: %.3f'):format(self._img_sc))
    end)
    --
    self:addChild(im.separator)
    --
    local bg = getBG()
    bg:setVisible(false):addTo(self)
    self._bg = bg
    self._img_sc = -1
    local canvas = wi.ChildWindow('xe.iv.canvas')
    canvas:addTo(self)
    canvas:addChild(function()
        self:_render()
    end)
    canvas:setFlags(im.WindowFlags.AlwaysHorizontalScrollbar)
end

function M:_setDivide()
    if self._clear_before_divide then
        self:clearRects()
    end
    local div = self._divide
    local col = math.round(div[1])
    local row = math.round(div[2])
    if row <= 0 or col <= 0 then
        return
    end
    local sz = self._img.size
    local w, h, xx, yy
    if div.crop then
        w = sz.x - div.l - div.r
        h = sz.y - div.t - div.b
        xx = div.l
        yy = div.t
    else
        w = sz.x
        h = sz.y
        xx = 0
        yy = 0
    end
    local ww = w / col
    local hh = h / row
    for c = 1, col do
        for r = 1, row do
            local rect = cc.rect(xx + (c - 1) * ww, yy + (r - 1) * hh, ww, hh)
            table.insert(self._rects, rect)
        end
    end
end

function M:clearRects()
    self._rects = {}
    self._img.rects = self._rects
end

function M:setBackgroundType(t)
    self._bg_type = t
end

function M:_render()
    local sz = self._img.size
    local wsz = im.getWindowSize()
    local scale = math.min(wsz.x / sz.x, wsz.y / sz.y)
    if self._img_sc == -1 then
        -- first set
        self._img_sc = math.min(scale, 1)
    elseif self._img_sc == -2 then
        self._img_sc = scale
    end
    self._img_sc = math.max(1 / 32, math.min(self._img_sc, 32))
    scale = self._img_sc
    sz = cc.pMul(sz, self._img_sc)

    local dx = (wsz.x - sz.x) / 2
    local dy = (wsz.y - sz.y) / 2
    local p = im.getCursorScreenPos()
    local a = cc.pAdd(p, cc.p(dx, dy))
    local b = cc.pAdd(a, sz)
    local dl = im.getWindowDrawList()
    -- background
    if self._bg_type == 'Black' then
        dl:addRectFilled(a, b, 0xff000000)
    elseif self._bg_type == 'White' then
        dl:addRectFilled(a, b, 0xffffffff)
    elseif self._bg_type == 'Gray' then
        dl:addRectFilled(a, b, 0xff7f7f7f)
    elseif self._bg_type == 'None' then
        --
    else
        dl:addImage(self._bg:getTexture(), a, b, cc.p(0, 0), cc.p(sz.x / 16, sz.y / 16))
    end
    -- image
    dl:addImage(self._img.sprite, a, b)

    for i, v in ipairs(self._rects) do
        local x, y, w, h = v.x, v.y, v.width, v.height
        local xx = x * scale + a.x
        local yy = y * scale + a.y
        dl:addRect(cc.p(xx, yy), cc.p(xx + w * scale, yy + h * scale), 0xff00ff00)
    end

    local scx, scy = im.getScrollMaxX(), im.getScrollMaxY()
    im.invisibleButton('iv.canvas.btn', cc.p(math.max(wsz.x, sz.x), math.max(wsz.y, sz.y)))
    if im.isItemHovered() then
        im.beginTooltip()
        im.text(('%d, %d'):format(scx, scy))
        im.endTooltip()
        local wheel = im.getIO().MouseWheel
        if wheel > 0 then
            self._img_sc = self._img_sc * 1.25
        elseif wheel < 0 then
            self._img_sc = self._img_sc * 0.8
        end
        self._img_sc = math.max(1 / 32, math.min(self._img_sc, 32))
    end
end

function M:_renderToolDivide()
    if not self._tool_divide_show then
        return
    end
    im.setNextWindowSize(cc.p(200, 300), im.Cond.Once)
    if im.beginPopupModal(TITLE_DIVIDE) then
        im.columns(2, tostring(self), false)
        local div = self._divide
        wi.propertyInput('Column', div, 1, { min = 0, int = true })
        wi.propertyInput('Row', div, 2, { min = 0, int = true })
        local w, h = self._img.size.x, self._img.size.y
        local l_max = w - div.r
        local r_max = w - div.l
        local t_max = h - div.b
        local b_max = h - div.t
        wi.propertyInput('Crop', div, 'crop')
        if div.crop then
            wi.propertyInput('Crop L', div, 'l', { min = 0, max = l_max, int = true })
            wi.propertyInput('Crop R', div, 'r', { min = 0, max = r_max, int = true })
            wi.propertyInput('Crop T', div, 't', { min = 0, max = t_max, int = true })
            wi.propertyInput('Crop B', div, 'b', { min = 0, max = b_max, int = true })
        end
        wi.propertyInput('Clear previous rects', self, '_clear_before_divide')
        im.columns(1)
        im.textWrapped('Note: This will clear all rects set before')
        if im.button('OK') then
            self:_setDivede()
            self._tool_divide_show = false
        end
        im.sameLine()
        if im.button('Cancel') then
            self._tool_divide_show = false
        end
        im.endPopup()
    end
end

function M:_renderToolAddRect()
    if not self._tool_addrect_show then
        return
    end
    im.setNextWindowSize(cc.p(200, 300), im.Cond.Once)
    if im.beginPopupModal(TITLE_ADDRECT) then
        im.columns(2, tostring(self), false)
        local rect = self._addrect
        local w, h = self._img.size.x, self._img.size.y
        wi.propertyInput('x', rect, 'x', { min = 0, max = w, int = true })
        wi.propertyInput('y', rect, 'y', { min = 0, max = h, int = true })
        wi.propertyInput('width', rect, 'width', { min = 1, int = true })
        wi.propertyInput('height', rect, 'height', { min = 1, int = true })
        im.columns(1)
        if im.button('OK') then
            table.insert(self._rects, rect)
            self._tool_addrect_show = false
        end
        im.sameLine()
        if im.button('Cancel') then
            self._tool_addrect_show = false
        end
        im.endPopup()
    end
end

function M:_save()
    local name = string.filename(self._img.name, false)
    return require('xe.image.util').saveRegions(self, self._img, self._rects, name)
end

return M
