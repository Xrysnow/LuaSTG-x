---@type audio.Effect
local M = audio.Effect
require('audio.enum')

local function setEffect(id, t)
    if id == nil then
        id = tostring(t)
    else
        id = tostring(id)
    end
    if not audio.Engine:setEffect(id, t) then
        Print('failed to create audio effect', id)
        return
    end
    return id
end

--- reverb: Decaying feedback based effect, on the order of milliseconds. Used to simulate the reflection off of the surroundings.
---@param id string
---@param gain number
---@param highgain number
---@param density number
---@param diffusion number
---@param decaytime number
---@param decayhighratio number
---@param earlygain number
---@param earlydelay number
---@param lategain number
---@param latedelay number
---@param roomrolloff number
---@param airabsorption number
---@param highlimit boolean
---@return string return id if success, nil if failed
function M.Reverb(id, gain, highgain, density, diffusion, decaytime, decayhighratio, earlygain, earlydelay, lategain, latedelay, roomrolloff, airabsorption, highlimit)
    highlimit = highlimit and 0 or 1
    local t = {
        [audio.EffectParameter.TYPE]              = audio.EffectType.REVERB,
        [audio.EffectParameter.REVERB_GAIN]       = gain,
        [audio.EffectParameter.REVERB_HFGAIN]     = highgain,
        [audio.EffectParameter.REVERB_DENSITY]    = density,
        [audio.EffectParameter.REVERB_DIFFUSION]  = diffusion,
        [audio.EffectParameter.REVERB_DECAY]      = decaytime,
        [audio.EffectParameter.REVERB_HFDECAY]    = decayhighratio,
        [audio.EffectParameter.REVERB_EARLYGAIN]  = earlygain,
        [audio.EffectParameter.REVERB_EARLYDELAY] = earlydelay,
        [audio.EffectParameter.REVERB_LATEGAIN]   = lategain,
        [audio.EffectParameter.REVERB_LATEDELAY]  = latedelay,
        [audio.EffectParameter.REVERB_ROLLOFF]    = roomrolloff,
        [audio.EffectParameter.REVERB_AIRHFGAIN]  = airabsorption,
        [audio.EffectParameter.REVERB_HFLIMITER]  = highlimit,
    }
    return setEffect(id, t)
end

--- chorus: Plays multiple copies of the sound with slight pitch and time variation. Used to make sounds sound "fuller" or "thicker".
---@param id string
---@param waveform audio.EffectWaveform
---@param phase number @[-180, 180], 90
---@param rate number @[0.0, 10.0], 1.1
---@param depth number @[0.0, 1.0], 0.1
---@param feedback number @[-1.0, 1.0], 0.25
---@param delay number @[0.0, 0.016], 0.016
---@return string return id if success, nil if failed
function M.Chorus(id, waveform, phase, rate, depth, feedback, delay)
    local t = {
        [audio.EffectParameter.TYPE]            = audio.EffectType.CHORUS,
        [audio.EffectParameter.CHORUS_WAVEFORM] = waveform,
        [audio.EffectParameter.CHORUS_PHASE]    = phase,
        [audio.EffectParameter.CHORUS_RATE]     = rate,
        [audio.EffectParameter.CHORUS_DEPTH]    = depth,
        [audio.EffectParameter.CHORUS_FEEDBACK] = feedback,
        [audio.EffectParameter.CHORUS_DELAY]    = delay,
    }
    return setEffect(id, t)
end

--- distortion: Alters the sound by amplifying it until it clips, shearing off parts of the signal, leading to a compressed and distorted sound.
---@param id string
---@param gain number
---@param edge number
---@param lowcut number
---@param center number
---@param bandwidth number
---@return string return id if success, nil if failed
function M.Distortion(id, gain, edge, lowcut, center, bandwidth)
    local t = {
        [audio.EffectParameter.TYPE]                = audio.EffectType.DISTORTION,
        [audio.EffectParameter.DISTORTION_GAIN]     = gain,
        [audio.EffectParameter.DISTORTION_EDGE]     = edge,
        [audio.EffectParameter.DISTORTION_LOWCUT]   = lowcut,
        [audio.EffectParameter.DISTORTION_EQCENTER] = center,
        [audio.EffectParameter.DISTORTION_EQBAND]   = bandwidth,
    }
    return setEffect(id, t)
