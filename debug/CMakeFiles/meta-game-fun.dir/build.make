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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/pab/CodeProj/cxx_projects/CGLFA

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/pab/CodeProj/cxx_projects/CGLFA/debug

# Include any dependencies generated for this target.
include CMakeFiles/meta-game-fun.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/meta-game-fun.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/meta-game-fun.dir/flags.make

CMakeFiles/meta-game-fun.dir/src/main.cpp.o: CMakeFiles/meta-game-fun.dir/flags.make
CMakeFiles/meta-game-fun.dir/src/main.cpp.o: ../src/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/pab/CodeProj/cxx_projects/CGLFA/debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/meta-game-fun.dir/src/main.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/meta-game-fun.dir/src/main.cpp.o -c /home/pab/CodeProj/cxx_projects/CGLFA/src/main.cpp

CMakeFiles/meta-game-fun.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/meta-game-fun.dir/src/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/pab/CodeProj/cxx_projects/CGLFA/src/main.cpp > CMakeFiles/meta-game-fun.dir/src/main.cpp.i

CMakeFiles/meta-game-fun.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/meta-game-fun.dir/src/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/pab/CodeProj/cxx_projects/CGLFA/src/main.cpp -o CMakeFiles/meta-game-fun.dir/src/main.cpp.s

CMakeFiles/meta-game-fun.dir/src/misc/TileManager.cpp.o: CMakeFiles/meta-game-fun.dir/flags.make
CMakeFiles/meta-game-fun.dir/src/misc/TileManager.cpp.o: ../src/misc/TileManager.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/pab/CodeProj/cxx_projects/CGLFA/debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/meta-game-fun.dir/src/misc/TileManager.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/meta-game-fun.dir/src/misc/TileManager.cpp.o -c /home/pab/CodeProj/cxx_projects/CGLFA/src/misc/TileManager.cpp

CMakeFiles/meta-game-fun.dir/src/misc/TileManager.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/meta-game-fun.dir/src/misc/TileManager.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/pab/CodeProj/cxx_projects/CGLFA/src/misc/TileManager.cpp > CMakeFiles/meta-game-fun.dir/src/misc/TileManager.cpp.i

CMakeFiles/meta-game-fun.dir/src/misc/TileManager.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/meta-game-fun.dir/src/misc/TileManager.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/pab/CodeProj/cxx_projects/CGLFA/src/misc/TileManager.cpp -o CMakeFiles/meta-game-fun.dir/src/misc/TileManager.cpp.s

CMakeFiles/meta-game-fun.dir/src/misc/num_player_setter.cpp.o: CMakeFiles/meta-game-fun.dir/flags.make
CMakeFiles/meta-game-fun.dir/src/misc/num_player_setter.cpp.o: ../src/misc/num_player_setter.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/pab/CodeProj/cxx_projects/CGLFA/debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/meta-game-fun.dir/src/misc/num_player_setter.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/meta-game-fun.dir/src/misc/num_player_setter.cpp.o -c /home/pab/CodeProj/cxx_projects/CGLFA/src/misc/num_player_setter.cpp

CMakeFiles/meta-game-fun.dir/src/misc/num_player_setter.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/meta-game-fun.dir/src/misc/num_player_setter.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/pab/CodeProj/cxx_projects/CGLFA/src/misc/num_player_setter.cpp > CMakeFiles/meta-game-fun.dir/src/misc/num_player_setter.cpp.i

CMakeFiles/meta-game-fun.dir/src/misc/num_player_setter.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/meta-game-fun.dir/src/misc/num_player_setter.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/pab/CodeProj/cxx_projects/CGLFA/src/misc/num_player_setter.cpp -o CMakeFiles/meta-game-fun.dir/src/misc/num_player_setter.cpp.s

