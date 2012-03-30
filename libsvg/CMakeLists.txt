set (SRCS
	Circle.cpp
	Document.cpp
	Element.cpp
	Length.cpp
	Line.cpp
	Polyline.cpp
	Shape.cpp
	Text.cpp
	TextContent.cpp
	TextPositioning.cpp
	XMLElement.cpp
	XMLNode.cpp
	)

set (INCS
	Circle.h
	Document.h
	Element.h
	Length.h
	Line.h
	Polyline.h
	Shape.h
	Text.h
	TextContent.h
	TextPositioning.h
	Types.h
	XMLElement.h
	XMLNode.h
	)


add_library (svg SHARED ${SRCS} ${INCS})

install (TARGETS svg DESTINATION lib)