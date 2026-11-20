---
--- controller_ui.lua
---
--- Copyright (C) 2018-2020 Xrysnow. All rights reserved.
---


local TouchKey = require('cc.TouchKey')
local tk_bg = 'res/touchkey_bg.png'
local font = 'font/WenQuanYiMicroHeiMono.ttf'
--local glv = cc.Director:getInstance():getOpenGLView()

local function createKeys(parent)
    cc.Image:setPNGPremultipliedAlphaEnabled(true)
    local tex = cc.Director:getInstance():getTextureCache():addImage(tk_bg)
    cc.Image:setPNGPremultipliedAlphaEnabled(false)

    local size = cc.Director:getInstance():getOpenGLView():getDesignResolutionSize()
    local scale_pos = math.min(size.x / 640, size.y / 480)
    local scale_size = scale_pos * 0.65
    local fontsize = scale_size * 18

    local xx = size.x / scale_pos
    local pESCAPE = cc.pMul(cc.p(xx - 135, 135), scale_pos)
    local pSHIFT = cc.pMul(cc.p(xx - 56, 56), scale_pos)
    local pX = cc.pMul(cc.p(xx - 56, 160), scale_pos)
    local pZ = cc.pMul(cc.p(xx - 150, 56), scale_pos)

    local tk_sc = 0.8 * scale_size
    local k5, k6, k7, k8 = KEY.ESCAPE, KEY.SHIFT, KEY.X, KEY.Z
    if setting then
        k5, k6, k7, k8 = setting.keysys.menu, setting.keys.slow, setting.keys.spell, setting.keys.shoot
    end

    local bt5 = cc.SetNode(TouchKey:create(tex, k5), parent, pESCAPE, tk_sc * 0.9)
    local bt6 = cc.SetNode(TouchKey:create(tex, k6), parent, pSHIFT, tk_sc * 1.4)
    local bt7 = cc.SetNode(TouchKey:create(tex, k7), parent, pX, tk_sc * 1.2)
    local bt8 = cc.SetNode(TouchKey:create(tex, k8, true), parent, pZ, tk_sc)

    local color = cc.c3b(255, 255, 0)
    local color_outline = cc.c4b(0, 0, 0, 255)

    local function addLabel(text, position, size)
        local label
        if lstg.GetPlatform() == 'ios' then
            -- UIKit draws the glyph and its outline together using the bundled font.
            label = cc.Label:createWithSystemFont(text, font, size)
        else
            label = cc.Label:createWithTTF(text, font, size)
        end
        cc.SetNode(label, parent, position, nil, color):enableOutline(color_outline, 1)
    end
    addLabel("ESC", pESCAPE, fontsize)
    addLabel("SHIFT", pSHIFT, fontsize * 0.8)
    addLabel("X", pX, fontsize)
    addLabel("Z", pZ, fontsize)

    local stick = require('platform.controller_stick')
    local keys = { setting.keys.up, setting.keys.right, setting.keys.down, setting.keys.left }
    local pos = cc.pMul(cc.p(106, 106), scale_pos)
    stick = stick:create(keys, pos, scale_size)
    cc.SetNode(stick, parent, pos)
end

local function CreateControllerUI(parent)
    local keys = cc.Node:create()
    parent:addChild(keys)
    local width, height
    local function layout()
        local size = cc.Director:getInstance():getOpenGLView():getDesignResolutionSize()
        if size.x ~= width or size.y ~= height then
            width, height = size.x, size.y
            keys:removeAllChildren()
            createKeys(keys)
        end
    end
    layout()
    keys:scheduleUpdateWithPriorityLua(layout, 0)
    return keys
end

return CreateControllerUI
