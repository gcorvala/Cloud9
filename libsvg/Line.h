#ifndef __SVG_LINE_H__
#define __SVG_LINE_H__

#include "Element.h"
#include "Length.h"

namespace SVG {
  class Line : public Element {
    public:
      Line (const Length& x1, const Length& y1, const Length& x2, const Length& y2);
      virtual ~Line ();

      Length getX1 () const;
      Length getY1 () const;
      Length getX2 () const;
      Length getY2 () const;

    private:
      Length m_x1;
      Length m_y1;
      Length m_x2;
      Length m_y2;
  };
}

#endif