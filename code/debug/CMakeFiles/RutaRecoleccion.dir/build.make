# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/guillermo/DAA/DAA_PR5_VRPT-SWTS/code

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/guillermo/DAA/DAA_PR5_VRPT-SWTS/code/debug

# Include any dependencies generated for this target.
include CMakeFiles/RutaRecoleccion.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/RutaRecoleccion.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/RutaRecoleccion.dir/flags.make

CMakeFiles/RutaRecoleccion.dir/src/main.cpp.o: CMakeFiles/RutaRecoleccion.dir/flags.make
CMakeFiles/RutaRecoleccion.dir/src/main.cpp.o: ../src/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/guillermo/DAA/DAA_PR5_VRPT-SWTS/code/debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/RutaRecoleccion.dir/src/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/RutaRecoleccion.dir/src/main.cpp.o -c /home/guillermo/DAA/DAA_PR5_VRPT-SWTS/code/src/main.cpp

CMakeFiles/RutaRecoleccion.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/RutaRecoleccion.dir/src/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/guillermo/DAA/DAA_PR5_VRPT-SWTS/code/src/main.cpp > CMakeFiles/RutaRecoleccion.dir/src/main.cpp.i

CMakeFiles/RutaRecoleccion.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/RutaRecoleccion.dir/src/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/guillermo/DAA/DAA_PR5_VRPT-SWTS/code/src/main.cpp -o CMakeFiles/RutaRecoleccion.dir/src/main.cpp.s

CMakeFiles/RutaRecoleccion.dir/src/data-parser.cpp.o: CMakeFiles/RutaRecoleccion.dir/flags.make
CMakeFiles/RutaRecoleccion.dir/src/data-parser.cpp.o: ../src/data-parser.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/guillermo/DAA/DAA_PR5_VRPT-SWTS/code/debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/RutaRecoleccion.dir/src/data-parser.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/RutaRecoleccion.dir/src/data-parser.cpp.o -c /home/guillermo/DAA/DAA_PR5_VRPT-SWTS/code/src/data-parser.cpp

CMakeFiles/RutaRecoleccion.dir/src/data-parser.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/RutaRecoleccion.dir/src/data-parser.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/guillermo/DAA/DAA_PR5_VRPT-SWTS/code/src/data-parser.cpp > CMakeFiles/RutaRecoleccion.dir/src/data-parser.cpp.i

CMakeFiles/RutaRecoleccion.dir/src/data-parser.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/RutaRecoleccion.dir/src/data-parser.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/guillermo/DAA/DAA_PR5_VRPT-SWTS/code/src/data-parser.cpp -o CMakeFiles/RutaRecoleccion.dir/src/data-parser.cpp.s

CMakeFiles/RutaRecoleccion.dir/src/recolection-greedy-strategy.cpp.o: CMakeFiles/RutaRecoleccion.dir/flags.make
CMakeFiles/RutaRecoleccion.dir/src/recolection-greedy-strategy.cpp.o: ../src/recolection-greedy-strategy.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/guillermo/DAA/DAA_PR5_VRPT-SWTS/code/debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/RutaRecoleccion.dir/src/recolection-greedy-strategy.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/RutaRecoleccion.dir/src/recolection-greedy-strategy.cpp.o -c /home/guillermo/DAA/DAA_PR5_VRPT-SWTS/code/src/recolection-greedy-strategy.cpp

CMakeFiles/RutaRecoleccion.dir/src/recolection-greedy-strategy.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/RutaRecoleccion.dir/src/recolection-greedy-strategy.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/guillermo/DAA/DAA_PR5_VRPT-SWTS/code/src/recolection-greedy-strategy.cpp > CMakeFiles/RutaRecoleccion.dir/src/recolection-greedy-strategy.cpp.i

