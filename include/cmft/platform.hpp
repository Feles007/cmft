#pragma once

#define CLANG 0
#define MSVC  0
#define GCC   0

#if defined(__clang__)
	#undef CLANG
	#define CLANG 1
#elif defined(__GNUC__) || defined(__GNUG__)
	#undef GCC
	#define GCC 1
#elif defined(_MSC_VER)
	#undef MSVC
	#define MSVC 1
#else
	#error cmft: Unknown compiler!
#endif
