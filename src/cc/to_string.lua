---
--- to_string.lua
---
--- Copyright (C) 2018-2020 Xrysnow. All rights reserved.
---


function cc.p2str(p)
    return string.format('{x=%.2f, y=%.2f}', p.x, p.y)
end

function cc.size2str(size)
    return string.format('{w=%.2f, h=%.2f}', size.width, size.height)
end

function cc.rect2str(rect)
    return string.format('{x=%.2f, y=%.2f, w=%.2f, h=%.2f}',
                         rect.x, rect.y, rect.width, rect.height)
end

local function isFloatColor(c)
    return (c.r <= 1 and c.g <= 1 and c.b <= 1) and (math.ceil(c.r) ~= c.r or math.ceil(c.g) ~= c.g or math.ceil(c.b) ~= c.b)
end

function cc.color2str(c)
    local f = isFloatColor(c)
    local a = c.a
    if f and a then
        return string.format('{r=%.2f, g=%.2f, b=%.2f, a=%.2f}',
                             c.r, c.g, c.b, c.a)
    elseif f and not a then
        return string.format('{r=%.2f, g=%.2f, b=%.2f}',
                             c.r, c.g, c.b)
    elseif a then
        return string.format('{r=%d, g=%d, b=%d, a=%d}',
                             c.r, c.g, c.b, c.a)
    else
        return string.format('{r=%d, g=%d, b=%d}',
                             c.r, c.g, c.b)
    end
end

function cc.vec2str(v)
    local z = v.z
    local w = v.w
    if w then
        return string.format('{x=%.2f, y=%.2f, z=%.2f, w=%.2f}',
                             v.x, v.y, v.z, v.w)
    elseif z then
        return string.format('{x=%.2f, y=%.2f, z=%.2f}',
                             v.x, v.y, v.z)
    else
        return string.format('{x=%.2f, y=%.2f}',
                             v.x, v.y)
    end
end

function cc.SetNode(node, father, position, scale, color, opacity)
    if father then
        father:addChild(node)
    end
    if position then
        node:setPosition(position.x, position.y)
    end
    if type(scale) == 'table' then
        node:setScale(scale.x or scale.width, scale.y or scale.height)
    elseif type(scale) == 'number' then
        node:setScale(scale)
    end
    if color then
        node:setColor(color)
    end
    if opacity then
        node:setOpacity(opacity)
    end
    return node
end


