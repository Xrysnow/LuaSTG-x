---@class lstg.MBGPlayer:xobject
local M = xclass()
local mbg = require('util.mbg.__init__')
local Main = require('game.mbg.Main')

function M:init(path)
    self.bound = false
    self.layer = LAYER_TOP + 100

    assert(type(path) == 'string')
    local s = cc.FileUtils:getInstance():getStringFromFile(path)
    if s == '' then
        print('failed to load', path)
    end
    local ok, ret = pcall(mbg.Parse, s)
    if not ok then
        print(ret)
        return
    end
    ---@type mbg.MBGData
    self._data = ret
    local data = self._data
    self._nFrame = data.TotalFrame
    --
    if not Main.rand then
        Main.initialize()
    end
    Main.loadContent()
    require('game.mbg.Opening').Open(data)
    require('game.mbg.Time')._play()
end

function M:frame()
    if not self._data then
        return
    end
    Main.update()
    Main.draw()
end

function M:render()
    if not self._data then
        return
    end
    SetViewMode('world')
    local Layer = require('game.mbg.Layer')
    local num = { #Layer.LayerArray }
    for _, layer in ipairs(Layer.LayerArray) do
        --table.insert(num, #layer.Barrages)
        table.insert(num, #layer.BatchArray)
        for _, b in ipairs(layer.Barrages) do
            b:draw()
        end
    end
    --local Time = require('game.mbg.Time')
    --RenderText('menu', table.concat(num, ','), 0, 0, 0.5)
    --RenderText('menu', ('Play:%s'):format(Time.Playing), 0, -20, 0.5)

    local la1 = Layer.LayerArray[1]
    local str = ('%d'):format(#(la1.Barrages))
    if la1._Tb then
        str = str .. (' %.1f'):format(la1._Tb)
    end
    RenderText('menu', str, 0, -200, 0.5)
end

return M
