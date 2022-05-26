#include "XInfoware.h"
#include "cocos2d.h"
#if CC_TARGET_PLATFORM == CC_PLATFORM_WIN32
	#include <intrin.h>
	#include "CCUtils-win32.h"
	#define WIN32_LEAN_AND_MEAN
	#include <wbemidl.h>
	#include <windows.h>
	#define INFOWARE_XCR_XFEATURE_ENABLED_MASK _XCR_XFEATURE_ENABLED_MASK
	#pragma comment(lib, "wbemuuid.lib")
#elif (CC_TARGET_PLATFORM == CC_PLATFORM_MAC) || (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
	#include <cpuid.h>
	#include <unistd.h>
	#include <mach/mach.h>
	#include <mach/vm_statistics.h>
	#include <sys/sysctl.h>
	#include <sys/types.h>
	#include <sys/utsname.h>
	#define INFOWARE_XCR_XFEATURE_ENABLED_MASK 0
#else

#if defined(__arm__) || defined(__arm) || defined(__ARM__) || defined(__ARM) || defined(__aarch64__)
#define ARCH_ARM
#else
	#include <cpuid.h>
#endif
	#include <unistd.h>
	#include <sys/utsname.h>
	#define INFOWARE_XCR_XFEATURE_ENABLED_MASK 0
#endif

using namespace infoware;

std::array<int32_t, 4> detail::cpuid(int32_t x)
{
	int32_t out[4];
#if CC_TARGET_PLATFORM == CC_PLATFORM_WIN32
	__cpuidex(out, x, 0);
#elif !defined(ARCH_ARM)
	__cpuid_count(x, 0, out[0], out[1], out[2], out[3]);
#endif
	return { out[0],out[1],out[2],out[3] };
}

uint64_t detail::xgetbv(uint32_t x)
{
#if CC_TARGET_PLATFORM == CC_PLATFORM_WIN32
	return _xgetbv(x);
#elif !defined(ARCH_ARM)
	std::uint32_t eax, edx;
	__asm__ __volatile__("xgetbv" : "=a"(eax), "=d"(edx) : "c"(x));
	return ((uint64_t)edx << 32) | eax;
#else
	return 0;
#endif
}

#if (CC_TARGET_PLATFORM == CC_PLATFORM_MAC) || (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
// Requires data.size() >= sizeof(T)
template <class T>
static std::pair<bool, T> deconstruct_specific_int(const std::vector<char>& data) {
	std::pair<bool, T> out{ true, {} };
	std::memcpy(&out.second, data.data(), sizeof(out.second));
	return out;
}

#define SYSCTL_IMPL(fname, ...)                          \
	std::size_t len{};                                   \
	if(fname(__VA_ARGS__, nullptr, &len, nullptr, 0))    \
		return {};                                       \
	std::vector<char> ret(len);                          \
	if(fname(__VA_ARGS__, ret.data(), &len, nullptr, 0)) \
		return {};                                       \
	return ret

std::vector<char> detail::sysctl(const char* name) {
	SYSCTL_IMPL(::sysctlbyname, name);
}
std::vector<char> detail::sysctl(int mib_0, int mib_1) {
	int name[2]{ mib_0, mib_1 };
	SYSCTL_IMPL(::sysctl, name, sizeof(name) / sizeof(*name));
}
std::pair<bool, std::uint64_t> detail::deconstruct_sysctl_int(const std::vector<char>& data) {
	switch (data.size()) {
		case sizeof(std::uint16_t) :
			return deconstruct_specific_int<std::uint16_t>(data);
		case sizeof(std::uint32_t) :
			return deconstruct_specific_int<std::uint32_t>(data);
		case sizeof(std::uint64_t) :
			return deconstruct_specific_int<std::uint64_t>(data);
		default:
			return {};
	}
}
#else
std::vector<char> detail::sysctl(const char*) {
	return {};
}
std::vector<char> detail::sysctl(int, int) {
	return {};
}
std::pair<bool, std::uint64_t> detail::deconstruct_sysctl_int(const std::vector<char>&) {
	return {};
}
#endif

