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
CMAKE_COMMAND = /snap/clion/158/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /snap/clion/158/bin/cmake/linux/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/lucas/CLionProjects/Arvore/Arvores_Bal

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/lucas/CLionProjects/Arvore/Arvores_Bal/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Prg2_demo.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Prg2_demo.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Prg2_demo.dir/flags.make

CMakeFiles/Prg2_demo.dir/main.cpp.o: CMakeFiles/Prg2_demo.dir/flags.make
CMakeFiles/Prg2_demo.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/lucas/CLionProjects/Arvore/Arvores_Bal/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Prg2_demo.dir/main.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Prg2_demo.dir/main.cpp.o -c /home/lucas/CLionProjects/Arvore/Arvores_Bal/main.cpp

CMakeFiles/Prg2_demo.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Prg2_demo.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/lucas/CLionProjects/Arvore/Arvores_Bal/main.cpp > CMakeFiles/Prg2_demo.dir/main.cpp.i

CMakeFiles/Prg2_demo.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Prg2_demo.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/lucas/CLionProjects/Arvore/Arvores_Bal/main.cpp -o CMakeFiles/Prg2_demo.dir/main.cpp.s

CMakeFiles/Prg2_demo.dir/libs/BasicTree.cpp.o: CMakeFiles/Prg2_demo.dir/flags.make
CMakeFiles/Prg2_demo.dir/libs/BasicTree.cpp.o: ../libs/BasicTree.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/lucas/CLionProjects/Arvore/Arvores_Bal/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/Prg2_demo.dir/libs/BasicTree.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Prg2_demo.dir/libs/BasicTree.cpp.o -c /home/lucas/CLionProjects/Arvore/Arvores_Bal/libs/BasicTree.cpp

CMakeFiles/Prg2_demo.dir/libs/BasicTree.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Prg2_demo.dir/libs/BasicTree.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/lucas/CLionProjects/Arvore/Arvores_Bal/libs/BasicTree.cpp > CMakeFiles/Prg2_demo.dir/libs/BasicTree.cpp.i

CMakeFiles/Prg2_demo.dir/libs/BasicTree.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Prg2_demo.dir/libs/BasicTree.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/lucas/CLionProjects/Arvore/Arvores_Bal/libs/BasicTree.cpp -o CMakeFiles/Prg2_demo.dir/libs/BasicTree.cpp.s

# Object files for target Prg2_demo
Prg2_demo_OBJECTS = \
"CMakeFiles/Prg2_demo.dir/main.cpp.o" \
"CMakeFiles/Prg2_demo.dir/libs/BasicTree.cpp.o"

# External object files for target Prg2_demo
Prg2_demo_EXTERNAL_OBJECTS =

Prg2_demo: CMakeFiles/Prg2_demo.dir/main.cpp.o
Prg2_demo: CMakeFiles/Prg2_demo.dir/libs/BasicTree.cpp.o
Prg2_demo: CMakeFiles/Prg2_demo.dir/build.make
Prg2_demo: CMakeFiles/Prg2_demo.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/lucas/CLionProjects/Arvore/Arvores_Bal/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable Prg2_demo"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Prg2_demo.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Prg2_demo.dir/build: Prg2_demo

.PHONY : CMakeFiles/Prg2_demo.dir/build

CMakeFiles/Prg2_demo.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Prg2_demo.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Prg2_demo.dir/clean

CMakeFiles/Prg2_demo.dir/depend:
	cd /home/lucas/CLionProjects/Arvore/Arvores_Bal/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/lucas/CLionProjects/Arvore/Arvores_Bal /home/lucas/CLionProjects/Arvore/Arvores_Bal /home/lucas/CLionProjects/Arvore/Arvores_Bal/cmake-build-debug /home/lucas/CLionProjects/Arvore/Arvores_Bal/cmake-build-debug /home/lucas/CLionProjects/Arvore/Arvores_Bal/cmake-build-debug/CMakeFiles/Prg2_demo.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Prg2_demo.dir/depend

