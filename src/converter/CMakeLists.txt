add_executable (converter converter.cpp)

target_link_libraries (converter cloud)

install (TARGETS converter DESTINATION bin)