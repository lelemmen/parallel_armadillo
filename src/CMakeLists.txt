# src-level CMakeLists

# Create a test executable
add_executable(parallel_armadillo parallel_armadillo.cpp)

# Include the headers and link (OpenMP is automatically used by armadillo, so no need to add it specifically)
find_package(Armadillo REQUIRED)
target_include_directories(parallel_armadillo PRIVATE ${ARMADILLO_INCUDE_DIRS})
target_link_libraries(parallel_armadillo ${ARMADILLO_LIBRARIES})


# Add level-1 compiler optimization
# set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O1")

# Add level-2 compiler optimization
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O2")

# Add level-3 compiler optimization
# set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O3")


# Use Accelerate
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -framework Accelerate")