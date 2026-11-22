local base = require('imgui.Widget')

---@class im.SelectableGroup:im.Widget
local M = class('im.SelectableGroup', base)

function M:ctor(labels, current, flags, sizes)
    assert(#labels > 0)
    self._labels = labels
    self._cur = current
    self._flags = {}
    if flags then
        if type(flags) == 'number' then
            local t = {}
            for _ = 1, #labels do
                table.insert(t, flags)
            end
            self._flags = t
        else
            self._flags = flags
        end
    end
    self._sizes = {}
    if sizes then
        if #sizes == 0 then
            local t = {}
            for _ = 1, #labels do
                table.insert(t, sizes)
            end
            self._flags = t
        else
            self._flags = sizes
        end
    end
end

function M:setOnSelect(f)
    self._onsel = f
    return self
end

function M:_handler()
    for i = 1, #self._labels do
        imgui.pushID(tostring(self) .. i)
        local param = { self._labels[i], i == self._cur, self._flags[i], self._sizes[i] }
        if imgui.selectable(unpack(param)) then
            self._cur = i
            if self._onsel then
                self:_onsel(i)
            end
            self._ret = { i }
        end
        imgui.popID()
    end
    base._handler(self)
end

return M
