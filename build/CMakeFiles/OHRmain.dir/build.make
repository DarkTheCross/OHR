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
CMAKE_COMMAND = /usr/local/Cellar/cmake/3.8.2/bin/cmake

# The command to remove a file.
RM = /usr/local/Cellar/cmake/3.8.2/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/mingxiangfan/Documents/programming/c++/OHR/OHR

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/mingxiangfan/Documents/programming/c++/OHR/OHR/build

# Include any dependencies generated for this target.
include CMakeFiles/OHRmain.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/OHRmain.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/OHRmain.dir/flags.make

CMakeFiles/OHRmain.dir/main.cpp.o: CMakeFiles/OHRmain.dir/flags.make
CMakeFiles/OHRmain.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/mingxiangfan/Documents/programming/c++/OHR/OHR/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/OHRmain.dir/main.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/OHRmain.dir/main.cpp.o -c /Users/mingxiangfan/Documents/programming/c++/OHR/OHR/main.cpp

CMakeFiles/OHRmain.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/OHRmain.dir/main.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/mingxiangfan/Documents/programming/c++/OHR/OHR/main.cpp > CMakeFiles/OHRmain.dir/main.cpp.i

CMakeFiles/OHRmain.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/OHRmain.dir/main.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/mingxiangfan/Documents/programming/c++/OHR/OHR/main.cpp -o CMakeFiles/OHRmain.dir/main.cpp.s

CMakeFiles/OHRmain.dir/main.cpp.o.requires:

.PHONY : CMakeFiles/OHRmain.dir/main.cpp.o.requires

CMakeFiles/OHRmain.dir/main.cpp.o.provides: CMakeFiles/OHRmain.dir/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/OHRmain.dir/build.make CMakeFiles/OHRmain.dir/main.cpp.o.provides.build
.PHONY : CMakeFiles/OHRmain.dir/main.cpp.o.provides

CMakeFiles/OHRmain.dir/main.cpp.o.provides.build: CMakeFiles/OHRmain.dir/main.cpp.o


# Object files for target OHRmain
OHRmain_OBJECTS = \
"CMakeFiles/OHRmain.dir/main.cpp.o"

# External object files for target OHRmain
OHRmain_EXTERNAL_OBJECTS =

OHRmain: CMakeFiles/OHRmain.dir/main.cpp.o
OHRmain: CMakeFiles/OHRmain.dir/build.make
OHRmain: /usr/local/opt/opencv3/lib/libopencv_shape.3.2.0.dylib
OHRmain: /usr/local/opt/opencv3/lib/libopencv_stitching.3.2.0.dylib
OHRmain: /usr/local/opt/opencv3/lib/libopencv_superres.3.2.0.dylib
OHRmain: /usr/local/opt/opencv3/lib/libopencv_videostab.3.2.0.dylib
OHRmain: HTMLElement/libHTMLElement.a
OHRmain: RectDetector/libRectDetector.a
OHRmain: WordDetector/libWordDetector.a
OHRmain: HTMLDocument/libHTMLDocument.a
OHRmain: /usr/local/opt/opencv3/lib/libopencv_objdetect.3.2.0.dylib
OHRmain: /usr/local/opt/opencv3/lib/libopencv_calib3d.3.2.0.dylib
OHRmain: /usr/local/opt/opencv3/lib/libopencv_features2d.3.2.0.dylib
OHRmain: /usr/local/opt/opencv3/lib/libopencv_flann.3.2.0.dylib
OHRmain: /usr/local/opt/opencv3/lib/libopencv_highgui.3.2.0.dylib
OHRmain: /usr/local/opt/opencv3/lib/libopencv_ml.3.2.0.dylib
OHRmain: /usr/local/opt/opencv3/lib/libopencv_photo.3.2.0.dylib
OHRmain: /usr/local/opt/opencv3/lib/libopencv_video.3.2.0.dylib
OHRmain: /usr/local/opt/opencv3/lib/libopencv_videoio.3.2.0.dylib
OHRmain: /usr/local/opt/opencv3/lib/libopencv_imgcodecs.3.2.0.dylib
OHRmain: /usr/local/opt/opencv3/lib/libopencv_imgproc.3.2.0.dylib
OHRmain: /usr/local/opt/opencv3/lib/libopencv_core.3.2.0.dylib
OHRmain: CMakeFiles/OHRmain.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/mingxiangfan/Documents/programming/c++/OHR/OHR/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable OHRmain"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/OHRmain.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/OHRmain.dir/build: OHRmain

.PHONY : CMakeFiles/OHRmain.dir/build

CMakeFiles/OHRmain.dir/requires: CMakeFiles/OHRmain.dir/main.cpp.o.requires

.PHONY : CMakeFiles/OHRmain.dir/requires

CMakeFiles/OHRmain.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/OHRmain.dir/cmake_clean.cmake
.PHONY : CMakeFiles/OHRmain.dir/clean

CMakeFiles/OHRmain.dir/depend:
	cd /Users/mingxiangfan/Documents/programming/c++/OHR/OHR/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/mingxiangfan/Documents/programming/c++/OHR/OHR /Users/mingxiangfan/Documents/programming/c++/OHR/OHR /Users/mingxiangfan/Documents/programming/c++/OHR/OHR/build /Users/mingxiangfan/Documents/programming/c++/OHR/OHR/build /Users/mingxiangfan/Documents/programming/c++/OHR/OHR/build/CMakeFiles/OHRmain.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/OHRmain.dir/depend

