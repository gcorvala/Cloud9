set (SVG_SRCS
	Circle.cpp
	Document.cpp
	Element.cpp
	Line.cpp
	Polyline.cpp
	SVGElement.cpp
	)

set (SVG_INCS
	Circle.h
	Document.h
	Element.h
	Line.h
	Polyline.h
	SVGElement.h
	)

set (SRCS
	${SVG_SRCS}
	Length.cpp
	Shape.cpp
	Text.cpp
	TextContent.cpp
	TextPositioning.cpp
	)

set (INCS
	${SVG_INCS}
	Length.h
	Shape.h
	Text.h
	TextContent.h
	TextPositioning.h
	Types.h
	)

add_library (svg SHARED ${SRCS} ${INCS})
target_link_libraries (svg xml)

install (TARGETS svg DESTINATION lib)