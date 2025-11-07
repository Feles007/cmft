#include "cmft/error.hpp"
#include <cstring>

void errno_exit() {
	const int e = errno;
	FATAL_ERROR("errno: %d - %s", e, std::strerror(e));
}
