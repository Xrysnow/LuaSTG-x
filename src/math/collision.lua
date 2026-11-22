--- collision check
---@class math.collision
local M = {}
local intersect = require('math.intersection')
local vec2 = require('math.vec2')

local func = {}
for i = 0, 5 do
    func[i] = {}
end
local TCircle = 0
local TOBB = 1
local TEllipse = 2
local TDiamond = 3
local TTriangle = 4
local TPoint = 5
local str_type = {
    Circle   = 0,
    OBB      = 1,
    Ellipse  = 2,
    Diamond  = 3,
    Triangle = 4,
    Point    = 5,

    circle   = 0,
    obb      = 1,
    ellipse  = 2,
    diamond  = 3,
    triangle = 4,
    point    = 5,
}
local type_str = {
    [0] = 'circle',
    [1] = 'obb',
    [2] = 'ellipse',
    [3] = 'diamond',
    [4] = 'triangle',
    [5] = 'point',
}

local function ToTriangle(p, a, b, rot)
    local s, c = math.sin(rot), math.cos(rot)
    local hda = vec2(c * a, s * a)
    local db = vec2(-s * b, c * b)
    local A = p + hda
    local B = p - hda + db
    local C = p - hda - db
    return A, B, C
end

func[TCircle][TCircle] = function(p0, a0, b0, rot0, p1, a1, b1, rot1)
    return intersect.Circle_Circle(p0, a0, p1, a1)
end
func[TCircle][TOBB] = function(p0, a0, b0, rot0, p1, a1, b1, rot1)
    return intersect.OBB_Circle(p1, a1, b1, rot1, p0, a0)
end
func[TCircle][TEllipse] = function(p0, a0, b0, rot0, p1, a1, b1, rot1)
    return intersect.Circle_Ellipse(p0, a0, p1, a1, b1, rot1)
end
func[TCircle][TDiamond] = function(p0, a0, b0, rot0, p1, a1, b1, rot1)
    return intersect.Circle_Diamond(p0, a0, p1, a1, b1, rot1)
end
func[TCircle][TTriangle] = function(p0, a0, b0, rot0, p1, a1, b1, rot1)
    local A1, B1, C1 = ToTriangle(p1, a1, b1, rot1)
    return intersect.Circle_Triangle(p0, a0, A1, B1, C1)
end
func[TCircle][TPoint] = function(p0, a0, b0, rot0, p1, a1, b1, rot1)
    return intersect.Point_Circle(p1, p0, a0)
end

func[TOBB][TCircle] = function(p0, a0, b0, rot0, p1, a1, b1, rot1)
    return intersect.OBB_Circle(p0, a0, b0, rot0, p1, a1)
end
func[TOBB][TOBB] = function(p0, a0, b0, rot0, p1, a1, b1, rot1)
    return intersect.OBB_OBB(p0, a0, b0, rot0, p1, a1, b1, rot1)
end
func[TOBB][TEllipse] = function(p0, a0, b0, rot0, p1, a1, b1, rot1)
    return intersect.OBB_Ellipse(p0, a0, b0, rot0, p1, a1, b1, rot1)
end
func[TOBB][TDiamond] = function(p0, a0, b0, rot0, p1, a1, b1, rot1)
    return intersect.OBB_Diamond(p0, a0, b0, rot0, p1, a1, b1, rot1)
end
func[TOBB][TTriangle] = function(p0, a0, b0, rot0, p1, a1, b1, rot1)
    local A1, B1, C1 = ToTriangle(p1, a1, b1, rot1)
    return intersect.OBB_Triangle(p0, a0, b0, rot0, A1, B1, C1)
end
func[TOBB][TPoint] = function(p0, a0, b0, rot0, p1, a1, b1, rot1)
    return intersect.Point_OBB(p1, p0, a0, b0, rot0)
end

func[TEllipse][TCircle] = function(p0, a0, b0, rot0, p1, a1, b1, rot1)
    return intersect.Circle_Ellipse(p1, a1, p0, a0, b0, rot0)
end
func[TEllipse][TOBB] = function(p0, a0, b0, rot0, p1, a1, b1, rot1)
    return intersect.OBB_Ellipse(p1, a1, b1, rot1, p0, a0, b0, rot0)
end
func[TEllipse][TEllipse] = function(p0, a0, b0, rot0, p1, a1, b1, rot1)
    return intersect.Ellipse_Ellipse(p0, a0, b0, rot0, p1, a1, b1, rot1)
end
func[TEllipse][TDiamond] = function(p0, a0, b0, rot0, p1, a1, b1, rot1)
    return intersect.Ellipse_Diamond(p0, a0, b0, rot0, p1, a1, b1, rot1)
end
func[TEllipse][TTriangle] = function(p0, a0, b0, rot0, p1, a1, b1, rot1)
    local A1, B1, C1 = ToTriangle(p1, a1, b1, rot1)
    return intersect.Ellipse_Triangle(p0, a0, b0, rot0, A1, B1, C1)
end
func[TEllipse][TPoint] = function(p0, a0, b0, rot0, p1, a1, b1, rot1)
    return intersect.Point_Ellipse(p1, p0, a0, b0, rot0)
