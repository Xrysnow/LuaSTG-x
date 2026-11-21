local gp = cc.gamepad
local M = {}

local groups = { 'keys', 'keysys' }
local stickAxes = { leftx = true, lefty = true, rightx = true, righty = true }
local buttons = {
    south = 'a', east = 'b', west = 'x', north = 'y', back = 'back', start = 'start',
    leftstick = 'leftstick', rightstick = 'rightstick', leftshoulder = 'leftshoulder',
    rightshoulder = 'rightshoulder', dpup = 'dpup', dpdown = 'dpdown',
    dpleft = 'dpleft', dpright = 'dpright',
}
M.hardwareButtons = {
    'south', 'east', 'west', 'north', 'leftshoulder', 'rightshoulder',
    'dpup', 'dpdown', 'dpleft', 'dpright', 'start', 'back',
}

local legacyButtons = {
    [4] = 'south', [5] = 'east', [7] = 'west', [8] = 'north',
    [10] = 'dpup', [11] = 'dpdown', [12] = 'dpleft', [13] = 'dpright',
    [15] = 'leftshoulder', [16] = 'rightshoulder',
    [19] = 'leftstick', [20] = 'rightstick', [21] = 'start', [22] = 'back',
}
local legacyAxes = {
    [0] = 'leftx', [1] = 'lefty', [2] = 'rightx', [3] = 'righty',
    [17] = 'lefttrigger', [18] = 'righttrigger',
}