CMakeFiles/meta-game-fun.dir/src/misc/globalvariables.cpp.o: CMakeFiles/meta-game-fun.dir/flags.make
CMakeFiles/meta-game-fun.dir/src/misc/globalvariables.cpp.o: ../src/misc/globalvariables.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/pab/CodeProj/cxx_projects/CGLFA/debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/meta-game-fun.dir/src/misc/globalvariables.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/meta-game-fun.dir/src/misc/globalvariables.cpp.o -c /home/pab/CodeProj/cxx_projects/CGLFA/src/misc/globalvariables.cpp

CMakeFiles/meta-game-fun.dir/src/misc/globalvariables.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/meta-game-fun.dir/src/misc/globalvariables.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/pab/CodeProj/cxx_projects/CGLFA/src/misc/globalvariables.cpp > CMakeFiles/meta-game-fun.dir/src/misc/globalvariables.cpp.i

CMakeFiles/meta-game-fun.dir/src/misc/globalvariables.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/meta-game-fun.dir/src/misc/globalvariables.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/pab/CodeProj/cxx_projects/CGLFA/src/misc/globalvariables.cpp -o CMakeFiles/meta-game-fun.dir/src/misc/globalvariables.cpp.s

CMakeFiles/meta-game-fun.dir/src/misc/MediaLoader.cpp.o: CMakeFiles/meta-game-fun.dir/flags.make
CMakeFiles/meta-game-fun.dir/src/misc/MediaLoader.cpp.o: ../src/misc/MediaLoader.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/pab/CodeProj/cxx_projects/CGLFA/debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/meta-game-fun.dir/src/misc/MediaLoader.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/meta-game-fun.dir/src/misc/MediaLoader.cpp.o -c /home/pab/CodeProj/cxx_projects/CGLFA/src/misc/MediaLoader.cpp

CMakeFiles/meta-game-fun.dir/src/misc/MediaLoader.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/meta-game-fun.dir/src/misc/MediaLoader.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/pab/CodeProj/cxx_projects/CGLFA/src/misc/MediaLoader.cpp > CMakeFiles/meta-game-fun.dir/src/misc/MediaLoader.cpp.i

CMakeFiles/meta-game-fun.dir/src/misc/MediaLoader.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/meta-game-fun.dir/src/misc/MediaLoader.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/pab/CodeProj/cxx_projects/CGLFA/src/misc/MediaLoader.cpp -o CMakeFiles/meta-game-fun.dir/src/misc/MediaLoader.cpp.s

CMakeFiles/meta-game-fun.dir/src/misc/char_creator.cpp.o: CMakeFiles/meta-game-fun.dir/flags.make
CMakeFiles/meta-game-fun.dir/src/misc/char_creator.cpp.o: ../src/misc/char_creator.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/pab/CodeProj/cxx_projects/CGLFA/debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/meta-game-fun.dir/src/misc/char_creator.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/meta-game-fun.dir/src/misc/char_creator.cpp.o -c /home/pab/CodeProj/cxx_projects/CGLFA/src/misc/char_creator.cpp

CMakeFiles/meta-game-fun.dir/src/misc/char_creator.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/meta-game-fun.dir/src/misc/char_creator.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/pab/CodeProj/cxx_projects/CGLFA/src/misc/char_creator.cpp > CMakeFiles/meta-game-fun.dir/src/misc/char_creator.cpp.i

CMakeFiles/meta-game-fun.dir/src/misc/char_creator.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/meta-game-fun.dir/src/misc/char_creator.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/pab/CodeProj/cxx_projects/CGLFA/src/misc/char_creator.cpp -o CMakeFiles/meta-game-fun.dir/src/misc/char_creator.cpp.s

CMakeFiles/meta-game-fun.dir/src/systems/PhysicsSystem.cpp.o: CMakeFiles/meta-game-fun.dir/flags.make
CMakeFiles/meta-game-fun.dir/src/systems/PhysicsSystem.cpp.o: ../src/systems/PhysicsSystem.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/pab/CodeProj/cxx_projects/CGLFA/debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/meta-game-fun.dir/src/systems/PhysicsSystem.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/meta-game-fun.dir/src/systems/PhysicsSystem.cpp.o -c /home/pab/CodeProj/cxx_projects/CGLFA/src/systems/PhysicsSystem.cpp

