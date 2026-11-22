local base = require('xe.ui.TreeNode')
---@class xe.SceneNode:xe.ui.TreeNode
local M = class('xe.SceneNode', base)
local log = require('xe.logger').log
local enumType = require('xe.node.enum_type')
local Serialize = require('xe.TreeHelper').Serialize
local DeSerialize = require('xe.TreeHelper').DeSerialize
local nodeType = require('xe.node_def._def').getNodeType()

local function _get_icon(type)
    local cfg = nodeType[type]
    if cfg and cfg.icon then
        return require('xe.node.icon').getSmallIcon(cfg.icon)
    else
        return require('xe.node.icon').getSmallIcon(type)
    end
end

function M:ctor(type)
    base.ctor(self, tostring(type))
    assert(table.length(nodeType) > 0, 'node types not registered')
    assert(type)
    self.type = type
    self.attr = {}
    self.property = {}
    self._watch = nil
    self:setOnSelect(function()
        self:getView():onSelChanged(self)
    end)
    self:setOnUnselect(function()
        self:getView():onSelChanged(nil)
    end)
    self:setOnDelete(function()
        self:getView():onSelChanged(nil)
        self:removeFromWatch()
    end)
    --TODO: should no put here
    self._icon = _get_icon(type)
    if self._icon then
        self._icon:addTo(self):setVisible(false)
    end

    self._onFoldChange = function()
        local v = self:getView()
        if v then
            v:setDirty(true)
        end
    end
end

local _ignore = { type = true, attr = true, child = true }
local function _collect_property(t)
    local ret = {}
    for k, v in pairs(t) do
        if not _ignore[k] then
            ret[k] = v
        end
    end
    return ret
end

--local function _get_default_value(type, idx)
--    local def = nodeType[type]
--    if def and def.default then
--        return def.default[idx]
--    end
--end

local function _construct_plain(type, default)
    local nt = nodeType[type]
    if not nt then
        log('invalid node type: ' .. tostring(type), 'Error')
        return-- error('...')
    end
    local def = default or nt.default
    ---@type xe.SceneNode
    local ret = M:create(
            type,
            _get_icon(type))
    local attr = ret.attr
    -- init node attr
    for i = 1, #nt do
        attr[i] = { title = nt[i][1], type = nt[i][2] }
    end
    -- set default value
    if def and def.attr then
        for i = 1, ret:getAttrCount() do
            local v = def.attr[i]
            ret:setAttrValue(i, v)
            ret:setDefaultAttrValue(i, v)
        end
    end
    -- default value fallback
    for i = 1, #nt do
        if ret:getAttrValue(i) == nil then
            local attr_type = nt[i][2]
            local attr_dft = nt[i][4]
            if not attr_dft and enumType[attr_type] then
                attr_dft = enumType[attr_type][1]
            end
            ret:setAttrValue(i, attr_dft or '')
        end
    end

    if nt.watch then
        ret._watch = nt.watch
    end
    if def then
        ret.property = _collect_property(def)
    end
    return ret
end

local function _construct_default(type, default)
    assert(nodeType[type], tostring(type))
    local def = default or nodeType[type].default
    ---@type xe.SceneNode
    local ret = _construct_plain(type, def)
    if not ret then
        return-- error('...')
    end
    if def and def.child then
        for _, c in ipairs(def.child) do
            local ch = _construct_default(c.type, c)
            if ch then
                ret:insertChild(ch)
            end
        end
    end
    ret:updateString()
    return ret
end

function M.getCtor(type, attr, property)
    local attr_ = table.clone(attr or {})
    local property_ = table.clone(property or {})
    return function()
        local ret = _construct_default(type)
        if not ret then
            return
        end
        for i, v in ipairs(attr_) do
            --ret.attr[i] = v
            ret:setAttrValue(i, v)
        end
        for k, v in pairs(property_) do
            --ret.property[k] = v
            ret:setProperty(nil, k, v)
        end
        ret:updateString()
        return ret
    end
end

function M:getType()
    return self.type
end

function M:getProperty(k)
    return self.property[k]
end

function M:setProperty(type, k, v)
    self.property[k] = v
    if type then
        self.property_type[k] = type
    end
end

--

function M:setAttrEditType(idx, type)
    self.attr[idx].cur_type = type
end

function M:getAttrEditType(idx)
    local a = self.attr[idx]
    return a.cur_type
end

