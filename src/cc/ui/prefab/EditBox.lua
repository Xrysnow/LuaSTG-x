---@class ui.EditBox:ccui.Widget
local M = class('ui.EditBox', ccui.Widget)
local common_size = cc.size(174, 24)
local _h = 32
local InputMode = {
    ---The user is allowed to enter any text, including line breaks.
    ANY           = 0,
    ---The user is allowed to enter an e-mail address.
    EMAIL_ADDRESS = 1,
    ---The user is allowed to enter an integer value.
    NUMERIC       = 2,
    ---The user is allowed to enter a phone number.
    PHONE_NUMBER  = 3,
    ---The user is allowed to enter a URL.
    URL           = 4,
    ---The user is allowed to enter a real number value.
    ---This extends kEditBoxInputModeNumeric by allowing a decimal point.
    DECIMAL       = 5,
    ---The user is allowed to enter any text, except for line breaks.
    SINGLE_LINE   = 6,
}
M.InputMode = InputMode

function M:ctor(param)
    self:setAnchorPoint(cc.p(0, 0.5))
    self.param = param or {}
    self.type = ''
end

function M:_reformat()
end

function M:_tonumber(idx)
    return tonumber(self:getString(idx))
end

function M:_checknumber(idx)
    local str = self:getString(idx)
    local val
    for i = #str, 1, -1 do
        val = tonumber(string.sub(str, 1, i))
        if val then
            break
        end
    end
    return val
end

function M:_reformatNumber(idx, isInt, min, max)
    local val = self:_checknumber(idx) or 0
    if isInt then
        val = math.floor(val)
    end
    if max then
        val = math.min(val, max)
    end
    if min then
        val = math.max(val, min)
    end
    self['_reformat'] = function()
    end
    self:setString(idx, tostring(val))
    self['_reformat'] = nil
end

function M:getValue()
end

function M:setValue(v)
end

function M:getString(idx)
    return ''
end

function M:setString(idx, str)
end

function M:_setEditBox(eb)
    require('cc.ui.handler').setEditBox(eb)
    table.insert(eb.handler.ended, function()
        self:_reformat()
    end)
end

function M:_createEditBoxBg()
    local input_bg = ccui.Scale9Sprite:create('editor/base_button_normal.png')
    input_bg:setCapInsets(cc.rect(2, 2, 28, 28))
    return input_bg
end

---@return ccui.EditBox
function M:_createEditBox(mode, size)
    local ret = ccui.EditBox:create(size or common_size, self:_createEditBoxBg())
    ret:setFontColor(cc.c3b(0, 0, 0))
    ret:setFont('Arial', 16)
    ret:setInputMode(mode)
    ret:setAnchorPoint(cc.p(0, 0.5))
    self:_setEditBox(ret)
    return ret
end

---@return cc.Label
function M:_createTitle(str)
    local ret = cc.Label:createWithSystemFont(str, 'Arial', 14)
    ret:setHorizontalAlignment(cc.TEXT_ALIGNMENT_LEFT)
    ret:setVerticalAlignment(cc.VERTICAL_TEXT_ALIGNMENT_CENTER)
    ret:setAnchorPoint(cc.p(0, 0.5))
    return ret
end

--

---@class ui.EditBoxFloat:ui.EditBox
local mFloat = class('ui.EditBoxFloat', M)

function mFloat:ctor(param, size)
    M.ctor(self, param)
    self.type = 'float'
    size = size or common_size
    self:setContentSize(size)
    local eb = self:_createEditBox(InputMode.DECIMAL, size)
    eb:addTo(self):setPosition(cc.p(0, size.height / 2))
    self._eb = eb
    self:_reformat()
end

function mFloat:_reformat()
    self:_reformatNumber(0, false, self.param.min, self.param.max)
end

function mFloat:getString(idx)
    return self._eb:getText()
end

function mFloat:setString(idx, str)
    self._eb:setText(str)
    self:_reformat()
end

function mFloat:getValue()
    return self:_tonumber(0)
end

function mFloat:setValue(v)
    v = tonumber(v) or 0
    self:setString(0, tostring(v))
