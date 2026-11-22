---@class icp.main:cc.ViewBase
local M = class('icp.main', require('cc.ViewBase'))
assert(imgui)
local im = imgui
local wi = require('imgui.Widget')

function M:ctor()
    require('cc.ViewBase').ctor(self)
    self:showWithScene()
    local la = im.on(self:getParent())
    local window_flags = bit.bor(
    --im.WindowFlags.MenuBar,
            im.WindowFlags.NoDocking,
            im.WindowFlags.NoTitleBar,
            im.WindowFlags.NoCollapse,
            im.WindowFlags.NoResize,
            im.WindowFlags.NoMove,
            im.WindowFlags.NoBringToFrontOnFocus,
            im.WindowFlags.NoNavFocus,
            im.WindowFlags.NoBackground
    )
    la:addChild(function()
        local viewport = im.getMainViewport()
        im.setNextWindowPos(viewport.Pos)
        im.setNextWindowSize(viewport.Size)
        im.setNextWindowViewport(viewport.ID)
        im.pushStyleVar(im.StyleVar.WindowRounding, 0)
        im.pushStyleVar(im.StyleVar.WindowBorderSize, 0)
        im.pushStyleVar(im.StyleVar.WindowPadding, im.p(0, 0))
        im.begin('Dock Space', nil, window_flags)
        im.popStyleVar(3)
        im.dockSpace(im.getID('icp.dock_space'), im.p(0, 0), im.DockNodeFlags.PassthruCentralNode)
        im.endToLua()
    end)

    local assetManager = require('icp.AssetManager'):getInstance()
    la:addChild(assetManager)
    local editor = require('icp.Editor'):getInstance()
    la:addChild(editor)
    local property = require('icp.Property'):getInstance()
    la:addChild(property)

    assetManager:addImage('D:/图片/表情/贴吧表情/43.png')
    --la:addChild(im.showDemoWindow)
    --la:addChild(im.showStyleEditor)
    --im.styleColorsLight()
    require('imgui.style').AdobeDark()

    require('imgui.lstg.util').loadFont()

    self:_loadIcons()

    self:scheduleUpdateWithPriorityLua(function()
        local key = require('keycode')
        if lstg.GetKeyState(key.CTRL) and lstg.GetLastKey() == key.R then
            for i, v in ipairs(table.keys(package.loaded)) do
                package.loaded[v] = nil
            end
            im.off()
            local dir = cc.Director:getInstance()
            dir:purgeCachedData()
            dir:replaceScene(nil)
            lstg.FrameReset()
        end
    end, 1)
end

function M:_loadIcons()
    local names = {
        "ActualSize",
        "AdjustWindowSize",
        "AutoZoom",
        "Checkerboard",
        "Convert",
        "Delete",
        "Edit",
        "FlipHorz",
        "FlipVert",
        "FullScreen",
        "GoToFirst",
        "GoToImage",
        "GotoLast",
        "LockRatio",
        "Menu",
        "OpenFile",
        "Print",
        "Refresh",
        "RotateLeft",
        "RotateRight",
        "ScaleToFill",
        "ScaleToFit",
        "ScaleToHeight",
        "ScaleToWidth",
        "Slideshow",
        "ThumbnailBar",
        "ViewNextImage",
        "ViewPreviousImage",
        "ZoomIn",
        "ZoomOut",
    }
    local cache = cc.Director:getInstance():getTextureCache()
    for i, v in ipairs(names) do
        local path = ('icp/icon/%s.png'):format(v)
        -- Restricted Ref construction: research/lua-binding-convergence_2026-11-01/core/callers.md
        local img = cc.Image()
        local ok = img:initWithImageFile(path)
        assert(ok)
        local tex = cache:addImage(img, path)
        assert(tex)
        img:release()
    end
end

return M
