local base = require('xe.input.Base')
---@class xe.input.EnemyStyleEnum:xe.input.Base
local M = class('xe.input.EnemyStyleEnum', base)
local im = imgui
local wi = require('imgui.Widget')
local path = 'xe/enemy_style/'
local _num = 34
local types = {}
for i = 1, _num do
    types[i] = tostring(i)
    types[tostring(i)] = i
end

local styles = {}
for i = 1, 34 do
    if i <= 18 then
        -- animation
        table.insert(styles, ('enemy%d_1'):format(i))
    elseif i <= 22 then
        table.insert(styles, ('kedama%d'):format(i - 18))
    elseif i <= 26 then
        table.insert(styles, ('enemy_orb%d'):format(i - 22))
    elseif i == 27 or i == 31 then
        -- without and with aura
        table.insert(styles, 'ghost_fire_r')
    elseif i == 28 or i == 32 then
        table.insert(styles, 'ghost_fire_b')
    elseif i == 29 or i == 33 then
        table.insert(styles, 'ghost_fire_g')
    elseif i == 30 or i == 34 then
        table.insert(styles, 'ghost_fire_y')
    end
end

---@param node xe.SceneNode
function M:ctor(node, idx)
    base.ctor(self, node, idx, 'enemy_style')
    self:_loadImages()

    local value = node:getAttrValue(idx)
    if not types[value] then
        value = self:getEditValue() or types[1]
    end
    self._value = value
    self._sel = types[value]

    local btn = wi.Button('', function()
        im.openPopup('xe.input.EnemyStyleEnum')
    end, im.Dir.Down, 'arrow')
    self:addChild(btn)
    local _tint = im.vec4(1, 1, 1, 1)
    self:addChild(function()
        self:_render()
        im.sameLine()
        im.text(self._value)

        local n = self:_getImage(self._sel)
        if n and not self._popup then
            im.ccNode(n)
        end
    end)
end

function M:_render()
    self._popup = false
    --im.pushStyleColor(im.Col.Button, im.vec4(0, 0, 0, 1))
    if im.beginPopup('xe.input.EnemyStyleEnum') then
        self._popup = true
        if self:_renderTypeSelector() then
            im.closeCurrentPopup()
        end
        im.endPopup()
    end
    --im.popStyleColor()
end

function M:_renderTypeSelector(nCol)
    nCol = nCol or 5
    im.pushStyleVar(im.StyleVar.ItemSpacing, im.p(4, 4))
    local w = im.getWindowWidth()
    local spa = im.getStyle().ItemSpacing
    local spaw = spa.x
    local size = im.p(64, 64)
    if nCol == -1 then
        local count = math.floor((w - spaw) / (size.x + spaw))
        nCol = math.max(count, 1)
    end
    local dl = im.getWindowDrawList()

    local ret, any_ret
    local last = self._sel
    for i = 1, #types do
        local p = im.getCursorScreenPos()
        local center = cc.pAdd(p, cc.pMul(size, 1 / 2))
        im.pushID(i)
        ret = im.button('', size)
        if ret then
            self._sel = i
            any_ret = true
        end
        im.popID()
        self:_renderImage(i, dl, center)
        if self._sel == i then
            dl:addRect(p, cc.pAdd(p, size), im.getColorU32(im.Col.ButtonActive), 0, 0, 3)
        end
        if i % nCol ~= 0 and i < #types then
            im.sameLine()
        end
    end
    im.popStyleVar(1)
    if self._sel ~= last then
        self._value = types[self._sel]
        self:submit()
    end
    return any_ret
end

---@param drawList imgui.ImDrawList
function M:_renderImage(id, drawList, center, scale)
    scale = scale or 1
    local node = self:_getImage(id)
    if node then
        local sz = node:getContentSize()
        sz = im.p(sz.x, sz.y)
        local hsz = cc.pMul(sz, 1 / 2 * scale)
        local lt = cc.pSub(center, hsz)
        drawList:addCCNode(node, lt)
    end
