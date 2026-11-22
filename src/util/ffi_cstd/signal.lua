local ffi = require('ffi')

ffi.cdef [[

typedef int sig_atomic_t;
typedef void (* _crt_signal_t)(int);

_crt_signal_t signal(int _Signal, _crt_signal_t _Function);
int raise(int sig);

]]

--
local M = {}

return M
