local base = require('xe.ui.TreeView')
---@class xe.AssetsTree:xe.ui.TreeView
local M = class('xe.AssetsTree', base)
local fu = cc.FileUtils:getInstance()
local ifont = require('xe.ifont')
local icons = {
    audio   = ifont.FileAudio,
    image   = ifont.FileImage,
    video   = ifont.FileVideo,
    code    = ifont.FileCode,
    archive = ifont.FileArchive,
    text    = ifont.FileAlt,
    csv     = ifont.FileCsv,
    file    = ifont.File,
    folder  = ifont.Folder,
    project = ifont.FilePowerpoint,
}
local exts = {
    audio   = { 'wav', 'ogg', 'mp3', 'flac', },
    image   = { 'bmp', 'png', 'jpg', 'jpeg', },
    video   = { 'mp4', },
    code    = { 'lua', 'luac', },
    archive = { 'zip', },
    text    = { 'txt', },
    project = { 'lstgxproj', 'luastg', },
}

local function get_prop()
    return require('xe.main').getProperty()
end

function M:ctor()
    base.ctor(self)
    self._dir = nil
    self._map = {}
    ---@type table<string,xe.AssetsNode>
    self._nodes = {}
    self._tree, self._arr = {}, {}
    local ii = 0
    self:scheduleUpdateWithPriorityLua(function()
        ii = ii + 1
        if ii % 30 == 5 then
            self:_update()
        end
        if ii >= 60 then
            ii = 0
        end
    end, 1)
end

function M:open(dir)
    dir = dir:gsub('\\', '/'):gsub('/+', '/')
    if dir:sub(-1) ~= '/' then
        dir = dir .. '/'
    end
    self:close()
    -- dir should be abs path
    dir = fu:fullPathForFilename(dir)
    assert(fu:isDirectoryExist(dir), ('directory %s dose not exist'):format(dir))
    self._dir = dir
    self:_update()
    self:getRoot():unfold()
end

function M:close()
    self._dir = nil
    self._map = {}
    self._nodes = {}
    self._tree, self._arr = {}, {}
    self:_setRoot(nil)
    self:setCurrent(nil)
    local panel = get_prop()
    panel:showAssets(nil)
    self:removeAllChildren()
end

function M:openCurrentFile()
    local cur = self:getCurrent()
    if cur then
        cur:openFile()
    end
end

---@param next_node xe.AssetsNode
function M:onSelChanged(next_node)
    -- submit scene
    local scene_tree = require('xe.main').getTree()
    scene_tree:submit()

    self:setCurrent(next_node)
    local panel = get_prop()
    if next_node == nil then
        panel:showNode(nil)
        return
    end
    local node = next_node
    if node:isRoot() then
        --TODO: show setting
        panel:showAssets(node)
    else
        panel:showAssets(node)
    end
end

function M:_newNode(t)
    return require('xe.assets.AssetsNode')(t)
end

function M:_updateTree()
    local tree = self._tree
    local root_path = tree[1].path
    -- skip existing node
    local root = self._nodes[root_path]
    if not root then
        root = self:_newNode(tree[1])
        self._nodes[root_path] = root
        self:_setRoot(root)
    end
    self:_buildTree(tree[2], root)
end

---@param parent xe.AssetsNode
function M:_buildTree(tree, parent)
    local nodes = self._nodes
    for _, v in ipairs(tree) do
        local attr = v[1]
        local path = attr.path
        local fold = parent:isFold()
        if v[2] then
            -- dir
            local dir_node = nodes[path]
            local fold_dir
            if not dir_node then
                dir_node = self:_newNode(attr)
                nodes[path] = dir_node
                parent:insertChild(dir_node)
                -- keep fold
                if fold then
                    parent:fold()
                end
                fold_dir = true
            else
                fold_dir = dir_node:isFold()
            end
            self:_buildTree(v[2], dir_node)
            if fold_dir then
                dir_node:fold()
            end
        else
            -- file
            local file_node = nodes[path]
            if not file_node then
                file_node = self:_newNode(attr)
                nodes[path] = file_node
                parent:insertChild(file_node)
                if fold then
                    parent:fold()
                end
            end
        end
    end