function M:getAttrEditValue(idx, type)
    local a = self.attr[idx]
    if not a.edit then
        return nil
    end
    return a.edit[type]
end

function M:_getAttrEditValues(idx)
    return self.attr[idx].edit
end

function M:setAttrEditValue(idx, type, value)
    local a = self.attr[idx]
    if not a.edit then
        a.edit = {}
    end
    a.edit[type] = value
end

--

function M:getAttrType(idx)
    return self.attr[idx].type
end

function M:getAttrValue(idx)
    local a = self.attr[idx]
    if not a then
        return
    end
    return a.value
end

function M:setAttrValue(idx, v)
    local a = self.attr[idx]
    --if not a then
    --    a = {}
    --    self.attr[idx] = a
    --end
    a.value = v
    self:updateString()
end

function M:getDefaultAttrValue(idx)
    return self.attr[idx].default
end

function M:setDefaultAttrValue(idx, v)
    self.attr[idx].default = v
end

function M:isAttrValueEqual(idx, v)
    return self.attr[idx].value == v
end

function M:getAttrCount()
    return #self.attr
end
--- check at compile
function M:checkAttr(idx)
    assert(1 <= idx and idx <= self:getAttrCount())
    local f = self:getConfig()[idx][3]
    local msg
    if f then
        msg = f(self:getAttrValue(idx))
    end
    if msg then
        return false, msg
    else
        return true
    end
end
--- check at edit
function M:checkAttrEdit(idx)
    assert(1 <= idx and idx <= self:getAttrCount())
    local f = self:getConfig()[idx][3]
    local checker = require('xe.node_def._checker')
    local t = {
        [checker.CheckClassName]     = checker.CheckNonBlank,
        [checker.CheckResFileInPack] = true,
        [checker.CheckAnonymous]     = true,
    }
    if t[f] then
        if type(t[f]) == 'function' then
            f = t[f]
        else
            return true
        end
    end
    local msg
    if f then
        msg = f(self:getAttrValue(idx))
    end
    if msg then
        return false, msg
    else
        return true
    end
end

function M:getAttrName(idx)
    return tostring(self:getConfig()[idx][1])
end

local _dict
function M:getAttrDesc(idx)
    _dict = _dict or i18n.getDict('xe.node')
    local desc = self:getConfig()[idx].desc
    if _dict and desc then
        return _dict(desc)
    end
end

function M:collectAttrValues()
    local ret = {}
    for i = 1, self:getAttrCount() do
        table.insert(ret, self:getAttrValue(i))
    end
    return ret
end

function M:getID()
    --print('SceneNode:getID()', self)
    if self:isRoot() then
        return 'root'
    end
    local p = self:getParentNode()
    if not p then
        error('require parent node')
    else
        local pid
        if p.getID then
            pid = p:getID()
        else
            pid = 'root'
        end
        return string.format('%s %d', pid, self:getIndex())
    end
end

local function _clone(node)
    --TODO: only copy values
    local type = node.type
    local attr = table.clone(node.attr)
    local property = table.clone(node.property)
    return function()
        local ret = M:create(
                type,
                _get_icon(type))
        ret.attr = attr
        ret.property = property
        --ret:updateString()
        return ret
    end
end

---@return fun():xe.ui.TreeNode
function M:getClone()
    local cl = _clone(self)
    local ccl = {}
    for i = 1, self:getChildrenCount() do
        table.insert(ccl, self:getChildAt(i):getClone())
    end
    return function()
        local ret = cl()
        for _, v in ipairs(ccl) do
            ret:insertChild(v())
        end
        ret:updateString()
        return ret
    end
end

---@param node xe.SceneNode
local function _dump(node)
    local t = table.clone(node.property)
    t.attr = {
        -- [1] = a1,
        -- [2] = a2,
        edit = {
            -- [1] = {
            --     [1]  = TYPE,
            --     [k1] = v1,
            --     [k2] = v2,
            -- },
            -- [2] = { ... },
        }
    }
    local edit = t.attr.edit
    for i = 1, node:getAttrCount() do
        t.attr[i] = node:getAttrValue(i)
        edit[i] = {}
        local et = node:getAttrEditType(i)
        if et then
            edit[i][1] = et
            for k, v in pairs(node:_getAttrEditValues(i)) do
                edit[i][k] = v
            end
        end
    end
    t.child = {}
    for i = 1, node:getChildrenCount() do
        table.insert(t.child, _dump(node:getChildAt(i)))
    end
    t.type = node:getType()
    t.expand = not node:isFold()
    if t.type == 'project' then
        return t.child
    else
        return t
    end
