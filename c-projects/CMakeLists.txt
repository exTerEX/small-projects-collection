cmake_minimum_required(VERSION 3.6)

project(c_projects LANGUAGES C)

# Set output directories
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin/lib)

# Set compilation standards
set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED YES)

# Check for some required header files
include(CheckIncludeFile)
include(CheckSymbolExists)

check_include_file(stdbool.h HAS_STDBOOL_H)

if(NOT HAS_STDBOOL_H)
  message(FATAL_ERROR "Missing required header: 'stdbool.h'")
endif()

# Check if subdirectories exist and add.
if(IS_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/miscellaneous")
  add_subdirectory("miscellaneous")
endif()

if(IS_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/numerical")
  add_subdirectory("numerical")
endif()

if(IS_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/machine_learning")
  add_subdirectory("machine_learning")
endif()

if(IS_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/conversions")
  add_subdirectory("conversions")
endif()


# Enable tool to generate binary distribution files
set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