end

function M:_remove(path)
    local node = self._nodes[path]
    if not node then
        return
    end
    if node == self:getCurrent() then
        local panel = get_prop()
        panel:showAssets(nil)
    end
    node:delete()
end

local ext_map = {}
for k, v in pairs(exts) do
    for _, ext in ipairs(v) do
        ext_map[ext] = k
    end
end
local function proc_attr(t)
    if t.mode == 'directory' then
        t.icon = icons.folder
    elseif t.mode == 'file' then
        local ext = string.fileext(t.name):lower()
        if ext_map[ext] then
            t.res_type = ext_map[ext]
            t.icon = icons[ext_map[ext]]
        else
            t.icon = icons.file
        end
    end
    local id = ('%s|%s|%d|%d|%d'):format(t.name, t.mode, t.change, t.modification, t.size)
    t._id = id
    return t
end
local function tree_sort(a, b)
    a, b = a[1], b[1]
    if a.mode ~= b.mode then
        return a.mode < b.mode
    else
        return a.name < b.name
    end
end

local lfs = lfs
local _skip = { ['.'] = true, ['..'] = true, ['./'] = true, ['../'] = true, ['/.'] = true, ['/..'] = true, }
local function iter(dir)
    local tree, arr = {}, {}
    ---@type string[]
    local list = fu:listFiles(dir)
    for _, entry in ipairs(list) do
        local skip = entry:ends_with('/./') or entry:ends_with('/../') or _skip[entry]
        if not skip then
            local attr, msg = lfs.attributes(fu:getSuitableFOpen(entry))
            if not attr then
                --error(tostring(msg))
                print(('error when access %q: %s'):format(entry, msg))
            else
                local name = entry
                if name:sub(-1) == '/' then
                    name = name:sub(1, -2)
                end
                name = name:filename(true)
                attr.name = name
                attr.path = entry
                if attr.mode == 'directory' then
                    -- skip directory starts with '.'
                    if name:sub(1, 1) ~= '.' then
                        proc_attr(attr)
                        local sub_tree, sub_arr = iter(entry)
                        table.insert(tree, { attr, sub_tree })
                        --table.sort(sub_tree, tree_sort)
                        for _, v in ipairs(sub_arr) do
                            table.insert(arr, v)
                        end
                    end
                elseif attr.mode == 'file' then
                    proc_attr(attr)
                    table.insert(tree, { attr })
                    table.insert(arr, attr)
                end
            end
        end
    end
    table.sort(tree, tree_sort)
    return tree, arr
end

function M:_update()
    if self._dir then
        local root_dir = self._dir
        local root_attr, msg = lfs.attributes(fu:getSuitableFOpen(root_dir))
        if not root_attr then
            --error(tostring(msg))
            self:close()
            return
        end
        proc_attr(root_attr)
        local name = root_dir
        if name:sub(-1) == '/' then
            name = name:sub(1, -2)
        end
        name = name:filename(true)
        root_attr.name = name
        root_attr.path = root_dir
        local tree, arr = iter(root_dir)
        table.insert(arr, 1, root_attr)
        self._tree, self._arr = { root_attr, tree }, arr
    else
        self._tree, self._arr = {}, {}
    end
    local need_build = false
    local map = {}
    for _, v in ipairs(self._arr) do
        --if not v.path then
        --    print(stringify(v))
        --end
        map[v.path] = v
    end
    local map_old = self._map
    for k, v in pairs(map) do
        local v_old = map_old[k]
        if not v_old then
            -- new file
            need_build = true
        elseif v_old._id ~= v._id then
            -- file changed
            self._nodes[k]:_updateAttr(v)
        end
    end
    for k, _ in pairs(map_old) do
        local v_new = map[k]
        if not v_new then
            -- file removed
            self:_remove(k)
        end
    end
    self._map = map
    -- rebuild tree if there is new file
    if need_build then
        self:_updateTree()
    end
end

return M
