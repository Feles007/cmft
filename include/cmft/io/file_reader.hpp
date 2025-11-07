#pragma once

#include "../core.hpp"

struct FileData {
	u8 *data;
	usize length;

	[[nodiscard]] static FileData read_file(nt_string path);
	static void deallocate(FileData fd);
};
