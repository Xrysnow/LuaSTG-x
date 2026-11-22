--- intersection between two geometries
---@class math.intersection
local M = {}
local vec2 = require('math.vec2')
local distance = require('math.distance_point')

local function SinCos(angle)
    return math.sin(angle), math.cos(angle)
end

---
---@param p0 math.vec2
---@param p1 math.vec2
---@param r number
---@return boolean
function M.Point_Circle(p0, p1, r)
    local dx = p0.x - p1.x
    local dy = p0.y - p1.y
    return dx * dx + dy * dy <= r * r
end

---
---@param p0 math.vec2
---@param halfW0 number
---@param halfH0 number
---@param p1 math.vec2
---@param halfW1 number
---@param halfH1 number
---@return boolean
function M.AABB_AABB(p0, halfW0, halfH0, p1, halfW1, halfH1)
    return math.max(p0.x - halfW0, p1.x - halfW1) <= math.min(p0.x + halfW0, p1.x + halfW1) and
            math.max(p0.y - halfH0, p1.y - halfH1) <= math.min(p0.y + halfH0, p1.y + halfH1)
end

---
---@param p0 math.vec2
---@param halfW number
---@param halfH number
---@param p1 math.vec2
---@param r number
---@return boolean
function M.AABB_Circle(p0, halfW, halfH, p1, r)
    local dw = math.max(0, math.abs(p0.x - p1.x) - halfW)
    local dh = math.max(0, math.abs(p0.y - p1.y) - halfH)
    return r * r >= dh * dh + dw * dw
end

---
---@param p0 math.vec2
---@param r0 number
---@param p1 math.vec2
---@param r1 number
---@return boolean
function M.Circle_Circle(p0, r0, p1, r1)
    local d = r0 + r1
    local dx = p0.x - p1.x
    local dy = p0.y - p1.y
    return dx * dx + dy * dy <= d * d
end

---
---@param p0 math.vec2
---@param p1 math.vec2
---@param halfW number
---@param halfH number
---@return boolean
function M.Point_AABB(p0, p1, halfW, halfH)
    local dx = p0.x - p1.x
    local dy = p0.y - p1.y
    return -halfW < dx and dx < halfW and -halfH < dy and dy < halfH
end

---
---@param p0 math.vec2
---@param p1 math.vec2
---@param halfW number
---@param halfH number
---@param rot number
---@return boolean
function M.Point_OBB(p0, p1, halfW, halfH, rot)
    local p = p0:getRotateAround(p1, -rot)
    return M.Point_AABB(p, p1, halfW, halfH)
end

---
---@param p0 math.vec2
---@param p1 math.vec2
---@param a number
---@param b number
---@param rot number
---@return boolean
function M.Point_Diamond(p0, p1, a, b, rot)
    local p = (p0 - p1):getRotated(-rot)
    local x_ = p.x / a
    local y_ = p.y / b
    local sum = x_ + y_
    local dif = x_ - y_
    return -1 < sum and sum < 1 and -1 < dif and dif < 1
end

---
---@param p0 math.vec2
---@param p1 math.vec2
---@param a number
---@param b number
---@param rot number
---@return boolean
function M.Point_Ellipse(p0, p1, a, b, rot)
    if (a == b) then
        return M.Point_Circle(p0, p1, a)
    end
    local p = (p0 - p1):getRotated(-rot)
    local x = p.x
    local y = p.y
    return x * x / (a * a) + y * y / (b * b) < 1
end

---
---@param p math.vec2
---@param A math.vec2
---@param B math.vec2
---@param C math.vec2
---@return boolean
function M.Point_Triangle(p, A, B, C)
    return M.Point_Triangle2(p - B, A - B, C - B)
end

---
---@param P math.vec2
---@param E0 math.vec2
---@param E1 math.vec2
---@return boolean
function M.Point_Triangle2(P, E0, E1)
    local _den = E0.y * E1.x - E0.x * E1.y
    local s = (P.y * E1.x - P.x * E1.y) / _den
    local t = (P.x * E0.y - P.y * E0.x) / _den
    return s > 0 and t > 0 and s + t < 1
