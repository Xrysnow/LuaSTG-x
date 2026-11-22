local M = {}
M._rep_path = nil
M._rep_stage = nil

function M.enterStage(stage_, fade, wait)
    wait = wait or 0
    if CheckRes('bgm', 'menu') then
        local t = fade and 30 or 0
        t = t + wait
        task.New(stage_, function()
            for i = 1, t do
                SetBGMVolume('menu', 1 - i / t)
                task.Wait()
            end
        end)
    end
    task.New(stage_, function()
        task.Wait(wait)
        if fade then
            New(mask_fader, 'close')
            task.Wait(30)
        end
        if lstg.practice == 'stage' then
            stage.group.PracticeStart(lstg.stage_name)
        elseif lstg.practice == 'spell' then
            stage.group.PracticeStart('Spell Practice@Spell Practice')
        elseif lstg.practice == 'replay' then
            -- since lstg.tmpvar can be cleared, consider set by M
            local rep_path = lstg.tmpvar.rep_path or M._rep_path
            local rep_stage = lstg.tmpvar.rep_stage or M._rep_stage
            SystemLog(string.format(
                    '[enterStage] %s, %s', rep_path, rep_stage))
            stage.Set('load', rep_path, rep_stage)
        else
            stage.group.Start(stage.groups[lstg.group_name])
        end
    end)
end

function M.stopMusics()
    local t_global, t_stage = EnumRes(ENUM_RES_TYPE.bgm)
    for _, v in pairs(t_global) do
        StopMusic(v)
    end
    for _, v in pairs(t_stage) do
        StopMusic(v)
    end
end

function M.stopSounds()
    local t_global, t_stage = EnumRes(ENUM_RES_TYPE.snd)
    for _, v in pairs(t_global) do
        StopSound(v)
    end
    for _, v in pairs(t_stage) do
        StopSound(v)
    end
end

function M.stopAudios()
    M.stopMusics()
    M.stopSounds()
end

local content = require('game.content')
function M.getSlotStrings()
    local ret = {}
    for i = 1, ext.replay.GetSlotCount() do
        ret[i] = string.format(
                'No.%02d %s %s %s %s %s %s',
                i,
                '--------',
                '--/--/--',
                '--:--',
                '--------',
                '-------',
                '---'
        )
    end
    local replays = content.enumReplays()
    for _, rep in ipairs(replays) do
        local str = string.format(
                'No.%02d %s %s %s %s %s %s',
                rep.index,
                rep.user_str,
                rep.date_str,
                rep.time_str,
                rep.player_str,
                rep.rank_str,
                rep.stage_str
        )
        ret[rep.index] = str
    end
end

local resTypeNames = {
    [1] = 'Texture',
    [2] = 'Sprite',
    [3] = 'Animation',
    [4] = 'Music',
    [5] = 'SoundEffect',
    [6] = 'Particle',
    [7] = 'Font',
    [8] = 'FX',
    [9] = 'RenderTarget',
}

function M.collectResInfo()
    local t = {}
    local count = {
        global       = 0,
        stage        = 0,
        Texture      = 0,
        Sprite       = 0,
        Animation    = 0,
        Music        = 0,
        SoundEffect  = 0,
        Particle     = 0,
        Font         = 0,
        FX           = 0,
        RenderTarget = 0,
    }
    local pools = lstg.getResourcePool()
    for _, poolName in ipairs({ 'global', 'stage' }) do
        local pool = pools[poolName]
        for i = 1, #resTypeNames do
            local p = pool[i]
            local keys = p:keys()
            table.sort(keys)
            for i, key in ipairs(keys) do
                ---@type lstg.Resource
                local res = p:at(key)
                local typeName = resTypeNames[res:getType()] or 'N/A'
                local path = res:getPath()
                local info = res:getInfo()
                table.insert(t, {
                    name     = key,
                    info     = info,
                    typeName = typeName,
                    path     = path,
                    poolName = poolName
                })
                if count[poolName] then
                    count[poolName] = count[poolName] + 1
                else
                    count[poolName] = 1
                end
                if count[typeName] then
                    count[typeName] = count[typeName] + 1
                else
                    count[typeName] = 1
                end
            end
        end
    end
    return t, count
end

return M
