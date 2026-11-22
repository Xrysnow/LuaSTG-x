--
local M = {}
local Math = require('game.mbg._math')
--local MathHelper = Math

M.display = { X = 0, Y = 0 }
M.WindowTitle = ""
M.QuantityTag = ""
M.BindTag = ""
M.LifeTag = ""
M.WideScreen = false
M.Grid = false
M.Missable = false
M.Tip = false
M.path = ""
M.registData = ""
M.name = ""
M.Available = false

-- Hashtable
M.conditions = {}
M.results = {}
M.type = {}
M.conditions2 = {}
M.results2 = {}
M.results3 = {}
M.cconditions = {}
M.cresults = {}
M.lconditions = {}
M.lresults = {}
M.lresults2 = {}

function M.initialize()
    M.rand = {
        NextDouble = function()
            return ran:Float(0, 1)
        end
    }
    M.type["正比"] = 0
    M.type["固定"] = 1
    M.type["正弦"] = 2
    M.conditions[""] = 0
    M.conditions["当前帧"] = 0
    M.conditions["X坐标"] = 1
    M.conditions["Y坐标"] = 2
    M.conditions["半径"] = 3
    M.conditions["半径方向"] = 4
    M.conditions["条数"] = 5
    M.conditions["周期"] = 6
    M.conditions["角度"] = 7
    M.conditions["范围"] = 8
    M.conditions["宽比"] = 9
    M.conditions["高比"] = 10
    M.conditions["不透明度"] = 11
    M.conditions["朝向"] = 12
    M.results["X坐标"] = 0
    M.results["Y坐标"] = 1
    M.results["半径"] = 2
    M.results["半径方向"] = 3
    M.results["条数"] = 4
    M.results["周期"] = 5
    M.results["角度"] = 6
    M.results["范围"] = 7
    M.results["速度"] = 8
    M.results["速度方向"] = 9
    M.results["加速度"] = 10
    M.results["加速度方向"] = 11
    M.results["生命"] = 12
    M.results["类型"] = 13
    M.results["宽比"] = 14
    M.results["高比"] = 15
    M.results["R"] = 16
    M.results["G"] = 17
    M.results["B"] = 18
    M.results["不透明度"] = 19
    M.results["朝向"] = 20
    M.results["子弹速度"] = 21
    M.results["子弹速度方向"] = 22
    M.results["子弹加速度"] = 23
    M.results["子弹加速度方向"] = 24
    M.results["横比"] = 25
    M.results["纵比"] = 26
    M.results["雾化效果"] = 27
    M.results["消除效果"] = 28
    M.results["高光效果"] = 29
    M.results["拖影效果"] = 30
    M.results["出屏即消"] = 31
    M.results["无敌状态"] = 32
    M.conditions2[""] = 0
    M.conditions2["当前帧"] = 0
    M.conditions2["X坐标"] = 1
    M.conditions2["Y坐标"] = 2
    M.results2["生命"] = 0
    M.results2["类型"] = 1
    M.results2["宽比"] = 2
    M.results2["高比"] = 3
    M.results2["R"] = 4
    M.results2["G"] = 5
    M.results2["B"] = 6
    M.results2["不透明度"] = 7
    M.results2["朝向"] = 8
    M.results2["子弹速度"] = 9
    M.results2["子弹速度方向"] = 10
    M.results2["子弹加速度"] = 11
    M.results2["子弹加速度方向"] = 12
    M.results2["横比"] = 13
    M.results2["纵比"] = 14
    M.results2["雾化效果"] = 15
    M.results2["消除效果"] = 16
    M.results2["高光效果"] = 17
    M.results2["拖影效果"] = 18
    M.results2["出屏即消"] = 19
    M.results2["无敌状态"] = 20
    M.results3["速度"] = 0
    M.results3["速度方向"] = 1
    M.results3["加速度"] = 2
    M.results3["加速度方向"] = 3
    M.cconditions[""] = 0
    M.cconditions["当前帧"] = 0
    M.cconditions["X坐标"] = 1
    M.cconditions["Y坐标"] = 2
    M.cconditions["半宽"] = 3
    M.cconditions["半高"] = 4
    M.cresults["半宽"] = 0
    M.cresults["半高"] = 1
    M.cresults["启用圆形"] = 2
    M.cresults["速度"] = 3
    M.cresults["速度方向"] = 4
    M.cresults["加速度"] = 5
    M.cresults["加速度方向"] = 6
    M.cresults["类型"] = 7
    M.cresults["ID"] = 8
    M.cresults["X坐标"] = 9
    M.cresults["Y坐标"] = 10
    M.lconditions[""] = 0
    M.lconditions["当前帧"] = 0
    M.lconditions["半径"] = 1
    M.lconditions["半径方向"] = 2
    M.lconditions["条数"] = 3
    M.lconditions["周期"] = 4
    M.lconditions["角度"] = 5
    M.lconditions["范围"] = 6
    M.lconditions["宽比"] = 7
    M.lconditions["长度"] = 8
    M.lconditions["不透明度"] = 9
    M.lresults["半径"] = 0
    M.lresults["半径方向"] = 1
    M.lresults["条数"] = 2
    M.lresults["周期"] = 3
    M.lresults["角度"] = 4
    M.lresults["范围"] = 5
    M.lresults["速度"] = 6
    M.lresults["速度方向"] = 7
    M.lresults["加速度"] = 8
    M.lresults["加速度方向"] = 9
    M.lresults["生命"] = 10
    M.lresults["类型"] = 11
    M.lresults["宽比"] = 12
    M.lresults["长度"] = 13
    M.lresults["不透明度"] = 14
    M.lresults["子弹速度"] = 15
    M.lresults["子弹速度方向"] = 16
    M.lresults["子弹加速度"] = 17
    M.lresults["子弹加速度方向"] = 18
    M.lresults["横比"] = 19
    M.lresults["纵比"] = 20
    M.lresults["高光效果"] = 21
    M.lresults["出屏即消"] = 22
    M.lresults["无敌状态"] = 23
    M.lresults2["生命"] = 0
    M.lresults2["类型"] = 1
    M.lresults2["宽比"] = 2
    M.lresults2["长度"] = 3
    M.lresults2["不透明度"] = 4
    M.lresults2["子弹速度"] = 5
    M.lresults2["子弹速度方向"] = 6
    M.lresults2["子弹加速度"] = 7
    M.lresults2["子弹加速度方向"] = 8
    M.lresults2["横比"] = 9
    M.lresults2["纵比"] = 10
    M.lresults2["高光效果"] = 11
    M.lresults2["出屏即消"] = 12
    M.lresults2["无敌状态"] = 13

    M.bgset = {}
    local set = require('game.mbg._set').load()
    for i, v in ipairs(set) do
        table.insert(M.bgset, v)
    end
