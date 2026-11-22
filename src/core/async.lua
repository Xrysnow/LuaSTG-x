--

---@class core.async
local async = {}

local tasks = std.list()

function async.addTask(task, tag, info)
    tag = tag or tostring(task)
    tasks:push_back({ task, tag, info })
    return tag
end

function async.getInfoByTag(tag)
    if not tag then
        return
    end
    for _, v in tasks:iter() do
        if v[2] == tag then
            return v[3]
        end
    end
end

function async.getNextTaskInfo()
    if tasks:empty() then
        return
    end
    local t = tasks:front()
    return t[3]
end

function async.getTaskCount()
    return tasks:size()
end

local load_tasks = {
    tex = {},
    img = {},
    ani = {},
    bgm = {},
    snd = {},
    psi = {},
    fnt = {},
    ttf = {},
    fx  = {},
}
local function check_loaded(type, name)
    if load_tasks[type][name] or FindResource(name, type) then
        --Print(string.format('resource %q (%s) has been loaded, ignore', name, type))
        return true
    end
    return false
end

local last_load_finished
local loader_waiting
local _loader_tag = '::load::'

local function add_loader(type, name, isAsync, handler, args, nArg)
    if check_loaded(type, name) then
        return
    end
    local info = { type, name }
    local task
    if isAsync then
        task = function()
            loader_waiting = { info }
            local arg = { unpack(args, 1, nArg) }
            table.insert(arg, function()
                last_load_finished = info
                load_tasks[type][name] = nil
                -- wait for one more frame
                loader_waiting.wait_once = true
            end)
            handler(unpack(arg))
        end
    else
        task = function()
            handler(unpack(args))
            last_load_finished = info
            load_tasks[type][name] = nil
        end
    end
    load_tasks[type][name] = task
    async.addTask(task, _loader_tag, info)
end

local fenv = {}

-- type, isAsync, loader, nArg
local _loader_cfg = {
    LoadTexture   = { 'tex', true, 'LoadTextureAsync', 2 },
    LoadImage     = { 'img', false },
    LoadAnimation = { 'ani', false },
    LoadPS        = { 'psi', true, 'LoadPSAsync', 6 },
    LoadFont      = { 'fnt', true, 'LoadFontAsync', 2 },
    LoadTTF       = { 'ttf', true, 'LoadTTFAsync', 3 },
    LoadSound     = { 'snd', true, 'LoadSoundAsync', 2 },
    LoadMusic     = { 'bgm', true, 'LoadMusicAsync', 4 },
    LoadFX        = { 'fx', false },
}

for k, v in pairs(_loader_cfg) do
    local f = _G[k]
    if v[2] then
        f = _G[v[3]]
    end
    assert(f)
    fenv[k] = function(name, ...)
        add_loader(v[1], name, v[2], f, { name, ... }, v[4])
    end
end

setmetatable(fenv, { __index = _G })

function async.addLoader(task, callback)
    local n0 = async.getTaskCount()
    setfenv(task, fenv)
    task()
    local n1 = async.getTaskCount()
    if callback then
        async.addTask(callback)
    end
    return n1 - n0
end

--- if next task is a load task, return its info
---@return table|nil {type, name}
function async.getNextLoaderInfo()
    if tasks:empty() then
        return
    end
    local t = tasks:front()
    if t[2] == _loader_tag then
        return t[3]
    end
end

---@return table|nil {type, name}
function async.getLoadingInfo()
    if loader_waiting then
        return loader_waiting[1]
    end
    return async.getNextLoaderInfo()
end

function async.isFinished()
    return async.getTaskCount() == 0
end

local _empty_task = std.fvoid

function async.addWait(t)
    t = t or 1
    if t <= 0 then
        return
    end
    for _ = 1, t do
        async.addTask(_empty_task)
    end
end

--

local function process_one_task()
    -- wait
    if loader_waiting then
        if loader_waiting.wait_once then
            loader_waiting = nil
        end
        return
    end
    if tasks:empty() then
        return
    end
    local t = tasks:front()
    tasks:pop_front()
    t[1]()
end

lstg.eventDispatcher:addListener('onFrameFunc', function()
    process_one_task()
end, -1, 'async.process')

_G['async'] = async
--return async
