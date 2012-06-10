include_directories (.)

aux_source_directory (Common COMMON_SOURCES)
aux_source_directory (Filtering FILTER_SOURCES)
aux_source_directory (Geometry GEOMETRY_SOURCES)
aux_source_directory (Hough HOUGH_SOURCES)
aux_source_directory (IO IO_SOURCES)

add_library (cloud2 SHARED
	${COMMON_SOURCES}
	${FILTER_SOURCES}
	${GEOMETRY_SOURCES}
	${HOUGH_SOURCES}
	${IO_SOURCES}
)

find_package (SWIG REQUIRED)
include (${SWIG_USE_FILE})
find_package (PythonLibs)
include_directories (${PYTHON_INCLUDE_PATH})

set_source_files_properties (example.i PROPERTIES CPLUSPLUS ON)
#set_source_files_properties (example.i PROPERTIES SWIG_FLAGS "-includeall")
swig_add_module (example python example.i ${COMMON_SOURCES} ${GEOMETRY_SOURCES} ${IO_SOURCES})
swig_link_libraries (example ${PYTHON_LIBRARIES})