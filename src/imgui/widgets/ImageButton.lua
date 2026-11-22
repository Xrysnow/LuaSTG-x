local base = require('imgui.Widget')

---@class im.ImageButton:im.Widget
local M = class('im.ImageButton', base)

function M:ctor(...)
    base.ctor(self, ...)
    local p1 = self._param[1]
    if iskindof(p1, 'cc.Sprite') then
        self._isTexture = false
    elseif iskindof(p1, 'cc.Texture2D') then
        self._isTexture = true
    else
        error('parameter #1 should be cc.Sprite or cc.Texture2D')
    end
end

function M:setTexCoord(uv0, uv1)
    if self._isTexture then
        if uv0 then
            self:setParam(3, uv0)
        end
        if uv1 then
            self:setParam(4, uv1)
        end
    end
    return self
end

function M:setFramePadding(v)
    local idx = self._isTexture and 5 or 3
    self:setParam(idx, v)
    return self
end

function M:getFramePadding(v)
    local idx = self._isTexture and 5 or 3
    return self:getParam(idx, v)
end

function M:setBgColor(v)
    local idx = self._isTexture and 6 or 4
    self:setParam(idx, v)
    return self
end

function M:getBgColor(v)
    local idx = self._isTexture and 6 or 4
    return self:getParam(idx, v)
end

function M:setTintColor(v)
    local idx = self._isTexture and 7 or 5
    self:setParam(idx, v)
    return self
end

function M:getTintColor(v)
    local idx = self._isTexture and 7 or 5
    return self:getParam(idx, v)
end

function M:setContentSize(size)
    base.setContentSize(self, size)
    self:setParam(2, imgui.size(size))
    return self
end

function M:getContentSize()
    return imgui.toccsize(self:getParam(2))
end

function M:setOnClick(f)
    self._onclick = f
    return self
end

function M:_handler()
    local ret
    imgui.pushID(tostring(self))
    ret = { imgui.imageButton(unpack(self._param)) }
    imgui.popID()
    self._ret = ret
    if ret[1] and self._onclick then
        self:_onclick()
    end
    base._handler(self)
end

return M
