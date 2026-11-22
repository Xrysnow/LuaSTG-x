local M = {
    { title = 'File', content = {
        {
            title    = {
                en = 'New project...',
                zh = '新建工程...',
            },
            event    = 'new',
            shortcut = 'Ctrl+N',
        },
        {
            title    = {
                en = 'Open project...',
                zh = '打开工程...',
            },
            event    = 'open',
            shortcut = 'Ctrl+O',
        },
        {
            title     = {
                en = 'Save project',
                zh = '保存工程',
            },
            event     = 'save',
            shortcut = 'Ctrl+S',
            need_proj = true,
        },
        {
            title     = {
                en = 'Close project',
                zh = '关闭工程',
            },
            event     = 'close',
            shortcut = 'Ctrl+W',
            need_proj = true,
        },
        {
            title = {
                en = 'Settings...',
                zh = '设置...',
            },
            event = 'setting',
        },
        {
            title = {
                en = 'Exit',
                zh = '退出',
            },
            event = 'exit',
        },
    } },
    { title = 'Help', content = {
        {
            title = {
                en = 'About',
                zh = '关于',
            },
            event = 'about',
        },
    } },
}

return M
