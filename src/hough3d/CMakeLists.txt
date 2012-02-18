find_package (Qt4 COMPONENTS QtCore QtGui REQUIRED)

include (${QT_USE_FILE})

add_executable (hough3d hough3d.cpp)

target_link_libraries (hough3d cloudui)
target_link_libraries (hough3d ${QT_LIBRARIES})

install (TARGETS hough3d DESTINATION bin)