## Object-Oriented Programming 1

The code was written during EOM's labs using `repl.it` environment.  
Semester 4, year 2021.

### Useful utilities:
`Makefile`:
```make
CXX = g++
EXEC = main
CXXFLAGS = -std=c++14 -Wall -pedantic
SRC = $(wildcard *.cpp)
OBJS = $(SRC:.cpp=.o)

all: $(EXEC) run

$(EXEC): $(OBJS)
	$(CXX) $^ -o $@

clean:
	rm -rf *.o $(EXEC)

run:
	./$(EXEC)

check: 
	valgrind ./$(EXEC)

.PHONY: all clean run check
```
  
`CMakeLists.txt`:
```cmake
cmake_minimum_required(VERSION 3.1)
project(CPPCMAKE)

#----------------------------------------------------------------------------
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_COLOR_MAKEFILE ON)
set(CMAKE_CXX_FLAGS "-Wall")
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG}")
set(CMAKE_CXX_FLAGS_RELEASE "-DNDEBUG -O0")

#----------------------------------------------------------------------------
# prevent for in-source building
set(CMAKE_DISABLE_IN_SOURCE_BUILD ON)
set(CMAKE_DISABLE_SOURCE_CHANGES  ON)
if ("${CMAKE_SOURCE_DIR}" STREQUAL "${CMAKE_BINARY_DIR}")
  message(SEND_ERROR "In-source builds are not allowed.")
endif ()

#----------------------------------------------------------------------------
set(PROJECT_LINK_DIRECTORY ${PROJECT_SOURCE_DIR})
add_compile_options(${CMAKE_CXX_FLAGS})

option(MY_ERROR_EXPECTED "Expected compilation error." OFF)
if(MY_ERROR_EXPECTED)
  message("Expected compilation error")
  add_compile_options("-DMY_ERROR_EXPECTED")
endif()

#----------------------------------------------------------------------------
# Create library
# --- implicite ---
include_directories(${PROJECT_SOURCE_DIR}/include)
file(GLOB SOURCES "${PROJECT_SOURCE_DIR}/src/*.cpp")
add_library(CPPLabSolution SHARED ${SOURCES})

# --- explicite ---
# add_library(CPPLabSolution SHARED MyList.cpp)

#----------------------------------------------------------------------------
# Create executable
add_executable(EXECUTABLE main.cpp)
target_link_libraries(EXECUTABLE CPPLabSolution)
```

Caveat emptor.