--
local M = {}

local ffi = require('ffi')
local k32 = ffi.load('kernel32')
local lib = ffi.load('Advapi32')
local bit = require('bit')
require('platform.win.types')

---
---  The following are masks for the predefined standard access types
---

local DELETE = (0x00010000)
local READ_CONTROL = (0x00020000)
local WRITE_DAC = (0x00040000)
local WRITE_OWNER = (0x00080000)
local SYNCHRONIZE = (0x00100000)
local STANDARD_RIGHTS_REQUIRED = (0x000F0000)
local STANDARD_RIGHTS_READ = (READ_CONTROL)
local STANDARD_RIGHTS_WRITE = (READ_CONTROL)
local STANDARD_RIGHTS_EXECUTE = (READ_CONTROL)
local STANDARD_RIGHTS_ALL = (0x001F0000)
local SPECIFIC_RIGHTS_ALL = (0x0000FFFF)

---
--- Registry Specific Access Rights.
---

local KEY_QUERY_VALUE = (0x0001)
local KEY_SET_VALUE = (0x0002)
local KEY_CREATE_SUB_KEY = (0x0004)
local KEY_ENUMERATE_SUB_KEYS = (0x0008)
local KEY_NOTIFY = (0x0010)
local KEY_CREATE_LINK = (0x0020)
local KEY_WOW64_32KEY = (0x0200)
local KEY_WOW64_64KEY = (0x0100)
local KEY_WOW64_RES = (0x0300)

local KEY_READ = bit.band(bit.bor(STANDARD_RIGHTS_READ,
                                  KEY_QUERY_VALUE,
                                  KEY_ENUMERATE_SUB_KEYS,
                                  KEY_NOTIFY),
                          bit.bnot(SYNCHRONIZE))

local KEY_WRITE = bit.band(bit.bor(STANDARD_RIGHTS_WRITE,
                                   KEY_SET_VALUE,
                                   KEY_CREATE_SUB_KEY),
                           bit.bnot(SYNCHRONIZE))

local KEY_EXECUTE = bit.band((KEY_READ),
                             bit.bnot(SYNCHRONIZE))

local KEY_ALL_ACCESS = bit.band(bit.bor(STANDARD_RIGHTS_ALL,
                                        KEY_QUERY_VALUE,
                                        KEY_SET_VALUE,
                                        KEY_CREATE_SUB_KEY,
                                        KEY_ENUMERATE_SUB_KEYS,
                                        KEY_NOTIFY,
                                        KEY_CREATE_LINK),
                                bit.bnot(SYNCHRONIZE))

local _default_desiredAccess = bit.bor(KEY_READ, KEY_WRITE)

---
--- RRF - Registry Routine Flags (for RegGetValue)
---

local RRF_RT_REG_NONE = 0x00000001  --- restrict type to REG_NONE      (other data types will not return ERROR_SUCCESS)
local RRF_RT_REG_SZ = 0x00000002  --- restrict type to REG_SZ        (other data types will not return ERROR_SUCCESS) (automatically converts REG_EXPAND_SZ to REG_SZ unless RRF_NOEXPAND is specified)
local RRF_RT_REG_EXPAND_SZ = 0x00000004  --- restrict type to REG_EXPAND_SZ (other data types will not return ERROR_SUCCESS) (must specify RRF_NOEXPAND or RegGetValue will fail with ERROR_INVALID_PARAMETER)
local RRF_RT_REG_BINARY = 0x00000008  --- restrict type to REG_BINARY    (other data types will not return ERROR_SUCCESS)
local RRF_RT_REG_DWORD = 0x00000010  --- restrict type to REG_DWORD     (other data types will not return ERROR_SUCCESS)
local RRF_RT_REG_MULTI_SZ = 0x00000020  --- restrict type to REG_MULTI_SZ  (other data types will not return ERROR_SUCCESS)
local RRF_RT_REG_QWORD = 0x00000040  --- restrict type to REG_QWORD     (other data types will not return ERROR_SUCCESS)

local RRF_RT_DWORD = (RRF_RT_REG_BINARY + RRF_RT_REG_DWORD) --- restrict type to *32-bit* RRF_RT_REG_BINARY or RRF_RT_REG_DWORD (other data types will not return ERROR_SUCCESS)
local RRF_RT_QWORD = (RRF_RT_REG_BINARY + RRF_RT_REG_QWORD) --- restrict type to *64-bit* RRF_RT_REG_BINARY or RRF_RT_REG_DWORD (other data types will not return ERROR_SUCCESS)
local RRF_RT_ANY = 0x0000ffff                             --- no type restriction

local RRF_NOEXPAND = 0x10000000  --- do not automatically expand environment strings if value is of type REG_EXPAND_SZ
local RRF_ZEROONFAILURE = 0x20000000  --- if pvData is not NULL, set content to all zeros on failure

---
--- Flags for RegLoadAppKey
---
local REG_PROCESS_APPKEY = 0x00000001

local HKEY_CLASSES_ROOT = 0x80000000
local HKEY_CURRENT_USER = 0x80000001
local HKEY_LOCAL_MACHINE = 0x80000002
local HKEY_USERS = 0x80000003
local HKEY_PERFORMANCE_DATA = 0x80000004
local HKEY_PERFORMANCE_TEXT = 0x80000050
local HKEY_PERFORMANCE_NLSTEXT = 0x80000060
local HKEY_CURRENT_CONFIG = 0x80000005
local HKEY_DYN_DATA = 0x80000006
local HKEY_CURRENT_USER_LOCAL_SETTINGS = 0x80000007
local _predefined_hkey = {
    [HKEY_CURRENT_USER]                = true,
    [HKEY_LOCAL_MACHINE]               = true,
    [HKEY_CLASSES_ROOT]                = true,
    [HKEY_CURRENT_CONFIG]              = true,
    [HKEY_CURRENT_USER_LOCAL_SETTINGS] = true,
    [HKEY_PERFORMANCE_DATA]            = true,
    [HKEY_PERFORMANCE_NLSTEXT]         = true,
    [HKEY_PERFORMANCE_TEXT]            = true,
    [HKEY_USERS]                       = true,
}
local _predefined_hkey_map = {
    HKEY_CURRENT_USER                = HKEY_CURRENT_USER,
    HKEY_LOCAL_MACHINE               = HKEY_LOCAL_MACHINE,
    HKEY_CLASSES_ROOT                = HKEY_CLASSES_ROOT,
    HKEY_CURRENT_CONFIG              = HKEY_CURRENT_CONFIG,
    HKEY_CURRENT_USER_LOCAL_SETTINGS = HKEY_CURRENT_USER_LOCAL_SETTINGS,
    HKEY_PERFORMANCE_DATA            = HKEY_PERFORMANCE_DATA,
    HKEY_PERFORMANCE_NLSTEXT         = HKEY_PERFORMANCE_NLSTEXT,
    HKEY_PERFORMANCE_TEXT            = HKEY_PERFORMANCE_TEXT,
    HKEY_USERS                       = HKEY_USERS,
}
local ERROR_SUCCESS = 0

