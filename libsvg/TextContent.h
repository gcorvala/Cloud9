#ifndef __TEXT_CONTENT_H__
#define __TEXT_CONTENT_H__

#include "Element.h"
#include "Length.h"

namespace SVG {
  class TextContent : public Element {
    public:
      TextContent ();
      virtual ~TextContent ();

    protected:
      Length m_text_length;
  };
}

#endif