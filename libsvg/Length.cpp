#include "Length.h"

#include <sstream>

namespace SVG {
  Length::Length (const Float32 value, const Type type)
    :m_type (type)
    ,m_value (value)
  {
  }

  Length::~Length ()
  {
  }

  Length::Type
  Length::getUnitType () const
  {
    return m_type;
  }

  Float32
  Length::getValue () const
  {
    return m_value;
  }

  void
  Length::setValue (Float32 value)
  {
    m_value = value;
  }

  std::string
  Length::getValueAsString () const
  {
    std::stringstream ss;

    ss << m_value;
    switch (m_type) {
      case Number:
        break;
      case Percentage:
        ss << '%';
        break;
      case Ems:
        ss << "em";
        break;
      case Exs:
        ss << "ex";
        break;
      case Px:
        ss << "px";
        break;
      case Cm:
        ss << "cm";
        break;
      case Mm:
        ss << "mm";
        break;
      case In:
        ss << "in";
        break;
      case Pt:
        ss << "pt";
        break;
      case Pc:
        ss << "pc";
        break;
    }

    return ss.str();
  }

  std::string
  Length::getSVGString () const
  {
    std::stringstream ss;

    ss << m_value;
    switch (m_type) {
      case Number:
        break;
      case Percentage:
        ss << '%';
        break;
      case Ems:
        ss << "em";
        break;
      case Exs:
        ss << "ex";
        break;
      case Px:
        ss << "px";
        break;
      case Cm:
        ss << "cm";
        break;
      case Mm:
        ss << "mm";
        break;
      case In:
        ss << "in";
        break;
      case Pt:
        ss << "pt";
        break;
      case Pc:
        ss << "pc";
        break;
    }

    return ss.str();
  }
}