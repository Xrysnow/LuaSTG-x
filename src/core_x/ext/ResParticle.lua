--

local ParticlePool = getmetatable(lstg.ResParticle.ParticlePool)
local setRenderMode = ParticlePool.setRenderMode

---
---@param mode lstg.RenderMode|string
function ParticlePool:setRenderMode(mode)
    if type(mode) == 'string' then
        mode = lstg.RenderMode:getByName(mode)
    end
    return setRenderMode(self, mode)
end
