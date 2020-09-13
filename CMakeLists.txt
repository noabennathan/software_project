cmake_minimum_required(VERSION 3.17)
project(software_project C)

set(CMAKE_C_STANDARD 90)
set(GCC_COVERAGE_COMPILE_FLAGS "-ansi -Wall -Wextra -Werror -pedantic-errors")
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${GCC_COVERAGE_COMPILE_FLAGS}")

add_executable(cluster cluster.c algorithm2.c algorithm4.c graph.c graph.h linked_list.c my_array.c my_assert.c spmat.c spmat.h)