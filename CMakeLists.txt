cmake_minimum_required(VERSION 3.1)
project(number-to-georgian)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)


add_library(compiler_warnings INTERFACE)
target_compile_options(compiler_warnings INTERFACE
	$<$<OR:$<CXX_COMPILER_ID:Clang>,$<CXX_COMPILER_ID:AppleClang>,$<CXX_COMPILER_ID:GNU>>:
		-Wall -Wextra>
	$<$<CXX_COMPILER_ID:MSVC>:
		/W4>
)

# The main library
add_library(number_to_georgian INTERFACE)
target_sources(number_to_georgian
	INTERFACE
		${CMAKE_CURRENT_SOURCE_DIR}/number_to_georgian/number_to_georgian.h
)
target_include_directories(number_to_georgian
	INTERFACE
		${CMAKE_CURRENT_SOURCE_DIR}/number_to_georgian
)
target_compile_options(number_to_georgian INTERFACE
	$<$<CXX_COMPILER_ID:MSVC>:
		/utf-8>
)


# Catch2 target
add_library(catch2 INTERFACE)
target_sources(catch2
	INTERFACE
		${CMAKE_CURRENT_SOURCE_DIR}/catch2/catch.hpp
)
target_include_directories(catch2
	SYSTEM INTERFACE
		${CMAKE_CURRENT_SOURCE_DIR}/catch2
)

# Tests
add_executable(test_number_to_georgian
	tests/test_number_to_georgian.cpp
)
target_link_libraries(test_number_to_georgian
	PRIVATE
		number_to_georgian
		catch2
		compiler_warnings
)

## Examples
#add_executable(example_runtime
#	examples/example_runtime.cpp
#)
#target_link_libraries(example_runtime
#	PRIVATE
#		number_to_georgian
#		compiler_warnings
#)
#
#add_executable(example_compiletime
#	examples/example_compiletime.cpp
#)
#target_link_libraries(example_compiletime
#	PRIVATE
#		number_to_georgian
#		compiler_warnings
#)


include(CTest)
include(catch2/Catch.cmake)
catch_discover_tests(test_number_to_georgian)

