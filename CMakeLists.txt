cmake_minimum_required(VERSION 3.6)

project(small_projects)

# Set output directories
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin/${CMAKE_SYSTEM_NAME})

# Check for some required header files
include(CheckIncludeFile)

check_include_file(stdbool.h HAS_STDBOOL_H)

if(NOT HAS_STDBOOL_H)
  message(FATAL_ERROR "Missing required header: 'stdbool.h'")
endif()

# Check if subdirectories exist and add.
if(IS_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/c-projects")
  add_subdirectory("c-projects")
endif()

if(IS_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/cpp-projects")
  add_subdirectory("cpp-projects")
endif()

# Enable tool to generate binary distribution files
set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
