find_package (Qt4 COMPONENTS QtCore QtGui QtOpenGL REQUIRED)

set (QT_USE_QTOPENGL TRUE)

include (${QT_USE_FILE})

add_executable (slicer slicer.cpp)

target_link_libraries (slicer ${QT_LIBRARIES})
target_link_libraries (slicer cloudui)

install (TARGETS slicer DESTINATION bin)