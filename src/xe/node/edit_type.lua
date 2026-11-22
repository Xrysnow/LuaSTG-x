--
local M = {}
local enum_type = require('xe.node.enum_type')

M.any = {
}
M.audio_pan = {
    'string',
    'const',
    const = {
        { 'default', "self.x / 256" },
    },
}
M.bgstage = {
    'enum',
    enum = enum_type.bgstage
}
M.blend = {
    'enum',
    enum = enum_type.blend
}
M.bool = {
    'bool'
}
M.bulletstyle = {
    'bullet_style'
}
M.color = {
    'color_enum',
    --'color',
}
M.difficulty = {
    'enum',
    enum = enum_type.difficulty
}
M.directmode = {
    'enum',
    enum = enum_type.directmode
}
M.event = {
    -- only used in callbackfunc
    'enum',
    enum = enum_type.event
}
M.gop = {
    -- game object property
}
M.group = {
    'enum',
    enum = enum_type.group
}
M.image = {
    'image'
}
M.item = {
    -- used in dropitem
    'enum',
    enum = enum_type.item
}
M.layer = {
    'enum',
    enum = enum_type.layer
}
M.leftright = {
    'enum',
    enum = enum_type.leftright
}
M.movetomode = {
    'enum',
    enum = enum_type.movetomode
}
M.number = {
    --'number'
}
M.param = {
    'param'
}
M.pos = {
    'vec2',
    'const',
    const = {
        { 'follow_self', "self.x, self.y" },
        { 'follow_player', "player.x, player.y" },
        { 'follow_boss', "_boss.x, _boss.y" },
    },
    vec2  = { 'x', 'y' }
}
M.resfile = {
    'path',
    loadsound    = { "wav,ogg" },
    loadbgm      = { "wav,ogg" },
    loadimage    = { "png,jpg,bmp" },
    loadani      = { "png,jpg,bmp" },
    bossdefine   = { "png,jpg,bmp" },
    loadparticle = "psi",
    patch        = "lua",
    loadFX       = { "fx,vert,frag" },
}
M.selectenemystyle = {
    'enemy_style'
}
M.selecttype = {
    'type_name'
}
M.sound = {
    'sound_effect'
}
M.stagegroup = {
    'enum',
    enum = enum_type.stagegroup
}
M.string = {
}
M.typename = {
    -- define an editor class
    'type_define'
}
M.vec2 = {
    'vec2'
}

--

M.tween_type = {
    'tween_type',
    --'enum',
    --enum = enum_type.tween_type
}

for k, v in pairs(M) do
    if not table.has(v, 'string') then
        table.insert(v, 'string')
    end
end

M.code_lua = {
    'code',
    code = {
        lang = 'lua',
    }
}

return M
