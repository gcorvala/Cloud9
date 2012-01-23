find_package (Qt4 COMPONENTS QtCore QtGui QtOpenGL REQUIRED)
find_package (OpenGL REQUIRED)

set (QT_USE_QTOPENGL TRUE)
set (QT_WRAP_CPP TRUE)

include (${QT_USE_FILE})
include_directories (${QT_QTOPENGL_INCLUDE_DIR})

set (MOC_HEADERS
	CloudWindow.h
	GLWidget.h
	ImageViewer.h
)

set (GRAPH_EDITOR_SRCS
	GraphEditor/Anchor.cpp
	GraphEditor/Edge.cpp
	GraphEditor/Graph.cpp
	GraphEditor/GraphEditorWidget.cpp
	GraphEditor/GraphToolBar.cpp
	GraphEditor/ImageReaderNode.cpp
	GraphEditor/ImageReaderThread.cpp
	GraphEditor/InputAnchor.cpp
	GraphEditor/Node.cpp
	GraphEditor/NodeThread.cpp
	GraphEditor/NullThread.cpp
	GraphEditor/OutputAnchor.cpp
	GraphEditor/SobelThread.cpp
	GraphEditor/TestNode.cpp
	)

set (GRAPH_EDITOR_INCS
	GraphEditor/Anchor.h
	GraphEditor/Edge.h
	GraphEditor/EstimatorThread.h
	GraphEditor/Graph.h
	GraphEditor/GraphEditorWidget.h
	GraphEditor/GraphToolBar.h
	GraphEditor/InputAnchor.h
	GraphEditor/ImageReaderNode.h
	GraphEditor/ImageReaderThread.h
	GraphEditor/Node.h
	GraphEditor/NodeThread.h
	GraphEditor/NullThread.h
	GraphEditor/OutputAnchor.h
	GraphEditor/SobelThread.h
	GraphEditor/TestNode.h
	)

qt4_wrap_cpp (MOC_SOURCES ${MOC_HEADERS} ${GRAPH_EDITOR_INCS})

aux_source_directory (. libcloudui_sources)
aux_source_directory (GraphEditor libcloudui_sources)

add_library (cloudui SHARED ${libcloudui_sources} ${MOC_SOURCES} ${GRAPH_EDITOR_SRCS} ${GRAPH_EDITOR_INCS})

target_link_libraries (cloudui cloud)
target_link_libraries (cloudui ${QT_LIBRARIES})
target_link_libraries (cloudui ${OPENGL_LIBRARIES})

install (DIRECTORY . DESTINATION include/libcloudui FILES_MATCHING PATTERN "*.h")
install (TARGETS cloudui LIBRARY DESTINATION lib)