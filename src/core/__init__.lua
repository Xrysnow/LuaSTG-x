local core = {
    'core/include.lua',
    'core_x/__init__.lua',

    'core/const.lua',
    'core/status.lua',
    'core/math.lua',
    --'core/respool.lua',
    'core/resources.lua',
    'core/screen.lua',
    'core/view.lua',
    'core/class.lua',
    'core/task.lua',
    'core/stage.lua',
    'core/input.lua',
    'core/global.lua',
    'core/corefunc.lua',
    'core/file.lua',
    'core/loading.lua',
    'core/async.lua',
}

for _, f in ipairs(core) do
    DoFile(f)
end

FileExist = plus.FileExists

lstg.loadData()

local gamepad = require('platform.GamepadActions')
gamepad.init()
lstg.ResourceMgr:getInstance():clearLocalFileCache()
