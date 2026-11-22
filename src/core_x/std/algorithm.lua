---
--- algorithm.lua
---
--- Copyright (C) 2018-2020 Xrysnow. All rights reserved.
---

std = std or {}
local std = std
local table = table
local ipairs = ipairs

---不修改序列的操作

function std.all_of(t, iter, op)
    return not std.find_if_not(t, iter, op)
end

function std.any_of(t, iter, op)
    return std.find_if(t, iter, op)
end

function std.none_of(t, iter, op)
    return not std.find_if(t, iter, op)
end

function std.for_each(t, iter, op)
    for _, v in iter(t) do
        op(v)
    end
end

function std.for_each_n(t, iter, n, op)
    local i = 0
    for _, v in iter(t) do
        op(v)
        i = i + 1
        if i >= n then
            break
        end
    end
end

function std.count(t, iter, val)
    local ret = 0
    for _, v in iter(t) do
        if v == val then
            ret = ret + 1
        end
    end
    return ret
end

function std.count_if(t, iter, op)
    local ret = 0
    for _, v in iter(t) do
        if op(v) then
            ret = ret + 1
        end
    end
    return ret
end

function std.mismatch(t1, iter1, t2, iter2, op)
    op = op or std.equal_to
    local _iter, _t, _i = iter2(t2)
    local v2
    for _, v1 in iter1(t1) do
        _i, v2 = _iter(_t, _i)
        if not _i then
            break
        end
        if not op(v1, v2) then
            return v1, v2
        end
    end
end

function std.find(t, iter, val)
    for _, v in iter(t) do
        if v == val then
            return true
        end
    end
    return false
end

function std.find_if(t, iter, op)
    for _, v in iter(t) do
        if op(v) then
            return true
        end
    end
    return false
end

function std.find_if_not(t, iter, op)
    for _, v in iter(t) do
        if not op(v) then
            return true
        end
    end
    return false
end

function std.find_first_of(t1, itre1, t2, iter2, op)
    op = op or std.equal_to
    local ret = 0
    for _, v1 in itre1(t1) do
        ret = ret + 1
        for _, v2 in iter2(t2) do
            if op(v1, v2) then
                return ret
            end
        end
    end
end

function std.search(t1, iter1, t2, iter2, op)
    op = op or std.equal_to
    local ret = 0
    local find = false
    local _iter1, _t1, _i = iter1(t1)
    for k1, v1 in iter1(t1) do
        ret = ret + 1
        _i = k1
        find = true
        local _v1 = v1
        for _, v2 in iter2(t2) do
            if not op(_v1, v2) then
                find = false
                break
            end
            _v1, _i = _iter1(_t1, _i)
        end
        if find then
            break
        end
    end
    if find then
        return ret
    end
end

---修改序列的操作

function std.copy(t, iter, dst)
    for _, v in iter(t) do
        table.insert(dst, v)
    end
end

function std.copy_if(t, iter, op, dst)
    for _, v in iter(t) do
        if op(v) then
            table.insert(dst, v)
        end
    end
end

function std.fill(t, iter, val)
    for k, _ in iter(t) do
        t[k] = val
    end
end

function std.fill_n(t, iter, n, val)
    local i = 0
    for k, _ in iter(t) do
        t[k] = val
        i = i + 1
        if i >= n then
            break
        end
    end
end

function std.transform(t, iter, f, dst)
    for _, v in iter(t) do
        table.insert(dst, f(v))
    end
end

function std.generate(t, iter, f)
    for k, _ in iter(t) do
        t[k] = f()
    end
end

function std.generate_n(t, iter, n, f)
    local i = 0
    for k, _ in iter(t) do
        t[k] = f()
        i = i + 1
        if i >= n then
            break
        end
    end
end

function std.remove(t, iter, val)
    std.replace(t, iter, val, nil)
end

function std.remove_if(t, iter, op)
    std.replace_if(t, iter, op, nil)
end

function std.replace(t, iter, val, newval)
    for k, v in iter(t) do
        if v == val then
            t[k] = newval
        end
    end
end

function std.replace_if(t, iter, op, newval)
    for k, v in iter(t) do
        if op(v) then
            t[k] = newval
        end
    end
end

function std.random_shuffle(t, r)
    for i = #t, 1 do
        local j = r(i + 1)
        t[i], t[j] = t[j], t[i]
    end
end

function std.unique(t, op)
    op = op or std.equal_to
    local ret = {}
    for i, v in ipairs(t) do
        if op(v, ret[#ret]) then
            table.insert(ret, v)
        end
        t[i] = nil
    end
    for i, v in ipairs(ret) do
        t[i] = v
    end
end

function std.unique_copy(t, dst, op)
    op = op or std.equal_to
    for i, v in ipairs(t) do
        if op(v, dst[#dst]) then
            table.insert(dst, v)
        end
    end
end

---最小/最大操作

function std.max_element(t, op)
    op = op or std.less
    local ret = t[1]
    for _, v in ipairs(t) do
        if op(ret, v) then
            ret = v
        end
    end
    return ret
end

function std.min_element(t, op)
    op = op or std.less
    local ret = t[1]
    for _, v in ipairs(t) do
        if op(v, ret) then
            ret = v
        end
    end
    return ret
end

function std.minmax_element(t, op)
    op = op or std.less
    local _min, _max = t[1], t[1]
    for _, v in ipairs(t) do
        if op(v, _min) then
            _min = v
        end
        if op(_max, v) then
            _max = v
        end
    end
    return _min, _max
end

function std.clamp(v, lo, hi, op)
    op = op or std.less
    if op(v, lo) then
        return lo
    else
        if op(hi, v) then
            return hi
        else
            return v
        end
    end
end

---数值运算

function std.accumulate(t, iter, init, op)
    op = op or std.plus
    for _, v in iter(t) do
        init = op(init, v)
    end
    return init
end

function std.inner_product(t1, t2, v0, op1, op2)
    op1 = op1 or std.plus
    op2 = op2 or std.multiplies
    for i, v1 in ipairs(t1) do
        local v2 = t2[i]
        v0 = op1(v0, op2(v1, v2))
    end
    return v0
end

function std.adjacent_difference(t, iter, dst, op)
    op = op or std.minus
    local last
    for i, v in iter(t) do
        if i > 1 then
            table.insert(dst, op(v, last))
        end
        last = v
    end
end