CMakeFiles/RutaRecoleccion.dir/src/recolection-greedy-strategy.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/RutaRecoleccion.dir/src/recolection-greedy-strategy.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/guillermo/DAA/DAA_PR5_VRPT-SWTS/code/src/recolection-greedy-strategy.cpp -o CMakeFiles/RutaRecoleccion.dir/src/recolection-greedy-strategy.cpp.s

CMakeFiles/RutaRecoleccion.dir/src/transport-vehicle.cpp.o: CMakeFiles/RutaRecoleccion.dir/flags.make
CMakeFiles/RutaRecoleccion.dir/src/transport-vehicle.cpp.o: ../src/transport-vehicle.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/guillermo/DAA/DAA_PR5_VRPT-SWTS/code/debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/RutaRecoleccion.dir/src/transport-vehicle.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/RutaRecoleccion.dir/src/transport-vehicle.cpp.o -c /home/guillermo/DAA/DAA_PR5_VRPT-SWTS/code/src/transport-vehicle.cpp

CMakeFiles/RutaRecoleccion.dir/src/transport-vehicle.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/RutaRecoleccion.dir/src/transport-vehicle.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/guillermo/DAA/DAA_PR5_VRPT-SWTS/code/src/transport-vehicle.cpp > CMakeFiles/RutaRecoleccion.dir/src/transport-vehicle.cpp.i

CMakeFiles/RutaRecoleccion.dir/src/transport-vehicle.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/RutaRecoleccion.dir/src/transport-vehicle.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/guillermo/DAA/DAA_PR5_VRPT-SWTS/code/src/transport-vehicle.cpp -o CMakeFiles/RutaRecoleccion.dir/src/transport-vehicle.cpp.s

CMakeFiles/RutaRecoleccion.dir/src/transport-greedy-strategy.cpp.o: CMakeFiles/RutaRecoleccion.dir/flags.make
CMakeFiles/RutaRecoleccion.dir/src/transport-greedy-strategy.cpp.o: ../src/transport-greedy-strategy.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/guillermo/DAA/DAA_PR5_VRPT-SWTS/code/debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/RutaRecoleccion.dir/src/transport-greedy-strategy.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/RutaRecoleccion.dir/src/transport-greedy-strategy.cpp.o -c /home/guillermo/DAA/DAA_PR5_VRPT-SWTS/code/src/transport-greedy-strategy.cpp

CMakeFiles/RutaRecoleccion.dir/src/transport-greedy-strategy.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/RutaRecoleccion.dir/src/transport-greedy-strategy.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/guillermo/DAA/DAA_PR5_VRPT-SWTS/code/src/transport-greedy-strategy.cpp > CMakeFiles/RutaRecoleccion.dir/src/transport-greedy-strategy.cpp.i

CMakeFiles/RutaRecoleccion.dir/src/transport-greedy-strategy.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/RutaRecoleccion.dir/src/transport-greedy-strategy.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/guillermo/DAA/DAA_PR5_VRPT-SWTS/code/src/transport-greedy-strategy.cpp -o CMakeFiles/RutaRecoleccion.dir/src/transport-greedy-strategy.cpp.s

CMakeFiles/RutaRecoleccion.dir/src/recolection-grasp-strategy.cpp.o: CMakeFiles/RutaRecoleccion.dir/flags.make
CMakeFiles/RutaRecoleccion.dir/src/recolection-grasp-strategy.cpp.o: ../src/recolection-grasp-strategy.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/guillermo/DAA/DAA_PR5_VRPT-SWTS/code/debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/RutaRecoleccion.dir/src/recolection-grasp-strategy.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/RutaRecoleccion.dir/src/recolection-grasp-strategy.cpp.o -c /home/guillermo/DAA/DAA_PR5_VRPT-SWTS/code/src/recolection-grasp-strategy.cpp

