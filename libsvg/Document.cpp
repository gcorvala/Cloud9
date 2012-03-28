#include "Document.h"

#include <iostream>
#include <fstream>

namespace SVG {
  Document::Document ()
  {
  }
  
  Document::~Document ()
  {
  }

  void
  Document::add (const Shape& shape)
  {
    shapes.push_back (&shape);
  }

  void
  Document::save (const std::string& path) const
  {
    std::filebuf fb;
    fb.open (path.c_str (), std::ios::out);
    std::ostream output (&fb);

    std::vector <const Shape*>::const_iterator it;
    output << "<?xml version=\"1.0\" standalone=\"no\" ?>" << std::endl
      << "<!DOCTYPE svg PUBLIC \"-//W3C//DTD SVG 1.1//EN\" \"http://www.w3.org/Graphics/SVG/1.1/DTD/svg11.dtd\">" << std::endl
      << "<svg width=\"1000px\" height=\"1000px\" xmlns=\"http://www.w3.org/2000/svg\" version=\"1.1\">" << std::endl;

    for (it = shapes.begin (); it != shapes.end (); ++it) {
      output << (*it)->getSVGString ();
    }

    output << "</svg>" << std::endl;

    fb.close ();
  }
}