--
local base = require('imgui.widgets.Window')
---@class icp.AssetManager:im.Window
local M = class('icp.AssetManager', base)
local im = imgui
local wi = require('imgui.Widget')
local ins
---@return icp.AssetManager
function M:getInstance()
    ins = ins or M()
    return ins
end

function M:ctor()
    base.ctor(self, 'Asset Manager')
    self._imgs = {}
    self:addChild(wi.Button('add image', function()
        local director = cc.Director:getInstance()
        local scene = director:getRunningScene()
        require('xe.image.util').selectImages(function(paths)
            if director:getRunningScene() ~= scene or not self:isRunning() or not self:isVisible()
                or self:isOpen() == false then return end
            for _, path in ipairs(paths) do self:addImage(path) end
        end)
    end))
    self:addChild(im.sameLine)
    self:addChild(wi.Button('remove', function()
        if self._sel then
            self:removeImage(self._sel)
        end
    end))
    self:addChild(im.sameLine)
    self:addChild(wi.Button('remove all', function()
        self:removeAllImage()
    end))
    --
    self:addChild(function()
        self:_renderImages()
    end)
end

function M:addImage(path)
    local sp = cc.Sprite:create(path)
    if not sp then
        return false
    end
    for i = 1, #self._imgs do
        local v = self._imgs[i]
        if path == v.path then
            -- reload
            self:removeImage(i)
            break
        end
    end
    local fname = string.filename(path, true)
    local sz = sp:getTextureRect()
    sz = im.p(sz.width, sz.height)
    local t = {
        path   = path,
        name   = fname,
        index  = #self._imgs,
        sprite = sp,
        size   = sz
    }
    sp:retain()
    table.insert(self._imgs, t)
    return true
end

function M:removeImage(idx)
    if idx == self._sel then
        self:unselectImage()
    end
    local t = self._imgs[idx]
    require('icp.Editor'):getInstance():removeImage(t)
    table.remove(self._imgs, idx)
    t.sprite:release()
end

function M:removeAllImage()
    self:unselectImage()
    for _, v in ipairs(self._imgs) do
        v.sprite:release()
    end
    self._imgs = {}
end

function M:selectImage(idx)
    if idx == self._sel then
        return
    end
    self._sel = idx
    require('icp.Property'):getInstance():showImage(self._imgs[idx])
end

function M:unselectImage()
    if self._sel then
        require('icp.Property'):getInstance():reset()
    end
    self._sel = nil
end

function M:getImageCount()
    return #self._imgs
end

function M:_renderImages()
    local width = im.getWindowWidth()
    local size = im.p(96, 96)
    local space = im.getStyle().ItemSpacing
    local ncol = math.floor((width - space.x * 2) / (size.x + space.x * 2))
    if ncol > self:getImageCount() then
        ncol = self:getImageCount()
    end
    ncol = math.max(ncol, 1)
    local drawList = im.getWindowDrawList()
    im.separator()
    im.columns(ncol, self:getName() .. '.col', false)

    local ret, any_sel
    for i = 1, #self._imgs do
        local t = self._imgs[i]
        local p = im.getCursorScreenPos()
        im.pushID(i)
        ret = im.button('', size)
        if ret then
            self:selectImage(i)
            any_sel = true
        end
        im.popID()
        local center = cc.pAdd(p, cc.pMul(size, 0.5))
        local sz = t.size
        local scale = math.min(size.x / sz.x, size.y / sz.y)
        local hsz = cc.pMul(sz, scale / 2)
        local lt = cc.pSub(center, hsz)
        local rb = cc.pAdd(center, hsz)
        drawList:addImage(t.sprite, lt, rb)
        if self._sel == i then
            drawList:addRect(p, cc.pAdd(p, size), im.getColorU32(im.Col.ButtonActive), 0, 0, 3)
        end
        im.textWrapped(t.name)
        im.nextColumn()
    end
    im.columns(1)
    im.separator()
    return any_sel
end

return M
