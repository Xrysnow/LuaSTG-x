--

---@type lstg.ResFont
local M = lstg.ResFont
local setRenderMode = getmetatable(M).setRenderMode

---
---@param mode lstg.RenderMode|string
---@return lstg.ResFont
function M:setRenderMode(mode)
    if type(mode) == 'string' then
        mode = lstg.RenderMode:getByName(mode)
    end
    return setRenderMode(self, mode)
end