---
--- Open/Create Options
---

local REG_OPTION_RESERVED = 0x00000000   --- Parameter is reserved

local REG_OPTION_NON_VOLATILE = 0x00000000   --- Key is preserved
--- when system is rebooted

local REG_OPTION_VOLATILE = 0x00000001   --- Key is not preserved
--- when system is rebooted

local REG_OPTION_CREATE_LINK = 0x00000002   --- Created key is a
--- symbolic link

local REG_OPTION_BACKUP_RESTORE = 0x00000004   --- open for backup or restore
--- special access rules
--- privilege required

local REG_OPTION_OPEN_LINK = 0x00000008   --- Open symbolic link

local REG_OPTION_DONT_VIRTUALIZE = 0x00000010   --- Disable Open/Read/Write
--- virtualization for this
--- open and the resulting
--- handle.

local REG_LEGAL_OPTION = (REG_OPTION_RESERVED +
        REG_OPTION_NON_VOLATILE +
        REG_OPTION_VOLATILE +
        REG_OPTION_CREATE_LINK +
        REG_OPTION_BACKUP_RESTORE +
        REG_OPTION_OPEN_LINK +
        REG_OPTION_DONT_VIRTUALIZE)

local REG_OPEN_LEGAL_OPTION = (REG_OPTION_RESERVED +
        REG_OPTION_BACKUP_RESTORE +
        REG_OPTION_OPEN_LINK +
        REG_OPTION_DONT_VIRTUALIZE)

---
--- Key creation/open disposition
---

local REG_CREATED_NEW_KEY = 0x00000001   --- New Registry Key created
local REG_OPENED_EXISTING_KEY = 0x00000002   --- Existing Key opened

---
--- hive format to be used by Reg(Nt)SaveKeyEx
---
local REG_STANDARD_FORMAT = 1
local REG_LATEST_FORMAT = 2
local REG_NO_COMPRESSION = 4

---
--- Key restore & hive load flags
---

local REG_WHOLE_HIVE_VOLATILE = 0x00000001   --- Restore whole hive volatile
local REG_REFRESH_HIVE = 0x00000002   --- Unwind changes to last flush
local REG_NO_LAZY_FLUSH = 0x00000004   --- Never lazy flush this hive
local REG_FORCE_RESTORE = 0x00000008   --- Force the restore process even when we have open handles on subkeys
local REG_APP_HIVE = 0x00000010   --- Loads the hive visible to the calling process
local REG_PROCESS_PRIVATE = 0x00000020   --- Hive cannot be mounted by any other process while in use
local REG_START_JOURNAL = 0x00000040   --- Starts Hive Journal
local REG_HIVE_EXACT_FILE_GROWTH = 0x00000080   --- Grow hive file in exact 4k increments
local REG_HIVE_NO_RM = 0x00000100   --- No RM is started for this hive (no transactions)
local REG_HIVE_SINGLE_LOG = 0x00000200   --- Legacy single logging is used for this hive
local REG_BOOT_HIVE = 0x00000400   --- This hive might be used by the OS loader
local REG_LOAD_HIVE_OPEN_HANDLE = 0x00000800   --- Load the hive and return a handle to its root kcb
local REG_FLUSH_HIVE_FILE_GROWTH = 0x00001000   --- Flush changes to primary hive file size as part of all flushes
local REG_OPEN_READ_ONLY = 0x00002000   --- Open a hive's files in read-only mode
local REG_IMMUTABLE = 0x00004000   --- Load the hive, but don't allow any modification of it
local REG_APP_HIVE_OPEN_READ_ONLY = (REG_OPEN_READ_ONLY)   --- Open an app hive's files in read-only mode (if the hive was not previously loaded)

---
--- Unload Flags
---
local REG_FORCE_UNLOAD = 1
local REG_UNLOAD_LEGAL_FLAGS = (REG_FORCE_UNLOAD)

---
--- Notify filter values
---

local REG_NOTIFY_CHANGE_NAME = 0x00000001 --- Create or delete (child)
local REG_NOTIFY_CHANGE_ATTRIBUTES = 0x00000002
local REG_NOTIFY_CHANGE_LAST_SET = 0x00000004 --- time stamp
local REG_NOTIFY_CHANGE_SECURITY = 0x00000008
local REG_NOTIFY_THREAD_AGNOSTIC = 0x10000000 --- Not associated with a calling thread, can only be used
--- for async user event based notification

local REG_LEGAL_CHANGE_FILTER = (REG_NOTIFY_CHANGE_NAME +
        REG_NOTIFY_CHANGE_ATTRIBUTES +
        REG_NOTIFY_CHANGE_LAST_SET +
        REG_NOTIFY_CHANGE_SECURITY +
        REG_NOTIFY_THREAD_AGNOSTIC)

--
-- Predefined Value Types.
--

local REG_NONE = 0 --- No value type
local REG_SZ = 1 --- Unicode nul terminated string
local REG_EXPAND_SZ = 2 --- Unicode nul terminated string (with environment variable references)
local REG_BINARY = 3 --- Free form binary
local REG_DWORD = 4 --- 32-bit number
local REG_DWORD_LITTLE_ENDIAN = 4 --- 32-bit number (same as REG_DWORD)
local REG_DWORD_BIG_ENDIAN = 5 --- 32-bit number
local REG_LINK = 6 --- Symbolic Link (unicode)
local REG_MULTI_SZ = 7 --- Multiple Unicode strings
local REG_RESOURCE_LIST = 8 --- Resource list in the resource map
local REG_FULL_RESOURCE_DESCRIPTOR = 9 --- Resource list in the hardware description
local REG_RESOURCE_REQUIREMENTS_LIST = 10
local REG_QWORD = 11 --- 64-bit number
local REG_QWORD_LITTLE_ENDIAN = 11 --- 64-bit number (same as REG_QWORD)

