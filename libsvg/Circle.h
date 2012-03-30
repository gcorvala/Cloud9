#ifndef __CIRCLE_H__
#define __CIRCLE_H__

#include "Shape.h"
#include "Length.h"

namespace SVG {
  class Circle : public Shape {
    public:
      Circle (const Length& cx, const Length& cy, const Length& r);
      virtual ~Circle ();
      
      std::string getSVGString () const;

    private:
      Length m_cx;
      Length m_cy;
      Length m_r;
  };
}

#endif