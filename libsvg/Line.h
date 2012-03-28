#ifndef __LINE_H__
#define __LINE_H__

#include <libcloud/Templates/Point2D.h>
#include "Shape.h"

namespace SVG {
  class Line : public Shape {
    public:
      Line (const Point2D <Float32>& start, const Point2D <Float32>& end);
      virtual ~Line ();

      std::string getSVGString () const;

    private:
      Point2D <Float32> m_start;
      Point2D <Float32> m_end;
  };
}

#endif