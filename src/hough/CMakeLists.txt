find_package (Qt4 COMPONENTS QtCore QtGui REQUIRED)

include (${QT_USE_FILE})

add_executable (hough hough.cpp)

target_link_libraries (hough cloudui)
target_link_libraries (hough ${QT_LIBRARIES})

install (TARGETS hough DESTINATION bin)