local Base = require('cc.ui.property_input.common')
---@class editor.PropertyInputVec2:editor.PropertyInputBase
local M = class('editor.PropertyInputVec2', Base)
Base.vec2 = M
local vec2_size = cc.size(66, 24)

function M:ctor(param, subtitle)
    Base.ctor(self, param)
    self.type = 'vec2'
    --self:setContentSize(cc.size(320, 32))
    local dx = 92
    local yy = 18
    ---@type ccui.EditBox[]
    self._eb = {}
    for i = 1, 2 do
        local eb = self:_createEditBox(Base.InputMode.DECIMAL, vec2_size)
        eb:addTo(self):setAnchorPoint(cc.p(0, 0.5)):setPosition(cc.p(16 + (i - 1) * dx, yy))
        table.insert(self._eb, eb)
    end
    if subtitle then
        self.subtitle = {}
        for i = 1, 2 do
            local lb = self:_createTitle(subtitle[i] or '')
            lb:addTo(self):setAnchorPoint(cc.p(0, 0.5)):setPosition(cc.p((i - 1) * dx, yy))
            self.subtitle[i] = lb
        end
    end
    self:_reformat()
end

function M:_reformat()
    for i = 1, 2 do
        self:_reformatNumber(i, false, self.param.min, self.param.max)
    end
end

function M:getValue()
    local ret = {}
    for i = 1, 2 do
        table.insert(ret, tonumber(self:getString(i)) or 0)
    end
    return ret
end

function M:setValue(v)
    for i = 1, 2 do
        local val = tonumber(string.trim(v[i] or '')) or 0
        self._eb[i]:setText(tostring(val))
    end
    self:_reformat()
end

function M:getString(idx)
    if not idx then
        return string.format(
                '%s, %s',
                self._eb[1]:getText(),
                self._eb[2]:getText())
    else
        return self._eb[idx]:getText()
    end
end

function M:setString(idx, str)
    if not idx then
        local t = string.split(str, ',')
        for i = 1, 2 do
            local v, _ = string.trim(t[i] or '')
            v = tonumber(v) or 0
            self._eb[i]:setText(tostring(v))
        end
    else
        local v, _ = string.trim(str or '')
        v = tonumber(v) or 0
        self._eb[idx]:setText(tostring(v))
    end
    self:_reformat()
end

return M
