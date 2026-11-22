--
local M = {}
local Math = require('game.mbg._math')
local MathHelper = Math

M.clcount = 0
M.clwait = 0
M.Aim1 = false
M.Aim2 = false
M.Aim3 = false
M.mouseleft = 0
M.mousex = 0
M.search = false
M.text = ""
M.textsave = ""
M.time = 0
--
M.total = 200
M.now = 1
M.left = 1
M.quake = { X = 0, Y = 0 }
M.stop = 1
M.Playing = false
M.Pause = false
M.GE = {}
---@type number[]
M.GEcount = {}

function M.clear()
    M.total = 200
    M.now = 1
    M.left = 1
    M.text = ""
    M.textsave = ""
    M.time = 0
    M.Playing = false
    M.Pause = false
    M.GE = {}
    M.GEcount = {}
end
local Vector2 = function(x, y)
    return { X = x or 0, Y = y or 0 }
end

function M.update()
    local Center = require('game.mbg.Center')
    local Player = require('game.mbg.Player')
    local Main = require('game.mbg.Main')
    local GlobalEvent = require('game.mbg.GlobalEvent')
    local Layer = require('game.mbg.Layer')

    if Main.Available then
        if #M.GE < M.total then
            for i = 1, M.total - #M.GE do
                local globalEvent = GlobalEvent()
                globalEvent.gotocondition = -1
                globalEvent.quakecondition = -1
                globalEvent.stopcondition = -1
                globalEvent.stoplevel = -1
                table.insert(M.GE, globalEvent)
            end
        end
    end
    if M.Playing then
        M.now = M.now + 1
        if (M.now > M.total) then
            M.now = 1
            M.left = 1
            Center.Eventsexe = {}

            for _, layer8 in ipairs(Layer.LayerArray) do
                for _, batch4 in ipairs(layer8.BatchArray) do
                    batch4.Eventsexe = {}
                    batch4.copys = batch4:copy()
                    for _, event16 in ipairs(batch4.copys.Parentevents) do
                        event16.loop = 0
                    end
                    local num22 = MathHelper.Lerp(-batch4.copys.rand.speed, batch4.copys.rand.speed, Main.rand.NextDouble())
                    local num23 = math.floor(MathHelper.Lerp(-batch4.copys.rand.speedd, batch4.copys.rand.speedd, Main.rand.NextDouble()))
                    local num24 = MathHelper.Lerp(-batch4.copys.rand.aspeed, batch4.copys.rand.aspeed, Main.rand.NextDouble())
                    local num25 = math.floor(MathHelper.Lerp(-batch4.copys.rand.aspeedd, batch4.copys.rand.aspeedd, Main.rand.NextDouble()))
                    if (batch4.fx == -99998) then
                        batch4.copys.fx = batch4.x - 4
                    end
                    if (batch4.fx == -99999) then
                        batch4.copys.fx = Player.position.X
                    end
                    if (batch4.fy == -99998) then
                        batch4.copys.fy = batch4.y + 16
                    end
                    if (batch4.fy == -99999) then
                        batch4.copys.fy = Player.position.Y
                    end
                    if (batch4.speedd == -99999) then
                        batch4.copys.speedd = MathHelper.ToDegrees(Main.Twopointangle(Player.position.X, Player.position.Y, batch4.copys.fx, batch4.copys.fy))
                    end
                    if (batch4.aspeedd == -99999) then
                        batch4.copys.aspeedd = MathHelper.ToDegrees(Main.Twopointangle(Player.position.X, Player.position.Y, batch4.copys.fx, batch4.copys.fy))
                    end
                    batch4.copys.aspeed = batch4.copys.aspeed + num24
                    batch4.copys.aspeedd = batch4.copys.aspeedd + num25
                    batch4.copys.speed = batch4.copys.speed + num22
                    batch4.copys.speedd = batch4.copys.speedd + num23
                    batch4.copys.aspeedx = batch4.copys.aspeed * Math.Cos(MathHelper.ToRadians(batch4.copys.aspeedd))
                    batch4.copys.aspeedy = batch4.copys.aspeed * Math.Sin(MathHelper.ToRadians(batch4.copys.aspeedd))
                    batch4.copys.speedx = batch4.copys.speed * Math.Cos(MathHelper.ToRadians(batch4.copys.speedd))
                    batch4.copys.speedy = batch4.copys.speed * Math.Sin(MathHelper.ToRadians(batch4.copys.speedd))
                    batch4.copys.bfdirection = batch4.fdirection
                    batch4.copys.bsonaspeedd = batch4.sonaspeedd
                    if (batch4.fdirection == -99998) then
                        batch4.copys.fdirection = MathHelper.ToDegrees(Main.Twopointangle(batch4.x - 4, batch4.y + 16, batch4.copys.fx, batch4.copys.fy))
                    elseif (batch4.fdirection == -99999) then
                        batch4.copys.fdirection = MathHelper.ToDegrees(Main.Twopointangle(Player.position.X, Player.position.Y, batch4.copys.fx, batch4.copys.fy))
                    elseif (batch4.fdirection == -100000) then
                        batch4.copys.fdirection = MathHelper.ToDegrees(Main.Twopointangle(batch4.fdirections.X, batch4.fdirections.Y, batch4.copys.fx, batch4.copys.fy))
                    end
                    if (batch4.sonaspeedd == -99998) then
                        batch4.copys.sonaspeedd = MathHelper.ToDegrees(Main.Twopointangle(batch4.x - 4, batch4.y + 16, batch4.copys.fx, batch4.copys.fy))
                    elseif (batch4.sonaspeedd == -99999) then
                        batch4.copys.sonaspeedd = MathHelper.ToDegrees(Main.Twopointangle(Player.position.X, Player.position.Y, batch4.copys.fx, batch4.copys.fy))
                    elseif (batch4.sonaspeedd == -100000) then
                        batch4.copys.sonaspeedd = MathHelper.ToDegrees(Main.Twopointangle(batch4.sonaspeedds.X, batch4.sonaspeedds.Y, batch4.copys.fx, batch4.copys.fy))
                    end
                    if (batch4.head == -100000) then
                        batch4.copys.head = MathHelper.ToDegrees(Main.Twopointangle(batch4.heads.X, batch4.heads.Y, batch4.copys.fx, batch4.copys.fx))
                    end
                end
                for _, lase4 in ipairs(layer8.LaseArray) do
                    lase4.Eventsexe = {}
                    lase4.copys = lase4:copy()
                    for _, event17 in ipairs(lase4.copys.Parentevents) do
                        event17.loop = 0
                    end
                    local num26 = MathHelper.Lerp(-lase4.copys.rand.speed, lase4.copys.rand.speed, Main.rand.NextDouble())
                    local num27 = math.floor(MathHelper.Lerp(-lase4.copys.rand.speedd, lase4.copys.rand.speedd, Main.rand.NextDouble()))
                    local num28 = MathHelper.Lerp(-lase4.copys.rand.aspeed, lase4.copys.rand.aspeed, Main.rand.NextDouble())
                    local num29 = math.floor(MathHelper.Lerp(-lase4.copys.rand.aspeedd, lase4.copys.rand.aspeedd, Main.rand.NextDouble()))
                    lase4.copys.aspeed = lase4.copys.aspeed + num28
                    lase4.copys.aspeedd = lase4.copys.aspeedd + num29
                    lase4.copys.speed = lase4.copys.speed + num26
                    lase4.copys.speedd = lase4.copys.speedd + num27
                    lase4.copys.aspeedx = lase4.copys.aspeed * Math.Cos(MathHelper.ToRadians(lase4.copys.aspeedd))
                    lase4.copys.aspeedy = lase4.copys.aspeed * Math.Sin(MathHelper.ToRadians(lase4.copys.aspeedd))
                    lase4.copys.speedx = lase4.copys.speed * Math.Cos(MathHelper.ToRadians(lase4.copys.speedd))
                    lase4.copys.speedy = lase4.copys.speed * Math.Sin(MathHelper.ToRadians(lase4.copys.speedd))
                    if (lase4.fdirection == -99999) then
                        lase4.copys.fdirection = MathHelper.ToDegrees(Main.Twopointangle(Player.position.X, Player.position.Y, lase4.copys.x - 4, lase4.copys.y + 16))
                    elseif (lase4.fdirection == -100000) then
                        lase4.copys.fdirection = MathHelper.ToDegrees(Main.Twopointangle(lase4.fdirections.X, lase4.fdirections.Y, lase4.copys.x - 4, lase4.copys.y + 16))
                    end
                    if (lase4.sonaspeedd == -99998) then
                        lase4.copys.sonaspeedd = MathHelper.ToDegrees(Main.Twopointangle(lase4.x - 4, lase4.y + 16, lase4.copys.x - 4, lase4.copys.y + 16))
                    elseif (lase4.sonaspeedd == -99999) then
                        lase4.copys.sonaspeedd = MathHelper.ToDegrees(Main.Twopointangle(Player.position.X, Player.position.Y, lase4.copys.x - 4, lase4.copys.y + 16))
                    elseif (lase4.sonaspeedd == -100000) then
                        lase4.copys.sonaspeedd = MathHelper.ToDegrees(Main.Twopointangle(lase4.sonaspeedds.X, lase4.sonaspeedds.Y, lase4.copys.x - 4, lase4.copys.y + 16))
                    end
                end
                for _, cover4 in ipairs(layer8.CoverArray) do
                    cover4.Eventsexe = {}
                    cover4.copys = cover4:copy()
                    for _, event18 in ipairs(cover4.copys.Parentevents) do
                        event18.loop = 0
                    end
                    local num30 = MathHelper.Lerp(-cover4.copys.rand.speed, cover4.copys.rand.speed, Main.rand.NextDouble())
                    local num31 = math.floor(MathHelper.Lerp(-cover4.copys.rand.speedd, cover4.copys.rand.speedd, Main.rand.NextDouble()))
                    local num32 = MathHelper.Lerp(-cover4.copys.rand.aspeed, cover4.copys.rand.aspeed, Main.rand.NextDouble())
                    local num33 = math.floor(MathHelper.Lerp(-cover4.copys.rand.aspeedd, cover4.copys.rand.aspeedd, Main.rand.NextDouble()))
                    cover4.copys.aspeed = cover4.copys.aspeed + num32
                    cover4.copys.aspeedd = cover4.copys.aspeedd + num33
                    cover4.copys.speed = cover4.copys.speed + num30
                    cover4.copys.speedd = cover4.copys.speedd + num31
                    cover4.copys.aspeedx = cover4.copys.aspeed * Math.Cos(MathHelper.ToRadians(cover4.copys.aspeedd))
                    cover4.copys.aspeedy = cover4.copys.aspeed * Math.Sin(MathHelper.ToRadians(cover4.copys.aspeedd))
                    cover4.copys.speedx = cover4.copys.speed * Math.Cos(MathHelper.ToRadians(cover4.copys.speedd))
                    cover4.copys.speedy = cover4.copys.speed * Math.Sin(MathHelper.ToRadians(cover4.copys.speedd))
                end
                for _, rebound3 in ipairs(layer8.ReboundArray) do
                    rebound3.copys = rebound3:copy()
                    local num34 = MathHelper.Lerp(-rebound3.copys.rand.speed, rebound3.copys.rand.speed, Main.rand.NextDouble())
                    local num35 = math.floor(MathHelper.Lerp(-rebound3.copys.rand.speedd, rebound3.copys.rand.speedd, Main.rand.NextDouble()))
                    local num36 = MathHelper.Lerp(-rebound3.copys.rand.aspeed, rebound3.copys.rand.aspeed, Main.rand.NextDouble())
                    local num37 = math.floor(MathHelper.Lerp(-rebound3.copys.rand.aspeedd, rebound3.copys.rand.aspeedd, Main.rand.NextDouble()))
                    rebound3.copys.aspeed = rebound3.copys.aspeed + num36
                    rebound3.copys.aspeedd = rebound3.copys.aspeedd + num37
                    rebound3.copys.speed = rebound3.copys.speed + num34
                    rebound3.copys.speedd = rebound3.copys.speedd + num35
                    rebound3.copys.aspeedx = rebound3.copys.aspeed * Math.Cos(MathHelper.ToRadians(rebound3.copys.aspeedd))
                    rebound3.copys.aspeedy = rebound3.copys.aspeed * Math.Sin(MathHelper.ToRadians(rebound3.copys.aspeedd))
                    rebound3.copys.speedx = rebound3.copys.speed * Math.Cos(MathHelper.ToRadians(rebound3.copys.speedd))
                    rebound3.copys.speedy = rebound3.copys.speed * Math.Sin(MathHelper.ToRadians(rebound3.copys.speedd))
                end
                for _, force3 in ipairs(layer8.ForceArray) do
                    force3.copys = force3:copy()
                    local num38 = MathHelper.Lerp(-force3.copys.rand.speed, force3.copys.rand.speed, Main.rand.NextDouble())
                    local num39 = math.floor(MathHelper.Lerp(-force3.copys.rand.speedd, force3.copys.rand.speedd, Main.rand.NextDouble()))
                    local num40 = MathHelper.Lerp(-force3.copys.rand.aspeed, force3.copys.rand.aspeed, Main.rand.NextDouble())
                    local num41 = math.floor(MathHelper.Lerp(-force3.copys.rand.aspeedd, force3.copys.rand.aspeedd, Main.rand.NextDouble()))
                    force3.copys.aspeed = force3.copys.aspeed + num40
                    force3.copys.aspeedd = force3.copys.aspeedd + num41
                    force3.copys.speed = force3.copys.speed + num38
                    force3.copys.speedd = force3.copys.speedd + num39
                    force3.copys.aspeedx = force3.copys.aspeed * Math.Cos(MathHelper.ToRadians(force3.copys.aspeedd))
                    force3.copys.aspeedy = force3.copys.aspeed * Math.Sin(MathHelper.ToRadians(force3.copys.aspeedd))
                    force3.copys.speedx = force3.copys.speed * Math.Cos(MathHelper.ToRadians(force3.copys.speedd))
                    force3.copys.speedy = force3.copys.speed * Math.Sin(MathHelper.ToRadians(force3.copys.speedd))
                end
            end
            for _, globalEvent3 in ipairs(M.GE) do
                globalEvent3.qtcount = 0
                globalEvent3.stcount = 0
            end
            M.stop = 1
            M.quake = { X = 0, Y = 0 }
        end
        if (M.now >= M.left + 105) then
            M.left = M.left + 1
        end
        for num42 = 0, #M.GE - 1 do
            local v = M.GE[num42 + 1]
            if (num42 + 1 == M.now and v.isgoto) then
                v.gtcount = v.gtcount + 1
                if (v.gotowhere ~= 0 and (v.gototime == 0 or v.gtcount <= v.gototime)) then
                    M.now = v.gotowhere
                end
            end
            if (v.isquake and M.now >= num42 + 1) then
                v.qtcount = v.qtcount + 1
                if (v.qtcount % 2 == 0 and (v.quaketime == 0 or v.qtcount <= v.quaketime)) then
                    M.quake = Vector2(0, (1 - v.qtcount / v.quaketime) * v.quakelevel * Math.Sin(v.qtcount))
                end
            end
            if (v.isstop and M.now >= num42 + 1) then
                v.stcount = v.stcount + 1
                if (v.stoptime == 0 or v.stcount <= v.stoptime) then
                    if (v.stoplevel == 0) then
                        M.stop = v.stcount / v.stoptime * v.stcount / v.stoptime
                    elseif (v.stoplevel == 1) then
                        M.stop = 0
                    end
                else
                    M.stop = 1
                end
            end
        end
    end
    local num43 = M.left + 106
    if (num43 >= M.total) then
        num43 = num43 - num43 - M.total
    end
    if (M.clcount == 1) then
        M.clwait = M.clwait + 1
        if (M.clwait > 15) then
            M.clwait = 0
            M.clcount = 0
        end
    end
    if Main.Available and M.search and not M.Playing then
        M.time = M.time + 1
        if (M.time >= 30) then
            M.time = 0
        end
    end
