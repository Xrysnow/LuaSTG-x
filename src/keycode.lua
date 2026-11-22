local KEY      = { NULL = 0x00 }

--KEY.LBUTTON
--KEY.RBUTTON
--KEY.MBUTTON

KEY.ESCAPE     = 6
KEY.BACKSPACE  = 7
KEY.TAB        = 8
KEY.ENTER      = 164
KEY.SPACE      = 59

KEY.SHIFT      = 12--,13
KEY.CTRL       = 14--,15
KEY.ALT        = 16--,17

KEY.LWIN       = 19
KEY.RWIN       = 19
--KEY.APPS

KEY.PAUSE      = 1
KEY.CAPSLOCK   = 11
KEY.NUMLOCK    = 30
KEY.SCROLLLOCK = 2

KEY.PGUP       = 22
KEY.PGDN       = 25
KEY.HOME       = 21
KEY.END        = 24
KEY.INSERT     = 20
KEY.DELETE     = 23

KEY.LEFT       = 26
KEY.RIGHT      = 27
KEY.UP         = 28
KEY.DOWN       = 29

KEY['0']       = 76
KEY['1']       = 77
KEY['2']       = 78
KEY['3']       = 79
KEY['4']       = 80
KEY['5']       = 81
KEY['6']       = 82
KEY['7']       = 83
KEY['8']       = 84
KEY['9']       = 85

KEY.A          = 124
KEY.B          = 125
KEY.C          = 126
KEY.D          = 127
KEY.E          = 128
KEY.F          = 129
KEY.G          = 130
KEY.H          = 131
KEY.I          = 132
KEY.J          = 133
KEY.K          = 134
KEY.L          = 135
KEY.M          = 136
KEY.N          = 137
KEY.O          = 138
KEY.P          = 139
KEY.Q          = 140
KEY.R          = 141
KEY.S          = 142
KEY.T          = 143
KEY.U          = 144
KEY.V          = 145
KEY.W          = 146
KEY.X          = 147
KEY.Y          = 148
KEY.Z          = 149

KEY.GRAVE      = 123
KEY.MINUS      = 73
KEY.EQUAL      = 89
KEY.BACKSLASH  = 120
KEY.LBRACKET   = 119
KEY.RBRACKET   = 121
KEY.SEMICOLON  = 87
KEY.APOSTROPHE = 67
KEY.COMMA      = 72
KEY.PERIOD     = 74
KEY.SLASH      = 75

--[[
KEY.NUMPAD0
KEY.NUMPAD1
KEY.NUMPAD2
KEY.NUMPAD3
KEY.NUMPAD4
KEY.NUMPAD5
KEY.NUMPAD6
KEY.NUMPAD7
KEY.NUMPAD8
KEY.NUMPAD9
]]

KEY.MULTIPLY   = 33
KEY.DIVIDE     = 34
KEY.ADD        = 31
KEY.SUBTRACT   = 32
KEY.DECIMAL    = 74

KEY.F1         = 47
KEY.F2         = 48
KEY.F3         = 49
KEY.F4         = 50
KEY.F5         = 51
KEY.F6         = 52
KEY.F7         = 53
KEY.F8         = 54
KEY.F9         = 55
KEY.F10        = 56
KEY.F11        = 57
KEY.F12        = 58

--for i = 1, 32 do
--    KEY['JOY1_' .. i] = 0x100 + i
--    KEY['JOY2_' .. i] = 0x200 + i
--end

return KEY
