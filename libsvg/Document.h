#ifndef __DOCUMENT_H__
#define __DOCUMENT_H__

#include "Shape.h"
#include <vector>
#include <string>

namespace SVG {
  class Document{
    public:
      Document ();
      virtual ~Document ();

      void add (const Shape& shape);

      void save (const std::string& path) const;

    private:
      std::vector <const Shape*> shapes;
  };
}

#endif