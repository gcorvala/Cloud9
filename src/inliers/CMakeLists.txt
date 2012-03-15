find_package (Qt4 COMPONENTS QtCore QtGui QtOpenGL REQUIRED)

set (QT_USE_QTOPENGL TRUE)

include (${QT_USE_FILE})

add_executable (inliers inliers.cpp)

target_link_libraries (inliers cloud)
target_link_libraries (inliers ${QT_LIBRARIES})
target_link_libraries (inliers cloudui)

install (TARGETS inliers DESTINATION bin)