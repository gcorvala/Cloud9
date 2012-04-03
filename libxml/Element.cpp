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
  Element::getAttribute (const std::string& name) const
  {
    Attr* attribute = static_cast <Attr*> (m_attributes.getNamedItem (name));
    return attribute->getValue ();
  }

  void
  Element::setAttribute (const std::string& name, const std::string& value)
  {
    m_attributes.setNamedItem (new Attr (name, value));
  }

  void
  Element::removeAttribute (const std::string& name)
  {
    m_attributes.removeNamedItem (name);
  }

  Attr*
  Element::getAttributeNode (const std::string& name) const
  {
    return static_cast <Attr*> (m_attributes.getNamedItem (name));
  }

  Attr*
  Element::setAttributeNode (Attr* attribute)
  {
    return static_cast <Attr*> (m_attributes.setNamedItem (attribute));
  }

  Attr*
  Element::removeAttributeNode (Attr* attribute) {
    return static_cast <Attr*> (m_attributes.getNamedItem (attribute->getName ()));
  }

  std::string
  Element::getString () const
  {
    std::vector <Node*>::const_iterator it;
    std::map <std::string, Attr*>::const_iterator attr_it;
    std::stringstream ss;
    Attr* attribute;

    ss << "<" << m_tag_name;
    
    for (unsigned long i = 0; i < m_attributes.getLength (); ++i) {
      attribute = static_cast <Attr*> (m_attributes.item (i));
      ss << " " << attribute->getName () << "=\"" << attribute->getValue () << "\"";
    }

    if (hasChildNodes () == true) {
      ss << ">" << std::endl;

      for (unsigned long i = 0; i < m_child_nodes.getLength (); ++i) {
        if (m_child_nodes.item (i)->getNodeType () == Node::Element) {
          Element* elem = static_cast <Element*> (m_child_nodes.item (i));
          ss << elem ->getString ();
        }
      }

      ss << "</" << m_tag_name << ">" << std::endl;
    }
    else {
      ss << " />" << std::endl;
    }

    return ss.str ();
  }

}