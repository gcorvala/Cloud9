#include "XMLElement.h"

namespace XML {
  Element::Element (const std::string& tag_name)
    :m_tag_name (tag_name)
  {
    m_node_name = tag_name;
  }

  Element::~Element ()
  {
  }

  std::string
  Element::getTagName () const
  {
    return m_tag_name;
  }
}