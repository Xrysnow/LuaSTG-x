--

---@type object
local object = xclass()

local c4f_white = { a = 1, r = 1, g = 1, b = 1 }
local function color_to_c4f(c)
    if c then
        return { a = c.a / 255, r = c.r / 255, g = c.g / 255, b = c.b / 255 }
    else
        return c4f_white
    end
end

--
local M = {}

function M.circle(r, rot, nSeg, color, lineWidth)
    local o = object()
    M.setCircle(o, r, rot, nSeg, color, lineWidth)
    return o
end

function M.arc(r, rot, ang, nSeg, color, lineWidth)
    local o = object()
    M.setArc(o, r, rot, ang, nSeg, color, lineWidth)
    return o
end

function M.rect(w, h, color, lineWidth)
    local o = object()
    M.setRect(o, w, h, color, lineWidth)
    return o
end

function M.triangle(x1, y1, x2, y2, x3, y3, color, lineWidth)
    local o = object()
    M.setTriangle(o, x1, y1, x2, y2, x3, y3, color, lineWidth)
    return o
end

function M.line(x1, y1, x2, y2, color, lineWidth)
    local o = object()
    M.setLine(o, x1, y1, x2, y2, color, lineWidth)
    return o
end

--

function M.setCircle(obj, r, rot, nSeg, color, lineWidth)
    local node = cc.DrawNode:create()
    if lineWidth then
        node:setLineWidth(lineWidth)
    end
    node:drawCircle(cc.p(0, 0), r or 1, rot or 0, nSeg or 360, color_to_c4f(color))
    obj.node = node
end

function M.setArc(obj, r, rot, ang, nSeg, color, lineWidth)
    rot = math.rad(rot)
    ang = math.rad(ang)
    local delta = 2 * math.pi / nSeg
    local n = ang / delta
    local vertices = {}
    for i = 1, n do
        local rads = (i - 1) * delta
        local xx = r * math.cos(rads + rot)
        local yy = r * math.sin(rads + rot)
        table.insert(vertices, cc.p(xx, yy))
    end
    local node = cc.DrawNode:create()
    if lineWidth then
        node:setLineWidth(lineWidth)
    end
    node:drawPoly(vertices, #vertices, false, color_to_c4f(color))
    obj.node = node
end

function M.setRect(obj, w, h, color, lineWidth)
    local node = cc.DrawNode:create()
    if lineWidth then
        node:setLineWidth(lineWidth)
    end
    node:drawRect(cc.p(-w / 2, -h / 2), cc.p(w / 2, h / 2), color_to_c4f(color) or c4f_white)
    obj.node = node
end

function M.setTriangle(obj, x1, y1, x2, y2, x3, y3, color, lineWidth)
    local node = cc.DrawNode:create()
    if lineWidth then
        node:setLineWidth(lineWidth)
    end
    local p1 = cc.p(x1, y1)
    local p2 = cc.p(x2, y2)
    local p3 = cc.p(x3, y3)
    local c = color_to_c4f(color) or c4f_white
    node:drawLine(p1, p2, c)
    node:drawLine(p2, p3, c)
    node:drawLine(p3, p1, c)
    obj.node = node
end

function M.setLine(obj, x1, y1, x2, y2, color, lineWidth)
    local node = cc.DrawNode:create()
    if lineWidth then
        node:setLineWidth(lineWidth)
    end
    local p1 = cc.p(x1, y1)
    local p2 = cc.p(x2, y2)
    local c = color_to_c4f(color) or c4f_white
    node:drawLine(p1, p2, c)
    obj.node = node
end

return M
