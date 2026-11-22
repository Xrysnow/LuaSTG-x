---@class lstg.mbg.Center
local M = {}
M._data = nil

M.ox = 315
M.oy = 240
M.ospeed = 0
M.ospeedd = 0
M.oaspeed = 0
M.oaspeedd = 0
M.speedx = 0
M.speedy = 0
M.aspeedx = 0
M.aspeedy = 0
M.x = 315
M.y = 240
M.speed = 0
M.speedd = 0
M.aspeed = 0
M.aspeedd = 0
-- string[]
M.events = {}
-- Centermanager
M.form = nil
M.Available = true
M.Aim = false
-- List<CExecution>
M.Eventsexe = {}

function M.clear()
    M.x = 315
    M.y = 240
    M.speed = 0
    M.speedd = 0
    M.aspeed = 0
    M.aspeedd = 0
    M.ox = M.x
    M.oy = M.y
    M.ospeed = M.speed
    M.ospeedd = M.speedd
    M.oaspeed = M.aspeed
    M.oaspeedd = M.aspeedd
    M.speedx = 0
    M.speedy = 0
    M.aspeedx = 0
    M.aspeedy = 0
    M.events = {}
    M.Available = true
end

local op_map = {
    [0] = function(a, b)
        return a > b
    end,
    [1] = function(a, b)
        return a < b
    end,
    [2] = function(a, b)
        return a == b
    end,
}

function M.update()
    local Time = require('game.mbg.Time')
    local Main = require('game.mbg.Main')
    local Math = require('game.mbg._math')
    local MathHelper = Math

    if (Main.Available and not Time.Playing) then
        M.ox = M.x
        M.oy = M.y
        M.ospeed = M.speed
        M.ospeedd = M.speedd
        M.oaspeed = M.aspeed
        M.oaspeedd = M.aspeedd
        M.aspeedx = M.aspeed * Math.Cos(MathHelper.ToRadians(M.aspeedd))
        M.aspeedy = M.aspeed * Math.Sin(MathHelper.ToRadians(M.aspeedd))
        M.speedx = M.speed * Math.Cos(MathHelper.ToRadians(M.speedd))
        M.speedy = M.speed * Math.Sin(MathHelper.ToRadians(M.speedd))
    end
    if (Main.Available and M.Available and Time.Playing) then
        M.speedx = M.speedx + M.aspeedx
        M.speedy = M.speedy + M.aspeedy
        M.ox = M.ox + M.speedx
        M.oy = M.oy + M.speedy
        --
        local Events = M._data and M._data.Events
        if Events then
            --[[
            local values = {
                ["当前帧"]   = Time.now,
                ["速度"]    = M.ospeed,
                ["速度方向"]  = M.ospeedd,
                ["加速度"]   = M.oaspeed,
                ["加速度方向"] = M.oaspeedd,
            }
            for _, e in ipairs(Events) do
                local Condition = e.Condition
                local Action = e.Action
                --
                local ok = true
                local First = Condition.First
                local Second = Condition.Second
                if First then
                    local LValue, Operator, RValue
                    LValue = values[First.LValue]
                    Operator = op_map[First.Operator]
                end
            end
            --]]
        end
        --
        local Eventsexe = {}
        for _, e in ipairs(M.Eventsexe) do
            if not e.NeedDelete then
                e:update()
                table.insert(Eventsexe, e)
            end
        end
        M.Eventsexe = Eventsexe
    end
end

return M
