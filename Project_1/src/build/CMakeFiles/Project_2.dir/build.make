# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.19

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

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = "C:/Program Files (x86)/Microsoft Visual Studio/2019/Community/Common7/IDE/CommonExtensions/Microsoft/CMake/CMake/bin/cmake.exe"

# The command to remove a file.
RM = "C:/Program Files (x86)/Microsoft Visual Studio/2019/Community/Common7/IDE/CommonExtensions/Microsoft/CMake/CMake/bin/cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:/Users/bfant/CISC205/Project_1/src

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:/Users/bfant/CISC205/Project_1/src/build

# Include any dependencies generated for this target.
include CMakeFiles/Project_2.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Project_2.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Project_2.dir/flags.make

CMakeFiles/Project_2.dir/main.cpp.o: CMakeFiles/Project_2.dir/flags.make
CMakeFiles/Project_2.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:/Users/bfant/CISC205/Project_1/src/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Project_2.dir/main.cpp.o"
	C:/cygwin64/bin/g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Project_2.dir/main.cpp.o -c C:/Users/bfant/CISC205/Project_1/src/main.cpp

CMakeFiles/Project_2.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Project_2.dir/main.cpp.i"
	C:/cygwin64/bin/g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:/Users/bfant/CISC205/Project_1/src/main.cpp > CMakeFiles/Project_2.dir/main.cpp.i

CMakeFiles/Project_2.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Project_2.dir/main.cpp.s"
	C:/cygwin64/bin/g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:/Users/bfant/CISC205/Project_1/src/main.cpp -o CMakeFiles/Project_2.dir/main.cpp.s

# Object files for target Project_2
Project_2_OBJECTS = \
"CMakeFiles/Project_2.dir/main.cpp.o"

# External object files for target Project_2
Project_2_EXTERNAL_OBJECTS =

Project_2.exe: CMakeFiles/Project_2.dir/main.cpp.o
Project_2.exe: CMakeFiles/Project_2.dir/build.make
Project_2.exe: libprocess-Project_2.a
Project_2.exe: CMakeFiles/Project_2.dir/linklibs.rsp
Project_2.exe: CMakeFiles/Project_2.dir/objects1.rsp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:/Users/bfant/CISC205/Project_1/src/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Project_2.exe"
	"C:/Program Files (x86)/Microsoft Visual Studio/2019/Community/Common7/IDE/CommonExtensions/Microsoft/CMake/CMake/bin/cmake.exe" -E rm -f CMakeFiles/Project_2.dir/objects.a
	C:/cygwin64/bin/ar.exe cr CMakeFiles/Project_2.dir/objects.a @CMakeFiles/Project_2.dir/objects1.rsp
	C:/cygwin64/bin/g++.exe -g -Wl,--whole-archive CMakeFiles/Project_2.dir/objects.a -Wl,--no-whole-archive -o Project_2.exe -Wl,--out-implib,libProject_2.dll.a -Wl,--major-image-version,0,--minor-image-version,0 @CMakeFiles/Project_2.dir/linklibs.rsp

# Rule to build all files generated by this target.
CMakeFiles/Project_2.dir/build: Project_2.exe

.PHONY : CMakeFiles/Project_2.dir/build

CMakeFiles/Project_2.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Project_2.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Project_2.dir/clean

CMakeFiles/Project_2.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" C:/Users/bfant/CISC205/Project_1/src C:/Users/bfant/CISC205/Project_1/src C:/Users/bfant/CISC205/Project_1/src/build C:/Users/bfant/CISC205/Project_1/src/build C:/Users/bfant/CISC205/Project_1/src/build/CMakeFiles/Project_2.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Project_2.dir/depend

