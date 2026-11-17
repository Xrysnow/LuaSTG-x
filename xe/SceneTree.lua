local base = require('xe.ui.TreeView')
---@class xe.SceneTree:xe.ui.TreeView
local M = class('xe.SceneTree', base)
local Node = require('xe.SceneNode')
local nodeType = require('xe.node_def._def').getNodeType()
local log = require('xe.logger').log
local format = string.format

local function get_prop()
    return require('xe.main').getProperty()
end

function M:ctor(...)
    base.ctor(self, ...)
    require('xe.node_def._def').regist()
    local root = Node('root')
    self:_setRoot(root)
    root:setLabel('Project')
    self._insert_pos = 'child'
    self._dirty = false
end

function M:newNode(type)
    self:insertDefault(type)
end

function M:setInsertPos(pos)
    assert(pos == 'child' or pos == 'after' or pos == 'before')
    self._insert_pos = pos
end

function M:getInsertPos()
    return self._insert_pos
end

function M.checkAllow(parent, child)
    assert(parent and child)
    local ctype = child:getType()
    local ptype = parent:getType()
    local ct = assert(nodeType[ctype],
                      ('invalid child type: %s'):format(ctype))
    local pt = assert(nodeType[ptype] or ptype == 'root',
                      ('invalid parent type: %s'):format(ptype))
    if ptype == 'root' then
        pt = {}
    end
    if not child:isRoot() then
        if pt.allowchild and not pt.allowchild[ctype] then
            return false
        end
        if pt.forbidchild and pt.forbidchild[ctype] then
            return false
        end
    end
    if ct.allowparent and not ct.allowparent[ptype] then
        return false
    end
    if ct.forbidparent and ct.forbidparent[ptype] then
        return false
    end
    return true
end

---@param node xe.SceneNode
---@param parent xe.SceneNode
function M.checkAncestor(node, parent)
    -- NOTE: node may not inserted to parent now
    local ret
    local ty = node:getType()
    local anc = nodeType[ty].needancestor
    local ancStack = node:getAncestorTypes()
    for _, v in ipairs(parent:getAncestorTypes()) do
        table.insert(ancStack, v)
    end
    if anc then
        ret = false
        for _, v in ipairs(ancStack) do
            if anc[v] then
                ret = true
            end
        end
    else
        ret = true
    end
    if not ret then
        local needed = {}
        for k, v in pairs(anc) do
            if type(k) == 'string' then
                table.insert(needed, k)
            end
        end
        log(format(
                '%q need ancestor: %s, but got %s',
                ty,
                table.concat(needed, '/'),
                table.concat(ancStack, '/')
        ), "error")
        return false
    end
    anc = nodeType[ty].forbidancestor
    if anc then
        for i, v in ipairs(ancStack) do
            -- skip self
            if anc[v] and i > 1 then
                log(format('%q forbid ancestor: %s (%d)', ty, v, i), "error")
                return false
            end
        end
    end
    if node:getChildrenCount() > 0 then
        for _, child in node:children() do
            ret = ret and M.checkAncestor(child, parent)
        end
    end
    return ret
end

---@param parent xe.SceneNode
---@param child xe.SceneNode
function M.insertNode(parent, child, idx)
    if not M.checkAllow(parent, child) then
        --log(format('can not insert %q as child of %q',
        --           child:getType(), parent:getType()), "Error")
        return false
    end
    if not M.checkAncestor(child, parent) then
        return false
    end
    if idx then
        parent:insertChildAt(idx, child)
    else
        parent:insertChild(child)
    end
    parent:unfold()
    child:select()
    child:addToWatch()
    return true
end

---@param node xe.SceneNode
function M:insertCurrent(node_ctor)
    local p = self._insert_pos
    local order = {
        child  = { 'insertToCurrent', 'insertAfterCurrent', 'insertBeforeCurrent', },
        after  = { 'insertAfterCurrent', 'insertToCurrent', 'insertBeforeCurrent', },
        before = { 'insertBeforeCurrent', 'insertToCurrent', 'insertAfterCurrent', },
    }
    if self:getCurrent():isRoot() then
        return self:insertToCurrent(node_ctor)
    else
        local t = order[p]
        if not t then
            error('invalid insert position')
        end
        local op, ret
        for _, v in ipairs(t) do
            op, ret = self[v](self, node_ctor)
            if ret then
                break
            end
        end
        if not ret then
            log(format("can't insert to %q",
                       self:getCurrent():getType()), "error")
        end
        return op, ret
    end
