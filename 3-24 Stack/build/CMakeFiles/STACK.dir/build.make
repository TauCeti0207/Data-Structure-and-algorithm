# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.22

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

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "D:\Program Files (x86)\cmake\cmake-3.22.2-windows-x86_64\bin\cmake.exe"

# The command to remove a file.
RM = "D:\Program Files (x86)\cmake\cmake-3.22.2-windows-x86_64\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "D:\code\2022code\Data-Structure-and-algorithm\3-24 Stack"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "D:\code\2022code\Data-Structure-and-algorithm\3-24 Stack\build"

# Include any dependencies generated for this target.
include CMakeFiles/STACK.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/STACK.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/STACK.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/STACK.dir/flags.make

CMakeFiles/STACK.dir/src/Stack.obj: CMakeFiles/STACK.dir/flags.make
CMakeFiles/STACK.dir/src/Stack.obj: ../src/Stack.cpp
CMakeFiles/STACK.dir/src/Stack.obj: CMakeFiles/STACK.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="D:\code\2022code\Data-Structure-and-algorithm\3-24 Stack\build\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/STACK.dir/src/Stack.obj"
	D:\PROGRA~1\gcc\mingw64\bin\X86_64~2.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/STACK.dir/src/Stack.obj -MF CMakeFiles\STACK.dir\src\Stack.obj.d -o CMakeFiles\STACK.dir\src\Stack.obj -c "D:\code\2022code\Data-Structure-and-algorithm\3-24 Stack\src\Stack.cpp"

CMakeFiles/STACK.dir/src/Stack.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/STACK.dir/src/Stack.i"
	D:\PROGRA~1\gcc\mingw64\bin\X86_64~2.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "D:\code\2022code\Data-Structure-and-algorithm\3-24 Stack\src\Stack.cpp" > CMakeFiles\STACK.dir\src\Stack.i

CMakeFiles/STACK.dir/src/Stack.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/STACK.dir/src/Stack.s"
	D:\PROGRA~1\gcc\mingw64\bin\X86_64~2.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "D:\code\2022code\Data-Structure-and-algorithm\3-24 Stack\src\Stack.cpp" -o CMakeFiles\STACK.dir\src\Stack.s

CMakeFiles/STACK.dir/src/test.obj: CMakeFiles/STACK.dir/flags.make
CMakeFiles/STACK.dir/src/test.obj: ../src/test.cpp
CMakeFiles/STACK.dir/src/test.obj: CMakeFiles/STACK.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="D:\code\2022code\Data-Structure-and-algorithm\3-24 Stack\build\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/STACK.dir/src/test.obj"
	D:\PROGRA~1\gcc\mingw64\bin\X86_64~2.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/STACK.dir/src/test.obj -MF CMakeFiles\STACK.dir\src\test.obj.d -o CMakeFiles\STACK.dir\src\test.obj -c "D:\code\2022code\Data-Structure-and-algorithm\3-24 Stack\src\test.cpp"

CMakeFiles/STACK.dir/src/test.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/STACK.dir/src/test.i"
	D:\PROGRA~1\gcc\mingw64\bin\X86_64~2.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "D:\code\2022code\Data-Structure-and-algorithm\3-24 Stack\src\test.cpp" > CMakeFiles\STACK.dir\src\test.i

CMakeFiles/STACK.dir/src/test.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/STACK.dir/src/test.s"
	D:\PROGRA~1\gcc\mingw64\bin\X86_64~2.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "D:\code\2022code\Data-Structure-and-algorithm\3-24 Stack\src\test.cpp" -o CMakeFiles\STACK.dir\src\test.s

# Object files for target STACK
STACK_OBJECTS = \
"CMakeFiles/STACK.dir/src/Stack.obj" \
"CMakeFiles/STACK.dir/src/test.obj"

# External object files for target STACK
STACK_EXTERNAL_OBJECTS =

STACK.exe: CMakeFiles/STACK.dir/src/Stack.obj
STACK.exe: CMakeFiles/STACK.dir/src/test.obj
STACK.exe: CMakeFiles/STACK.dir/build.make
STACK.exe: CMakeFiles/STACK.dir/linklibs.rsp
STACK.exe: CMakeFiles/STACK.dir/objects1.rsp
STACK.exe: CMakeFiles/STACK.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="D:\code\2022code\Data-Structure-and-algorithm\3-24 Stack\build\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable STACK.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\STACK.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/STACK.dir/build: STACK.exe
.PHONY : CMakeFiles/STACK.dir/build

CMakeFiles/STACK.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\STACK.dir\cmake_clean.cmake
.PHONY : CMakeFiles/STACK.dir/clean

CMakeFiles/STACK.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "D:\code\2022code\Data-Structure-and-algorithm\3-24 Stack" "D:\code\2022code\Data-Structure-and-algorithm\3-24 Stack" "D:\code\2022code\Data-Structure-and-algorithm\3-24 Stack\build" "D:\code\2022code\Data-Structure-and-algorithm\3-24 Stack\build" "D:\code\2022code\Data-Structure-and-algorithm\3-24 Stack\build\CMakeFiles\STACK.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/STACK.dir/depend
