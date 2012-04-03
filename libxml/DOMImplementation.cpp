#include "DOMImplementation.h"

namespace XML {
  DOMImplementation::DOMImplementation ()
  {
  }

  DOMImplementation::~DOMImplementation ()
  {
  }

  bool
  DOMImplementation::hasFeature (const std::string& feature, const std::string& version) const
  {
    return false;
  }

  DocumentType*
  DOMImplementation::createDocumentType (const std::string& qualified_name, const std::string& public_id, const std::string& system_id) const
  {
    DocumentType* doc_type = new DocumentType (qualified_name, public_id, system_id);
    return doc_type;
  }

  Document*
  DOMImplementation::createDocument (const std::string& namespace_uri, const std::string& qualified_name, DocumentType& doc_type) const
  {
    Document* doc = new Document (doc_type);
    Element* root = doc->createElement (qualified_name);
    doc->m_document_element = root;
    return doc;
  }
}