---@class math.hull
local M = {}
local vec2 = require('math.vec2')
local intersection = require('math.intersection')
local t_insert = table.insert
local t_remove = table.remove

local function knn(points, p, k)
    local points_ = {}
    for _, v in ipairs(points) do
        local dx = p.x - v.x
        local dy = p.y - v.y
        local d = math.sqrt(dx * dx + dy * dy)
        t_insert(points_, { v, d })
    end
    table.sort(points_, function(a, b)
        return a[2] < b[2]
    end)
    local ret = {}
    for i = 1, k do
        ret[i] = points_[i][1]
    end
    return ret
end

local function intersects(p1, p2, p3, p4)
    return intersection.Segment_Segment(p1, p2, p3, p4)
end

local function angle(p1, p2, previous)
    return (math.atan2(p1.y - p2.y, p1.x - p2.x) - previous or 0) % (math.pi * 2) - math.pi
end

local function point_in_polygon(point, polygon)
    local px, py = point.x, point.y
    local size = #polygon
    for i = 1, size do
        local p1, p2 = polygon[i], polygon[(i + 1) % size]
        local p1x, p1y = p1.x, p1.y
        local p2x, p2y = p2.x, p2.y
        if math.min(p1x, p2x) < px and px <= math.max(p1x, p2x) then
            local p = p1y - p2y
            local q = p1x - p2x
            local y = (px - p1x) * p / q + p1y
            if y < py then
                return true
            end
        end
    end
    return false
end

---
---@param points math.vec2[]
---@param k number
function M.concave(points, k)
    k = k or 3
    local size = #points
    if size < 3 then
        error('invlid parameter')
    end
    if size == 3 then
        -- Points are a polygon already
        return points
    end
    local points_ = {}
    for _, v in ipairs(points) do
        t_insert(points_, v)
    end
    points = points_
    -- Make sure that k neighbours can be found
    k = math.min(math.max(k, 3), size - 1)
    local first = points[1]
    local first_i = 1
    for i = 2, size do
        local p = points[i]
        if p.y < first.y then
            first = p
            first_i = i
        end
    end
    local current = first
    -- Initialize hull
    local hull = { first }
    -- Remove processed point
    t_remove(points, first_i)
    local previous_angle = 0
    while (current ~= first or #hull == 1) and #points > 0 do
        if #hull == 3 then
            t_insert(points, first)
        end
        local neighbours = knn(points, current, k)
        table.sort(neighbours, function(a, b)
            local ang1 = -angle(a, current, previous_angle)
            local ang2 = -angle(b, current, previous_angle)
            return ang1 < ang2
        end)
        local c_points = neighbours
        local its = true
        local i = 0
        while its and i < #c_points do
            i = i + 1
            local last_point = c_points[i] == first and 1 or 0
            local j = 1
            its = false
            while its and j < #hull - last_point + 1 do
                its = intersects(hull[#hull], c_points[i],
                                 hull[#hull - j], hull[#hull - j + 1])
                j = j + 1
            end
        end
        if its then
            -- All points intersect, try again with higher a number of neighbours
            return M.concave(points, k + 1)
        end
        previous_angle = angle(c_points[i], current)
        current = c_points[i]
        -- Valid candidate was found
        t_insert(hull, current)
        for ii = 1, #points do
            if rawequal(points[ii], current) then
                t_remove(points, ii)
                break
            end
        end
    end
    for _, point in ipairs(points) do
        if not point_in_polygon(point, hull) then
            return M.concave(points, k + 1)
        end
    end
    return hull
end

local function cross(o, a, b)
    local ox, oy = o.x, o.y
    local ax, ay = a.x, a.y
    local bx, by = b.x, b.y
    return (ax - ox) * (by - oy) - (ay - oy) * (bx - ox)
end

---
---@param points math.vec2[]
function M.convex(points)
    if #points <= 1 then
        return points
    end
    local points_ = {}
    for _, v in ipairs(points) do
        t_insert(points_, v)
    end
    points = points_
    table.sort(points, function(a, b)
        if a.x == b.x then
            return a.y < b.y
        else
            return a.x < b.x
        end
    end)

    local lower = {}
    for _, p in ipairs(points) do
        while #lower >= 2 and cross(lower[#lower - 1], lower[#lower], p) <= 0 do
            t_remove(lower)
        end
        t_insert(lower, p)
    end
    local upper = {}
    for i = #points, 1, -1 do
        local p = points[i]
        while #upper >= 2 and cross(upper[#upper - 1], upper[#upper], p) <= 0 do
            t_remove(upper)
        end
        t_insert(upper, p)
    end
    local ret = lower
    t_remove(ret)
    for i = 1, #upper - 1 do
        t_insert(ret, upper[i])
    end
    return ret
end

return M
