include_directories (../../3rdparty/libredwg)

add_executable (dwg dwg.cpp)

target_link_libraries (dwg libredwg)

install (TARGETS dwg DESTINATION bin)