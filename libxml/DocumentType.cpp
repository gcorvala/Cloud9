#include "DocumentType.h"

#include <sstream>

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

  std::string
  DocumentType::getString () const
  {
    std::stringstream ss;

    ss << "<!DOCTYPE " << m_name << " PUBLIC \"" << m_public_id << "\" \"" << m_system_id << "\">" << std::endl;
    return ss.str ();
  }
}