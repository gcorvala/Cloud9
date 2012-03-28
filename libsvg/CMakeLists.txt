set (SRCS
	Document.cpp
	Line.cpp
	Shape.cpp
	)

set (INCS
	Document.h
	Line.h
	Shape.h
	)


add_library (svg SHARED ${SRCS} ${INCS})

target_link_libraries (svg cloud)

install (TARGETS svg DESTINATION lib)