end

---
---@param p0 math.vec2
---@param p1 math.vec2
---@param halfDiagA math.vec2
---@param halfDiagB math.vec2
---@return boolean
function M.Point_Parallelogram(p0, p1, halfDiagA, halfDiagB)
    local E0 = halfDiagA + halfDiagB
    local E1 = halfDiagA - halfDiagB
    local P = p0 - p1 + halfDiagA
    local _den = E0.y * E1.x - E0.x * E1.y
    local s = (P.y * E1.x - P.x * E1.y) / _den
    local t = (P.x * E0.y - P.y * E0.x) / _den
    return 0 < s and s < 1 and 0 < t and t < 1
end

---
---@param p0 math.vec2
---@param halfW number
---@param halfH number
---@param rot number
---@param p1 math.vec2
---@param r number
---@return boolean
function M.OBB_Circle(p0, halfW, halfH, rot, p1, r)
    local tSin, tCos = SinCos(rot)
    local d = p0 - p1
    local dw = math.max(0, math.abs(tCos * d.x + tSin * d.y) - halfW)
    local dh = math.max(0, math.abs(-tSin * d.x + tCos * d.y) - halfH)
    return r * r >= dh * dh + dw * dw
end

---
---@param p0 math.vec2
---@param halfW0 number
---@param halfH0 number
---@param rot0 number
---@param p1 math.vec2
---@param halfW1 number
---@param halfH1 number
---@param rot1 number
---@return boolean
function M.OBB_OBB(p0, halfW0, halfH0, rot0, p1, halfW1, halfH1, rot1)
    local tSin0, tCos0 = SinCos(rot0)
    local tSin1, tCos1 = SinCos(rot1)
    local e = {
        { tCos0, tSin0 }, --e00
        { -tSin0, tCos0 }, --e01
        { tCos1, tSin1 }, --e10
        { -tSin1, tCos1 } --e11
    }
    local projOther = { halfW0, halfH0, halfW1, halfH1 }
    local d = p0 - p1
    for i = 1, 4 do
        --3311
        local ii = 3 - math.floor((i - 1) / 2) * 2
        local v0 = e[ii] * projOther[ii]
        local v1 = e[ii + 1] * projOther[ii + 1]
        local ex = e[i].x
        local ey = e[i].y
        local projHalfDiag = math.max(
                math.abs(ex * (v0.x + v1.x) + ey * (v0.y + v1.y)),
                math.abs(ex * (v0.x - v1.x) + ey * (v0.y - v1.y))
        )
        if (projHalfDiag + projOther[i] < math.abs(ex * d.x + ey * d.y)) then
            return false
        end
    end
    return true
end

---
---@param p0 math.vec2
---@param halfW0 number
---@param halfH0 number
---@param rot0 number
---@param p1 math.vec2
---@param rot1 number
---@return boolean
function M.OBB_Line(p0, halfW0, halfH0, rot0, p1, rot1)
    local tSin0, tCos0 = SinCos(rot0)
    local tSin1, tCos1 = SinCos(rot1)
    local e00 = vec2(tCos0, tSin0)
    local e01 = vec2(-tSin0, tCos0)
    local halfDiag0 = e00 * halfW0 + e01 * halfH0
    local halfDiag1 = e00 * halfW0 - e01 * halfH0
    local eProj = vec2(-tSin1, tCos1)
    local halfProj = math.max(
            math.abs(eProj:dot(halfDiag0)),
            math.abs(eProj:dot(halfDiag1)))
    local d = distance.line(p0, p1, vec2(tCos1, tSin1))
    return d <= halfProj
end

