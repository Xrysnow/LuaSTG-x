---
--- Layer.lua
---
--- Copyright (C) 2018 Xrysnow. All rights reserved.
---

local mbg = require('util.mbg.main')

---@class mbg.Layer
local Layer = {}
mbg.Layer = Layer

local function _Layer()
    ---@type mbg.Layer
    local ret       = {}
    ret.Name           = ''
    ret.Life           = mbg.Life()
    ---@type mbg.BulletEmitter[]
    ret.BulletEmitters = {}
    ---@type mbg.ReflexBoard[]
    ret.ReflexBoards   = {}
    ---@type mbg.ForceField[]
    ret.ForceFields    = {}
    ---@type mbg.Mask[]
    ret.Masks          = {}
    ---@type mbg.LazerEmitter[]
    ret.LazerEmitters  = {}
    ret.LoadContent = Layer.LoadContent
    ret.FindBulletEmitterByID = Layer.FindBulletEmitterByID
    return ret
end

local mt = {
    __call = function()
        return _Layer()
    end
}
setmetatable(Layer, mt)

---LoadContent
---@param _mbg mbg.String
---@param bulletEmitterCount number
---@param lazerEmitterCount number
---@param maskEmitterCount number
---@param reflexBoardCount number
---@param forceFieldCount number
function Layer:LoadContent(_mbg,
                               bulletEmitterCount,
                               lazerEmitterCount,
                               maskEmitterCount,
                               reflexBoardCount,
                               forceFieldCount)
    local linkers       = {}
    self.BulletEmitters = {}
    for i = 1, bulletEmitterCount do
        local i1, i2 = mbg.BulletEmitter.ParseFrom(_mbg:readline(), self)
        table.insert(linkers, i2)
        table.insert(self.BulletEmitters, i1)
    end
    self.LazerEmitters = {}
    for i = 1, lazerEmitterCount do
        local i1, i2 = mbg.LazerEmitter.ParseFrom(_mbg:readline(), self)
        table.insert(linkers, i2)
        table.insert(self.LazerEmitters, i1)
    end
    self.Masks = {}
    for i = 1, maskEmitterCount do
        local i1, i2 = mbg.Mask.ParseFrom(_mbg:readline(), self)
        table.insert(linkers, i2)
        table.insert(self.Masks, i1)
    end
    self.ReflexBoards = {}
    for i = 1, reflexBoardCount do
        table.insert(self.ReflexBoards, mbg.ReflexBoard.ParseFrom(_mbg:readline()))
    end
    self.ForceFields = {}
    for i = 1, forceFieldCount do
        table.insert(self.ForceFields, mbg.ForceField.ParseFrom(_mbg:readline()))
    end

    for _, l in pairs(linkers) do
        l()
    end
end

---FindBulletEmitterByID
---@param id number
---@return mbg.BulletEmitter
function Layer:FindBulletEmitterByID(id)
    for _, i in pairs(self.BulletEmitters) do
        if i.ID == id then
            return i
        end
    end
    error('找不到子弹发射器: ' .. id)
end

---ParseFrom
---@param content mbg.String
---@param _mbg mbg.String
---@return mbg.Layer
function Layer.ParseFrom(content, _mbg)
    if content:equalto("empty") then
        return nil
    else
        local layer              = mbg.Layer()
        layer.Name               = mbg.ReadString(content)
        layer.Life.Begin         = mbg.ReadString(content):toint()
        layer.Life.LifeTime      = mbg.ReadString(content):toint()
        local bulletEmitterCount = mbg.ReadString(content):toint()
        local lazerEmitterCount  = mbg.ReadString(content):toint()
        local maskEmitterCount   = mbg.ReadString(content):toint()
        local reflexBoardCount   = mbg.ReadString(content):toint()
        local forceFieldCount    = mbg.ReadString(content):toint()

        layer:LoadContent(
                _mbg,
                bulletEmitterCount,
                lazerEmitterCount,
                maskEmitterCount,
                reflexBoardCount,
                forceFieldCount)

        return layer
    end
end

