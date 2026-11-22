int = math.floor
abs = math.abs
max = math.max
min = math.min
mod = math.mod
rnd = math.random
sqrt = math.sqrt
local sqrt = sqrt
local int = int

---返回x的符号（1,-1,0）
function sign(x)
    if x > 0 then
        return 1
    elseif x < 0 then
        return -1
    else
        return 0
    end
end

--local ranx = Rand()
--assert(not ran, 'random generator has been set')
--ran = {}
ran = lstg.Random()
---@type lstg.Random
local ran = ran
assert(ran, 'failed to create random generator')
--

---生成[a,b]范围的随机整数
---@param a number
---@param b number
---@return number
function ran:Int(a, b)
    if a > b then
        return self:randInt(b, a)
    else
        return self:randInt(a, b)
    end
end

---生成[a,b]范围的随机浮点数
---@param a number
---@param b number
---@return number
function ran:Float(a, b)
    return self:randFloat(a, b)
end

---随机生成1或-1
---@return number
function ran:Sign()
    return self:randSign()
end

---设置随机数种子
---@param n number
function ran:Seed(n)
    --Print('set random seed to ' .. n)
    Print(string.format('%s: %d', i18n('set random seed to'), n))
    self:setSeed(n)
end

---sqrt(x^2+y^2)
---@param x number
---@param y number
---@return number
function hypot(x, y)
    return sqrt(x * x + y * y)
end

local SetV = SetV
local Angle = Angle

---设置对象的速度
---@param obj object 要设置的对象
---@param v number 速度大小
---@param angle number 速度方向（角度）
---@param updateRot boolean 是否更新自转
---@param aim boolean 方向是否相对自机
function SetV2(obj, v, angle, updateRot, aim)
    if aim then
        SetV(obj, v, angle + Angle(obj, lstg.player), updateRot)
    else
        SetV(obj, v, angle, updateRot)
    end
end

local fac = {}

---阶乘
---@param num number
---@return number
function Factorial(num)
    if num < 0 then
        error(i18n "Can't get factorial of a minus number")
    end
    if num < 2 then
        return 1
    end
    num = int(num)
    if fac[num] then
        return fac[num]
    end
    local result = 1
    for i = 1, num do
        if fac[i] then
            result = fac[i]
        else
            result = result * i
            fac[i] = result
        end
    end
    return result
end

local Factorial = Factorial

---组合数
---@param ord number
---@param sum number
---@return number
function combinNum(ord, sum)
    if sum < 0 or ord < 0 then
        error(i18n "Can't get combinatorial of minus numbers")
    end
    ord = int(ord)
    sum = int(sum)
    return Factorial(sum) / (Factorial(ord) * Factorial(sum - ord))
end
