---@class ui.ColorCircle:cc.DrawNode @note: not for realtime
local M = class('ui.ColorCircle', cc.DrawNode)

function M:ctor(r, seg)
    seg = seg or r * 1.8
    for i = 1, seg do
        local r_ = i * r / seg
        local rseg = math.floor(7 * r_)
        local dth = 2 * math.pi / rseg
        for j = 1, rseg do
            local a = (j - 1) * dth
            local p = cc.p(r_ * math.cos(a), r_ * math.sin(a))
            local _r, _g, _b = color.fromHSV({ h = a, s = r_ / r, v = 1 })
            local c = cc.c4f(_r, _g, _b, 1)
            self:drawPoint(p, 1, c)
        end
    end
end

return M