ffi.cdef [[
typedef long LSTATUS;
typedef void* LPSECURITY_ATTRIBUTES;
typedef void* PVALENTW;
typedef DWORD REGSAM;

LSTATUS RegCloseKey(
  HKEY hKey
);
LSTATUS RegConnectRegistryW(
  LPCWSTR lpMachineName,
  HKEY    hKey,
  PHKEY   phkResult
);
LSTATUS RegCopyTreeW(
  HKEY    hKeySrc,
  LPCWSTR lpSubKey,
  HKEY    hKeyDest
);
LSTATUS RegCreateKeyExW(
  HKEY                        hKey,
  LPCWSTR                     lpSubKey,
  DWORD                       Reserved,
  LPWSTR                      lpClass,
  DWORD                       dwOptions,
  REGSAM                      samDesired,
  const LPSECURITY_ATTRIBUTES lpSecurityAttributes,
  PHKEY                       phkResult,
  LPDWORD                     lpdwDisposition
);
LSTATUS RegCreateKeyTransactedW(
  HKEY                        hKey,
  LPCWSTR                     lpSubKey,
  DWORD                       Reserved,
  LPWSTR                      lpClass,
  DWORD                       dwOptions,
  REGSAM                      samDesired,
  const LPSECURITY_ATTRIBUTES lpSecurityAttributes,
  PHKEY                       phkResult,
  LPDWORD                     lpdwDisposition,
  HANDLE                      hTransaction,
  PVOID                       pExtendedParemeter
);
LSTATUS RegCreateKeyW(
  HKEY    hKey,
  LPCWSTR lpSubKey,
  PHKEY   phkResult
);
LSTATUS RegDeleteKeyExW(
  HKEY    hKey,
  LPCWSTR lpSubKey,
  REGSAM  samDesired,
  DWORD   Reserved
);
LSTATUS RegDeleteKeyTransactedW(
  HKEY    hKey,
  LPCWSTR lpSubKey,
  REGSAM  samDesired,
  DWORD   Reserved,
  HANDLE  hTransaction,
  PVOID   pExtendedParameter
);
LSTATUS RegDeleteKeyValueW(
  HKEY    hKey,
  LPCWSTR lpSubKey,
  LPCWSTR lpValueName
);
LSTATUS RegDeleteKeyW(
  HKEY    hKey,
  LPCWSTR lpSubKey
);
LSTATUS RegDeleteTreeW(
  HKEY    hKey,
  LPCWSTR lpSubKey
);
LSTATUS RegDeleteValueW(
  HKEY    hKey,
  LPCWSTR lpValueName
);
LSTATUS RegDisablePredefinedCache();
LSTATUS RegDisablePredefinedCacheEx();
LONG RegDisableReflectionKey(
  HKEY hBase
);
LONG RegEnableReflectionKey(
  HKEY hBase
);
LSTATUS RegEnumKeyExW(
  HKEY      hKey,
  DWORD     dwIndex,
  LPWSTR    lpName,
  LPDWORD   lpcchName,
  LPDWORD   lpReserved,
  LPWSTR    lpClass,
  LPDWORD   lpcchClass,
  PFILETIME lpftLastWriteTime
);
LSTATUS RegEnumKeyW(
  HKEY   hKey,
  DWORD  dwIndex,
  LPWSTR lpName,
  DWORD  cchName
);
LSTATUS RegEnumValueW(
  HKEY    hKey,
  DWORD   dwIndex,
  LPWSTR  lpValueName,
  LPDWORD lpcchValueName,
  LPDWORD lpReserved,
  LPDWORD lpType,
  LPBYTE  lpData,
  LPDWORD lpcbData
);
LSTATUS RegFlushKey(
  HKEY hKey
);
LSTATUS RegGetValueW(
  HKEY    hkey,
  LPCWSTR lpSubKey,
  LPCWSTR lpValue,
  DWORD   dwFlags,
  LPDWORD pdwType,
  PVOID   pvData,
  LPDWORD pcbData
);
LSTATUS RegLoadAppKeyW(
  LPCWSTR lpFile,
  PHKEY   phkResult,
  REGSAM  samDesired,
  DWORD   dwOptions,
  DWORD   Reserved
);
LSTATUS RegLoadKeyW(
  HKEY    hKey,
  LPCWSTR lpSubKey,
  LPCWSTR lpFile
);
LSTATUS RegLoadMUIStringW(
  HKEY    hKey,
  LPCWSTR pszValue,
  LPWSTR  pszOutBuf,
  DWORD   cbOutBuf,
  LPDWORD pcbData,
  DWORD   Flags,
  LPCWSTR pszDirectory
);
LSTATUS RegNotifyChangeKeyValue(
  HKEY   hKey,
  BOOL   bWatchSubtree,
  DWORD  dwNotifyFilter,
  HANDLE hEvent,
  BOOL   fAsynchronous
);
LSTATUS RegOpenCurrentUser(
  REGSAM samDesired,
  PHKEY  phkResult
);
LSTATUS RegOpenKeyExW(
  HKEY    hKey,
  LPCWSTR lpSubKey,
  DWORD   ulOptions,
  REGSAM  samDesired,
  PHKEY   phkResult
);
LSTATUS RegOpenKeyTransactedW(
  HKEY    hKey,
  LPCWSTR lpSubKey,
  DWORD   ulOptions,
  REGSAM  samDesired,
  PHKEY   phkResult,
  HANDLE  hTransaction,
  PVOID   pExtendedParemeter
);
LSTATUS RegOpenKeyW(
  HKEY    hKey,
  LPCWSTR lpSubKey,
  PHKEY   phkResult
);
LSTATUS RegOpenUserClassesRoot(
  HANDLE hToken,
  DWORD  dwOptions,
  REGSAM samDesired,
  PHKEY  phkResult
);
LSTATUS RegOverridePredefKey(
  HKEY hKey,
  HKEY hNewHKey
);
LSTATUS RegQueryInfoKeyW(
  HKEY      hKey,
  LPWSTR    lpClass,
  LPDWORD   lpcchClass,
  LPDWORD   lpReserved,
  LPDWORD   lpcSubKeys,
  LPDWORD   lpcbMaxSubKeyLen,
  LPDWORD   lpcbMaxClassLen,
  LPDWORD   lpcValues,
  LPDWORD   lpcbMaxValueNameLen,
  LPDWORD   lpcbMaxValueLen,
  LPDWORD   lpcbSecurityDescriptor,
  PFILETIME lpftLastWriteTime
);
LSTATUS RegQueryMultipleValuesW(
  HKEY     hKey,
  PVALENTW val_list,
  DWORD    num_vals,
  LPWSTR   lpValueBuf,
  LPDWORD  ldwTotsize
);
LONG RegQueryReflectionKey(
  HKEY hBase,
  BOOL *bIsReflectionDisabled
);
LSTATUS RegQueryValueExW(
  HKEY    hKey,
  LPCWSTR lpValueName,
  LPDWORD lpReserved,
  LPDWORD lpType,
  LPBYTE  lpData,
  LPDWORD lpcbData
);
LSTATUS RegQueryValueW(
  HKEY    hKey,
  LPCWSTR lpSubKey,
  LPWSTR  lpData,
  PLONG   lpcbData
);
LSTATUS RegRenameKey(
  HKEY    hKey,
  LPCWSTR lpSubKeyName,
  LPCWSTR lpNewKeyName
);
LSTATUS RegReplaceKeyW(
  HKEY    hKey,
  LPCWSTR lpSubKey,
  LPCWSTR lpNewFile,
  LPCWSTR lpOldFile
);
LSTATUS RegRestoreKeyW(
  HKEY    hKey,
  LPCWSTR lpFile,
  DWORD   dwFlags
);
LSTATUS RegSaveKeyExW(
  HKEY                        hKey,
  LPCWSTR                     lpFile,
  const LPSECURITY_ATTRIBUTES lpSecurityAttributes,
  DWORD                       Flags
);
LSTATUS RegSaveKeyW(
  HKEY                        hKey,
  LPCWSTR                     lpFile,
  const LPSECURITY_ATTRIBUTES lpSecurityAttributes
);
LSTATUS RegSetKeyValueW(
  HKEY    hKey,
  LPCWSTR lpSubKey,
  LPCWSTR lpValueName,
  DWORD   dwType,
  LPCVOID lpData,
  DWORD   cbData
);
LSTATUS RegSetValueExW(
  HKEY       hKey,
  LPCWSTR    lpValueName,
  DWORD      Reserved,
  DWORD      dwType,
  const BYTE *lpData,
  DWORD      cbData
);
LSTATUS RegSetValueW(
  HKEY    hKey,
  LPCWSTR lpSubKey,
  DWORD   dwType,
  LPCWSTR lpData,
  DWORD   cbData
);
LSTATUS RegUnLoadKeyW(
  HKEY    hKey,
  LPCWSTR lpSubKey
);
]]