end

function M:dump()
    return _dump(self)
end

function M:dumpForNodeDef()
    local ret = { attr = {} }
    -- readonly
    for i = 1, self:getAttrCount() do
        ret.attr[i] = self:getAttrValue(i) or ''
    end
    --setmetatable(ret.attr, {
    --    __index    = function(t, k)
    --        return self:getAttrValue(k) or ''
    --    end,
    --    __newindex = function(t, k, v)
    --        self:setAttrValue(k, v)
    --    end,
    --    __len      = function()
    --        return self:getAttrCount()
    --    end
    --})
    setmetatable(ret, {
        __index    = function(t, k)
            return self:getProperty(k)
        end,
        __newindex = function(t, k, v)
            self:setProperty(nil, k, v)
        end,
        __call     = function(t, v)
            return self:format(v)
        end
    })
    return ret
end

function M:serialize()
    if self:isRoot() then
        return Serialize(self:dump().child)
    else
        return Serialize(self:dump())
    end
end

local function _des(t)
    --assert(t, 'got nil')
    local ret = _construct_plain(assert(t.type))
    if not ret then
        return
    end
    local n = ret:getAttrCount()
    for i = 1, n do
        ret:setAttrValue(i, t.attr[i])
    end
    local edit = t.attr.edit
    if edit then
        for i = 1, n do
            if edit[i] then
                for k, v in pairs(edit[i]) do
                    if k == 1 then
                        ret:setAttrEditType(i, v)
                    else
                        ret:setAttrEditValue(i, k, v)
                    end
                end
            end
        end
    end

    ret.property = _collect_property(t)
    if t.child then
        for _, v in ipairs(t.child) do
            local ch = _des(v)
            if ch then
                ret:insertChild(ch)
            end
        end
    end
    ret:updateString()
    if ret:getProperty('expand') == true then
        ret:unfold()
    else
        ret:fold()
    end
    return ret
end

function M.deserialize(s)
    if type(s) == 'string' then
        s = DeSerialize(s)
    end
    if not s then
        return nil
    end
    return function()
        return _des(s)
    end
end

--

function M:updateString()
    self:setString(self:toText())
end

---@return string
function M:toText()
    local fmt = self:getConfig().totext
    if fmt then
        if type(fmt) == 'string' then
            return self:format(fmt)
        else
            return fmt(self:dumpForNodeDef())
        end
    end
end

---@return string
function M:toHead()
    local fmt = self:getConfig().tohead
    if fmt then
        if type(fmt) == 'string' then
            return self:format(fmt)
        else
            return fmt(self:dumpForNodeDef())
        end
    end
end

---@return string
function M:toFoot()
    local fmt = self:getConfig().tofoot
    if fmt then
        if type(fmt) == 'string' then
            return self:format(fmt)
        else
            return fmt(self:dumpForNodeDef())
        end
    end
end

--

function M:getDisplayType()
    local t = self:getConfig().disptype
    if not t then
        t = tostring(self:getType())
    elseif type(t) == 'table' then
        t = i18n(t)
    end
    return t
end

function M:isForbidDelete()
    if self:isRoot() then
        return true
    end
    return self:getConfig().forbiddelete
end

function M:isEditFirst()
    return self:getConfig().editfirst
end

--

function M:checkBeforeCompile()
    local f = self:getConfig().check
    local msg = f and f(self:dumpForNodeDef())
    if msg then
        return false, msg
    else
        return true
    end
end

---@return boolean,string
function M:checkAfterCompile()
    local f = self:getConfig().checkafter
    local msg = f and f(self:dumpForNodeDef())
    if msg then
        return false, msg
    else
        return true
    end
end

