--
local M = {}
local im = imgui

local docking_window_flags = 0
if im then
    docking_window_flags = bit.bor(
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
end

function M.load(target, docking, no_tool, no_font)
    if not im then
        return
    end
    require('imgui.__init__')
    local la = im.on(target or cc.Director:getInstance():getRunningScene())
    if docking then
        im.clear()
        la._lstgTools = nil
        local wi = require('imgui.Widget')
        local dock
        dock = wi.Widget(function()
            local viewport = im.getMainViewport()
            im.setNextWindowPos(viewport.Pos)
            im.setNextWindowSize(viewport.Size)
            im.setNextWindowViewport(viewport.ID)
            im.pushStyleVar(im.StyleVar.WindowRounding, 0)
            im.pushStyleVar(im.StyleVar.WindowBorderSize, 0)
            im.pushStyleVar(im.StyleVar.WindowPadding, im.p(0, 0))
            im.begin('Dock Space', nil, docking_window_flags)
            im.popStyleVar(3)
            im.dockSpace(im.getID(tostring(docking)), im.p(0, 0), im.DockNodeFlags.PassthruCentralNode)
            wi._handler(dock)
            im.endToLua()
        end)
        la:addChild(dock)
    end
    if not no_font and not M._fontLoaded then
        im.addFontTTF('font/WenQuanYiMicroHeiMono.ttf', 16)
        M._fontLoaded = true
    end
    if not no_tool and not la._lstgTools then
        local tools = require('imgui.Widget').Widget()
        tools:setHandler(function()
            local dockID = im.getID('LuaSTG-x Tools Dock')
            for _, window in ipairs(tools:getChildren()) do
                -- Merge on first display; allow undocking and rearranging afterwards.
                im.setNextWindowDockID(dockID, im.Cond.Once)
                window:handler()
            end
        end)
        --la:addChild(im.showDemoWindow)
        tools:addChild(require('imgui.ui.Console').createWindow('Console'):setContentSize(cc.size(500, 500)))
        tools:addChild(require('imgui.ui.LogWindow').createWindow('Log'):setContentSize(cc.size(500, 500)))
        tools:addChild(require('imgui.ui.StyleSetting')('Setting'):setContentSize(cc.size(500, 500)))
        tools:addChild(require('imgui.ui.VariableWatch').createWindow('Watch'):setContentSize(cc.size(500, 500)))
        tools:addChild(require('imgui.lstg.GameInfo')('Game Info'):setContentSize(cc.size(500, 500)))
        tools:addChild(require('imgui.ui.About').createWindow('About'):setContentSize(cc.size(500, 500)))
        la:addChild(tools)
        la._lstgTools = tools
    end
    -- disable navigation
    im.configFlagDisable(im.ConfigFlags.NavEnableKeyboard, im.ConfigFlags.NavEnableGamepad)
    --im.setVisible(setting.imgui_visible)
    la:setVisible(setting.imgui_visible)
    return la, la._lstgTools
end

function M.loadFont()
    if not im then
        return
    end
    local cfg = im.ImFontConfig()
    cfg.OversampleH = 1
    cfg.PixelSnapH = true
    im.addFontTTF('font/WenQuanYiMicroHeiMono.ttf', 14, cfg)
    cfg.MergeMode = true
    im.addFontTTF('font/NotoSansDisplay-Regular.ttf', 18, cfg)
end

return M
