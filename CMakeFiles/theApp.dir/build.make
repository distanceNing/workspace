# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.8

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
CMAKE_COMMAND = /usr/local/bin/cmake

# The command to remove a file.
RM = /usr/local/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /root/workspace/workspace

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /root/workspace/workspace

# Include any dependencies generated for this target.
include CMakeFiles/theApp.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/theApp.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/theApp.dir/flags.make

CMakeFiles/theApp.dir/include/net/socket/tcp_socket.cpp.o: CMakeFiles/theApp.dir/flags.make
CMakeFiles/theApp.dir/include/net/socket/tcp_socket.cpp.o: include/net/socket/tcp_socket.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/root/workspace/workspace/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/theApp.dir/include/net/socket/tcp_socket.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/theApp.dir/include/net/socket/tcp_socket.cpp.o -c /root/workspace/workspace/include/net/socket/tcp_socket.cpp

CMakeFiles/theApp.dir/include/net/socket/tcp_socket.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/theApp.dir/include/net/socket/tcp_socket.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /root/workspace/workspace/include/net/socket/tcp_socket.cpp > CMakeFiles/theApp.dir/include/net/socket/tcp_socket.cpp.i

CMakeFiles/theApp.dir/include/net/socket/tcp_socket.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/theApp.dir/include/net/socket/tcp_socket.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /root/workspace/workspace/include/net/socket/tcp_socket.cpp -o CMakeFiles/theApp.dir/include/net/socket/tcp_socket.cpp.s

CMakeFiles/theApp.dir/include/net/socket/tcp_socket.cpp.o.requires:

.PHONY : CMakeFiles/theApp.dir/include/net/socket/tcp_socket.cpp.o.requires

CMakeFiles/theApp.dir/include/net/socket/tcp_socket.cpp.o.provides: CMakeFiles/theApp.dir/include/net/socket/tcp_socket.cpp.o.requires
	$(MAKE) -f CMakeFiles/theApp.dir/build.make CMakeFiles/theApp.dir/include/net/socket/tcp_socket.cpp.o.provides.build
.PHONY : CMakeFiles/theApp.dir/include/net/socket/tcp_socket.cpp.o.provides

CMakeFiles/theApp.dir/include/net/socket/tcp_socket.cpp.o.provides.build: CMakeFiles/theApp.dir/include/net/socket/tcp_socket.cpp.o


CMakeFiles/theApp.dir/src/config.cpp.o: CMakeFiles/theApp.dir/flags.make
CMakeFiles/theApp.dir/src/config.cpp.o: src/config.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/root/workspace/workspace/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/theApp.dir/src/config.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/theApp.dir/src/config.cpp.o -c /root/workspace/workspace/src/config.cpp

CMakeFiles/theApp.dir/src/config.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/theApp.dir/src/config.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /root/workspace/workspace/src/config.cpp > CMakeFiles/theApp.dir/src/config.cpp.i

CMakeFiles/theApp.dir/src/config.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/theApp.dir/src/config.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /root/workspace/workspace/src/config.cpp -o CMakeFiles/theApp.dir/src/config.cpp.s

CMakeFiles/theApp.dir/src/config.cpp.o.requires:

.PHONY : CMakeFiles/theApp.dir/src/config.cpp.o.requires

CMakeFiles/theApp.dir/src/config.cpp.o.provides: CMakeFiles/theApp.dir/src/config.cpp.o.requires
	$(MAKE) -f CMakeFiles/theApp.dir/build.make CMakeFiles/theApp.dir/src/config.cpp.o.provides.build
.PHONY : CMakeFiles/theApp.dir/src/config.cpp.o.provides

CMakeFiles/theApp.dir/src/config.cpp.o.provides.build: CMakeFiles/theApp.dir/src/config.cpp.o


CMakeFiles/theApp.dir/src/Protocol.cpp.o: CMakeFiles/theApp.dir/flags.make
CMakeFiles/theApp.dir/src/Protocol.cpp.o: src/Protocol.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/root/workspace/workspace/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/theApp.dir/src/Protocol.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/theApp.dir/src/Protocol.cpp.o -c /root/workspace/workspace/src/Protocol.cpp

CMakeFiles/theApp.dir/src/Protocol.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/theApp.dir/src/Protocol.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /root/workspace/workspace/src/Protocol.cpp > CMakeFiles/theApp.dir/src/Protocol.cpp.i

CMakeFiles/theApp.dir/src/Protocol.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/theApp.dir/src/Protocol.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /root/workspace/workspace/src/Protocol.cpp -o CMakeFiles/theApp.dir/src/Protocol.cpp.s

