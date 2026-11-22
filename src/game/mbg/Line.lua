---@class lstg.mbg.Line
local M = class('lstg.mbg.Line')

function M:ctor(start, end_)
    local Pointf = require('game.mbg.PointF')
    self.Start = Pointf(start.X, start.Y)
    self.End = Pointf(end_.X, end_.Y)
end

return M
