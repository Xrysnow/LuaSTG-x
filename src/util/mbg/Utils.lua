---
--- Utils.lua
---
--- Copyright (C) 2018 Xrysnow. All rights reserved.
---

local mbg = require('util.mbg.main')

---ReadString
---@param line mbg.String
---@param splitter string optional
---@return mbg.String
function mbg.ReadString(line, splitter)
    splitter = splitter or ','
    if line:isempty() then
        error("无法从空字符串读取信息")
    end
    local spl = line:find(splitter)
    if spl > 0 then
        local ret = line:read(spl - 1)
        line:read(#splitter)
        return ret;
    else
        return line:readall()
    end
end

---@param line mbg.String
---@param splitter string optional
function mbg.ReadBool(line, splitter)
    local s = mbg.ReadString(line, splitter):tostring()
    assert(s == 'True' or s == 'true' or s == 'False' or s == 'false')
    return s == 'True' or s == 'true'
end

---@param line mbg.String
---@param splitter string optional
function mbg.ReadUInt(line, splitter)
    local ret = math.floor(mbg.ReadString(line, splitter):tonumber())
    assert(ret >= 0)
    return ret
end

---@param line mbg.String
---@param splitter string optional
function mbg.ReadInt(line, splitter)
    return math.floor(mbg.ReadString(line, splitter):tonumber())
end

---@param line mbg.String
---@param splitter string optional
function mbg.ReadDouble(line, splitter)
    return mbg.ReadString(line, splitter):tonumber()
end

---ReadPosition
---@param line mbg.String
---@param splitter string optional
function mbg.ReadPosition(line, splitter)
    splitter = splitter or ','
    local content = mbg.ReadString(line, splitter)

    local px1 = content:find(':')
    local px2 = content:find('Y')

    local py1 = content:findlast(':')
    local py2 = content:findlast('}')

    local p = mbg.Position()
    p.X = content:sub(px1 + 1, px2 - 1):trim():tonumber()
    p.Y = content:sub(py1 + 1, py2 - 1):trim():tonumber()

    return p
end