end

local _getCtor

function M:insertDefault(type)
    _getCtor = _getCtor or require('xe.SceneNode').getCtor
    return self:insertCurrent(_getCtor(type))
end

function M:insertOp(parent_id, child_ctor, idx)
    local pid = parent_id
    local cid
    local op = {
        exe  = function()
            local p = self:getNodeByID(pid)
            local c = child_ctor()
            assert(p and c)
            if M.insertNode(p, c, idx) then
                self:updateID()
                cid = c:getID()
                pid = p:getID()
                return true
            end
            return false
        end,
        undo = function()
            local c = self:getNodeByID(cid)
            c:delete()
        end
    }
    local ret = op.exe()
    if ret then
        self._dirty = true
    end
    return op, ret
end

function M:insertToCurrent(node_ctor)
    local cur = self:getCurrent()
    if not cur then
        return
    end
    return self:insertOp(cur:getID(), node_ctor)
end

function M:insertBeforeCurrent(node_ctor)
    local cur = self:getCurrent()
    if (not cur) or cur:isRoot() or (not cur:getParentNode()) then
        return
    end
    return self:insertOp(cur:getParentNode():getID(), node_ctor, cur:getIndex())
end

function M:insertAfterCurrent(node_ctor)
    local cur = self:getCurrent()
    if (not cur) or cur:isRoot() or (not cur:getParentNode()) then
        return
    end
    return self:insertOp(cur:getParentNode():getID(), node_ctor, cur:getIndex() + 1)
end

---@param node xe.SceneNode
function M.checkDelete(node)
    return M.isValid(node) and not node:isForbidDelete()
end

function M:deleteOp(node_id)
    local id = node_id
    local ctor, idx, pid
    local op = {
        exe  = function()
            local node = self:getNodeByID(id)
            if not M.checkDelete(node) then
                log("can't delete node", 'Error')
                return false
            end
            ctor = node:getClone()
            idx = node:getIndex()
            local p = node:getParentNode()
            node:delete()
            self:updateID()
            pid = p:getIndex()
            return true
        end,
        undo = function()
            local p = self:getNodeByID(pid)
            if not p then
                log("can't find parent", 'Error')
                return
            end
            local node = ctor()
            M.insertNode(p, node, idx)
            self:updateID()
            pid = p:getIndex()
            id = node:getID()
        end
    }
    local ret = op.exe()
    if ret then
        self._dirty = true
    end
    return op, ret
end

function M:deleteCurrent()
    local cur = self:getCurrent()
    if not cur then
        return
    end
    if cur:isRoot() then
        return
    end
    return self:deleteOp(cur:getID())
end

function M:updateID()
    -- id is dynamic
end