end

--- echo: Decaying feedback based effect, on the order of seconds. Also known as delay causes the sound to repeat at regular intervals at a decreasing volume.
---@param id string
---@param delay number
---@param tapdelay number
---@param damping number
---@param feedback number
---@param spread number
---@return string return id if success, nil if failed
function M.Echo(id, delay, tapdelay, damping, feedback, spread)
    local t = {
        [audio.EffectParameter.TYPE]          = audio.EffectType.ECHO,
        [audio.EffectParameter.ECHO_DELAY]    = delay,
        [audio.EffectParameter.ECHO_LRDELAY]  = tapdelay,
        [audio.EffectParameter.ECHO_DAMPING]  = damping,
        [audio.EffectParameter.ECHO_FEEDBACK] = feedback,
        [audio.EffectParameter.ECHO_SPREAD]   = spread,
    }
    return setEffect(id, t)
end

--- flanger: Plays two copies of the sound while varying the phase, or equivalently delaying one of them, by amounts on the order of milliseconds, resulting in phasing sounds.
---@param id string
---@param waveform audio.EffectWaveform
---@param phase number
---@param rate number
---@param depth number
---@param feedback number
---@param delay number
---@return string return id if success, nil if failed
function M.Flanger(id, waveform, phase, rate, depth, feedback, delay)
    local t = {
        [audio.EffectParameter.TYPE]             = audio.EffectType.FLANGER,
        [audio.EffectParameter.FLANGER_WAVEFORM] = waveform,
        [audio.EffectParameter.FLANGER_PHASE]    = phase,
        [audio.EffectParameter.FLANGER_RATE]     = rate,
        [audio.EffectParameter.FLANGER_DEPTH]    = depth,
        [audio.EffectParameter.FLANGER_FEEDBACK] = feedback,
        [audio.EffectParameter.FLANGER_DELAY]    = delay,
    }
    return setEffect(id, t)
end

---
---@param id string
---@param frequency number
---@param left_dir audio.EffectDirection
---@param right_dir audio.EffectDirection
---@return string return id if success, nil if failed
function M.FreqShifter(id, frequency, left_dir, right_dir)
    local t = {
        [audio.EffectParameter.TYPE]                 = audio.EffectType.FREQSHIFTER,
        [audio.EffectParameter.FREQSHIFTER_FREQ]     = frequency,
        [audio.EffectParameter.FREQSHIFTER_LEFTDIR]  = left_dir,
        [audio.EffectParameter.FREQSHIFTER_RIGHTDIR] = right_dir,
    }
    return setEffect(id, t)
end

---
---@param id string
---@param waveform audio.EffectWaveform
---@param rate number
---@param phonem_a audio.EffectPhoneme
---@param phonem_b audio.EffectPhoneme
---@param tune_a number
---@param tune_b number
---@return string return id if success, nil if failed
function M.Morpher(id, waveform, rate, phonem_a, phonem_b, tune_a, tune_b)
    local t = {
        [audio.EffectParameter.TYPE]             = audio.EffectType.MORPHER,
        [audio.EffectParameter.MORPHER_WAVEFORM] = waveform,
        [audio.EffectParameter.MORPHER_RATE]     = rate,
        [audio.EffectParameter.MORPHER_PHONEMEA] = phonem_a,
        [audio.EffectParameter.MORPHER_PHONEMEB] = phonem_b,
        [audio.EffectParameter.MORPHER_TUNEA]    = tune_a,
        [audio.EffectParameter.MORPHER_TUNEB]    = tune_b,
    }
    return setEffect(id, t)
end

