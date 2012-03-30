#ifndef __TEXT_H__
#define __TEXT_H__

#include "Shape.h"

namespace SVG {
  class Text : public Shape {
    public:
      Text ();
      virtual ~Text ();

      std::string getSVGString () const;

    protected:
      
  };
}

#endif