#include "Line.h"

#include <sstream>

namespace SVG {
  Line::Line (const Length& x1, const Length& y1, const Length& x2, const Length& y2)
    :m_x1 (x1)
    ,m_y1 (y1)
    ,m_x2 (x2)
    ,m_y2 (y2)
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
       << "<line x1=\"" << m_x1.getSVGString ()
       << "\" y1=\"" << m_y1.getSVGString ()
       << "\" x2=\"" << m_x2.getSVGString ()
       << "\" y2=\"" << m_y2.getSVGString ()
       << "\" stroke-width=\"10\" />"
       << "</g>" << std::endl;

    return ss.str();
  }
}