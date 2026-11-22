local base = require('xe.input.Base')
---@class xe.input.String:xe.input.Base
local M = class('xe.input.String', base)
local im = imgui
local wi = require('imgui.Widget')

---@param node xe.SceneNode
function M:ctor(node, idx, extra)
    base.ctor(self, node, idx, 'string')
    local value = self:getEditValue()
    if value == '' then
        value = node:getAttrValue(idx) or ''
    end

    if extra then
        local icon = require('xe.ifont').Edit
        local btn = wi.Button(icon, function()
            require('xe.input.EditText').show(idx, node)
        end)
        self:addChild(btn):addChild(im.sameLine)
    end

    local input = require('imgui.widgets.InputText')('')
    self._input = input
    self:addChild(input)
    input:setString(value):setWidth(-1)
    self:addChild(function()
        if im.isItemDeactivatedAfterEdit() then
            self:submit()
        elseif im.isItemEdited() then
            self:_setNodeValue()
            self:_checkValid()
        end
    end)
end

function M:getValue()
    return self._input:getString()
end

function M:setValue(v)
    self._input:setString(v)
end

return M
