add_executable (octree octree.cpp)

target_link_libraries (octree cloud)

install (TARGETS octree DESTINATION bin)