---
---@param p math.vec2
---@param halfW number
---@param halfH number
---@param rot number
---@param A math.vec2
---@param B math.vec2
---@param C math.vec2
---@return boolean
function M.OBB_Triangle(p, halfW, halfH, rot, A, B, C)
    local tSin, tCos = SinCos(rot)
    local hw = vec2(tCos * halfW, tSin * halfW)
    local hh = vec2(-tSin * halfH, tCos * halfH)
    local v0 = p + hw + hh
    local v1 = p + hw - hh
    local v2 = p - hw - hh
    local v3 = p - hw + hh
    return M.Triangle_Triangle(A, B, C, v0, v1, v2) or M.Triangle_Triangle(A, B, C, v0, v3, v2)
end

---
---@param p0 math.vec2
---@param halfW number
---@param halfH number
---@param rot0 number
---@param p1 math.vec2
---@param a number
---@param b number
---@param rot1 number
---@return boolean
function M.OBB_Diamond(p0, halfW, halfH, rot0, p1, a, b, rot1)
    local tSin0, tCos0 = SinCos(rot0)
    local tSin1, tCos1 = SinCos(rot1)
    local hw = vec2(tCos0 * halfW, tSin0 * halfW)
    local hh = vec2(-tSin0 * halfH, tCos0 * halfH)
    return M.Parallelogram_Parallelogram(
            p0, hw + hh, hw - hh,
            p1, vec2(tCos1 * a, tSin1 * a), vec2(-tSin1 * b, tCos1 * b))
end

---
---@param p0 math.vec2
---@param halfW number
---@param halfH number
---@param rot0 number
---@param p1 math.vec2
---@param a number
---@param b number
---@param rot1 number
---@return boolean
function M.OBB_Ellipse(p0, halfW, halfH, rot0, p1, a, b, rot1)
    if (a == b) then
        return M.OBB_Circle(p0, halfW, halfH, rot0, p1, a)
    end
    local tSin0, tCos0 = SinCos(rot0)
    local tSin1, tCos1 = SinCos(rot1)
    local e00 = vec2(tCos0, tSin0)
    local e01 = vec2(-tSin0, tCos0)
    local e11 = vec2(-tSin1, tCos1)
    local f = e11 * (a / b - 1)
    local p0_ = p0 + distance.line_signed(p0, p1, e11) * f
    local tmp = e00 * halfW + p0
    local vDiag0 = tmp + e01 * halfH
    local vDiag1 = tmp - e01 * halfH
    local vDiag0_ = vDiag0 + distance.line_signed(vDiag0, p1, e11) * f
    local vDiag1_ = vDiag1 + distance.line_signed(vDiag1, p1, e11) * f
    local halfDiag0_ = vDiag0_ - p0_
    local halfDiag1_ = vDiag1_ - p0_
    local d = distance.parallelogram(p1, p0_, halfDiag0_, halfDiag1_)
    return d <= a
end

---
---@param p0 math.vec2
---@param r number
---@param p1 math.vec2
---@param a number
---@param b number
---@param rot number
---@return boolean
function M.Circle_Ellipse(p0, r, p1, a, b, rot)
    return distance.ellipse(p0, p1, a, b, rot) <= r
end

---
---@param p0 math.vec2
---@param r number
---@param p1 math.vec2
---@param a number
---@param b number
---@param rot number
---@return boolean
function M.Circle_Diamond(p0, r, p1, a, b, rot)
    return distance.diamond(p0, p1, a, b, rot) <= r
end

---
---@param p math.vec2
---@param r number
---@param A math.vec2
---@param B math.vec2
---@param C math.vec2
---@return boolean
function M.Circle_Triangle(p, r, A, B, C)
    return distance.triangle(p, A, B, C) <= r
end

