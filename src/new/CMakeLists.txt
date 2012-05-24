add_executable (new new.cpp)

target_link_libraries (new cloud2)

install (TARGETS new DESTINATION bin)