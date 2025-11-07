project('cmft', 'cpp')

inc = include_directories('include')

src = [
	'src/error.cpp',
	'src/allocation.cpp',
	'src/file_reader.cpp',
]

lib = library(
	'cmft',
	src,
	include_directories : inc,
	cpp_args : '-D_CRT_SECURE_NO_WARNINGS',
)

cmft = declare_dependency(include_directories : inc, link_with : lib)