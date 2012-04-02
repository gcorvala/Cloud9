set (SRCS
	Document.cpp
	DocumentType.cpp
	DOMImplementation.cpp
	Element.cpp
	Node.cpp
	)

set (INCS
	Document.h
	DocumentType.h
	DOMImplementation.h
	Element.h
	Node.h
	Types.h
	)

add_library (xml SHARED ${SRCS} ${INCS})

install (TARGETS xml DESTINATION lib)