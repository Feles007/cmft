#include "cmft/array.hpp"
void test() {
	Array<int, 6> a;
	a[0] = 0;
	for (usize i = 0; i < a.length(); ++i) {
	}
	Slice<int> s   = a;
	CSlice<int> cs = s;
}
