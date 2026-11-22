local forward = require('forward')
forward.forward('LoadFont')
forward.forward('SetResourceStatus')

local profiler = profiler
local e = lstg.eventDispatcher

function BeforeRender()
    lstg.forceSetViewMode('ui')
    --TODO: fix this
    for k, _ in pairs(forward.Fonts) do
        RenderText(k, ' ', 0, 0)
    end
    e:dispatchEvent('onBeforeRender')
end

function AfterRender()
    e:dispatchEvent('onAfterRender')
end

local abs = abs
local cos = cos
local sin = sin
local hypot = hypot
local pairs = pairs
local rawget = rawget

local ot = ObjTable()

function UserSystemOperation()
    --assistance of Polar coordinate system
    local polar--, radius, angle, delta, omiga, center
    --acceleration and gravity
    local alist--, accelx, accely, gravity
    --limitation of velocity
    local forbid--, vx, vy, v, ovx, ovy, cache
    --
    for i = 1, 32768 do
        local obj = ot[i]
        if obj then
            polar = rawget(obj, 'polar')
            if polar then
                local radius = polar.radius or 0
                local angle = polar.angle or 0
                local delta = polar.delta
                if delta then
                    polar.radius = radius + delta
                end
                local omiga = polar.omiga
                if omiga then
                    polar.angle = angle + omiga
                end
                local center = polar.center or { x = 0, y = 0 }
                radius = polar.radius
                angle = polar.angle
                obj.x = center.x + radius * cos(angle)
                obj.y = center.y + radius * sin(angle)
            end
            alist = rawget(obj, 'acceleration')
            if alist then
                local accelx = alist.ax
                if accelx then
                    obj.vx = obj.vx + accelx
                end
                local accely = alist.ay
                if accely then
                    obj.vy = obj.vy + accely
                end
                local gravity = alist.g
                if gravity then
                    obj.vy = obj.vy - gravity
                end
            end
            forbid = rawget(obj, 'forbidveloc')
            if forbid then
                local ovx = obj.vx
                local ovy = obj.vy
                local v = forbid.v
                if v and (v * v) < (ovx * ovx + ovy * ovy) then
                    local cache = v / hypot(ovx, ovy)
                    obj.vx = cache * ovx
                    obj.vy = cache * ovy
                    ovx = obj.vx
                    ovy = obj.vy
                end
                local vx = forbid.vx
                local vy = forbid.vy
                if vx and vx < abs(ovx) then
                    obj.vx = vx
                end
                if vy and vy < abs(ovy) then
                    obj.vy = vy
                end
            end
        end
    end
    --rebounder
    if not rebounder then
        return
    end
    if not ReboundPause and rebounder.size ~= 0 then
        for _, obj in ObjList(GROUP_ENEMY_BULLET) do
            if IsValid(obj) and obj.colli and (obj.vx ~= 0 or obj.vy ~= 0) then
                local accel, ax, ay = obj.acceleration, 0, 0
                if accel then
                    ax, ay = accel.ax, accel.ay
                end
                local result = { rebounding.ReboundCheck(obj.x, obj.y, obj.vx, obj.vy, ax, ay) }
                if result[1] then
                    obj.x, obj.y, obj.vx, obj.vy = unpack(result, 1, 4)
                    if accel then
                        accel.ax, accel.ay = result[5], result[6]
                    end
                    for i = 7, #result do
                        local self = rebounder.list[result[i]]
                        self.class.colli(self, obj)
                    end
                end
            end
        end
        for _, obj in ObjList(GROUP_INDES) do
            if IsValid(obj) and obj.colli and (obj.vx ~= 0 or obj.vy ~= 0) then
                local accel, ax, ay = obj.acceleration, 0, 0
                if accel then
                    ax, ay = accel.ax, accel.ay
                end
                local result = { rebounding.ReboundCheck(obj.x, obj.y, obj.vx, obj.vy, ax, ay) }
                if result[1] then
                    obj.x, obj.y, obj.vx, obj.vy = unpack(result, 1, 4)
                    if accel then
                        accel.ax, accel.ay = result[5], result[6]
                    end
                    for i = 7, #result do
                        local self = rebounder.list[result[i]]
                        self.class.colli(self, obj)
                    end
                end
            end
        end
    end
