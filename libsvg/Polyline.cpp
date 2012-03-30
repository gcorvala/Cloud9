#include "Polyline.h"

#include <sstream>

namespace SVG {
  Polyline::Polyline (const std::vector < std::pair <Float32, Float32> > points)
    :m_points (points)
  {
  }

  Polyline::~Polyline ()
  {
  }

  std::string
  Polyline::getSVGString () const
  {
    std::stringstream ss;
    std::vector < std::pair <Float32, Float32> >::const_iterator it;

    ss << "<polyline fill=\"none\" stroke=\"black\" stroke-width=\"10\" points=\"";

    for (it = m_points.begin (); it != m_points.end (); ++it) {
      if (it != m_points.begin ()) {
        ss << ' ';
      }
      ss << it->first << ',' << it->second;
    }

    ss << "\" />" <<  std::endl;

    return ss.str();
  }
}