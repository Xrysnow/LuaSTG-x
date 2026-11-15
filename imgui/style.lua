--- from https://github.com/ocornut/imgui/issues/707
local M = {}
local im = imgui
local ImVec4 = cc.vec4
local ImVec2 = cc.p
local set = im.setStyleColor
local style = im.getStyle()
local col = im.Col

local function copy(idx_dst, idx_src)
    set(idx_dst, im.getStyleColorVec4(idx_src))
end
function M.styleVarsDefault()
    style.Alpha = 1.0
    style.WindowPadding = ImVec2(8, 8)
    style.WindowRounding = 7.0
    style.WindowBorderSize = 1.0
    style.WindowMinSize = ImVec2(32, 32)
    style.WindowTitleAlign = ImVec2(0.0, 0.5)
    style.WindowMenuButtonPosition = im.Dir.Left
    style.ChildRounding = 0.0
    style.ChildBorderSize = 1.0
    style.PopupRounding = 0.0
    style.PopupBorderSize = 1.0
    style.FramePadding = ImVec2(4, 3)
    style.FrameRounding = 0.0
    style.FrameBorderSize = 0.0
    style.ItemSpacing = ImVec2(8, 4)
    style.ItemInnerSpacing = ImVec2(4, 4)
    style.TouchExtraPadding = ImVec2(0, 0)
    style.IndentSpacing = 21.0
    style.ColumnsMinSpacing = 6.0
    style.ScrollbarSize = 14.0
    style.ScrollbarRounding = 9.0
    style.GrabMinSize = 10.0
    style.GrabRounding = 0.0
    style.TabRounding = 4.0
    style.TabBorderSize = 0.0
    style.TabMinWidthForUnselectedCloseButton = 0.0
    style.ColorButtonPosition = im.Dir.Right
    style.ButtonTextAlign = ImVec2(0.5, 0.5)
    style.SelectableTextAlign = ImVec2(0.0, 0.0)
    style.DisplayWindowPadding = ImVec2(19, 19)
    style.DisplaySafeAreaPadding = ImVec2(3, 3)
    style.MouseCursorScale = 1.0
    style.AntiAliasedLines = true
    style.AntiAliasedFill = true
    style.CurveTessellationMaxError = math.sqrt(1.25)
    style.CircleSegmentMaxError = 1.60
end

--- by @usernameiwantedwasalreadytaken
function M.Microsoft()
    im.styleColorsLight()
    M.styleVarsDefault()
    local hspacing = 8
    local vspacing = 6
    style.DisplaySafeAreaPadding = ImVec2(0, 0)
    style.WindowPadding = ImVec2(hspacing / 2, vspacing)
    style.FramePadding = ImVec2(hspacing, vspacing)
    style.ItemSpacing = ImVec2(hspacing, vspacing)
    style.ItemInnerSpacing = ImVec2(hspacing, vspacing)
    style.IndentSpacing = 20.0

    style.WindowRounding = 0.0
    style.FrameRounding = 0.0

    --style.WindowBorderSize = 0.0
    style.FrameBorderSize = 1.0
    style.PopupBorderSize = 1.0

    style.ScrollbarSize = 20.0
    style.ScrollbarRounding = 0.0
    --style.GrabMinSize = 5.0
    style.GrabRounding = 0.0

    local white = ImVec4(1.00, 1.00, 1.00, 1.00)
    local transparent = ImVec4(0.00, 0.00, 0.00, 0.00)
    local dark = ImVec4(0.00, 0.00, 0.00, 0.20)
    local darker = ImVec4(0.00, 0.00, 0.00, 0.50)
    local background = ImVec4(0.95, 0.95, 0.95, 1.00)
    local text = ImVec4(0.10, 0.10, 0.10, 1.00)
    local border = ImVec4(0.60, 0.60, 0.60, 1.00)
    local grab = ImVec4(0.69, 0.69, 0.69, 1.00)
    local header = ImVec4(0.86, 0.86, 0.86, 1.00)
    local active = ImVec4(0.00, 0.47, 0.84, 1.00)
    local hover = ImVec4(0.00, 0.47, 0.84, 0.20)

    set(col.Text, text)
    set(col.WindowBg, background)
    set(col.ChildBg, background)
    set(col.PopupBg, white)

    set(col.Border, border)
    set(col.BorderShadow, transparent)

    set(col.Button, header)
    set(col.ButtonHovered, hover)
    set(col.ButtonActive, active)

    set(col.FrameBg, white)
    set(col.FrameBgHovered, hover)
    set(col.FrameBgActive, active)

    set(col.MenuBarBg, header)
    set(col.Header, header)
    set(col.HeaderHovered, hover)
    set(col.HeaderActive, active)

    set(col.CheckMark, text)
    set(col.SliderGrab, grab)
    set(col.SliderGrabActive, darker)

    --set(col.CloseButton, transparent)
    --set(col.CloseButtonHovered, transparent)
    --set(col.CloseButtonActive, transparent)

    set(col.ScrollbarBg, header)
    set(col.ScrollbarGrab, grab)
    set(col.ScrollbarGrabHovered, dark)
    set(col.ScrollbarGrabActive, darker)

    --
    style.WindowBorderSize = 1
    style.GrabMinSize = 10