end

--local jit = require('jit')
--local ffi = ffi or require('ffi')
--local ptr_t = ffi.typeof('uint32_t*')
--local ObjOnFrame = ObjOnFrame
--local ii = 0

function _DoFrame()
    --SetTitle(setting.mod .. ' | FPS=' .. GetFPS() .. ' | Nobj=' .. GetnObj())
    UpdateObjList()
    GetInput()
    --next_stage顶替current_stage
    if stage.next_stage then

        -- from ex
        if lstg.var.ran_seed then
            ran:Seed(lstg.var.ran_seed)
        end

        stage.current_stage = stage.next_stage
        stage.next_stage = nil
        stage.current_stage.timer = 0
        stage.current_stage:init()
    end
    if stage.current_stage then
        task.Do(stage.current_stage)
        if stage.current_stage then
            stage.current_stage:frame()
            stage.current_stage.timer = stage.current_stage.timer + 1
        end
    end

    profiler.tic('ObjFrame')
    ObjFrame()--LPOOL.DoFrame() 执行对象的Frame函数
    profiler.toc('ObjFrame')

    profiler.tic('UserSystemOperation')
    UserSystemOperation()  --用于lua层模拟内核级操作
    profiler.toc('UserSystemOperation')

    BoundCheck()--执行边界检查

    profiler.tic('CollisionCheck')
    --碰撞检查
    CollisionCheck(GROUP_PLAYER, GROUP_ENEMY_BULLET)
    CollisionCheck(GROUP_PLAYER, GROUP_ENEMY)
    CollisionCheck(GROUP_PLAYER, GROUP_INDES)
    CollisionCheck(GROUP_ENEMY, GROUP_PLAYER_BULLET)
    CollisionCheck(GROUP_NONTJT, GROUP_PLAYER_BULLET)
    CollisionCheck(GROUP_ITEM, GROUP_PLAYER)
    profiler.toc('CollisionCheck')

    profiler.tic('UpdateXY')
    UpdateXY()--更新对象的XY坐标偏移量
    profiler.toc('UpdateXY')

    profiler.tic('AfterFrame')
    AfterFrame()--帧末更新函数
    profiler.toc('AfterFrame')

    --next_stage顶替current_stage
    if stage.next_stage and stage.current_stage then
        stage.current_stage:del()
        task.Clear(stage.current_stage)
        if stage.preserve_res then
            stage.preserve_res = nil
        else
            RemoveResource 'stage'--清空场景资源池
            SystemLog(i18n 'clear stage resource pool')
        end
        --LPOOL.ResetPool 清空对象池
        ResetPool()
        SystemLog(i18n 'clear object pool')
        --LDEBUG()
    end
end

function DoFrame()
    local factor = 1
    if setting.render_skip then
        factor = int(setting.render_skip) + 1
    end
    for _ = 1, factor do
        _DoFrame()
    end
end

---@~chinese 将被每帧调用以执行渲染指令。
---
---@~english Will be invoked every frame to process all render instructions.
---
function RenderFunc()
    e:dispatchEvent('onRenderFunc')
end
e:addListener('onRenderFunc', function()
    local stage = stage
    if not stage.current_stage then
        return
    end
    if stage.current_stage.timer and stage.current_stage.timer > 1 and stage.next_stage == nil then
        BeginScene()

        BeforeRender()

        --profiler.tic('stagerender')
        stage.current_stage:render()
        --profiler.toc('stagerender')

        profiler.tic('ObjRender')
        ObjRender()
        profiler.toc('ObjRender')

        --profiler.tic('AfterRender')
        AfterRender()
        --profiler.toc('AfterRender')

        --profiler.tic('EndScene')
        e:dispatchEvent('beforeEndScene')
        EndScene()
        e:dispatchEvent('afterEndScene')
        --profiler.toc('EndScene')
    end
end, 0)

