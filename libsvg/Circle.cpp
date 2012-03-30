#include "Circle.h"

#include <sstream>

namespace SVG {
  Circle::Circle (const Length& cx, const Length& cy, const Length& r)
    :m_cx (cx)
    ,m_cy (cy)
    ,m_r (r)
  {
  }

  Circle::~Circle ()
  {
  }

  std::string
  Circle::getSVGString () const
  {
    std::stringstream ss;

    ss << "<circle cx=\"" << m_cx.getSVGString ()
       << "\" cy=\"" << m_cy.getSVGString ()
       << "\" r=\"" << m_r.getSVGString ()
       << "\" fill=\"none\" stroke=\"black\" stroke-width=\"10\" />" << std::endl;

    return ss.str();
  }
}