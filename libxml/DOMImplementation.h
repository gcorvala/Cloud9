#ifndef __XML_DOM_IMPLEMENTATION_H__
#define __XML_DOM_IMPLEMENTATION_H__

#include "Document.h"
#include "DocumentType.h"
#include "Types.h"

namespace XML {
  class DOMImplementation {
    public:
      DOMImplementation ();
      virtual ~DOMImplementation ();

      Boolean hasFeature (const std::string& feature, const std::string& version) const;
      DocumentType* createDocumentType (const std::string& qualified_name, const std::string& public_id = "", const std::string& system_id = "") const;
      Document* createDocument (const std::string& namespace_uri, const std::string& qualified_name, DocumentType& doc_type) const;
  };
}

#endif