end

function M._play()
    local Player = require('game.mbg.Player')
    local Main = require('game.mbg.Main')
    local Layer = require('game.mbg.Layer')

    M.Playing = true
    if not M.Pause then
        for _, layer in ipairs(Layer.LayerArray) do
            for _, batch in ipairs(layer.BatchArray) do
                batch.Selecting = false
                batch.copys = batch:copy()
                for _, e in ipairs(batch.copys.Parentevents) do
                    e.loop = 0
                end
                local num = MathHelper.Lerp(-batch.copys.rand.speed, batch.copys.rand.speed, Main.rand.NextDouble())
                local num2 = math.floor(MathHelper.Lerp(-batch.copys.rand.speedd, batch.copys.rand.speedd, Main.rand.NextDouble()))
                local num3 = MathHelper.Lerp(-batch.copys.rand.aspeed, batch.copys.rand.aspeed, Main.rand.NextDouble())
                local num4 = math.floor(MathHelper.Lerp(-batch.copys.rand.aspeedd, batch.copys.rand.aspeedd, Main.rand.NextDouble()))
                if (batch.fx == -99998) then
                    batch.copys.fx = batch.x - 4
                end
                if (batch.fx == -99999) then
                    batch.copys.fx = Player.position.X
                end
                if (batch.fy == -99998) then
                    batch.copys.fy = batch.y + 16
                end
                if (batch.fy == -99999) then
                    batch.copys.fy = Player.position.Y
                end
                if (batch.speedd == -99999) then
                    batch.copys.speedd = MathHelper.ToDegrees(Main.Twopointangle(Player.position.X, Player.position.Y, batch.copys.fx, batch.copys.fy))
                end
                if (batch.aspeedd == -99999) then
                    batch.copys.aspeedd = MathHelper.ToDegrees(Main.Twopointangle(Player.position.X, Player.position.Y, batch.copys.fx, batch.copys.fy))
                end
                batch.copys.aspeed = batch.copys.aspeed + num3
                batch.copys.aspeedd = batch.copys.aspeedd + num4
                batch.copys.speed = batch.copys.speed + num
                batch.copys.speedd = batch.copys.speedd + num2
                batch.copys.aspeedx = batch.copys.aspeed * Math.Cos(MathHelper.ToRadians(batch.copys.aspeedd))
                batch.copys.aspeedy = batch.copys.aspeed * Math.Sin(MathHelper.ToRadians(batch.copys.aspeedd))
                batch.copys.speedx = batch.copys.speed * Math.Cos(MathHelper.ToRadians(batch.copys.speedd))
                batch.copys.speedy = batch.copys.speed * Math.Sin(MathHelper.ToRadians(batch.copys.speedd))
                batch.copys.bfdirection = batch.fdirection
                batch.copys.bsonaspeedd = batch.sonaspeedd
                if (batch.fdirection == -99998) then
                    batch.copys.fdirection = MathHelper.ToDegrees(Main.Twopointangle(batch.x - 4, batch.y + 16, batch.copys.fx, batch.copys.fy))
                elseif (batch.fdirection == -99999) then
                    batch.copys.fdirection = MathHelper.ToDegrees(Main.Twopointangle(Player.position.X, Player.position.Y, batch.copys.fx, batch.copys.fy))
                elseif (batch.fdirection == -100000) then
                    batch.copys.fdirection = MathHelper.ToDegrees(Main.Twopointangle(batch.fdirections.X, batch.fdirections.Y, batch.copys.fx, batch.copys.fy))
                end
                if (batch.sonaspeedd == -99998) then
                    batch.copys.sonaspeedd = MathHelper.ToDegrees(Main.Twopointangle(batch.x - 4, batch.y + 16, batch.copys.fx, batch.copys.fy))
                elseif (batch.sonaspeedd == -99999) then
                    batch.copys.sonaspeedd = MathHelper.ToDegrees(Main.Twopointangle(Player.position.X, Player.position.Y, batch.copys.fx, batch.copys.fy))
                elseif (batch.sonaspeedd == -100000) then
                    batch.copys.sonaspeedd = MathHelper.ToDegrees(Main.Twopointangle(batch.sonaspeedds.X, batch.sonaspeedds.Y, batch.copys.fx, batch.copys.fy))
                end
                if (batch.head == -100000) then
                    batch.copys.head = MathHelper.ToDegrees(Main.Twopointangle(batch.heads.X, batch.heads.Y, batch.copys.fx, batch.copys.fx))
                end
                for _, event2 in ipairs(batch.Parentevents) do
                    for _, e in ipairs(event2.events) do
                        event2:addBatchParentEvent(e)
                    end
                end
                for _, event3 in ipairs(batch.Sonevents) do
                    for _, e in ipairs(event3.events) do
                        event3:addBatchChildEvent(e)
                    end
                end
            end
            for _, lase in ipairs(layer.LaseArray) do
                lase.Selecting = false
                lase.copys = lase:copy()
                for _, e in ipairs(lase.copys.Parentevents) do
                    e.loop = 0
                end
                local num5 = MathHelper.Lerp(-lase.copys.rand.speed, lase.copys.rand.speed, Main.rand.NextDouble())
                local num6 = math.floor(MathHelper.Lerp(-lase.copys.rand.speedd, lase.copys.rand.speedd, Main.rand.NextDouble()))
                local num7 = MathHelper.Lerp(-lase.copys.rand.aspeed, lase.copys.rand.aspeed, Main.rand.NextDouble())
                local num8 = math.floor(MathHelper.Lerp(-lase.copys.rand.aspeedd, lase.copys.rand.aspeedd, Main.rand.NextDouble()))
                lase.copys.aspeed = lase.copys.aspeed + num7
                lase.copys.aspeedd = lase.copys.aspeedd + num8
                lase.copys.speed = lase.copys.speed + num5
                lase.copys.speedd = lase.copys.speedd + num6
                lase.copys.aspeedx = lase.copys.aspeed * Math.Cos(MathHelper.ToRadians(lase.copys.aspeedd))
                lase.copys.aspeedy = lase.copys.aspeed * Math.Sin(MathHelper.ToRadians(lase.copys.aspeedd))
                lase.copys.speedx = lase.copys.speed * Math.Cos(MathHelper.ToRadians(lase.copys.speedd))
                lase.copys.speedy = lase.copys.speed * Math.Sin(MathHelper.ToRadians(lase.copys.speedd))
                if (lase.fdirection == -99999) then
                    lase.copys.fdirection = MathHelper.ToDegrees(Main.Twopointangle(Player.position.X, Player.position.Y, lase.copys.x - 4, lase.copys.y + 16))
                elseif (lase.fdirection == -100000) then
                    lase.copys.fdirection = MathHelper.ToDegrees(Main.Twopointangle(lase.fdirections.X, lase.fdirections.Y, lase.copys.x - 4, lase.copys.y + 16))
                end
                if (lase.sonaspeedd == -99998) then
                    lase.copys.sonaspeedd = MathHelper.ToDegrees(Main.Twopointangle(lase.x - 4, lase.y + 16, lase.copys.x - 4, lase.copys.y + 16))
                elseif (lase.sonaspeedd == -99999) then
                    lase.copys.sonaspeedd = MathHelper.ToDegrees(Main.Twopointangle(Player.position.X, Player.position.Y, lase.copys.x - 4, lase.copys.y + 16))
                elseif (lase.sonaspeedd == -100000) then
                    lase.copys.sonaspeedd = MathHelper.ToDegrees(Main.Twopointangle(lase.sonaspeedds.X, lase.sonaspeedds.Y, lase.copys.x - 4, lase.copys.y + 16))
                end
                for _, event5 in ipairs(lase.Parentevents) do
                    for _, e in ipairs(event5.events) do
                        event5:addLaserParentEvent(e)
                    end
                end
                for _, event6 in ipairs(lase.Sonevents) do
                    for _, e in ipairs(event6.events) do
                        event6:addLaserChildEvent(e)
                    end
                end
            end
            for _, cover in ipairs(layer.CoverArray) do
                cover.Selecting = false
                cover.copys = cover:copy()
                for _, e in ipairs(cover.copys.Parentevents) do
                    e.loop = 0
                end
                local num9 = MathHelper.Lerp(-cover.copys.rand.speed, cover.copys.rand.speed, Main.rand.NextDouble())
                local num10 = math.floor(MathHelper.Lerp(-cover.copys.rand.speedd, cover.copys.rand.speedd, Main.rand.NextDouble()))
                local num11 = MathHelper.Lerp(-cover.copys.rand.aspeed, cover.copys.rand.aspeed, Main.rand.NextDouble())
                local num12 = math.floor(MathHelper.Lerp(-cover.copys.rand.aspeedd, cover.copys.rand.aspeedd, Main.rand.NextDouble()))
                cover.copys.aspeed = cover.copys.aspeed + num11
                cover.copys.aspeedd = cover.copys.aspeedd + num12
                cover.copys.speed = cover.copys.speed + num9
                cover.copys.speedd = cover.copys.speedd + num10
                cover.copys.aspeedx = cover.copys.aspeed * Math.Cos(MathHelper.ToRadians(cover.copys.aspeedd))
                cover.copys.aspeedy = cover.copys.aspeed * Math.Sin(MathHelper.ToRadians(cover.copys.aspeedd))
                cover.copys.speedx = cover.copys.speed * Math.Cos(MathHelper.ToRadians(cover.copys.speedd))
                cover.copys.speedy = cover.copys.speed * Math.Sin(MathHelper.ToRadians(cover.copys.speedd))
                for _, event8 in ipairs(cover.Parentevents) do
                    for _, e in ipairs(event8.events) do
                        event8:addCoverParentEvent(e)
                    end
                end
                for _, event9 in ipairs(cover.Sonevents) do
                    for _, e in ipairs(event9.events) do
                        event9:addCoverChildEvent(e)
                    end
                end
            end
            for _, rebound in ipairs(layer.ReboundArray) do
                rebound.Selecting = false
                rebound.copys = rebound:copy()
                local num13 = MathHelper.Lerp(-rebound.copys.rand.speed, rebound.copys.rand.speed, Main.rand.NextDouble())
                local num14 = math.floor(MathHelper.Lerp(-rebound.copys.rand.speedd, rebound.copys.rand.speedd, Main.rand.NextDouble()))
                local num15 = MathHelper.Lerp(-rebound.copys.rand.aspeed, rebound.copys.rand.aspeed, Main.rand.NextDouble())
                local num16 = math.floor(MathHelper.Lerp(-rebound.copys.rand.aspeedd, rebound.copys.rand.aspeedd, Main.rand.NextDouble()))
                rebound.copys.aspeed = rebound.copys.aspeed + num15
                rebound.copys.aspeedd = rebound.copys.aspeedd + num16
                rebound.copys.speed = rebound.copys.speed + num13
                rebound.copys.speedd = rebound.copys.speedd + num14
                rebound.copys.aspeedx = rebound.copys.aspeed * Math.Cos(MathHelper.ToRadians(rebound.copys.aspeedd))
                rebound.copys.aspeedy = rebound.copys.aspeed * Math.Sin(MathHelper.ToRadians(rebound.copys.aspeedd))
                rebound.copys.speedx = rebound.copys.speed * Math.Cos(MathHelper.ToRadians(rebound.copys.speedd))
                rebound.copys.speedy = rebound.copys.speed * Math.Sin(MathHelper.ToRadians(rebound.copys.speedd))
            end
            for _, force in ipairs(layer.ForceArray) do
                force.Selecting = false
                force.copys = force:copy()
                local num17 = MathHelper.Lerp(-force.copys.rand.speed, force.copys.rand.speed, Main.rand.NextDouble())
                local num18 = math.floor(MathHelper.Lerp(-force.copys.rand.speedd, force.copys.rand.speedd, Main.rand.NextDouble()))
                local num19 = MathHelper.Lerp(-force.copys.rand.aspeed, force.copys.rand.aspeed, Main.rand.NextDouble())
                local num20 = math.floor(MathHelper.Lerp(-force.copys.rand.aspeedd, force.copys.rand.aspeedd, Main.rand.NextDouble()))
                force.copys.aspeed = force.copys.aspeed + num19
                force.copys.aspeedd = force.copys.aspeedd + num20
                force.copys.speed = force.copys.speed + num17
                force.copys.speedd = force.copys.speedd + num18
                force.copys.aspeedx = force.copys.aspeed * Math.Cos(MathHelper.ToRadians(force.copys.aspeedd))
                force.copys.aspeedy = force.copys.aspeed * Math.Sin(MathHelper.ToRadians(force.copys.aspeedd))
                force.copys.speedx = force.copys.speed * Math.Cos(MathHelper.ToRadians(force.copys.speedd))
                force.copys.speedy = force.copys.speed * Math.Sin(MathHelper.ToRadians(force.copys.speedd))
            end
        end
        M.now = M.now - 1
    end
