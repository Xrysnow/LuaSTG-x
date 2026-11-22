---@class cc.Map
local M = class('cc.Map')

function M:ctor()
    self.___ = {}
end

function M:insert(k, ref)
    local old = self.___[k]
    if old then
        old:release()
    end
    if ref then
        ref:retain()
    end
    self.___[k] = ref
end

function M:at(k)
    return self.___[k]
end

function M:keys()
    local ret = {}
    for k, v in pairs(self.___) do
        table.insert(ret, k)
    end
    return ret
end

function M:values()
    local ret = {}
    for k, v in pairs(self.___) do
        table.insert(ret, v)
    end
    return ret
end

function M:clear()
    local keys = {}
    for k, _ in pairs(self.___) do
        table.insert(keys, k)
    end
    for _, v in ipairs(keys) do
        self.___[v]:release()
        self.___[v] = nil
    end
end

return M
