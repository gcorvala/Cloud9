add_executable (svgbin svg.cpp)

target_link_libraries (svgbin svg)

install (TARGETS svgbin DESTINATION bin)