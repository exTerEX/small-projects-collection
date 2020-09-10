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