local function BuildMultiString(data)
    if #data == 0 then
        return ffi.new('wchar_t[2]')
    end
    local totalLen = 0
    for i, v in ipairs(data) do
        totalLen = totalLen + v.length + 1
    end
    totalLen = totalLen + 1
    local multiString = ffi.new('wchar_t[?]', totalLen)
    local offset = 0
    for i, v in ipairs(data) do
        ffi.copy(multiString + offset, v.c_str, v.length * 2)
        offset = offset + v.length + 1
    end
    return multiString, totalLen
end

local wcs = require('platform.win.wcs')

local function wstring(s)
    if type(s) == 'string' then
        local p, sz = wcs.wcs_sz(s)
        return { c_str = p, length = sz - 1 }
    else
        return s
    end
end

local function MAKELANGID(p, s)
    return bit.bor(bit.lshift(s, 10), p)
end
local function ErrorMessage(result)
    --local LANG_NEUTRAL = 0
    --local SUBLANG_DEFAULT = 1
    --local languageId = MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT)
    local FORMAT_MESSAGE_IGNORE_INSERTS = 0x00000200
    local FORMAT_MESSAGE_FROM_STRING = 0x00000400
    local FORMAT_MESSAGE_FROM_HMODULE = 0x00000800
    local FORMAT_MESSAGE_FROM_SYSTEM = 0x00001000
    local FORMAT_MESSAGE_ARGUMENT_ARRAY = 0x00002000
    if result == 8 then
        error('out of memory')
    elseif result == 0 then
        return 'no error'
    end
    require('platform.win.util')
    local bufsize = 2048
    local buf = ffi.new('char[?]', bufsize)
    local flags = bit.bor(FORMAT_MESSAGE_FROM_SYSTEM,
                          FORMAT_MESSAGE_IGNORE_INSERTS)
    local sz = k32.FormatMessageA(flags, nil, result, 0, buf, bufsize, nil)
    if sz == 0 then
        return ''
    end
    return ffi.string(buf, sz)
end

local _no_exception = false
local function RegException(code, msg)
    if _no_exception then
        _no_exception = false
        return nil
    else
        print(ErrorMessage(code), code)
        error(msg)
    end
end

local function HKEY(data)
    if data == nil then
        return ffi.new('HKEY[1]')
    elseif type(data) == 'number' then
        return ffi.new('HKEY[1]', data)
    elseif type(data) == 'cdata' then
        local ret = ffi.new('HKEY[1]', data)
        ret[0] = data
        return ret
    else
        return ffi.new('HKEY[1]', data)
    end
end

local RegCloseKey = lib.RegCloseKey
local RegCreateKeyEx = lib.RegCreateKeyExW
local RegOpenKeyEx = lib.RegOpenKeyExW
local RegSetValueEx = lib.RegSetValueExW
local RegGetValue = lib.RegGetValueW
local RegQueryInfoKey = lib.RegQueryInfoKeyW
local RegEnumKeyEx = lib.RegEnumKeyExW
local RegEnumValue = lib.RegEnumValueW
local RegQueryValueEx = lib.RegQueryValueExW
local RegDeleteValue = lib.RegDeleteValueW
local RegDeleteKeyEx = lib.RegDeleteKeyExW
local RegDeleteTree = lib.RegDeleteTreeW
local RegCopyTree = lib.RegCopyTreeW
local RegFlushKey = lib.RegFlushKey
local RegLoadKey = lib.RegLoadKeyW
local RegSaveKey = lib.RegSaveKeyW
local RegEnableReflectionKey = lib.RegEnableReflectionKey
local RegDisableReflectionKey = lib.RegDisableReflectionKey
local RegQueryReflectionKey = lib.RegQueryReflectionKey
local RegConnectRegistry = lib.RegConnectRegistryW

---@class platform.win.RegKey
local RegKey = {}

