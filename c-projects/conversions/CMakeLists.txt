file(
  GLOB SOURCES
  RELATIVE ${CMAKE_CURRENT_SOURCE_DIR}
  *.c)

foreach(SOURCE ${SOURCES})
  string(REPLACE ".c" "" FILENAME ${SOURCE})
  add_executable(${FILENAME} ${SOURCE})
  if(MATH_LIBRARY)
    target_link_libraries(${FILENAME} ${MATH_LIBRARY})
  endif()
endforeach(SOURCE ${SOURCES})
