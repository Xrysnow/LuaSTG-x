local base = require('imgui.Widget')

---@class im.Button:im.Widget
local M = class('im.Button', base)

function M:ctor(...)
    base.ctor(self, ...)
    local t = type(self:getParam(2))
    if t == 'number' then
        self:setStyleArrow()
    else
        self:setStyleNormal()
    end
end

function M:setStyleNormal()
    self._style = 'normal'
    if type(self:getParam(2)) ~= 'table' then
        self:setContentSize(cc.size(0, 0))
    end
    return self
end

function M:setStyleSmall()
    self._style = 'small'
    return self
end

function M:setStyleInvisible()
    self._style = 'invisible'
    if type(self:getParam(2)) ~= 'table' then
        self:setContentSize(base.getContentSize(self))
    end
    return self
end

function M:setStyleArrow()
    self._style = 'arrow'
    if type(self:getDir()) ~= 'number' then
        self:setDir(0)
    end
    return self
end

function M:setStyle(style)
    style = style or 'normal'
    if style == 'normal' then
        self:setStyleNormal()
    elseif style == 'small' then
        self:setStyleSmall()
    elseif style == 'invisible' then
        self:setStyleInvisible()
    elseif style == 'arrow' then
        self:setStyleArrow()
    end
end

function M:getStyle()
    return self._style
end

function M:_hasLabel()
    return self._style == 'normal' or self._style == 'small'
end

function M:_hasID()
    return self._style == 'invisible' or self._style == 'arrow'
end

function M:setLabel(label)
    if self:_hasLabel() then
        self:setParam(1, label)
    end
    return self
end

function M:getLabel()
    if self:_hasLabel() then
        return self:getParam(1)
    end
end

function M:setID(str_id)
    if self:_hasID() then
        self:setParam(1, str_id)
    end
    return self
end

function M:getID()
    if self:_hasID() then
        return self:getParam(1)
    end
end

function M:setContentSize(size)
    base.setContentSize(self, size)
    self:setParam(2, imgui.size(size))
    return self
end

function M:getContentSize()
    return imgui.toccsize(self:getParam(2))
end

function M:setDir(dir)
    if self._style == 'arrow' then
        self:setParam(2, dir)
    end
    return self
end

function M:getDir()
    if self._style == 'arrow' then
        return self:getParam(2)
    end
end

function M:setOnClick(f)
    self._onclick = f
    return self
end

function M:_handler()
    local ret
    imgui.pushID(tostring(self))
    if self._style == 'normal' then
        ret = { imgui.button(unpack(self._param)) }
    elseif self._style == 'small' then
        ret = { imgui.smallButton(self._param[1]) }
    elseif self._style == 'invisible' then
        ret = { imgui.invisibleButton(self._param[1], self._param[2]) }
    elseif self._style == 'arrow' then
        ret = { imgui.arrowButton(self._param[1], self._param[2]) }
    end
    imgui.popID()
    self._ret = ret
    if ret[1] and self._onclick then
        self:_onclick()
    end
    base._handler(self)
end

return M
