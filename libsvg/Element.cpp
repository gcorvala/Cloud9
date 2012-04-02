#include "Element.h"

namespace SVG {
  Element::Element (const std::string& name, const std::string& id, const std::string& xml_base)
    :XML::Element (name)
    ,m_id (id)
    ,m_xml_base (xml_base)
  {
  }

  Element::~Element ()
  {
  }
}