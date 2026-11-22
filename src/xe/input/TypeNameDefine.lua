local base = require('xe.input.Base')
---@class xe.input.TypeNameDefine:xe.input.Base
local M = class('xe.input.TypeNameDefine', base)
local im = imgui
local wi = require('imgui.Widget')
local dif_list = { 'All', 'Easy', 'Normal', 'Hard', 'Lunatic' }
local dif_str = { '', 'Easy', 'Normal', 'Hard', 'Lunatic' }
for i = 2, #dif_str do
    dif_str[dif_str[i]] = i
end

function M:ctor(node, idx, extra)
    base.ctor(self, node, idx, 'type_define')
    local value = self:getEditValue()
    if value == '' then
        value = node:getAttrValue(idx) or ''
    end
    self._value = value
    local t1 = value:match('^(.+):.+$')
    local t2 = value:match('^.+:(.+)$') or ''
    if t1 and dif_str[t2] then
        self._name = t1
        self._dif = t2
    else
        self._name = value
        self._dif = ''
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
    input:setString(value):setWidth(-1)
    self:addChild(input)
    self:addChild(function()
        if im.isItemDeactivatedAfterEdit() then
            self._name = input:getString()
            self:_updateValue()
            self:submit()
        elseif im.isItemEdited() then
            self._name = input:getString()
            self:_updateValue()
            self:_setNodeValue()
            self:_checkValid()
        end
    end)

    local dif_sel = wi.Combo('', dif_list, dif_str[t2] or 1)
    dif_sel:setOnChange(function(_, _, ii)
        self._dif = dif_str[ii] or ''
        self:_updateValue()
        self:submit()
    end)
    self:addChild(dif_sel)
end

function M:_updateValue()
    if self._dif == '' then
        self._value = self._name
    else
        self._value = ('%s:%s'):format(self._name, self._dif)
    end
end

return M
