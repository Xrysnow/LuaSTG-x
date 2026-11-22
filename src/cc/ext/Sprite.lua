---@type cc.Sprite
local Sprite = cc.Sprite

---
---@param b lstg.Buffer buffer which holds the image data.
---@return boolean true if loaded correctly.
function Sprite:createWithImageData(b)
    -- Restricted Ref construction: research/lua-binding-convergence_2026-11-01/core/callers.md
    local img = cc.Image()
    img:initWithImageData(b)
    -- Restricted Ref construction: research/lua-binding-convergence_2026-11-01/core/callers.md
    local tex = cc.Texture2D()
    tex:initWithImage(img)
    return cc.Sprite:createWithTexture(tex)
end

--- warning: only support RGBA8888
---@param b lstg.Buffer
---@param width number
---@param height number
---@param bitsPerComponent number
---@param preMulti boolean
---@return boolean
function Sprite:createWithRawData(b, width, height, bitsPerComponent, preMulti)
    -- Restricted Ref construction: research/lua-binding-convergence_2026-11-01/core/callers.md
    local img = cc.Image()
    img:initWithRawData(unpack({ b, width, height, bitsPerComponent, preMulti }))
    -- Restricted Ref construction: research/lua-binding-convergence_2026-11-01/core/callers.md
    local tex = cc.Texture2D()
    tex:initWithImage(img)
    return cc.Sprite:createWithTexture(tex)
end

--- clone sprite
---@return cc.Sprite
function Sprite:clone()
    return cc.Sprite:createWithSpriteFrame(self:getSpriteFrame())
end
