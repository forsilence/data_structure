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
CMAKE_SOURCE_DIR = K:\c_learning_and_Algorithm\data_structure\queue

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = K:\c_learning_and_Algorithm\data_structure\queue\build

# Include any dependencies generated for this target.
include byArray/CMakeFiles/queue.dir/depend.make

# Include the progress variables for this target.
include byArray/CMakeFiles/queue.dir/progress.make

# Include the compile flags for this target's objects.
include byArray/CMakeFiles/queue.dir/flags.make

byArray/CMakeFiles/queue.dir/queue.c.obj: byArray/CMakeFiles/queue.dir/flags.make
byArray/CMakeFiles/queue.dir/queue.c.obj: ../byArray/queue.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=K:\c_learning_and_Algorithm\data_structure\queue\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object byArray/CMakeFiles/queue.dir/queue.c.obj"
	cd /d K:\c_learning_and_Algorithm\data_structure\queue\build\byArray && D:\x86_64-8.1.0-release-posix-seh-rt_v6-rev0\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\queue.dir\queue.c.obj -c K:\c_learning_and_Algorithm\data_structure\queue\byArray\queue.c

byArray/CMakeFiles/queue.dir/queue.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/queue.dir/queue.c.i"
	cd /d K:\c_learning_and_Algorithm\data_structure\queue\build\byArray && D:\x86_64-8.1.0-release-posix-seh-rt_v6-rev0\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E K:\c_learning_and_Algorithm\data_structure\queue\byArray\queue.c > CMakeFiles\queue.dir\queue.c.i

byArray/CMakeFiles/queue.dir/queue.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/queue.dir/queue.c.s"
	cd /d K:\c_learning_and_Algorithm\data_structure\queue\build\byArray && D:\x86_64-8.1.0-release-posix-seh-rt_v6-rev0\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S K:\c_learning_and_Algorithm\data_structure\queue\byArray\queue.c -o CMakeFiles\queue.dir\queue.c.s

# Object files for target queue
queue_OBJECTS = \
"CMakeFiles/queue.dir/queue.c.obj"

# External object files for target queue
queue_EXTERNAL_OBJECTS =

byArray/libqueue.a: byArray/CMakeFiles/queue.dir/queue.c.obj
byArray/libqueue.a: byArray/CMakeFiles/queue.dir/build.make
byArray/libqueue.a: byArray/CMakeFiles/queue.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=K:\c_learning_and_Algorithm\data_structure\queue\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C static library libqueue.a"
	cd /d K:\c_learning_and_Algorithm\data_structure\queue\build\byArray && $(CMAKE_COMMAND) -P CMakeFiles\queue.dir\cmake_clean_target.cmake
	cd /d K:\c_learning_and_Algorithm\data_structure\queue\build\byArray && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\queue.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
byArray/CMakeFiles/queue.dir/build: byArray/libqueue.a

.PHONY : byArray/CMakeFiles/queue.dir/build

byArray/CMakeFiles/queue.dir/clean:
	cd /d K:\c_learning_and_Algorithm\data_structure\queue\build\byArray && $(CMAKE_COMMAND) -P CMakeFiles\queue.dir\cmake_clean.cmake
.PHONY : byArray/CMakeFiles/queue.dir/clean

byArray/CMakeFiles/queue.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" K:\c_learning_and_Algorithm\data_structure\queue K:\c_learning_and_Algorithm\data_structure\queue\byArray K:\c_learning_and_Algorithm\data_structure\queue\build K:\c_learning_and_Algorithm\data_structure\queue\build\byArray K:\c_learning_and_Algorithm\data_structure\queue\build\byArray\CMakeFiles\queue.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : byArray/CMakeFiles/queue.dir/depend

