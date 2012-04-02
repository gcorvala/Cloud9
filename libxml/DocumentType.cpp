#include "DocumentType.h"

namespace XML {
  DocumentType::DocumentType (const std::string& name, const std::string& public_id, const std::string& system_id)
    :Node (Node::DocumentType)
    ,m_name (name)
    ,m_public_id (public_id)
    ,m_system_id (system_id)
  {
  }

  DocumentType::~DocumentType ()
  {
  }
}