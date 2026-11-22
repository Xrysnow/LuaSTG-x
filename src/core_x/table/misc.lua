--
local pairs = pairs
local ipairs = ipairs

function table.append(t1, t2)
    local ret = {}
    for k, v in pairs(t1) do
        ret[k] = v
    end
    for k, v in pairs(t2) do
        ret[k] = v
    end
    return ret
end

--- 返回元素的平均值
function table.average(t)
    local sum
    for _, v in pairs(t) do
        if sum then
            sum = sum + v
        else
            sum = v
        end
    end
    return sum
end

--- 如果列表不包含任何元素，则返回 true；否则返回 false
function table.is_empty(t)
    for _, _ in pairs(t) do
        return false
    end
    return true
end

function table.length(t)
    local ret = 0
    for _, _ in pairs(t) do
        ret = ret + 1
    end
    return ret
end
