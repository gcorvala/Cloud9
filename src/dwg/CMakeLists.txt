include_directories (${TD_INCLUDE_DIRS})

add_executable (dwg dwg.cpp)

target_link_libraries (dwg ${TD_CORE_LIBS})

install (TARGETS dwg DESTINATION bin)