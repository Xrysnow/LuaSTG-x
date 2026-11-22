local base = require('xe.input.Base')
---@class xe.input.BulletStyleEnum:xe.input.Base
local M = class('xe.input.BulletStyleEnum', base)
local im = imgui
local wi = require('imgui.Widget')
local cache = cc.Director:getInstance():getTextureCache()
--local img_path = 'xe/bullet_style/'

local styles = {
    'arrow_big', 'arrow_mid', 'arrow_small', 'gun_bullet', 'butterfly', 'square',
    'ball_small', 'ball_mid', 'ball_mid_c', 'ball_big', 'ball_huge', 'ball_light',
    'star_small', 'star_big', 'grain_a', 'grain_b', 'grain_c', 'kite', 'knife', 'knife_b',
    'water_drop', 'mildew', 'ellipse', 'heart', 'money', 'music', 'silence',
    'water_drop_dark', 'ball_huge_dark', 'ball_light_dark'
}
M._styles = styles
for i, v in ipairs(styles) do
    styles[v] = i
end
local colors = require('xe.input.ColorEnum')._colors
local style_desc = require('xe.node.bullet_desc')

---@param node xe.SceneNode
function M:ctor(node, idx)
    base.ctor(self, node, idx, 'bullet_style')
    self:_loadImage()

    local value = node:getAttrValue(idx, self._type)
    if not styles[value] then
        value = self:getEditValue()
        if not styles[value] then
            value = styles[1]
        end
    end

    self._value = value
    self._sel = styles[value]
    if node:getAttrCount() > idx and node:getAttrType(idx + 1) == 'color' then
        -- enable dynamic color if next attr is color
        self._color = colors[node:getAttrValue(idx + 1)] or 1
    end

    local btn = wi.Button('', function()
        im.openPopup('xe.input.BulletStyleEnum')
    end, im.Dir.Down, 'arrow')
    self:addChild(btn)
    local _tint = im.vec4(1, 1, 1, 1)
    self:addChild(function()
        self:_updateColor()
        self:_render()
        im.sameLine()
        im.text(self._value)

        local sp = self:_getImage(self._sel, self._color or 1)
        if sp then
            local rect = sp:getTextureRect()
            im.image(sp, im.vec2(rect.width, rect.height), _tint, im.getStyleColorVec4(im.Col.Border))
        end

        local info = M._img[self._value .. '1'] or M._ani[self._value .. '1']
        if info then
            local str
            if info.colliType then
                str = ('%s (%.1f, %.1f)'):format('Rectangle', info.a, info.b)
            else
                str = ('%s (%.1f)'):format('Circle', info.a)
            end
            im.nextColumn()
            wi.propertyHeader('Collision', self, '')
            im.nextColumn()
            im.text(str)
        end
    end)
end

function M:_loadImage()
    local main = require('xe.main'):getInstance()
    local img = main._bullet_style
    if not img then
        img = {}
        main._bullet_style = img
        for k, v in pairs(M._img) do
            local tex = cache:getTextureForKey(v.tex_path)
            local sp = cc.Sprite:createWithTexture(tex, cc.rect(v.x, v.y, v.w, v.h))
            sp:setVisible(false):addTo(main)
            img[k] = sp
        end
        for k, v in pairs(M._ani) do
            local tex = cache:getTextureForKey(v.tex_path)
            local sp = cc.Sprite:createWithTexture(tex, cc.rect(v.x, v.y, v.w, v.h))
            sp:setVisible(false):addTo(main)
            img[k] = sp
        end
    end
    self._img = img
end

function M:_render()
    if im.beginPopup('xe.input.BulletStyleEnum') then
        if self:_renderTypeSelector() then
            im.closeCurrentPopup()
        end
        im.endPopup()
    end
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
    for i = 1, #styles do
        local p = im.getCursorScreenPos()
        local center = cc.pAdd(p, cc.pMul(size, 1 / 2))
        im.pushID(i)
        ret = im.button('', size)
        if ret then
            self._sel = i
            any_ret = true
        end
        im.popID()
        self:_renderImage(i, self._color or 1, dl, center)
        if self._sel == i then
            dl:addRect(p, cc.pAdd(p, size), im.getColorU32(im.Col.ButtonActive), 0, 0, 3)
        end
        if i % nCol ~= 0 and i < #styles then
            im.sameLine()
        end

        if im.isItemHovered() then
            local desc = i18n(style_desc[styles[i]])
            if desc then
                im.setTooltip(desc)
            end
        end
    end
    im.popStyleVar(1)
    if self._sel ~= last then
        self._value = styles[self._sel]
        self:submit()
    end
    return any_ret
end

function M:_renderImage(tid, cid, drawList, center, scale)
    scale = scale or 1
    local sp = self:_getImage(tid, cid)
    if sp then
        local sz = sp:getTextureRect()
        sz = im.p(sz.width, sz.height)
        local hsz = cc.pMul(sz, 1 / 2 * scale)
        local lt = cc.pSub(center, hsz)
        local rb = cc.pAdd(center, hsz)
        drawList:addImage(sp, lt, rb)
    end
