add_executable (hough3d hough3d.cpp)

target_link_libraries (hough3d cloud)

install (TARGETS hough3d DESTINATION bin)