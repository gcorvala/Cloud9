#ifndef __POLYLINE_H__
#define __POLYLINE_H__

#include "Shape.h"
#include "Types.h"
#include <vector>

namespace SVG {
  class Polyline : public Shape {
    public:
      Polyline (const std::vector < std::pair <Float32, Float32> > points);
      virtual ~Polyline ();

      std::string getSVGString () const;

    private:
      std::vector < std::pair <Float32, Float32> > m_points;
  };
}

#endif