#ifndef __XML_ATTR_H__
#define __XML_ATTR_H__

#include "Node.h"
#include <string>

namespace XML {
  class Node;
  class Element;
  class Attr : public Node {
    public:
      Attr (const std::string& name = "", const std::string& value = "");
      virtual ~Attr ();

      std::string getName () const;
      bool getSpecified () const;
      std::string getValue () const;
      void setValue (const std::string& value);
      XML::Element* getOwnerElement () const;

    protected:
      // FIXME : name and value already present in Node class
      std::string m_name;
      bool m_specified;
      std::string m_value;
      XML::Element* m_owner_element;
  };
}

#endif