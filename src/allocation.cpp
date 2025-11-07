#include "cmft/allocation.hpp"
#include "cmft/error.hpp"
#include <cstdlib>

void *allocate(Layout layout) {
	void *p = _aligned_malloc(layout.size, layout.alignment);
	if (p) return p;
	FATAL_ERROR("Allocation of %" FMT_USIZE ":%" FMT_USIZE " failed", layout.size, layout.alignment);
}
void deallocate(void *p, [[maybe_unused]] Layout layout) {
	if (p) _aligned_free(p);
	else FATAL_ERROR("Null pointer freed");
}
