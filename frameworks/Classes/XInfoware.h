#pragma once
#include <algorithm>
#include <array>
#include <bitset>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <functional>
#include <memory>
#include <string>
#include <sstream>
#include <vector>
#include <utility>

// https://github.com/ThePhD/infoware

namespace infoware
{
	namespace detail
	{
		std::array<int32_t, 4> cpuid(int32_t x);
		uint64_t xgetbv(uint32_t x);
		std::vector<char> sysctl(const char* name);
		std::vector<char> sysctl(int mib_0, int mib_1);
		std::pair<bool, std::uint64_t> deconstruct_sysctl_int(const std::vector<char>& data);
		std::string narrowen_bstring(const wchar_t* wstr);
		std::string narrowen_winstring(const wchar_t* bstr);

		struct release_deleter {
			template <typename T>
			void operator()(T* p) const {
				p->Release();
			}
		};
		struct quickscope_wrapper {
			std::function<void()> func;
			quickscope_wrapper(const quickscope_wrapper&) = delete;
			~quickscope_wrapper() {
				if (func)
					func();
			}
		};
	}

	namespace cpu
	{
		struct quantities_t {
			std::uint32_t logical;
			std::uint32_t physical;
			std::uint32_t packages;
		};
		enum class instruction_set_t {
			s3d_now, s3d_now_extended,
			mmx, mmx_extended,
			sse, sse2, sse3, ssse3, sse4a, sse41, sse42, aes,
			avx, avx2,
			avx_512, avx_512_f, avx_512_cd,
			avx_512_pf, avx_512_er, avx_512_vl,
			avx_512_bw, avx_512_bq, avx_512_dq,
			avx_512_ifma, avx_512_vbmi,
			hle,
			bmi1, bmi2, adx, mpx, sha, prefetch_wt1,
			fma3, fma4,
			xop,
			rd_rand,
			x64,
			x87_fpu,
		};

		quantities_t quantities();
		uint64_t frequency() noexcept;
		std::string vendor_id();
		std::string vendor();
		std::string model_name();
		bool instruction_set_supported(instruction_set_t set);
		std::vector<instruction_set_t> supported_instruction_sets();
	}

	namespace system
	{
		struct memory_t {
			std::uint64_t physical_available;
			std::uint64_t physical_total;
			std::uint64_t virtual_available;
			std::uint64_t virtual_total;
		};
#ifdef linux
#undef linux
#endif
		enum class kernel_t {
			windows_nt,
			linux,
			darwin,
			unknown,
		};
		struct kernel_info_t {
			kernel_t variant;
			std::uint32_t major;
			std::uint32_t minor;
			std::uint32_t patch;
			std::uint32_t build_number;
		};
		struct OS_info_t {
			std::string name;
			std::string full_name;
			unsigned int major;
			unsigned int minor;
			unsigned int patch;
			unsigned int build_number;
		};
		
		memory_t memory() noexcept;
		kernel_info_t kernel_info();
		OS_info_t os_info();
	}
}
