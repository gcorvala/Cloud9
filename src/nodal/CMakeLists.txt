find_package (Qt4 COMPONENTS QtCore QtGui REQUIRED)

include (${QT_USE_FILE})

add_executable (nodal nodal.cpp)

target_link_libraries (nodal cloudui)
target_link_libraries (nodal ${QT_LIBRARIES})

install (TARGETS nodal DESTINATION bin)