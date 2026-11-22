--

---@type lstg.Random
local M = lstg.Random
local insert = table.insert
local floor = math.floor
local pow = math.pow
local log = math.log

--- Choose a random element from a non-empty array.
---@param array table
function M:choice(array)
    local len = #array
    if len == 0 then
        return
    end
    return array[self:below(len) + 1]
end

--- Shuffle array in place.
---@param array table
function M:shuffle(array)
    for i = #array, 2, -1 do
        local j = self:below(i) + 1
        array[i], array[j] = array[j], array[i]
    end
end

--- Chooses k unique random elements from an array.
---
--- Returns a new array.
---@param array table
---@param k number
---@return table
function M:sample(array, k)
    local n = #array
    if k > n or n == 0 then
        return {}
    end
    local result = {}
    local mark = {}
    for i = 1, k do
        local j = self:below(k - i + 1) + 1
        insert(result, array[mark[j] or j])
        mark[j] = mark[k - i + 1] or n - i + 1
    end
    return result
end

--- Chooses k unique random numbers from a range.
---
--- Returns an array.
---@param start number
---@param stop number
---@param step number
---@param k number
---@return table
function M:sample_range(start, stop, step, k)
    if start == stop or step == 0 then
        return {}
    end
    local width = stop - start
    local n
    if step > 0 then
        n = (width + step - 1) / step
    else
        n = (width + step + 1) / step
    end
    n = floor(n)
    if n <= 0 then
        return {}
    end
    local result = {}
    local mark = {}
    for i = 1, k do
        local j = self:below(i) + 1
        insert(result, start + step * (mark[j] or j - 1))
        mark[j] = mark[k - i + 1] or n - i + 1
    end
    return result
end

--- Chooses k unique random elements from an array by given weight.
---
--- Reference: https://www.sciencedirect.com/science/article/abs/pii/S002001900500298X
---
--- Returns an array.
---@param array table
---@param weight table
---@param k number
---@return table
function M:sample_weighted(array, weight, k)
    local n = #array
    if k > n or n == 0 or k < 1 then
        return {}
    end
    local heap = {}
    local Xw
    local Tw, w_acc = 0, 0
    for i, sample in ipairs(array) do
        if #heap < k then
            local wi = weight[i] or 0
            local ui = self:uniform(0, 1)
            local ki = pow(ui, 1 / wi)
            insert(heap, { ki, sample })
            if #heap == k then
                table.sort(heap, function(a, b)
                    return a[1] > b[1]
                end)
            end
            -- continue
        else
            if w_acc == 0 then
                Tw = heap[#heap][1]
                local r = self:uniform(0, 1)
                Xw = log(r) / log(Tw)
            end
            local wi = weight[i] or 0
            if w_acc + wi < Xw then
                w_acc = w_acc + wi
                -- continue
            else
                w_acc = 0
                local tw = pow(Tw, wi)
                local r2 = self:uniform(tw, 1)
                local ki = pow(r2, 1 / wi)
                heap[#heap] = nil
                if #heap == 0 or ki > heap[1][1] then
                    insert(heap, 1, { ki, sample })
                elseif ki <= heap[#heap][1] then
                    insert(heap, { ki, sample })
                else
                    for j = 1, k - 1 do
                        if heap[j][1] >= ki and ki > heap[j + 1][1] then
                            insert(heap, j, { ki, sample })
                            break
                        end
                    end
                end
            end
        end
    end
    local result = {}
    for _, v in ipairs(heap) do
        insert(result, v[2])
    end
    return result
end