end

--- by @ice1000
function M.JetBrainsDarcula()
    im.styleColorsDark()
    M.styleVarsDefault()
    style.WindowRounding = 5.3
    style.GrabRounding = 2.3
    style.FrameRounding = 2.3
    --style.ScrollbarRounding = 5.0
    style.FrameBorderSize = 1.0
    style.ItemSpacing.y = 6.5

    set(col.Text, ImVec4(0.73333335, 0.73333335, 0.73333335, 1.00))
    set(col.TextDisabled, ImVec4(0.34509805, 0.34509805, 0.34509805, 1.00))
    set(col.WindowBg, ImVec4(0.23529413, 0.24705884, 0.25490198, 0.94))
    set(col.ChildBg, ImVec4(0.23529413, 0.24705884, 0.25490198, 0.00))
    set(col.PopupBg, ImVec4(0.23529413, 0.24705884, 0.25490198, 0.94))
    set(col.Border, ImVec4(0.33333334, 0.33333334, 0.33333334, 0.50))
    set(col.BorderShadow, ImVec4(0.15686275, 0.15686275, 0.15686275, 0.00))
    set(col.FrameBg, ImVec4(0.16862746, 0.16862746, 0.16862746, 0.54))
    set(col.FrameBgHovered, ImVec4(0.453125, 0.67578125, 0.99609375, 0.67))
    set(col.FrameBgActive, ImVec4(0.47058827, 0.47058827, 0.47058827, 0.67))
    --set(col.TitleBg, ImVec4(0.04, 0.04, 0.04, 1.00))
    --set(col.TitleBgCollapsed, ImVec4(0.16, 0.29, 0.48, 1.00))
    --set(col.TitleBgActive, ImVec4(0.00, 0.00, 0.00, 0.51))
    set(col.MenuBarBg, ImVec4(0.27058825, 0.28627452, 0.2901961, 0.80))
    set(col.ScrollbarBg, ImVec4(0.27058825, 0.28627452, 0.2901961, 0.60))
    set(col.ScrollbarGrab, ImVec4(0.21960786, 0.30980393, 0.41960788, 0.51))
    set(col.ScrollbarGrabHovered, ImVec4(0.21960786, 0.30980393, 0.41960788, 1.00))
    set(col.ScrollbarGrabActive, ImVec4(0.13725491, 0.19215688, 0.2627451, 0.91))
    -- set(col.ComboBg, ImVec4(0.1, 0.1, 0.1, 0.99))
    set(col.CheckMark, ImVec4(0.90, 0.90, 0.90, 0.83))
    set(col.SliderGrab, ImVec4(0.70, 0.70, 0.70, 0.62))
    set(col.SliderGrabActive, ImVec4(0.30, 0.30, 0.30, 0.84))
    set(col.Button, ImVec4(0.33333334, 0.3529412, 0.36078432, 0.49))
    set(col.ButtonHovered, ImVec4(0.21960786, 0.30980393, 0.41960788, 1.00))
    set(col.ButtonActive, ImVec4(0.13725491, 0.19215688, 0.2627451, 1.00))
    set(col.Header, ImVec4(0.33333334, 0.3529412, 0.36078432, 0.53))
    set(col.HeaderHovered, ImVec4(0.453125, 0.67578125, 0.99609375, 0.67))
    set(col.HeaderActive, ImVec4(0.47058827, 0.47058827, 0.47058827, 0.67))
    set(col.Separator, ImVec4(0.31640625, 0.31640625, 0.31640625, 1.00))
    set(col.SeparatorHovered, ImVec4(0.31640625, 0.31640625, 0.31640625, 1.00))
    set(col.SeparatorActive, ImVec4(0.31640625, 0.31640625, 0.31640625, 1.00))
    set(col.ResizeGrip, ImVec4(1.00, 1.00, 1.00, 0.85))
    set(col.ResizeGripHovered, ImVec4(1.00, 1.00, 1.00, 0.60))
    set(col.ResizeGripActive, ImVec4(1.00, 1.00, 1.00, 0.90))
    set(col.PlotLines, ImVec4(0.61, 0.61, 0.61, 1.00))
    set(col.PlotLinesHovered, ImVec4(1.00, 0.43, 0.35, 1.00))
    set(col.PlotHistogram, ImVec4(0.90, 0.70, 0.00, 1.00))
    set(col.PlotHistogramHovered, ImVec4(1.00, 0.60, 0.00, 1.00))
    set(col.TextSelectedBg, ImVec4(0.18431373, 0.39607847, 0.79215693, 0.90))

    --
    style.TabRounding = 0
    style.ScrollbarRounding = 0
    set(col.Tab, ImVec4(60 / 255, 63 / 255, 65 / 255, 1))
    set(col.TabHovered, ImVec4(51 / 255, 53 / 255, 55 / 255, 1))
    set(col.TabActive, ImVec4(78 / 255, 82 / 255, 84 / 255, 1))
    set(col.TabUnfocused, ImVec4(51 / 255, 53 / 255, 55 / 255, 1))
    set(col.TabUnfocusedActive, ImVec4(78 / 255, 82 / 255, 84 / 255, 1))
    set(col.TitleBg, ImVec4(60 / 255, 63 / 255, 65 / 255, 1))
    set(col.TitleBgCollapsed, ImVec4(60 / 255, 63 / 255, 65 / 255, 1))
    set(col.TitleBgActive, ImVec4(60 / 255, 63 / 255, 65 / 255, 1))
    set(col.ScrollbarBg, ImVec4(0, 0, 0, 0))
    set(col.ScrollbarGrab, ImVec4(1, 1, 1, 47 / 255))
    set(col.ScrollbarGrabHovered, ImVec4(1, 1, 1, 58 / 255))
    set(col.ScrollbarGrabActive, ImVec4(1, 1, 1, 58 / 255))
