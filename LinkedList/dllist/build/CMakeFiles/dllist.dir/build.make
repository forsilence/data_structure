# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.18

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
$$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = D:\cmake\cmake-3.18.0-rc1-win64-x64\bin\cmake.exe

# The command to remove a file.
RM = D:\cmake\cmake-3.18.0-rc1-win64-x64\bin\cmake.exe -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = K:\c_learning_and_Algorithm\data_structure\LinkedList\dllist

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = K:\c_learning_and_Algorithm\data_structure\LinkedList\dllist\build

# Include any dependencies generated for this target.
include CMakeFiles/dllist.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/dllist.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/dllist.dir/flags.make

CMakeFiles/dllist.dir/dllist.c.obj: CMakeFiles/dllist.dir/flags.make
CMakeFiles/dllist.dir/dllist.c.obj: ../dllist.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=K:\c_learning_and_Algorithm\data_structure\LinkedList\dllist\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/dllist.dir/dllist.c.obj"
	D:\x86_64-8.1.0-release-posix-seh-rt_v6-rev0\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\dllist.dir\dllist.c.obj -c K:\c_learning_and_Algorithm\data_structure\LinkedList\dllist\dllist.c

CMakeFiles/dllist.dir/dllist.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/dllist.dir/dllist.c.i"
	D:\x86_64-8.1.0-release-posix-seh-rt_v6-rev0\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E K:\c_learning_and_Algorithm\data_structure\LinkedList\dllist\dllist.c > CMakeFiles\dllist.dir\dllist.c.i

CMakeFiles/dllist.dir/dllist.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/dllist.dir/dllist.c.s"
	D:\x86_64-8.1.0-release-posix-seh-rt_v6-rev0\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S K:\c_learning_and_Algorithm\data_structure\LinkedList\dllist\dllist.c -o CMakeFiles\dllist.dir\dllist.c.s

CMakeFiles/dllist.dir/main.c.obj: CMakeFiles/dllist.dir/flags.make
CMakeFiles/dllist.dir/main.c.obj: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=K:\c_learning_and_Algorithm\data_structure\LinkedList\dllist\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/dllist.dir/main.c.obj"
	D:\x86_64-8.1.0-release-posix-seh-rt_v6-rev0\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\dllist.dir\main.c.obj -c K:\c_learning_and_Algorithm\data_structure\LinkedList\dllist\main.c

CMakeFiles/dllist.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/dllist.dir/main.c.i"
	D:\x86_64-8.1.0-release-posix-seh-rt_v6-rev0\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E K:\c_learning_and_Algorithm\data_structure\LinkedList\dllist\main.c > CMakeFiles\dllist.dir\main.c.i

CMakeFiles/dllist.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/dllist.dir/main.c.s"
	D:\x86_64-8.1.0-release-posix-seh-rt_v6-rev0\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S K:\c_learning_and_Algorithm\data_structure\LinkedList\dllist\main.c -o CMakeFiles\dllist.dir\main.c.s

# Object files for target dllist
dllist_OBJECTS = \
"CMakeFiles/dllist.dir/dllist.c.obj" \
"CMakeFiles/dllist.dir/main.c.obj"

# External object files for target dllist
dllist_EXTERNAL_OBJECTS =

libdllist.a: CMakeFiles/dllist.dir/dllist.c.obj
libdllist.a: CMakeFiles/dllist.dir/main.c.obj
libdllist.a: CMakeFiles/dllist.dir/build.make
libdllist.a: CMakeFiles/dllist.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=K:\c_learning_and_Algorithm\data_structure\LinkedList\dllist\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking C static library libdllist.a"
	$(CMAKE_COMMAND) -P CMakeFiles\dllist.dir\cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\dllist.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/dllist.dir/build: libdllist.a

.PHONY : CMakeFiles/dllist.dir/build

CMakeFiles/dllist.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\dllist.dir\cmake_clean.cmake
.PHONY : CMakeFiles/dllist.dir/clean

CMakeFiles/dllist.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" K:\c_learning_and_Algorithm\data_structure\LinkedList\dllist K:\c_learning_and_Algorithm\data_structure\LinkedList\dllist K:\c_learning_and_Algorithm\data_structure\LinkedList\dllist\build K:\c_learning_and_Algorithm\data_structure\LinkedList\dllist\build K:\c_learning_and_Algorithm\data_structure\LinkedList\dllist\build\CMakeFiles\dllist.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/dllist.dir/depend

