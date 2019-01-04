# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.8

# Default target executed when no arguments are given to make.
default_target: all

.PHONY : default_target

# Allow only one "make -f Makefile2" at a time, but pass parallelism.
.NOTPARALLEL:


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

#=============================================================================
# Targets provided globally by CMake.

# Special rule for the target rebuild_cache
rebuild_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake to regenerate build system..."
	/usr/local/bin/cmake -H$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : rebuild_cache

# Special rule for the target rebuild_cache
rebuild_cache/fast: rebuild_cache

.PHONY : rebuild_cache/fast

# Special rule for the target edit_cache
edit_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "No interactive CMake dialog available..."
	/usr/local/bin/cmake -E echo No\ interactive\ CMake\ dialog\ available.
.PHONY : edit_cache

# Special rule for the target edit_cache
edit_cache/fast: edit_cache

.PHONY : edit_cache/fast

# The main all target
all: cmake_check_build_system
	$(CMAKE_COMMAND) -E cmake_progress_start /root/workspace/workspace/CMakeFiles /root/workspace/workspace/CMakeFiles/progress.marks
	$(MAKE) -f CMakeFiles/Makefile2 all
	$(CMAKE_COMMAND) -E cmake_progress_start /root/workspace/workspace/CMakeFiles 0
.PHONY : all

# The main clean target
clean:
	$(MAKE) -f CMakeFiles/Makefile2 clean
.PHONY : clean

# The main clean target
clean/fast: clean

.PHONY : clean/fast

# Prepare targets for installation.
preinstall: all
	$(MAKE) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall

# Prepare targets for installation.
preinstall/fast:
	$(MAKE) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall/fast

# clear depends
depend:
	$(CMAKE_COMMAND) -H$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 1
.PHONY : depend

#=============================================================================
# Target rules for targets named theApp

# Build rule for target.
theApp: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 theApp
.PHONY : theApp

# fast build rule for target.
theApp/fast:
	$(MAKE) -f CMakeFiles/theApp.dir/build.make CMakeFiles/theApp.dir/build
.PHONY : theApp/fast

include/net/socket/tcp_socket.o: include/net/socket/tcp_socket.cpp.o

.PHONY : include/net/socket/tcp_socket.o

# target to build an object file
include/net/socket/tcp_socket.cpp.o:
	$(MAKE) -f CMakeFiles/theApp.dir/build.make CMakeFiles/theApp.dir/include/net/socket/tcp_socket.cpp.o
.PHONY : include/net/socket/tcp_socket.cpp.o

include/net/socket/tcp_socket.i: include/net/socket/tcp_socket.cpp.i

.PHONY : include/net/socket/tcp_socket.i

# target to preprocess a source file
include/net/socket/tcp_socket.cpp.i:
	$(MAKE) -f CMakeFiles/theApp.dir/build.make CMakeFiles/theApp.dir/include/net/socket/tcp_socket.cpp.i
.PHONY : include/net/socket/tcp_socket.cpp.i

include/net/socket/tcp_socket.s: include/net/socket/tcp_socket.cpp.s

.PHONY : include/net/socket/tcp_socket.s

# target to generate assembly for a file
include/net/socket/tcp_socket.cpp.s:
	$(MAKE) -f CMakeFiles/theApp.dir/build.make CMakeFiles/theApp.dir/include/net/socket/tcp_socket.cpp.s
.PHONY : include/net/socket/tcp_socket.cpp.s

src/Protocol.o: src/Protocol.cpp.o

.PHONY : src/Protocol.o

# target to build an object file
src/Protocol.cpp.o:
	$(MAKE) -f CMakeFiles/theApp.dir/build.make CMakeFiles/theApp.dir/src/Protocol.cpp.o
.PHONY : src/Protocol.cpp.o

src/Protocol.i: src/Protocol.cpp.i

.PHONY : src/Protocol.i

# target to preprocess a source file
src/Protocol.cpp.i:
	$(MAKE) -f CMakeFiles/theApp.dir/build.make CMakeFiles/theApp.dir/src/Protocol.cpp.i
.PHONY : src/Protocol.cpp.i

src/Protocol.s: src/Protocol.cpp.s

.PHONY : src/Protocol.s

# target to generate assembly for a file
src/Protocol.cpp.s:
	$(MAKE) -f CMakeFiles/theApp.dir/build.make CMakeFiles/theApp.dir/src/Protocol.cpp.s
.PHONY : src/Protocol.cpp.s

src/config.o: src/config.cpp.o

.PHONY : src/config.o

# target to build an object file
src/config.cpp.o:
	$(MAKE) -f CMakeFiles/theApp.dir/build.make CMakeFiles/theApp.dir/src/config.cpp.o
.PHONY : src/config.cpp.o

src/config.i: src/config.cpp.i

.PHONY : src/config.i

# target to preprocess a source file
src/config.cpp.i:
	$(MAKE) -f CMakeFiles/theApp.dir/build.make CMakeFiles/theApp.dir/src/config.cpp.i
.PHONY : src/config.cpp.i

src/config.s: src/config.cpp.s

.PHONY : src/config.s

# target to generate assembly for a file
src/config.cpp.s:
	$(MAKE) -f CMakeFiles/theApp.dir/build.make CMakeFiles/theApp.dir/src/config.cpp.s
