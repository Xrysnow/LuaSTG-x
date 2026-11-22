---
--- tween.lua
---
--- Copyright (C) 2018-2020 Xrysnow. All rights reserved.
---

---@class math.tween
local M = {}
local math = math
local pi = math.pi
local pi_2 = math.pi / 2
local pix2 = math.pi * 2

function M.linear(t)
    return t
end

function M.quadIn(t)
    return t * t
end

function M.quadOut(t)
    return -t * (t - 2)
end

function M.quadInOut(t)
    t = t * 2
    if (t < 1) then
        return t * t / 2
    end
    t = t - 1
    return -(t * (t - 2) - 1) / 2
end

function M.cubicIn(t)
    return t * t * t
end

function M.cubicOut(t)
    t = t - 1
    return t * t * t + 1
end

function M.cubicInOut(t)
    t = t * 2
    if (t < 1) then
        return t * t * t / 2
    end
    t = t - 2
    return (t * t * t + 2) / 2
end

function M.powIn(t, p)
    p = math.abs(p or 1)
    return math.pow(t, p)
end

function M.powOut(t, p)
    p = math.abs(p or 1)
    t = 1 - t
    return 1 - math.pow(t, p)
end

function M.powInOut(t, p)
    p = math.abs(p or 1)
    t = t * 2
    if (t < 1) then
        return math.pow(t, p) / 2
    end
    t = 2 - t
    return 1 - math.pow(t, p) / 2
end

function M.sineIn(t)
    return 1 - math.cos(pi_2 * t)
end

function M.sineOut(t)
    return math.sin(pi_2 * t)
end

function M.sineInOut(t)
    return (1 - math.cos(pi * t)) / 2
end

function M.expoIn(t, b)
    b = b or 2
    if (b == 1) then
        return t
    end
    return (math.pow(b, t) - 1) / (b - 1)
end

function M.expoOut(t, b)
    return 1 - M.expoIn(1 - t, b)
end

function M.expoInOut(t, b)
    t = t * 2
    if (t < 1) then
        return M.expoIn(t, b) / 2
    end
    t = 2 - t
    return 1 - M.expoIn(t, b) / 2
end

function M.circIn(t)
    return 1 - math.sqrt(1 - t * t)
end

function M.circOut(t)
    t = 1 - t
    return math.sqrt(1 - t * t)
end

function M.circInOut(t)
    t = t * 2
    if (t < 1) then
        return M.circIn(t) / 2
    end
    t = 2 - t
    return 1 - M.circIn(t) / 2
end

function M.elasticIn(t, a, p)
    a = a or 1
    p = p or 0.3
    if (t == 0) then
        return 0
    end
    local s
    if (a < 1) then
        a = 1
        s = p / 4
    else
        s = p / pix2 * math.asin(1 / a)
    end
    t = t - 1
    return -(a * math.pow(2, 10 * t) * math.sin((t - s) * pix2 / p))
end

function M.elasticOut(t, a, p)
    a = a or 1
    p = p or 0.3
    if (t == 0) then
        return 0
    end
    if (t == 1) then
        return 1
    end
    return 1 - M.elasticIn(1 - t, a, p)
end

function M.elasticInOut(t, a, p)
    a = a or 1
    p = p or 0.45
    t = t * 2
    if (t < 1) then
        return M.elasticIn(t, a, p) / 2
    end
    t = 2 - t
    return 1 - M.elasticIn(t, a, p) / 2
end

function M.backIn(t, s)
    s = s or 1.70158
    return t * t * (t * (s + 1) - s)
end

function M.backOut(t, s)
    return 1 - M.backIn(1 - t, s)
end

function M.backInOut(t, s)
    s = s or 1.70158 * 1.525
    t = t * 2
    if (t < 1) then
        return M.backIn(t, s) / 2
    end
    t = 2 - t
    return 1 - M.backIn(t, s) / 2
end

function M.bounceIn(t)
    return 1 - M.bounceOut(1 - t)
end

function M.bounceOut(t)
    if (t < 1.0 / 2.75) then
        return t * t * 7.5625
    end
    if (t < 2.0 / 2.75) then
        t = t - 1.5 / 2.75
        return t * t * 7.5625 + 0.75
    end
    if (t < 2.5 / 2.75) then
        t = t - 2.25 / 2.75
        return t * t * 7.5625 + 0.9375
    end
    t = t - 2.625 / 2.75
    return t * t * 7.5625 + 0.984375
end

function M.bounceInOut(t)
    t = t * 2
    if (t < 1) then
        return M.bounceIn(t) / 2
    end
    t = 2 - t
    return 1 - M.bounceIn(t) / 2
end

return M