CMakeFiles/meta-game-fun.dir/src/systems/PhysicsSystem.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/meta-game-fun.dir/src/systems/PhysicsSystem.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/pab/CodeProj/cxx_projects/CGLFA/src/systems/PhysicsSystem.cpp > CMakeFiles/meta-game-fun.dir/src/systems/PhysicsSystem.cpp.i

CMakeFiles/meta-game-fun.dir/src/systems/PhysicsSystem.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/meta-game-fun.dir/src/systems/PhysicsSystem.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/pab/CodeProj/cxx_projects/CGLFA/src/systems/PhysicsSystem.cpp -o CMakeFiles/meta-game-fun.dir/src/systems/PhysicsSystem.cpp.s

CMakeFiles/meta-game-fun.dir/src/systems/WorldSystem.cpp.o: CMakeFiles/meta-game-fun.dir/flags.make
CMakeFiles/meta-game-fun.dir/src/systems/WorldSystem.cpp.o: ../src/systems/WorldSystem.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/pab/CodeProj/cxx_projects/CGLFA/debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/meta-game-fun.dir/src/systems/WorldSystem.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/meta-game-fun.dir/src/systems/WorldSystem.cpp.o -c /home/pab/CodeProj/cxx_projects/CGLFA/src/systems/WorldSystem.cpp

CMakeFiles/meta-game-fun.dir/src/systems/WorldSystem.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/meta-game-fun.dir/src/systems/WorldSystem.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/pab/CodeProj/cxx_projects/CGLFA/src/systems/WorldSystem.cpp > CMakeFiles/meta-game-fun.dir/src/systems/WorldSystem.cpp.i

CMakeFiles/meta-game-fun.dir/src/systems/WorldSystem.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/meta-game-fun.dir/src/systems/WorldSystem.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/pab/CodeProj/cxx_projects/CGLFA/src/systems/WorldSystem.cpp -o CMakeFiles/meta-game-fun.dir/src/systems/WorldSystem.cpp.s

CMakeFiles/meta-game-fun.dir/src/systems/CameraSystem.cpp.o: CMakeFiles/meta-game-fun.dir/flags.make
CMakeFiles/meta-game-fun.dir/src/systems/CameraSystem.cpp.o: ../src/systems/CameraSystem.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/pab/CodeProj/cxx_projects/CGLFA/debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object CMakeFiles/meta-game-fun.dir/src/systems/CameraSystem.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/meta-game-fun.dir/src/systems/CameraSystem.cpp.o -c /home/pab/CodeProj/cxx_projects/CGLFA/src/systems/CameraSystem.cpp

CMakeFiles/meta-game-fun.dir/src/systems/CameraSystem.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/meta-game-fun.dir/src/systems/CameraSystem.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/pab/CodeProj/cxx_projects/CGLFA/src/systems/CameraSystem.cpp > CMakeFiles/meta-game-fun.dir/src/systems/CameraSystem.cpp.i

CMakeFiles/meta-game-fun.dir/src/systems/CameraSystem.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/meta-game-fun.dir/src/systems/CameraSystem.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/pab/CodeProj/cxx_projects/CGLFA/src/systems/CameraSystem.cpp -o CMakeFiles/meta-game-fun.dir/src/systems/CameraSystem.cpp.s

CMakeFiles/meta-game-fun.dir/src/systems/AnimationSystem.cpp.o: CMakeFiles/meta-game-fun.dir/flags.make
CMakeFiles/meta-game-fun.dir/src/systems/AnimationSystem.cpp.o: ../src/systems/AnimationSystem.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/pab/CodeProj/cxx_projects/CGLFA/debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Building CXX object CMakeFiles/meta-game-fun.dir/src/systems/AnimationSystem.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/meta-game-fun.dir/src/systems/AnimationSystem.cpp.o -c /home/pab/CodeProj/cxx_projects/CGLFA/src/systems/AnimationSystem.cpp

