---@type audio
local a = audio

local SourceType = {}
a.SourceType = SourceType
SourceType.STATIC = 0     --- play from SoundData
SourceType.STREAM = 1     --- play from Decoder
SourceType.QUEUE = 2      --- play with queue

local DistanceModel = {}
a.DistanceModel = DistanceModel
DistanceModel.NONE = 0
DistanceModel.INVERSE = 1
DistanceModel.INVERSE_CLAMPED = 2
DistanceModel.LINEAR = 3
DistanceModel.LINEAR_CLAMPED = 4
DistanceModel.EXPONENT = 5
DistanceModel.EXPONENT_CLAMPED = 6

local DecoderType = {}
a.DecoderType = DecoderType
DecoderType.UNKNOWN = 0
DecoderType.WAV = 1
DecoderType.VORBIS = 2
DecoderType.FLAC = 3
DecoderType.MP3 = 4

local EffectType = {}
a.EffectType = EffectType
EffectType.BASIC = 0          --- not a real type
EffectType.REVERB = 1
EffectType.CHORUS = 2         --- implemented in openal-soft-1.16.0
EffectType.DISTORTION = 3     --- implemented in openal-soft-1.16.0
EffectType.ECHO = 4
EffectType.FLANGER = 5        --- implemented in openal-soft-1.16.0
EffectType.FREQSHIFTER = 6    --- implemented in openal-soft-1.19.0
EffectType.MORPHER = 7        --- not implemented yet
EffectType.PITCHSHIFTER = 8   --- implemented in openal-soft-1.19.0
EffectType.MODULATOR = 9
EffectType.AUTOWAH = 10       --- implemented in openal-soft-1.19.0
EffectType.COMPRESSOR = 11    --- implemented in openal-soft-1.16.0
EffectType.EQUALIZER = 12     --- implemented in openal-soft-1.16.0

local EffectParameter = {}
a.EffectParameter = EffectParameter
EffectParameter.TYPE = 0
EffectParameter.VOLUME = 1
EffectParameter.REVERB_GAIN = 2    --- [0.0, 1.0], 0.32
EffectParameter.REVERB_HFGAIN = 3    --- [0.0, 1.0], 0.89
EffectParameter.REVERB_DENSITY = 4    --- [0.0, 1.0], 1.0
EffectParameter.REVERB_DIFFUSION = 5        --- [0.0, 1.0], 1.0
EffectParameter.REVERB_DECAY = 6    --- [0.1, 20.0], 1.49
EffectParameter.REVERB_HFDECAY = 7    --- [0.1, 2.0], 0.83
EffectParameter.REVERB_EARLYGAIN = 8        --- [0.0, 3.16], 0.05
EffectParameter.REVERB_EARLYDELAY = 9        --- [0.0, 0.3], 0.007
EffectParameter.REVERB_LATEGAIN = 10    --- [0.0, 10.0], 1.26
EffectParameter.REVERB_LATEDELAY = 11        --- [0.0, 0.1], 0.011
EffectParameter.REVERB_ROLLOFF = 12    --- [0.0, 10.0], 0.0
EffectParameter.REVERB_AIRHFGAIN = 13        --- [0.892, 1.0], 0.994
EffectParameter.REVERB_HFLIMITER = 14        --- [AL_FALSE, AL_TRUE], AL_TRUE
EffectParameter.CHORUS_WAVEFORM = 15
EffectParameter.CHORUS_PHASE = 16    --- [-180, 180], 90
EffectParameter.CHORUS_RATE = 17    --- [0.0, 10.0], 1.1
EffectParameter.CHORUS_DEPTH = 18    --- [0.0, 1.0], 0.1
EffectParameter.CHORUS_FEEDBACK = 19    --- [-1.0, 1.0], 0.25
EffectParameter.CHORUS_DELAY = 20    --- [0.0, 0.016], 0.016
EffectParameter.DISTORTION_GAIN = 21    --- [0.01, 1.0], 0.05
EffectParameter.DISTORTION_EDGE = 22    --- [0.0, 1.0], 0.2
EffectParameter.DISTORTION_LOWCUT = 23        --- [80.0, 24000.0], 8000.0
EffectParameter.DISTORTION_EQCENTER = 24        --- [80.0, 24000.0], 3600.0
EffectParameter.DISTORTION_EQBAND = 25        --- [80.0, 24000.0], 3600.0
EffectParameter.ECHO_DELAY = 26    --- [0.0, 0.207], 0.1
EffectParameter.ECHO_LRDELAY = 27    --- [0.0, 0.404], 0.1
EffectParameter.ECHO_DAMPING = 28    --- [0.0, 0.99], 0.5
EffectParameter.ECHO_FEEDBACK = 29        --- [0.0, 1.0], 0.5
EffectParameter.ECHO_SPREAD = 30    --- [-1.0, 1.0], -1.0
EffectParameter.FLANGER_WAVEFORM = 31
EffectParameter.FLANGER_PHASE = 32    --- [-180, 180], 0
EffectParameter.FLANGER_RATE = 33    --- [0.0, 10.0], 0.27
EffectParameter.FLANGER_DEPTH = 34    --- [0.0, 1.0], 1.0
EffectParameter.FLANGER_FEEDBACK = 35        --- [-1.0, 1.0], -0.5
EffectParameter.FLANGER_DELAY = 36    --- [0.0, 0.004], 0.002
EffectParameter.FREQSHIFTER_FREQ = 37        --- [0.0, 24000.0], 0.0
EffectParameter.FREQSHIFTER_LEFTDIR = 38
EffectParameter.FREQSHIFTER_RIGHTDIR = 39
EffectParameter.MORPHER_WAVEFORM = 40
EffectParameter.MORPHER_RATE = 41        --- [0.0, 10.0], 1.41
EffectParameter.MORPHER_PHONEMEA = 42
EffectParameter.MORPHER_PHONEMEB = 43
EffectParameter.MORPHER_TUNEA = 44        --- [-24, 24], 0
EffectParameter.MORPHER_TUNEB = 45        --- [-24, 24], 0
EffectParameter.PITCHSHIFTER_PITCH = 46        --- [-12, 12], 12
EffectParameter.MODULATOR_WAVEFORM = 47
EffectParameter.MODULATOR_FREQ = 48        --- [0.0, 8000.0], 440.0
EffectParameter.MODULATOR_HIGHCUT = 49        --- [0.0, 24000.0], 800.0
EffectParameter.AUTOWAH_ATTACK = 50        --- [0.0001, 1.0], 0.06
EffectParameter.AUTOWAH_RELEASE = 51        --- [0.0001, 1.0], 0.06
EffectParameter.AUTOWAH_RESONANCE = 52        --- [2.0, 1000.0], 1000.0
EffectParameter.AUTOWAH_PEAKGAIN = 53        --- [0.00003, 31621.0], 11.22
EffectParameter.COMPRESSOR_ENABLE = 54        --- [AL_FALSE, AL_TRUE], AL_TRUE
EffectParameter.EQUALIZER_LOWGAIN = 55        --- [0.126, 7.943], 1.0
EffectParameter.EQUALIZER_LOWCUT = 56        --- [50.0, 800.0], 200.0
EffectParameter.EQUALIZER_MID1GAIN = 57        --- [0.126, 7.943], 1.0
EffectParameter.EQUALIZER_MID1FREQ = 58        --- [200.0, 3000.0], 500.0
EffectParameter.EQUALIZER_MID1BAND = 59        --- [0.01, 1.0], 1.0
EffectParameter.EQUALIZER_MID2GAIN = 60        --- [0.126, 7.943], 1.0
EffectParameter.EQUALIZER_MID2FREQ = 61        --- [1000.0, 8000.0], 3000.0
EffectParameter.EQUALIZER_MID2BAND = 62        --- [0.01, 1.0], 1.0
EffectParameter.EQUALIZER_HIGHGAIN = 63        --- [0.126, 7.943], 1.0
EffectParameter.EQUALIZER_HIGHCUT = 64        --- [4000.0, 16000.0], 6000.0

