#pragma once
#include <cstdint>
#include <algorithm>
#include <iostream>

namespace lstg
{
	class RandomWELL512
	{
	public:
		using result_type = uint32_t;
		static constexpr result_type default_seed = 1u;

		template <class Seed_seq>
		using Enable_if_seed_seq_t = typename std::enable_if<
			!std::is_convertible<typename std::remove_cv<Seed_seq>::type, result_type>::value &&
			!std::is_same<typename std::remove_cv<Seed_seq>::type, RandomWELL512>::value, int>::type;

		template <class Seed_seq>
		static constexpr result_type _seed_seq_to_seed(Seed_seq& seq) {
			result_type arr[4]{};
			seq.generate(arr, arr + 4);
			return arr[3];
		}

		static constexpr result_type min() noexcept {
			return 0;
		}
		static constexpr result_type max() noexcept {
			return std::numeric_limits<result_type>::max();
		}
		uint32_t operator()() noexcept {
			return getRandUInt();
		}
		void seed(result_type seed_ = default_seed) noexcept;
		template <class Seed_seq, Enable_if_seed_seq_t<Seed_seq> = 0>
		void seed(Seed_seq seq) noexcept {
			seed(_seed_seq_to_seed(seq));
		}
		void discard(unsigned long long nskip) noexcept;
		friend bool operator==(const RandomWELL512& lhs, const RandomWELL512& rhs) noexcept;
		friend bool operator!=(const RandomWELL512& lhs, const RandomWELL512& rhs) noexcept {
			return !(lhs == rhs);
		}
		template <class E, class T>
		std::basic_istream<E, T>& operator>>(std::basic_istream<E, T>& istr) {
			istr >> index;
			for (int i = 0; i < 16; ++i)
				istr >> state[i];
			return istr;
		}
		template <class E, class T>
		std::basic_ostream<E, T>& operator<<(std::basic_ostream<E, T>& ostr) {
			ostr << index;
			for (int i = 0; i < 16; ++i)
				ostr << ' ' << state[i];
			return ostr;
		}

		uint32_t getSeed() const;
		/** unsigned int in [0, 2^32-1] */
		uint32_t getRandUInt();
		/** unsigned int in [0, hi] */
		uint32_t getRandUInt(uint32_t hi);
		/** random float in [0, 1] */
		float getRandFloat();
		/** random float in [lo, hi] */
		float getRandFloat(float lo, float hi);

		RandomWELL512();
		RandomWELL512(uint32_t seed_);
		template <class Seed_seq, Enable_if_seed_seq_t<Seed_seq> = 0>
		explicit RandomWELL512(Seed_seq& seq)
			: RandomWELL512(_seed_seq_to_seed(seq)) {}
	protected:
		uint32_t state[16] = {};
		uint32_t index = 0;
		uint32_t _seed = 0;
	};
}
