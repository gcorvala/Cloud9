add_executable (slicer slicer.cpp)

target_link_libraries (slicer cloud)

install (TARGETS slicer DESTINATION bin)