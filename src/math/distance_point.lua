--- distance from a point to another geometry
---@class math.distance
local M = {}
local vec2 = require('math.vec2')

---
---@param p0 vec2_table
---@param p1 vec2_table
---@return number
function M.point_squared(p0, p1)
    local dx = p0.x - p1.x
    local dy = p0.y - p1.y
    return dx * dx + dy * dy
end

---
---@param p0 vec2_table
---@param p1 vec2_table
---@return number
function M.point(p0, p1)
    return math.sqrt(M.point_squared(p0, p1))
end

---
---@param p0 vec2_table
---@param p1 vec2_table a point on the line
---@param e vec2_table normal vector of the line
---@return number
function M.line_signed(p0, p1, e)
    return e.x * (p0.x - p1.x) + e.y * (p0.y - p1.y)
end

---
---@param p0 vec2_table
---@param p1 vec2_table a point on the line
---@param e vec2_table normal vector of the line
---@return number
function M.line(p0, p1, e)
    return math.abs(M.line_signed(p0, p1, e))
end

---
---@param p0 vec2_table
---@param p1 vec2_table
---@param r number
---@return number
function M.circle(p0, p1, r)
    return math.max(M.point(p0, p1) - r, 0)
end

---
---@param p0 vec2_table
---@param p1 vec2_table
---@param halfW number
---@param halfH number
---@param rot number
---@return number
function M.obb_squared(p0, p1, halfW, halfH, rot)
    local aCos = math.cos(rot)
    local aSin = math.sin(rot)
    local dx = p0.x - p1.x
    local dy = p0.y - p1.y
    local dw = math.max(0, math.abs(aCos * dx + aSin * dy) - halfW)
    local dh = math.max(0, math.abs(-aSin * dx + aCos * dy) - halfH)
    return dh * dh + dw * dw
end

---
---@param p0 vec2_table
---@param p1 vec2_table
---@param halfW number
---@param halfH number
---@param rot number
---@return number
function M.obb(p0, p1, halfW, halfH, rot)
    return math.sqrt(M.obb_squared(p0, p1, halfW, halfH, rot))
end

---
---@param p0 vec2_table
---@param pA vec2_table
---@param pB vec2_table
---@param pC vec2_table
---@return number
function M.triangle(p0, pA, pB, pC)
    local p, A, B, C = vec2(p0), vec2(pA), vec2(pB), vec2(pC)
    local AX = p - A
    local AB = B - A
    local AC = C - A
    local nA2B = AB:dot(AX) < 0
    local nA2C = AC:dot(AX) < 0
    if nA2B and nA2C then
        return AX:length()
    end
    local BX = p - B
    local BC = C - B
    local nB2A = AB:dot(BX) > 0
    local nB2C = BC:dot(BX) < 0
    if (nB2A and nB2C) then
        return BX:length()
    end
    local CX = p - C
    local nC2A = AC:dot(CX) > 0
    local nC2B = BC:dot(CX) > 0
    if (nC2A and nC2B) then
        return CX:length()
    end
    if (not nA2B and not nB2A and AC:cross(AB) * AB:cross(AX) > 0) then
        local e = AB:getNormalized()
        return M.line(p, A, e)
    end
    if (not nC2B and not nB2C and AB:cross(BC) * BC:cross(BX) < 0) then
        local e = BC:getNormalized()
        return M.line(p, B, e)
    end
    if (not nC2A and not nA2C and BC:cross(AC) * AC:cross(CX) < 0) then
        local e = AC:getNormalized()
        return M.line(p, C, e)
    end
    return 0
end

---
---@param p0 vec2_table
---@param p1 vec2_table
---@param halfW number
---@param halfH number
---@param rot number
---@return number
function M.diamond(p0, p1, halfW, halfH, rot)
    local r = vec2(math.cos(rot), math.sin(rot))
    local w = vec2(halfW, 0):getRotated(r)
    local h = vec2(0, halfH):getRotated(r)
    return M.parallelogram(p0, p1, w, h)
end

---
---@param p0 vec2_table
---@param p1 vec2_table
---@param pA vec2_table
---@param pB vec2_table
---@return number
function M.parallelogram(p0, p1, pA, pB)
    local p0, p1, A, B = vec2(p0), vec2(p1), vec2(pA), vec2(pB)
    local p = p0 - p1
    local AB = B - A
    local AD = -B - A
    local AX = p - A
    local nA2B = AB:dot(AX) < 0
    local nA2D = AD:dot(AX) < 0
    if (nA2B and nA2D) then
        return AX:length()
    end
    local BX = p - B
    local nB2A = AB:dot(BX) > 0
    local nB2C = AD:dot(BX) < 0
    if (nB2A and nB2C) then
        return BX:length()
    end
    local CX = p + A
    local nC2B = AD:dot(CX) > 0
    local nC2D = AB:dot(CX) > 0
    if (nC2B and nC2D) then
        return CX:length()
    end
    local DX = p + B
    local nD2A = AD:dot(DX) > 0
    local nD2C = AB:dot(DX) < 0
    if (nD2A and nD2C) then
        return DX:length()
    end
    if (not nA2B and not nB2A and AB:cross(A) * AB:cross(AX) > 0) then
        local e = AB:getNormalized()
        return M.line(p, A, e)
    end
    if (not nC2D and not nD2C and AB:cross(A) * AB:cross(CX) < 0) then
        local e = AB:getNormalized()
        return M.line(p, -A, e)
    end
    if (not nA2D and not nD2A and AD:cross(A) * AD:cross(AX) > 0) then
        local e = AD:getNormalized()
        return M.line(p, A, e)
    end
    if (not nC2B and not nB2C and AD:cross(A) * AD:cross(BX) < 0) then
        local e = AD:getNormalized()
        return M.line(p, B, e)
    end
    return 0
end

---
---@param p0 vec2_table
---@param p1 vec2_table
---@param a number
---@param b number
---@param rot number
---@return number
function M.ellipse(p0, p1, a, b, rot)
    if a == b then
        return M.circle(p0, p1, a)
    end
    local px, py = p0.x - p1.x, p0.y - p1.y
    local tCos, tSin = math.cos(-rot), math.sin(-rot)
    local x = math.abs(px * tCos - py * tSin)
    local y = math.abs(py * tCos + px * tSin)
    if (x * x / (a * a) + y * y / (b * b) <= 1.0) then
        return 0
    end
    local a2 = a * a
    local b2 = b * b
    local ax = a * x
    local by = b * y
    local tmp = b2 - a2
    local theta = math.pi / 4 - (((b2 - a2) / math.sqrt(2)) + ax - by) / (ax + by)
    theta = math.max(0, math.min(theta, math.pi / 2))
    local ct, st = math.cos(theta), math.sin(theta)
    for _ = 0, 1 do
        local dtheta = (tmp * st * ct + ax * st - by * ct) /
                (tmp * (ct * ct - st * st) + ax * ct + by * st)
        if (math.abs(dtheta) < 1e-5) then
            break
        end
        theta = theta - dtheta
        ct, st = math.cos(theta), math.sin(theta)
    end
    local dx = a * ct - x
    local dy = b * st - y
    return math.sqrt(dx * dx + dy * dy)
end

return M