#if CC_TARGET_PLATFORM == CC_PLATFORM_WIN32
std::string detail::narrowen_winstring(const wchar_t* wstr) {
	if (!wstr)
		return {};
	return cocos2d::StringWideCharToUtf8({ wstr, std::wcslen(wstr) });
}
std::string detail::narrowen_bstring(const wchar_t* bstr) {
	if (!bstr)
		return {};
	return cocos2d::StringWideCharToUtf8({ bstr, SysStringLen(const_cast<BSTR>(bstr)) });
}
#else
std::string detail::narrowen_winstring(const wchar_t*) {
	return {};
}
std::string detail::narrowen_bstring(const wchar_t*) {
	return {};
}
#endif

// quantities

#if CC_TARGET_PLATFORM == CC_PLATFORM_WIN32
static std::vector<SYSTEM_LOGICAL_PROCESSOR_INFORMATION> cpuinfo_buffer() {
	std::vector<SYSTEM_LOGICAL_PROCESSOR_INFORMATION> buffer;
	DWORD byte_count = 0;
	GetLogicalProcessorInformation(nullptr, &byte_count);
	buffer.resize(byte_count / sizeof(SYSTEM_LOGICAL_PROCESSOR_INFORMATION));
	GetLogicalProcessorInformation(buffer.data(), &byte_count);
	return buffer;
}
cpu::quantities_t cpu::quantities() {
	cpu::quantities_t ret{};
	for (auto&& info : cpuinfo_buffer())
		switch (info.Relationship) {
		case RelationProcessorCore:
			++ret.physical;
			// A hyperthreaded core supplies more than one logical processor.
			ret.logical += static_cast<std::uint32_t>(std::bitset<sizeof(ULONG_PTR) * 8>(static_cast<std::uintptr_t>(info.ProcessorMask)).count());
			break;
		case RelationProcessorPackage:
			// Logical processors share a physical package.
			++ret.packages;
			break;
		default:
			break;
		}
	return ret;
}
#elif (CC_TARGET_PLATFORM == CC_PLATFORM_MAC) || (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
cpu::quantities_t cpu::quantities() {
	cpu::quantities_t ret{};
	const auto ctl_thread_data = detail::sysctl("machdep.cpu.thread_count");
	if (!ctl_thread_data.empty()) {
		const auto thread_data = detail::deconstruct_sysctl_int(ctl_thread_data);
		if (thread_data.first)
			ret.logical = thread_data.second;
	}
	const auto ctl_core_data = detail::sysctl("machdep.cpu.core_count");
	if (!ctl_core_data.empty()) {
		const auto core_data = detail::deconstruct_sysctl_int(ctl_core_data);
		if (core_data.first)
			ret.physical = core_data.second;
	}
	const auto ctl_packages_data = detail::sysctl("hw.packages");
	if (!ctl_packages_data.empty()) {
		const auto packages_data = detail::deconstruct_sysctl_int(ctl_packages_data);
		if (packages_data.first)
			ret.packages = packages_data.second;
	}
	return ret;
}
#else
cpu::quantities_t cpu::quantities() {
	cpu::quantities_t ret{};
	ret.logical = sysconf(_SC_NPROCESSORS_ONLN);
	std::ifstream cpuinfo("/proc/cpuinfo");
	if (!cpuinfo.is_open() || !cpuinfo)
		return ret;
	std::vector<unsigned int> package_ids;
	for (std::string line; std::getline(cpuinfo, line);)
		if (line.find("physical id") == 0) {
			const auto physical_id = std::strtoul(line.c_str() + line.find_first_of("1234567890"), nullptr, 10);
			if (std::find(package_ids.begin(), package_ids.end(), physical_id) == package_ids.end())
				package_ids.emplace_back(physical_id);
		}
	ret.packages = package_ids.size();
	ret.physical = ret.logical / ret.packages;
	return ret;
}
#endif

std::string cpu::vendor_id()
{
#ifndef ARCH_ARM
	char name[13];
	const auto info = detail::cpuid(0);
	std::memcpy(name + 0, &info[1], 4);
	std::memcpy(name + 4, &info[3], 4);
	std::memcpy(name + 8, &info[2], 4);
	name[12] = '\0';
	return name;
#elif defined(__aarch64__)
	return "ARM64";
#else
	return "ARM";
#endif // !ARCH_ARM
}

