#pragma once

#define MCA_START(n) __asm volatile("# LLVM-MCA-BEGIN " #n ::: "memory");
#define MCA_END()    __asm volatile("# LLVM-MCA-END" ::: "memory");

#define MCA(...)                                                            \
	__asm volatile("# LLVM-MCA-BEGIN " TO_STRING(__VA_ARGS__)::: "memory"); \
	McaEnd mca_end;

struct McaEnd {
	~McaEnd() {
		__asm volatile("# LLVM-MCA-END" ::: "memory");
	}
};
