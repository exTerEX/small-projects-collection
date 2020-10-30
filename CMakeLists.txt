cmake_minimum_required(VERSION 3.6)

project(small_projects LANGUAGES CXX)

# Set output directories
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin/lib)

# Set compilation standards
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED YES)

# Check for some required header files
include(CheckIncludeFile)
include(CheckSymbolExists)

check_include_file(stdbool.h HAS_STDBOOL_H)

if(NOT HAS_STDBOOL_H)
  message(FATAL_ERROR "Missing required header: 'stdbool.h'")
endif()

# Check if subdirectories exist and add.
if(IS_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/cpp-projects")
  add_subdirectory("cpp-projects")
endif()

# Enable tool to generate binary distribution files
set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