end

--- by @r-lyeh
function M.CherryTheme()
    im.styleColorsDark()
    M.styleVarsDefault()
    -- cherry colors, 3 intensities
    local function HI(v)
        return ImVec4(0.502, 0.075, 0.256, v)
    end
    local function MED(v)
        return ImVec4(0.455, 0.198, 0.301, v)
    end
    local function LOW(v)
        return ImVec4(0.232, 0.201, 0.271, v)
    end
    -- backgrounds
    local function BG(v)
        return ImVec4(0.200, 0.220, 0.270, v)
    end
    -- text
    local function TEXT(v)
        return ImVec4(0.860, 0.930, 0.890, v)
    end

    set(col.Text, TEXT(0.78))
    set(col.TextDisabled, TEXT(0.28))
    set(col.WindowBg, ImVec4(0.13, 0.14, 0.17, 1.00))
    set(col.ChildBg, BG(0.58))
    set(col.PopupBg, BG(0.9))
    set(col.Border, ImVec4(0.31, 0.31, 1.00, 0.00))
    set(col.BorderShadow, ImVec4(0.00, 0.00, 0.00, 0.00))
    set(col.FrameBg, BG(1.00))
    set(col.FrameBgHovered, MED(0.78))
    set(col.FrameBgActive, MED(1.00))
    set(col.TitleBg, LOW(1.00))
    set(col.TitleBgActive, HI(1.00))
    set(col.TitleBgCollapsed, BG(0.75))
    set(col.MenuBarBg, BG(0.47))
    set(col.ScrollbarBg, BG(1.00))
    set(col.ScrollbarGrab, ImVec4(0.09, 0.15, 0.16, 1.00))
    set(col.ScrollbarGrabHovered, MED(0.78))
    set(col.ScrollbarGrabActive, MED(1.00))
    set(col.CheckMark, ImVec4(0.71, 0.22, 0.27, 1.00))
    set(col.SliderGrab, ImVec4(0.47, 0.77, 0.83, 0.14))
    set(col.SliderGrabActive, ImVec4(0.71, 0.22, 0.27, 1.00))
    set(col.Button, ImVec4(0.47, 0.77, 0.83, 0.14))
    set(col.ButtonHovered, MED(0.86))
    set(col.ButtonActive, MED(1.00))
    set(col.Header, MED(0.76))
    set(col.HeaderHovered, MED(0.86))
    set(col.HeaderActive, HI(1.00))
    --set(col.Column, ImVec4(0.14, 0.16, 0.19, 1.00))
    --set(col.ColumnHovered, MED(0.78))
    --set(col.ColumnActive, MED(1.00))
    set(col.ResizeGrip, ImVec4(0.47, 0.77, 0.83, 0.04))
    set(col.ResizeGripHovered, MED(0.78))
    set(col.ResizeGripActive, MED(1.00))
    set(col.PlotLines, TEXT(0.63))
    set(col.PlotLinesHovered, MED(1.00))
    set(col.PlotHistogram, TEXT(0.63))
    set(col.PlotHistogramHovered, MED(1.00))
    set(col.TextSelectedBg, MED(0.43))
    -- [...]
    --set(col.ModalWindowDarkening, BG(0.73))

    style.WindowPadding = ImVec2(6, 4)
    style.WindowRounding = 0.0
    style.FramePadding = ImVec2(5, 2)
    style.FrameRounding = 3.0
    style.ItemSpacing = ImVec2(7, 1)
    style.ItemInnerSpacing = ImVec2(1, 1)
    style.TouchExtraPadding = ImVec2(0, 0)
    style.IndentSpacing = 6.0
    style.ScrollbarSize = 12.0
    style.ScrollbarRounding = 16.0
    style.GrabMinSize = 20.0
    style.GrabRounding = 2.0

    style.WindowTitleAlign = ImVec2(0.50, style.WindowTitleAlign.y)

    set(col.Border, ImVec4(0.539, 0.479, 0.255, 0.162))
    style.FrameBorderSize = 0.0
    style.WindowBorderSize = 1.0