function M.migration(config)
    local old = config.controller_map
    if type(old) ~= 'table' then return end
    local profile = { version = 2, slot = 0, keys = {}, keysys = {} }
    local missing = {}
    local different = false
    for _, group in ipairs(groups) do
        for name, key in pairs(old[group] or {}) do
            local default = default_setting.controller_map[group][name]
            if type(key) == 'table' and type(key[1]) == 'number' then
                different = different or not default or key[1] ~= default[1] or key[2] ~= default[2]
                local code = key[1] >= 1000 and key[1] - 1000 or key[1]
                -- Offsets below 1000 also came from unmapped devices. Only
                -- explicit Controller::Key codes have an unambiguous origin.
                if key[1] >= 1000 and key[2] == nil and legacyButtons[code] then
                    profile[group][name] = legacyButtons[code]
                elseif key[1] >= 1000 and type(key[2]) == 'boolean' and legacyAxes[code] then
                    profile[group][name] = (key[2] and '+' or '-') .. legacyAxes[code]
                else
                    missing[#missing + 1] = name
                end
            end
        end
    end
    if different then
        table.sort(missing)
        return profile, missing
    end
end

-- Match layout as well as model. Same-model units without serials keep separate
-- live IDs and require Start (or explicit selection) when more than one matches.
function M.identity(info)
    return table.concat({ info.layout, info.mappingGuid, info.name, info.vendor or '',
        info.product or '', info.serial or '' }, '|')
end

local function direction(binding)
    local sign, axis = binding:match('^([%+%-])(.+)$')
    return axis, sign == '-' and -1 or 1
end

local function valueAt(pad, binding, previous)
    local axis, sign = direction(binding)
    if not axis then return pad:down(binding) end
    local value = (pad:axis(axis) or 0) * sign
    return previous and value >= 0.45 or value >= 0.60
end

local function axisValue(name, value)
    return value / (stickAxes[name] and value < 0 and 32768 or 32767)
end

local profile, configured, selected, tick, lastKey, consumedAt
local actions, codeActions, installed = {}, {}, {}
local edges = {}
local inPause = false

local function source(action, key, down, emit)
    if action[key] == down then return end
    action[key] = down
    local held = action.keyboard or action.pad
    if held == action.held then return end
    action.held = held
    if emit then
        edges[#edges + 1] = { action = action.name, down = held }
    end
end

function M.loadFromSetting()
    configured = setting
    profile = configured.gamepad_actions
    if type(profile) ~= 'table' or profile.version ~= 2 then profile = default_setting.gamepad_actions end
    actions, codeActions = {}, {}
    edges = {}
    for _, group in ipairs(groups) do
        local names = {}
        for name in pairs(configured[group]) do names[#names + 1] = name end
        table.sort(names)
        for _, name in ipairs(names) do
            local binding = (profile[group] or {})[name]
            local action = {
                name = name, code = configured[group][name], binding = type(binding) == 'string' and binding or '',
                keyboard = false, pad = false, held = false,
            }
            actions[#actions + 1] = action
            codeActions[action.code] = action
        end
    end
    selected, tick, consumedAt = nil, nil, nil
end

local function install(pad, id, info)
    local identity = M.identity(info)
    local records = configured.gamepad_hardware
    local fields = type(records) == 'table' and records[identity] or nil
    fields = type(fields) == 'string' and fields or ''
    if not installed[id] and fields == '' and pad:mappingStatus() ~= 'Local' then return end
    if installed[id] == fields then return end
    local code = gp.setLocalBindings(id, info.layout, fields)
    if code and code >= 0 then installed[id] = fields end
end

local function observe(frame)
    if configured ~= setting then M.loadFromSetting() end
    local now = frame:tick()
    if tick == now then return end
    local first = tick == nil
    tick = now
    lastKey = nil
    local paused = ext and ext.pause_menu ~= nil
    -- The game can skip up to three Director ticks while simulating at 15 Hz.
    -- A launcher or an inactive scene has no consumer for older actions.
    local emit = not paused and consumedAt ~= nil and now - consumedAt <= 4
    if not emit or inPause then edges = {} end
    inPause = paused

    local pad, id, match, ambiguous
    local ids = frame:devices()
    local live = {}
    local slot = profile.slot or 0
    for _, candidate in ipairs(ids) do
        local view = frame:find(candidate)
        local info = view:info()
        live[candidate] = true
        install(view, candidate, info)
        if view:player() == slot then
            pad, id = view, candidate
        elseif view:mapped() and view:player() == nil and configured.gamepad_preferred == M.identity(info) then
            ambiguous = match ~= nil
            match = candidate
        end
    end
    for old in pairs(installed) do if not live[old] then installed[old] = nil end end
    if not pad and match and not ambiguous then gp.assignPlayer(match, slot) end
    for _, action in ipairs(actions) do
        source(action, 'keyboard', not not lstg.GetKeyState(action.code), not first and emit)
        if selected ~= id then
            source(action, 'pad', false, not first and emit)
        end
    end
    local useEdges = selected == id
    for e in frame:events() do
        if not pad and e.kind == 'button' and e.button == 'start' and e.down and e.reason == 'physical' then
            local candidate = frame:find(e.device)
            if candidate and candidate:mapped() and candidate:player() == nil then
                if gp.assignPlayer(e.device, slot) then break end
            end
        elseif pad and e.device == id and e.kind == 'playerChanged' then
            useEdges = true
        elseif pad and useEdges and e.device == id and (e.kind == 'button' or e.kind == 'axis') then
            for _, action in ipairs(actions) do
                local axis, sign = direction(action.binding)
                local down
                if e.kind == 'button' and action.binding == e.button then
                    down = e.down
                elseif e.kind == 'axis' and axis == e.axis then
                    local value = axisValue(axis, e.value) * sign
                    down = action.pad and value >= 0.45 or value >= 0.60
                end
                if down ~= nil then
                    if down and not action.pad and e.reason == 'physical' then lastKey = action.code end
                    source(action, 'pad', down, emit and (not down or e.reason == 'physical'))
                end
            end
        end
    end
    if pad then
        for _, action in ipairs(actions) do
            if action.binding ~= '' then
                local down = not not valueAt(pad, action.binding, action.pad)
                source(action, 'pad', down, emit and not down and selected == id)
            end
        end
    end
    selected = id
end

function M.init()
    M.loadFromSetting()
    if not M.listener then
        M.listener = cc.Director:getInstance():getEventDispatcher():addCustomEventListener(
            'director_before_update', function() observe(gp.frame()) end)
    end
end

function M.getStatus(code)
    observe(gp.frame())
    local action = codeActions[code]
    return action and action.pad
end

function M.getLastKey()
    observe(gp.frame())
    return lastKey or 0
end

function M.consume()
    local frame = gp.frame()
    if not consumedAt then consumedAt = frame:tick() end
    observe(frame)
    consumedAt = tick
    local current = { held = {}, pressed = {}, released = {}, edges = edges, tick = tick }
    edges = {}
    for _, action in ipairs(actions) do current.held[action.name] = action.held end
    for _, edge in ipairs(current.edges) do
        if edge.down then current.pressed[edge.action] = true else current.released[edge.action] = true end
    end
    return current
end

function M.bindLabel(pad, binding)
    if not binding or binding == '' then return '-' end
    local axis = direction(binding)
    if pad and not axis then
        local label = pad:label(binding)
        if label and label ~= '' then return label end
    end
    return binding
end

function M.learnAction(frame, id)
    if not id then return end
    for e in frame:events() do
        if e.device == id and e.reason == 'physical' then
            if e.kind == 'button' and e.down then return e.button end
            if e.kind == 'axis' then
                local value = axisValue(e.axis, e.value)
                if math.abs(value) >= 0.60 then return (value < 0 and '-' or '+') .. e.axis end
            end
        end
    end
end

function M.learnHardware(frame, id, target, existing)
    local field = buttons[target]
    if not field then return end
    for e in frame:events() do
        if e.device == id and e.reason == 'physical' and e.kind == 'raw' then
            local binding
            if e.control == 'button' and e.value ~= 0 then binding = 'b' .. e.index
            elseif e.control == 'axis' and math.abs(e.value) >= 22000 then
                binding = (e.value < 0 and '-' or '+') .. 'a' .. e.index
            elseif e.control == 'hat' and (e.value == 1 or e.value == 2 or e.value == 4 or e.value == 8) then
                binding = 'h' .. e.index .. '.' .. e.value
            end
            if binding then
                local fields = {}
                for entry in (existing or ''):gmatch('[^,]+') do
                    if entry:match('^([^:]+):') ~= field then fields[#fields + 1] = entry end
                end
                fields[#fields + 1] = field .. ':' .. binding
                return table.concat(fields, ',')
            end
        end
    end
end

return M
