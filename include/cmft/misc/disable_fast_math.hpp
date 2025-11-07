#include "../platform.hpp"

#ifndef CMFT_FAST_MATH_ENABLED
	#error cmft: Fast math disabled witout being enabled!
#else
	#undef CMFT_FAST_MATH_ENABLED
#endif

#if CLANG | MSVC
	#pragma float_control(pop)
#elif GCC
	#pragma GCC pop_options
#endif
