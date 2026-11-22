--- spline
---@class math.spline
local M = {}

---
---@param t number
---@param p1 number
---@param p2 number
---@param p3 number
---@param p4 number
---@param alpha number
---@return number
function M.Cardinal(t, p1, p2, p3, p4, alpha)
    local t2 = t * t
    local t3 = t2 * t
    local m0 = alpha * (p3 - p1)
    local m0_add_m1 = m0 + alpha * (p4 - p2)
    local c2 = 3 * (p3 - p2) - m0_add_m1 - m0
    local c3 = -2 * (p3 - p2) + m0_add_m1
    return c3 * t3 + c2 * t2 + m0 * t + p2
end

---
---@param t number
---@param p1 number
---@param p2 number
---@param p3 number
---@param p4 number
---@return number
function M.CatmullRom(t, p1, p2, p3, p4)
    return M.Cardinal(t, p1, p2, p3, p4, 0.5)
end

local _alpha = 0.5
local function t_next(ti, pi, pj)
    local dx = pj.x - pi.x
    local dy = pj.y - pi.y
    return math.pow(dx * dx + dy * dy, _alpha * 0.5) + ti
end

---
---@param t number
---@param p1 vec2_table
---@param p2 vec2_table
---@param p3 vec2_table
---@param p4 vec2_table
---@return vec2_table
function M.CentripetalCatmullRom(t, p1, p2, p3, p4)
    local t0 = 0
    local t1 = t_next(t0, p1, p2)
    local t2 = t_next(t1, p2, p3)
    local t3 = t_next(t2, p3, p4)

    t = t1 * (1 - t) + t2 * t

    local t01 = (t - t0) / (t1 - t0)
    local t12 = (t - t1) / (t2 - t1)
    local t23 = (t - t2) / (t3 - t2)
    local t02 = (t - t0) / (t2 - t0)
    local t13 = (t - t1) / (t3 - t1)

    local A1_x = (1 - t01) * p1.x + t01 * p2.x
    local A2_x = (1 - t12) * p2.x + t12 * p3.x
    local A3_x = (1 - t23) * p3.x + t23 * p4.x
    local B1_x = (1 - t02) * A1_x + t02 * A2_x
    local B2_x = (1 - t13) * A2_x + t13 * A3_x

    local A1_y = (1 - t01) * p1.y + t01 * p2.y
    local A2_y = (1 - t12) * p2.y + t12 * p3.y
    local A3_y = (1 - t23) * p3.y + t23 * p4.y
    local B1_y = (1 - t02) * A1_y + t02 * A2_y
    local B2_y = (1 - t13) * A2_y + t13 * A3_y

    return {
        x = (1 - t12) * B1_x + t12 * B2_x,
        y = (1 - t12) * B1_y + t12 * B2_y
    }
end

return M
