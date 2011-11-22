find_package (Qt4 COMPONENTS QtCore QtGui QtOpenGL REQUIRED)

set (QT_USE_QTOPENGL TRUE)

include (${QT_USE_FILE})

add_executable (viewer viewer.cpp)

target_link_libraries (viewer cloudui)
target_link_libraries (viewer ${QT_LIBRARIES})

install (TARGETS viewer DESTINATION bin)