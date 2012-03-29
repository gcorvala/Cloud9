set (SRCS
	Document.cpp
	Length.cpp
	Line.cpp
	Polyline.cpp
	Shape.cpp
	)

set (INCS
	Document.h
	Length.h
	Line.h
	Polyline.h
	Shape.h
	Types.h
	)


add_library (svg SHARED ${SRCS} ${INCS})

install (TARGETS svg DESTINATION lib)