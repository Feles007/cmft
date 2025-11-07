#pragma once

#include "../error.hpp"
#include "../platform.hpp"

// restrict
#ifdef UNSAFE_OPTIMIZATIONS
	#define restrict __restrict
#else
	#define restrict
#endif

// unreachable()
#ifdef UNSAFE_OPTIMIZATIONS
	#if CLANG | GCC
		#define unreachable() __builtin_unreachable()
	#elif MSVC
		#define unreachable() __assume(false)
	#endif
#else
	#define unreachable() FATAL_ERROR("Entered unreachable code at " SOURCE_LOCATION)
#endif

// assume(expression)
#ifdef UNSAFE_OPTIMIZATIONS
	#if CLANG | GCC
		#define assume(expression) \
			if (!(expression)) unreachable()
	#elif MSVC
		#define assume(expression) __assume(expression)
	#endif
#else
	#define assume(expression) \
		if (!(expression)) FATAL_ERROR("Assumed condition (" #expression ") was false at " SOURCE_LOCATION)
#endif

#if CLANG | GCC
	#define alwaysinline __attribute__((alwaysinline))
	#define noinline     __attribute__((noinline))
#elif MSVC
	#define alwaysinline __forceinline
	#define noinline     __declspec(noinline)
#endif