end

func[TDiamond][TCircle] = function(p0, a0, b0, rot0, p1, a1, b1, rot1)
    return intersect.Circle_Diamond(p1, a1, p0, a0, b0, rot0)
end
func[TDiamond][TOBB] = function(p0, a0, b0, rot0, p1, a1, b1, rot1)
    return intersect.OBB_Diamond(p1, a1, b1, rot1, p0, a0, b0, rot0)
end
func[TDiamond][TEllipse] = function(p0, a0, b0, rot0, p1, a1, b1, rot1)
    return intersect.Ellipse_Diamond(p1, a1, b1, rot1, p0, a0, b0, rot0)
end
func[TDiamond][TDiamond] = function(p0, a0, b0, rot0, p1, a1, b1, rot1)
    return intersect.Diamond_Diamond(p0, a0, b0, rot0, p1, a1, b1, rot1)
end
func[TDiamond][TTriangle] = function(p0, a0, b0, rot0, p1, a1, b1, rot1)
    local A1, B1, C1 = ToTriangle(p1, a1, b1, rot1)
    return intersect.Diamond_Triangle(p0, a0, b0, rot0, A1, B1, C1)
end
func[TDiamond][TPoint] = function(p0, a0, b0, rot0, p1, a1, b1, rot1)
    return intersect.Point_Diamond(p1, p0, a0, b0, rot0)
end

func[TTriangle][TCircle] = function(p0, a0, b0, rot0, p1, a1, b1, rot1)
    local A0, B0, C0 = ToTriangle(p0, a0, b0, rot0)
    return intersect.Circle_Triangle(p1, a1, A0, B0, C0)
end
func[TTriangle][TOBB] = function(p0, a0, b0, rot0, p1, a1, b1, rot1)
    local A0, B0, C0 = ToTriangle(p0, a0, b0, rot0)
    return intersect.OBB_Triangle(p1, a1, b1, rot1, A0, B0, C0)
end
func[TTriangle][TEllipse] = function(p0, a0, b0, rot0, p1, a1, b1, rot1)
    local A0, B0, C0 = ToTriangle(p0, a0, b0, rot0)
    return intersect.Ellipse_Triangle(p1, a1, b1, rot1, A0, B0, C0)
end
func[TTriangle][TDiamond] = function(p0, a0, b0, rot0, p1, a1, b1, rot1)
    local A0, B0, C0 = ToTriangle(p0, a0, b0, rot0)
    return intersect.Diamond_Triangle(p1, a1, b1, rot1, A0, B0, C0)
end
func[TTriangle][TTriangle] = function(p0, a0, b0, rot0, p1, a1, b1, rot1)
    local A0, B0, C0 = ToTriangle(p0, a0, b0, rot0)
    local A1, B1, C1 = ToTriangle(p1, a1, b1, rot1)
    return intersect.Triangle_Triangle(A0, B0, C0, A1, B1, C1)
end
func[TTriangle][TPoint] = function(p0, a0, b0, rot0, p1, a1, b1, rot1)
    local A0, B0, C0 = ToTriangle(p0, a0, b0, rot0)
    return intersect.Point_Triangle(p1, A0, B0, C0)
end

func[TPoint][TCircle] = function(p0, a0, b0, rot0, p1, a1, b1, rot1)
    return intersect.Point_Circle(p0, p1, a1)
end
func[TPoint][TOBB] = function(p0, a0, b0, rot0, p1, a1, b1, rot1)
    return intersect.Point_OBB(p0, p1, a1, b1, rot1)
end
func[TPoint][TEllipse] = function(p0, a0, b0, rot0, p1, a1, b1, rot1)
    return intersect.Point_Ellipse(p0, p1, a1, b1, rot1)
end
func[TPoint][TDiamond] = function(p0, a0, b0, rot0, p1, a1, b1, rot1)
    return intersect.Point_Diamond(p0, p1, a1, b1, rot1)
end
func[TPoint][TTriangle] = function(p0, a0, b0, rot0, p1, a1, b1, rot1)
    local A1, B1, C1 = ToTriangle(p1, a1, b1, rot1)
    return intersect.Point_Triangle(p0, A1, B1, C1)
end
func[TPoint][TPoint] = function(p0, a0, b0, rot0, p1, a1, b1, rot1)
    return p0 == p1
end

local function to_type(t)
    if type(t) == 'string' then
        return str_type[t] or 0
    else
        return t
    end
end

---
---@param s string
---@return number
function M.string_to_type(s)
    return str_type[s]
end

---
---@param t number
---@return string
function M.type_to_string(t)
    return type_str[t]
end

---
---@param p0 vec2_table
---@param a0 number
---@param b0 number
---@param rot0 number
---@param t0 number|string
---@param p1 vec2_table
---@param a1 number
---@param b1 number
---@param rot1 number
---@param t1 number|string
function M.check(p0, a0, b0, rot0, t0, p1, a1, b1, rot1, t1)
    return func[to_type(t0)][to_type(t1)](vec2(p0), a0, b0, rot0, vec2(p1), a1, b1, rot1)
end

return M