// frequency

#if CC_TARGET_PLATFORM == CC_PLATFORM_WIN32
uint64_t cpu::frequency() noexcept {
	HKEY hkey;
	if (RegOpenKeyExA(HKEY_LOCAL_MACHINE, R"(HARDWARE\DESCRIPTION\System\CentralProcessor\0)", 0, KEY_READ, &hkey)) {
		// Fallback
		LARGE_INTEGER freq;
		QueryPerformanceFrequency(&freq);
		return freq.QuadPart * 1000;
	}

	DWORD freq_mhz;
	DWORD freq_mhz_len = sizeof(freq_mhz);
	if (RegQueryValueExA(hkey, "~MHz", nullptr, nullptr, static_cast<LPBYTE>(static_cast<void*>(&freq_mhz)), &freq_mhz_len))
		return {};

	return (uint64_t)freq_mhz * 1000000;
}

#elif (CC_TARGET_PLATFORM == CC_PLATFORM_MAC) || (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
uint64_t cpu::frequency() noexcept {
	const auto ctl_data = detail::sysctl("hw.cpufrequency");
	if (ctl_data.empty())
		return 0;
	const auto data = detail::deconstruct_sysctl_int(ctl_data);
	if (!data.first)
		return 0;
	return data.second;
}
#else
uint64_t cpu::frequency() noexcept {
	std::ifstream cpuinfo("/proc/cpuinfo");
	if (!cpuinfo.is_open() || !cpuinfo)
		return 0;
	for (std::string line; std::getline(cpuinfo, line);)
		if (line.find("cpu MHz") == 0) {
			const auto colon_id = line.find_first_of(':');
			return static_cast<std::uint64_t>(std::strtod(line.c_str() + colon_id + 1, nullptr) * 1000000);
		}
	return 0;
}
#endif

// vendor

#if CC_TARGET_PLATFORM == CC_PLATFORM_WIN32
template <unsigned int IdentLen>
static std::string central_processor_subkey(const char* key) {
	HKEY hkey;
	if (RegOpenKeyExA(HKEY_LOCAL_MACHINE, R"(HARDWARE\DESCRIPTION\System\CentralProcessor\0)", 0, KEY_READ, &hkey))
		return {};
	char identifier[IdentLen];
	DWORD identifier_len = sizeof(identifier);
	LPBYTE lpdata = static_cast<LPBYTE>(static_cast<void*>(&identifier[0]));
	if (RegQueryValueExA(hkey, key, nullptr, nullptr, lpdata, &identifier_len))
		return {};
	return identifier;
}
std::string cpu::vendor() {
	return central_processor_subkey<12 + 1>("VendorIdentifier");
}
std::string cpu::model_name() {
	return central_processor_subkey<64 + 1>("ProcessorNameString");
}
#elif (CC_TARGET_PLATFORM == CC_PLATFORM_MAC) || (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
static std::string sysctl_value(const char* subkey) {
	auto ctl_data = detail::sysctl((std::string("machdep.cpu.") + subkey).c_str());
	if (ctl_data.empty())
		return {};
	else
		return ctl_data.data();
}
std::string cpu::vendor() {
	return sysctl_value("vendor");
}
std::string cpu::model_name() {
	return sysctl_value("brand_string");
}
#else
static std::string cpuinfo_value(const char* key) {
	std::ifstream cpuinfo("/proc/cpuinfo");
	if (!cpuinfo.is_open() || !cpuinfo)
		return {};
	for (std::string line; std::getline(cpuinfo, line);)
		if (line.find(key) == 0) {
			const auto colon_id = line.find_first_of(':');
			const auto nonspace_id = line.find_first_not_of(" \t", colon_id + 1);
			return line.c_str() + nonspace_id;
		}
	return {};
}
std::string cpu::vendor() {
	return cpuinfo_value("vendor");
}
std::string cpu::model_name() {
	return cpuinfo_value("model name");
}
#endif

// supported_instruction_sets