local insert = table.insert
---@return table|boolean,string,xe.SceneNode
function M:compile(t, indent)
    t = t or {}
    indent = indent or 0
    local ret, msg, node
    --
    for i = 1, self:getAttrCount() do
        ret, msg = self:checkAttr(i)
        if not ret then
            return false, ('Attribute %q is invalid: %s'):format(self:getAttrName(i), msg)
        end
    end
    --
    ret, msg = self:checkBeforeCompile()
    if not ret then
        return false, msg, self
    end
    --
    if t.beforeHead then
        local code = t.beforeHead(self)
        if code then
            insert(t, { self:format(code), indent })
        end
    end
    --
    local head = self:toHead()
    if head then
        insert(t, { head, indent })
    end
    for i = 1, self:getChildrenCount() do
        ret, msg, node = self:getChildAt(i):compile(t, indent + self:getCodeIndent())
        if not ret then
            return false, msg, node
        end
    end
    local foot = self:toFoot()
    if foot then
        insert(t, { foot, indent })
    end
    --
    if t.afterFoot and (not t.afterFootCheck or t.afterFootCheck(self)) then
        local code = t.afterFoot(self)
        if code then
            insert(t, { self:format(code), indent })
        end
    end
    --
    ret, msg = self:checkAfterCompile()
    if not ret then
        return false, msg, self
    end
    --
    return t
end

--

function M:_getAttrValueFromName(name)
    local v
    local cfg = self:getConfig()
    for i = 1, #self.attr do
        if name == cfg[i][1] then
            v = self:getAttrValue(i)
            break
        end
    end
    return v
end

local tonumber = tonumber
local assert = assert
function M:format(s)
    -- note: only replace once
    local function f1(ss)
        if ss:sub(1, 1) == 'q' then
            if ss:sub(2, 2) == 'p' then
                return ('%q'):format(self:getParentNode():getAttrValue(tonumber(ss:sub(3))))
            else
                return ('%q'):format(self:getAttrValue(tonumber(ss:sub(2))))
            end
        else
            return self:getAttrValue(tonumber(ss)) or ss
        end
    end
    s = s:gsub('$(q?p?%d+)', f1)
    return s
end

--

---
---@param typ string @spellcard/stage
function M:isDebuggable(typ)
    if typ == 'spellcard' then
        return self:getType() == 'bossspellcard'
    elseif typ == 'stage' then
        local p = self:getParentNode()
        return p and p:getType() == 'stagetask'
    end
end

function M:getCodeIndent()
    if self:isRoot() then
        return 0
    end
    local v = self:getConfig().depth
    return v or 1
end

function M:getAncestors()
    if self:isRoot() then
        return {}
    end
    local p = self
    local ret = {}
    while p do
        table.insert(ret, p)
        p = p:getParentNode()
    end
    return ret
end

function M:getAncestorTypes()
    if self:isRoot() then
        return {}
    end
    local p = self
    local ret = {}
    while p do
        table.insert(ret, p:getType())
        p = p:getParentNode()
    end
    return ret
end

function M:getConfig()
    if self:isRoot() then
        return {}
    end
    local cfg = self._config
    if cfg then
        return cfg
    end
    self._config = assert(nodeType[self:getType()], 'invalid type: ' .. tostring(self:getType()))
    return self._config
end

function M:getWatch()
    return self._watch
end

function M:addToWatch()
    local w = self:getWatch()
    if w then
        require('xe.TreeHelper').addWatch(w, self)
    end
    for _, child in self:children() do
        child:addToWatch()
    end
end

function M:removeFromWatch()
    require('xe.TreeHelper').removeWatch(self)
    for _, child in self:children() do
        child:removeFromWatch()
    end
end

--

function M:_renderContextItem()
    if self:isRoot() then
        imgui.closeCurrentPopup()
        return
    end
    self:select()
    ---@type xe.SceneTree
    --local tree = self:getView()
    local tool = require('xe.ToolMgr')
    local items = M._ctxItem
    for i = 1, 2 do
        local v = items[i]
        if imgui.selectable(i18n(v)) then
            tool[v.name]()
        end
    end
    local ii = 3
    if self:isDebuggable('stage') then
        if imgui.selectable(i18n(items[ii])) then
            tool[items[ii].name]()
        end
    end
    ii = ii + 1
    if self:isDebuggable('spellcard') then
        if imgui.selectable(i18n(items[ii])) then
            tool[items[ii].name]()
        end
    end
end

M._ctxItem = {
    {
        name = 'copy',
        en   = 'Copy',
        zh   = '复制',
    },
    {
        name = 'paste',
        en   = 'Paste',
        zh   = '粘贴',
    },
    {
        name = 'debugStage',
        en   = 'Debug stage here',
        zh   = '运行当前关卡',
    },
    {
        name = 'debugSC',
        en   = 'Debug SC here',
        zh   = '运行当前符卡',
    },
}

return M
