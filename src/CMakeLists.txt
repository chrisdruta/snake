# Author: Chris Druta
# Date: 12-23-16

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

#adds debug information
add_definitions(-Wall -g)
link_libraries(m)

# The following file GLOB command will search for all files within the current directory
# that match the specified expressions (*.cpp and *.h), and assign the resulting files
# to the variable SRCS. Thus, SRCS is a list a all CPP source and header files in the
# current directory.

file(GLOB SRCS *.cpp *.h)

find_package(Curses REQUIRED)
include_directories(${CURSES_INCLUDE_DIR})

add_executable(snake ${SRCS})
target_link_libraries(snake ${CURSES_LIBRARIES})