---
---@param p0 math.vec2
---@param a0 number
---@param b0 number
---@param rot0 number
---@param p1 math.vec2
---@param a1 number
---@param b1 number
---@param rot1 number
---@return boolean
function M.Ellipse_Ellipse(p0, a0, b0, rot0, p1, a1, b1, rot1)
    if (a0 == b0) then
        return M.Circle_Ellipse(p0, a0, p1, a1, b1, rot1)
    end
    if (a1 == b1) then
        return M.Circle_Ellipse(p1, a1, p0, a0, b0, rot0)
    end
    local s, c = SinCos(rot1 - rot0)
    local c2 = c * c
    local s2 = s * s
    local sc = s * c
    local a_ = 1 / (a1 * a1)
    local b_ = 1 / (b1 * b1)
    local m00 = (a_ * c2 + b_ * s2) * (a0 * a0)
    local m11 = (b_ * c2 + a_ * s2) * (b0 * b0)
    local m01 = (a_ - b_) * sc * (a0 * b0)
    local sum = m00 + m11
    local tmp = m00 - m11
    local dif = math.sqrt(tmp * tmp + 4 * m01 * m01)
    local tanv = 2 * m01 / (dif + m00 - m11)
    local s0, c0 = SinCos(-rot0)
    local d = p1 - p0
    local d_ = vec2(d.x * c0 - d.y * s0, d.y * c0 + d.x * s0)
    d_.x = d_.x / a0
    d_.y = d_.y / b0
    return distance.ellipse(
            vec2.zero(), d_,
            math.sqrt(2 / (sum + dif)), math.sqrt(2 / (sum - dif)), math.atan(tanv)) <= 1
end

---
---@param p0 math.vec2
---@param a0 number
---@param b0 number
---@param rot0 number
---@param p1 math.vec2
---@param a1 number
---@param b1 number
---@param rot1 number
---@return boolean
function M.Ellipse_Diamond(p0, a0, b0, rot0, p1, a1, b1, rot1)
    if (a0 == b0) then
        return M.Circle_Diamond(p0, a0, p1, a1, b1, rot1)
    end
    local s, c = SinCos(rot1 - rot0)
    local fac = a0 / b0
    local p = (p1 - p0):getRotated(-rot0)
    p.y = p.y * fac
    return distance.parallelogram(
            vec2.zero(), p, vec2(c * a1, s * a1 * fac), vec2(-s * b1, c * b1 * fac)) <= a0
end

---
---@param p math.vec2
---@param a number
---@param b number
---@param rot number
---@param A math.vec2
---@param B math.vec2
---@param C math.vec2
---@return boolean
function M.Ellipse_Triangle(p, a, b, rot, A, B, C)
    if (a == b) then
        return M.Circle_Triangle(p, a, A, B, C)
    end
    local s, c = SinCos(-rot)
    local fac = a / b
    local PA = A - p
    local PB = B - p
    local PC = C - p
    local A_ = vec2(PA.x * c - PA.y * s, (PA.y * c + PA.x * s) * fac)
    local B_ = vec2(PB.x * c - PB.y * s, (PB.y * c + PB.x * s) * fac)
    local C_ = vec2(PC.x * c - PC.y * s, (PC.y * c + PC.x * s) * fac)
    return M.Point_Triangle(vec2.zero(), A_, B_, C_)
end

---
---@param A0 math.vec2
---@param B0 math.vec2
---@param A1 math.vec2
---@param B1 math.vec2
---@return boolean
function M.Segment_Segment(A0, B0, A1, B1)
    local A0B0 = B0 - A0
    local A0A1 = A1 - A0
    local A0B1 = B1 - A0
    local c1 = A0B0:cross(A0A1)
    local c2 = A0B0:cross(A0B1)
    if (c1 == 0 and c2 == 0) then
        if (A0B0:lengthSquared() == 0) then
            return false
        end
        local t1 = (A0B0.x == 0) and A0A1.y / A0B0.y or A0A1.x / A0B0.x
        local t2 = (A0B0.x == 0) and A0B1.y / A0B0.y or A0B1.x / A0B0.x
        return (0 < t1 and t1 < 1) or
                (0 < t2 and t2 < 1) or
                (t1 < 0 and 1 < t2) or
                (t2 < 0 and 1 < t1)
    end
    if (c1 * c2 > 0) then
        return false
    end
    local A1B1 = B1 - A1
    local c3 = -A1B1:cross(A0A1)
    local c4 = A1B1:cross(B0 - A1)
    return c3 * c4 < 0
