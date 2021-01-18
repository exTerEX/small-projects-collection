include(CheckLibraryExists)

file(
  GLOB SOURCES
  RELATIVE ${CMAKE_CURRENT_SOURCE_DIR}
  *.c)

check_library_exists(m sqrt "" HAVE_LIB_M)

if(HAVE_LIB_M)
    set(EXTRA_LIBS ${EXTRA_LIBS} m)
endif()

foreach(SOURCE ${SOURCES})
  string(REPLACE ".c" "" FILENAME ${SOURCE})
  add_executable(${FILENAME} ${SOURCE})
  target_link_libraries(${FILENAME} PUBLIC ${EXTRA_LIBS})
endforeach(SOURCE ${SOURCES})
