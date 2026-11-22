/*
	meow_fft. My Easy Oresome Wonderful Fast Fourier Transform.
	Copyright (C) 2017 Richard Maxwell <jodi.the.tigger@gmail.com>

	Permission to use, copy, modify, and/or distribute this software for any
	purpose with or without fee is hereby granted.

	THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
	WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
	MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY
	SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
	WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION
	OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN
	CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
*/

#ifndef MEOW_FFT
#define MEOW_FFT

#include <stdlib.h>
// for size_t

#ifdef __cplusplus
extern "C" {
#endif

	// C-API -----------------------------------------------------------------------

	typedef struct Meow_FFT_Complex
	{
		float r;
		float j;
	}
	Meow_FFT_Complex;

	struct Meow_FFT_Workset;
	struct Meow_FFT_Workset_Real;

	size_t meow_fft_generate_workset
	(
		int                      N
		, struct Meow_FFT_Workset* workset
	);
	// returns the size of the workset if null is passed.

	size_t meow_fft_generate_workset_real
	(
		int                           N
		, struct Meow_FFT_Workset_Real* workset
	);
	// returns the size of the workset if null is passed.

	unsigned meow_fft_is_slow(const struct Meow_FFT_Workset*      workset);
	unsigned meow_fft_is_slow_real(const struct Meow_FFT_Workset_Real* workset);
	// returns non-zero if the fft has a slow dft in any one of its stages.

	// C-API (ffts) ----------------------------------------------------------------

	// NOTES:
	// countof(out) == countof(in).
	// In order to do that I have mixed out[0] with out[N/2]. That is:
	// out[0].r == out[0].r, out[0].j = out[N/2].r


	void meow_fft_real
	(
		const struct Meow_FFT_Workset_Real* workset
		, const float*                        in
		, Meow_FFT_Complex*                   out
	);

	void meow_fft_real_i
	(
		const struct Meow_FFT_Workset_Real* workset
		, const Meow_FFT_Complex*             in
		, Meow_FFT_Complex*                   temp
		, float*                              out
	);

	void meow_fft
	(
		const struct Meow_FFT_Workset* data
		, const Meow_FFT_Complex*        in
		, Meow_FFT_Complex*              out
	);

	void meow_fft_i
	(
		const struct Meow_FFT_Workset* data
		, const Meow_FFT_Complex*        in
		, Meow_FFT_Complex*              out
	);

	// -----------------------------------------------------------------------------

#ifdef __cplusplus
}
#endif

#endif // MEOW_FFT

// bash script used to generate radix N codelets from fftw that suit this code.
// since my tests run slower with > 8 radix, I hand modified the radix 8
// generated (function signature) instead of updating this code.
#if 0
#!/bin/sh
# <command> N [-1|1] [|_i]

cat << EOF

static void meow_radix_${ 1 }_dit${ 3 }
(
	meow_fft_complex* out
	, const float*  W
	, unsigned      count
	)
{
	EOF

#// First loop doesn't use twiddles
		. / gen_notw.native - n ${ 1 } -standalone - sign ${ 2 }                               \
		| sed  's/E /float /g'                                                     \
		| sed '/INT.*/d'                                                           \
		| sed - r 's/r[io]\[(.+)]/out\[\1\].r/g'                                    \
		| sed - r 's/i[io]\[(.+)]/out\[\1\].j/g'                                    \
		| sed '/for (.*).*/d'                                                      \
		| sed - r 's/WS\(.., (.*)\)/count * \1/g'                                   \
		| sed - r 's/FMA\((.+), (.+), (.+)\)/\(\1 * \2\) + \(\3\)/g'                \
		| sed - r 's/FMS\((.+), (.+), (.+)\)/\(\1 * \2\) - \(\3\)/g'                \
		| sed - r 's/FNMA\((.+), (.+), (.+)\)/-\(\1 * \2\) + \(\3\)/g'              \
		| sed - r 's/FNMS\((.+), (.+), (.+)\)/\(\3\) - \(\1 * \2\)/g'               \
		| sed - r 's/DK\((.+), (.+)\);/static const float \1  = \2;/g'              \
		| head - n - 3                                                               \
		| tail - n + 9

		echo ""
		echo "out = out + 1;"
		echo ""

		. / gen_twiddle.native - n ${ 1 } -standalone - sign ${ 2 } -dit - with - ms 1            \
		| sed  's/E /float /g'                                                     \
		| sed 's/INT /unsigned /g'                                                 \
		| sed - r 's/r[io]\[(.+)]/out\[\1\].r/g'                                    \
		| sed - r 's/i[io]\[(.+)]/out\[\1\].j/g'                                    \
		| sed 's/, MAKE_VOLATILE_STRIDE(.*))/)/g'                                  \
		| sed 's/, MAKE_VOLATILE_STRIDE(.*)//g'                                    \
		| sed - r 's/WS\(.., (.*)\)/count * \1/g'                                   \
		| sed - r 's/FMA\((.+), (.+), (.+)\)/\(\1 * \2\) + \(\3\)/g'                \
		| sed - r 's/FMS\((.+), (.+), (.+)\)/\(\1 * \2\) - \(\3\)/g'                \
		| sed - r 's/FNMA\((.+), (.+), (.+)\)/-\(\1 * \2\) + \(\3\)/g'              \
		| sed - r 's/FNMS\((.+), (.+), (.+)\)/\(\3\) - \(\1 * \2\)/g'               \
		| sed '/DK(.*);/d'                                                         \
		| sed 's/ri = ri + 1, ii = ii + 1,/out = out + 1,/g'                       \
		| sed 's/m = mb, W = W + (mb * .*);/m = 1;/g'                              \
		| sed - r 's/(for \(.*\)).*/\1\n{/g'                                        \
		| sed 's/me/count/g'                                                       \
		| head - n - 2                                                               \
		| tail - n + 10


		echo "}"
#endif