function RegKey:__gc()
    self:Close()
end
--- Access the wrapped raw HKEY handle
function RegKey:Get()
    return self.m_hKey
end

function RegKey:Close()
    if self:IsValid() then
        if not self:IsPredefined() then
            RegCloseKey(self.m_hKey)
        end
        self.m_hKey = nil
    end
end
--- Is the wrapped HKEY handle valid?
function RegKey:IsValid()
    return self.m_hKey ~= nil
end
--- Is the wrapped handle a predefined handle (e.g.HKEY_CURRENT_USER) ?
function RegKey:IsPredefined()
    return _predefined_hkey[tonumber(self.m_hKey)]
end

function RegKey:Detach()
    local hKey = self.m_hKey
    self.m_hKey = nil
    return hKey
end

function RegKey:Attach(hKey)
    if self.m_hKey ~= hKey then
        self:Close()
        self.m_hKey = hKey
    end
end

function RegKey:SwapWith(other)
    self.m_hKey, other.m_hKey = other.m_hKey, self.m_hKey
end

function RegKey:Create1(hKeyParent,
                        subKey,
                        desiredAccess)
    desiredAccess = desiredAccess or _default_desiredAccess
    local kDefaultOptions = REG_OPTION_NON_VOLATILE
    self:Create2(hKeyParent, subKey, desiredAccess, kDefaultOptions,
                 nil, -- no security attributes,
                 nil-- no disposition
    )
end

function RegKey:Create2(hKeyParent,
                        subKey,
                        desiredAccess,
                        options,
                        securityAttributes,
                        disposition)
    subKey = wstring(subKey)
    local hKey = HKEY()
    local retCode = RegCreateKeyEx(
            hKeyParent,
            subKey.c_str,
            0, -- reserved
            ffi.cast('LPWSTR', REG_NONE), -- user-defined class type parameter not supported
            options,
            desiredAccess,
            securityAttributes,
            hKey,
            disposition
    )
    if retCode ~= ERROR_SUCCESS then
        return RegException(retCode, "RegCreateKeyEx failed.")
    end
    self:Close()
    self.m_hKey = hKey[0]
end

function RegKey:Open(hKeyParent,
                     subKey,
                     desiredAccess)
    desiredAccess = desiredAccess or _default_desiredAccess
    subKey = wstring(subKey)
    local hKey = HKEY()
    local retCode = RegOpenKeyEx(
            hKeyParent,
            subKey.c_str,
            REG_NONE, -- default options
            desiredAccess,
            hKey
    )
    if retCode ~= ERROR_SUCCESS then
        return RegException(retCode, "RegOpenKeyEx failed.")
    end
    self:Close()
    self.m_hKey = hKey[0]
end

function RegKey:TryCreate1(hKeyParent,
                           subKey,
                           desiredAccess)
    desiredAccess = desiredAccess or _default_desiredAccess
    local kDefaultOptions = REG_OPTION_NON_VOLATILE
    self:TryCreate2(hKeyParent, subKey, desiredAccess, kDefaultOptions,
                    nil, -- no security attributes,
                    nil-- no disposition
    )
end

function RegKey:TryCreate2(hKeyParent,
                           subKey,
                           desiredAccess,
                           options,
                           securityAttributes,
                           disposition)
    return self:_try('Create2',
                     hKeyParent,
                     subKey,
                     desiredAccess,
                     options,
                     securityAttributes,
                     disposition)
end

function RegKey:TryOpen(hKeyParent,
                        subKey,
                        desiredAccess)
    desiredAccess = desiredAccess or _default_desiredAccess
    return self:_try('Open',
                     hKeyParent,
                     subKey,
                     desiredAccess)
end

function RegKey:SetDwordValue(valueName, data)
    valueName = wstring(valueName)
    assert(self:IsValid())
    local data_ = ffi.new('DWORD[1]')
    data_[0] = data
    local retCode = RegSetValueEx(
            self.m_hKey,
            valueName.c_str,
            0, -- reserved
            REG_DWORD,
            ffi.cast('BYTE*', data_),
            ffi.sizeof('DWORD')
    )
    if retCode ~= ERROR_SUCCESS then
        return RegException(retCode, "Cannot write DWORD value: RegSetValueEx failed.")
    end
end

function RegKey:SetQwordValue(valueName, data)
    valueName = wstring(valueName)
    assert(self:IsValid())
    local data_ = ffi.new('ULONGLONG[1]')
    data_[0] = data
    local retCode = RegSetValueEx(
            self.m_hKey,
            valueName.c_str,
            0, -- reserved
            REG_QWORD,
            ffi.cast('BYTE*', data_),
            ffi.sizeof('ULONGLONG')
    )
    if retCode ~= ERROR_SUCCESS then
        return RegException(retCode, "Cannot write QWORD value: RegSetValueEx failed.")
    end
end

function RegKey:SetStringValue(valueName, data)
    valueName = wstring(valueName)
    data = wstring(data)
    assert(self:IsValid())
    local dataSize = ffi.sizeof('wchar_t') * (data.length + 1)
    local retCode = RegSetValueEx(
            self.m_hKey,
            valueName.c_str,
            0, -- reserved
            REG_SZ,
            ffi.cast('BYTE*', data.c_str),
            dataSize
    )
    if retCode ~= ERROR_SUCCESS then
        return RegException(retCode, "Cannot write string value: RegSetValueEx failed.")
    end
end

function RegKey:SetExpandStringValue(valueName, data)
    valueName = wstring(valueName)
    data = wstring(data)
    assert(self:IsValid())
    local dataSize = ffi.sizeof('wchar_t') * (data.length + 1)
    local retCode = RegSetValueEx(
            self.m_hKey,
            valueName.c_str,
            0, -- reserved
            REG_EXPAND_SZ,
            ffi.cast('BYTE*', data.c_str),
            dataSize
    )
    if retCode ~= ERROR_SUCCESS then
        return RegException(retCode, "Cannot write expand string value: RegSetValueEx failed.")
    end
end

