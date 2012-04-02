#ifndef __SVG_DOCUMENT_H__
#define __SVG_DOCUMENT_H__

#include "Shape.h"
#include <libxml/Document.h>
//#include "SVGElement.h"
#include <vector>
#include <string>

namespace SVG {
  class Document : public XML::Document {
    public:
      Document ();
      virtual ~Document ();

      void add (const Shape& shape);

      void save (const std::string& path) const;

    private:
      std::string m_title;
      std::string m_referrer;
      std::string m_domain;
      std::string m_url;
      //SVGElement* m_root_element;

      std::vector <const Shape*> shapes;
  };
}

#endif