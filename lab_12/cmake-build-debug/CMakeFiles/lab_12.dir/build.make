# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.19

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
CMAKE_COMMAND = "G:\Work\CLion 2021.1.3\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "G:\Work\CLion 2021.1.3\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = G:\Work\Proga\Labs\lab_12

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = G:\Work\Proga\Labs\lab_12\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/lab_12.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/lab_12.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/lab_12.dir/flags.make

CMakeFiles/lab_12.dir/main.cpp.obj: CMakeFiles/lab_12.dir/flags.make
CMakeFiles/lab_12.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=G:\Work\Proga\Labs\lab_12\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/lab_12.dir/main.cpp.obj"
	"G:\Work\CLion 2021.1.3\compiler\mingw64\bin\g++.exe" $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\lab_12.dir\main.cpp.obj -c G:\Work\Proga\Labs\lab_12\main.cpp

CMakeFiles/lab_12.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/lab_12.dir/main.cpp.i"
	"G:\Work\CLion 2021.1.3\compiler\mingw64\bin\g++.exe" $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E G:\Work\Proga\Labs\lab_12\main.cpp > CMakeFiles\lab_12.dir\main.cpp.i

CMakeFiles/lab_12.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/lab_12.dir/main.cpp.s"
	"G:\Work\CLion 2021.1.3\compiler\mingw64\bin\g++.exe" $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S G:\Work\Proga\Labs\lab_12\main.cpp -o CMakeFiles\lab_12.dir\main.cpp.s

CMakeFiles/lab_12.dir/BracketsCheck.cpp.obj: CMakeFiles/lab_12.dir/flags.make
CMakeFiles/lab_12.dir/BracketsCheck.cpp.obj: ../BracketsCheck.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=G:\Work\Proga\Labs\lab_12\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/lab_12.dir/BracketsCheck.cpp.obj"
	"G:\Work\CLion 2021.1.3\compiler\mingw64\bin\g++.exe" $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\lab_12.dir\BracketsCheck.cpp.obj -c G:\Work\Proga\Labs\lab_12\BracketsCheck.cpp

CMakeFiles/lab_12.dir/BracketsCheck.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/lab_12.dir/BracketsCheck.cpp.i"
	"G:\Work\CLion 2021.1.3\compiler\mingw64\bin\g++.exe" $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E G:\Work\Proga\Labs\lab_12\BracketsCheck.cpp > CMakeFiles\lab_12.dir\BracketsCheck.cpp.i

CMakeFiles/lab_12.dir/BracketsCheck.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/lab_12.dir/BracketsCheck.cpp.s"
	"G:\Work\CLion 2021.1.3\compiler\mingw64\bin\g++.exe" $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S G:\Work\Proga\Labs\lab_12\BracketsCheck.cpp -o CMakeFiles\lab_12.dir\BracketsCheck.cpp.s

# Object files for target lab_12
lab_12_OBJECTS = \
"CMakeFiles/lab_12.dir/main.cpp.obj" \
"CMakeFiles/lab_12.dir/BracketsCheck.cpp.obj"

# External object files for target lab_12
lab_12_EXTERNAL_OBJECTS =

lab_12.exe: CMakeFiles/lab_12.dir/main.cpp.obj
lab_12.exe: CMakeFiles/lab_12.dir/BracketsCheck.cpp.obj
lab_12.exe: CMakeFiles/lab_12.dir/build.make
lab_12.exe: CMakeFiles/lab_12.dir/linklibs.rsp
lab_12.exe: CMakeFiles/lab_12.dir/objects1.rsp
lab_12.exe: CMakeFiles/lab_12.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=G:\Work\Proga\Labs\lab_12\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable lab_12.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\lab_12.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/lab_12.dir/build: lab_12.exe

.PHONY : CMakeFiles/lab_12.dir/build

CMakeFiles/lab_12.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\lab_12.dir\cmake_clean.cmake
.PHONY : CMakeFiles/lab_12.dir/clean

CMakeFiles/lab_12.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" G:\Work\Proga\Labs\lab_12 G:\Work\Proga\Labs\lab_12 G:\Work\Proga\Labs\lab_12\cmake-build-debug G:\Work\Proga\Labs\lab_12\cmake-build-debug G:\Work\Proga\Labs\lab_12\cmake-build-debug\CMakeFiles\lab_12.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/lab_12.dir/depend
