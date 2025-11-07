#pragma once

#include "cpp_utils.hpp"
#include <cstdio>
#include <cstdlib>

#define EXIT() std::exit(EXIT_FAILURE)

#define FATAL_ERROR(...)          \
	do {                          \
		std::printf(__VA_ARGS__); \
		std::putchar('\n');       \
		EXIT();                   \
	} while (0)

// FATAL_ERROR but assuming you later call exit. For cleanup before exiting.
#define FATAL_ERROR_DEFER_EXIT(...) \
	do {                            \
		std::printf(__VA_ARGS__);   \
		std::putchar('\n');         \
	} while (0)

#define xassert(expression) \
	if (!(expression)) FATAL_ERROR("Assert failed at " SOURCE_LOCATION " - xassert(" #expression ")")

#ifdef UNSAFE_OPTIMIZATIONS
	#define debug_xassert(expression) assume(expression)
#else
	#define debug_xassert(expression) xassert(expression)
#endif

#define todo(description) FATAL_ERROR("TODO at " SOURCE_LOCATION " - " description)

[[noreturn]] void errno_exit();
