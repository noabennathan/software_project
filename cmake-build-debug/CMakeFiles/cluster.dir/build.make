# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.17

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Disable VCS-based implicit rules.
% : %,v


# Disable VCS-based implicit rules.
% : RCS/%


# Disable VCS-based implicit rules.
% : RCS/%,v


# Disable VCS-based implicit rules.
% : SCCS/s.%


# Disable VCS-based implicit rules.
% : s.%


.SUFFIXES: .hpux_make_needs_suffix_list


# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2020.2.1\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2020.2.1\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\noyki\CLionProjects\software_project

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\noyki\CLionProjects\software_project\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/cluster.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/cluster.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/cluster.dir/flags.make

CMakeFiles/cluster.dir/cluster.c.obj: CMakeFiles/cluster.dir/flags.make
CMakeFiles/cluster.dir/cluster.c.obj: ../cluster.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\noyki\CLionProjects\software_project\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/cluster.dir/cluster.c.obj"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\cluster.dir\cluster.c.obj   -c C:\Users\noyki\CLionProjects\software_project\cluster.c

CMakeFiles/cluster.dir/cluster.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/cluster.dir/cluster.c.i"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\noyki\CLionProjects\software_project\cluster.c > CMakeFiles\cluster.dir\cluster.c.i

CMakeFiles/cluster.dir/cluster.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/cluster.dir/cluster.c.s"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\noyki\CLionProjects\software_project\cluster.c -o CMakeFiles\cluster.dir\cluster.c.s

CMakeFiles/cluster.dir/algorithm2.c.obj: CMakeFiles/cluster.dir/flags.make
CMakeFiles/cluster.dir/algorithm2.c.obj: ../algorithm2.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\noyki\CLionProjects\software_project\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/cluster.dir/algorithm2.c.obj"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\cluster.dir\algorithm2.c.obj   -c C:\Users\noyki\CLionProjects\software_project\algorithm2.c

CMakeFiles/cluster.dir/algorithm2.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/cluster.dir/algorithm2.c.i"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\noyki\CLionProjects\software_project\algorithm2.c > CMakeFiles\cluster.dir\algorithm2.c.i

CMakeFiles/cluster.dir/algorithm2.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/cluster.dir/algorithm2.c.s"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\noyki\CLionProjects\software_project\algorithm2.c -o CMakeFiles\cluster.dir\algorithm2.c.s

CMakeFiles/cluster.dir/algorithm4.c.obj: CMakeFiles/cluster.dir/flags.make
CMakeFiles/cluster.dir/algorithm4.c.obj: ../algorithm4.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\noyki\CLionProjects\software_project\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/cluster.dir/algorithm4.c.obj"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\cluster.dir\algorithm4.c.obj   -c C:\Users\noyki\CLionProjects\software_project\algorithm4.c

CMakeFiles/cluster.dir/algorithm4.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/cluster.dir/algorithm4.c.i"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\noyki\CLionProjects\software_project\algorithm4.c > CMakeFiles\cluster.dir\algorithm4.c.i

CMakeFiles/cluster.dir/algorithm4.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/cluster.dir/algorithm4.c.s"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\noyki\CLionProjects\software_project\algorithm4.c -o CMakeFiles\cluster.dir\algorithm4.c.s

CMakeFiles/cluster.dir/graph.c.obj: CMakeFiles/cluster.dir/flags.make
CMakeFiles/cluster.dir/graph.c.obj: ../graph.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\noyki\CLionProjects\software_project\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building C object CMakeFiles/cluster.dir/graph.c.obj"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\cluster.dir\graph.c.obj   -c C:\Users\noyki\CLionProjects\software_project\graph.c

CMakeFiles/cluster.dir/graph.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/cluster.dir/graph.c.i"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\noyki\CLionProjects\software_project\graph.c > CMakeFiles\cluster.dir\graph.c.i

CMakeFiles/cluster.dir/graph.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/cluster.dir/graph.c.s"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\noyki\CLionProjects\software_project\graph.c -o CMakeFiles\cluster.dir\graph.c.s

CMakeFiles/cluster.dir/linked_list.c.obj: CMakeFiles/cluster.dir/flags.make
CMakeFiles/cluster.dir/linked_list.c.obj: ../linked_list.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\noyki\CLionProjects\software_project\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building C object CMakeFiles/cluster.dir/linked_list.c.obj"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\cluster.dir\linked_list.c.obj   -c C:\Users\noyki\CLionProjects\software_project\linked_list.c

CMakeFiles/cluster.dir/linked_list.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/cluster.dir/linked_list.c.i"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\noyki\CLionProjects\software_project\linked_list.c > CMakeFiles\cluster.dir\linked_list.c.i

CMakeFiles/cluster.dir/linked_list.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/cluster.dir/linked_list.c.s"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\noyki\CLionProjects\software_project\linked_list.c -o CMakeFiles\cluster.dir\linked_list.c.s

