#include "Line.h"

#include <sstream>

namespace SVG {
  Line::Line (const Point2D <Float32>& start, const Point2D <Float32>& end)
    :m_start (start)
    ,m_end (end)
  {
  }

  Line::~Line ()
  {
  }

  std::string
  Line::getSVGString () const
  {
    std::stringstream ss;
    ss << "<g stroke=\"green\" >"
       << "<line x1=\"" << m_start.x
       << "\" y1=\"" << m_start.y
       << "\" x2=\"" << m_end.x
       << "\" y2=\"" << m_end.y
       << "\" stroke-width=\"10\" />"
       << "</g>" << std::endl;
    return ss.str();
  }
}