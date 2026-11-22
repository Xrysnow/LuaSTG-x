local base = require('xe.input.ListBase')
---@class xe.input.ResImage:xe.input.ListBase
local M = class('xe.input.ResImage', base)
local im = imgui
local wi = require('imgui.Widget')

---@param node xe.SceneNode
function M:ctor(node, idx)
    base.ctor(self, node, idx, 'image')
    local imgonly = false
    local type = node:getType()
    if type == 'loadparticle' or type == 'bglayer' then
        imgonly = true
    end
    local list = {}
    if imgonly then
        for k, v in pairs(require('xe.TreeHelper').watch.image) do
            if k:getType() == 'loadimage' then
                local path = k:getAttrValue(1)
                local n = k:getAttrValue(2)
                local name = 'image:' .. n
                table.insert(list, { name, path })
            end
        end
    else
        for k, v in pairs(require('xe.TreeHelper').watch.image) do
            local ty = k:getType()
            local path = k:getAttrValue(1)
            local n = k:getAttrValue(2)
            if ty == 'loadimage' then
                local name = 'image:' .. n
                table.insert(list, { name, path })
            elseif ty == 'loadani' then
                local name = 'ani:' .. n
                table.insert(list, { name, path })
            elseif ty == 'loadparticle' then
                local name = 'particle:' .. n
                table.insert(list, { name, path })
            end
        end
    end
    table.sort(list, function(a, b)
        return a[1] < b[1]
    end)
    if #list == 0 then
        self._value = ''
        self:addChild(function()
            im.textDisabled('No available image')
        end)
        return
    end
    self._list = list

    local map = {}
    for i, v in ipairs(list) do
        map[v[1]] = { i, v[2] }
    end
    local value = self:getEditValue()
    if not map[value] then
        value = node:getAttrValue(idx)
    end
    if not map[value] then
        value = list[1][1]
    end
    self._value = value
    self._sel = map[value][1]
    self._path = map[value][2]

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
    local lst = {}
    for i, v in ipairs(self._list) do
        lst[i] = v[1]
    end
    self:_renderList(lst)
    local sel = self._sel
    if sel ~= last then
        self._value = self._list[sel][1]
        self._path = self._list[sel][2]
        self:submit()
    end
end

return M
