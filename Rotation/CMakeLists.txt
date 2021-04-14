cmake_minimum_required(VERSION 3.16)
project(Rotation)

set(EXECUTABLE ${CMAKE_PROJECT_NAME}_run)

set(CMAKE_CXX_STANDARD 14)

add_subdirectory(lib/GNUPlot)
add_subdirectory(tst)
add_subdirectory(lib/googletest)

file(GLOB_RECURSE SOURCES LIST_DIRECTORIES true inc/*.h src/*.cpp)

include_directories(${CMAKE_SOURCE_DIR}/lib/GNUPlot)
include_directories(${CMAKE_SOURCE_DIR}/inc)

add_executable(${EXECUTABLE} ${SOURCES})
add_library(${CMAKE_PROJECT_NAME}_lib STATIC ${SOURCES})
target_link_libraries(${EXECUTABLE} PRIVATE GNUPlot_lib)