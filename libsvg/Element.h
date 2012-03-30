#ifndef __ELEMENT_H__
#define __ELEMENT_H__

#include "XMLElement.h"
#include <string>

namespace SVG {
  class Element : public XML::Element {
    public:
      Element (const std::string& name, const std::string& id, const std::string& xml_base);
      virtual ~Element ();

    protected:
      std::string m_id;
      std::string m_xml_base;
  };
}

#endif