end
---@return cc.Node
function M:_getImage(id)
    return self._img[id]
end

local cache = cc.Director:getInstance():getTextureCache()
function M:_loadImages()
    cc.Image:setPNGPremultipliedAlphaEnabled(false)
    local main = require('xe.main'):getInstance()
    local img = main._enemy_style
    if img then
        self._img = img
        return
    end
    img = {}
    self._img = img
    main._enemy_style = img
    ---@type cc.Sprite[]
    local tmp = {}
    local container = cc.Node:create()
    container:setVisible(false):addTo(main)
    local blendFunc = { src = ccb.BlendFactor.SRC_ALPHA, dst = ccb.BlendFactor.ONE_MINUS_SRC_ALPHA }

    for k, v in pairs(M._img) do
        local tex = cache:addImage(v.tex_path)
        local sp = cc.Sprite:createWithTexture(tex, cc.rect(v.x, v.y, v.w, v.h))
        sp:setVisible(false):addTo(container)
        sp:setBlendFunc(blendFunc)
        tmp[k] = sp
    end
    local function setRotation(node, r)
        node:runAction(cc.RepeatForever:create(cc.RotateBy:create(1 / 60, r)))
    end

    local _enemy_aura_tb = {
        1, 2, 3, 4, 3, 1, nil, nil, nil, 3, 1, 4, 1, nil, 3, 1, 2, 4,
        3, 1, 2, 4, 1, 2, 3, 4, nil, nil, nil, nil, 1, 3, 2, 1 }
    local function newAura(i)
        local idx = _enemy_aura_tb[i]
        if not idx then
            return
        end
        local sp = tmp['enemy_aura' .. idx]:clone()
        sp:setBlendFunc(blendFunc)
        sp:setOpacity(0x80)
        return sp
    end
    local function addAura(node, i)
        local aura = newAura(i)
        if aura then
            setRotation(aura, 3)
            aura:addTo(node):setLocalZOrder(-1):alignCenter()
            local ii = 0
            aura:scheduleUpdateWithPriorityLua(function()
                aura:setScale(1.25 + 0.15 * math.sin(ii * 6 / 180 * math.pi))
                ii = ii + 1
            end, 1)
        end
    end

    for i = 1, 18 do
        local frames = {}
        for j = 1, 4 do
            local name = ('enemy%d_%d'):format(i, j)
            local sp = assert(tmp[name])
            table.insert(frames, sp:getSpriteFrame())
        end
        local a = cc.Animation:createWithSpriteFrames(frames, 8 / 60)
        local name = ('enemy%d_%d'):format(i, 1)
        ---@type cc.Sprite
        local sp = assert(tmp[name])
        sp:runAction(cc.RepeatForever:create(cc.Animate:create(a)))
        addAura(sp, i)
        img[i] = sp
    end
    for i = 19, 22 do
        local name = 'kedama' .. (i - 18)
        ---@type cc.Sprite
        local sp = assert(tmp[name])
        addAura(sp, i)

        local node = cc.Node:create()
        local rect = sp:getTextureRect()
        node:addTo(container):setVisible(false):setContentSize(cc.p(rect.width, rect.height))
        sp:removeSelf():setVisible(true):addTo(node):alignCenter()
        setRotation(sp, 12)
        img[i] = node
    end
    for i = 23, 26 do
        local name = 'enemy_orb' .. (i - 22)
        local sp = assert(tmp[name])
        local node = cc.Node:create()
        local rect = sp:getTextureRect()
        node:addTo(container):setVisible(false):setContentSize(cc.p(rect.width, rect.height))
        sp:removeSelf():setVisible(true):addTo(node):alignCenter()

        setRotation(sp, 6)
        addAura(sp, i)
        img[i] = node

        local ring_name = 'enemy_orb_ring' .. _enemy_aura_tb[i]
        local ring = tmp[ring_name]
        local ring1 = ring:clone()
        local ring2 = ring:clone()
        setRotation(ring1, -6)
        setRotation(ring2, 4)
        ring2:setScale(1.4)
        ring1:setBlendFunc(blendFunc):addTo(node):setLocalZOrder(1):alignCenter()
        ring2:setBlendFunc(blendFunc):addTo(node):setLocalZOrder(2):alignCenter()
    end

    local parimg = cache:addImage('THlib/misc/particles.png')
    assert(parimg)
    local parimg1 = cc.Sprite:createWithTexture(parimg, cc.rect(0, 0, 32, 32))
    local res_parimg = lstg.ResSprite:createWithSprite('_', parimg1, 0, 0, 0)
    assert(res_parimg)
    ---@type lstg.ResParticle[]
    local ps = {}
    for k, v in pairs(M._ps) do
        local res = lstg.ResParticle:create(k, v.path, res_parimg, 0, 0, 0)
        assert(res, v.path)
        ps[k] = res
    end

    for style = 27, 34 do
        local name
        if style == 27 or style == 31 then
            name = 'ghost_fire_r'
        elseif style == 28 or style == 32 then
            name = 'ghost_fire_b'
        elseif style == 29 or style == 33 then
            name = 'ghost_fire_g'
        elseif style == 30 or style == 34 then
            name = 'ghost_fire_y'
        end
        local psys = ps[name]:newCocosParticle()

        --psys:setBlendFunc(blendFunc)

        local frames = {}
        local ii = style <= 30 and style - 26 or style - 30
        for i = 1, 8 do
            local spname = ('Ghost%d%d'):format(ii, i)
            table.insert(frames, tmp[spname]:getSpriteFrame())
        end
        local a = cc.Animation:createWithSpriteFrames(frames, 4 / 60)
        local spname = ('Ghost%d%d'):format(ii, 1)
        ---@type cc.Sprite
        local sp = tmp[spname]:clone()
        sp:setVisible(false):addTo(container)
        sp:runAction(cc.RepeatForever:create(cc.Animate:create(a)))
        sp:setBlendFunc(blendFunc)
        sp:setRotation(90)

        addAura(sp, style)
        psys:addTo(sp):setLocalZOrder(1):alignCenter()

        img[style] = sp
    end
