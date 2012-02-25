add_executable (cube cube.cpp)

target_link_libraries (cube cloud)

install (TARGETS cube DESTINATION bin)