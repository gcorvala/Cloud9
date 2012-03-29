#ifndef __LINE_H__
#define __LINE_H__

#include "Shape.h"
#include "Length.h"

namespace SVG {
  class Line : public Shape {
    public:
      Line (const Length& x1, const Length& y1, const Length& x2, const Length& y2);
      virtual ~Line ();

      std::string getSVGString () const;

    private:
      Length m_x1;
      Length m_y1;
      Length m_x2;
      Length m_y2;
  };
}

#endif