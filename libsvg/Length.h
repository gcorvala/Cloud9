#ifndef __SVG_LENGTH_H__
#define __SVG_LENGTH_H__

#include "Types.h"
#include <string>

namespace SVG {
  class Length {
    public:
      enum Type {
        Number,
        Percentage,
        Ems,
        Exs,
        Px,
        Cm,
        Mm,
        In,
        Pt,
        Pc
      };
      
      Length (const Float32 value = 0, const Type type = Number);  
      virtual ~Length ();

      Type getUnitType () const;
      Float32 getValue () const;
      void setValue (Float32 value);
      Float32 getValueInSpecifiedUnits () const;
      void setValueInSpecifiedUnits (Float32 value);
      std::string getValueAsString () const;
      void setValueAsString (const std::string& value);
      void newValueSpecifiedUnits (Type type, Float32 value);
      void convertToSpecifiedUnits (Type type);

      std::string getSVGString () const;

    private:
      Type m_type;
      Float32 m_value;
  };
}

#endif