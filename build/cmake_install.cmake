# Install script for directory: /Users/mingxiangfan/Documents/programming/c++/OHR/OHR

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/usr/local")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

if("${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/Users/mingxiangfan/Documents/programming/c++/OHR/OHR/bin/OHRmain")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
file(INSTALL DESTINATION "/Users/mingxiangfan/Documents/programming/c++/OHR/OHR/bin" TYPE EXECUTABLE FILES "/Users/mingxiangfan/Documents/programming/c++/OHR/OHR/build/OHRmain")
  if(EXISTS "$ENV{DESTDIR}/Users/mingxiangfan/Documents/programming/c++/OHR/OHR/bin/OHRmain" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}/Users/mingxiangfan/Documents/programming/c++/OHR/OHR/bin/OHRmain")
    execute_process(COMMAND /usr/bin/install_name_tool
      -delete_rpath "/usr/local/opt/opencv3/lib"
      "$ENV{DESTDIR}/Users/mingxiangfan/Documents/programming/c++/OHR/OHR/bin/OHRmain")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/strip" "$ENV{DESTDIR}/Users/mingxiangfan/Documents/programming/c++/OHR/OHR/bin/OHRmain")
    endif()
  endif()
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for each subdirectory.
  include("/Users/mingxiangfan/Documents/programming/c++/OHR/OHR/build/HTMLElement/cmake_install.cmake")
  include("/Users/mingxiangfan/Documents/programming/c++/OHR/OHR/build/RectDetector/cmake_install.cmake")
  include("/Users/mingxiangfan/Documents/programming/c++/OHR/OHR/build/WordDetector/cmake_install.cmake")
  include("/Users/mingxiangfan/Documents/programming/c++/OHR/OHR/build/HTMLDocument/cmake_install.cmake")

endif()

if(CMAKE_INSTALL_COMPONENT)
  set(CMAKE_INSTALL_MANIFEST "install_manifest_${CMAKE_INSTALL_COMPONENT}.txt")
else()
  set(CMAKE_INSTALL_MANIFEST "install_manifest.txt")
endif()

string(REPLACE ";" "\n" CMAKE_INSTALL_MANIFEST_CONTENT
       "${CMAKE_INSTALL_MANIFEST_FILES}")
file(WRITE "/Users/mingxiangfan/Documents/programming/c++/OHR/OHR/build/${CMAKE_INSTALL_MANIFEST}"
     "${CMAKE_INSTALL_MANIFEST_CONTENT}")