end

--- by @ebachard
function M.LightGreen()
    im.styleColorsLight()
    M.styleVarsDefault()
    style.WindowRounding = 2.0    -- Radius of window corners rounding. Set to 0.0f to have rectangular windows
    style.ScrollbarRounding = 3.0 -- Radius of grab corners rounding for scrollbar
    style.GrabRounding = 2.0      -- Radius of grabs corners rounding. Set to 0.0f to have rectangular slider grabs.
    style.AntiAliasedLines = true
    style.AntiAliasedFill = true
    style.WindowRounding = 2
    style.ChildRounding = 2
    style.ScrollbarSize = 16
    style.ScrollbarRounding = 3
    style.GrabRounding = 2
    style.ItemSpacing.x = 10
    style.ItemSpacing.y = 4
    style.IndentSpacing = 22
    style.FramePadding.x = 6
    style.FramePadding.y = 4
    style.Alpha = 1.0
    style.FrameRounding = 3.0

    set(col.Text, ImVec4(0.00, 0.00, 0.00, 1.00))
    set(col.TextDisabled, ImVec4(0.60, 0.60, 0.60, 1.00))
    set(col.WindowBg, ImVec4(0.86, 0.86, 0.86, 1.00))
    --set(col.ChildWindowBg, ImVec4(0.00, 0.00, 0.00, 0.00))
    set(col.ChildBg, ImVec4(0.00, 0.00, 0.00, 0.00))
    set(col.PopupBg, ImVec4(0.93, 0.93, 0.93, 0.98))
    set(col.Border, ImVec4(0.71, 0.71, 0.71, 0.08))
    set(col.BorderShadow, ImVec4(0.00, 0.00, 0.00, 0.04))
    set(col.FrameBg, ImVec4(0.71, 0.71, 0.71, 0.55))
    set(col.FrameBgHovered, ImVec4(0.94, 0.94, 0.94, 0.55))
    set(col.FrameBgActive, ImVec4(0.71, 0.78, 0.69, 0.98))
    set(col.TitleBg, ImVec4(0.85, 0.85, 0.85, 1.00))
    set(col.TitleBgCollapsed, ImVec4(0.82, 0.78, 0.78, 0.51))
    set(col.TitleBgActive, ImVec4(0.78, 0.78, 0.78, 1.00))
    set(col.MenuBarBg, ImVec4(0.86, 0.86, 0.86, 1.00))
    set(col.ScrollbarBg, ImVec4(0.20, 0.25, 0.30, 0.61))
    set(col.ScrollbarGrab, ImVec4(0.90, 0.90, 0.90, 0.30))
    set(col.ScrollbarGrabHovered, ImVec4(0.92, 0.92, 0.92, 0.78))
    set(col.ScrollbarGrabActive, ImVec4(1.00, 1.00, 1.00, 1.00))
    set(col.CheckMark, ImVec4(0.184, 0.407, 0.193, 1.00))
    set(col.SliderGrab, ImVec4(0.26, 0.59, 0.98, 0.78))
    set(col.SliderGrabActive, ImVec4(0.26, 0.59, 0.98, 1.00))
    set(col.Button, ImVec4(0.71, 0.78, 0.69, 0.40))
    set(col.ButtonHovered, ImVec4(0.725, 0.805, 0.702, 1.00))
    set(col.ButtonActive, ImVec4(0.793, 0.900, 0.836, 1.00))
    set(col.Header, ImVec4(0.71, 0.78, 0.69, 0.31))
    set(col.HeaderHovered, ImVec4(0.71, 0.78, 0.69, 0.80))
    set(col.HeaderActive, ImVec4(0.71, 0.78, 0.69, 1.00))
    --set(col.Column, ImVec4(0.39, 0.39, 0.39, 1.00))
    --set(col.ColumnHovered, ImVec4(0.26, 0.59, 0.98, 0.78))
    --set(col.ColumnActive, ImVec4(0.26, 0.59, 0.98, 1.00))
    set(col.Separator, ImVec4(0.39, 0.39, 0.39, 1.00))
    set(col.SeparatorHovered, ImVec4(0.14, 0.44, 0.80, 0.78))
    set(col.SeparatorActive, ImVec4(0.14, 0.44, 0.80, 1.00))
    set(col.ResizeGrip, ImVec4(1.00, 1.00, 1.00, 0.00))
    set(col.ResizeGripHovered, ImVec4(0.26, 0.59, 0.98, 0.45))
    set(col.ResizeGripActive, ImVec4(0.26, 0.59, 0.98, 0.78))
    set(col.PlotLines, ImVec4(0.39, 0.39, 0.39, 1.00))
    set(col.PlotLinesHovered, ImVec4(1.00, 0.43, 0.35, 1.00))
    set(col.PlotHistogram, ImVec4(0.90, 0.70, 0.00, 1.00))
    set(col.PlotHistogramHovered, ImVec4(1.00, 0.60, 0.00, 1.00))
    set(col.TextSelectedBg, ImVec4(0.26, 0.59, 0.98, 0.35))
    --set(col.ModalWindowDarkening, ImVec4(0.20, 0.20, 0.20, 0.35))
    set(col.DragDropTarget, ImVec4(0.26, 0.59, 0.98, 0.95))
    copy(col.NavHighlight, col.HeaderHovered)
    set(col.NavWindowingHighlight, ImVec4(0.70, 0.70, 0.70, 0.70))
