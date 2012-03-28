#ifndef __SHAPE_H__
#define __SHAPE_H__

#include <string>

namespace SVG {
  class Shape {
    public:
      Shape ();
      virtual ~Shape ();

      virtual std::string getSVGString () const = 0;
  };
}

#endif