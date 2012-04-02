#ifndef __SVG_TEXT_H__
#define __SVG_TEXT_H__

#include "TextPositioning.h"

namespace SVG {
  class Text : public TextPositioning {
    public:
      Text ();
      virtual ~Text ();

      std::string getSVGString () const;

    protected:
      
  };
}

#endif