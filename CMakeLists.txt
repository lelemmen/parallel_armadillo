# top-level CMakeLists


cmake_minimum_required(VERSION 3.8 FATAL_ERROR)
set(CMAKE_CXX_STANDARD 11)
project(parallel_armadillo LANGUAGES CXX)


# Enable parallellized code with OpenMP
find_package(openmp)
if (OPENMP_FOUND)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${OpenMP_CXX_FLAGS}")   # set the C++ compiler flags
    set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} ${OpenMP_CXX_FLAGS}")
endif()


# Create a test executable
add_executable(parallel_armadillo
        parallel_armadillo.cpp)

# Include the headers and link
find_package(Armadillo REQUIRED)
target_include_directories(parallel_armadillo PRIVATE ${ARMADILLO_INCUDE_DIRS})
target_link_libraries(parallel_armadillo ${ARMADILLO_LIBRARIES})



