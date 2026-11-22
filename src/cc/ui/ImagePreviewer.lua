---@class ui.ImagePreviewer:ccui.Layout
local M = class('ui.ImagePreviewer', ccui.Layout)

function M:ctor(size)
    self.size = size or cc.size(128, 128)
    self:setContentSize(self.size)
    --self:setBackGroundColorType(1):setBackGroundColor(cc.c3b(255, 200, 200))

    local bg = cc.Sprite:create('ui/ImagePreviewer/bg.png')
    bg:setTextureRect(cc.rect(0, 0, self.size.width, self.size.height))
    bg:getTexture():setTexParameters({
        minFilter = ccb.SamplerFilter.LINEAR,
        magFilter = ccb.SamplerFilter.LINEAR,
        sAddressMode = ccb.SamplerAddressMode.REPEAT,
        tAddressMode = ccb.SamplerAddressMode.REPEAT,
    })
    bg:addTo(self):alignTop(0):alignLeft(0)
    self._bg = bg

    local wbg = require('cc.ui.sprite').White(self.size)
    wbg:addTo(self):alignCenter():setVisible(false)
    self._wbg = wbg
end

---@param sprite cc.Sprite
function M:showSprite(sprite)
    if self._sp then
        self._sp:removeSelf()
    end
    if sprite then
        sprite:addTo(self):alignCenter()
    end
    self._sp = sprite
    return self
end

function M:getSprite()
    return self._sp
end

function M:setBgGrid()
    self._wbg:setVisible(false)
    return self
end

function M:setBgColor(color)
    self._wbg:setColor(color):setVisible(true)
    return self
end

function M:setBgBlack()
    return self:setBgColor(cc.BLACK)
end

function M:setBgWhite()
    return self:setBgColor(cc.WHITE)
end

function M:reset()
    return self:showSprite(nil)
end

return M