static bool has_os_avx() {
#ifndef ARCH_ARM
	bool avxsupport = false;
	const auto cpuinfo = detail::cpuid(1);
	bool osusesxsave_restore = (cpuinfo[2] & (1 << 27)) != 0;
	bool cpusupportsavx = (cpuinfo[2] & (1 << 28)) != 0;
	if (osusesxsave_restore && cpusupportsavx) {
		const auto xcrFeatureMask = detail::xgetbv(INFOWARE_XCR_XFEATURE_ENABLED_MASK);
		avxsupport = (xcrFeatureMask & 0x06) == 0x06;
	}
	return avxsupport;
#else
	return false;
#endif // !ARCH_ARM
}
static bool has_os_avx_512() {
#ifndef ARCH_ARM
	if (!has_os_avx())
		return false;
	const auto xcrFeatureMask = detail::xgetbv(INFOWARE_XCR_XFEATURE_ENABLED_MASK);
	return (xcrFeatureMask & 0xE6) == 0xE6;
#else
	return false;
#endif // !ARCH_ARM
}

std::vector<cpu::instruction_set_t> cpu::supported_instruction_sets() {
#ifndef ARCH_ARM
	auto info = detail::cpuid(0);
	const auto idinfo = info[0];
	info = detail::cpuid(0x80000000);
	const std::uint32_t extendedidinfo = info[0];
	std::vector<cpu::instruction_set_t> supported;
	supported.reserve(64);

#define ADD_SET_IF(infoindex, bitindex, name)      \
	if((info[(infoindex)] & (1 << (bitindex))) != 0) \
		supported.push_back(cpu::instruction_set_t::name);

	if (idinfo >= 0x00000001) {
		info = detail::cpuid(0x00000001);

		ADD_SET_IF(3, 22, mmx_extended);
		ADD_SET_IF(3, 23, mmx);
		ADD_SET_IF(3, 25, sse);
		ADD_SET_IF(3, 26, sse2);

		ADD_SET_IF(2, 0, sse3);
		ADD_SET_IF(2, 9, ssse3);
		ADD_SET_IF(2, 19, sse41);
		ADD_SET_IF(2, 20, sse42);
		ADD_SET_IF(2, 25, aes);
		ADD_SET_IF(2, 28, fma3);
		ADD_SET_IF(2, 12, rd_rand);
	}
	if (idinfo >= 0x00000007) {
		info = detail::cpuid(0x00000007);
		if (has_os_avx()) {
			// Both must be present to have AVX
			ADD_SET_IF(1, 5, avx2);
		}
		ADD_SET_IF(1, 4, hle);

		ADD_SET_IF(1, 3, bmi1);
		ADD_SET_IF(1, 8, bmi2);
		ADD_SET_IF(1, 19, adx);
		ADD_SET_IF(1, 14, mpx);
		ADD_SET_IF(1, 29, sha);

		if (has_os_avx_512()) {
			supported.push_back(cpu::instruction_set_t::avx_512);

			ADD_SET_IF(1, 16, avx_512_f);
			ADD_SET_IF(1, 28, avx_512_cd);
			ADD_SET_IF(1, 26, avx_512_pf);
			ADD_SET_IF(1, 27, avx_512_er);
			ADD_SET_IF(1, 31, avx_512_vl);
			ADD_SET_IF(1, 30, avx_512_bw);
			ADD_SET_IF(1, 17, avx_512_dq);
			ADD_SET_IF(1, 21, avx_512_ifma);
			ADD_SET_IF(2, 1, avx_512_vbmi);
		}

		ADD_SET_IF(2, 0, prefetch_wt1);
	}
	if (extendedidinfo >= 0x80000001) {
		info = detail::cpuid(0x80000001);

		ADD_SET_IF(3, 29, x64);
		ADD_SET_IF(3, 0, x87_fpu);
		ADD_SET_IF(3, 30, s3d_now);
		ADD_SET_IF(3, 31, s3d_now_extended);
		ADD_SET_IF(3, 29, x64);
		ADD_SET_IF(2, 5, bmi1);
		ADD_SET_IF(2, 6, bmi2);
		ADD_SET_IF(2, 16, adx);
		ADD_SET_IF(2, 11, mpx);
	}
#undef ADD_SET_IF
	return supported;
#else
	return {};
#endif // !ARCH_ARM
}

