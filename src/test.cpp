#include "cmft/array.hpp"

void func(Slice<const int>) {}

void test() {
	Array<int, 6> a;

	for (usize i = 0; i < a.length(); ++i) {
	}
	Slice<int> s        = a;
	Slice<const int> cs = s;

	func(a);
	func(s);
	func(cs);

	Array<const int, 9> b;

	const int& n = b[0];
	(void)n;
}
