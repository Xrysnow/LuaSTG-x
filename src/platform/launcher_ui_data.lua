--
local M = {}

M.title = {
    mod    = {
        en = 'Game',
        zh = 'MOD',
    },
    input  = {
        en = 'Input',
        zh = '输入',
    },
    sound  = {
        en = 'Sound',
        zh = '声音',
    },
    graph  = {
        en = 'Graph',
        zh = '图像',
    },
    others = {
        en = 'Others',
        zh = '其他',
    },
    exit   = {
        en = 'Exit',
        zh = '退出',
    },
}
M.label = {
    fps_title   = {
        en = "Render FPS",
        zh = "渲染帧数",
    },
    full        = {
        en = "    Fullscreen",
        zh = "全屏",
    },
    high        = {
        en = "960P",
        zh = "高 (960P)",
    },
    label       = {
        en = "BGM volume",
        zh = "BGM音量",
    },
    label1      = {
        en = "SE volume",
        zh = "音效音量",
    },
    label19     = {
        en = "Window size",
        zh = "窗口大小",
    },
    label2      = {
        en = "Mute",
        zh = "静音",
    },
    label20     = {
        en = "Screen orientation",
        zh = "屏幕方向",
    },
    label21     = {
        en = "Settings saved",
        zh = "设置已保存",
    },
    label3      = {
        en = "Game resolution",
        zh = "游戏分辨率",
    },
    label4      = {
        en = "Posteffect",
        zh = "后处理",
    },
    label5      = {
        en = "VSync",
        zh = "垂直同步",
    },
    label6      = {
        en = "Controller mapping",
        zh = "手柄映射",
    },
    low         = {
        en = "480P",
        zh = "低 (480P)",
    },
    mid         = {
        en = "720P",
        zh = "中 (720P)",
    },
    ori_lb1     = {
        en = "Landscape",
        zh = "横向",
    },
    ori_lb2     = {
        en = "Portrait",
        zh = "纵向",
    },
    title       = {
        en = "Aspect ratio",
        zh = "画面比例",
    },
    touchkey_lb = {
        en = "Show touck key",
        zh = "显示触摸按键",
    },
}

M.label.volume_bgm = M.label.label
M.label.volume_se = M.label.label1
M.label.mute = M.label.label2
M.label.win_size = M.label.label19
M.label.ori_title = M.label.label20

return M
