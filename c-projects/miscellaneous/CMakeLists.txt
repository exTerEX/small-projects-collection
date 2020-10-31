file(
  GLOB SOURCES
  RELATIVE ${CMAKE_CURRENT_SOURCE_DIR}
  *.c)

foreach(SOURCE ${SOURCES})
  string(REPLACE ".c" "" FILENAME ${SOURCE})
  add_executable(${FILENAME} ${SOURCE})
  if(MATH_LIBRARY)
    if (UNIX)
      # TODO: Must be fixed to run compile 'prime.c' on linux.
      target_link_libraries(${FILENAME} ${MATH_LIBRARY})
    else ()
      target_link_libraries(${FILENAME} ${MATH_LIBRARY})
    endif()
  endif()
endforeach(SOURCE ${SOURCES})
