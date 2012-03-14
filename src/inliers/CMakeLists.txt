add_executable (inliers inliers.cpp)

target_link_libraries (inliers cloud)

install (TARGETS inliers DESTINATION bin)