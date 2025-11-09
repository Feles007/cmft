#include "cmft/array.hpp"
#include "cmft/heap_array.hpp"
#include "cmft/io/file_reader.hpp"

void func(Slice<const int>) {}
void func2(Slice<int>) {}

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
	auto h = HeapArray<int>(9);

	func(h);

	func2(a);
	func2(s);
	//	func2(cs); // nope
	func2(h);

	h.deallocate();

	h = HeapArray<int>(16);
	h.deallocate();

	auto file = read_file("meson.build");
	file.deallocate();
}