end

--

local _tex = {}
local _img = {}
local _ps = {}
M._tex = _tex
M._img = _img
M._ps = _ps

local function LoadTexture(name, path)
    path = string.path_uniform(path)
    --local tex = cache:addImage(path)
    --assert(tex)
    _tex[name] = { path = path }
end
local function LoadImage(name, tex_name, x, y, w, h, a, b, colliType)
    local tex_path = assert(_tex[tex_name].path)
    _img[name] = {
        tex_path = tex_path, x = x, y = y, w = w, h = h, a = a, b = b, colliType = colliType
    }
end
local function LoadImageGroup(prefix, texname, x, y, w, h, cols, rows, a, b, rect)
    for i = 0, cols * rows - 1 do
        LoadImage(prefix .. (i + 1), texname,
                  x + w * (i % cols), y + h * (math.floor(i / cols)), w, h, a or 0, b or 0, rect or false)
    end
end
local function LoadPS(name, path, img_name, a, b, colliType)
    _ps[name] = {
        path = path, img_name = img_name, a = a, b = b, colliType = colliType,
    }
end
local function SetImageState()
end

--LoadTexture('particles', 'THlib\\misc\\particles.png')
--LoadImageGroup('parimg', 'particles', 0, 0, 32, 32, 4, 4)

