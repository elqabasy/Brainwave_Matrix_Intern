# Set the minimum version for CMake
cmake_minimum_required(VERSION 3.10)

# Set the project name
project(BANK_SYSTEM)

# Set the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Define paths for headers and source files
include_directories(${CMAKE_SOURCE_DIR}/include)
file(GLOB SOURCES "${CMAKE_SOURCE_DIR}/source/*.cpp")

# Create the executable
add_executable(BankSystem main.cpp ${SOURCES})

# Link standard libraries if needed
target_link_libraries(BankSystem)
