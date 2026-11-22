---@type audio.Filter
local M = audio.Filter
require('audio.enum')

---Lowpass
---@param gain number The overall volume of the audio. Must be between 0 and 1.
---@param high_gain number Volume of high-frequency audio. Only applies to low-pass and band-pass filters. Must be between 0 and 1.
function M.Lowpass(gain, high_gain)
    return {
        [audio.FilterParameter.TYPE]     = audio.FilterType.LOWPASS,
        [audio.FilterParameter.VOLUME]   = gain,
        [audio.FilterParameter.HIGHGAIN] = high_gain,
    }
end

---Highpass
---@param gain number The overall volume of the audio. Must be between 0 and 1.
---@param low_gain number Volume of low-frequency audio. Only applies to high-pass and band-pass filters. Must be between 0 and 1.
function M.Highpass(gain, low_gain)
    return {
        [audio.FilterParameter.TYPE]    = audio.FilterType.HIGHPASS,
        [audio.FilterParameter.VOLUME]  = gain,
        [audio.FilterParameter.LOWGAIN] = low_gain,
    }
end

---Bandpass
---@param gain number The overall volume of the audio. Must be between 0 and 1.
---@param low_gain number Volume of low-frequency audio. Only applies to high-pass and band-pass filters. Must be between 0 and 1.
---@param high_gain number Volume of high-frequency audio. Only applies to low-pass and band-pass filters. Must be between 0 and 1.
function M.Bandpass(gain, low_gain, high_gain)
    return {
        [audio.FilterParameter.TYPE]     = audio.FilterType.BANDPASS,
        [audio.FilterParameter.VOLUME]   = gain,
        [audio.FilterParameter.LOWGAIN]  = low_gain,
        [audio.FilterParameter.HIGHGAIN] = high_gain,
    }
end

return M