CMakeFiles/meta-game-fun.dir/src/systems/AnimationSystem.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/meta-game-fun.dir/src/systems/AnimationSystem.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/pab/CodeProj/cxx_projects/CGLFA/src/systems/AnimationSystem.cpp > CMakeFiles/meta-game-fun.dir/src/systems/AnimationSystem.cpp.i

CMakeFiles/meta-game-fun.dir/src/systems/AnimationSystem.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/meta-game-fun.dir/src/systems/AnimationSystem.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/pab/CodeProj/cxx_projects/CGLFA/src/systems/AnimationSystem.cpp -o CMakeFiles/meta-game-fun.dir/src/systems/AnimationSystem.cpp.s

CMakeFiles/meta-game-fun.dir/src/systems/RenderSystem.cpp.o: CMakeFiles/meta-game-fun.dir/flags.make
CMakeFiles/meta-game-fun.dir/src/systems/RenderSystem.cpp.o: ../src/systems/RenderSystem.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/pab/CodeProj/cxx_projects/CGLFA/debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_11) "Building CXX object CMakeFiles/meta-game-fun.dir/src/systems/RenderSystem.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/meta-game-fun.dir/src/systems/RenderSystem.cpp.o -c /home/pab/CodeProj/cxx_projects/CGLFA/src/systems/RenderSystem.cpp

CMakeFiles/meta-game-fun.dir/src/systems/RenderSystem.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/meta-game-fun.dir/src/systems/RenderSystem.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/pab/CodeProj/cxx_projects/CGLFA/src/systems/RenderSystem.cpp > CMakeFiles/meta-game-fun.dir/src/systems/RenderSystem.cpp.i

CMakeFiles/meta-game-fun.dir/src/systems/RenderSystem.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/meta-game-fun.dir/src/systems/RenderSystem.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/pab/CodeProj/cxx_projects/CGLFA/src/systems/RenderSystem.cpp -o CMakeFiles/meta-game-fun.dir/src/systems/RenderSystem.cpp.s

CMakeFiles/meta-game-fun.dir/src/systems/InputReactorSystem.cpp.o: CMakeFiles/meta-game-fun.dir/flags.make
CMakeFiles/meta-game-fun.dir/src/systems/InputReactorSystem.cpp.o: ../src/systems/InputReactorSystem.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/pab/CodeProj/cxx_projects/CGLFA/debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_12) "Building CXX object CMakeFiles/meta-game-fun.dir/src/systems/InputReactorSystem.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/meta-game-fun.dir/src/systems/InputReactorSystem.cpp.o -c /home/pab/CodeProj/cxx_projects/CGLFA/src/systems/InputReactorSystem.cpp

CMakeFiles/meta-game-fun.dir/src/systems/InputReactorSystem.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/meta-game-fun.dir/src/systems/InputReactorSystem.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/pab/CodeProj/cxx_projects/CGLFA/src/systems/InputReactorSystem.cpp > CMakeFiles/meta-game-fun.dir/src/systems/InputReactorSystem.cpp.i

CMakeFiles/meta-game-fun.dir/src/systems/InputReactorSystem.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/meta-game-fun.dir/src/systems/InputReactorSystem.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/pab/CodeProj/cxx_projects/CGLFA/src/systems/InputReactorSystem.cpp -o CMakeFiles/meta-game-fun.dir/src/systems/InputReactorSystem.cpp.s

CMakeFiles/meta-game-fun.dir/src/systems/EnemySystem.cpp.o: CMakeFiles/meta-game-fun.dir/flags.make
CMakeFiles/meta-game-fun.dir/src/systems/EnemySystem.cpp.o: ../src/systems/EnemySystem.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/pab/CodeProj/cxx_projects/CGLFA/debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_13) "Building CXX object CMakeFiles/meta-game-fun.dir/src/systems/EnemySystem.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/meta-game-fun.dir/src/systems/EnemySystem.cpp.o -c /home/pab/CodeProj/cxx_projects/CGLFA/src/systems/EnemySystem.cpp

