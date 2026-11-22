local base = require('xe.ui.TreeNode')
---@class xe.AssetsNode:xe.ui.TreeNode
local M = class('xe.AssetsNode', base)
local im = imgui
local wi = require('imgui.Widget')

function M:ctor(attr)
    base.ctor(self)
    self:_updateAttr(attr)

    self:setOnSelect(function()
        self:getView():onSelChanged(self)
    end)
    self:setOnUnselect(function()
        self:getView():onSelChanged(nil)
    end)
    self:setOnDelete(function()
        self:getView():onSelChanged(nil)
    end)

    --TODO: right click
end

function M:getType()
    return self._type
end

function M:getID()
    return self._attr._id
end
function M:getPath()
    return self._attr.path
end

function M:_setString()
    local icon = self._attr.icon or ''
    local name = self._attr.name or 'N/A'
    self:setLabel(('%s  %s'):format(icon, name))
end

function M:renderPropery()
    im.text(('Info: %s'):format(self._type:capitalize()))
    im.separator()
    im.columns(2, 'xe.assets.property')

    wi.propertyConst('Name', self._attr.name)
    wi.propertyConst('Path', self._attr.path)

    wi.propertyConst('Mod time', self._mod_str)

    if self._type ~= 'directory' then
        wi.propertyConst('Size', self._size_str)
    end

    self:_renderProperty()

    im.columns(1)
end

function M:openFile()
    local path = self:getPath()
    local ext = string.fileext(path)
    -- ignore project file
    if ext:starts_with('lstgx') or ext == 'luastg' then
        return
    end

    local cmd
    local target = cc.Application:getInstance():getTargetPlatform()
    local fu = cc.FileUtils:getInstance()
    if target == cc.PLATFORM_OS_WINDOWS then
        cmd = ('start %s'):format(fu:getSuitableFOpen(path))
    elseif target == cc.PLATFORM_OS_MAC then
        cmd = ('open %s'):format(path)
    elseif target == cc.PLATFORM_OS_IPHONE or target == cc.PLATFORM_OS_IPAD then
        cmd = ('open %s'):format(path)
    elseif target == cc.PLATFORM_OS_ANDROID then
        cmd = ''
    else
        cmd = ('xdg-open %s'):format(path)
    end
    os.execute(cmd)
end

function M:_renderProperty()
end

function M:_updateAttr(t)
    self._attr = t
    if t.mode == 'directory' then
        self._type = 'directory'
    else
        self._type = t.res_type or 'file'
    end
    self:_setString()

    self._mod_str = os.date('%Y/%m/%d %H:%M:%S', self._attr.modification)

    local size = self._attr.size
    local size_str = ''
    if size >= 0x40000000 then
        size_str = ('%.2f GB (%d B)'):format(size / 0x40000000, size)
    elseif size >= 0x00100000 then
        local size_mb = size / 0x00100000
        if size_mb >= 100 then
            size_str = ('%.1f MB (%d B)'):format(size_mb, size)
        else
            size_str = ('%.2f MB (%d B)'):format(size_mb, size)
        end
    elseif size >= 0x0400 then
        local size_kb = size / 0x0400
        if size_kb >= 100 then
            size_str = ('%d KB (%d B)'):format(size_kb, size)
        else
            size_str = ('%.1f KB (%d B)'):format(size_kb, size)
        end
    else
        size_str = ('%d B'):format(size)
    end
    self._size_str = size_str
end

function M:_renderContextItem()
    self:select()
    local t = M._ctxItem
    if im.selectable(i18n(t.open)) then
        self:openFile()
    end
end

M._ctxItem = {
    open = {
        en = 'Open',
        zh = '打开',
    },
}

return M