local EffectWaveform = {}
--- TYPE_CHORUS: CHORUS_WAVEFORM
--- TYPE_FLANGER: FLANGER_WAVEFORM
--- TYPE_MORPHER: MORPHER_WAVEFORM
a.EffectWaveform = EffectWaveform
EffectWaveform.SINE = 0
EffectWaveform.TRIANGLE = 1
EffectWaveform.SAWTOOTH = 2
EffectWaveform.SQUARE = 3

local EffectDirection = {}
--- TYPE_FREQSHIFTER: FREQSHIFTER_LEFTDIR, FREQSHIFTER_RIGHTDIR
a.EffectDirection = EffectDirection
EffectDirection.NONE = 0
EffectDirection.UP = 1
EffectDirection.DOWN = 2

local EffectPhoneme = {}
--- TYPE_MORPHER: MORPHER_PHONEMEA, MORPHER_PHONEMEB
a.EffectPhoneme = EffectPhoneme
EffectPhoneme.A = 0
EffectPhoneme.E = 1
EffectPhoneme.I = 2
EffectPhoneme.O = 3
EffectPhoneme.U = 4
EffectPhoneme.AA = 5
EffectPhoneme.AE = 6
EffectPhoneme.AH = 7
EffectPhoneme.AO = 8
EffectPhoneme.EH = 9
EffectPhoneme.ER = 10
EffectPhoneme.IH = 11
EffectPhoneme.IY = 12
EffectPhoneme.UH = 13
EffectPhoneme.UW = 14
EffectPhoneme.B = 15
EffectPhoneme.D = 16
EffectPhoneme.F = 17
EffectPhoneme.G = 18
EffectPhoneme.J = 19
EffectPhoneme.K = 20
EffectPhoneme.L = 21
EffectPhoneme.M = 22
EffectPhoneme.N = 23
EffectPhoneme.P = 24
EffectPhoneme.R = 25
EffectPhoneme.S = 26
EffectPhoneme.T = 27
EffectPhoneme.V = 28
EffectPhoneme.Z = 29

local FilterType = {}
a.FilterType = FilterType
FilterType.BASIC = 0
FilterType.LOWPASS = 1
FilterType.HIGHPASS = 2
FilterType.BANDPASS = 3

local FilterParameter = {}
a.FilterParameter = FilterParameter
FilterParameter.TYPE = 0
FilterParameter.VOLUME = 1
FilterParameter.LOWGAIN = 2  --- HIGHPASS, BANDPASS
FilterParameter.HIGHGAIN = 3 --- LOWPASS, BANDPASS

local StreamSeekOrigin = {}
a.StreamSeekOrigin = StreamSeekOrigin
StreamSeekOrigin.BEGINNING = 0    --- Seek from the beginning.
StreamSeekOrigin.CURRENT = 1    --- Seek from current position.
StreamSeekOrigin.END = 2    --- Seek from the end.

---@class audio.EffectWaveform:number
local EffectWaveform

---@class audio.EffectDirection:number
local EffectDirection

---@class audio.EffectPhoneme:number
local EffectPhoneme