// instruction_set_supported

#if CC_TARGET_PLATFORM == CC_PLATFORM_WIN32
bool cpu::instruction_set_supported(cpu::instruction_set_t set) {
	std::vector<cpu::instruction_set_t> ises = supported_instruction_sets();
	if (std::find(ises.cbegin(), ises.cend(), set) != ises.cend())
		return true;
	// TODO: is this necessary if we detect things with xgetbv and cpuid?
	// That is, AVX usually needs to have both OS support alongside
	DWORD feature;
	switch (set) {
	case cpu::instruction_set_t::s3d_now:
		feature = PF_3DNOW_INSTRUCTIONS_AVAILABLE;
		break;
	case cpu::instruction_set_t::mmx:
		feature = PF_MMX_INSTRUCTIONS_AVAILABLE;
		break;
	case cpu::instruction_set_t::sse:
		feature = PF_XMMI_INSTRUCTIONS_AVAILABLE;
		break;
	case cpu::instruction_set_t::sse2:
		feature = PF_XMMI64_INSTRUCTIONS_AVAILABLE;
		break;
	case cpu::instruction_set_t::sse3:
		feature = PF_SSE3_INSTRUCTIONS_AVAILABLE;
		break;
	case cpu::instruction_set_t::avx:
		feature = PF_XMMI64_INSTRUCTIONS_AVAILABLE;
		break;
	default:
		return false;
	}
	return IsProcessorFeaturePresent(feature) != 0;
}
#elif (CC_TARGET_PLATFORM == CC_PLATFORM_MAC) || (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
static std::pair<const char* const*, const char* const*> instruction_set_to_names(cpu::instruction_set_t set) {
	static const char* mmx[] = { "MMX" };
	static const char* threednow[] = { "3DNOW", "3DNOWEXT" };
	static const char* sse[] = { "SSE" };
	static const char* sse2[] = { "SSE2" };
	static const char* sse3[] = { "SSSE3", "SSE3" };
	static const char* avx[] = { "AVX" };

#define HANDLED_CASE(iset, variable)        \
	case cpu::instruction_set_t::iset: \
		return {variable, variable + (sizeof(variable) / sizeof(*variable))};

	switch (set) {
		HANDLED_CASE(s3d_now, threednow)
		HANDLED_CASE(mmx, mmx)
		HANDLED_CASE(sse, sse)
		HANDLED_CASE(sse2, sse2)
		HANDLED_CASE(sse3, sse3)
		HANDLED_CASE(avx, avx)
		default:
			return { nullptr, nullptr };
	}
#undef HANDLED_CASE
}
bool cpu::instruction_set_supported(cpu::instruction_set_t set) {
	const auto ises = supported_instruction_sets();
	if (std::find(ises.begin(), ises.end(), set) != ises.cend())
		return true;
	const auto set_names = instruction_set_to_names(set);
	if (!set_names.first)
		return false;
	auto ctl_data = detail::sysctl("machdep.cpu.features");
	if (ctl_data.empty())
		return 0;
	for (auto cur_name = std::strtok(ctl_data.data(), " \t\n"); cur_name; cur_name = std::strtok(nullptr, " \t\n"))
		if (std::any_of(set_names.first, set_names.second, [&](const char* name) { return name == cur_name; }))
			return true;
	return false;
}
#else
static std::pair<const char* const*, const char* const*> instruction_set_to_names(cpu::instruction_set_t set) {
	static const char* mmx[] = { "mmx" };
	static const char* threednow[] = { "3dnow", "3dnowext" };
	static const char* sse[] = { "sse" };
	static const char* sse2[] = { "sse2" };
	static const char* sse3[] = { "ssse3", "sse3" };
	static const char* avx[] = { "avx" };

#define HANDLED_CASE(iset, variable)        \
	case cpu::instruction_set_t::iset: \
		return {variable, variable + (sizeof(variable) / sizeof(*variable))};

	switch (set) {
		HANDLED_CASE(s3d_now, threednow)
		HANDLED_CASE(mmx, mmx)
		HANDLED_CASE(sse, sse)
		HANDLED_CASE(sse2, sse2)
		HANDLED_CASE(sse3, sse3)
		HANDLED_CASE(avx, avx)
		default:
			return { nullptr, nullptr };
	}
#undef HANDLED_CASE
}
bool cpu::instruction_set_supported(cpu::instruction_set_t set) {
	const auto ises = supported_instruction_sets();
	if (std::find(ises.begin(), ises.end(), set) != ises.cend())
		return true;
	const auto set_names = instruction_set_to_names(set);
	if (!set_names.first)
		return false;
	std::ifstream cpuinfo("/proc/cpuinfo");
	if (!cpuinfo.is_open() || !cpuinfo)
		return false;
	for (std::string tmp; std::getline(cpuinfo, tmp);)
		if (tmp.find("flags") == 0) {
			const auto colon_id = tmp.find_first_of(':');
			std::istringstream is(tmp.c_str() + colon_id + 1);
			while (is >> tmp)
				if (std::any_of(set_names.first, set_names.second, [&](const char* name) { return tmp == name; }))
					return true;
		}
	return false;
}
#endif

