--
local M = {
    -- launch
    ["error in parsing setting"]                 = "读取设置出错",
    -- class
    ["Invalid base class"]                       = "无效的基类",
    -- corefunc
    ["clear stage resource pool"]                = "清空场景资源池",
    ["clear object pool"]                        = "清空对象池",
    ["entrance stage not set"]                   = "未设置初始场景",
    ["save screenshot to"]                       = "保存截屏到",
    ["failed to create blendmode"]               = "创建混合模式失败",
    -- math
    ["set random seed to"]                       = "设置随机数种子为",
    ["can't get factorial of a minus number"]    = "不能计算负数的阶乘",
    ["can't get combinatorial of minus numbers"] = "不能计算负数的组合数",
    -- include
    ["can't find script"]                        = "找不到脚本",
    -- loading
    ["load %s from local path %q"]               = "加载 %s 于本地路径 %q",
    ["load %s from %q"]                          = "加载 %s 于 %q",
    ["can't find"]                               = "找不到",
    ["load mod %q from local path"]              = "从本地路径加载MOD %q",
    ["load mod %q from zip file"]                = "从zip文件加载MOD %q",
    ["can't find mod"]                           = "找不到MOD",
    ["load plugin %q from local path"]           = "从本地路径加载插件 %q",
    ["enum plugins in %q"]                       = "查找插件于 %q",
    -- resources
    ["can't find image %q"]                      = "找不到图像 %q",
    ["invalid resource type name"]               = "无效的资源类型名",
    -- score
    ["can't find score file"]                    = "找不到score文件",
    -- view
    ["Invalid arguement for SetViewMode"]        = "SetViewMode: 无效参数",

    -- plus/NativeAPI
    ["try to create directory %q"]               = "尝试创建目录 %q",
    ["create directory failed"]                  = "创建目录失败",
    ["path %q dose not exist"]                   = "路径 %q 不存在",
    ["set local writable path to %q"]            = "设置本地可写路径为 %q",
}

return M
