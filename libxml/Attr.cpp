#include "Attr.h"

namespace XML {
  Attr::Attr (const std::string& name, const std::string& value)
    :Node (Node::Attribute)
    ,m_name (name)
    ,m_value (value)
  {
    m_node_name = name;
  }

  Attr::~Attr ()
  {
  }

  std::string
  Attr::getName () const
  {
    return m_name;
  }

  bool
  Attr::getSpecified () const
  {
    return m_specified;
  }

  std::string
  Attr::getValue () const
  {
    return m_value;
  }

  void
  Attr::setValue (const std::string& value)
  {
    m_value = value;
  }

  XML::Element*
  Attr::getOwnerElement () const
  {
    return m_owner_element;
  }
}