end
---@return cc.Sprite
function M:_getImage(tid, cid)
    local tname = styles[tid]
    if not self._img[tname .. '16'] then
        cid = math.floor((cid - 1) / 2) + 1
    end
    local name = ('%s%d'):format(tname, cid)
    return self._img[name]
end

function M:_updateColor()
    if not self._color then
        return
    end
    self._color = colors[self._node:getAttrValue(self._idx + 1)] or 1
end

--

local _tex = {}
local _img = {}
local _ani = {}
M._tex = _tex
M._img = _img
M._ani = _ani

local function LoadTexture(name, path)
    path = string.path_uniform(path)
    local tex = cache:addImage(path)
    assert(tex)
    _tex[name] = { tex, path }
end
local function LoadImage(name, tex_name, x, y, w, h, a, b, colliType)
    local tex = assert(_tex[tex_name][1])
    local tex_path = assert(_tex[tex_name][2])
    _img[name] = {
        tex = tex, tex_path = tex_path, x = x, y = y, w = w, h = h, a = a, b = b, colliType = colliType
    }
end
local function LoadImageGroup(prefix, texname, x, y, w, h, cols, rows, a, b, rect)
    for i = 0, cols * rows - 1 do
        LoadImage(prefix .. (i + 1), texname,
                  x + w * (i % cols), y + h * (math.floor(i / cols)), w, h, a or 0, b or 0, rect or false)
    end
end
local function LoadAnimation(name, tex_name, x, y, w, h, nCol, nRow, interval, a, b, colliType)
    local tex = assert(_tex[tex_name][1])
    local tex_path = assert(_tex[tex_name][2])
    _ani[name] = {
        tex  = tex, tex_path = tex_path, x = x, y = y, w = w, h = h, a = a, b = b, colliType = colliType,
        nCol = nCol, nRow = nRow, interval = interval,
    }
end
local function SetImageState()
end
local function SetImageCenter()
end

LoadTexture('bullet1', 'THlib\\bullet\\bullet1.png', true)
--发弹点 无判定
--LoadImageGroup('preimg', 'bullet1',
--               80, 0, 32, 32, 1, 8)
--鳞弹
LoadImageGroup('arrow_big', 'bullet1',
               0, 0, 16, 16, 1, 16, 2.5, 2.5)
--铳弹
LoadImageGroup('gun_bullet', 'bullet1',
               24, 0, 16, 16, 1, 16, 2.5, 2.5)
--铳弹（虚）
LoadImageGroup('gun_bullet_void', 'bullet1',
               56, 0, 16, 16, 1, 16, 2.5, 2.5)
--蝶弹
LoadImageGroup('butterfly', 'bullet1',
               112, 0, 32, 32, 1, 8, 4, 4)
--札弹
LoadImageGroup('square', 'bullet1',
               152, 0, 16, 16, 1, 16, 3, 3)
--小玉
LoadImageGroup('ball_mid', 'bullet1',
               176, 0, 32, 32, 1, 8, 4, 4)
--菌弹
LoadImageGroup('mildew', 'bullet1',
               208, 0, 16, 16, 1, 16, 2, 2)
--椭弹
LoadImageGroup('ellipse', 'bullet1',
               224, 0, 32, 32, 1, 8, 4.5, 4.5)

LoadTexture('bullet2', 'THlib\\bullet\\bullet2.png')
--星弹（小）
LoadImageGroup('star_small', 'bullet2',
               96, 0, 16, 16, 1, 16, 3, 3)
--星弹（大）
LoadImageGroup('star_big', 'bullet2',
               224, 0, 32, 32, 1, 8, 5.5, 5.5)
for i = 1, 8 do
    SetImageCenter('star_big' .. i, 15.5, 16)
end
--LoadImageGroup('ball_huge','bullet2',0,0,64,64,1,4,16,16)
--LoadImageGroup('fade_ball_huge','bullet2',0,0,64,64,1,4,16,16)
--中玉
LoadImageGroup('ball_big', 'bullet2',
               192, 0, 32, 32, 1, 8, 8, 8)
for i = 1, 8 do
    SetImageCenter('ball_big' .. i, 16, 16.5)
end
--点弹
LoadImageGroup('ball_small', 'bullet2',
               176, 0, 16, 16, 1, 16, 2, 2)
--米弹
LoadImageGroup('grain_a', 'bullet2',
               160, 0, 16, 16, 1, 16, 2.5, 2.5)
--针弹
LoadImageGroup('grain_b', 'bullet2',
               128, 0, 16, 16, 1, 16, 2.5, 2.5)

LoadTexture('bullet3', 'THlib\\bullet\\bullet3.png')
--刀弹
LoadImageGroup('knife', 'bullet3',
               0, 0, 32, 32, 1, 8, 4, 4)
--杆菌弹
LoadImageGroup('grain_c', 'bullet3',
               48, 0, 16, 16, 1, 16, 2.5, 2.5)
