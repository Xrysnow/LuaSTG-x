---@class xe.FilePanel:ccui.Layout
local M = class('editor.FilePanel', ccui.Layout)
local fu = cc.FileUtils:getInstance()

function M:ctor(param)
    self.param = param or {}
    table.deploy(self, param, {
        size              = cc.size(64, 720),
        color             = cc.WHITE,
        view_color        = cc.c3b(235, 235, 235),
        view_size         = cc.size(64, 640),
        item_select_color = cc.c3b(187, 187, 187),
    })
    self:setBackGroundColorType(1):setBackGroundColor(self.color)
    self._title = require('cc.ui.label').create(i18n 'Project Files')
    self._title:addTo(self):alignTop(12):alignLeft(20)
    self._title:setTextColor(cc.BLACK)

    local path = param.path or ''
    self._folders = {}
    self._files = {}
    self._folders_fp = {}
    self._files_fp = {}
    path = fu:fullPathForFilename(path)
    path = string.filefolder(path)

    self.node_param = {
        btn_offset = 12,
        text_color = cc.BLACK,
        item_h     = 24,
    }
    self.tree = require('cc.ui.TreeView')()
    self.tree:addTo(self):setContentSize(self.view_size):alignCenter()
    self.tree:setBackGroundColor(self.view_color)
    self.root = require('cc.ui.TreeNode')('null.png', 'res://', function()
        self.tree:setCurrent(self.root)
    end, nil, self.node_param)
    self.root:setSelectColor(self.item_select_color)
    self.root:setSelectTextColor(cc.BLACK)
    self.root.toggle:setVisible(false)
    self.tree:_setRoot(self.root)

    self:setContentSize(self.size)
    self:setPath(path)
end

function M:getFiles()
    return self._files
end

--function M:getFolders()
--    return self._folders
--end

function M:hasFile(f)
    return table.has(self._files, f) or table.has(self._files_fp, f)
end

--function M:hasFolder(f)
--    return table.has(self._folders, f) or table.has(self._folders_fp, f)
--end

function M:setPath(path)
    if path:sub(-1) ~= '/' then
        path = path .. '/'
    end
    assert(fu:isDirectoryExist(path))
    if path == self._path then
        return
    end
    self._path = path
    local files = fu:listFiles(path)
    --Print(path)
    for i, v in ipairs(files) do
        local f = v:sub(#path + 1)
        if f:sub(-1) == '/' then
            if f ~= './' and f ~= '../' then
                table.insert(self._folders, f)
                table.insert(self._folders_fp, v)
            end
        else
            table.insert(self._files, f)
            table.insert(self._files_fp, v)
        end
    end
    --Print(stringify(self._folders))
    --Print(stringify(self._files))
    self.root:deleteAllChildren()
    for i, v in ipairs(self._files) do
        self.root:insertChild(self:createItem(nil, v))
    end
end

function M:createItem(ico, str)
    local ret
    ret = require('cc.ui.TreeNode')(
            ico or 'null.png', str or 'N/A', function()
                self.tree:setCurrent(ret)
            end, nil, self.node_param)
    ret:setSelectColor(self.item_select_color)
    ret:setSelectTextColor(cc.BLACK)
    ret.toggle:setVisible(false)
    return ret
end

function M:setContentSize(size)
    self.super.setContentSize(self, size)
    self.tree:setContentSize(cc.size(size.width - 20, size.height - 80)):alignCenter()
    return self
end

return M
