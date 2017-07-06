cmake_minimum_required(VERSION 2.8)
project( OHRmain )

find_package( OpenCV 3 )

include_directories( ${OpenCV_INCLUDE_DIRS} )

add_subdirectory(HTMLElement)

add_subdirectory(RectDetector)

add_subdirectory(WordDetector)

add_subdirectory(HTMLDocument)

add_executable( OHRmain main.cpp)

set (EXTRA_LIBS HTMLElement RectDetector WordDetector HTMLDocument)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

target_link_libraries( OHRmain ${OpenCV_LIBS} lept tesseract ${EXTRA_LIBS})

install (TARGETS OHRmain DESTINATION ${PROJECT_SOURCE_DIR}/bin)