----------------------------------------------------------------------

---@~chinese 将被每帧调用以执行帧逻辑。返回`true`时会使游戏退出。
---
---@~english Will be invoked every frame to process all frame logic. Game will exit if it returns `true`.
---
function FrameFunc()
    e:dispatchEvent('onFrameFunc')
    return lstg.quit_flag
end

e:addListener('onFrameFunc', function()
    if GetLastKey() == setting.keysys.snapshot and setting.allowsnapshot then
        Screenshot()
    end
end, -1, 'Screenshot')

e:addListener('onFrameFunc', function()
    if lstg.quit_flag then
        GameExit()
    end
end, 9, 'GameExit')

e:addListener('onFrameFunc', function()
    if GetKeyState(KEY.CTRL) and GetLastKey() == KEY.R then
        lstg.included = {}
        lstg.current_script_path = { '' }
        lstg.eventDispatcher:removeAllListeners()
        for _, v in ipairs(
                {
                    'RenderFunc',
                    'FrameFunc',
                    'all_class',
                    'class_name',
                }) do
            _G[v] = nil
        end
        Print('=   FrameReset   =')
        FrameReset()
        dofile('main.lua')
    end
end, 10, 'FrameReset')

----------------------------------------------------------------------

---@~chinese 将在窗口失去焦点时调用。
---
---@~english Will be invoked when the window lose focus.
---
function FocusLoseFunc()
    e:dispatchEvent('onFocusLose')
end

---@~chinese 将在窗口重新获得焦点时调用。
---
---@~english Will be invoked when the window get focus.
---
function FocusGainFunc()
    e:dispatchEvent('onFocusGain')
end

---@~chinese 将在引擎初始化结束后调用。
---
---@~english Will be invoked after the initialization of engine finished.
---
function GameInit()
    SetViewMode 'ui'
    if stage.next_stage == nil then
        error(i18n 'Entrance stage not set')
    end
    SetResourceStatus 'stage'
end

local Director = cc.Director:getInstance()
function GameExit()
    lstg.saveSettingFile()
    print('Clear resource pool')
    lstg.ClearResourcePool()
    print('FrameEnd')
    lstg.FrameEnd()
    print('FrameEnd finish')
    if plus and plus.isMobile() then
        Director:endToLua()
    else
        os.exit()
    end
end

--

function DrawCollider()
    local x, y = 0, 0
    DrawGroupCollider(GROUP_ENEMY_BULLET, Color(150, 163, 73, 164), x, y)
    DrawGroupCollider(GROUP_ENEMY, Color(150, 163, 73, 164), x, y)
    DrawGroupCollider(GROUP_INDES, Color(150, 163, 73, 20), x, y)
    DrawGroupCollider(GROUP_PLAYER, Color(100, 175, 15, 20), x, y)

    --DrawGroupCollider(GROUP_ITEM, Color(100, 175, 175, 175), x, y)
end

local show_collider = false

e:addListener('beforeEndScene', function()
    if KeyIsPressed('toggle_collider') then
        show_collider = not show_collider
    end
    if show_collider then
        DrawCollider()
    end
    SetViewMode('world')
end, 9)

--

---
function Screenshot()
    local time = os.date("%Y-%m-%d-%H-%M-%S")
    local path = 'snapshot/' .. time .. '.png'
    lstg.Snapshot(path)
    SystemLog(string.format('%s %q', i18n('save screenshot to'), path))
end

function BentLaserData()
    return lstg.GameObjectBentLaser:create()
end

--

