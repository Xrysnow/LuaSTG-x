---@class lstg.mbg.EventRead
local M = {}
--local M = class('lstg.mbg.EventRead')

function M:ctor()
    self.rand = 0
    self.special = 0
    self.special2 = 0
    self.condition = ""
    self.result = ""
    self.condition2 = ""
    self.contype = 0
    self.contype2 = 0
    self.opreator = ""
    self.opreator2 = ""
    self.collector = ""
    self.change = 0
    self.changetype = 0
    self.changevalue = 0
    self.changename = 0
    self.res = 0
    self.times = 0
    self.time = 0
    self.noloop = false
end

function M:copy()
    local ret = M()
    for k, v in pairs(self) do
        ret[k] = v
    end
    return ret
end

local mt = {
    __call = function()
        local ret = {}
        M.ctor(ret)
        ret.copy = M.copy
        return ret
    end
}
setmetatable(M, mt)

return M
