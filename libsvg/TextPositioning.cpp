#include "TextPositioning.h"

namespace SVG {
  TextPositioning::TextPositioning (const Length& x, const Length& y, const Length& dx, const Length& dy, const std::string& id, const std::string& xml_base)
    :TextContent (id, xml_base)
    ,m_x (x)
    ,m_y (y)
    ,m_dx (dx)
    ,m_dy (dy)
  {
  }

  TextPositioning::~TextPositioning ()
  {
  }
}