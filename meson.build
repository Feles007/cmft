project(
	'cmft',
	'cpp',
)

src = [
	'src/error.cpp',
	'src/allocation.cpp',
	'src/file_reader.cpp',
]

library(
	'cmft',
	src,
	install : true,
	include_directories : include_directories('include'),
	cpp_args : '-D_CRT_SECURE_NO_WARNINGS',
)