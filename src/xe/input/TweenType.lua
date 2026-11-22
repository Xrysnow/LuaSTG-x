local base = require('xe.input.Base')
---@class xe.input.TweenType:xe.input.Base
local M = class('xe.input.TweenType', base)
local im = imgui
local wi = require('imgui.Widget')
local items1 = {}
local items2 = { 'In', 'Out', 'InOut' }
local _map1 = {}
for k, v in pairs(math.tween) do
    if k ~= 'linear' then
        _map1[k:match('^[a-z]+')] = true
    end
end
for k, v in pairs(_map1) do
    table.insert(items1, k)
end
table.sort(items1)
table.insert(items1, 1, 'linear')

function M:ctor(node, idx)
    base.ctor(self, node, idx, 'tween_type')

    local value = self:getEditValue()
    if not math.tween[value] then
        value = node:getAttrValue(idx) or ''
        if not math.tween[value] then
            value = 'linear'
        end
    end
    self._value = value

    local map1 = {}
    for i, v in ipairs(items1) do
        map1[v] = i
    end
    local map2 = {}
    for i, v in ipairs(items2) do
        map2[v] = i
    end

    if value == 'linear' then
        self._sel1 = 1
        self._sel2 = 1
        self._v1 = 'linear'
        self._v2 = ''
    else
        local p1, p2 = value:find('^[a-z]+')
        local sub1 = value:sub(p1, p2)
        local sub2 = value:sub(p2 + 1)
        self._sel1 = map1[sub1] or 2
        self._sel2 = map2[sub2] or 1
        self._v1 = sub1
        self._v2 = sub2
    end

    local sel2 = wi.Combo('', items2, self._sel2)
    sel2:setOnChange(function(_, _, ii)
        self._sel2 = ii
        if self._sel1 == 1 then
            return
        end
        self._v2 = items2[ii]
        self._value = self._v1 .. self._v2
        self:submit()
    end)

    local ext = wi.Widget()
    ext:addChild(function()
        im.nextColumn()
        im.nextColumn()
        im.setNextItemWidth(-1)
    end):addChild(sel2)

    local sel1 = wi.Combo('', items1, self._sel1)
    sel1:setOnChange(function(_, _, ii)
        self._sel1 = ii
        if ii == 1 then
            ext:setVisible(false)
            self._sel2 = 1
            self._v1 = 'linear'
            self._v2 = ''
        else
            ext:setVisible(true)
            self._sel2 = 1
            self._v1 = items1[ii]
        end
        self._value = self._v1 .. self._v2
        self:submit()
    end)

    self:addChild(function()
        im.setNextItemWidth(-1)
    end):addChild(sel1):addChild(ext)
end

return M
