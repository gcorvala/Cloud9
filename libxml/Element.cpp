#include "Element.h"

#include <sstream>

namespace XML {
  Element::Element (const std::string& tag_name)
    :Node (Node::Element)
    ,m_tag_name (tag_name)
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

  std::string
  Element::getString () const
  {
    std::vector <Node*>::const_iterator it;
    std::stringstream ss;

    ss << "<" << m_tag_name << ">" << std::endl;

    for (it = m_child_nodes.begin (); it != m_child_nodes.end (); ++it) {
      if ((*it)->getNodeType () == Node::Element) {
        Element* elem = static_cast <Element*> (*it);
        ss << elem->getString ();
      }
    }

    ss << "</" << m_tag_name << ">" << std::endl;

    return ss.str ();
  }

}