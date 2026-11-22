---
--- list.lua
---
--- Copyright (C) 2018-2020 Xrysnow. All rights reserved.
---

std = std or {}


-------------------------------------------------
-- list_iterator
-------------------------------------------------

---
---@class std.list_iterator
---@field prev std.list_iterator
---@field next std.list_iterator
---@field key string
---@field val any
local list_iterator = {}
std.list_iterator = list_iterator

local function iter_ctor(v, prev, next)
    local ret = {
        val  = v,
        prev = prev,
        next = next,
    }
    ret.key = tostring(ret)
    setmetatable(ret, {
        __index = list_iterator
    })
    return ret
end

local mt_list_iterator = {
    __call = function(t, ...)
        return iter_ctor(...)
    end,
}
setmetatable(list_iterator, mt_list_iterator)

function list_iterator:advance(n)
    local ret = self
    for i = 1, n do
        ret = ret.next
    end
    for i = 1, -n do
        ret = ret.prev
    end
    assert(ret)
    return ret
end

function list_iterator:move(n)
    local i = self:advance(n)
    self.val = i.val
    self.prev = i.prev
    self.next = i.next
    self.key = i.key
end

function list_iterator:inc()
    self:move(1)
end

function list_iterator:dec()
    self:move(-1)
end


-------------------------------------------------
-- list
-------------------------------------------------

---
---@class std.list
---@field _begin std.list_iterator
---@field _end std.list_iterator
local list = {}
std.list = list

local function list_ctor(T)
    local ret = {
        _end = {},
    }
    ret._begin = ret._end
    setmetatable(ret._begin, {
        __index = list_iterator
    })
    ret._T = T or 0
    setmetatable(ret, {
        __index = list
    })
    return ret
end
local mt_list = { __call = function(op, param)
    local ty = type(param)
    if std.islist(param) then
        return param:copy()
    elseif std.is_callable(param) then
        return list_ctor(param)
    elseif ty == 'table' then
        local ret = list_ctor()
        for i = 1, #param do
            ret:push_back(param[i])
        end
        return ret
    elseif ty == 'number' or ty == 'string' or ty == 'boolean' then
        return list_ctor(function()
            return param
        end)
    elseif param == nil then
        return list_ctor()
    else
        error("Can't construct list from " .. tostring(param))
    end
end }
setmetatable(list, mt_list)

---alloc
---@param v any
---@param prev std.list_iterator
---@param next std.list_iterator
---@return string,std.list_iterator
local function alloc(v, prev, next)
    local ret = list_iterator(v, prev, next)
    return ret.key, ret
end

--iterators--------------------------------------

---### Return iterator to beginning
---Returns an iterator pointing to the first element in the list container.
---If the container is empty, the returned iterator value shall not be dereferenced.
function list:begin()
    return self._begin
end

---### Return iterator to end
---Returns an iterator referring to the past-the-end element in the list container. It does not point to any element, and thus shall not be dereferenced.
---If the container is empty, this function returns the same as list::begin.
function list:end_()
    return self._end
end

function list:iter()
    return std.list_iter(self)
end

function list:iter_rev()
    return std.list_rev_iter(self)
end

--element access---------------------------------

---### Access first element
---Returns the first element in the list container.
---Calling this function on an empty container causes error.
function list:front()
    assert(not self:empty())
    return self._begin.val
end

---### Access last element
---Returns the last element in the list container.
---Calling this function on an empty container causes error.
function list:back()
    assert(not self:empty())
    return self._end.prev.val
end

function list:at(idx)
    idx = math.floor(idx)
    assert(idx > 0 and idx <= self:size(), string.format('invalid index %d', idx))
    assert(self:begin() and self:begin().advance, stringify(getmetatable(self:begin())))
    return self:begin():advance(idx - 1).val
end

--capacity---------------------------------------

---### Test whether container is empty
---Returns whether the list container is empty (i.e. whether its size is 0).
function list:empty()
    return self._begin.next == nil
end

---### Return size
---Returns the number of elements in the list container.
---@return number
function list:size()
    if self:empty() then
        return 0
    end
    local it = self._begin.next
    local ret = 0
    while it do
        it = it.next
        ret = ret + 1
    end
    return ret
    --for _, __ in pairs(self) do
    --    ret = ret + 1
    --end
    --return ret - 3
end

--modifiers--------------------------------------

---### Clear content
---Removes all elements from the list container, and leaving the container with a size of 0.
function list:clear()
    self:erase(self._begin, self._end)
end

---### Insert elements
---The container is extended by inserting new elements before the element at the specified position.
---Return value: An iterator that points to the first of the newly inserted elements.
---@param it std.list_iterator
---@param v any
---@return std.list_iterator
function list:insert(it, v)
    --Print(stringify(self))
    if self:empty() then
        self._begin = list_iterator(v)
        --self._begin = { val = v }
        self._begin.key = tostring(self._begin)
        self._end = list_iterator()
        --self._end = {}
        self._begin.next = self._end
        self._end.prev = self._begin
        self[self._begin.key] = self._begin
        return self._begin
    else
        local key, it_ = alloc(v, it.prev, it)
        self[key] = it_
        if it == self._begin then
            self._begin = it_
            self._begin.next.prev = self._begin
        else
            it.prev.next = it_
            it.prev = it_
        end
        return it_
    end