local shader_path = "src/shader/"
local internalShaders = {
    add   = { "Common.vert", "ColorAdd.frag" },
    addF1 = { "Fog_Liner.vert", "ColorAdd_Fog.frag" },
    addF2 = { "Fog_Exp1.vert", "ColorAdd_Fog.frag" },
    addF3 = { "Fog_Exp2.vert", "ColorAdd_Fog.frag" },
    mul   = { "Common.vert", "ColorMulti.frag" },
    mulF1 = { "Fog_Liner.vert", "ColorMulti_Fog.frag" },
    mulF2 = { "Fog_Exp1.vert", "ColorMulti_Fog.frag" },
    mulF3 = { "Fog_Exp2.vert", "ColorMulti_Fog.frag" },
}

local _bop = ccb.BlendOperation
local _bfac = ccb.BlendFactor
local internalMode = {
    ['add+add']   = { _bop.ADD, _bfac.SRC_ALPHA, _bfac.ONE },
    ['add+alpha'] = { _bop.ADD, _bfac.SRC_ALPHA, _bfac.ONE_MINUS_SRC_ALPHA },
    ['add+sub']   = { _bop.SUBTRACT, _bfac.SRC_ALPHA, _bfac.ONE },
    ['add+rev']   = { _bop.RESERVE_SUBTRACT, _bfac.SRC_ALPHA, _bfac.ONE },

    ['mul+add']   = { _bop.ADD, _bfac.SRC_ALPHA, _bfac.ONE },
    ['mul+alpha'] = { _bop.ADD, _bfac.SRC_ALPHA, _bfac.ONE_MINUS_SRC_ALPHA },
    ['mul+sub']   = { _bop.SUBTRACT, _bfac.SRC_ALPHA, _bfac.ONE },
    ['mul+rev']   = { _bop.RESERVE_SUBTRACT, _bfac.SRC_ALPHA, _bfac.ONE },

    ['']          = { _bop.ADD, _bfac.SRC_ALPHA, _bfac.ONE_MINUS_SRC_ALPHA },
}
for k, v in pairs(internalMode) do
    local m = k:sub(1, 3)
    if m == '' then
        m = 'mul'
    end
    local s = internalShaders[m]
    local p = CreateShaderProgramFromPath(
            shader_path .. s[1], shader_path .. s[2])
    assert(p)
    local rm = lstg.RenderMode:create(k, v[1], v[2], v[3], p)
    assert(rm, i18n 'failed to create RenderMode')
    -- backup default RenderMode
    rm:clone('_' .. k)
    for i = 1, 3 do
        local k_fog = ('%sF%d'):format(m, i)
        local s_fog = internalShaders[k_fog]
        local p_fog = CreateShaderProgramFromPath(
                shader_path .. s_fog[1], shader_path .. s_fog[2])
        local name = ('%s+fog%d'):format(k, i)
        local rm_fog = lstg.RenderMode:create(name, v[1], v[2], v[3], p_fog)
        assert(rm_fog, i18n 'failed to create RenderMode')
    end
end
lstg.RenderMode:getByName(''):setAsDefault()

function CreateRenderMode(name, blendEquation, blendFuncSrc, blendFuncDst, shaderName)
    local shaderProgram
    if not shaderName then
        shaderProgram = lstg.RenderMode:getDefault():getProgram()
    else
        local res = FindResFX(shaderName)
        assert(res, shaderName)
        if res then
            shaderProgram = res:getProgram()
        end
    end
    assert(shaderProgram)
    if type(blendEquation) == 'string' then
        blendEquation = _bop[blendEquation:upper()]
    end
    if type(blendFuncSrc) == 'string' then
        blendFuncSrc = _bfac[blendFuncSrc:upper()]
    end
    if type(blendFuncDst) == 'string' then
        blendFuncDst = _bfac[blendFuncDst:upper()]
    end
    local ret = lstg.RenderMode:create(
            name, blendEquation, blendFuncSrc, blendFuncDst, shaderProgram)
    assert(ret, i18n 'failed to create RenderMode')
    return ret
end

-- local p_light = CreateShaderProgramFromPath(
--         shader_path .. 'NormalTex.vert', shader_path .. 'NormalTex.frag')
local p_light = nil
if p_light then
    local rm = lstg.RenderMode:create(
            'lstg.light', _bop.ADD, _bfac.SRC_ALPHA, _bfac.ONE_MINUS_SRC_ALPHA, p_light)
    assert(rm, i18n 'failed to create RenderMode')
