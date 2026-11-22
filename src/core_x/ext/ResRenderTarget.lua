--

---@type lstg.ResRenderTarget
local M = lstg.ResRenderTarget

---@see lstg.ResTexture
---@param minFilter number
---@param magFilter number gl.LINEAR gl.NEAREST
---@param wrapS number
---@param wrapT number gl.REPEAT gl.MIRRORED_REPEAT gl.CLAMP_TO_EDGE gl.CLAMP_TO_BORDER
function M:setTexParameters(minFilter, magFilter, wrapS, wrapT)
    lstg.ResTexture.setTexParameters(self, minFilter, magFilter, wrapS, wrapT)
end

