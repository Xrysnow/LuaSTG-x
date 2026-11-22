---@type mbg
local mbg = require('util.mbg.main')
require('util.mbg.Components.__init__')
require('util.mbg.Event.__init__')
require('util.mbg.Common')
require('util.mbg.Center')
require('util.mbg.Layer')
require('util.mbg.MBGData')
require('util.mbg.Sound')
require('util.mbg.String')
require('util.mbg.Utils')

---@return mbg.MBGData
function mbg.Parse(s)
    s = s:gsub('\r', '')
    return mbg.MBGData.ParseFrom(mbg.String(s))
end

local test2 = [[Crazy Storm Data 1.01
3 GlobalEvents:
77_-1_=_0_True_1_100_-1_>_0_True_1_100_-1_>_100_True_150_0
1_-1_=_0_True_10_1_-1_=_0_True_1000_1_-1_=_0_True_1000_0
20_-1_<_128_True_123_26_-1_>_44_True_1210_1220_-1_>_1120_True_120_0
1 Sounds:
1_tan00.wav_10
Center:315,240,0,0,0,0,当前帧=120且当前帧>50：范围移动，172，460，112，112;当前帧=120：范围移动，172，460，112，112;当前帧=120：范围移动，172，460，112，112;
Totalframe:3123
Layer1:2,123,123,0,0,0,0,0
Layer2:32123,3123,3123,0,0,0,0,0
Layer3:21312,13,13,0,0,0,0,0
Layer4:新图层 ,1,200,3,1,1,1,1
0,3,False,-1,False,,160,96,1,200,-99998,-99998,0,0,{X:0 Y:0},1,5,16,{X:0 Y:0},360,0,0,{X:0 Y:0},0,0,{X:0 Y:0},200,1,1,1,255,255,255,100,0,{X:0 Y:0},True,5,0,{X:0 Y:0},0,0,{X:0 Y:0},1,1,True,True,False,False,True,False,新事件组|34|12|当前帧=12或当前帧=177：半径增加124，正比，12帧;&,新事件组|1|0|当前帧=1：生命变化到1，正比，1帧;&,0,0,0,0,0,0,5,0,0,0,0,0,0,0,0,0,0,True,True,True,False
1,3,False,-1,False,,224,224,123,1,-99998,-99998,0,0,{X:0 Y:0},1,5,0,{X:0 Y:0},360,0,0,{X:0 Y:0},0,0,{X:0 Y:0},200,1,1,1,255,255,255,100,0,{X:0 Y:0},True,5,0,{X:0 Y:0},0,0,{X:0 Y:0},1,1,True,True,False,False,True,False,,,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,True,True,True,False
2,3,False,-1,False,,192,320,123,1,-99998,-99998,0,0,{X:0 Y:0},1,5,0,{X:0 Y:0},360,0,0,{X:0 Y:0},0,0,{X:0 Y:0},200,1,1,1,255,255,255,100,0,{X:0 Y:0},True,5,0,{X:0 Y:0},0,0,{X:0 Y:0},1,1,True,True,False,False,True,False,,,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,True,True,True,False
0,3,False,-1,False,,192,96,1,200,0,0,{X:0 Y:0},1,5,0,{X:0 Y:0},360,0,0,{X:0 Y:0},0,0,{X:0 Y:0},200,0,1,100,100,False,5,0,{X:0 Y:0},0,0,{X:0 Y:0},1,1,False,True,False,,,,0,0,0,0,0,0,0,0,0,0,0,0,0,0,False
0,3,224,96,1,200,100,100,False,0,1,0,0,{X:0 Y:0},0,0,{X:0 Y:0},,,0,0,0,0,-1,False
0,3,256,96,1,200,100,0,1,0,0,0,0,,0,0,0,0,
0,3,288,96,1,200,100,100,False,0,1,0,0,0,0,0,0,False,False,0,0,0,0,0,
]]

function mbg.Serialize(o, tab, rec)
    tab = tab or 0
    rec = rec or {}
    if type(o) == 'number' then
        return tostring(o)
    elseif type(o) == 'string' then
        return string.format('%q', o)
    elseif type(o) == 'boolean' then
        return tostring(o)
    elseif type(o) == 'nil' then
        return 'nil'
    elseif type(o) == 'table' then
        if getmetatable(o) == getmetatable(mbg.String) then
            return string.format('%q', o.string)
        else
            if rec[o] then
                return tostring(o)
            else
                rec[o] = true
                local r = '{\n'
                for k, v in pairs(o) do
                    if type(v) ~= 'function' then
                        if type(k) == 'number' then
                            k = '[' .. k .. ']'
                        elseif type(k) == 'string' then
                            k = string.format('[%q]', k)
                        else
                            error('cannot serialize a ' .. type(k) .. ' key')
                        end
                        r = r .. string.rep('\t', tab + 1) .. k .. '=' .. mbg.Serialize(v, tab + 1, rec) .. ',\n'
                    end
                end
                return r .. string.rep('\t', tab) .. '}'
            end
        end
    else
        return ''
    end
end

--[[
local fu = cc.FileUtils:getInstance()
local list = fu:listFiles('Example')
for i, v in ipairs(list) do
    if string.fileext(v) == 'mbg' then
        --print(v)
        local s = fu:getStringFromFile(v)
        assert(s ~= '', v)
        local m = mbg.Parse(s)
        local str = mbg.Serialize(m)
        local fp = fu:fullPathForFilename('Example/')
        local path = fp .. string.filename(v) .. '.lua'
        print(path)
        fu:writeStringToFile(str, path)
    end
end
--]]
--[[
local m = mbg.Parse(test2)
SystemLog('\n\n')
SystemLog(mbg.Serialize(m))
SystemLog('\n\n')
--]]
return mbg
