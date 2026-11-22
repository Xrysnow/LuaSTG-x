local M = {}

M.types = {
    integer    = true,
    float      = true,
    enum       = true,
    boolean    = true,
    string     = true,
    vec2       = true,
    color      = true,
    image      = true,
    image_enum = true,
    code       = true,
}

M.node_types = {
    bool             = true,
    movetomode       = true,
    typename         = true,
    selecttype       = true,
    image            = true,
    group            = true,
    leftright        = true,
    blend            = true,
    param            = true,
    any              = true,
    difficulty       = true,
    layer            = true,
    calculus         = true,
    direct           = true,
    stagegroup       = true,
    item             = true,
    selectenemystyle = true,
    bulletstyle      = true,
    bgstage          = true,
    directmode       = true,
    event            = true,
    sound            = true,
    color            = true,
    resfile          = true,
    object           = true,
}

local _alias = {
    bool             = { 'boolean', 'code' },
    movetomode       = { 'enum', 'code' },
    typename         = { 'string', 'code' },
    selecttype       = { 'enum', 'code' },
    image            = { 'enum', 'code' },
    sound            = { 'enum', 'code' },
    group            = { 'enum', 'code' },
    leftright        = { 'enum', 'code' },
    blend            = { 'enum', 'code' },
    param            = { 'code', },
    any              = { 'code', },
    difficulty       = { 'enum', 'string', 'code' },
    layer            = { 'enum', 'code' },
    calculus         = { 'enum', 'code' },
    direct           = { 'enum', 'code' },
    stagegroup       = { 'enum', 'code' },
    item             = { 'enum', 'code' },
    selectenemystyle = { 'enum', 'code' },
    bulletstyle      = { 'enum', 'code' },
    bgstage          = { 'enum', 'code' },
    directmode       = { 'enum', 'code' },
    event            = { 'enum', 'code' },
    color            = { 'enum', 'color', 'code' },
    resfile          = { 'string', 'code' },
    object           = { 'code', },
}

function M.has(t)
    return M.types[t]
end

return M
