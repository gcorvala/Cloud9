#ifndef __SVG_SVG_ELEMENT_H__
#define __SVG_SVG_ELEMENT_H__

#include "Element.h"
#include "Length.h"

namespace SVG {
  class SVGElement : public Element {
    public:
      SVGElement ();
      virtual ~SVGElement ();

    protected:
      Length m_x;
      Length m_y;
      Length m_width;
      Length m_height;
      std::string m_content_script_type;
      std::string m_content_style_type;
  };
}

#endif