CMakeFiles/cluster.dir/my_array.c.obj: CMakeFiles/cluster.dir/flags.make
CMakeFiles/cluster.dir/my_array.c.obj: ../my_array.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\noyki\CLionProjects\software_project\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building C object CMakeFiles/cluster.dir/my_array.c.obj"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\cluster.dir\my_array.c.obj   -c C:\Users\noyki\CLionProjects\software_project\my_array.c

CMakeFiles/cluster.dir/my_array.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/cluster.dir/my_array.c.i"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\noyki\CLionProjects\software_project\my_array.c > CMakeFiles\cluster.dir\my_array.c.i

CMakeFiles/cluster.dir/my_array.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/cluster.dir/my_array.c.s"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\noyki\CLionProjects\software_project\my_array.c -o CMakeFiles\cluster.dir\my_array.c.s

CMakeFiles/cluster.dir/my_assert.c.obj: CMakeFiles/cluster.dir/flags.make
CMakeFiles/cluster.dir/my_assert.c.obj: ../my_assert.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\noyki\CLionProjects\software_project\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building C object CMakeFiles/cluster.dir/my_assert.c.obj"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\cluster.dir\my_assert.c.obj   -c C:\Users\noyki\CLionProjects\software_project\my_assert.c

CMakeFiles/cluster.dir/my_assert.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/cluster.dir/my_assert.c.i"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\noyki\CLionProjects\software_project\my_assert.c > CMakeFiles\cluster.dir\my_assert.c.i

CMakeFiles/cluster.dir/my_assert.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/cluster.dir/my_assert.c.s"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\noyki\CLionProjects\software_project\my_assert.c -o CMakeFiles\cluster.dir\my_assert.c.s

CMakeFiles/cluster.dir/spmat.c.obj: CMakeFiles/cluster.dir/flags.make
CMakeFiles/cluster.dir/spmat.c.obj: ../spmat.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\noyki\CLionProjects\software_project\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building C object CMakeFiles/cluster.dir/spmat.c.obj"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\cluster.dir\spmat.c.obj   -c C:\Users\noyki\CLionProjects\software_project\spmat.c

CMakeFiles/cluster.dir/spmat.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/cluster.dir/spmat.c.i"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\noyki\CLionProjects\software_project\spmat.c > CMakeFiles\cluster.dir\spmat.c.i

CMakeFiles/cluster.dir/spmat.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/cluster.dir/spmat.c.s"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\noyki\CLionProjects\software_project\spmat.c -o CMakeFiles\cluster.dir\spmat.c.s

# Object files for target cluster
cluster_OBJECTS = \
"CMakeFiles/cluster.dir/cluster.c.obj" \
"CMakeFiles/cluster.dir/algorithm2.c.obj" \
"CMakeFiles/cluster.dir/algorithm4.c.obj" \
"CMakeFiles/cluster.dir/graph.c.obj" \
"CMakeFiles/cluster.dir/linked_list.c.obj" \
"CMakeFiles/cluster.dir/my_array.c.obj" \
"CMakeFiles/cluster.dir/my_assert.c.obj" \
"CMakeFiles/cluster.dir/spmat.c.obj"

# External object files for target cluster
cluster_EXTERNAL_OBJECTS =

cluster.exe: CMakeFiles/cluster.dir/cluster.c.obj
cluster.exe: CMakeFiles/cluster.dir/algorithm2.c.obj
cluster.exe: CMakeFiles/cluster.dir/algorithm4.c.obj
cluster.exe: CMakeFiles/cluster.dir/graph.c.obj
cluster.exe: CMakeFiles/cluster.dir/linked_list.c.obj
cluster.exe: CMakeFiles/cluster.dir/my_array.c.obj
cluster.exe: CMakeFiles/cluster.dir/my_assert.c.obj
cluster.exe: CMakeFiles/cluster.dir/spmat.c.obj
cluster.exe: CMakeFiles/cluster.dir/build.make
cluster.exe: CMakeFiles/cluster.dir/linklibs.rsp
cluster.exe: CMakeFiles/cluster.dir/objects1.rsp
cluster.exe: CMakeFiles/cluster.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\noyki\CLionProjects\software_project\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Linking C executable cluster.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\cluster.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/cluster.dir/build: cluster.exe

.PHONY : CMakeFiles/cluster.dir/build

CMakeFiles/cluster.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\cluster.dir\cmake_clean.cmake
.PHONY : CMakeFiles/cluster.dir/clean

CMakeFiles/cluster.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\noyki\CLionProjects\software_project C:\Users\noyki\CLionProjects\software_project C:\Users\noyki\CLionProjects\software_project\cmake-build-debug C:\Users\noyki\CLionProjects\software_project\cmake-build-debug C:\Users\noyki\CLionProjects\software_project\cmake-build-debug\CMakeFiles\cluster.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/cluster.dir/depend

