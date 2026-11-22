--
local M = {}

local MocVersion = {}
M.MocVersion = MocVersion

--- unknown
MocVersion.Unknown = 0
--- moc3 file version 3.0.00 - 3.2.07
MocVersion.V30 = 1
--- moc3 file version 3.3.00 - 3.3.03
MocVersion.V33 = 2
--- moc3 file version 4.0.00 -
MocVersion.V40 = 3

local BlendMode = {}
M.BlendMode = BlendMode

BlendMode.Normal = 0
BlendMode.Additive = 1
BlendMode.Multiplicative = 2

return M