end

---
---@param A0 math.vec2
---@param B0 math.vec2
---@param C0 math.vec2
---@param A1 math.vec2
---@param B1 math.vec2
---@param C1 math.vec2
---@return boolean
function M.Triangle_Triangle(A0, B0, C0, A1, B1, C1)
    local E00 = A0 - B0
    local E01 = C0 - B0
    for _, p in ipairs { A1, B1, C1 } do
        if (M.Point_Triangle(p - B0, E00, E01)) then
            return true
        end
    end
    local E10 = A1 - B1
    local E11 = C1 - B1
    for _, p in ipairs { A0, B0, C0 } do
        if (M.Point_Triangle(p - B1, E10, E11)) then
            return true
        end
    end
    for _, p0 in ipairs { A0, C0 } do
        for _, p1 in ipairs { A1, C1 } do
            if (M.Segment_Segment(B0, p0, B1, p1)) then
                return true
            end
        end
    end
    return false
end

---
---@param p0 math.vec2
---@param halfDiagA0 math.vec2
---@param halfDiagB0 math.vec2
---@param p1 math.vec2
---@param halfDiagA1 math.vec2
---@param halfDiagB1 math.vec2
---@return boolean
function M.Parallelogram_Parallelogram(p0, halfDiagA0, halfDiagB0, p1, halfDiagA1, halfDiagB1)
    local d01 = p1 - p0
    for _, e in ipairs {
        (halfDiagA0 + halfDiagB0),
        (halfDiagA0 - halfDiagB0),
        (halfDiagA1 + halfDiagB1),
        (halfDiagA1 - halfDiagB1) } do
        local ep = e:getPerp():getNormalized()
        local proj0 = math.max(math.abs(ep:dot(halfDiagA0)), math.abs(ep:dot(halfDiagB0)))
        local proj1 = math.max(math.abs(ep:dot(halfDiagA1)), math.abs(ep:dot(halfDiagB1)))
        if (proj0 + proj1 < math.abs(ep:dot(d01))) then
            return false
        end
    end
    return true
end

---
---@param p0 math.vec2
---@param a0 number
---@param b0 number
---@param rot0 number
---@param p1 math.vec2
---@param a1 number
---@param b1 number
---@param rot1 number
---@return boolean
function M.Diamond_Diamond(p0, a0, b0, rot0, p1, a1, b1, rot1)
    local tSin0, tCos0 = SinCos(rot0)
    local tSin1, tCos1 = SinCos(rot1)
    return M.Parallelogram_Parallelogram(
            p0, vec2(tCos0 * a0, tSin0 * a0), vec2(-tSin0 * b0, tCos0 * b0),
            p1, vec2(tCos1 * a1, tSin1 * a1), vec2(-tSin1 * b1, tCos1 * b1))
end

---
---@param p math.vec2
---@param a number
---@param b number
---@param rot number
---@param A math.vec2
---@param B math.vec2
---@param C math.vec2
---@return boolean
function M.Diamond_Triangle(p, a, b, rot, A, B, C)
    local tSin, tCos = SinCos(rot)
    local hd0 = vec2(tCos * a, tSin * a)
    local hd1 = vec2(-tSin * b, tCos * b)
    local v0 = p + hd0
    local v1 = p + hd1
    local v2 = p - hd0
    local v3 = p - hd1
    return M.Triangle_Triangle(A, B, C, v0, v1, v2) or M.Triangle_Triangle(A, B, C, v0, v3, v2)
end

---
---@param p0 math.vec2
---@param r number
---@param p1 math.vec2
---@param rot number
---@return boolean
function M.Line_Circle(p0, r, p1, rot)
    local tSin0, tCos0 = SinCos(rot)
    return distance.line(p0, p1, tCos0, tSin0) <= r
end

return M
