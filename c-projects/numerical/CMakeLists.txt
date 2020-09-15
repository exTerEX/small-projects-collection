file(
  GLOB SOURCES
  RELATIVE ${CMAKE_CURRENT_SOURCE_DIR}
  *.c)

foreach(SOURCE ${SOURCES})
  string(REPLACE ".c" "" FILENAME ${SOURCE})
  add_executable(${FILENAME} ${SOURCE})
endforeach(SOURCE ${SOURCES})
