--
local M = {}

---@param data mbg.MBGData
function M.Open(data)
    local Center = require('game.mbg.Center')
    local Batch = require('game.mbg.Batch')
    local Force = require('game.mbg.Force')
    local GlobalEvent = require('game.mbg.GlobalEvent')
    local Layer = require('game.mbg.Layer')
    local Main = require('game.mbg.Main')
    local Time = require('game.mbg.Time')

    Main.Available = true
    Layer.clear()
    Center.clear()
    --History.clear()
    Time.clear()

    if data.GlobalEvents then
        for i, e in ipairs(data.GlobalEvents) do
            local globalEvent = GlobalEvent()
            local Frame = e.Frame
            table.insert(Time.GEcount, Frame - 1)
            --globalEvent.gotocondition = e['1']
            --globalEvent.gotoopreator = e['2']
            --globalEvent.gotocvalue = e['3']
            globalEvent.isgoto = e.JumpEnabled
            globalEvent.gototime = e.JumpTimes
            globalEvent.gotowhere = e.JumpTarget
            --globalEvent.quakecondition = e['7']
            --globalEvent.quakeopreator = e['8']
            --globalEvent.quakecvalue = e['9']
            globalEvent.isquake = e.VibrateEnabled
            globalEvent.quaketime = e.VibrateTime
            globalEvent.quakelevel = e.VibrateForce
            --globalEvent.stopcondition = e['13']
            --globalEvent.stopopreator = e['14']
            --globalEvent.stopcvalue = e['15']
            globalEvent.isstop = e.SleepEnabled
            globalEvent.stoptime = e.SleepTime
            globalEvent.stoplevel = e.SleepType
            if #Time.GE < Frame then
                for k = 1, Frame do
                    local globalEvent2 = GlobalEvent()
                    globalEvent2.gotocondition = -1
                    globalEvent2.quakecondition = -1
                    globalEvent2.stopcondition = -1
                    globalEvent2.stoplevel = -1
                    table.insert(Time.GE, globalEvent2)
                end
            end
            Time.GE[Frame] = globalEvent
        end
    end
    if data.Sounds then
        --
    end
    if data.Center then
        Center.Available = true
        Center.x = data.Center.Position.X
        Center.y = data.Center.Position.Y
        local Motion = data.Center.Motion
        if Motion then
            Center.speed = Motion.Speed
            Center.speedd = Motion.SpeedDirection
            Center.aspeed = Motion.Acceleration
            Center.aspeedd = Motion.AccelerationDirection
        end
        if data.Center.Events then
            for _, v in ipairs(data.Center.Events) do
                table.insert(Center.events, v)
            end
        end
    else
        Center.Available = false
    end
    Time.total = data.TotalFrame
    for i = 1, 4 do
        ---@type mbg.Layer
        local layerData = data['Layer' .. i]
        if layerData then
            local layer = Layer(layerData.Name, layerData.Life.Begin, layerData.Life.LifeTime)
            for _, batchData in ipairs(layerData.BulletEmitters) do
                local batch = Batch(batchData)
                --table.insert(Layer.LayerArray[i].BatchArray, batch)
                table.insert(layer.BatchArray, batch)
            end
            for _, laserData in ipairs(layerData.LazerEmitters) do
                --
            end
            for _, maskData in ipairs(layerData.Masks) do
                --
            end
            for _, rbData in ipairs(layerData.ReflexBoards) do
                --
            end
            for _, forceData in ipairs(layerData.ForceFields) do
                local force = Force(forceData)
                table.insert(layer.ForceArray, force)
            end
        end
    end
end

return M
