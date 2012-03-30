set (SRCS
	Circle.cpp
	Document.cpp
	Element.cpp
	Length.cpp
	Line.cpp
	Node.cpp
	Polyline.cpp
	Shape.cpp
	Text.cpp
	TextContent.cpp
	TextPositioning.cpp
	)

set (INCS
	Circle.h
	Document.h
	Element.h
	Length.h
	Line.h
	Node.h
	Polyline.h
	Shape.h
	Text.h
	TextContent.h
	TextPositioning.h
	Types.h
	)


add_library (svg SHARED ${SRCS} ${INCS})

install (TARGETS svg DESTINATION lib)