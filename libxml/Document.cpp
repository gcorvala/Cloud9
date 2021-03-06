#include "Document.h"

#include <sstream>

namespace XML {
  Document::Document ()
    :Node (Node::Document)
    ,m_doc_type (NULL)
    ,m_xml_standalone (false)
    ,m_xml_version ("1.0")
  {
  }

  Document::Document (XML::DocumentType& doc_type)
    :Node (Node::Document)
    ,m_doc_type (&doc_type)
    ,m_xml_standalone (false)
    ,m_xml_version ("1.0")
  {
    m_node_name = "#document";
    doc_type.m_owner_document = this;
  }

  Document::~Document ()
  {
    if (m_doc_type) {
      delete m_doc_type;
    }
    if (m_document_element) {
      delete m_document_element;
    }
  }

  XML::Element*
  Document::getDocumentElement () const
  {
    return m_document_element;
  }

  Element*
  Document::createElement (const std::string& tag_name)
  {
    XML::Element* element = new XML::Element (tag_name);
    element->m_owner_document = this;
    return element;
  }

  std::string
  Document::getString () const
  {
    std::stringstream ss;

    ss << "<?xml version=\"" << m_xml_version << "\" standalone=\"" << (m_xml_standalone ? "yes" : "no") << "\" ?>" << std::endl;
    if (m_doc_type != NULL) {
      ss << m_doc_type->getString ();
    }
    ss << m_document_element->getString () << std::endl;

    return ss.str ();
  }
}