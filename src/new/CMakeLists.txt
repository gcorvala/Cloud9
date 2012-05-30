find_package (Qt4 COMPONENTS QtCore QtGui REQUIRED)

include (${QT_USE_FILE})

add_executable (new new.cpp)

target_link_libraries (new cloud2)
target_link_libraries (new cloud)
target_link_libraries (new cloudui)
target_link_libraries (new ${QT_LIBRARIES})

install (TARGETS new DESTINATION bin)