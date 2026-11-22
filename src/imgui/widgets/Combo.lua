local base = require('imgui.Widget')

---@class im.Combo:im.Widget
local M = class('im.Checkbox', base)

function M:ctor(...)
    base.ctor(self, ...)
    self._items = {}
    self._cur = 0
end

function M:setLabel(label)
    self:setParam(1, label)
    return self
end

function M:getLabel()
    return self:getParam(1)
end

function M:setCurrent(v)
    if type(v) == 'number' then
        self:setParam(2, self._items[v])
        self._cur = v
    elseif type(v) == 'string' then
        self:setParam(2, v)
        self._cur = 0
        for i, item in ipairs(self._items) do
            if item == v then
                self._cur = i
            end
        end
    end
    return self
end

---@return string,number
function M:getCurrent()
    return self:getParam(2), self._cur
end

function M:setFlags(flag, ...)
    self:setParam(3, bit.bor(flag, ...))
    return self
end

function M:getFlags()
    return self:getParam(3)
end

function M:setItems(items)
    assert(type(items) == 'table')
    self._items = items
end

function M:getItems()
    return self._items
end

function M:setOnChange(f)
    self._onchange = f
    return self
end

function M:_handler()
    imgui.pushID(tostring(self))
    self._ret = { imgui.beginCombo(unpack(self._param)) }
    imgui.popID()
    if self._ret[1] then
        local n = #self._items
        local cur = 0
        for i = 1, n do
            local item = self._items[i]
            local is_selected = self._param[2] == item
            if imgui.selectable(item, is_selected) then
                self._param[2] = item
                cur = i
            end
            if is_selected then
                imgui.setItemDefaultFocus()
            end
        end
        -- 0 means no item or cancelled
        if cur ~= self._cur and cur ~= 0 then
            self._cur = cur
            if self._onchange then
                self:_onchange(self._param[2], cur)
            end
        end
        base._handler(self)
        imgui.endCombo()
    end
end

return M
