--
local M = {}

---@brief One.
---
--- This is only semantic sugar for the number 1.  You can instead use `1` or
--- `true` or `_True` or `GL_TRUE` or `VK_TRUE` or anything else that is equal
--- to one.
---
---@ingroup init
---
M.GLFW_TRUE = 1

---@brief Zero.
---
--- This is only semantic sugar for the number 0.  You can instead use `0` or
--- `false` or `_False` or `GL_FALSE` or `VK_FALSE` or anything else that is
--- equal to zero.
---
---@ingroup init
---
M.GLFW_FALSE = 0


---@name Key and button actions
---@{

---@brief The key or mouse button was released.
---
--- The key or mouse button was released.
---
---@ingroup input
---
M.GLFW_RELEASE = 0

---@brief The key or mouse button was pressed.
---
--- The key or mouse button was pressed.
---
---@ingroup input
---
M.GLFW_PRESS = 1

---@brief The key was held down until it repeated.
---
--- The key was held down until it repeated.
---
---@ingroup input
---
M.GLFW_REPEAT = 2

---@defgroup hat_state Joystick hat states
---@brief Joystick hat states.
---
--- See [joystick hat input](@ref joystick_hat) for how these are used.
---
---@ingroup input
---@{
M.GLFW_HAT_CENTERED = 0
M.GLFW_HAT_UP = 1
M.GLFW_HAT_RIGHT = 2
M.GLFW_HAT_DOWN = 4
M.GLFW_HAT_LEFT = 8
M.GLFW_HAT_RIGHT_UP = (M.GLFW_HAT_RIGHT + M.GLFW_HAT_UP)
M.GLFW_HAT_RIGHT_DOWN = (M.GLFW_HAT_RIGHT + M.GLFW_HAT_DOWN)
M.GLFW_HAT_LEFT_UP = (M.GLFW_HAT_LEFT + M.GLFW_HAT_UP)
M.GLFW_HAT_LEFT_DOWN = (M.GLFW_HAT_LEFT + M.GLFW_HAT_DOWN)




---@defgroup keys Keyboard keys
---@brief Keyboard key IDs.
---
--- See [key input](@ref input_key) for how these are used.
---
--- These key codes are inspired by the _USB HID Usage Tables v1.12_ (p. 53-60),
--- but re-arranged to map to 7-bit ASCII for printable keys (function keys are
--- put in the 256+ range).
---
--- The naming of the key codes follow these rules:
---  - The US keyboard layout is used
---  - Names of printable alpha-numeric characters are used (e.g. "A", "R",
---    "3", etc.)
---  - For non-alphanumeric characters, Unicode:ish names are used (e.g.
---    "COMMA", "LEFT_SQUARE_BRACKET", etc.). Note that some names do not
---    correspond to the Unicode standard (usually for brevity)
---  - Keys that lack a clear US mapping are named "WORLD_x"
---  - For non-printable keys, custom names are used (e.g. "F4",
---    "BACKSPACE", etc.)
---
---@ingroup input
---

--- The unknown key
M.GLFW_KEY_UNKNOWN = -1

--- Printable keys

M.GLFW_KEY_SPACE = 32
M.GLFW_KEY_APOSTROPHE = 39  --- '
M.GLFW_KEY_COMMA = 44  --- ,
M.GLFW_KEY_MINUS = 45  --- -
M.GLFW_KEY_PERIOD = 46  --- .
M.GLFW_KEY_SLASH = 47  --- /
M.GLFW_KEY_0 = 48
M.GLFW_KEY_1 = 49
M.GLFW_KEY_2 = 50
M.GLFW_KEY_3 = 51
M.GLFW_KEY_4 = 52
M.GLFW_KEY_5 = 53
M.GLFW_KEY_6 = 54
M.GLFW_KEY_7 = 55
M.GLFW_KEY_8 = 56
M.GLFW_KEY_9 = 57
M.GLFW_KEY_SEMICOLON = 59  --- ;
M.GLFW_KEY_EQUAL = 61  --- =
M.GLFW_KEY_A = 65
M.GLFW_KEY_B = 66
M.GLFW_KEY_C = 67
M.GLFW_KEY_D = 68
M.GLFW_KEY_E = 69
M.GLFW_KEY_F = 70
M.GLFW_KEY_G = 71
M.GLFW_KEY_H = 72
M.GLFW_KEY_I = 73
M.GLFW_KEY_J = 74
M.GLFW_KEY_K = 75
M.GLFW_KEY_L = 76
M.GLFW_KEY_M = 77
M.GLFW_KEY_N = 78
M.GLFW_KEY_O = 79
M.GLFW_KEY_P = 80
M.GLFW_KEY_Q = 81
M.GLFW_KEY_R = 82
M.GLFW_KEY_S = 83
M.GLFW_KEY_T = 84
M.GLFW_KEY_U = 85
M.GLFW_KEY_V = 86
M.GLFW_KEY_W = 87
M.GLFW_KEY_X = 88
M.GLFW_KEY_Y = 89
M.GLFW_KEY_Z = 90
M.GLFW_KEY_LEFT_BRACKET = 91  --- [
M.GLFW_KEY_BACKSLASH = 92  --- \
M.GLFW_KEY_RIGHT_BRACKET = 93  --- ]
M.GLFW_KEY_GRAVE_ACCENT = 96  --- `
M.GLFW_KEY_WORLD_1 = 161 --- non-US #1
M.GLFW_KEY_WORLD_2 = 162 --- non-US #2

--- Function keys

M.GLFW_KEY_ESCAPE = 256
M.GLFW_KEY_ENTER = 257
M.GLFW_KEY_TAB = 258
M.GLFW_KEY_BACKSPACE = 259
M.GLFW_KEY_INSERT = 260
M.GLFW_KEY_DELETE = 261
M.GLFW_KEY_RIGHT = 262
M.GLFW_KEY_LEFT = 263
M.GLFW_KEY_DOWN = 264
M.GLFW_KEY_UP = 265
M.GLFW_KEY_PAGE_UP = 266
M.GLFW_KEY_PAGE_DOWN = 267
M.GLFW_KEY_HOME = 268
M.GLFW_KEY_END = 269
M.GLFW_KEY_CAPS_LOCK = 280
M.GLFW_KEY_SCROLL_LOCK = 281
M.GLFW_KEY_NUM_LOCK = 282
M.GLFW_KEY_PRINT_SCREEN = 283
M.GLFW_KEY_PAUSE = 284
M.GLFW_KEY_F1 = 290
M.GLFW_KEY_F2 = 291
M.GLFW_KEY_F3 = 292
M.GLFW_KEY_F4 = 293
M.GLFW_KEY_F5 = 294
M.GLFW_KEY_F6 = 295
M.GLFW_KEY_F7 = 296
M.GLFW_KEY_F8 = 297
M.GLFW_KEY_F9 = 298
M.GLFW_KEY_F10 = 299
M.GLFW_KEY_F11 = 300
M.GLFW_KEY_F12 = 301
M.GLFW_KEY_F13 = 302
M.GLFW_KEY_F14 = 303
M.GLFW_KEY_F15 = 304
M.GLFW_KEY_F16 = 305
M.GLFW_KEY_F17 = 306
M.GLFW_KEY_F18 = 307
M.GLFW_KEY_F19 = 308
M.GLFW_KEY_F20 = 309
M.GLFW_KEY_F21 = 310
M.GLFW_KEY_F22 = 311
M.GLFW_KEY_F23 = 312
M.GLFW_KEY_F24 = 313
M.GLFW_KEY_F25 = 314
M.GLFW_KEY_KP_0 = 320
M.GLFW_KEY_KP_1 = 321
M.GLFW_KEY_KP_2 = 322
M.GLFW_KEY_KP_3 = 323
M.GLFW_KEY_KP_4 = 324
M.GLFW_KEY_KP_5 = 325
M.GLFW_KEY_KP_6 = 326
M.GLFW_KEY_KP_7 = 327
M.GLFW_KEY_KP_8 = 328
M.GLFW_KEY_KP_9 = 329
M.GLFW_KEY_KP_DECIMAL = 330
M.GLFW_KEY_KP_DIVIDE = 331
M.GLFW_KEY_KP_MULTIPLY = 332
M.GLFW_KEY_KP_SUBTRACT = 333
M.GLFW_KEY_KP_ADD = 334
M.GLFW_KEY_KP_ENTER = 335
M.GLFW_KEY_KP_EQUAL = 336
M.GLFW_KEY_LEFT_SHIFT = 340
M.GLFW_KEY_LEFT_CONTROL = 341
M.GLFW_KEY_LEFT_ALT = 342
M.GLFW_KEY_LEFT_SUPER = 343
M.GLFW_KEY_RIGHT_SHIFT = 344
M.GLFW_KEY_RIGHT_CONTROL = 345
M.GLFW_KEY_RIGHT_ALT = 346
M.GLFW_KEY_RIGHT_SUPER = 347
M.GLFW_KEY_MENU = 348

M.GLFW_KEY_LAST = M.GLFW_KEY_MENU



---@defgroup mods Modifier key flags
---@brief Modifier key flags.
---
--- See [key input](@ref input_key) for how these are used.
---
---@ingroup input
---@{


---@brief If this bit is set one or more Shift keys were held down.
---
--- If this bit is set one or more Shift keys were held down.
---
M.GLFW_MOD_SHIFT = 0x0001

---@brief If this bit is set one or more Control keys were held down.
---
--- If this bit is set one or more Control keys were held down.
---
M.GLFW_MOD_CONTROL = 0x0002

---@brief If this bit is set one or more Alt keys were held down.
---
--- If this bit is set one or more Alt keys were held down.
---
M.GLFW_MOD_ALT = 0x0004

---@brief If this bit is set one or more Super keys were held down.
---
--- If this bit is set one or more Super keys were held down.
---
M.GLFW_MOD_SUPER = 0x0008

---@brief If this bit is set the Caps Lock key is enabled.
---
--- If this bit is set the Caps Lock key is enabled and the @ref
--- GLFW_LOCK_KEY_MODS input mode is set.
---
M.GLFW_MOD_CAPS_LOCK = 0x0010

---@brief If this bit is set the Num Lock key is enabled.
---
--- If this bit is set the Num Lock key is enabled and the @ref
--- GLFW_LOCK_KEY_MODS input mode is set.
---
M.GLFW_MOD_NUM_LOCK = 0x0020

---@defgroup buttons Mouse buttons
---@brief Mouse button IDs.
---
--- See [mouse button input](@ref input_mouse_button) for how these are used.
---
---@ingroup input
---@{
M.GLFW_MOUSE_BUTTON_1 = 0
M.GLFW_MOUSE_BUTTON_2 = 1
M.GLFW_MOUSE_BUTTON_3 = 2
M.GLFW_MOUSE_BUTTON_4 = 3
M.GLFW_MOUSE_BUTTON_5 = 4
M.GLFW_MOUSE_BUTTON_6 = 5
M.GLFW_MOUSE_BUTTON_7 = 6
M.GLFW_MOUSE_BUTTON_8 = 7
M.GLFW_MOUSE_BUTTON_LAST = M.GLFW_MOUSE_BUTTON_8
M.GLFW_MOUSE_BUTTON_LEFT = M.GLFW_MOUSE_BUTTON_1
M.GLFW_MOUSE_BUTTON_RIGHT = M.GLFW_MOUSE_BUTTON_2
M.GLFW_MOUSE_BUTTON_MIDDLE = M.GLFW_MOUSE_BUTTON_3

---@defgroup joysticks Joysticks
---@brief Joystick IDs.
---
--- See [joystick input](@ref joystick) for how these are used.
---
---@ingroup input
---@{
M.GLFW_JOYSTICK_1 = 0
M.GLFW_JOYSTICK_2 = 1
M.GLFW_JOYSTICK_3 = 2
M.GLFW_JOYSTICK_4 = 3
M.GLFW_JOYSTICK_5 = 4
M.GLFW_JOYSTICK_6 = 5
M.GLFW_JOYSTICK_7 = 6
M.GLFW_JOYSTICK_8 = 7
M.GLFW_JOYSTICK_9 = 8
M.GLFW_JOYSTICK_10 = 9
M.GLFW_JOYSTICK_11 = 10
M.GLFW_JOYSTICK_12 = 11
M.GLFW_JOYSTICK_13 = 12
M.GLFW_JOYSTICK_14 = 13
M.GLFW_JOYSTICK_15 = 14
M.GLFW_JOYSTICK_16 = 15
M.GLFW_JOYSTICK_LAST = M.GLFW_JOYSTICK_16

---@defgroup gamepad_buttons Gamepad buttons
---@brief Gamepad buttons.
---
--- See @ref gamepad for how these are used.
---
---@ingroup input
---@{
M.GLFW_GAMEPAD_BUTTON_A = 0
M.GLFW_GAMEPAD_BUTTON_B = 1
M.GLFW_GAMEPAD_BUTTON_X = 2
M.GLFW_GAMEPAD_BUTTON_Y = 3
M.GLFW_GAMEPAD_BUTTON_LEFT_BUMPER = 4
M.GLFW_GAMEPAD_BUTTON_RIGHT_BUMPER = 5
M.GLFW_GAMEPAD_BUTTON_BACK = 6
M.GLFW_GAMEPAD_BUTTON_START = 7
M.GLFW_GAMEPAD_BUTTON_GUIDE = 8
M.GLFW_GAMEPAD_BUTTON_LEFT_THUMB = 9
M.GLFW_GAMEPAD_BUTTON_RIGHT_THUMB = 10
M.GLFW_GAMEPAD_BUTTON_DPAD_UP = 11
M.GLFW_GAMEPAD_BUTTON_DPAD_RIGHT = 12
M.GLFW_GAMEPAD_BUTTON_DPAD_DOWN = 13
M.GLFW_GAMEPAD_BUTTON_DPAD_LEFT = 14
M.GLFW_GAMEPAD_BUTTON_LAST = M.GLFW_GAMEPAD_BUTTON_DPAD_LEFT

M.GLFW_GAMEPAD_BUTTON_CROSS = M.GLFW_GAMEPAD_BUTTON_A
M.GLFW_GAMEPAD_BUTTON_CIRCLE = M.GLFW_GAMEPAD_BUTTON_B
M.GLFW_GAMEPAD_BUTTON_SQUARE = M.GLFW_GAMEPAD_BUTTON_X
M.GLFW_GAMEPAD_BUTTON_TRIANGLE = M.GLFW_GAMEPAD_BUTTON_Y

---@defgroup gamepad_axes Gamepad axes
---@brief Gamepad axes.
---
--- See @ref gamepad for how these are used.
---
---@ingroup input
---@{
M.GLFW_GAMEPAD_AXIS_LEFT_X = 0
M.GLFW_GAMEPAD_AXIS_LEFT_Y = 1
M.GLFW_GAMEPAD_AXIS_RIGHT_X = 2
M.GLFW_GAMEPAD_AXIS_RIGHT_Y = 3
M.GLFW_GAMEPAD_AXIS_LEFT_TRIGGER = 4
M.GLFW_GAMEPAD_AXIS_RIGHT_TRIGGER = 5
M.GLFW_GAMEPAD_AXIS_LAST = M.GLFW_GAMEPAD_AXIS_RIGHT_TRIGGER




---@defgroup errors Error codes
---@brief Error codes.
---
--- See [error handling](@ref error_handling) for how these are used.
---
---@ingroup init
---@{

---@brief No error has occurred.
---
--- No error has occurred.
---
---@analysis Yay.
---
M.GLFW_NO_ERROR = 0

---@brief GLFW has not been initialized.
---
--- This occurs if a GLFW function was called that must not be called unless the
--- library is [initialized](@ref intro_init).
---
---@analysis Application programmer error.  Initialize GLFW before calling any
--- function that requires initialization.
---
M.GLFW_NOT_INITIALIZED = 0x00010001

---@brief No context is current for this thread.
---
--- This occurs if a GLFW function was called that needs and operates on the
--- current OpenGL or OpenGL ES context but no context is current on the calling
--- thread.  One such function is @ref glfwSwapInterval.
---
---@analysis Application programmer error.  Ensure a context is current before
--- calling functions that require a current context.
---
M.GLFW_NO_CURRENT_CONTEXT = 0x00010002

---@brief One of the arguments to the function was an invalid enum value.
---
--- One of the arguments to the function was an invalid enum value, for example
--- requesting @ref GLFW_RED_BITS with @ref glfwGetWindowAttrib.
---
---@analysis Application programmer error.  Fix the offending call.
---
M.GLFW_INVALID_ENUM = 0x00010003

---@brief One of the arguments to the function was an invalid value.
---
--- One of the arguments to the function was an invalid value, for example
--- requesting a non-existent OpenGL or OpenGL ES version like 2.7.
---
--- Requesting a valid but unavailable OpenGL or OpenGL ES version will instead
--- result in a @ref GLFW_VERSION_UNAVAILABLE error.
---
---@analysis Application programmer error.  Fix the offending call.
---
M.GLFW_INVALID_VALUE = 0x00010004

---@brief A memory allocation failed.
---
--- A memory allocation failed.
---
---@analysis A bug in GLFW or the underlying operating system.  Report the bug
--- to our [issue tracker](https://github.com/glfw/glfw/issues).
---
M.GLFW_OUT_OF_MEMORY = 0x00010005

---@brief GLFW could not find support for the requested API on the system.
---
--- GLFW could not find support for the requested API on the system.
---
---@analysis The installed graphics driver does not support the requested
--- API, or does not support it via the chosen context creation backend.
--- Below are a few examples.
---
---@par
--- Some pre-installed Windows graphics drivers do not support OpenGL.  AMD only
--- supports OpenGL ES via EGL, while Nvidia and Intel only support it via
--- a WGL or GLX extension.  macOS does not provide OpenGL ES at all.  The Mesa
--- EGL, OpenGL and OpenGL ES libraries do not interface with the Nvidia binary
--- driver.  Older graphics drivers do not support Vulkan.
---
M.GLFW_API_UNAVAILABLE = 0x00010006

---@brief The requested OpenGL or OpenGL ES version is not available.
---
--- The requested OpenGL or OpenGL ES version (including any requested context
--- or framebuffer hints) is not available on this machine.
---
---@analysis The machine does not support your requirements.  If your
--- application is sufficiently flexible, downgrade your requirements and try
--- again.  Otherwise, inform the user that their machine does not match your
--- requirements.
---
---@par
--- Future invalid OpenGL and OpenGL ES versions, for example OpenGL 4.8 if 5.0
--- comes out before the 4.x series gets that far, also fail with this error and
--- not @ref GLFW_INVALID_VALUE, because GLFW cannot know what future versions
--- will exist.
---
M.GLFW_VERSION_UNAVAILABLE = 0x00010007

---@brief A platform-specific error occurred that does not match any of the
--- more specific categories.
---
--- A platform-specific error occurred that does not match any of the more
--- specific categories.
---
---@analysis A bug or configuration error in GLFW, the underlying operating
--- system or its drivers, or a lack of required resources.  Report the issue to
--- our [issue tracker](https://github.com/glfw/glfw/issues).
---
M.GLFW_PLATFORM_ERROR = 0x00010008

---@brief The requested format is not supported or available.
---
--- If emitted during window creation, the requested pixel format is not
--- supported.
---
--- If emitted when querying the clipboard, the contents of the clipboard could
--- not be converted to the requested format.
---
---@analysis If emitted during window creation, one or more
--- [hard constraints](@ref window_hints_hard) did not match any of the
--- available pixel formats.  If your application is sufficiently flexible,
--- downgrade your requirements and try again.  Otherwise, inform the user that
--- their machine does not match your requirements.
---
---@par
--- If emitted when querying the clipboard, ignore the error or report it to
--- the user, as appropriate.
---
M.GLFW_FORMAT_UNAVAILABLE = 0x00010009

---@brief The specified window does not have an OpenGL or OpenGL ES context.
---
--- A window that does not have an OpenGL or OpenGL ES context was passed to
--- a function that requires it to have one.
---
---@analysis Application programmer error.  Fix the offending call.
---
M.GLFW_NO_WINDOW_CONTEXT = 0x0001000A




---@addtogroup window
---@{

---@brief Input focus window hint and attribute
---
--- Input focus [window hint](@ref GLFW_FOCUSED_hint) or
--- [window attribute](@ref GLFW_FOCUSED_attrib).
---
M.GLFW_FOCUSED = 0x00020001

---@brief Window iconification window attribute
---
--- Window iconification [window attribute](@ref GLFW_ICONIFIED_attrib).
---
M.GLFW_ICONIFIED = 0x00020002

---@brief Window resize-ability window hint and attribute
---
--- Window resize-ability [window hint](@ref GLFW_RESIZABLE_hint) and
--- [window attribute](@ref GLFW_RESIZABLE_attrib).
---
M.GLFW_RESIZABLE = 0x00020003

---@brief Window visibility window hint and attribute
---
--- Window visibility [window hint](@ref GLFW_VISIBLE_hint) and
--- [window attribute](@ref GLFW_VISIBLE_attrib).
---
M.GLFW_VISIBLE = 0x00020004

---@brief Window decoration window hint and attribute
---
--- Window decoration [window hint](@ref GLFW_DECORATED_hint) and
--- [window attribute](@ref GLFW_DECORATED_attrib).
---
M.GLFW_DECORATED = 0x00020005

---@brief Window auto-iconification window hint and attribute
---
--- Window auto-iconification [window hint](@ref GLFW_AUTO_ICONIFY_hint) and
--- [window attribute](@ref GLFW_AUTO_ICONIFY_attrib).
---
M.GLFW_AUTO_ICONIFY = 0x00020006

---@brief Window decoration window hint and attribute
---
--- Window decoration [window hint](@ref GLFW_FLOATING_hint) and
--- [window attribute](@ref GLFW_FLOATING_attrib).
---
M.GLFW_FLOATING = 0x00020007

---@brief Window maximization window hint and attribute
---
--- Window maximization [window hint](@ref GLFW_MAXIMIZED_hint) and
--- [window attribute](@ref GLFW_MAXIMIZED_attrib).
---
M.GLFW_MAXIMIZED = 0x00020008

---@brief Cursor centering window hint
---
--- Cursor centering [window hint](@ref GLFW_CENTER_CURSOR_hint).
---
M.GLFW_CENTER_CURSOR = 0x00020009

---@brief Window framebuffer transparency hint and attribute
---
--- Window framebuffer transparency
--- [window hint](@ref GLFW_TRANSPARENT_FRAMEBUFFER_hint) and
--- [window attribute](@ref GLFW_TRANSPARENT_FRAMEBUFFER_attrib).
---
M.GLFW_TRANSPARENT_FRAMEBUFFER = 0x0002000A

---@brief Mouse cursor hover window attribute.
---
--- Mouse cursor hover [window attribute](@ref GLFW_HOVERED_attrib).
---
M.GLFW_HOVERED = 0x0002000B

---@brief Input focus on calling show window hint and attribute
---
--- Input focus [window hint](@ref GLFW_FOCUS_ON_SHOW_hint) or
--- [window attribute](@ref GLFW_FOCUS_ON_SHOW_attrib).
---
M.GLFW_FOCUS_ON_SHOW = 0x0002000C

---@brief Framebuffer bit depth hint.
---
--- Framebuffer bit depth [hint](@ref GLFW_RED_BITS).
---
M.GLFW_RED_BITS = 0x00021001

---@brief Framebuffer bit depth hint.
---
--- Framebuffer bit depth [hint](@ref GLFW_GREEN_BITS).
---
M.GLFW_GREEN_BITS = 0x00021002

---@brief Framebuffer bit depth hint.
---
--- Framebuffer bit depth [hint](@ref GLFW_BLUE_BITS).
---
M.GLFW_BLUE_BITS = 0x00021003

---@brief Framebuffer bit depth hint.
---
--- Framebuffer bit depth [hint](@ref GLFW_ALPHA_BITS).
---
M.GLFW_ALPHA_BITS = 0x00021004

---@brief Framebuffer bit depth hint.
---
--- Framebuffer bit depth [hint](@ref GLFW_DEPTH_BITS).
---
M.GLFW_DEPTH_BITS = 0x00021005

---@brief Framebuffer bit depth hint.
---
--- Framebuffer bit depth [hint](@ref GLFW_STENCIL_BITS).
---
M.GLFW_STENCIL_BITS = 0x00021006

---@brief Framebuffer bit depth hint.
---
--- Framebuffer bit depth [hint](@ref GLFW_ACCUM_RED_BITS).
---
M.GLFW_ACCUM_RED_BITS = 0x00021007

---@brief Framebuffer bit depth hint.
---
--- Framebuffer bit depth [hint](@ref GLFW_ACCUM_GREEN_BITS).
---
M.GLFW_ACCUM_GREEN_BITS = 0x00021008

---@brief Framebuffer bit depth hint.
---
--- Framebuffer bit depth [hint](@ref GLFW_ACCUM_BLUE_BITS).
---
M.GLFW_ACCUM_BLUE_BITS = 0x00021009

---@brief Framebuffer bit depth hint.
---
--- Framebuffer bit depth [hint](@ref GLFW_ACCUM_ALPHA_BITS).
---
M.GLFW_ACCUM_ALPHA_BITS = 0x0002100A

---@brief Framebuffer auxiliary buffer hint.
---
--- Framebuffer auxiliary buffer [hint](@ref GLFW_AUX_BUFFERS).
---
M.GLFW_AUX_BUFFERS = 0x0002100B

---@brief OpenGL stereoscopic rendering hint.
---
--- OpenGL stereoscopic rendering [hint](@ref GLFW_STEREO).
---
M.GLFW_STEREO = 0x0002100C

---@brief Framebuffer MSAA samples hint.
---
--- Framebuffer MSAA samples [hint](@ref GLFW_SAMPLES).
---
M.GLFW_SAMPLES = 0x0002100D

---@brief Framebuffer sRGB hint.
---
--- Framebuffer sRGB [hint](@ref GLFW_SRGB_CAPABLE).
---
M.GLFW_SRGB_CAPABLE = 0x0002100E

---@brief Monitor refresh rate hint.
---
--- Monitor refresh rate [hint](@ref GLFW_REFRESH_RATE).
---
M.GLFW_REFRESH_RATE = 0x0002100F

---@brief Framebuffer double buffering hint.
---
--- Framebuffer double buffering [hint](@ref GLFW_DOUBLEBUFFER).
---
M.GLFW_DOUBLEBUFFER = 0x00021010

---@brief Context client API hint and attribute.
---
--- Context client API [hint](@ref GLFW_CLIENT_API_hint) and
--- [attribute](@ref GLFW_CLIENT_API_attrib).
---
M.GLFW_CLIENT_API = 0x00022001

---@brief Context client API major version hint and attribute.
---
--- Context client API major version [hint](@ref GLFW_CLIENT_API_hint) and
--- [attribute](@ref GLFW_CLIENT_API_attrib).
---
M.GLFW_CONTEXT_VERSION_MAJOR = 0x00022002

---@brief Context client API minor version hint and attribute.
---
--- Context client API minor version [hint](@ref GLFW_CLIENT_API_hint) and
--- [attribute](@ref GLFW_CLIENT_API_attrib).
---
M.GLFW_CONTEXT_VERSION_MINOR = 0x00022003

---@brief Context client API revision number hint and attribute.
---
--- Context client API revision number [hint](@ref GLFW_CLIENT_API_hint) and
--- [attribute](@ref GLFW_CLIENT_API_attrib).
---
M.GLFW_CONTEXT_REVISION = 0x00022004

---@brief Context robustness hint and attribute.
---
--- Context client API revision number [hint](@ref GLFW_CLIENT_API_hint) and
--- [attribute](@ref GLFW_CLIENT_API_attrib).
---
M.GLFW_CONTEXT_ROBUSTNESS = 0x00022005

---@brief OpenGL forward-compatibility hint and attribute.
---
--- OpenGL forward-compatibility [hint](@ref GLFW_CLIENT_API_hint) and
--- [attribute](@ref GLFW_CLIENT_API_attrib).
---
M.GLFW_OPENGL_FORWARD_COMPAT = 0x00022006

---@brief OpenGL debug context hint and attribute.
---
--- OpenGL debug context [hint](@ref GLFW_CLIENT_API_hint) and
--- [attribute](@ref GLFW_CLIENT_API_attrib).
---
M.GLFW_OPENGL_DEBUG_CONTEXT = 0x00022007

---@brief OpenGL profile hint and attribute.
---
--- OpenGL profile [hint](@ref GLFW_CLIENT_API_hint) and
--- [attribute](@ref GLFW_CLIENT_API_attrib).
---
M.GLFW_OPENGL_PROFILE = 0x00022008

---@brief Context flush-on-release hint and attribute.
---
--- Context flush-on-release [hint](@ref GLFW_CLIENT_API_hint) and
--- [attribute](@ref GLFW_CLIENT_API_attrib).
---
M.GLFW_CONTEXT_RELEASE_BEHAVIOR = 0x00022009

---@brief Context error suppression hint and attribute.
---
--- Context error suppression [hint](@ref GLFW_CLIENT_API_hint) and
--- [attribute](@ref GLFW_CLIENT_API_attrib).
---
M.GLFW_CONTEXT_NO_ERROR = 0x0002200A

---@brief Context creation API hint and attribute.
---
--- Context creation API [hint](@ref GLFW_CLIENT_API_hint) and
--- [attribute](@ref GLFW_CLIENT_API_attrib).
---
M.GLFW_CONTEXT_CREATION_API = 0x0002200B

---@brief Window content area scaling window
--- [window hint](@ref GLFW_SCALE_TO_MONITOR).
---
M.GLFW_SCALE_TO_MONITOR = 0x0002200C

---@brief macOS specific
--- [window hint](@ref GLFW_COCOA_RETINA_FRAMEBUFFER_hint).
---
M.GLFW_COCOA_RETINA_FRAMEBUFFER = 0x00023001

---@brief macOS specific
--- [window hint](@ref GLFW_COCOA_FRAME_NAME_hint).
---
M.GLFW_COCOA_FRAME_NAME = 0x00023002

---@brief macOS specific
--- [window hint](@ref GLFW_COCOA_GRAPHICS_SWITCHING_hint).
---
M.GLFW_COCOA_GRAPHICS_SWITCHING = 0x00023003

---@brief X11 specific
--- [window hint](@ref GLFW_X11_CLASS_NAME_hint).
---
M.GLFW_X11_CLASS_NAME = 0x00024001

---@brief X11 specific
--- [window hint](@ref GLFW_X11_CLASS_NAME_hint).
---
M.GLFW_X11_INSTANCE_NAME = 0x00024002

M.GLFW_NO_API = 0
M.GLFW_OPENGL_API = 0x00030001
M.GLFW_OPENGL_ES_API = 0x00030002

M.GLFW_NO_ROBUSTNESS = 0
M.GLFW_NO_RESET_NOTIFICATION = 0x00031001
M.GLFW_LOSE_CONTEXT_ON_RESET = 0x00031002

M.GLFW_OPENGL_ANY_PROFILE = 0
M.GLFW_OPENGL_CORE_PROFILE = 0x00032001
M.GLFW_OPENGL_COMPAT_PROFILE = 0x00032002

M.GLFW_CURSOR = 0x00033001
M.GLFW_STICKY_KEYS = 0x00033002
M.GLFW_STICKY_MOUSE_BUTTONS = 0x00033003
M.GLFW_LOCK_KEY_MODS = 0x00033004
M.GLFW_RAW_MOUSE_MOTION = 0x00033005

M.GLFW_CURSOR_NORMAL = 0x00034001
M.GLFW_CURSOR_HIDDEN = 0x00034002
M.GLFW_CURSOR_DISABLED = 0x00034003

M.GLFW_ANY_RELEASE_BEHAVIOR = 0
M.GLFW_RELEASE_BEHAVIOR_FLUSH = 0x00035001
M.GLFW_RELEASE_BEHAVIOR_NONE = 0x00035002

M.GLFW_NATIVE_CONTEXT_API = 0x00036001
M.GLFW_EGL_CONTEXT_API = 0x00036002
M.GLFW_OSMESA_CONTEXT_API = 0x00036003


---@defgroup shapes Standard cursor shapes
---@brief Standard system cursor shapes.
---
--- See [standard cursor creation](@ref cursor_standard) for how these are used.
---
---@ingroup input
---@{


---@brief The regular arrow cursor shape.
---
--- The regular arrow cursor.
---
M.GLFW_ARROW_CURSOR = 0x00036001

---@brief The text input I-beam cursor shape.
---
--- The text input I-beam cursor shape.
---
M.GLFW_IBEAM_CURSOR = 0x00036002

---@brief The crosshair shape.
---
--- The crosshair shape.
---
M.GLFW_CROSSHAIR_CURSOR = 0x00036003

---@brief The hand shape.
---
--- The hand shape.
---
M.GLFW_HAND_CURSOR = 0x00036004

---@brief The horizontal resize arrow shape.
---
--- The horizontal resize arrow shape.
---
M.GLFW_HRESIZE_CURSOR = 0x00036005

---@brief The vertical resize arrow shape.
---
--- The vertical resize arrow shape.
---
M.GLFW_VRESIZE_CURSOR = 0x00036006

M.GLFW_CONNECTED = 0x00040001
M.GLFW_DISCONNECTED = 0x00040002


---@addtogroup init
---@{

---@brief Joystick hat buttons init hint.
---
--- Joystick hat buttons [init hint](@ref GLFW_JOYSTICK_HAT_BUTTONS).
---
M.GLFW_JOYSTICK_HAT_BUTTONS = 0x00050001

---@brief macOS specific init hint.
---
--- macOS specific [init hint](@ref GLFW_COCOA_CHDIR_RESOURCES_hint).
---
M.GLFW_COCOA_CHDIR_RESOURCES = 0x00051001

---@brief macOS specific init hint.
---
--- macOS specific [init hint](@ref GLFW_COCOA_MENUBAR_hint).
---
M.GLFW_COCOA_MENUBAR = 0x00051002

M.GLFW_DONT_CARE = -1

return M