---@return xe.SceneNode
function M:getNodeByID(id)
    local n = self:getRoot()
    if id == n:getID() then
        return n
    end
    local idx = string.split(id, ' ')
    assert(#idx >= 2)
    for i = 2, #idx do
        local index = assert(tonumber(idx[i]))
        n = assert(n:getChildAt(index))
    end
    return n
end

---@param node xe.SceneNode
function M:submitAttr(node, values)
    local changed = false
    local val = table.clone(values)
    local rec_old = {}
    local rec_new = {}
    if M.isValid(node) then
        for i = 1, node:getAttrCount() do
            -- NOTE: nil means not ready
            if not node:isAttrValueEqual(i, val[i]) and val[i] ~= nil then
                rec_old[i] = table.clone(node:getAttrValue(i))
                node:setAttrValue(i, val[i])
                rec_new[i] = table.clone(node:getAttrValue(i))
                --print(string.format(
                --        '[%s] changed from %q to %q',
                --        node:getType(), rec_old[i], val[i]))
                changed = true
            end
        end
    end
    if changed then
        node:updateString()
        local id = node:getID()
        local op = {
            exe  = function()
                local n = self:getNodeByID(id)
                for k, v in pairs(rec_new) do
                    n:setAttrValue(k, v)
                end
                n:updateString()
            end,
            undo = function()
                local n = self:getNodeByID(id)
                for k, v in pairs(rec_old) do
                    n:setAttrValue(k, v)
                end
                n:updateString()
            end
        }
        op.exe()
        self._dirty = true
        return op
    end
end

function M:submitAttrToCurrent()
    --print('SceneTree:submitAttrToCurrent')
    local cur = self:getCurrent()
    if M.isValid(cur) then
        local values = get_prop():collectValues()
        return self:submitAttr(self:getCurrent(), values)
    end
end

function M:submitAttrTo(node)
    local values = get_prop():collectValues()
    return self:submitAttr(node, values)
end

function M:editCurrentAttr(idx)
    --TODO: remove
    print('SceneTree:editCurrentAttr', idx)
    self.cur_attr_idx = idx
    local node = self:getCurrent()
    if not node then
        return
    end
    local enum = nodeType[node:getType()][idx][2]
    if enum == 'resfile' then
        local type = node:getType()
        local wildCard
        if type == 'loadsound' or type == 'loadbgm' then
            wildCard = { "wav", "ogg" }
        elseif type == 'loadimage' or type == 'loadani' or type == 'bossdefine' then
            wildCard = { "png", "jpg", "bmp" }
        elseif type == 'loadparticle' then
            wildCard = "psi"
        elseif type == 'patch' then
            wildCard = "lua"
        elseif type == 'loadFX' then
            wildCard = "fx"
        else
            wildCard = ""
        end
        local curProjDir = require('xe.Project').getDir()
        require('platform.FileDialog').openPath(wildCard, curProjDir, function(path)
            if not self:isRunning() or self:getCurrent() ~= node or self.cur_attr_idx ~= idx then return end
            local fullpath = path
            local name = string.filename(path)
            local panel = get_prop()
            if type == 'bossdefine' then
                panel:setValue(5, fullpath)
            elseif type == 'patch' then
                panel:setValue(1, fullpath)
            else
                panel:setValue(1, fullpath)
                panel:setValue(2, name)
                if type == 'loadparticle' then
                    local f, msg = io.open_u8(fullpath, 'rb')
                    if f == nil then
                        log(msg, "Error")
                    else
                        local s = f:read(1)
                        f:close()
                        if s then panel:setValue(3, 'parimg' .. (s:byte(1) + 1)) end
                    end
                end
            end
            self:submitAttrToCurrent()
        end)
    end
end

---@param next_node xe.SceneNode
function M:onSelChanged(next_node)
    M.submit()
    self:setCurrent(next_node)
    local panel = get_prop()
    if next_node == nil then
        panel:showNode(nil)
        return
    end
    local node = next_node
    if node:isRoot() then
        self:setTypeHint("Node type: Project")
        panel:showNode(node)
    else
        self:setTypeHint("Node type: " .. node:getDisplayType())
        panel:showNode(node)
        if node:getAttrValue(1) == "" and node:isEditFirst() then
            --self:editCurrentAttr(1)
            --TODO: use highlight
        end
    end
    --
    local toolbar = require('xe.main').getToolBar()
    toolbar:setEnabled('debugSC', next_node:isDebuggable('spellcard'))
    toolbar:setEnabled('debugStage', next_node:isDebuggable('stage'))
end

function M:copyCurrent()
    local cur = self:getCurrent()
    if M.isValid(cur) and not cur:isRoot() then
        require('platform.ClipBoard').set("\001LuaSTG" .. cur:serialize())
    end
end

function M:cutCurrent()
    local cur = self:getCurrent()
    if M.isValid(cur) and not cur:isRoot() and not cur:isForbidDelete() then
        self:copyCurrent()
        return self:deleteCurrent()
    end
end

function M:pasteToCurrent()
    local cur = self:getCurrent()
    if M.isValid(cur) or cur:isRoot() then
        local cp = require('platform.ClipBoard').get()
        if cp and string.sub(cp, 1, 7) == "\001LuaSTG" then
            cp = cp:sub(8, -1)
            local f = require('xe.SceneNode').deserialize
            local node_ctor = f(cp)
            if not node_ctor then
                log('failed to deserialize node', 'error')
                return
            end
            return self:insertCurrent(node_ctor)
        end
    end
end

function M:exportCurrent()
    local cur = self:getCurrent()
    if not M.isValid(cur) or cur:isRoot() then
        return
    end
    return cur:serialize()
end

function M:importToCurrent(str)
    local cur = self:getCurrent()
    if not M.isValid(cur) then
        return false
    end
    local t = require('xe.TreeHelper').DeSerialize(str)
    local f = require('xe.SceneNode').deserialize
    local node_ctor = f(t)
    if not node_ctor then
        -- error
        log('failed to deserialize node', 'error')
        return false
    end
    self:insertCurrent(node_ctor)
    return true
end

function M:setTypeHint(str)
    --TODO: should be shown in property
    str = str or 'N/A'
    --print('current node type: ' .. str)
    return
end

function M:deserialize(str)
    local t = require('xe.TreeHelper').DeSerialize(str)
    local f = require('xe.SceneNode').deserialize
    for i, v in ipairs(t) do
        local node_ctor = f(v)
        if not node_ctor then
            -- error
            log('failed to deserialize node', 'error')
            self:reset()
            return false
        end
        --self:getRoot():insertChild(node)
        self:setCurrent(self:getRoot())
        self:insertToCurrent(node_ctor)
    end
    return true
end

function M:serialize()
    return self:getRoot():serialize()
end

local _def_node_type = { enemydefine = true, bulletdefine = true, objectdefine = true, laserdefine = true, laserbentdefine = true, rebounderdefine = true }
local _init_node_type = { enemyinit = true, bulletinit = true, objectinit = true, laserinit = true, laserbentinit = true, rebounderinit = true }
---@param node xe.SceneNode
local function CalcParamNumAll(node)
    local checker = require('xe.node_def._checker')
    local ty = node:getType()
    if _def_node_type[ty] then
        for _, v in node:children() do
            if _init_node_type[v:getType()] then
                checker.paramNumDict[node:getAttrValue(1)] = checker.CalcParamNum(v:getAttrValue(1))
                break
            end
        end
    elseif ty == 'folder' then
        for _, v in node:children() do
            CalcParamNumAll(v)
        end
    end
end

local _indents = {}
---@return table|boolean,string,xe.SceneNode
function M:compile(debugCur, debugSC)
    --
    local debugCode, debugNode
    if debugCur and self:getCurrent() then
        print('compile to debug stage')
        local curNode = self:getCurrent()
        local taskNode = curNode:getParentNode()
        if taskNode:getType() == 'stagetask' then
            local stageNode = taskNode:getParentNode()
            local groupNode = stageNode:getParentNode()
            local stageName = stageNode:getAttrValue(1)
            local groupName = groupNode:getAttrValue(1)
            debugCode = ("_debug_stage_name = '%s@%s'\nInclude ('THlib/UI/debugger.lua')\n"):format(stageName, groupName)
            local firstNode = taskNode:getChildAt(1)
            if firstNode ~= curNode then
                debugNode = { firstNode, curNode }
            end
        else
            log("must debug from direct child node of stagetask node", 'error')
            return
        end
    end
    --
    local scDebugNode
    if debugSC and self:getCurrent() then
        print('compile to debug SC')
        scDebugNode = self:getCurrent()
        if scDebugNode:getType() ~= 'bossspellcard' then
            log('current node is not a spell card node', 'error')
            return
        end
    end
    --
    local checker = require('xe.node_def._checker')
    checker.reset()
    for _, v in self:getRoot():children() do
        CalcParamNumAll(v)
    end
    --
    local watchDict = checker.watchDict
    local watch = require('xe.TreeHelper').watch
    ---@param wdata table<xe.SceneNode,boolean>
    for key, wdata in pairs(watch) do
        watchDict[key] = {}
        if key == "sound" then
            for node, _ in pairs(wdata) do
                assert(node.getAttrValue,
                       ('invalid object in watch %s: %s'):format(key, getclassname(node)))
                local k = node:getAttrValue(2)
                watchDict[key][k] = true
            end
        elseif key ~= 'image' then
            for node, _ in pairs(wdata) do
                assert(node.getAttrValue,
                       ('invalid object in watch %s: %s'):format(key, getclassname(node)))
                local k = node:getAttrValue(1)
                watchDict[key][k] = true
            end
        end
    end
    watchDict.imageonly = {}
    for node, _ in pairs(watch.image) do
        local ty = node:getType()
        local name = node:getAttrValue(2)
        if ty == 'loadimage' then
            watchDict.image['image:' .. name] = true
            watchDict.imageonly['image:' .. name] = true
        elseif ty == 'loadani' then
            watchDict.image['ani:' .. name] = true
        elseif ty == 'loadparticle' then
            watchDict.image['particle:' .. name] = true
        end
    end
    --
    local ret = {}
    local insert = table.insert
    local t, msg, node = {}
    --
    local t1 = {}
    if debugNode then
        t1[debugNode[2]] = 'end '
    end
    local t2 = {}
    if debugNode then
        t2[debugNode[1]] = 'if false then '
    end
    if scDebugNode then
        if setting.xe.debug_sc_current_only then
            t2[scDebugNode] = '_boss_class_name = $qp1\n'
                    .. '_debug_cards = { boss.move.New(0, 144, 60, MOVE_NORMAL), _tmp_sc }\n'
        else
            t2[scDebugNode] = '_boss_class_name = $qp1\n'
                    .. '_editor_class[$qp1].cards = { boss.move.New(0, 144, 60, MOVE_NORMAL), _tmp_sc }\n'
        end
    end
    for _, _ in pairs(t1) do
        t.beforeHead = function(item)
            return t1[item]
        end
        break
    end
    for _, _ in pairs(t2) do
        t.afterFoot = function(item)
            return t2[item]
        end
        break
    end
    --
    t, msg, node = self:getRoot():compile(t)
    if not t then
        if node then
            -- select on error
            node:select()
            msg = ('%s | %s | %s'):format(msg, node:getType(), node:getID())
            log(msg, 'error', node:getType())
        else
            log(tostring(msg), 'error')
        end
        return
    end
    for i, v in ipairs(t) do
        local s, indent = v[1], v[2]
        if indent <= 0 then
            insert(ret, s)
        else
            local ind_str = _indents[indent]
            if not ind_str then
                ind_str = ('\t'):rep(indent)
                _indents[indent] = ind_str
            end
            local strip
            if s:sub(-1) == '\n' then
                strip = true
            end
            local str = ind_str .. s:gsub('\n', '\n' .. ind_str)
            if strip then
                str = str:sub(1, -#ind_str - 1)
            end
            insert(ret, str)
        end
    end
    -- use xe.game
    --if debugCode then
    --    table.insert(ret, debugCode)
    --end
    --if debugSC then
    --    table.insert(ret, "Include('THlib/UI/scdebugger.lua')\n")
    --end
    --
    return table.concat(ret)
end

function M:reset()
    self:getRoot():deleteAllChildren()
    get_prop():showNode(nil)
    require('xe.TreeHelper').clearWatch()
end

function M:setDirty(v)
    self._dirty = v
end

function M:isDirty()
    return self._dirty
end

function M.isValid(node)
    return node and node.attr
end

function M.isFocused()
    return true
end

--- submit current with history
function M.submit(self)
    local changed = false
    if not self or self == M then
        self = require('xe.main').getEditor():getTree()
    end
    local op = self:submitAttrToCurrent()
    if op then
        changed = true
        require('xe.history').add(op)
    end
    -- auto save
    if changed and setting.xe.auto_save then
        require('xe.Project').save()
    end
    return changed
end

return M
