local base = require('imgui.Widget')

---@class im.Bullet:im.Widget
local M = class('im.Bullet', base)

function M:ctor(...)
    base.ctor(self, ...)
end

function M:_handler()
    imgui.bullet()
    base._handler(self)
end

return M
