---@type imgui
local im = imgui

-- Use the enums exported by the compiled ImGui version. Recreating numeric
-- tables here silently changes style types, flag bits and named key values.
for _, name in ipairs({
    'WindowFlags', 'InputTextFlags', 'TreeNodeFlags', 'PopupFlags',
    'SelectableFlags', 'ComboFlags', 'TabBarFlags', 'TabItemFlags',
    'TableFlags', 'TableColumnFlags', 'TableRowFlags', 'TableBgTarget',
    'FocusedFlags', 'HoveredFlags', 'DockNodeFlags', 'DragDropFlags',
    'DataType', 'Dir', 'SortDirection', 'Key',
    'ConfigFlags', 'BackendFlags', 'Col', 'StyleVar',
    'ButtonFlags', 'ColorEditFlags', 'SliderFlags', 'MouseCursor',
    'Cond', 'ViewportFlags',
}) do
    im[name] = assert(im['ImGui' .. name], 'missing ImGui enum: ' .. name)
end

-- Keep the renamed entries used by existing Lua widgets and style presets.
im.Col.TabActive = im.Col.TabSelected
im.Col.TabUnfocused = im.Col.TabDimmed
im.Col.TabUnfocusedActive = im.Col.TabDimmedSelected
im.Col.NavHighlight = im.Col.NavCursor
im.TreeNodeFlags.AllowItemOverlap = im.TreeNodeFlags.AllowOverlap
im.TreeNodeFlags.NavLeftJumpsBackHere = im.TreeNodeFlags.NavLeftJumpsToParent
im.SelectableFlags.AllowItemOverlap = im.SelectableFlags.AllowOverlap
im.ViewportFlags.Minimized = im.ViewportFlags.IsMinimized
im.ImGuiKeyModFlags = {
    None = im.Key.ImGuiMod_None,
    Ctrl = im.Key.ImGuiMod_Ctrl,
    Shift = im.Key.ImGuiMod_Shift,
    Alt = im.Key.ImGuiMod_Alt,
    Super = im.Key.ImGuiMod_Super,
}
im.KeyModFlags = im.ImGuiKeyModFlags