function RegKey:SetMultiStringValue(valueName, data)
    assert(type(data) == 'table')
    if #data > 0 and type(data[1]) == 'string' then
        local data_ = {}
        for i, v in ipairs(data) do
            data_[i] = wstring(v)
        end
    end
    valueName = wstring(valueName)
    assert(self:IsValid())
    local multiString, multiStringLength = BuildMultiString(data)
    local dataSize = multiStringLength * ffi.sizeof('wchar_t')
    local retCode = RegSetValueEx(
            self.m_hKey,
            valueName.c_str,
            0, -- reserved
            REG_MULTI_SZ,
            ffi.cast('BYTE*', multiString),
            dataSize
    )
    if retCode ~= ERROR_SUCCESS then
        return RegException(retCode, "Cannot write multi-string value: RegSetValueEx failed.")
    end
end

function RegKey:SetBinaryValue(valueName, data, dataSize)
    valueName = wstring(valueName)
    assert(self:IsValid())
    local retCode = RegSetValueEx(
            self.m_hKey,
            valueName.c_str,
            0, -- reserved
            REG_BINARY,
            ffi.cast('BYTE*', data),
            dataSize
    )
    if retCode ~= ERROR_SUCCESS then
        return RegException(retCode, "Cannot write binary value: RegSetValueEx failed.")
    end
end

function RegKey:GetDwordValue(valueName)
    valueName = wstring(valueName)
    assert(self:IsValid())
    local data = ffi.new('DWORD[1]')
    local dataSize = ffi.new('DWORD[1]', ffi.sizeof('DWORD'))
    local flags = RRF_RT_REG_DWORD
    local retCode = RegGetValue(
            self.m_hKey,
            nil, -- no subkey
            valueName.c_str,
            flags,
            nil, -- type not required
            data,
            dataSize
    )
    if retCode ~= ERROR_SUCCESS then
        return RegException(retCode, "Cannot get DWORD value: RegGetValue failed.")
    end
    return data[0]
end

function RegKey:GetQwordValue(valueName)
    valueName = wstring(valueName)
    assert(self:IsValid())
    local data = ffi.new('ULONGLONG[1]')
    local dataSize = ffi.new('DWORD[1]', ffi.sizeof('ULONGLONG'))
    local flags = RRF_RT_REG_QWORD
    local retCode = RegGetValue(
            self.m_hKey,
            nil, -- no subkey
            valueName.c_str,
            flags,
            nil, -- type not required
            data,
            dataSize
    )
    if retCode ~= ERROR_SUCCESS then
        return RegException(retCode, "Cannot get DWORD value: RegGetValue failed.")
    end
    return data[0]
end

function RegKey:GetStringValue(valueName)
    valueName = wstring(valueName)
    assert(self:IsValid())
    local dataSize = ffi.new('DWORD[1]', 0)
    local flags = RRF_RT_REG_SZ
    local retCode = RegGetValue(
            self.m_hKey,
            nil, -- no subkey
            valueName.c_str,
            flags,
            nil, -- type not required
            nil, -- output buffer not needed now
            dataSize
    )
    if retCode ~= ERROR_SUCCESS then
        return RegException(retCode, "Cannot get size of string value: RegGetValue failed.")
    end
    local result = ffi.new('wchar_t[?]', dataSize[0] / ffi.sizeof('wchar_t'), string.byte(' '))
    retCode = RegGetValue(
            self.m_hKey,
            nil, -- no subkey
            valueName.c_str,
            flags,
            nil, -- type not required
            result, -- output buffer
            dataSize
    )
    if retCode ~= ERROR_SUCCESS then
        return RegException(retCode, "Cannot get size of string value: RegGetValue failed.")
    end
    -- Remove the NUL terminator scribbled by RegGetValue from the wstring
    --local length = dataSize[0] / ffi.sizeof('wchar_t') - 1
    --local result_ = ffi.new('wchar_t[?]', length)
    --ffi.copy(result_, result, ffi.sizeof(result_))
    return wcs.mbs(result)
end

local ExpandStringOption = {
    DontExpand = 0,
    Expand     = 1,
}
RegKey.ExpandStringOption = ExpandStringOption

local function processExpandOption(expandOption)
    if expandOption == true then
        expandOption = ExpandStringOption.Expand
    end
    expandOption = expandOption or ExpandStringOption.DontExpand
    return expandOption
end

function RegKey:GetExpandStringValue(valueName, expandOption)
    expandOption = processExpandOption(expandOption)
    valueName = wstring(valueName)
    assert(self:IsValid())
    local flags = RRF_RT_REG_EXPAND_SZ
    if expandOption == ExpandStringOption.DontExpand then
        flags = bit.bor(flags, RRF_NOEXPAND)
    end
    -- Get the size of the result string
    local dataSize = ffi.new('DWORD[1]', 0)
    local retCode = RegGetValue(
            self.m_hKey,
            nil, -- no subkey
            valueName.c_str,
            flags,
            nil, -- type not required
            nil, -- output buffer not needed now
            dataSize
    )
    if retCode ~= ERROR_SUCCESS then
        return RegException(retCode, "Cannot get size of expand string value: RegGetValue failed.")
    end
    local result = ffi.new('wchar_t[?]', dataSize[0] / ffi.sizeof('wchar_t'), string.byte(' '))
    retCode = RegGetValue(
            self.m_hKey,
            nil, -- no subkey
            valueName.c_str,
            flags,
            nil, -- type not required
            result, -- output buffer
            dataSize
    )
    if retCode ~= ERROR_SUCCESS then
        return RegException(retCode, "Cannot get size of expand string value: RegGetValue failed.")
    end
    -- Remove the NUL terminator scribbled by RegGetValue from the wstring
    --local length = dataSize[0] / ffi.sizeof('wchar_t') - 1
    --local result_ = ffi.new('wchar_t[?]', length)
    --ffi.copy(result_, result, ffi.sizeof(result_))
    return wcs.mbs(result)
end

function RegKey:GetMultiStringValue(valueName)
    valueName = wstring(valueName)
    assert(self:IsValid())
    local dataSize = ffi.new('DWORD[1]', 0)
    local flags = RRF_RT_REG_MULTI_SZ
    local retCode = RegGetValue(
            self.m_hKey,
            nil, -- no subkey
            valueName.c_str,
            flags,
            nil, -- type not required
            nil, -- output buffer not needed now
            dataSize
    )
    if retCode ~= ERROR_SUCCESS then
        return RegException(retCode, "Cannot get size of multi-string value: RegGetValue failed.")
    end
    local data = ffi.new('wchar_t[?]', dataSize[0] / ffi.sizeof('wchar_t'), string.byte(' '))
    retCode = RegGetValue(
            self.m_hKey,
            nil, -- no subkey
            valueName.c_str,
            flags,
            nil, -- type not required
            data, -- output buffer
            dataSize
    )
    if retCode ~= ERROR_SUCCESS then
        return RegException(retCode, "Cannot get size of multi-string value: RegGetValue failed.")
    end
    --local size = dataSize[0] / ffi.sizeof('wchar_t')
    local result = {}
    local curr_idx = 0
    while data[curr_idx] ~= 0 do
        local currStringPtr = data + curr_idx
        local currStringLength = wcs.wcslen(currStringPtr)
        table.insert(result, wcs.mbs(currStringPtr))
        curr_idx = curr_idx + currStringLength + 1
    end
    return result
