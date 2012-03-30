#ifndef __TEXT_POSITIONING_H__
#define __TEXT_POSITIONING_H__

#include "TextContent.h"

namespace SVG {
  class TextPositioning : public TextContent {
    public:
      TextPositioning ();
      virtual ~TextPositioning ();

    protected:
      Length m_x;
      Length m_y;
      Length m_dx;
      Length m_dy;
  };
}

#endif