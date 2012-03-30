#ifndef __LENGTH_H__
#define __LENGTH_H__

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

      std::string getSVGString () const;

    private:
      Type m_type;
      Float32 m_value;
  };
}

#endif