local base = require('imgui.Widget')
---@class xe.NodePropertySetter:im.Widget
local M = class('xe.NodePropertySetter', base)
local im = imgui
local wi = base

---@param node xe.SceneNode
function M:ctor(node, idx)
    self._node = node
    self._idx = idx
    self._title = node:getAttrName(idx) or ''
    self._desc = node:getAttrDesc(idx)
    local t = node:getAttrType(idx)
    local types = require('xe.node.edit_type')[t]
    assert(types and #types > 0)
    self._types = types
    local type_items = {}
    ---@type xe.input.Base[]
    self._inputs = {}
    for _, v in ipairs(types) do
        if v == 'const' then
            for _, vv in ipairs(types.const) do
                assert(vv[1] and vv[2])
                local input = self:_createConst(vv[2])
                -- use type to identify different const
                input._type = vv[1]
                input:setVisible(false)
                table.insert(self._inputs, input)
                table.insert(type_items, vv[1])
            end
        else
            local input = self:_createInput(v)
            input:setVisible(false)
            table.insert(self._inputs, input)
            table.insert(type_items, v)
        end
    end
    local num = #self._inputs
    assert(num > 0)
    -- default edit type is saved in project
    self._cur = 1
    if num == 1 then
        self._inputs[1]:setVisible(true)
    else
        local cur_idx = self:_getCurIndex() or 1
        self._cur = cur_idx

        M._makeTypeItems(type_items)
        local edit_type_sel = wi.Combo('', type_items, self._cur):setFlags(im.ComboFlags.NoPreview)
        edit_type_sel:setOnChange(function(_, item, ii)
            if ii == 0 then
                return
            end
            self:_select(ii)
        end)
        self:addChild(edit_type_sel):addChild(im.sameLine)

        self._inputs[cur_idx]:setVisible(true)
    end
    for _, input in ipairs(self._inputs) do
        input:addTo(self)
    end
end

function M._makeTypeItems(items)
    -- xxx_xxx -> Xxx Xxx
    for i = 1, #items do
        local item = items[i]
        if item == 'string' then
            items[i] = 'Code'
        else
            local words = string.split(item, '_')
            for j = 1, #words do
                words[j] = string.capitalize(words[j])
            end
            items[i] = table.concat(words, ' ')
        end
    end
end

function M:getValue()
    return self._inputs[self._cur]:getValue()
end

function M:setValue(v)
    if v == nil then
        v = ''
    end
    return self._inputs[self._cur]:setValue(v)
end

function M:getString()
    local i = self._inputs[self._cur]
    local ret = i:getString()
    if i._type == 'string' then
        ret = string.format('%q', ret)
    end
    return ret
end

function M:setString(idx, str)
    self._inputs[self._cur]:setString(idx, str)
end

function M:getTitle()
    return self._title
end

function M:_select(idx)
    if self._cur == idx then
        return
    end
    for _, v in ipairs(self._inputs) do
        if v:isVisible() then
            v:setVisible(false)
        end
    end
    local input = self._inputs[idx]
    assert(input)
    input:setVisible(true)
    self._cur = idx
    -- submit here because inputs don't share values
    input:submit()
end

function M:_getCurIndex()
    local t = self._node:getAttrEditType(self._idx)-- or 'string'
    for i, v in ipairs(self._inputs) do
        if v:getType() == t then
            return i
        end
    end
end

function M:_createInput(t)
    -- NOTE: input only submit its value when edit finished
    local nt = self._node:getType()
    ---@type xe.input.Base
    local ret
    if t == 'path' then
        --TODO: loadFX
        ret = require('xe.input.Path')(self._node, self._idx, self._types[nt])
    elseif t == 'bool' then
        ret = require('xe.input.Bool')(self._node, self._idx)
    elseif t == 'color_enum' then
        ret = require('xe.input.ColorEnum')(self._node, self._idx)
    elseif t == 'bullet_style' then
        ret = require('xe.input.BulletStyleEnum')(self._node, self._idx)
    elseif t == 'enemy_style' then
        ret = require('xe.input.EnemyStyleEnum')(self._node, self._idx)
    elseif t == 'sound_effect' then
        ret = require('xe.input.ResSound')(self._node, self._idx)
    elseif t == 'image' then
        ret = require('xe.input.ResImage')(self._node, self._idx)
    elseif t == 'type_name' then
        ret = require('xe.input.TypeName')(self._node, self._idx)
    elseif t == 'type_define' then
        ret = require('xe.input.TypeNameDefine')(self._node, self._idx, true)
    elseif t == 'param' then
        ret = require('xe.input.Param')(self._node, self._idx)
    elseif t == 'vec2' then
        ret = require('xe.input.Vec2')(self._node, self._idx, self._types[t])
    elseif t == 'enum' then
        ret = require('xe.input.Enum')(self._node, self._idx, self._types[t])
    elseif t == 'code' then
        ret = require('xe.input.Code')(self._node, self._idx, self._types[t])
    elseif t == 'tween_type' then
        ret = require('xe.input.TweenType')(self._node, self._idx)
    else
        ret = require('xe.input.String')(self._node, self._idx, true)
    end
    ret._master = self
    -- submit here because init value may differ from current
    require('xe.SceneTree').submit()
    ret:_checkValid()
    return ret
end

function M:_createConst(v)
    local ret = require('xe.input.Const')(self._node, self._idx, v)
    ret._master = self
    require('xe.SceneTree').submit()
    return ret
end

function M:_handler()
    --TODO: tooltip
    local error
    local input = self._inputs[self._cur]
    if input then
        error = input:getError()
    end
    local desc = error or self._desc

    local pos1 = im.getCursorScreenPos()
    wi.propertyHeader(self._title, self, '', { tooltip = desc })
    im.nextColumn()
    wi._handler(self)
    local pos2 = im.getCursorScreenPos()
    im.nextColumn()

    if error then
        local dl = im.getWindowDrawList()
        dl:addRectFilled(pos1, pos2, im.color32(255, 0, 0, 63))
        self._error = true
    else
        self._error = false
    end
end

return M