end

function M._pause()
    if M.Playing then
        M.Pause = true
    end
    M.Playing = false
end

function M._stop()
    local Center = require('game.mbg.Center')
    local Player = require('game.mbg.Player')
    local Layer = require('game.mbg.Layer')

    M.Playing = false
    M.Pause = false
    Player.clear()
    M.now = 1
    M.left = 1
    for _, globalEvent2 in ipairs(M.GE) do
        globalEvent2.gtcount = 0
        globalEvent2.qtcount = 0
        globalEvent2.stcount = 0
    end
    M.stop = 1
    M.quake = Vector2(0, 0)
    for _, layer7 in ipairs(Layer.LayerArray) do
        for _, batch3 in ipairs(layer7.BatchArray) do
            batch3.Eventsexe = {}
            for _, e in ipairs(batch3.Parentevents) do
                e.results = {}
            end
            for _, e in ipairs(batch3.Sonevents) do
                e.results = {}
            end
        end
        for _, lase3 in ipairs(layer7.LaseArray) do
            lase3.Eventsexe = {}
            for _, e in ipairs(lase3.Parentevents) do
                e.results = {}
            end
            for _, e in ipairs(lase3.Sonevents) do
                e.results = {}
            end
        end
        for _, cover3 in ipairs(layer7.CoverArray) do
            cover3.Eventsexe = {}
            for _, e in ipairs(cover3.Parentevents) do
                e.results = {}
            end
            for _, e in ipairs(cover3.Sonevents) do
                e.results = {}
            end
        end
        Center.Eventsexe = {}
        layer7.Barrages = {}
    end
end

return M
