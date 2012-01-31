find_package (Qt4 COMPONENTS QtGui REQUIRED)

include (${QT_USE_FILE})

add_executable (cloudApp cloud.cpp)

target_link_libraries (cloudApp cloudui)

install (TARGETS cloudApp DESTINATION bin)