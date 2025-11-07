#include "../platform.hpp"

#if CLANG | MSVC
	#pragma float_control(push)
	#pragma float_control(precise, off)
	#pragma float_control(except, off)
	#pragma fp_contract(on)
	#pragma fenv_access(off)
#elif GCC
	#pragma GCC push_options
	#pragma GCC optimize "Ofast"
#endif

#define CMFT_FAST_MATH_ENABLED