end

--- by @Derydoca
function M.AdobeDark()
    im.styleColorsDark()
    M.styleVarsDefault()
    --set(col.Text, ImVec4(1.000, 1.000, 1.000, 1.000))
    --set(col.TextDisabled, ImVec4(0.500, 0.500, 0.500, 1.000))
    --set(col.WindowBg, ImVec4(0.180, 0.180, 0.180, 1.000))
    --set(col.ChildBg, ImVec4(0.280, 0.280, 0.280, 0.000))
    --set(col.PopupBg, ImVec4(0.313, 0.313, 0.313, 1.000))
    set(col.Border, ImVec4(0.266, 0.266, 0.266, 1.000))
    set(col.BorderShadow, ImVec4(0.000, 0.000, 0.000, 0.000))
    set(col.FrameBg, ImVec4(0.160, 0.160, 0.160, 1.000))
    set(col.FrameBgHovered, ImVec4(0.200, 0.200, 0.200, 1.000))
    set(col.FrameBgActive, ImVec4(0.280, 0.280, 0.280, 1.000))
    set(col.TitleBg, ImVec4(0.148, 0.148, 0.148, 1.000))
    set(col.TitleBgActive, ImVec4(0.148, 0.148, 0.148, 1.000))
    set(col.TitleBgCollapsed, ImVec4(0.148, 0.148, 0.148, 1.000))
    set(col.MenuBarBg, ImVec4(0.195, 0.195, 0.195, 1.000))
    --set(col.ScrollbarBg, ImVec4(0.160, 0.160, 0.160, 1.000))
    --set(col.ScrollbarGrab, ImVec4(0.277, 0.277, 0.277, 1.000))
    --set(col.ScrollbarGrabHovered, ImVec4(0.300, 0.300, 0.300, 1.000))
    --set(col.ScrollbarGrabActive, ImVec4(1.000, 0.391, 0.000, 1.000))
    set(col.CheckMark, ImVec4(1.000, 1.000, 1.000, 1.000))
    set(col.SliderGrab, ImVec4(0.391, 0.391, 0.391, 1.000))
    set(col.SliderGrabActive, ImVec4(1.000, 0.391, 0.000, 1.000))
    set(col.Button, ImVec4(1.000, 1.000, 1.000, 0.000))
    set(col.ButtonHovered, ImVec4(1.000, 1.000, 1.000, 0.156))
    set(col.ButtonActive, ImVec4(1.000, 1.000, 1.000, 0.391))
    set(col.Header, ImVec4(0.313, 0.313, 0.313, 1.000))
    set(col.HeaderHovered, ImVec4(0.469, 0.469, 0.469, 1.000))
    set(col.HeaderActive, ImVec4(0.469, 0.469, 0.469, 1.000))
    copy(col.Separator, col.Border)
    set(col.SeparatorHovered, ImVec4(0.391, 0.391, 0.391, 1.000))
    set(col.SeparatorActive, ImVec4(1.000, 0.391, 0.000, 1.000))
    set(col.ResizeGrip, ImVec4(1.000, 1.000, 1.000, 0.250))
    set(col.ResizeGripHovered, ImVec4(1.000, 1.000, 1.000, 0.670))
    set(col.ResizeGripActive, ImVec4(1.000, 0.391, 0.000, 1.000))
    --set(col.Tab, ImVec4(0.098, 0.098, 0.098, 1.000))
    --set(col.TabHovered, ImVec4(0.352, 0.352, 0.352, 1.000))
    --set(col.TabActive, ImVec4(0.195, 0.195, 0.195, 1.000))
    --set(col.TabUnfocused, ImVec4(0.098, 0.098, 0.098, 1.000))
    --set(col.TabUnfocusedActive, ImVec4(0.195, 0.195, 0.195, 1.000))
    set(col.DockingPreview, ImVec4(1.000, 0.391, 0.000, 0.781))
    set(col.DockingEmptyBg, ImVec4(0.180, 0.180, 0.180, 1.000))
    set(col.PlotLines, ImVec4(0.469, 0.469, 0.469, 1.000))
    set(col.PlotLinesHovered, ImVec4(1.000, 0.391, 0.000, 1.000))
    set(col.PlotHistogram, ImVec4(0.586, 0.586, 0.586, 1.000))
    set(col.PlotHistogramHovered, ImVec4(1.000, 0.391, 0.000, 1.000))
    set(col.TextSelectedBg, ImVec4(1.000, 1.000, 1.000, 0.156))
    set(col.DragDropTarget, ImVec4(1.000, 0.391, 0.000, 1.000))
    set(col.NavHighlight, ImVec4(1.000, 0.391, 0.000, 1.000))
    set(col.NavWindowingHighlight, ImVec4(1.000, 0.391, 0.000, 1.000))
    set(col.NavWindowingDimBg, ImVec4(0.000, 0.000, 0.000, 0.586))
    set(col.ModalWindowDimBg, ImVec4(0.000, 0.000, 0.000, 0.586))

    style.ChildRounding = 4.0
    style.FrameBorderSize = 1.0
    style.FrameRounding = 2.0
    style.GrabMinSize = 7.0
    style.PopupRounding = 2.0
    --style.ScrollbarRounding = 12.0
    --style.ScrollbarSize = 13.0
    style.TabBorderSize = 1.0
    style.TabRounding = 0.0
    --style.WindowRounding = 4.0

    --
    set(col.Text, ImVec4(225 / 255, 225 / 255, 225 / 255, 1))
    set(col.TextDisabled, ImVec4(135 / 255, 135 / 255, 135 / 255, 1))
    set(col.WindowBg, ImVec4(50 / 255, 50 / 255, 50 / 255, 1))
    set(col.ChildBg, ImVec4(50 / 255, 50 / 255, 50 / 255, 1))
    set(col.PopupBg, ImVec4(50 / 255, 50 / 255, 50 / 255, 1))
    set(col.Tab, ImVec4(38 / 255, 38 / 255, 38 / 255, 1))
    set(col.TabHovered, ImVec4(50 / 255, 50 / 255, 50 / 255, 1))
    set(col.TabActive, ImVec4(050 / 255, 50 / 255, 50 / 255, 1))
    set(col.TabUnfocused, ImVec4(38 / 255, 38 / 255, 38 / 255, 1))
    set(col.TabUnfocusedActive, ImVec4(46 / 255, 46 / 255, 46 / 255, 1))
    set(col.ScrollbarBg, ImVec4(41 / 255, 41 / 255, 41 / 255, 1))
    set(col.ScrollbarGrab, ImVec4(71 / 255, 71 / 255, 71 / 255, 1.000))
    set(col.ScrollbarGrabHovered, ImVec4(71 / 255, 71 / 255, 71 / 255, 1.000))
    set(col.ScrollbarGrabActive, ImVec4(71 / 255, 71 / 255, 71 / 255, 1.000))
    style.ScrollbarRounding = 0
    style.ScrollbarSize = 16
    style.WindowRounding = 0
    style.FramePadding = ImVec2(6, 4)
