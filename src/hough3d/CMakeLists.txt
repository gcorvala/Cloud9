find_package (Qt4 COMPONENTS QtCore QtGui QtOpenGL REQUIRED)

set (QT_USE_QTOPENGL TRUE)

include (${QT_USE_FILE})

add_executable (hough3d hough3d.cpp)

target_link_libraries (hough3d ${QT_LIBRARIES})
target_link_libraries (hough3d cloudui)

install (TARGETS hough3d DESTINATION bin)