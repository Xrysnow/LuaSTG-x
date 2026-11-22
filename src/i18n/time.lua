--
local M = {}

function M.getTimeZone()
    return 24 - os.time({ year = 1970, month = 1, day = 2, hour = 0, min = 0, sec = 0 }) / 3600
end

return M