end

function RegKey:GetBinaryValue(valueName)
    valueName = wstring(valueName)
    assert(self:IsValid())
    local dataSize = ffi.new('DWORD[1]', 0)
    local flags = RRF_RT_REG_BINARY
    local retCode = RegGetValue(
            self.m_hKey,
            nil, -- no subkey
            valueName.c_str,
            flags,
            nil, -- type not required
            nil, -- output buffer not needed now
            dataSize
    )
    if retCode ~= ERROR_SUCCESS then
        return RegException(retCode, "Cannot get size of binary data: RegGetValue failed.")
    end
    local data = ffi.new('BYTE[?]', dataSize[0])
    retCode = RegGetValue(
            self.m_hKey,
            nil, -- no subkey
            valueName.c_str,
            flags,
            nil, -- type not required
            data, -- output buffer
            dataSize
    )
    if retCode ~= ERROR_SUCCESS then
        return RegException(retCode, "Cannot get size of binary data: RegGetValue failed.")
    end
    return data, dataSize[0]
end

function RegKey:GetValue(valueName, ...)
    local typeId = self:QueryValueType(valueName)
    if typeId == REG_DWORD then
        return self:GetDwordValue(valueName), 'DWORD'
    elseif typeId == REG_QWORD then
        return self:GetQwordValue(valueName), 'QWORD'
    elseif typeId == REG_SZ then
        return self:GetStringValue(valueName), 'String'
    elseif typeId == REG_EXPAND_SZ then
        return self:GetExpandStringValue(valueName, ...), 'ExpandString'
    elseif typeId == REG_MULTI_SZ then
        return self:GetMultiStringValue(valueName), 'MultiString'
    elseif typeId == REG_BINARY then
        return self:GetBinaryValue(valueName), 'Binary'
    end
end

function RegKey:_try(method, ...)
    _no_exception = true
    local result = { self[method](self, ...) }
    _no_exception = false
    return unpack(result)
end

function RegKey:TryGetDwordValue(valueName)
    return self:_try('GetDwordValue', valueName)
end

function RegKey:TryGetQwordValue(valueName)
    return self:_try('GetQwordValue', valueName)
end

function RegKey:TryGetStringValue(valueName)
    return self:_try('GetStringValue', valueName)
end

function RegKey:TryGetExpandStringValue(valueName, expandOption)
    return self:_try('GetExpandStringValue', valueName, expandOption)
end

function RegKey:TryGetMultiStringValue(valueName)
    return self:_try('GetMultiStringValue', valueName)
end

function RegKey:TryGetBinaryValue(valueName)
    return self:_try('GetBinaryValue', valueName)
end

function RegKey:EnumSubKeys()
    assert(self:IsValid())
    local subKeyCount = ffi.new('DWORD[1]', 0)
    local maxSubKeyNameLen = ffi.new('DWORD[1]', 0)
    local retCode = RegQueryInfoKey(
            self.m_hKey,
            nil, -- no user-defined class
            nil, -- no user-defined class size
            nil, -- reserved
            subKeyCount,
            maxSubKeyNameLen,
            nil, -- no subkey class length
            nil, -- no value count
            nil, -- no value name max length
            nil, -- no max value length
            nil, -- no security descriptor
            nil  -- no last write time
    )
    if retCode ~= ERROR_SUCCESS then
        return RegException(retCode, "RegQueryInfoKey failed while preparing for subkey enumeration.")
    end
    subKeyCount = subKeyCount[0]
    maxSubKeyNameLen = maxSubKeyNameLen[0] + 1
    local nameBuffer = ffi.new('wchar_t[?]', maxSubKeyNameLen)
    local subkeyNames = {}
    for index = 1, subKeyCount do
        local subKeyNameLen = ffi.new('DWORD[1]', maxSubKeyNameLen)
        retCode = RegEnumKeyEx(
                self.m_hKey,
                index - 1,
                nameBuffer,
                subKeyNameLen,
                nil, -- reserved
                nil, -- no class
                nil, -- no class
                nil  -- no last write time
        )
        if retCode ~= ERROR_SUCCESS then
            return RegException(retCode, "Cannot enumerate subkeys: RegEnumKeyEx failed.")
        end
        table.insert(subkeyNames, wcs.mbs(nameBuffer))
    end
    return subkeyNames
end

function RegKey:EnumValues()
    assert(self:IsValid())
    local valueCount = ffi.new('DWORD[1]', 0)
    local maxValueNameLen = ffi.new('DWORD[1]', 0)
    local retCode = RegQueryInfoKey(
            self.m_hKey,
            nil, -- no user-defined class
            nil, -- no user-defined class size
            nil, -- reserved
            nil, -- no subkey count
            nil, -- no subkey max length
            nil, -- no subkey class length
            valueCount,
            maxValueNameLen,
            nil, -- no max value length
            nil, -- no security descriptor
            nil  -- no last write time
    )
    if retCode ~= ERROR_SUCCESS then
        return RegException(retCode, "RegQueryInfoKey failed while preparing for value enumeration.")
    end
    valueCount = valueCount[0]
    maxValueNameLen = maxValueNameLen[0] + 1
    local nameBuffer = ffi.new('wchar_t[?]', maxValueNameLen)
    local valueInfo = {}
    for index = 1, valueCount do
        local valueNameLen = ffi.new('DWORD[1]', maxValueNameLen)
        local valueType = ffi.new('DWORD[1]', 0)
        retCode = RegEnumValue(
                self.m_hKey,
                index - 1,
                nameBuffer,
                valueNameLen,
                nil, -- reserved
                valueType,
                nil, -- no data
                nil  -- no data size
        )
        if retCode ~= ERROR_SUCCESS then
            return RegException(retCode, "Cannot enumerate subkeys: RegEnumValue failed.")
        end
        table.insert(valueInfo, { wcs.mbs(nameBuffer), valueType[0] })
    end
    return valueInfo
