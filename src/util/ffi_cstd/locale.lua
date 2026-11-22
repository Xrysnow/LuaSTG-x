local ffi = require('ffi')

ffi.cdef [[

struct lconv {
   char *decimal_point;
   char *thousands_sep;
   char *grouping;
   char *int_curr_symbol;
   char *currency_symbol;
   char *mon_decimal_point;
   char *mon_thousands_sep;
   char *mon_grouping;
   char *positive_sign;
   char *negative_sign;
   char int_frac_digits;
   char frac_digits;
   char p_cs_precedes;
   char p_sep_by_space;
   char n_cs_precedes;
   char n_sep_by_space;
   char p_sign_posn;
   char n_sign_posn;
};

char *setlocale(int category, const char *locale);
struct lconv *localeconv();

]]

--
local M = {}

M.LC_ALL = 0
M.LC_COLLATE = 1
M.LC_CTYPE = 2
M.LC_MONETARY = 3
M.LC_NUMERIC = 4
M.LC_TIME = 5

return M