end

function M.loadContent()
    LoadTexture('mbg.barrages', 'CrazyStorm/barrages.png')
    LoadTexture('mbg.mist', 'CrazyStorm/mist.png')
    LoadTexture('mbg.dis', 'CrazyStorm/dis.png')
    for i, v in ipairs(M.bgset) do
        local name = 'mbg.barrage' .. i
        LoadImage(name, 'mbg.barrages', v.rect.X, v.rect.Y, v.rect.Width, v.rect.Height)
        SetImageCenter(name, v.origin.X, v.origin.Y)
    end
    for i = 1, 8 do
        local name = 'mbg.mist' .. i
        LoadImage(name, 'mbg.mist', (i - 1) * 32, 0, 32, 30)
        SetImageCenter(name, 16, 15)
    end
    for i = 1, 8 do
        local name = 'mbg.dis' .. i
        LoadImage(name, 'mbg.dis', (i - 1) * 32, 0, 32, 32)
        SetImageCenter(name, 16, 16)
    end
end

function M.update()
    local Layer = require('game.mbg.Layer')
    local Time = require('game.mbg.Time')
    local Center = require('game.mbg.Center')
    local Player = require('game.mbg.Player')

    --Sound.update()
    --TopButton.update()
    --ItemButton.update()
    --MidButton.update()
    Layer.aupdate()
    Time.update()
    for i, v in ipairs(Layer.LayerArray) do
        v.sort = i - 1
        v:update()
    end
    Center.update()
    --Selectbox.update()
    Player.update()
