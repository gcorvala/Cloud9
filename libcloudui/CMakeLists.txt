find_package (Qt4 COMPONENTS QtCore QtGui QtOpenGL REQUIRED)
find_package (OpenGL REQUIRED)

set (QT_USE_QTOPENGL TRUE)
set (QT_WRAP_CPP TRUE)

include (${QT_USE_FILE})
include_directories (${QT_QTOPENGL_INCLUDE_DIR})

set (MOC_HEADERS
	Anchor.h
	CloudWindow.h
	Edge.h
	GLWidget.h
	Graph.h
	ImageViewer.h
	Node.h
)
qt4_wrap_cpp (MOC_SOURCES ${MOC_HEADERS})

aux_source_directory (. libcloudui_sources)

add_library (cloudui SHARED ${libcloudui_sources} ${MOC_SOURCES})

target_link_libraries (cloudui cloud)
target_link_libraries (cloudui ${QT_LIBRARIES})
target_link_libraries (cloudui ${OPENGL_LIBRARIES})

install (DIRECTORY . DESTINATION include/libcloudui FILES_MATCHING PATTERN "*.h")
install (TARGETS cloudui LIBRARY DESTINATION lib)