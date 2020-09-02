cmake_minimum_required(VERSION 3.6)

project (
    small_projects
    LANGUAGES C
    VERSION 0.1.0
    DESCRIPTION "Build setup for small mini projects."
)

# Set compilation standards
set( CMAKE_C_STANDARD 11 )
set( CMAKE_CXX_STANDARD 20 )
set( CMAKE_C_STANDARD_REQUIRED YES )
set( CMAKE_CXX_STANDARD_REQUIRED YES )

# Check for some required header files
include(CheckIncludeFile)
include(CheckSymbolExists)

check_include_file(stdbool.h HAS_STDBOOL_H)

if (NOT HAS_STDBOOL_H)
    message(FATAL_ERROR "Missing required header: 'stdbool.h'")
endif()

# Add subdirectories containing CMakeLists.txt
add_subdirectory("c-algorithms")

# Enable tool to generate binary distribution files
set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)