CMakeFiles/theApp.dir/src/Protocol.cpp.o.requires:

.PHONY : CMakeFiles/theApp.dir/src/Protocol.cpp.o.requires

CMakeFiles/theApp.dir/src/Protocol.cpp.o.provides: CMakeFiles/theApp.dir/src/Protocol.cpp.o.requires
	$(MAKE) -f CMakeFiles/theApp.dir/build.make CMakeFiles/theApp.dir/src/Protocol.cpp.o.provides.build
.PHONY : CMakeFiles/theApp.dir/src/Protocol.cpp.o.provides

CMakeFiles/theApp.dir/src/Protocol.cpp.o.provides.build: CMakeFiles/theApp.dir/src/Protocol.cpp.o


CMakeFiles/theApp.dir/src/producer.cpp.o: CMakeFiles/theApp.dir/flags.make
CMakeFiles/theApp.dir/src/producer.cpp.o: src/producer.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/root/workspace/workspace/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/theApp.dir/src/producer.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/theApp.dir/src/producer.cpp.o -c /root/workspace/workspace/src/producer.cpp

CMakeFiles/theApp.dir/src/producer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/theApp.dir/src/producer.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /root/workspace/workspace/src/producer.cpp > CMakeFiles/theApp.dir/src/producer.cpp.i

CMakeFiles/theApp.dir/src/producer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/theApp.dir/src/producer.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /root/workspace/workspace/src/producer.cpp -o CMakeFiles/theApp.dir/src/producer.cpp.s

CMakeFiles/theApp.dir/src/producer.cpp.o.requires:

.PHONY : CMakeFiles/theApp.dir/src/producer.cpp.o.requires

CMakeFiles/theApp.dir/src/producer.cpp.o.provides: CMakeFiles/theApp.dir/src/producer.cpp.o.requires
	$(MAKE) -f CMakeFiles/theApp.dir/build.make CMakeFiles/theApp.dir/src/producer.cpp.o.provides.build
.PHONY : CMakeFiles/theApp.dir/src/producer.cpp.o.provides

CMakeFiles/theApp.dir/src/producer.cpp.o.provides.build: CMakeFiles/theApp.dir/src/producer.cpp.o


CMakeFiles/theApp.dir/src/msg.cpp.o: CMakeFiles/theApp.dir/flags.make
CMakeFiles/theApp.dir/src/msg.cpp.o: src/msg.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/root/workspace/workspace/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/theApp.dir/src/msg.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/theApp.dir/src/msg.cpp.o -c /root/workspace/workspace/src/msg.cpp

CMakeFiles/theApp.dir/src/msg.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/theApp.dir/src/msg.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /root/workspace/workspace/src/msg.cpp > CMakeFiles/theApp.dir/src/msg.cpp.i

CMakeFiles/theApp.dir/src/msg.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/theApp.dir/src/msg.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /root/workspace/workspace/src/msg.cpp -o CMakeFiles/theApp.dir/src/msg.cpp.s

CMakeFiles/theApp.dir/src/msg.cpp.o.requires:

.PHONY : CMakeFiles/theApp.dir/src/msg.cpp.o.requires

CMakeFiles/theApp.dir/src/msg.cpp.o.provides: CMakeFiles/theApp.dir/src/msg.cpp.o.requires
	$(MAKE) -f CMakeFiles/theApp.dir/build.make CMakeFiles/theApp.dir/src/msg.cpp.o.provides.build
.PHONY : CMakeFiles/theApp.dir/src/msg.cpp.o.provides

CMakeFiles/theApp.dir/src/msg.cpp.o.provides.build: CMakeFiles/theApp.dir/src/msg.cpp.o


CMakeFiles/theApp.dir/src/consumer.cpp.o: CMakeFiles/theApp.dir/flags.make
CMakeFiles/theApp.dir/src/consumer.cpp.o: src/consumer.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/root/workspace/workspace/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/theApp.dir/src/consumer.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/theApp.dir/src/consumer.cpp.o -c /root/workspace/workspace/src/consumer.cpp

CMakeFiles/theApp.dir/src/consumer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/theApp.dir/src/consumer.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /root/workspace/workspace/src/consumer.cpp > CMakeFiles/theApp.dir/src/consumer.cpp.i

CMakeFiles/theApp.dir/src/consumer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/theApp.dir/src/consumer.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /root/workspace/workspace/src/consumer.cpp -o CMakeFiles/theApp.dir/src/consumer.cpp.s

CMakeFiles/theApp.dir/src/consumer.cpp.o.requires:

.PHONY : CMakeFiles/theApp.dir/src/consumer.cpp.o.requires