.PHONY : src/config.cpp.s

src/consumer.o: src/consumer.cpp.o

.PHONY : src/consumer.o

# target to build an object file
src/consumer.cpp.o:
	$(MAKE) -f CMakeFiles/theApp.dir/build.make CMakeFiles/theApp.dir/src/consumer.cpp.o
.PHONY : src/consumer.cpp.o

src/consumer.i: src/consumer.cpp.i

.PHONY : src/consumer.i

# target to preprocess a source file
src/consumer.cpp.i:
	$(MAKE) -f CMakeFiles/theApp.dir/build.make CMakeFiles/theApp.dir/src/consumer.cpp.i
.PHONY : src/consumer.cpp.i

src/consumer.s: src/consumer.cpp.s

.PHONY : src/consumer.s

# target to generate assembly for a file
src/consumer.cpp.s:
	$(MAKE) -f CMakeFiles/theApp.dir/build.make CMakeFiles/theApp.dir/src/consumer.cpp.s
.PHONY : src/consumer.cpp.s

src/main.o: src/main.cpp.o

.PHONY : src/main.o

# target to build an object file
src/main.cpp.o:
	$(MAKE) -f CMakeFiles/theApp.dir/build.make CMakeFiles/theApp.dir/src/main.cpp.o
.PHONY : src/main.cpp.o

src/main.i: src/main.cpp.i

.PHONY : src/main.i

# target to preprocess a source file
src/main.cpp.i:
	$(MAKE) -f CMakeFiles/theApp.dir/build.make CMakeFiles/theApp.dir/src/main.cpp.i
.PHONY : src/main.cpp.i

src/main.s: src/main.cpp.s

.PHONY : src/main.s

# target to generate assembly for a file
src/main.cpp.s:
	$(MAKE) -f CMakeFiles/theApp.dir/build.make CMakeFiles/theApp.dir/src/main.cpp.s
.PHONY : src/main.cpp.s

src/msg.o: src/msg.cpp.o

.PHONY : src/msg.o

# target to build an object file
src/msg.cpp.o:
	$(MAKE) -f CMakeFiles/theApp.dir/build.make CMakeFiles/theApp.dir/src/msg.cpp.o
.PHONY : src/msg.cpp.o

src/msg.i: src/msg.cpp.i

.PHONY : src/msg.i

# target to preprocess a source file
src/msg.cpp.i:
	$(MAKE) -f CMakeFiles/theApp.dir/build.make CMakeFiles/theApp.dir/src/msg.cpp.i
.PHONY : src/msg.cpp.i

src/msg.s: src/msg.cpp.s

.PHONY : src/msg.s

# target to generate assembly for a file
src/msg.cpp.s:
	$(MAKE) -f CMakeFiles/theApp.dir/build.make CMakeFiles/theApp.dir/src/msg.cpp.s
.PHONY : src/msg.cpp.s

src/producer.o: src/producer.cpp.o

.PHONY : src/producer.o

# target to build an object file
src/producer.cpp.o:
	$(MAKE) -f CMakeFiles/theApp.dir/build.make CMakeFiles/theApp.dir/src/producer.cpp.o
.PHONY : src/producer.cpp.o

src/producer.i: src/producer.cpp.i

.PHONY : src/producer.i

# target to preprocess a source file
src/producer.cpp.i:
	$(MAKE) -f CMakeFiles/theApp.dir/build.make CMakeFiles/theApp.dir/src/producer.cpp.i
.PHONY : src/producer.cpp.i

src/producer.s: src/producer.cpp.s

.PHONY : src/producer.s

# target to generate assembly for a file
src/producer.cpp.s:
	$(MAKE) -f CMakeFiles/theApp.dir/build.make CMakeFiles/theApp.dir/src/producer.cpp.s
.PHONY : src/producer.cpp.s

# Help Target
help:
	@echo "The following are some of the valid targets for this Makefile:"
	@echo "... all (the default if no target is provided)"
	@echo "... clean"
	@echo "... depend"
	@echo "... rebuild_cache"
	@echo "... edit_cache"
	@echo "... theApp"
	@echo "... include/net/socket/tcp_socket.o"
	@echo "... include/net/socket/tcp_socket.i"
	@echo "... include/net/socket/tcp_socket.s"
	@echo "... src/Protocol.o"
	@echo "... src/Protocol.i"
	@echo "... src/Protocol.s"
	@echo "... src/config.o"
	@echo "... src/config.i"
	@echo "... src/config.s"
	@echo "... src/consumer.o"
	@echo "... src/consumer.i"
	@echo "... src/consumer.s"
	@echo "... src/main.o"
	@echo "... src/main.i"
	@echo "... src/main.s"
	@echo "... src/msg.o"
	@echo "... src/msg.i"
	@echo "... src/msg.s"
	@echo "... src/producer.o"
	@echo "... src/producer.i"
	@echo "... src/producer.s"
.PHONY : help



#=============================================================================
# Special targets to cleanup operation of make.

# Special rule to run CMake to check the build system integrity.
# No rule that depends on this can have commands that come from listfiles
# because they might be regenerated.
cmake_check_build_system:
	$(CMAKE_COMMAND) -H$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 0
.PHONY : cmake_check_build_system

