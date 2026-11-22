local base = require('xe.input.ListBase')
---@class xe.input.TypeName:xe.input.ListBase
local M = class('xe.input.TypeName', base)
local im = imgui
local wi = require('imgui.Widget')
local watch_map = {
    enemycreate     = 'enemydefine',
    bosscreate      = 'bossdefine',
    bulletcreate    = 'bulletdefine',
    objectcreate    = 'objectdefine',
    lasercreate     = 'laserdefine',
    laserbentcreate = 'laserbentdefine',
    bossdefine      = 'bgdefine',
    reboundercreate = 'rebounder',
}

function M:ctor(node, idx)
    base.ctor(self, node, idx, 'type_name')
    local t = node:getType()
    local watch = watch_map[t]
    if not watch then
        self._value = ''
        self:addChild(function()
            im.textDisabled('Unknown type')
        end)
        return
    end
    local list = {}
    if t ~= 'bossdefine' then
        -- background type
        for k, v in pairs(require('xe.TreeHelper').watch[watch]) do
            assert(k.getAttrValue, ('invalid object in watch.%s: %s'):format(watch, getclassname(k)))
            local name = k:getAttrValue(1) or ''
            local tmp = name:match('^(.+):.+$')
            if tmp then
                table.insert(list, tmp)
            elseif name ~= '' then
                table.insert(list, name)
            end
        end
    else
        for k, v in pairs(require('xe.TreeHelper').watch[watch]) do
            assert(k.getAttrValue, ('invalid object in watch.%s: %s'):format(watch, getclassname(k)))
            local name = k:getAttrValue(1) or ''
            if name ~= '' then
                table.insert(list, name)
            end
        end
    end
    if #list == 0 then
        self._value = ''
        self:addChild(function()
            im.textDisabled('No available type name')
        end)
        return
    end
    self._list = list

    local map = {}
    for i, v in ipairs(list) do
        map[v] = i
    end
    local value = self:getEditValue()
    if not map[value] then
        value = node:getAttrValue(idx)
    end
    if not map[value] then
        require('xe.logger').log('use default type name', 'info')
        value = list[1]
    end
    self._value = value
    self._sel = map[value]

    local btn, selector
    btn = wi.Button('', function()
        if btn:getDir() == im.Dir.Down then
            btn:setDir(im.Dir.Up)
            selector:setVisible(true)
        else
            btn:setDir(im.Dir.Down)
            selector:setVisible(false)
        end
    end, im.Dir.Down, 'arrow')
    selector = wi.Widget(function()
        self:_render()
    end)
    selector:setVisible(false)
    self:addChild(btn):addChild(im.sameLine):addChild(function()
        im.text(self._value)
    end):addChild(selector)
end

function M:_render()
    local last = self._sel
    self:_renderList(self._list)
    local sel = self._sel
    if sel ~= last then
        self._value = self._list[sel]
        self:submit()
    end
end

return M
