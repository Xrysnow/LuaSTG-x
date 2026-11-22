-- Load before Lua code that uses the old video.Player interface.
local player = assert(video and video.Player, "video texture support is required")
if rawget(player, "vplay") then
    return player
end

player.PlayMode = video.PlayMode
player.vplay = player.startPlayback
player.vstop = player.stopPlayback
player.vpause = player.pausePlayback
player.vresume = player.resumePlayback
player.seek = player.seekFrame

local nodeUpdate = cc.Node.update
local advance, advanceFrame = player.advance, player.advanceFrame
function player:update(dt)
    local result = nodeUpdate(self, dt)
    local seconds = tonumber(dt)
    if seconds and seconds > -math.huge and seconds < math.huge then
        if seconds < 0 then
            advanceFrame(self)
        else
            advance(self, seconds)
        end
    end
    return result
end

return player