CMakeFiles/theApp.dir/src/consumer.cpp.o.provides: CMakeFiles/theApp.dir/src/consumer.cpp.o.requires
	$(MAKE) -f CMakeFiles/theApp.dir/build.make CMakeFiles/theApp.dir/src/consumer.cpp.o.provides.build
.PHONY : CMakeFiles/theApp.dir/src/consumer.cpp.o.provides

CMakeFiles/theApp.dir/src/consumer.cpp.o.provides.build: CMakeFiles/theApp.dir/src/consumer.cpp.o


CMakeFiles/theApp.dir/src/main.cpp.o: CMakeFiles/theApp.dir/flags.make
CMakeFiles/theApp.dir/src/main.cpp.o: src/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/root/workspace/workspace/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/theApp.dir/src/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/theApp.dir/src/main.cpp.o -c /root/workspace/workspace/src/main.cpp

CMakeFiles/theApp.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/theApp.dir/src/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /root/workspace/workspace/src/main.cpp > CMakeFiles/theApp.dir/src/main.cpp.i

CMakeFiles/theApp.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/theApp.dir/src/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /root/workspace/workspace/src/main.cpp -o CMakeFiles/theApp.dir/src/main.cpp.s

CMakeFiles/theApp.dir/src/main.cpp.o.requires:

.PHONY : CMakeFiles/theApp.dir/src/main.cpp.o.requires

CMakeFiles/theApp.dir/src/main.cpp.o.provides: CMakeFiles/theApp.dir/src/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/theApp.dir/build.make CMakeFiles/theApp.dir/src/main.cpp.o.provides.build
.PHONY : CMakeFiles/theApp.dir/src/main.cpp.o.provides

CMakeFiles/theApp.dir/src/main.cpp.o.provides.build: CMakeFiles/theApp.dir/src/main.cpp.o


# Object files for target theApp
theApp_OBJECTS = \
"CMakeFiles/theApp.dir/include/net/socket/tcp_socket.cpp.o" \
"CMakeFiles/theApp.dir/src/config.cpp.o" \
"CMakeFiles/theApp.dir/src/Protocol.cpp.o" \
"CMakeFiles/theApp.dir/src/producer.cpp.o" \
"CMakeFiles/theApp.dir/src/msg.cpp.o" \
"CMakeFiles/theApp.dir/src/consumer.cpp.o" \
"CMakeFiles/theApp.dir/src/main.cpp.o"

# External object files for target theApp
theApp_EXTERNAL_OBJECTS =

theApp: CMakeFiles/theApp.dir/include/net/socket/tcp_socket.cpp.o
theApp: CMakeFiles/theApp.dir/src/config.cpp.o
theApp: CMakeFiles/theApp.dir/src/Protocol.cpp.o
theApp: CMakeFiles/theApp.dir/src/producer.cpp.o
theApp: CMakeFiles/theApp.dir/src/msg.cpp.o
theApp: CMakeFiles/theApp.dir/src/consumer.cpp.o
theApp: CMakeFiles/theApp.dir/src/main.cpp.o
theApp: CMakeFiles/theApp.dir/build.make
theApp: CMakeFiles/theApp.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/root/workspace/workspace/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Linking CXX executable theApp"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/theApp.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/theApp.dir/build: theApp

.PHONY : CMakeFiles/theApp.dir/build

CMakeFiles/theApp.dir/requires: CMakeFiles/theApp.dir/include/net/socket/tcp_socket.cpp.o.requires
CMakeFiles/theApp.dir/requires: CMakeFiles/theApp.dir/src/config.cpp.o.requires
CMakeFiles/theApp.dir/requires: CMakeFiles/theApp.dir/src/Protocol.cpp.o.requires
CMakeFiles/theApp.dir/requires: CMakeFiles/theApp.dir/src/producer.cpp.o.requires
CMakeFiles/theApp.dir/requires: CMakeFiles/theApp.dir/src/msg.cpp.o.requires
CMakeFiles/theApp.dir/requires: CMakeFiles/theApp.dir/src/consumer.cpp.o.requires
CMakeFiles/theApp.dir/requires: CMakeFiles/theApp.dir/src/main.cpp.o.requires

.PHONY : CMakeFiles/theApp.dir/requires

CMakeFiles/theApp.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/theApp.dir/cmake_clean.cmake
.PHONY : CMakeFiles/theApp.dir/clean

CMakeFiles/theApp.dir/depend:
	cd /root/workspace/workspace && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /root/workspace/workspace /root/workspace/workspace /root/workspace/workspace /root/workspace/workspace /root/workspace/workspace/CMakeFiles/theApp.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/theApp.dir/depend
