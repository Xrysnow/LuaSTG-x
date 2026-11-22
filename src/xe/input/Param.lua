local base = require('xe.input.Base')
---@class xe.input.Parameter:xe.input.Base
local M = class('xe.input.Parameter', base)
local im = imgui
local wi = require('imgui.Widget')
local _def_node_type = {
    enemydefine     = true,
    bulletdefine    = true,
    objectdefine    = true,
    laserdefine     = true,
    laserbentdefine = true,
    rebounderdefine = true
}
local _init_node_type = {
    enemyinit     = true,
    bulletinit    = true,
    objectinit    = true,
    laserinit     = true,
    laserbentinit = true,
    rebounderinit = true
}

function M:ctor(node, idx)
    base.ctor(self, node, idx, 'param')
    -- NOTE: param depends on type name of node
    self:addChild(function()
        self:_update()
    end)
    self:_update()
end

function M:_update()
    local tname = self._node:getAttrValue(1) or ''
    local diff = M._findDifficulty(self._node)

    ---@type xe.SceneNode
    local ret
    local root = require('xe.main').getEditor():getTree():getRoot()
    if diff then
        ret = M._findNodeByTypeName(root, tname .. ':' .. diff)
    end
    if not ret then
        ret = M._findNodeByTypeName(root, tname)
    end

    if ret == self._define then
        if not ret then
            local msg = tname == '' and 'Invalid type' or ('Invalid type %q'):format(tname)
            im.textDisabled(msg)
        end
        return
    end

    self._define = ret
    self:removeAllChildren()
    self:addChild(function()
        self:_update()
    end)

    local value = self:getEditValue()
    self._value = ''

    local names, values = {}, {}
    if ret then
        local split = require('xe.util').splitParam
        for _, v in ret:children() do
            if _init_node_type[v:getType()] then
                local def = split(v:getAttrValue(1))
                if #def == 0 then
                    local msg = 'No parameter'
                    self:addChild(function()
                        im.textDisabled(msg)
                    end)
                    return
                end
                local val = split(value)
                for i = 1, #def do
                    table.insert(names, def[i])
                    table.insert(values, val[i] or 'nil')
                end
                self._value = value
                break
            end
        end
    else
        local msg = tname == '' and 'Invalid type' or ('Invalid type %q'):format(tname)
        self:addChild(function()
            im.textDisabled(msg)
        end)
        return
    end

    self._val = values
    self:addChild(function()
        local msg = ('%d paramters'):format(#names)
        im.text(msg)
        im.nextColumn()
    end)

    self._inputs = {}
    for i = 1, #names do
        local label = '    ' .. names[i]
        local input = wi.InputText('', values[i], nil, -1)
        table.insert(self._inputs, input)
        self:addChild(function()
            wi.propertyHeader(label, self, '')
        end):addChild(im.nextColumn):addChild(input)
        self:addChild(function()
            if im.isItemDeactivatedAfterEdit() then
                self._val[i] = input:getString()
                self:_updateValue()
                self:submit()
            elseif im.isItemEdited() then
                self._val[i] = input:getString()
                self:_updateValue()
                self:_checkValid()
            end
        end)
        if i < #names then
            self:addChild(im.nextColumn)
        end
    end
end

function M:_updateValue()
    local val = {}
    for _, v in ipairs(self._val) do
        if v == '' then
            table.insert(val, 'nil')
        else
            table.insert(val, v)
        end
    end
    self._value = table.concat(val, ', ')
end

---@param node xe.SceneNode
function M._findDifficulty(node)
    -- get difficulty from parent define node
    while node do
        if node:isRoot() then
            break
        end
        local type = node:getType()
        if _def_node_type[type] then
            return string.match(node:getAttrValue(1), '^.+:(.+)$')
        elseif type == 'stagegroup' then
            return node:getAttrValue(1)
        end
        node = node:getParentNode()
    end
end

---@param node xe.SceneNode
function M._findNodeByTypeName(node, tname)
    if _def_node_type[node:getType()] then
        if node:getAttrValue(1) == tname then
            return node
        else
            return
        end
    else
        local ret
        for i = 1, node:getChildrenCount() do
            ret = M._findNodeByTypeName(node:getChildAt(i), tname)
            if ret then
                return ret
            end
        end
    end
end

return M
