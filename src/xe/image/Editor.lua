--
local base = require('imgui.widgets.Window')
---@class icp.Editor:im.Window
local M = class('icp.Editor', base)
local im = imgui
local wi = require('imgui.Widget')
local ins
---@return icp.Editor
function M:getInstance()
    ins = ins or M()
    return ins
end

function M:ctor()
    base.ctor(self, 'Editor')
    self:setFlags(im.WindowFlags.HorizontalScrollbar)
    local tabBarFlag = bit.band(
            im.TabBarFlags.Reorderable,
            im.TabBarFlags.AutoSelectNewTabs,
            im.TabBarFlags.TabListPopupButton,
            im.TabBarFlags.FittingPolicyScroll
    )
    self._tab = wi.TabBar('', tabBarFlag)
    self:addChild(self._tab)
    --self._items = {}
end

function M:_addItem(title, item)
    if type(item) == 'function' then
        item = wi.Widget(item)
    end
    local tab_item = wi.TabItem(title)
    tab_item:setClosable(true)
    self._tab:addChildChain(tab_item, item)
    return tab_item
end

function M:addImage(img_info)
    --if self._items[img_info.path] then
    --    -- already added
    --    return
    --end
    for i, v in ipairs(self._tab:getChildren()) do
        if v._path == img_info.path then
            return
        end
    end
    local content = require('icp.ImageDecomposer')(img_info)
    local tab_item = self:_addItem(img_info.name, content)
    tab_item._path = img_info.path
    --self._items[img_info.path] = tab_item
end

function M:removeImage(img_info)
    --local item = self._items[img_info.path]
    --if item then
    --    item:removeSelf()
    --    self._items[img_info.path] = nil
    --end
    for i, v in ipairs(self._tab:getChildren()) do
        if v._path == img_info.path then
            v:removeSelf()
            break
        end
    end
end

return M
