# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.14

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake.exe

# The command to remove a file.
RM = /usr/bin/cmake.exe -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /cygdrive/c/Users/Вика/Documents/GitHub/lem_in

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /cygdrive/c/Users/Вика/Documents/GitHub/lem_in/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/lemin.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/lemin.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/lemin.dir/flags.make

CMakeFiles/lemin.dir/main.c.o: CMakeFiles/lemin.dir/flags.make
CMakeFiles/lemin.dir/main.c.o: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/cygdrive/c/Users/Вика/Documents/GitHub/lem_in/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/lemin.dir/main.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/lemin.dir/main.c.o   -c /cygdrive/c/Users/Вика/Documents/GitHub/lem_in/main.c

CMakeFiles/lemin.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/lemin.dir/main.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /cygdrive/c/Users/Вика/Documents/GitHub/lem_in/main.c > CMakeFiles/lemin.dir/main.c.i

CMakeFiles/lemin.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/lemin.dir/main.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /cygdrive/c/Users/Вика/Documents/GitHub/lem_in/main.c -o CMakeFiles/lemin.dir/main.c.s

# Object files for target lemin
lemin_OBJECTS = \
"CMakeFiles/lemin.dir/main.c.o"

# External object files for target lemin
lemin_EXTERNAL_OBJECTS =

lemin.exe: CMakeFiles/lemin.dir/main.c.o
lemin.exe: CMakeFiles/lemin.dir/build.make
lemin.exe: CMakeFiles/lemin.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/cygdrive/c/Users/Вика/Documents/GitHub/lem_in/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable lemin.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/lemin.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/lemin.dir/build: lemin.exe

.PHONY : CMakeFiles/lemin.dir/build

CMakeFiles/lemin.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/lemin.dir/cmake_clean.cmake
.PHONY : CMakeFiles/lemin.dir/clean

CMakeFiles/lemin.dir/depend:
	cd /cygdrive/c/Users/Вика/Documents/GitHub/lem_in/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /cygdrive/c/Users/Вика/Documents/GitHub/lem_in /cygdrive/c/Users/Вика/Documents/GitHub/lem_in /cygdrive/c/Users/Вика/Documents/GitHub/lem_in/cmake-build-debug /cygdrive/c/Users/Вика/Documents/GitHub/lem_in/cmake-build-debug /cygdrive/c/Users/Вика/Documents/GitHub/lem_in/cmake-build-debug/CMakeFiles/lemin.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/lemin.dir/depend
