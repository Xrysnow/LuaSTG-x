--
local pairs = pairs
local ipairs = ipairs

--- 返回通过将函数应用于每个元素而生成的元素平均值
function table.average_by(t, fn)
    local sum
    for _, v in pairs(t) do
        if sum then
            sum = sum + fn(v)
        else
            sum = fn(v)
        end
    end
    return sum
end

--- 将给定函数应用于列表的每个元素。
--- 返回由各元素（该函数返回了非nil/false）的结果组成的列表
---@param t table
---@param fn fun(v:any):any
function table.choose(t, fn)
    local ret = {}
    for k, v in pairs(t) do
        local u = fn(v)
        if u then
            ret[k] = u
        end
    end
    return ret
end

--- 对列表的每个元素应用给定函数。连接所有结果并返回组合列表。
---@param t table
---@param fn fun(v:any):table
function table.collect(t, fn)
    local ret = {}
    for _, v in pairs(t) do
        for _, u in ipairs(fn(v)) do
            table.insert(ret, u)
        end
    end
    return ret
end

function table.exists(t, fn)
    for _, v in pairs(t) do
        if fn(v) then
            return true
        end
    end
    return false
end

function table.exists2(t1, t2, fn)
    for k, v in pairs(t1) do
        if fn(v, t2[k]) then
            return true
        end
    end
    return false
end

--- 返回一个新集合，其中仅包含给定谓词为其返回 true 的集合的元素
---@param t table
---@param fn fun(v:any):boolean
function table.filter(t, fn)
    local ret = {}
    for k, v in pairs(t) do
        if fn(v) then
            ret[k] = v
        end
    end
    return ret
end

--- 返回给定函数为其返回 true 的第一个元素
function table.ffind(t, fn)
    for _, v in pairs(t) do
        if fn(v) then
            return v
        end
    end
end

--- 返回满足给定谓词的列表中第一个元素的索引
function table.ffindkey(t, fn)
    for k, v in pairs(t) do
        if fn(v) then
            return k
        end
    end
end

--- 测试集合的所有元素是否满足给定谓词
function table.forall(t,fn)
    for _, v in pairs(t) do
        if not fn(v) then
            return false
        end
    end
    return true
end

--- 创建一个新集合，其元素是将给定函数应用于集合的每个元素的结果
function table.map(t, fn)
    local ret = {}
    for k, v in pairs(t) do
        ret[k] = fn(v)
    end
    return ret
end
