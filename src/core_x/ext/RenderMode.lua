---@type lstg.RenderMode
local RenderMode = lstg.RenderMode

local _default

function RenderMode:setAsDefault()
    _default = self:getName()
    return self
end

---@return lstg.RenderMode
function RenderMode:getDefault()
    return RenderMode:getByName(_default)
end