CMakeFiles/RutaRecoleccion.dir/src/recolection-grasp-strategy.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/RutaRecoleccion.dir/src/recolection-grasp-strategy.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/guillermo/DAA/DAA_PR5_VRPT-SWTS/code/src/recolection-grasp-strategy.cpp > CMakeFiles/RutaRecoleccion.dir/src/recolection-grasp-strategy.cpp.i

CMakeFiles/RutaRecoleccion.dir/src/recolection-grasp-strategy.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/RutaRecoleccion.dir/src/recolection-grasp-strategy.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/guillermo/DAA/DAA_PR5_VRPT-SWTS/code/src/recolection-grasp-strategy.cpp -o CMakeFiles/RutaRecoleccion.dir/src/recolection-grasp-strategy.cpp.s

CMakeFiles/RutaRecoleccion.dir/src/report-generator.cpp.o: CMakeFiles/RutaRecoleccion.dir/flags.make
CMakeFiles/RutaRecoleccion.dir/src/report-generator.cpp.o: ../src/report-generator.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/guillermo/DAA/DAA_PR5_VRPT-SWTS/code/debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/RutaRecoleccion.dir/src/report-generator.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/RutaRecoleccion.dir/src/report-generator.cpp.o -c /home/guillermo/DAA/DAA_PR5_VRPT-SWTS/code/src/report-generator.cpp

CMakeFiles/RutaRecoleccion.dir/src/report-generator.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/RutaRecoleccion.dir/src/report-generator.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/guillermo/DAA/DAA_PR5_VRPT-SWTS/code/src/report-generator.cpp > CMakeFiles/RutaRecoleccion.dir/src/report-generator.cpp.i

CMakeFiles/RutaRecoleccion.dir/src/report-generator.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/RutaRecoleccion.dir/src/report-generator.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/guillermo/DAA/DAA_PR5_VRPT-SWTS/code/src/report-generator.cpp -o CMakeFiles/RutaRecoleccion.dir/src/report-generator.cpp.s

CMakeFiles/RutaRecoleccion.dir/src/instance-processor.cpp.o: CMakeFiles/RutaRecoleccion.dir/flags.make
CMakeFiles/RutaRecoleccion.dir/src/instance-processor.cpp.o: ../src/instance-processor.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/guillermo/DAA/DAA_PR5_VRPT-SWTS/code/debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/RutaRecoleccion.dir/src/instance-processor.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/RutaRecoleccion.dir/src/instance-processor.cpp.o -c /home/guillermo/DAA/DAA_PR5_VRPT-SWTS/code/src/instance-processor.cpp

CMakeFiles/RutaRecoleccion.dir/src/instance-processor.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/RutaRecoleccion.dir/src/instance-processor.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/guillermo/DAA/DAA_PR5_VRPT-SWTS/code/src/instance-processor.cpp > CMakeFiles/RutaRecoleccion.dir/src/instance-processor.cpp.i

CMakeFiles/RutaRecoleccion.dir/src/instance-processor.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/RutaRecoleccion.dir/src/instance-processor.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/guillermo/DAA/DAA_PR5_VRPT-SWTS/code/src/instance-processor.cpp -o CMakeFiles/RutaRecoleccion.dir/src/instance-processor.cpp.s

CMakeFiles/RutaRecoleccion.dir/src/summary-generator.cpp.o: CMakeFiles/RutaRecoleccion.dir/flags.make
CMakeFiles/RutaRecoleccion.dir/src/summary-generator.cpp.o: ../src/summary-generator.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/guillermo/DAA/DAA_PR5_VRPT-SWTS/code/debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object CMakeFiles/RutaRecoleccion.dir/src/summary-generator.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/RutaRecoleccion.dir/src/summary-generator.cpp.o -c /home/guillermo/DAA/DAA_PR5_VRPT-SWTS/code/src/summary-generator.cpp

CMakeFiles/RutaRecoleccion.dir/src/summary-generator.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/RutaRecoleccion.dir/src/summary-generator.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/guillermo/DAA/DAA_PR5_VRPT-SWTS/code/src/summary-generator.cpp > CMakeFiles/RutaRecoleccion.dir/src/summary-generator.cpp.i

