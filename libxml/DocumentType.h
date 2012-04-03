#ifndef __XML_DOCUMENT_TYPE_H__
#define __XML_DOCUMENT_TYPE_H__

#include "Node.h"
#include <string>

namespace XML {
  class DocumentType : public Node {
    public:
      DocumentType (const std::string& name, const std::string& public_id, const std::string& system_id);
      virtual ~DocumentType ();

      std::string getString () const;

    protected:
      std::string m_name;
      std::string m_public_id;
      std::string m_system_id;
  };
}

#endif