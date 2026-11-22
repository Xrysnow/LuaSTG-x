---@class lstg.mbg.PointF
local M = class('lstg.mbg.PointF')

function M:ctor(x, y)
    self.X = x or 0
    self.Y = y or 0
end

return M