// memory

#if CC_TARGET_PLATFORM == CC_PLATFORM_WIN32
system::memory_t system::memory() noexcept {
	MEMORYSTATUSEX mem;
	mem.dwLength = sizeof(mem);
	if (!GlobalMemoryStatusEx(&mem))
		return { 0,0,0,0 };
	return { mem.ullAvailPhys, mem.ullTotalPhys, mem.ullAvailVirtual, mem.ullTotalVirtual };
}
#elif (CC_TARGET_PLATFORM == CC_PLATFORM_MAC) || (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
system::memory_t system::memory() noexcept {
	system::memory_t ret{};
	const auto host = mach_host_self();
	const auto ctl_ram = detail::sysctl(CTL_HW, HW_MEMSIZE);
	if (!ctl_ram.empty()) {
		const auto ram = detail::deconstruct_sysctl_int(ctl_ram);
		if (ram.first)
			ret.virtual_total = ram.second;
	}
	vm_statistics64 stats;
	natural_t count = HOST_VM_INFO64_COUNT;
	if (host_statistics64(host, HOST_VM_INFO64, reinterpret_cast<host_info64_t>(&stats), &count) == KERN_SUCCESS)
		ret.virtual_available = stats.free_count * getpagesize();
	ret.physical_total = ret.virtual_total;
	ret.physical_available = ret.virtual_available;
	return ret;
}
#else
system::memory_t system::memory() noexcept {
	std::ifstream meminfo("/proc/meminfo");
	if (!meminfo.is_open() || !meminfo)
		return {};
	system::memory_t ret;
	for (std::string line; std::getline(meminfo, line);) {
		const auto colon_id = line.find_first_of(':');
		const auto value = std::strtoul(line.c_str() + colon_id + 1, nullptr, 10) * 1024;
		if (line.find("MemTotal") == 0)
			ret.physical_total = value;
		else if (line.find("MemAvailable") == 0)
			ret.physical_available = value;
		else if (line.find("VmallocTotal") == 0)
			ret.virtual_total = value;
		else if (line.find("VmallocUsed") == 0)
			ret.virtual_available = ret.virtual_total - value;
	}
	return ret;
}
#endif

// kernel_info