end

--- by @malamanteau
function M.CorporateGrey()
    im.styleColorsDark()
    M.styleVarsDefault()
    -- 0 = FLAT APPEARENCE
    -- 1 = MORE "3D" LOOK
    local is3D = 0

    set(col.Text, ImVec4(1.00, 1.00, 1.00, 1.00))
    set(col.TextDisabled, ImVec4(0.40, 0.40, 0.40, 1.00))
    set(col.ChildBg, ImVec4(0.25, 0.25, 0.25, 1.00))
    set(col.WindowBg, ImVec4(0.25, 0.25, 0.25, 1.00))
    set(col.PopupBg, ImVec4(0.25, 0.25, 0.25, 1.00))
    set(col.Border, ImVec4(0.12, 0.12, 0.12, 0.71))
    set(col.BorderShadow, ImVec4(1.00, 1.00, 1.00, 0.06))
    set(col.FrameBg, ImVec4(0.42, 0.42, 0.42, 0.54))
    set(col.FrameBgHovered, ImVec4(0.42, 0.42, 0.42, 0.40))
    set(col.FrameBgActive, ImVec4(0.56, 0.56, 0.56, 0.67))
    set(col.TitleBg, ImVec4(0.19, 0.19, 0.19, 1.00))
    set(col.TitleBgActive, ImVec4(0.22, 0.22, 0.22, 1.00))
    set(col.TitleBgCollapsed, ImVec4(0.17, 0.17, 0.17, 0.90))
    set(col.MenuBarBg, ImVec4(0.335, 0.335, 0.335, 1.000))
    set(col.ScrollbarBg, ImVec4(0.24, 0.24, 0.24, 0.53))
    set(col.ScrollbarGrab, ImVec4(0.41, 0.41, 0.41, 1.00))
    set(col.ScrollbarGrabHovered, ImVec4(0.52, 0.52, 0.52, 1.00))
    set(col.ScrollbarGrabActive, ImVec4(0.76, 0.76, 0.76, 1.00))
    set(col.CheckMark, ImVec4(0.65, 0.65, 0.65, 1.00))
    set(col.SliderGrab, ImVec4(0.52, 0.52, 0.52, 1.00))
    set(col.SliderGrabActive, ImVec4(0.64, 0.64, 0.64, 1.00))
    set(col.Button, ImVec4(0.54, 0.54, 0.54, 0.35))
    set(col.ButtonHovered, ImVec4(0.52, 0.52, 0.52, 0.59))
    set(col.ButtonActive, ImVec4(0.76, 0.76, 0.76, 1.00))
    set(col.Header, ImVec4(0.38, 0.38, 0.38, 1.00))
    set(col.HeaderHovered, ImVec4(0.47, 0.47, 0.47, 1.00))
    set(col.HeaderActive, ImVec4(0.76, 0.76, 0.76, 0.77))
    set(col.Separator, ImVec4(0.000, 0.000, 0.000, 0.137))
    set(col.SeparatorHovered, ImVec4(0.700, 0.671, 0.600, 0.290))
    set(col.SeparatorActive, ImVec4(0.702, 0.671, 0.600, 0.674))
    set(col.ResizeGrip, ImVec4(0.26, 0.59, 0.98, 0.25))
    set(col.ResizeGripHovered, ImVec4(0.26, 0.59, 0.98, 0.67))
    set(col.ResizeGripActive, ImVec4(0.26, 0.59, 0.98, 0.95))
    set(col.PlotLines, ImVec4(0.61, 0.61, 0.61, 1.00))
    set(col.PlotLinesHovered, ImVec4(1.00, 0.43, 0.35, 1.00))
    set(col.PlotHistogram, ImVec4(0.90, 0.70, 0.00, 1.00))
    set(col.PlotHistogramHovered, ImVec4(1.00, 0.60, 0.00, 1.00))
    set(col.TextSelectedBg, ImVec4(0.73, 0.73, 0.73, 0.35))
    set(col.ModalWindowDimBg, ImVec4(0.80, 0.80, 0.80, 0.35))
    set(col.DragDropTarget, ImVec4(1.00, 1.00, 0.00, 0.90))
    set(col.NavHighlight, ImVec4(0.26, 0.59, 0.98, 1.00))
    set(col.NavWindowingHighlight, ImVec4(1.00, 1.00, 1.00, 0.70))
    set(col.NavWindowingDimBg, ImVec4(0.80, 0.80, 0.80, 0.20))

    style.PopupRounding = 3

    style.WindowPadding = ImVec2(4, 4)
    style.FramePadding = ImVec2(6, 4)
    style.ItemSpacing = ImVec2(6, 2)

    style.ScrollbarSize = 18

    style.WindowBorderSize = 1
    style.ChildBorderSize = 1
    style.PopupBorderSize = 1
    style.FrameBorderSize = is3D

    style.WindowRounding = 3
    style.ChildRounding = 3
    style.FrameRounding = 3
    style.ScrollbarRounding = 2
    style.GrabRounding = 3

    -- docking
    style.TabBorderSize = is3D
    style.TabRounding = 3

    set(col.DockingEmptyBg, ImVec4(0.38, 0.38, 0.38, 1.00))
    set(col.Tab, ImVec4(0.25, 0.25, 0.25, 1.00))
    set(col.TabHovered, ImVec4(0.40, 0.40, 0.40, 1.00))
    set(col.TabActive, ImVec4(0.33, 0.33, 0.33, 1.00))
    set(col.TabUnfocused, ImVec4(0.25, 0.25, 0.25, 1.00))
    set(col.TabUnfocusedActive, ImVec4(0.33, 0.33, 0.33, 1.00))
    set(col.DockingPreview, ImVec4(0.85, 0.85, 0.85, 0.28))

    if bit.band(im.getIO().ConfigFlags, im.ConfigFlags.ViewportsEnable) ~= 0 then
        style.WindowRounding = 0.0
        local color = im.getStyleColorVec4(col.WindowBg)
        color.w = 1.0
        im.setStyleColor(col.WindowBg, color)
    end