end

function M.draw()
    local Layer = require('game.mbg.Layer')
    local Time = require('game.mbg.Time')
    --local Center = require('game.mbg.Center')
    --local Player = require('game.mbg.Player')
    --
    for _, layer in ipairs(Layer.LayerArray) do
        if layer.Visible and not Time.Playing then
            local ForceArray = {}
            for _, v in ipairs(layer.ForceArray) do
                if not v.NeedDelete then
                    table.insert(ForceArray, v)
                    --v:draw()
                end
            end
            layer.ForceArray = ForceArray
            --
            local ReboundArray = {}
            for _, v in ipairs(layer.ReboundArray) do
                if not v.NeedDelete then
                    table.insert(ReboundArray, v)
                    --v:draw()
                end
            end
            layer.ReboundArray = ReboundArray
            --
            local CoverArray = {}
            for _, v in ipairs(layer.CoverArray) do
                if not v.NeedDelete then
                    table.insert(CoverArray, v)
                    --v:draw()
                end
            end
            layer.CoverArray = CoverArray
            --
            local LaseArray = {}
            for _, v in ipairs(layer.LaseArray) do
                if not v.NeedDelete then
                    table.insert(LaseArray, v)
                    --v:draw()
                end
            end
            layer.LaseArray = LaseArray
            --
            local BatchArray = {}
            for _, v in ipairs(layer.BatchArray) do
                if not v.NeedDelete then
                    table.insert(BatchArray, v)
                    --v:draw()
                end
            end
            layer.BatchArray = BatchArray
        end
        local Barrages = {}
        for _, v in ipairs(layer.Barrages) do
            if not v.NeedDelete then
                table.insert(Barrages, v)
                --if v.Blend then
                --    v:draw('Additive')
                --    v:ldraw('Additive')
                --else
                --    v:draw()
                --    v:ldraw()
                --end
            end
        end
        layer.Barrages = Barrages
    end
    --Player.draw()
    --Center.draw()
    --Layer.ldraw()
    local LayerArray = {}
    for _, layer in ipairs(Layer.LayerArray) do
        if not layer.NeedDelete then
            table.insert(LayerArray, layer)
            --layer:draw()
        end
    end
    --Time.draw()
end

function M.Twopointangle(x2, y2, x1, y1)
    local num
    if x2 ~= x1 then
        num = Math.Atan(((y2 - y1) / (x2 - x1)))
    else
        num = Math.Atan(((y2 - y1) / (x2 - x1 + 0.1)))
    end
    if (x2 - x1 < 0) then
        num = num + math.pi
    end
    return num
end

-- private
function M.CrossMul(pt1, pt2)
    return pt1.X * pt2.Y - pt1.Y * pt2.X
end

-- private
function M.CheckCrose(line1, line2)
    local PointF = require('game.mbg.PointF')
    local pointF = PointF()
    local pointF2 = PointF()
    local pointF3 = PointF()
    pointF.X = line2.Start.X - line1.End.X;
    pointF.Y = line2.Start.Y - line1.End.Y;
    pointF2.X = line2.End.X - line1.End.X;
    pointF2.Y = line2.End.Y - line1.End.Y;
    pointF3.X = line1.Start.X - line1.End.X;
    pointF3.Y = line1.Start.Y - line1.End.Y;
    return M.CrossMul(pointF, pointF3) * M.CrossMul(pointF2, pointF3) <= 0
end

function M.CheckTwoLineCrose(line1, line2)
    return M.CheckCrose(line1, line2) and M.CheckCrose(line2, line1)
end

return M