CMakeFiles/meta-game-fun.dir/src/systems/EnemySystem.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/meta-game-fun.dir/src/systems/EnemySystem.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/pab/CodeProj/cxx_projects/CGLFA/src/systems/EnemySystem.cpp > CMakeFiles/meta-game-fun.dir/src/systems/EnemySystem.cpp.i

CMakeFiles/meta-game-fun.dir/src/systems/EnemySystem.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/meta-game-fun.dir/src/systems/EnemySystem.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/pab/CodeProj/cxx_projects/CGLFA/src/systems/EnemySystem.cpp -o CMakeFiles/meta-game-fun.dir/src/systems/EnemySystem.cpp.s

CMakeFiles/meta-game-fun.dir/src/core/ControllerInputHandler.cpp.o: CMakeFiles/meta-game-fun.dir/flags.make
CMakeFiles/meta-game-fun.dir/src/core/ControllerInputHandler.cpp.o: ../src/core/ControllerInputHandler.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/pab/CodeProj/cxx_projects/CGLFA/debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_14) "Building CXX object CMakeFiles/meta-game-fun.dir/src/core/ControllerInputHandler.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/meta-game-fun.dir/src/core/ControllerInputHandler.cpp.o -c /home/pab/CodeProj/cxx_projects/CGLFA/src/core/ControllerInputHandler.cpp

CMakeFiles/meta-game-fun.dir/src/core/ControllerInputHandler.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/meta-game-fun.dir/src/core/ControllerInputHandler.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/pab/CodeProj/cxx_projects/CGLFA/src/core/ControllerInputHandler.cpp > CMakeFiles/meta-game-fun.dir/src/core/ControllerInputHandler.cpp.i

CMakeFiles/meta-game-fun.dir/src/core/ControllerInputHandler.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/meta-game-fun.dir/src/core/ControllerInputHandler.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/pab/CodeProj/cxx_projects/CGLFA/src/core/ControllerInputHandler.cpp -o CMakeFiles/meta-game-fun.dir/src/core/ControllerInputHandler.cpp.s

CMakeFiles/meta-game-fun.dir/src/core/KeyboardTypingInputHandler.cpp.o: CMakeFiles/meta-game-fun.dir/flags.make
CMakeFiles/meta-game-fun.dir/src/core/KeyboardTypingInputHandler.cpp.o: ../src/core/KeyboardTypingInputHandler.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/pab/CodeProj/cxx_projects/CGLFA/debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_15) "Building CXX object CMakeFiles/meta-game-fun.dir/src/core/KeyboardTypingInputHandler.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/meta-game-fun.dir/src/core/KeyboardTypingInputHandler.cpp.o -c /home/pab/CodeProj/cxx_projects/CGLFA/src/core/KeyboardTypingInputHandler.cpp

CMakeFiles/meta-game-fun.dir/src/core/KeyboardTypingInputHandler.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/meta-game-fun.dir/src/core/KeyboardTypingInputHandler.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/pab/CodeProj/cxx_projects/CGLFA/src/core/KeyboardTypingInputHandler.cpp > CMakeFiles/meta-game-fun.dir/src/core/KeyboardTypingInputHandler.cpp.i

CMakeFiles/meta-game-fun.dir/src/core/KeyboardTypingInputHandler.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/meta-game-fun.dir/src/core/KeyboardTypingInputHandler.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/pab/CodeProj/cxx_projects/CGLFA/src/core/KeyboardTypingInputHandler.cpp -o CMakeFiles/meta-game-fun.dir/src/core/KeyboardTypingInputHandler.cpp.s

