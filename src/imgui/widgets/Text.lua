local base = require('imgui.Widget')

---@class im.Text:im.Widget
local M = class('im.Text', base)

function M:ctor(...)
    base.ctor(self, ...)
end

function M:setString(s)
    self:setParam(1, s)
    return self
end

---@return string
function M:getString()
    return self:getParam(1)
end

function M:setColor(color)
    self._color = color and imgui.color(color)
    return self
end

function M:getColor()
    return self._color and imgui.tocc4b(self._color)
end

function M:setDisabled(b)
    if b then
        self:setColor(imgui.getStyleColorVec4(imgui.ImGuiCol.TextDisabled))
    else
        self:setColor(imgui.getStyleColorVec4(imgui.ImGuiCol.Text))
    end
    return self
end

function M:setStyleNormal()
    self._style = 'normal'
    return self
end

function M:setStyleBullet()
    self._style = 'bullet'
    return self
end

function M:setStyleWrapped()
    self._style = 'wrapped'
    return self
end

function M:setStyleLabel(label)
    self._style = 'label'
    self._lb = label or ''
    return self
end

function M:setStyle(style)
    style = style or 'normal'
    if style == 'normal' then
        self:setStyleNormal()
    elseif style == 'bullet' then
        self:setStyleBullet()
    elseif style == 'wrapped' then
        self:setStyleWrapped()
    elseif style == 'label' then
        self:setStyleLabel()
    end
    return self
end

function M:setLabel(label)
    self:setStyleLabel(label)
    return self
end

function M:_handler()
    if self._color then
        imgui.pushStyleColor(imgui.ImGuiCol.Text, self._color)
    end
    local str = self:getString()
    if self._style == 'bullet' then
        imgui.bullet()
        imgui.textUnformatted(str)
    elseif self._style == 'wrapped' then
        imgui.pushTextWrapPos(0)
        imgui.textUnformatted(str)
        imgui.popTextWrapPos()
    elseif self._style == 'label' then
        --imgui.pushID(tostring(self))
        imgui.labelText(self._lb, str)
        --imgui.popID()
    else
        imgui.textUnformatted(str)
    end
    if self._color then
        imgui.popStyleColor()
    end
    base._handler(self)
end

return M
