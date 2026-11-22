---
--- misc.lua
---
--- Copyright (C) 2018-2020 Xrysnow. All rights reserved.
---


---字符串自动换行
---注意：[\n] 会被忽略
---@param font string
---@param str string
---@param width number
---@return string
function ArrangeLine(font, str, width)
    local ss = String.SplitText(str)
    local ws = {}
    local w, h = 0, 0
    for i, v in pairs(ss) do
        w, h = CalcTextSize(font, v)
        table.insert(ws, w)
    end

    local ww = 0
    local offset = 0
    for i, v in pairs(ws) do
        ww = ww + ws[i]
        if ww > width then
            table.insert(ss, i + offset, '\n')
            offset = offset + 1
            ww = ws[i]
        end
    end
    return table.concat(ss), offset + 1
end

---段落自动换行
---@param font string
---@param str string
---@param width number
---@return string
function ArrangeParagraph(font, str, width)
    local lines = String.SplitLines(str)
    local p = {}
    for i, line in pairs(lines) do
        if line == '' then
            table.insert(p, '')
        else
            local l = ArrangeLine(font, line, width)
            table.insert(p, l)
        end
    end
    return table.concat(p, '\n')
end
--[[
---展开参数
---Example: ParamsDeploy(self,params,{a=1})
---@param tgt object @目标
---@param src table @参数
---@param dft table @默认值
function ParamsDeploy(tgt, src, dft)
    for k, v in pairs(dft) do
        tgt[k] = v
    end
    for k, v in pairs(src) do
        tgt[k] = v
    end
end
--]]
