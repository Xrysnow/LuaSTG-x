local base = require('imgui.Widget')

---@class im.RadioButtonGroup:im.Widget
local M = class('im.RadioButtonGroup', base)

function M:ctor(labels, initIndex, sameLine)
    labels = labels or {}
    self._count = #labels
    self._labels = labels
    self._idx = initIndex or 1
    self._sameLine = sameLine and true or false
end

function M:getSelected()
    return self._idx
end

function M:setSelected(idx)
    self._idx = idx
    return self
end

function M:getLabel(idx)
    return self._labels[idx]
end

function M:setLabel(idx, str)
    if self._labels[idx] then
        self._labels[idx] = str
    end
    return self
end

function M:isSameLine()
    return self._sameLine
end

function M:setSameLine(b)
    self._sameLine = b
    return self
end

function M:getCount()
    return self._count
end

function M:setOnChange(f)
    self._onChange = f
end

function M:_handler()
    local ret
    for i = 1, self._count do
        ret = imgui.radioButton(self._labels[i], self._idx == i)
        if ret then
            self._idx = i
            if self._onChange then
                self:_onChange(i)
            end
        end
        if self._sameLine and i < self._count then
            imgui.sameLine()
        end
    end
end

return M
