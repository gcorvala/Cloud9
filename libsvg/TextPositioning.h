#ifndef __SVG_TEXT_POSITIONING_H__
#define __SVG_TEXT_POSITIONING_H__

#include "TextContent.h"
#include "Length.h"

namespace SVG {
  class TextPositioning : public TextContent {
    public:
      TextPositioning (const Length& x, const Length& y, const Length& dx, const Length& dy, const std::string& id, const std::string& xml_base);
      virtual ~TextPositioning ();

    protected:
      Length m_x;
      Length m_y;
      Length m_dx;
      Length m_dy;
  };
}

#endif