#if CC_TARGET_PLATFORM == CC_PLATFORM_WIN32
system::kernel_info_t system::kernel_info() {
	std::string path;
	path.resize(GetSystemDirectoryA(nullptr, 0) - 1);
	GetSystemDirectoryA(&path[0], static_cast<UINT>(path.size() + 1));
	path += "\\kernel32.dll";

	const auto ver_info_len = GetFileVersionInfoSizeA(path.c_str(), nullptr);
	auto ver_info = std::make_unique<std::uint8_t[]>(ver_info_len);
	GetFileVersionInfoA(path.c_str(), 0, ver_info_len, ver_info.get());

	VS_FIXEDFILEINFO* file_version;
	unsigned int file_version_len;
	VerQueryValueA(ver_info.get(), "", reinterpret_cast<void**>(&file_version), &file_version_len);

	return { system::kernel_t::windows_nt, HIWORD(file_version->dwProductVersionMS), LOWORD(file_version->dwProductVersionMS),
			HIWORD(file_version->dwProductVersionLS), LOWORD(file_version->dwProductVersionLS) };
}
#else
system::kernel_info_t system::kernel_info() {
	utsname uts;
	uname(&uts);

	char* marker = uts.release;
	const std::uint32_t major = std::strtoul(marker, &marker, 10);
	const std::uint32_t minor = std::strtoul(marker + 1, &marker, 10);
	const std::uint32_t patch = std::strtoul(marker + 1, &marker, 10);
	const std::uint32_t build_number = std::strtoul(marker + 1, nullptr, 10);

	auto kernel = system::kernel_t::unknown;
	if (!std::strcmp(uts.sysname, "Linux"))
		kernel = system::kernel_t::linux;
	else if (!std::strcmp(uts.sysname, "Darwin"))
		kernel = system::kernel_t::darwin;

	return { kernel, major, minor, patch, build_number };
}
#endif

// os_info

