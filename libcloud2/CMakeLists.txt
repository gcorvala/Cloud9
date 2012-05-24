include_directories (.)

aux_source_directory (Common COMMON_SOURCES)
aux_source_directory (Geometry GEOMETRY_SOURCES)
aux_source_directory (Hough HOUGH_SOURCES)
aux_source_directory (IO IO_SOURCES)

add_library (cloud2 SHARED
	${COMMON_SOURCES}
	${GEOMETRY_SOURCES}
	${HOUGH_SOURCES}
	${IO_SOURCES}
)