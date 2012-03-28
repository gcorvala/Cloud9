set (INCS
	dl_attributes.h
	dl_codes.h
	dl_creationadapter.h
	dl_creationinterface.h
	dl_dxf.h
	dl_entities.h
	dl_exception.h
	dl_extrusion.h
	dl_writer.h
	dl_writer_ascii.h
	)

set (SRCS
	dl_dxf.cpp
	dl_writer_ascii.cpp
	)

include_directories (.)

add_library (dxflib SHARED ${INCS} ${SRCS})