---
---@param id string
---@param pitch number
---@return string return id if success, nil if failed
function M.PitchShifter(id, pitch)
    local t = {
        [audio.EffectParameter.TYPE]               = audio.EffectType.PITCHSHIFTER,
        [audio.EffectParameter.PITCHSHIFTER_PITCH] = pitch,
    }
    return setEffect(id, t)
end

--- modulator: An implementation of amplitude modulation multiplies the source signal with a simple waveform, to produce either volume changes, or inharmonic overtones.
---@param id string
---@param waveform audio.EffectWaveform
---@param frequency number
---@param highcut number
---@return string return id if success, nil if failed
function M.Modulator(id, waveform, frequency, highcut)
    local t = {
        [audio.EffectParameter.TYPE]               = audio.EffectType.MODULATOR,
        [audio.EffectParameter.MODULATOR_WAVEFORM] = waveform,
        [audio.EffectParameter.MODULATOR_FREQ]     = frequency,
        [audio.EffectParameter.MODULATOR_HIGHCUT]  = highcut,
    }
    return setEffect(id, t)
end

---
---@param id string
---@param attack number
---@param release number
---@param resonance number
---@param peakgain number
---@return string return id if success, nil if failed
function M.Autowah(id, attack, release, resonance, peakgain)
    local t = {
        [audio.EffectParameter.TYPE]              = audio.EffectType.AUTOWAH,
        [audio.EffectParameter.AUTOWAH_ATTACK]    = attack,
        [audio.EffectParameter.AUTOWAH_RELEASE]   = release,
        [audio.EffectParameter.AUTOWAH_RESONANCE] = resonance,
        [audio.EffectParameter.AUTOWAH_PEAKGAIN]  = peakgain,
    }
    return setEffect(id, t)
end

--- compressor: Decreases the dynamic range of the sound, making the loud and quiet parts closer in volume, producing a more uniform amplitude throughout time.
---@param id string
---@param enable boolean
---@return string return id if success, nil if failed
function M.Compressor(id, enable)
    enable = enable and 0 or 1
    local t = {
        [audio.EffectParameter.TYPE]              = audio.EffectType.COMPRESSOR,
        [audio.EffectParameter.COMPRESSOR_ENABLE] = enable,
    }
    return setEffect(id, t)
end

--- equalizer: Adjust the frequency components of the sound using a 4-band (low-shelf, two band-pass and a high-shelf) equalizer.
---@param id string
---@param lowgain number
---@param lowcut number
---@param lowmidgain number
---@param lowmidfrequency number
---@param lowmidbandwidth number
---@param highmidgain number
---@param highmidfrequency number
---@param highmidbandwidth number
---@param highgain number
---@param highcut number
---@return string return id if success, nil if failed
function M.Equalizer(id, lowgain, lowcut, lowmidgain, lowmidfrequency, lowmidbandwidth, highmidgain, highmidfrequency, highmidbandwidth, highgain, highcut)
    local t = {
        [audio.EffectParameter.TYPE]               = audio.EffectType.EQUALIZER,
        [audio.EffectParameter.EQUALIZER_LOWGAIN]  = lowgain,
        [audio.EffectParameter.EQUALIZER_LOWCUT]   = lowcut,
        [audio.EffectParameter.EQUALIZER_MID1GAIN] = lowmidgain,
        [audio.EffectParameter.EQUALIZER_MID1FREQ] = lowmidfrequency,
        [audio.EffectParameter.EQUALIZER_MID1BAND] = lowmidbandwidth,
        [audio.EffectParameter.EQUALIZER_MID2GAIN] = highmidgain,
        [audio.EffectParameter.EQUALIZER_MID2FREQ] = highmidfrequency,
        [audio.EffectParameter.EQUALIZER_MID2BAND] = highmidbandwidth,
        [audio.EffectParameter.EQUALIZER_HIGHGAIN] = highgain,
        [audio.EffectParameter.EQUALIZER_HIGHCUT]  = highcut,
    }
    return setEffect(id, t)
end

return M
