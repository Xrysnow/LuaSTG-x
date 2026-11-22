---
--- MBGData.lua
---
--- Copyright (C) 2018 Xrysnow. All rights reserved.
---

local mbg = require('util.mbg.main')

---@class mbg.MBGData
local MBGData = {}
mbg.MBGData = MBGData

local function _MBGData()
    ---@type mbg.MBGData
    local ret = {}
    ret.Version = ''
    ret.TotalFrame = 0
    ret.Center = mbg.Center()
    ret.Layer1 = mbg.Layer()
    ret.Layer2 = mbg.Layer()
    ret.Layer3 = mbg.Layer()
    ret.Layer4 = mbg.Layer()
    ---@type mbg.Sound[]
    ret.Sounds = {}
    ---@type mbg.GlobalEvents[]
    ret.GlobalEvents = {}

    ret.ProcessNormalTitle = MBGData.ProcessNormalTitle
    ret.ProcessNumberTitle = MBGData.ProcessNumberTitle
    ret.GlobalEvent = MBGData.GlobalEvent

    return ret
end

local mt = {
    __call = function()
        return _MBGData()
    end
}
setmetatable(MBGData, mt)

---ProcessNormalTitle
---@param title mbg.String
---@param content mbg.String
---@param _mbg mbg.String
function MBGData:ProcessNormalTitle(title, content, _mbg)
    local s = title:tostring()
    if s == 'Center' then
        self.Center = mbg.Center.ParseFromContent(content)
    elseif s == 'Totalframe' then
        self.TotalFrame = content:toint()
    elseif s == 'Layer1' then
        self.Layer1 = mbg.Layer.ParseFrom(content, _mbg)
    elseif s == 'Layer2' then
        self.Layer2 = mbg.Layer.ParseFrom(content, _mbg)
    elseif s == 'Layer3' then
        self.Layer3 = mbg.Layer.ParseFrom(content, _mbg)
    elseif s == 'Layer4' then
        self.Layer4 = mbg.Layer.ParseFrom(content, _mbg)
    else
        error("未知的标签:" .. title:tostring())
    end
end

---ProcessNumberTitle
---@param title mbg.String
---@param _mbg mbg.String
function MBGData:ProcessNumberTitle(title, _mbg)
    if title:contains("Sounds") then
        self.Sounds = mbg.Sound.ParseSounds(title, _mbg)
        return true
    elseif title:contains("GlobalEvents") then
        self.GlobalEvents = mbg.GlobalEvents.ParseEvents(title, _mbg)
        return true
    end
    return false
end

function MBGData:GlobalEvent(title, _mbg)
    error('Not implemented.')
end

---ParseFrom
---@param mbgData mbg.String
---@return mbg.MBGData
function MBGData.ParseFrom(mbgData)
    local _mbg = mbgData:copy()
    ---@type mbg.MBGData
    local data = mbg.MBGData()
    data.Version = _mbg:readline()

    local version = data.Version:tostring()
    if version ~= "Crazy Storm Data 1.01" then
        error("未知版本的CrazyStorm数据：" .. version)
    end
    while _mbg:peek() ~= -1 do
        local content = _mbg:readline();
        if content and not content:isempty() then
            local title = mbg.ReadString(content, ':')

            local processed = data:ProcessNumberTitle(title, _mbg)
            if not processed then
                data:ProcessNormalTitle(title, content, _mbg)
            end
        end
    end
    return data
end