end

---@param size size_table
---@param min number @optional
---@param max number @optional
---@return ui.EditBoxFloat
function M.Float(size, min, max)
    return mFloat({ min = min, max = max }, size)
end

--

---@class ui.EditBoxInteger:ui.EditBox
local mInteger = class('ui.EditBoxInteger', M)

function mInteger:ctor(param, size)
    M.ctor(self, param)
    self.type = 'integer'
    size = size or common_size
    self:setContentSize(size)
    local eb = self:_createEditBox(InputMode.NUMERIC, size)
    eb:addTo(self):setPosition(cc.p(0, size.height / 2))
    self._eb = eb
    self:_reformat()
end

function mInteger:_reformat()
    self:_reformatNumber(0, true, self.param.min, self.param.max)
end

function mInteger:getString(idx)
    return self._eb:getText()
end

function mInteger:setString(idx, str)
    self._eb:setText(str)
    self:_reformat()
end

function mInteger:getValue()
    return math.floor(self:_tonumber(0))
end

function mInteger:setValue(v)
    v = tonumber(v) or 0
    v = math.round(v)
    self:setString(0, tostring(v))
end

---@param size size_table
---@param min number @optional
---@param max number @optional
---@return ui.EditBoxInteger
function M.Integer(size, min, max)
    return mInteger({ min = min, max = max }, size)
end

--

---@class ui.EditBoxString:ui.EditBox
local mString = class('ui.EditBoxString', M)

function mString:ctor(param, size)
    M.ctor(self, param)
    self.type = 'string'
    size = size or common_size
    self:setContentSize(size)
    local eb = self:_createEditBox(InputMode.ANY, size)
    eb:addTo(self):setPosition(cc.p(0, size.height / 2))
    self._eb = eb
    self:_reformat()
end

function mString:getString(idx)
    return self._eb:getText()
end

function mString:setString(idx, str)
    if str == nil then
        str = ''
    end
    return self._eb:setText(tostring(str))
end

function mString:getValue()
    return self:getString(0)
end

function mString:setValue(v)
    self:setString(0, v)
end

---@param size size_table
---@return ui.EditBoxString
function M.String(size)
    return mString(nil, size)
end

--

---@class ui.EditBoxHex:ui.EditBox
local mHex = class('ui.EditBoxHex', M)

function mHex:ctor(param, size)
    M.ctor(self, param)
    self.type = 'hex'
    size = size or common_size
    self:setContentSize(size)
    local eb = self:_createEditBox(InputMode.SINGLE_LINE, size)
    eb:addTo(self):setPosition(cc.p(0, size.height / 2))
    self._eb = eb
    self:_reformat()
end

function mHex:_checknumber(idx)
    local str = '0x' .. self:getString(idx)
    local val
    for i = #str, 1, -1 do
        val = tonumber(string.sub(str, 1, i))
        if val then
            break
        end
    end
    return val
end

function mHex:_tonumber(idx)
    return tonumber('0x' .. self:getString(idx))
end

function mHex:_reformatNumber(idx, isInt, min, max)
    local val = self:_checknumber(idx) or 0
    if isInt then
        val = math.floor(val)
    end
    if max then
        val = math.min(val, max)
    end
    if min then
        val = math.max(val, min)
    end
    self['_reformat'] = function()
    end
    --Print(val)
    self:setString(idx, string.format('%08X', val))
    self['_reformat'] = nil
end

function mHex:_reformat()
    self:_reformatNumber(nil, true, self.param.min, self.param.max)
end

function mHex:getString(idx)
    return self._eb:getText()
end

function mHex:setString(idx, str)
    self._eb:setText(str)
    self:_reformat()
end

function mHex:getValue()
    return math.floor(self:_tonumber(0))
end

function mHex:setValue(v)
    v = tonumber(v) or 0
    v = math.round(v)
    self:setString(0, string.format('%08X', v))
end

---@param size size_table
---@return ui.EditBoxHex
function M.Hex(size)
    return mHex(nil, size)
end

return M
