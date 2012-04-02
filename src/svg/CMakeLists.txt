add_executable (svgbin svg.cpp)

target_link_libraries (svgbin svg xml)

install (TARGETS svgbin DESTINATION bin)