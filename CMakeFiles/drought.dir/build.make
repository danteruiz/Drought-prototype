# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.4

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
CMAKE_COMMAND = /Applications/CMake.app/Contents/bin/cmake

# The command to remove a file.
RM = /Applications/CMake.app/Contents/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/danteruiz/Documents/Drought-prototype

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/danteruiz/Documents/Drought-prototype

# Include any dependencies generated for this target.
include CMakeFiles/Drought.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Drought.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Drought.dir/flags.make

CMakeFiles/Drought.dir/source/main.cpp.o: CMakeFiles/Drought.dir/flags.make
CMakeFiles/Drought.dir/source/main.cpp.o: source/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/danteruiz/Documents/Drought-prototype/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Drought.dir/source/main.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Drought.dir/source/main.cpp.o -c /Users/danteruiz/Documents/Drought-prototype/source/main.cpp

CMakeFiles/Drought.dir/source/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Drought.dir/source/main.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/danteruiz/Documents/Drought-prototype/source/main.cpp > CMakeFiles/Drought.dir/source/main.cpp.i

CMakeFiles/Drought.dir/source/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Drought.dir/source/main.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/danteruiz/Documents/Drought-prototype/source/main.cpp -o CMakeFiles/Drought.dir/source/main.cpp.s

CMakeFiles/Drought.dir/source/main.cpp.o.requires:

.PHONY : CMakeFiles/Drought.dir/source/main.cpp.o.requires

CMakeFiles/Drought.dir/source/main.cpp.o.provides: CMakeFiles/Drought.dir/source/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/Drought.dir/build.make CMakeFiles/Drought.dir/source/main.cpp.o.provides.build
.PHONY : CMakeFiles/Drought.dir/source/main.cpp.o.provides

CMakeFiles/Drought.dir/source/main.cpp.o.provides.build: CMakeFiles/Drought.dir/source/main.cpp.o


# Object files for target Drought
Drought_OBJECTS = \
"CMakeFiles/Drought.dir/source/main.cpp.o"

# External object files for target Drought
Drought_EXTERNAL_OBJECTS =

Drought: CMakeFiles/Drought.dir/source/main.cpp.o
Drought: CMakeFiles/Drought.dir/build.make
Drought: /usr/local/lib/libsfml-system.dylib
Drought: /usr/local/lib/libsfml-window.dylib
Drought: /usr/local/lib/libsfml-graphics.dylib
Drought: /usr/local/lib/libsfml-network.dylib
Drought: /usr/local/lib/libsfml-audio.dylib
Drought: libfile.a
Drought: CMakeFiles/Drought.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/danteruiz/Documents/Drought-prototype/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Drought"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Drought.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Drought.dir/build: Drought

.PHONY : CMakeFiles/Drought.dir/build

CMakeFiles/Drought.dir/requires: CMakeFiles/Drought.dir/source/main.cpp.o.requires

.PHONY : CMakeFiles/Drought.dir/requires

CMakeFiles/Drought.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Drought.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Drought.dir/clean

CMakeFiles/Drought.dir/depend:
	cd /Users/danteruiz/Documents/Drought-prototype && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/danteruiz/Documents/Drought-prototype /Users/danteruiz/Documents/Drought-prototype /Users/danteruiz/Documents/Drought-prototype /Users/danteruiz/Documents/Drought-prototype /Users/danteruiz/Documents/Drought-prototype/CMakeFiles/Drought.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Drought.dir/depend

