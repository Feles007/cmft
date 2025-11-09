project('cmft', 'cpp')

inc = include_directories('include')

src = [
	'src/error.cpp',
	'src/allocation.cpp',
	'src/file_reader.cpp',
	'src/test.cpp',
]

lib = static_library(
	'cmft',
	src,
	include_directories : inc,
	cpp_args : '-D_CRT_SECURE_NO_WARNINGS',
)

meson.override_dependency(
	'cmft',
	declare_dependency(include_directories : inc, link_with : lib)
)