end

function RegKey:QueryValueType(valueName)
    assert(self:IsValid())
    valueName = wstring(valueName)
    local typeId = ffi.new('DWORD[1]', 0)
    local retCode = RegQueryValueEx(
            self.m_hKey,
            valueName.c_str,
            nil, -- reserved
            typeId,
            nil,
            nil
    )
    if retCode ~= ERROR_SUCCESS then
        return RegException(retCode, "Cannot get the value type: RegQueryValueEx failed.")
    end
    return typeId[0]
end

function RegKey:QueryInfoKey(subKeys, values, lastWriteTime)
    assert(self:IsValid())
    subKeys = subKeys or ffi.new('DWORD[1]', 0)
    values = values or ffi.new('DWORD[1]', 0)
    lastWriteTime = lastWriteTime or ffi.new('FILETIME[1]', 0)
    local retCode = RegQueryInfoKey(
            self.m_hKey,
            nil,
            nil,
            nil,
            subKeys,
            nil,
            nil,
            values,
            nil,
            nil,
            nil,
            lastWriteTime
    )
    if retCode ~= ERROR_SUCCESS then
        return RegException(retCode, "RegQueryInfoKey failed.")
    end
end

function RegKey:DeleteValue(valueName)
    assert(self:IsValid())
    valueName = wstring(valueName)
    local retCode = RegDeleteValue(self.m_hKey, valueName.c_str)
    if retCode ~= ERROR_SUCCESS then
        return RegException(retCode, "RegDeleteValue failed.")
    end
end

function RegKey:DeleteKeyEx(subKey, desiredAccess)
    assert(self:IsValid())
    subKey = wstring(subKey)
    local retCode = RegDeleteKeyEx(self.m_hKey, subKey.c_str, desiredAccess, 0)
    if retCode ~= ERROR_SUCCESS then
        return RegException(retCode, "RegDeleteKeyEx failed.")
    end
end

function RegKey:DeleteTree(subKey)
    assert(self:IsValid())
    subKey = wstring(subKey)
    local retCode = RegDeleteTree(self.m_hKey, subKey.c_str)
    if retCode ~= ERROR_SUCCESS then
        return RegException(retCode, "RegDeleteTree failed.")
    end
end

function RegKey:CopyTree(sourceSubKey, destKey)
    assert(self:IsValid())
    sourceSubKey = wstring(sourceSubKey)
    local retCode = RegCopyTree(self.m_hKey, sourceSubKey.c_str, destKey:Get())
    if retCode ~= ERROR_SUCCESS then
        return RegException(retCode, "RegCopyTree failed.")
    end
end

function RegKey:FlushKey()
    assert(self:IsValid())
    local retCode = RegFlushKey(self.m_hKey)
    if retCode ~= ERROR_SUCCESS then
        return RegException(retCode, "RegFlushKey failed.")
    end
end

function RegKey:LoadKey(subKey, filename)
    assert(self:IsValid())
    subKey = wstring(subKey)
    filename = wstring(filename)
    local retCode = RegLoadKey(self.m_hKey, subKey.c_str, filename.c_str)
    if retCode ~= ERROR_SUCCESS then
        return RegException(retCode, "RegLoadKey failed.")
    end
end

function RegKey:SaveKey(filename, securityAttributes)
    assert(self:IsValid())
    filename = wstring(filename)
    local retCode = RegSaveKey(self.m_hKey, filename.c_str, securityAttributes)
    if retCode ~= ERROR_SUCCESS then
        return RegException(retCode, "RegSaveKey failed.")
    end
end

function RegKey:EnableReflectionKey()
    assert(self:IsValid())
    local retCode = RegEnableReflectionKey(self.m_hKey)
    if retCode ~= ERROR_SUCCESS then
        return RegException(retCode, "RegEnableReflectionKey failed.")
    end
end

function RegKey:DisableReflectionKey()
    assert(self:IsValid())
    local retCode = RegDisableReflectionKey(self.m_hKey)
    if retCode ~= ERROR_SUCCESS then
        return RegException(retCode, "DisableReflectionKey failed.")
    end
end

function RegKey:QueryReflectionKey()
    assert(self:IsValid())
    local isReflectionDisabled = ffi.new('BOOL[1]', 0)
    local retCode = RegQueryReflectionKey(self.m_hKey, isReflectionDisabled)
    if retCode ~= ERROR_SUCCESS then
        return RegException(retCode, "QueryReflectionKey failed.")
    end
    return isReflectionDisabled[0] > 0
end

function RegKey:ConnectRegistry(machineName, hKeyPredefined)
    machineName = wstring(machineName)
    self:Close()
    local hKeyResult = HKEY()
    local retCode = RegConnectRegistry(machineName.c_str, hKeyPredefined, hKeyResult)
    if retCode ~= ERROR_SUCCESS then
        return RegException(retCode, "RegConnectRegistry failed.")
    end
    self.m_hKey = hKeyResult[0]
end

local _type_string = {
    [REG_SZ]        = 'REG_SZ',
    [REG_EXPAND_SZ] = 'REG_EXPAND_SZ',
    [REG_MULTI_SZ]  = 'REG_MULTI_SZ',
    [REG_DWORD]     = 'REG_DWORD',
    [REG_QWORD]     = 'REG_QWORD',
    [REG_BINARY]    = 'REG_BINARY',
}
function RegKey.RegTypeToString(regType)
    local s = _type_string[tonumber(regType)]
    return s or 'Unknown/unsupported registry type'
end
M.RegTypeToString = RegKey.RegTypeToString

---@return platform.win.RegKey
function M.RegKey(path)
    assert(type(path) == 'string' and #path > 0)
    path = string.gsub(path, '/', '\\')
    path = string.gsub(path, '\\\\', '\\')
    local pos = path:find('\\')
    local parent_str = path:sub(1, pos - 1)
    local sub_str = path:sub(pos + 1)
    local parent = _predefined_hkey_map[parent_str]
    if not parent or #sub_str == 0 then
        error(('invalid path %q'):format(path))
    end
    local ret = {}
    ret['.dtor_proxy'] = ffi.gc(
            ffi.new('int[0]'),
            function()
                RegKey.__gc(ret)
            end)
    setmetatable(ret, { __index = RegKey })
    ret:Create1(ffi.cast('HKEY', parent), sub_str)
    return ret
end

return M