# Object files for target meta-game-fun
meta__game__fun_OBJECTS = \
"CMakeFiles/meta-game-fun.dir/src/main.cpp.o" \
"CMakeFiles/meta-game-fun.dir/src/misc/TileManager.cpp.o" \
"CMakeFiles/meta-game-fun.dir/src/misc/num_player_setter.cpp.o" \
"CMakeFiles/meta-game-fun.dir/src/misc/globalvariables.cpp.o" \
"CMakeFiles/meta-game-fun.dir/src/misc/MediaLoader.cpp.o" \
"CMakeFiles/meta-game-fun.dir/src/misc/char_creator.cpp.o" \
"CMakeFiles/meta-game-fun.dir/src/systems/PhysicsSystem.cpp.o" \
"CMakeFiles/meta-game-fun.dir/src/systems/WorldSystem.cpp.o" \
"CMakeFiles/meta-game-fun.dir/src/systems/CameraSystem.cpp.o" \
"CMakeFiles/meta-game-fun.dir/src/systems/AnimationSystem.cpp.o" \
"CMakeFiles/meta-game-fun.dir/src/systems/RenderSystem.cpp.o" \
"CMakeFiles/meta-game-fun.dir/src/systems/InputReactorSystem.cpp.o" \
"CMakeFiles/meta-game-fun.dir/src/systems/EnemySystem.cpp.o" \
"CMakeFiles/meta-game-fun.dir/src/core/ControllerInputHandler.cpp.o" \
"CMakeFiles/meta-game-fun.dir/src/core/KeyboardTypingInputHandler.cpp.o"

# External object files for target meta-game-fun
meta__game__fun_EXTERNAL_OBJECTS =

meta-game-fun: CMakeFiles/meta-game-fun.dir/src/main.cpp.o
meta-game-fun: CMakeFiles/meta-game-fun.dir/src/misc/TileManager.cpp.o
meta-game-fun: CMakeFiles/meta-game-fun.dir/src/misc/num_player_setter.cpp.o
meta-game-fun: CMakeFiles/meta-game-fun.dir/src/misc/globalvariables.cpp.o
meta-game-fun: CMakeFiles/meta-game-fun.dir/src/misc/MediaLoader.cpp.o
meta-game-fun: CMakeFiles/meta-game-fun.dir/src/misc/char_creator.cpp.o
meta-game-fun: CMakeFiles/meta-game-fun.dir/src/systems/PhysicsSystem.cpp.o
meta-game-fun: CMakeFiles/meta-game-fun.dir/src/systems/WorldSystem.cpp.o
meta-game-fun: CMakeFiles/meta-game-fun.dir/src/systems/CameraSystem.cpp.o
meta-game-fun: CMakeFiles/meta-game-fun.dir/src/systems/AnimationSystem.cpp.o
meta-game-fun: CMakeFiles/meta-game-fun.dir/src/systems/RenderSystem.cpp.o
meta-game-fun: CMakeFiles/meta-game-fun.dir/src/systems/InputReactorSystem.cpp.o
meta-game-fun: CMakeFiles/meta-game-fun.dir/src/systems/EnemySystem.cpp.o
meta-game-fun: CMakeFiles/meta-game-fun.dir/src/core/ControllerInputHandler.cpp.o
meta-game-fun: CMakeFiles/meta-game-fun.dir/src/core/KeyboardTypingInputHandler.cpp.o
meta-game-fun: CMakeFiles/meta-game-fun.dir/build.make
meta-game-fun: /usr/local/lib/libraylib.so
meta-game-fun: /usr/lib/libpugixml.so
meta-game-fun: CMakeFiles/meta-game-fun.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/pab/CodeProj/cxx_projects/CGLFA/debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_16) "Linking CXX executable meta-game-fun"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/meta-game-fun.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/meta-game-fun.dir/build: meta-game-fun

.PHONY : CMakeFiles/meta-game-fun.dir/build

CMakeFiles/meta-game-fun.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/meta-game-fun.dir/cmake_clean.cmake
.PHONY : CMakeFiles/meta-game-fun.dir/clean

CMakeFiles/meta-game-fun.dir/depend:
	cd /home/pab/CodeProj/cxx_projects/CGLFA/debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/pab/CodeProj/cxx_projects/CGLFA /home/pab/CodeProj/cxx_projects/CGLFA /home/pab/CodeProj/cxx_projects/CGLFA/debug /home/pab/CodeProj/cxx_projects/CGLFA/debug /home/pab/CodeProj/cxx_projects/CGLFA/debug/CMakeFiles/meta-game-fun.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/meta-game-fun.dir/depend