#if CC_TARGET_PLATFORM == CC_PLATFORM_WIN32
static std::string version_name() {
	auto err = CoInitializeEx(nullptr, COINIT_MULTITHREADED);
	if (FAILED(err) && err != RPC_E_CHANGED_MODE)
		return {};
	detail::quickscope_wrapper com_uninitialiser{ CoUninitialize };

	const auto init_result =
		CoInitializeSecurity(nullptr, -1, nullptr, nullptr, RPC_C_AUTHN_LEVEL_DEFAULT, RPC_C_IMP_LEVEL_IMPERSONATE, nullptr, EOAC_NONE, nullptr);
	if (FAILED(init_result) && init_result != RPC_E_TOO_LATE)
		return {};

	IWbemLocator* wbem_loc_raw;
	if (FAILED(CoCreateInstance(CLSID_WbemLocator, 0, CLSCTX_INPROC_SERVER, IID_IWbemLocator, reinterpret_cast<void**>(&wbem_loc_raw))))
		return {};
	std::unique_ptr<IWbemLocator, detail::release_deleter> wbem_loc(wbem_loc_raw);

	IWbemServices* wbem_services_raw;
	wchar_t network_resource[] = LR"(ROOT\CIMV2)";
	if (FAILED(wbem_loc->ConnectServer(network_resource, nullptr, nullptr, 0, 0, 0, 0, &wbem_services_raw)))
		return {};
	std::unique_ptr<IWbemServices, detail::release_deleter> wbem_services(wbem_services_raw);

	if (FAILED(CoSetProxyBlanket(wbem_services.get(), RPC_C_AUTHN_WINNT, RPC_C_AUTHZ_NONE, nullptr, RPC_C_AUTHN_LEVEL_CALL, RPC_C_IMP_LEVEL_IMPERSONATE, nullptr,
		EOAC_NONE)))
		return {};

	IEnumWbemClassObject* query_iterator_raw;
	wchar_t query_lang[] = L"WQL";
	wchar_t query[] = L"SELECT Name FROM Win32_OperatingSystem";
	if (FAILED(wbem_services->ExecQuery(query_lang, query, WBEM_FLAG_FORWARD_ONLY | WBEM_FLAG_RETURN_IMMEDIATELY, nullptr, &query_iterator_raw)))
		return {};
	std::unique_ptr<IEnumWbemClassObject, detail::release_deleter> query_iterator(query_iterator_raw);

	std::string ret;
	while (query_iterator) {
		IWbemClassObject* value_raw;
		unsigned long iter_result;

		query_iterator->Next(static_cast<LONG>(WBEM_INFINITE), 1, &value_raw, &iter_result);
		if (!iter_result)
			break;
		std::unique_ptr<IWbemClassObject, detail::release_deleter> value(value_raw);

		VARIANT val;
		value->Get(L"Name", 0, &val, 0, 0);
		detail::quickscope_wrapper val_destructor{ [&] { VariantClear(&val); } };

		ret = detail::narrowen_bstring(val.bstrVal);
	}
	return ret.substr(0, ret.find('|'));
}
system::OS_info_t system::os_info() {
	const auto kernel_version = system::kernel_info();
	return { "Windows NT", version_name(), kernel_version.major, kernel_version.minor, kernel_version.patch, kernel_version.build_number };
}
#elif (CC_TARGET_PLATFORM == CC_PLATFORM_MAC) || (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
system::OS_info_t system::os_info() {
	auto ctl_ostype_data = detail::sysctl("kern.ostype");
	auto ctl_version_data = detail::sysctl("kern.version");

	auto ctl_osrelease_data = detail::sysctl("kern.osrelease");
	char buf{};
	char* osrelease_marker = ctl_osrelease_data.empty() ? &buf : ctl_osrelease_data.data();

	const auto ctl_osrevision_data = detail::sysctl("kern.osrevision");
	unsigned int build_number{};
	if (!ctl_osrevision_data.empty()) {
		const auto osrevision_data = detail::deconstruct_sysctl_int(ctl_osrevision_data);
		if (osrevision_data.first)
			build_number = osrevision_data.second;
	}

	return { ctl_ostype_data.empty() ? "" : ctl_ostype_data.data(),                                 //
			ctl_version_data.empty() ? "" : ctl_version_data.data(),                               //
			static_cast<unsigned int>(std::strtoul(osrelease_marker, &osrelease_marker, 10)),      //
			static_cast<unsigned int>(std::strtoul(osrelease_marker + 1, &osrelease_marker, 10)),  //
			static_cast<unsigned int>(std::strtoul(osrelease_marker + 1, nullptr, 10)),            //
			build_number };
}
#else
static system::OS_info_t lsb_release(std::ifstream& release) {
	system::OS_info_t ret{};

	for (std::string line; std::getline(release, line);)
		if (line.find("DISTRIB_ID") == 0)
			ret.name = line.substr(line.find('=') + 1);
		else if (line.find("DISTRIB_RELEASE") == 0) {
			char* marker = &line[line.find('=') + 1];
			ret.major = std::strtoul(marker, &marker, 10);
			ret.minor = std::strtoul(marker + 1, &marker, 10);
			ret.patch = std::strtoul(marker + 1, &marker, 10);
			ret.build_number = std::strtoul(marker + 1, nullptr, 10);
		}
		else if (line.find("DISTRIB_DESCRIPTION") == 0) {
			const auto start_idx = line.find('"') + 1;
			const auto end_idx = line.size() - 1;
			ret.full_name = line.substr(start_idx, end_idx - start_idx);
		}

	return ret;
}
static void trim_quotes(std::string& in) {
	if (in.empty())
		return;

	if (in.back() == '"')
		in.pop_back();

	if (in.front() == '"')
		in.erase(in.begin());
}
// https://www.linux.org/docs/man5/os-release.html
system::OS_info_t system::os_info() {
	std::ifstream release("/etc/os-release");

	if (!release.is_open() || !release) {
		release.open("/usr/lib/os-release", std::ios::in);
		if (!release.is_open() || !release) {
			release.open("/etc/lsb-release", std::ios::in);
			if (!release.is_open() || !release)
				return {};
			else
				return lsb_release(release);
		}
	}

	system::OS_info_t ret{};

	for (std::string line; std::getline(release, line);)
		if (line.find("NAME") == 0)
			ret.name = line.substr(line.find('=') + 1);
		else if (line.find("PRETTY_NAME") == 0)
			ret.full_name = line.substr(line.find('=') + 1);
		else if (line.find("VERSION_ID") == 0) {
			char* marker = &line[line.find('=') + 1];
			if (marker[0] == '"')
				++marker;
			ret.major = std::strtoul(marker, &marker, 10);
			if (marker[0] && marker[0] != '"')
				ret.minor = std::strtoul(marker + 1, &marker, 10);
			if (marker[0] && marker[0] != '"')
				ret.patch = std::strtoul(marker + 1, &marker, 10);
			if (marker[0] && marker[0] != '"')
				ret.build_number = std::strtoul(marker + 1, nullptr, 10);
		}

	trim_quotes(ret.name);
	trim_quotes(ret.full_name);

	return ret;
}
#endif