end

---@~chinese 设置雾效果。若无参数，将关闭雾效果。否则开启雾效果。
---@~chinese - `near`为`-1`时，使用EXP1算法，`far`作为强度参数。
---@~chinese - `near`为`-2`时，使用EXP2算法，`far`作为强度参数。
---@~chinese - 否则，使用线性算法，`near, far`作为范围参数。
---
---@~english Set fog effect. Will clear fog effect if no parameter if passed, otherwise enable fog effect.
---@~english - If `near` is `-1`, EXP1 algorism will be used and `far` will be density parameter.
---@~english - If `near` is `-2`, EXP2 algorism will be used and `far` will be density parameter.
---@~english - Otherwise, linear algorism will be used and `near, far` will be range parameter.
---
---@param near number
---@param far number
---@param color lstg.Color 可选，默认为`0x00FFFFFF` | optional, default is `0x00FFFFFF`.
function SetFog(near, far, color)
    local t = {}
    local fog_type
    if not near or near == far then
        -- no fog
        for k, _ in pairs(internalMode) do
            t[k] = '_' .. k
        end
    elseif near == -1 then
        -- exp1
        fog_type = 2
        for k, _ in pairs(internalMode) do
            t[k] = k .. '+fog2'
        end
    elseif near == -2 then
        -- exp2
        fog_type = 3
        for k, _ in pairs(internalMode) do
            t[k] = k .. '+fog3'
        end
    else
        -- linear
        fog_type = 1
        for k, _ in pairs(internalMode) do
            t[k] = k .. '+fog1'
        end
    end
    color = color or Color(0xff000000)
    for k, v in pairs(t) do
        local rm = lstg.RenderMode:getByName(k)
        local rm_fog = lstg.RenderMode:getByName(v)
        assert(rm, ("%q"):format(k))
        assert(rm_fog, ("%q"):format(v))
        rm:setProgram(rm_fog:getProgram())
        if fog_type then
            rm:setColor('u_fogColor', color)
            if fog_type == 1 then
                rm:setFloat('u_fogStart', near)
                rm:setFloat('u_fogEnd', far)
            else
                rm:setFloat('u_fogDensity', far)
            end
        end
    end
end
lstg.SetFog = SetFog

function SetDepth(enable, compareFunc)
    local r = cc.Director:getInstance():getRenderer()
    if enable then
        r:setDepthTest(true)
        r:setDepthWrite(true)
        if compareFunc then
            if type(compareFunc) == 'string' then
                compareFunc = ccb.CompareFunction[compareFunc:upper()]
            end
            assert(type(compareFunc) == 'number')
            r:setDepthCompareFunction(compareFunc)
        end
    else
        r:setDepthTest(false)
        r:setDepthWrite(false)
    end
end

--

local _capture = {}

---
--- x,y,w,h are in ui coords
---@param obj object
---@param x number
---@param y number
---@param w number
---@param h number
function CaptureScreen(obj, x, y, w, h)
    x = x + screen.dx
    y = y + screen.dy
    local scale = screen.scale
    table.insert(_capture,
                 { obj, x * scale, y * scale, w * scale, h * scale })
end

e:addListener('afterEndScene', function()
    if #_capture > 0 then
        ---@type cc.RenderTexture
        local fb = CopyFrameBuffer()
        local sp = fb:getSprite()
        local sz = sp:getTextureRect()
        local hh = sz.height
        for _, v in ipairs(_capture) do
            local obj, x, y, w, h = unpack(v)
            local newsp = cc.Sprite:createWithTexture(
                    sp:getTexture(), cc.rect(x, hh - y - h, w, h), false)
            local r = lstg.ResSprite:createWithSprite(
                    string.format('::CAP:: %s', tostring(obj)), newsp, 0, 0, 0)
            obj.img = r
        end
        _capture = {}
    end
end, 1, 'CaptureScreen')