CMakeFiles/RutaRecoleccion.dir/src/summary-generator.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/RutaRecoleccion.dir/src/summary-generator.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/guillermo/DAA/DAA_PR5_VRPT-SWTS/code/src/summary-generator.cpp -o CMakeFiles/RutaRecoleccion.dir/src/summary-generator.cpp.s

# Object files for target RutaRecoleccion
RutaRecoleccion_OBJECTS = \
"CMakeFiles/RutaRecoleccion.dir/src/main.cpp.o" \
"CMakeFiles/RutaRecoleccion.dir/src/data-parser.cpp.o" \
"CMakeFiles/RutaRecoleccion.dir/src/recolection-greedy-strategy.cpp.o" \
"CMakeFiles/RutaRecoleccion.dir/src/transport-vehicle.cpp.o" \
"CMakeFiles/RutaRecoleccion.dir/src/transport-greedy-strategy.cpp.o" \
"CMakeFiles/RutaRecoleccion.dir/src/recolection-grasp-strategy.cpp.o" \
"CMakeFiles/RutaRecoleccion.dir/src/report-generator.cpp.o" \
"CMakeFiles/RutaRecoleccion.dir/src/instance-processor.cpp.o" \
"CMakeFiles/RutaRecoleccion.dir/src/summary-generator.cpp.o"

# External object files for target RutaRecoleccion
RutaRecoleccion_EXTERNAL_OBJECTS =

RutaRecoleccion: CMakeFiles/RutaRecoleccion.dir/src/main.cpp.o
RutaRecoleccion: CMakeFiles/RutaRecoleccion.dir/src/data-parser.cpp.o
RutaRecoleccion: CMakeFiles/RutaRecoleccion.dir/src/recolection-greedy-strategy.cpp.o
RutaRecoleccion: CMakeFiles/RutaRecoleccion.dir/src/transport-vehicle.cpp.o
RutaRecoleccion: CMakeFiles/RutaRecoleccion.dir/src/transport-greedy-strategy.cpp.o
RutaRecoleccion: CMakeFiles/RutaRecoleccion.dir/src/recolection-grasp-strategy.cpp.o
RutaRecoleccion: CMakeFiles/RutaRecoleccion.dir/src/report-generator.cpp.o
RutaRecoleccion: CMakeFiles/RutaRecoleccion.dir/src/instance-processor.cpp.o
RutaRecoleccion: CMakeFiles/RutaRecoleccion.dir/src/summary-generator.cpp.o
RutaRecoleccion: CMakeFiles/RutaRecoleccion.dir/build.make
RutaRecoleccion: CMakeFiles/RutaRecoleccion.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/guillermo/DAA/DAA_PR5_VRPT-SWTS/code/debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Linking CXX executable RutaRecoleccion"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/RutaRecoleccion.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/RutaRecoleccion.dir/build: RutaRecoleccion

.PHONY : CMakeFiles/RutaRecoleccion.dir/build

CMakeFiles/RutaRecoleccion.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/RutaRecoleccion.dir/cmake_clean.cmake
.PHONY : CMakeFiles/RutaRecoleccion.dir/clean

CMakeFiles/RutaRecoleccion.dir/depend:
	cd /home/guillermo/DAA/DAA_PR5_VRPT-SWTS/code/debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/guillermo/DAA/DAA_PR5_VRPT-SWTS/code /home/guillermo/DAA/DAA_PR5_VRPT-SWTS/code /home/guillermo/DAA/DAA_PR5_VRPT-SWTS/code/debug /home/guillermo/DAA/DAA_PR5_VRPT-SWTS/code/debug /home/guillermo/DAA/DAA_PR5_VRPT-SWTS/code/debug/CMakeFiles/RutaRecoleccion.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/RutaRecoleccion.dir/depend

