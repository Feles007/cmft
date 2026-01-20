cmake_minimum_required(VERSION 3.16)

project(
	cmft
	VERSION 1.0
	LANGUAGES CXX
)

add_executable(
	cmft
	src/test.cpp src/error.cpp src/allocation.cpp src/file_reader.cpp
)

target_include_directories(
	cmft
	PRIVATE
	include
)

target_compile_features(
	cmft
	PRIVATE cxx_std_23
)

if(MSVC)
	target_compile_definitions(
		cmft
		PRIVATE
		_CRT_SECURE_NO_WARNINGS
	)
endif()