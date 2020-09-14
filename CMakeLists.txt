cmake_minimum_required(VERSION 3.17)
project(software_project2 C)

set(CMAKE_C_STANDARD 90)
set(GCC_COVERAGE_COMPILE_FLAGS "-ansi -Wall -Wextra -Werror -pedantic-errors")
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${GCC_COVERAGE_COMPILE_FLAGS}")

add_executable(cluster cluster.c algorithm2.c algorithm2.h algorithm4.c algorithm4.h graph.c graph.h linked_list.c linked_list.h my_array.c my_array.h my_assert.h my_assert.c spmat.c spmat.h)