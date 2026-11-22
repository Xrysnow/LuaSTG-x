--
local M = {
    {
        name = {
            zh = '工程',
            en = 'Project',
        },
        {
            name = {
                zh = '自动保存',
                en = 'Auto save',
            },
            key  = 'auto_save',
            type = 'bool',
        },
        {
            name = {
                zh = '打包到引擎目录',
                en = 'Pack to engine path',
            },
            key  = 'pack_to_engine_path',
            type = 'bool',
        },
    },
    {
        name = {
            zh = '编辑器',
            en = 'Editor',
        },
        {
            name   = {
                zh = '节点边距',
                en = 'Node padding',
            },
            key    = 'editor_tree_padding',
            type   = 'int',
            slider = true,
            min    = 0,
            max    = 8,
        },
        {
            name    = {
                zh = '节点缩进',
                en = 'Node indent',
            },
            key     = 'editor_tree_indent',
            type    = 'int',
            min     = 2,
            max     = 32,
            default = function()
                return imgui.getStyle().IndentSpacing
            end
        },
    },
    {
        name = {
            zh = '调试',
            en = 'Debug',
        },
        {
            name = {
                zh = '作弊标志',
                en = 'Cheat flag',
            },
            key  = 'cheat',
            type = 'bool',
        },
        {
            name = {
                zh = '仅调试当前符卡',
                en = 'Debug current SC only',
            },
            key  = 'debug_sc_current_only',
            type = 'bool',
        },
    },
    {
        name = {
            zh = '代码编辑器',
            en = 'Code editor',
        },
        {
            name    = {
                zh = '字体缩放',
                en = 'Font scale',
            },
            key     = 'code_editor_font_scale',
            type    = 'int',
            default = 100,
        },
        {
            name    = {
                zh = '主题',
                en = 'Theme',
            },
            key     = 'code_editor_theme',
            type    = 'combo',
            combo = {
                { 'Light' }, { 'Dark' }, { 'Retro blue' },
            },
        },
    },
    {
        name = {
            zh = '界面',
            en = 'UI',
        },
        {
            name  = {
                zh = '主题',
                en = 'Theme',
            },
            key   = 'theme',
            type  = 'combo',
            combo = {
                { 'Light' }, { 'Dark' },
                { 'Microsoft' }, { 'JetBrainsDarcula' }, { 'CherryTheme' },
                { 'LightGreen' }, { 'AdobeDark' }, { 'CorporateGrey' },
                { 'DarkTheme2' },
            },
        },
    },
}

return M
