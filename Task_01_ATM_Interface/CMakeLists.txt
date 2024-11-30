# Minimum CMake version required
cmake_minimum_required(VERSION 3.10)

# Project name and version
set(PROJECT_NAME ATMInterface)
set(PROJECT_VERSION 1.0)

# Define project
project(${PROJECT_NAME} VERSION ${PROJECT_VERSION} LANGUAGES CXX)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Define source and header directories
set(SOURCE_DIR source/)
set(INCLUDE_DIR include/)

# Function to get all files with a specific extension from a directory
function(get_files result directory extension)
    file(GLOB_RECURSE files "${directory}/*.${extension}")
    set(${result} ${files} PARENT_SCOPE)
endfunction()

# Get all source and header files
get_files(SOURCE_FILES ${SOURCE_DIR} cpp)
get_files(HEADER_FILES ${INCLUDE_DIR} hpp)

# Include directories
include_directories(${INCLUDE_DIR})

# Add executable
add_executable(${PROJECT_NAME} ${SOURCE_FILES} ${HEADER_FILES})

# Print project details
# message(STATUS "Project: ${PROJECT_NAME} ${PROJECT_VERSION}")
# message(STATUS "C++ Standard: ${CMAKE_CXX_STANDARD}")
# message(STATUS "Source Files: ${SOURCE_FILES}")
# message(STATUS "Header Files: ${HEADER_FILES}")

