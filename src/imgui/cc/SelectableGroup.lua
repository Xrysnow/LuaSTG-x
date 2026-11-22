local base = require('imgui.Widget')

---@class im.cc.SelectableGroup:im.Widget
local M = class('im.cc.SelectableGroup', base)
local im = imgui

function M:ctor(nodes, current, flags, sizes)
    local n = cc.Node:create()
    self._root = n
    n:setVisible(false)
    self:addChild(n)
    self:clear()
    self:reset(nodes, current, flags, sizes)
    self:setLabelAutoColor(true)
end

function M:setOnSelect(f)
    self._onsel = f
    return self
end

function M:setLabelAutoColor(b)
    self._lac = b
end

function M:getCurrent()
    return self._cur
end
function M:getNodeCount()
    return #self._nodes
end

function M:clear()
    self._cur = 0
    ---@type cc.Node[]
    self._nodes = {}
    self._flags = {}
    self._sizes = {}
    self._root:removeAllChildren()
end

function M:reset(nodes, current, flags, sizes)
    self:clear()
    if not nodes then
        return
    end
    flags = flags or {}
    sizes = sizes or {}
    if type(flags) == 'number' then
        local t = {}
        for _ = 1, #nodes do
            table.insert(t, flags)
        end
        flags = t
    end
    if sizes.x then
        local t = {}
        for _ = 1, #nodes do
            table.insert(t, sizes)
        end
        sizes = t
    end
    for i, node in ipairs(nodes) do
        self:addNode(node, nil, flags[i], sizes[i])
    end
    if current then
        self._cur = current
    end
end

function M:addNode(node, pos, flag, size)
    assert(node)
    self._root:addChild(node)
    -- avoid nil in table
    flag = flag or self._flags[#self._flags] or false
    size = size or false
    if not pos or pos > #self._nodes or pos < 1 then
        -- insert at last by default
        pos = #self._nodes + 1
    end
    table.insert(self._nodes, pos, node)
    table.insert(self._flags, pos, flag)
    table.insert(self._sizes, pos, size)
    if pos <= self._cur then
        self._cur = self._cur + 1
    end
end

function M:removeNode(pos)
    if pos and (pos > #self._nodes or pos < 1) then
        return
    end
    if #self._nodes == 0 then
        return
    end
    -- remove last node by default
    pos = pos or #self._nodes
    self._root:removeChild(assert(self._nodes[pos]))
    table.remove(self._nodes, pos)
    table.remove(self._flags, pos)
    table.remove(self._sizes, pos)
end

function M:_handler()
    local w = im.getWindowWidth() - im.getStyle().WindowPadding.x * 2
    local dl = im.getWindowDrawList()
    for i = 1, #self._nodes do
        local node = self._nodes[i]
        local nsz = node:getContentSize()
        local pos = im.getCursorScreenPos()
        local sz = self._sizes[i]
        if not sz then
            sz = im.vec2(0, nsz.y)
        end
        if sz.y == 0 then
            sz.y = nsz.y
        end
        local ww, hh = sz.x, sz.y
        if ww == 0 then
            ww = w
        end
        local xx = pos.x + (ww - nsz.x) / 2
        local yy = pos.y + (hh - nsz.y) / 2
        local param = { '', i == self._cur, self._flags[i] or 0, sz }
        im.pushID(tostring(self) .. i)
        if im.selectable(unpack(param)) then
            self._cur = i
            if self._onsel then
                self:_onsel(i)
            end
            self._ret = { i }
        end
        im.popID()

        if self._lac then
            im.setCCLabelColor(node)
        end
        dl:addCCNode(node, im.vec2(xx, yy))
    end
    base._handler(self)
end

return M
