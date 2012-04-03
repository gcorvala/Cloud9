#include "Line.h"

#include <sstream>

namespace SVG {
  Line::Line (const Length& x1, const Length& y1, const Length& x2, const Length& y2)
    :Element ("line")
    ,m_x1 (x1)
    ,m_y1 (y1)
    ,m_x2 (x2)
    ,m_y2 (y2)
  {
    setAttribute ("x1", m_x1.getValueAsString ());
    setAttribute ("y1", m_y1.getValueAsString ());
    setAttribute ("x2", m_x2.getValueAsString ());
    setAttribute ("y2", m_y2.getValueAsString ());
  }

  Line::~Line ()
  {
  }

  Length
  Line::getX1 () const
  {
    return m_x1;
  }

  Length
  Line::getY1 () const
  {
    return m_y1;
  }

  Length
  Line::getX2 () const
  {
    return m_x2;
  }

  Length
  Line::getY2 () const
  {
    return m_y2;
  }

/*  std::string
  Line::getSVGString () const
  {
    std::stringstream ss;

    ss << "<line x1=\"" << m_x1.getSVGString ()
       << "\" y1=\"" << m_y1.getSVGString ()
       << "\" x2=\"" << m_x2.getSVGString ()
       << "\" y2=\"" << m_y2.getSVGString ()
       << "\" stroke=\"black\" stroke-width=\"10\" />" << std::endl;

    return ss.str();
  }*/
}