LoadTexture('enemy1', 'THlib/enemy/enemy1.png')
--小妖精
LoadImageGroup('enemy1_', 'enemy1', 0, 384, 32, 32, 12, 1, 8, 8)--红
LoadImageGroup('enemy2_', 'enemy1', 0, 416, 32, 32, 12, 1, 8, 8)--绿
LoadImageGroup('enemy3_', 'enemy1', 0, 448, 32, 32, 12, 1, 8, 8)--蓝
LoadImageGroup('enemy4_', 'enemy1', 0, 480, 32, 32, 12, 1, 8, 8)--黄
--女仆妖精
LoadImageGroup('enemy5_', 'enemy1', 0, 0, 48, 32, 4, 3, 8, 8)--蓝
LoadImageGroup('enemy6_', 'enemy1', 0, 96, 48, 32, 4, 3, 8, 8)--红
--大妖精
LoadImageGroup('enemy7_', 'enemy1', 320, 0, 48, 48, 4, 3, 16, 16)--棕
LoadImageGroup('enemy8_', 'enemy1', 320, 144, 48, 48, 4, 3, 16, 16)--青
--大蝴蝶
LoadImageGroup('enemy9_', 'enemy1', 0, 192, 64, 64, 4, 3, 16, 16)--白

LoadImageGroup('kedama', 'enemy1', 256, 320, 32, 32, 2, 2, 8, 8)
LoadImageGroup('enemy_x', 'enemy1', 192, 32, 32, 32, 4, 1, 8, 8)

LoadImageGroup('enemy_orb', 'enemy1', 192, 64, 32, 32, 4, 1, 8, 8)
LoadImageGroup('enemy_orb_ring', 'enemy1', 192, 96, 32, 32, 4, 1)
for i = 1, 4 do
    SetImageState('enemy_orb_ring' .. i, 'add+add', Color(0xFF404040))
end
LoadImageGroup('enemy_aura', 'enemy1', 192, 32, 32, 32, 4, 1)
for i = 1, 4 do
    SetImageState('enemy_aura' .. i, '', Color(0x80FFFFFF))
end

LoadTexture('enemy2', 'THlib/enemy/enemy2.png')
--小妖精
LoadImageGroup('enemy10_', 'enemy2', 0, 0, 32, 32, 12, 1, 8, 8)--蓝
LoadImageGroup('enemy11_', 'enemy2', 0, 32, 32, 32, 12, 1, 8, 8)--红
LoadImageGroup('enemy12_', 'enemy2', 0, 64, 32, 32, 12, 1, 8, 8)--黄
LoadImageGroup('enemy13_', 'enemy2', 0, 96, 32, 32, 12, 1, 8, 8)--紫
--大蝴蝶
LoadImageGroup('enemy14_', 'enemy2', 0, 128, 64, 64, 6, 2, 16, 16)--黑
--小妖精
LoadImageGroup('enemy15_', 'enemy2', 0, 288, 32, 32, 12, 1, 8, 8)--蓝
LoadImageGroup('enemy16_', 'enemy2', 0, 352, 32, 32, 12, 1, 8, 8)--红
LoadImageGroup('enemy17_', 'enemy2', 0, 416, 32, 32, 12, 1, 8, 8)--绿
LoadImageGroup('enemy18_', 'enemy2', 0, 480, 32, 32, 12, 1, 8, 8)--黄

LoadPS('ghost_fire_r', 'THlib/enemy/ghost_fire_r.psi', 'parimg1', 8, 8)
LoadPS('ghost_fire_b', 'THlib/enemy/ghost_fire_b.psi', 'parimg1', 8, 8)
LoadPS('ghost_fire_g', 'THlib/enemy/ghost_fire_g.psi', 'parimg1', 8, 8)
LoadPS('ghost_fire_y', 'THlib/enemy/ghost_fire_y.psi', 'parimg1', 8, 8)

LoadTexture('enemy3', 'THlib/enemy/enemy3.png')
LoadImageGroup('Ghost1', 'enemy3', 0, 0, 32, 32, 8, 1, 8, 8)--红
LoadImageGroup('Ghost3', 'enemy3', 0, 32, 32, 32, 8, 1, 8, 8)--绿
LoadImageGroup('Ghost2', 'enemy3', 0, 64, 32, 32, 8, 1, 8, 8)--蓝
LoadImageGroup('Ghost4', 'enemy3', 0, 96, 32, 32, 8, 1, 8, 8)--黄

return M
