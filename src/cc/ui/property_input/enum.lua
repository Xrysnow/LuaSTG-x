local Base = require('cc.ui.property_input.common')
---@class editor.PropertyInputEnum:editor.PropertyInputBase
local M = class('editor.PropertyInputEnum', Base)
Base.enum = M

function M:ctor(param, size)
    assert(param.enum)
    Base.ctor(self, param)
    self.type = 'enum'
    self.enum = param.enum
    local ddl = require('cc.ui.DropDownList').createBase(size.width, size.height, self.enum)
    ddl:addTo(self):setAnchorPoint(cc.p(0, 0.5)):setPosition(cc.p(0, 0))
    self._ddl = ddl
    self._str = {}
    for i, v in ipairs(self.enum) do
        self._str[tostring(v)] = i
    end
    self:_reformat()
end

function M:getString(idx)
    return self._ddl:getCurrentString()
end

function M:setString(idx, str)
    if not self._str[str] then
        return
    end
    self._ddl.button:setTitleText(str)
    self._ddl._cur = self._str[str]
    self:_reformat()
end

function M:getValue()
    return self.enum[self._ddl:getCurrentIndex()]
end

function M:setValue(v)
    self:setString(0, tostring(v))
end

return M
