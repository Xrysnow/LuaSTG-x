---@type string
local string = string

string.whitespace = ' \t\n\r\v\f'
string.ascii_lowercase = 'abcdefghijklmnopqrstuvwxyz'
string.ascii_uppercase = 'ABCDEFGHIJKLMNOPQRSTUVWXYZ'
string.ascii_letters = string.ascii_lowercase .. string.ascii_uppercase
string.digits = '0123456789'
string.hexdigits = string.digits .. 'abcdef' .. 'ABCDEF'
string.octdigits = '01234567'
string.punctuation = [[!"#$%&'()*+,-./:;<=>?@[\]^_`{|}~]]
string.printable = string.digits .. string.ascii_letters .. string.punctuation .. string.whitespace

function string.is_whitespace(s)
    return string.whitespace:find(s) ~= nil
end
function string.is_ascii_lowercase(s)
    return string.ascii_lowercase:find(s) ~= nil
end
function string.is_ascii_uppercase(s)
    return string.ascii_uppercase:find(s) ~= nil
end
function string.is_ascii_letter(s)
    return string.ascii_letters:find(s) ~= nil
end
function string.is_digit(s)
    return string.digits:find(s) ~= nil
end
function string.is_hexdigit(s)
    return string.hexdigits:find(s) ~= nil
end
function string.is_octdigit(s)
    return string.octdigits:find(s) ~= nil
end
function string.is_punctuation(s)
    return string.punctuation:find(s) ~= nil
end
function string.is_printable(s)
    return string.printable:find(s) ~= nil
end

local insert = table.insert
local concat = table.concat

---@param s string
---@param sep string
--function string.split(s, sep)
--    local ret = {}
--    if not sep or sep == '' then
--        local len = #s
--        for i = 1, len do
--            insert(ret, s:sub(i, i))
--        end
--    else
--        while true do
--            local p = string.find(s, sep)
--            if not p then
--                insert(ret, s)
--                break
--            end
--            local ss = s:sub(1, p - 1)
--            insert(ret, ss)
--            s = s:sub(p + 1, #s)
--        end
--    end
--    return ret
--end

---@param s string
function string.remove(s, pattern)
    return concat(string.split(s, pattern))
end

---@param s string
function string.capitalize(s)
    if s == '' then
        return ''
    end
    return string.upper(s:sub(1, 1)) .. s:sub(2)
end

function string.capwords(s, sep)
    sep = sep or ' '
    local w = string.split(s, sep)
    local c = {}
    for _, v in ipairs(w) do
        insert(c, string.capitalize(v))
    end
    return concat(c, sep)
end

--------------------------------------------------
-- filename and path
--------------------------------------------------

--- filename from path
---@param s string
---@param with_ext boolean
---@return string
function string.filename(s, with_ext)
    s = s:gsub('\\', '/'):gsub('/+', '/')
    if with_ext then
        return s:match(".*/([^/]*)$") or s
    else
        return s:match(".*/([^/]*)%.%w+$") or s:match(".*/([^/]*)$") or s:match("(.*)%.%w+") or s
    end
end

--- file extention from path
---@param s string
---@return string
function string.fileext(s)
    s = s:gsub('\\', '/'):gsub('/+', '/')
    return s:match(".*%.(%w+)$") or ''
end

--- file folder from path
---@param s string
---@return string
function string.filefolder(s)
    s = s:gsub('\\', '/'):gsub('/+', '/')
    return s:match("(.+)/[^/]*%w+$") or ''
end

---
---@param s string
---@return string
function string.path_uniform(s)
    return s:gsub('\\', '/'):gsub('/+', '/')
end

--------------------------------------------------

---
---@param s string
---@param str string
function string.starts_with(s, str)
    return s:sub(1, #str) == str
end

---
---@param s string
---@param str string
function string.ends_with(s, str)
    return s:sub(-#str, -1) == str
end
