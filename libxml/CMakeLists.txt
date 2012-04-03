set (SRCS
	Attr.cpp
	Document.cpp
	DocumentType.cpp
	DOMImplementation.cpp
	Element.cpp
	NamedNodeMap.cpp
	Node.cpp
	NodeList.cpp
	)

set (INCS
	Attr.h
	Document.h
	DocumentType.h
	DOMImplementation.h
	Element.h
	NamedNodeMap.h
	Node.h
	NodeList.h
	)

add_library (xml SHARED ${SRCS} ${INCS})

install (TARGETS xml DESTINATION lib)