--链弹
LoadImageGroup('arrow_small', 'bullet3',
               80, 0, 16, 16, 1, 16, 2.5, 2.5)
--滴弹
LoadImageGroup('kite', 'bullet3',
               112, 0, 16, 16, 1, 16, 2.5, 2.5)
--伪激光
LoadImageGroup('fake_laser', 'bullet3',
               144, 0, 14, 16, 1, 16, 5, 5, true)
for i = 1, 16 do
    SetImageState('fake_laser' .. i, 'mul+add')
    SetImageCenter('fake_laser' .. i, 0, 8)
end

LoadTexture('bullet4', 'THlib\\bullet\\bullet4.png')
--10角星弹
LoadImageGroup('star_big_b', 'bullet4',
               32, 0, 32, 32, 1, 8, 6, 6)
--小玉b
LoadImageGroup('ball_mid_b', 'bullet4',
               64, 0, 32, 32, 1, 8, 4, 4)
for i = 1, 8 do
    SetImageState('ball_mid_b' .. i, 'mul+add', Color(200, 200, 200, 200))
end
--箭弹
LoadImageGroup('arrow_mid', 'bullet4',
               96, 0, 32, 32, 1, 8, 3.5, 3.5)
for i = 1, 8 do
    SetImageCenter('arrow_mid' .. i, 24, 16)
end
--心弹
LoadImageGroup('heart', 'bullet4',
               128, 0, 32, 32, 1, 8, 9, 9)
--刀弹b
LoadImageGroup('knife_b', 'bullet4',
               192, 0, 32, 32, 1, 8, 3.5, 3.5)
--环玉
for i = 1, 8 do
    LoadImage('ball_mid_c' .. i, 'bullet4',
              232, i * 32 - 24, 16, 16, 4, 4)
end
--钱币
LoadImageGroup('money', 'bullet4',
               168, 0, 16, 16, 1, 8, 4, 4)
--小玉d
LoadImageGroup('ball_mid_d', 'bullet4',
               168, 128, 16, 16, 1, 8, 3, 3)
for i = 1, 8 do
    SetImageState('ball_mid_d' .. i, 'mul+add')
end
-------ball_light--------
LoadTexture('bullet5', 'THlib\\bullet\\bullet5.png')
--光玉
LoadImageGroup('ball_light', 'bullet5',
               0, 0, 64, 64, 4, 2, 11.5, 11.5)
LoadImageGroup('fade_ball_light', 'bullet5',
               0, 0, 64, 64, 4, 2, 11.5, 11.5)
LoadImageGroup('ball_light_dark', 'bullet5',
               0, 0, 64, 64, 4, 2, 11.5, 11.5)
LoadImageGroup('fade_ball_light_dark', 'bullet5',
               0, 0, 64, 64, 4, 2, 11.5, 11.5)
for i = 1, 8 do
    SetImageState('ball_light' .. i, 'mul+add')
end
--------------------------
--------ball_huge---------
LoadTexture('bullet_ball_huge', 'THlib\\bullet\\bullet_ball_huge.png')
--大玉
LoadImageGroup('ball_huge', 'bullet_ball_huge',
               0, 0, 64, 64, 4, 2, 13.5, 13.5)
LoadImageGroup('fade_ball_huge', 'bullet_ball_huge',
               0, 0, 64, 64, 4, 2, 13.5, 13.5)
LoadImageGroup('ball_huge_dark', 'bullet_ball_huge',
               0, 0, 64, 64, 4, 2, 13.5, 13.5)
LoadImageGroup('fade_ball_huge_dark', 'bullet_ball_huge',
               0, 0, 64, 64, 4, 2, 13.5, 13.5)
for i = 1, 8 do
    SetImageState('ball_huge' .. i, 'mul+add')
end
--------------------------
--------water_drop--------
--炎弹 有动画
LoadTexture('bullet_water_drop', 'THlib\\bullet\\bullet_water_drop.png')
for i = 1, 8 do
    LoadAnimation('water_drop' .. i, 'bullet_water_drop',
                  48 * (i - 1), 0, 48, 32, 1, 4, 4, 4, 4)
    --SetAnimationState('water_drop' .. i, 'mul+add')
end
for i = 1, 8 do
    LoadAnimation('water_drop_dark' .. i, 'bullet_water_drop',
                  48 * (i - 1), 0, 48, 32, 1, 4, 4, 4, 4)
end
--------------------------
--------music-------------
--音符 有动画
LoadTexture('bullet_music', 'THlib\\bullet\\bullet_music.png')
for i = 1, 8 do
    LoadAnimation('music' .. i, 'bullet_music',
                  60 * (i - 1), 0, 60, 32, 1, 3, 8, 4, 4)
end
------silence-------------
LoadTexture('bullet6', 'THlib\\bullet\\bullet6.png')
--休止符
LoadImageGroup('silence', 'bullet6',
               192, 0, 32, 32, 1, 8, 4.5, 4.5)
--------------------------

return M
