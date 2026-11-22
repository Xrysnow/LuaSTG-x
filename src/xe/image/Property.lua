--
local base = require('imgui.widgets.Window')
---@class icp.Property:im.Window
local M = class('icp.Property', base)
local im = imgui
local wi = require('imgui.Widget')
local ins
---@return icp.Property
function M:getInstance()
    ins = ins or M()
    return ins
end

function M:ctor()
    base.ctor(self, 'Property')
end

function M:reset()
    self:removeAllChildren(true)
end

function M:showImage(img_info)
    self:reset()
    self:addChild(function()
        im.columns(2, 'Property', true)
        local w = im.getWindowWidth()
        im.setColumnWidth(0, w * 0.4)
        --
        wi.propertyConst('File Name', img_info.name)
        im.separator()
        wi.propertyConst('File Path', img_info.path)
        im.separator()
        wi.propertyConst('Width', img_info.size.x, { fmt = '%d' })
        im.separator()
        wi.propertyConst('Height', img_info.size.y, { fmt = '%d' })
        --im.separator()
        --
        im.columns(1)
        --
        im.spacing()
        if im.button('Edit', im.p(im.getColumnWidth(), 0)) then
            require('icp.Editor'):getInstance():addImage(img_info)
        end
    end)
end

return M