end

function list:insert_at(idx, v)
    idx = math.floor(idx)
    assert(idx > 0 and idx <= self:size() + 1, string.format('invalid index %d', idx))
    self:insert(self:begin():advance(idx - 1), v)
end

---### Erase elements
---Removes from the list container either a single element (position) or a range of elements ([first,last)).
---Return value: An iterator pointing to the element that followed the last element erased by the function call. This is the container end if the operation erased the last element in the sequence.
---@param it std.list_iterator
---@param it2 std.list_iterator
function list:erase(it, it2)
    assert(it ~= self._end)
    it2 = it2 or it.next
    local i = it
    while i and i ~= it2 do
        self[i.key] = nil
        i = i.next
    end
    it2.prev = it.prev
    if it == self._begin then
        self._begin = it2
        self._begin.prev = nil
    else
        it.prev.next = it2
    end
    return it2
end

function list:erase_at(idx)
    idx = math.floor(idx)
    assert(idx > 0 and idx <= self:size(), string.format('invalid index %d', idx))
    self:erase(self:begin():advance(idx - 1))
end

---### Insert element at beginning
---Inserts a new element at the beginning of the list, right before its current first element. This increases the container size by one.
function list:push_front(v)
    self:insert(self._begin, v)
end

---### Delete first element
---Removes the first element in the list container, reducing its size by one.
function list:pop_front()
    local it = self._begin
    self:erase(it)
    return it.val
end

---### Add element at the end
---Adds a new element at the end of the list container, after its current last element. This increases the container size by one.
function list:push_back(v)
    self:insert(self._end, v)
end

---### Delete last element
---Removes the last element in the list container, reducing the container size by one.
function list:pop_back()
    local it = self._end.prev
    self:erase(it)
    return it.val
end

--list operations--------------------------------

---### Remove elements with specific value
---Removes from the container all the elements that compare equal to v.
function list:remove(v)
    local it = self._begin
    while it ~= self._end do
        if it.val == v then
            it = self:erase(it)
        else
            it = it.next
        end
    end
end

---### Remove elements fulfilling condition
---Removes from the container all the elements for which Predicate p returns true.
function list:remove_if(p)
    local it = self._begin
    while it ~= self._end do
        if p(it.val) then
            it = self:erase(it)
        else
            it = it.next
        end
    end
end

function list:insert_if(v, p)
    if self:empty() then
        if p(nil, nil) then
            self:push_back(v)
            return
        end
    elseif self._begin == self._end.prev then
        if p(nil, self._begin.val) then
            self:push_front(v)
            return
        elseif p(self._begin.val, nil) then
            self:push_back(v)
            return
        end
    else
        if p(nil, self._begin.val) then
            self:push_front(v)
            return
        end

        local it = self._begin
        while it ~= self._end.prev do
            if p(it.val, it.next.val) then
                self:insert(it, v)
                return
            end
            it = it.next
        end

        if p(self._end.prev.val, nil) then
            self:push_back(v)
            return
        end
    end
end

--allocator--------------------------------------

---### Get allocator
---Returns the allocator object associated with the list container.
function list:get_allocator()
    return self._T
end

--copy-------------------------------------------

---copy
---@return std.list
function list:copy()
    local ret = list(self._T)
    for k, v in pairs(self) do
        ret[k] = v
    end
    return ret
end

function std.islist(v)
    local mt = getmetatable(v)
    return mt and mt.__index == list
end


------------------------

function std.list_iter(lst)
    assert(std.islist(lst))
    local iter = function(t, it)
        if it then
            return it.next, it.val
        else
            return nil
        end
    end
    return iter, lst, lst._begin
end

function std.list_rev_iter(lst)
    assert(std.islist(lst))
    local iter = function(t, it)
        if it then
            local prev = it.prev
            if prev then
                return prev, prev.val
            end
        end
        return nil
    end
    return iter, lst, lst._end
end

------------------------
--[[
local lst = std.list()
assert(lst:empty())

lst:push_back(1)
lst:push_back(2)
lst:push_back(3)
lst:push_back(4)
lst:push_back(5)

assert(lst:size() == 5)
assert(not lst:empty())

lst:remove(3)
assert(lst:size() == 4)
lst:pop_front()
assert(lst:size() == 3)
lst:pop_back()
assert(lst:size() == 2)

assert(lst:front() == lst:begin().val)
assert(lst:back() == lst:end_().prev.val)

lst:push_front(0)
lst:push_back(6)

assert(lst:front() == lst:begin().val)
assert(lst:back() == lst:end_().prev.val)

for _, v in std.list_iter(lst) do
    print(v)
end
print('---')
for _, v in std.list_rev_iter(lst) do
    print(v)
end
--]]

