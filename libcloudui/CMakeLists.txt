find_package (Qt4 COMPONENTS QtCore QtGui QtOpenGL REQUIRED)
find_package (OpenGL REQUIRED)

set (QT_USE_QTOPENGL TRUE)
set (QT_WRAP_CPP TRUE)

include (${QT_USE_FILE})
include_directories (${QT_QTOPENGL_INCLUDE_DIR})

set (MOC_HEADERS
	CloudWindow.h
)

set (CLOUD_APPLICATION_SRCS
	CloudApplication/CloudApplication.cpp
	)

set (CLOUD_APPLICATION_INCS
	CloudApplication/CloudApplication.h
	)

set (GRAPH_EDITOR_SRCS
	GraphEditor/Anchor.cpp
	GraphEditor/Edge.cpp
	GraphEditor/Graph.cpp
	GraphEditor/GraphEditorWidget.cpp
	GraphEditor/GraphToolBar.cpp
	GraphEditor/InputAnchor.cpp
	GraphEditor/IntegerProperty.cpp
	GraphEditor/Node.cpp
	GraphEditor/OutputAnchor.cpp
	GraphEditor/PathProperty.cpp
	GraphEditor/Property.cpp
	GraphEditor/RealProperty.cpp
	)

set (GRAPH_EDITOR_INCS
	GraphEditor/Anchor.h
	GraphEditor/Edge.h
	GraphEditor/Graph.h
	GraphEditor/GraphEditorWidget.h
	GraphEditor/GraphToolBar.h
	GraphEditor/InputAnchor.h
	GraphEditor/IntegerProperty.h
	GraphEditor/Node.h
	GraphEditor/OutputAnchor.h
	GraphEditor/PathProperty.h
	GraphEditor/Property.h
	GraphEditor/RealProperty.h
	)

set (NODES_SRCS
	Nodes/CannyNode.cpp
	Nodes/GaussianNode.cpp
	Nodes/HoughNode.cpp
	Nodes/ImageNode.cpp
	Nodes/ImageReaderNode.cpp
	Nodes/ImageWriterNode.cpp
	Nodes/MeanShiftNode.cpp
	Nodes/PhaseCongruencyNode.cpp
	Nodes/PointCloudReaderNode.cpp
	Nodes/SobelNode.cpp
	Nodes/TestNode.cpp
	Nodes/ThresholdNode.cpp
	Nodes/ViewerNode.cpp
	)

set (NODES_INCS
	Nodes/CannyNode.h
	Nodes/GaussianNode.h
	Nodes/HoughNode.h
	Nodes/ImageNode.h
	Nodes/ImageReaderNode.h
	Nodes/ImageWriterNode.h
	Nodes/MeanShiftNode.h
	Nodes/PhaseCongruencyNode.h
	Nodes/PointCloudReaderNode.h
	Nodes/SobelNode.h
	Nodes/TestNode.h
	Nodes/ThresholdNode.h
	Nodes/ViewerNode.h
	)

set (VIEWERS_SRCS
	Viewers/ImageViewerWidget.cpp
	Viewers/PointCloudViewerWidget.cpp
	)

set (VIEWERS_INCS
	Viewers/ImageViewerWidget.h
	Viewers/PointCloudViewerWidget.h
	)

qt4_wrap_cpp (MOC_SOURCES ${MOC_HEADERS} ${CLOUD_APPLICATIONS_INCS} ${GRAPH_EDITOR_INCS} ${NODES_INCS} ${VIEWERS_INCS})

aux_source_directory (. libcloudui_sources)
aux_source_directory (CloudApplication libcloudui_sources)
aux_source_directory (GraphEditor libcloudui_sources)
aux_source_directory (Nodes libcloudui_sources)
aux_source_directory (Viewers libcloudui_sources)

add_library (cloudui SHARED ${libcloudui_sources} ${MOC_SOURCES} ${CLOUD_APPLICATIONS_SRCS} ${GRAPH_EDITOR_SRCS} ${GRAPH_EDITOR_INCS} ${NODES_SRCS} ${NODES_INCS} ${VIEWERS_SRCS} ${VIEWERS_INCS})

target_link_libraries (cloudui cloud)
target_link_libraries (cloudui ${QT_LIBRARIES})
target_link_libraries (cloudui ${OPENGL_LIBRARIES})

install (DIRECTORY . DESTINATION include/libcloudui FILES_MATCHING PATTERN "*.h")
install (TARGETS cloudui LIBRARY DESTINATION lib)