end

--- by @Raikiri
function M.DarkTheme2()
    im.styleColorsDark()
    M.styleVarsDefault()
    style.FrameRounding = 4.0
    style.GrabRounding = 4.0

    set(col.Text, ImVec4(0.95, 0.961, 0.98, 1.00))
    set(col.TextDisabled, ImVec4(0.36, 0.42, 0.47, 1.00))
    set(col.WindowBg, ImVec4(0.11, 0.15, 0.17, 1.00))
    set(col.ChildBg, ImVec4(0.15, 0.18, 0.22, 1.00))
    set(col.PopupBg, ImVec4(0.08, 0.08, 0.08, 0.94))
    set(col.Border, ImVec4(0.08, 0.10, 0.12, 1.00))
    set(col.BorderShadow, ImVec4(0.00, 0.00, 0.00, 0.00))
    set(col.FrameBg, ImVec4(0.20, 0.25, 0.29, 1.00))
    set(col.FrameBgHovered, ImVec4(0.12, 0.20, 0.28, 1.00))
    set(col.FrameBgActive, ImVec4(0.09, 0.12, 0.14, 1.00))
    set(col.TitleBg, ImVec4(0.09, 0.12, 0.14, 0.65))
    set(col.TitleBgActive, ImVec4(0.08, 0.10, 0.12, 1.00))
    set(col.TitleBgCollapsed, ImVec4(0.00, 0.00, 0.00, 0.51))
    set(col.MenuBarBg, ImVec4(0.15, 0.18, 0.22, 1.00))
    set(col.ScrollbarBg, ImVec4(0.02, 0.02, 0.02, 0.39))
    set(col.ScrollbarGrab, ImVec4(0.20, 0.25, 0.29, 1.00))
    set(col.ScrollbarGrabHovered, ImVec4(0.18, 0.22, 0.25, 1.00))
    set(col.ScrollbarGrabActive, ImVec4(0.09, 0.21, 0.31, 1.00))
    set(col.CheckMark, ImVec4(0.28, 0.56, 1.00, 1.00))
    set(col.SliderGrab, ImVec4(0.28, 0.56, 1.00, 1.00))
    set(col.SliderGrabActive, ImVec4(0.37, 0.61, 1.00, 1.00))
    set(col.Button, ImVec4(0.20, 0.25, 0.29, 1.00))
    set(col.ButtonHovered, ImVec4(0.28, 0.56, 1.00, 1.00))
    set(col.ButtonActive, ImVec4(0.06, 0.53, 0.98, 1.00))
    set(col.Header, ImVec4(0.20, 0.25, 0.29, 0.55))
    set(col.HeaderHovered, ImVec4(0.26, 0.59, 0.98, 0.80))
    set(col.HeaderActive, ImVec4(0.26, 0.59, 0.98, 1.00))
    set(col.Separator, ImVec4(0.20, 0.25, 0.29, 1.00))
    set(col.SeparatorHovered, ImVec4(0.10, 0.40, 0.75, 0.78))
    set(col.SeparatorActive, ImVec4(0.10, 0.40, 0.75, 1.00))
    set(col.ResizeGrip, ImVec4(0.26, 0.59, 0.98, 0.25))
    set(col.ResizeGripHovered, ImVec4(0.26, 0.59, 0.98, 0.67))
    set(col.ResizeGripActive, ImVec4(0.26, 0.59, 0.98, 0.95))
    set(col.Tab, ImVec4(0.11, 0.15, 0.17, 1.00))
    set(col.TabHovered, ImVec4(0.26, 0.59, 0.98, 0.80))
    set(col.TabActive, ImVec4(0.20, 0.25, 0.29, 1.00))
    set(col.TabUnfocused, ImVec4(0.11, 0.15, 0.17, 1.00))
    set(col.TabUnfocusedActive, ImVec4(0.11, 0.15, 0.17, 1.00))
    set(col.PlotLines, ImVec4(0.61, 0.61, 0.61, 1.00))
    set(col.PlotLinesHovered, ImVec4(1.00, 0.43, 0.35, 1.00))
    set(col.PlotHistogram, ImVec4(0.90, 0.70, 0.00, 1.00))
    set(col.PlotHistogramHovered, ImVec4(1.00, 0.60, 0.00, 1.00))
    set(col.TextSelectedBg, ImVec4(0.26, 0.59, 0.98, 0.35))
    set(col.DragDropTarget, ImVec4(1.00, 1.00, 0.00, 0.90))
    set(col.NavHighlight, ImVec4(0.26, 0.59, 0.98, 1.00))
    set(col.NavWindowingHighlight, ImVec4(1.00, 1.00, 1.00, 0.70))
    set(col.NavWindowingDimBg, ImVec4(0.80, 0.80, 0.80, 0.20))
    set(col.ModalWindowDimBg, ImVec4(0.80, 0.80, 0.80, 0.35))
end

return M
