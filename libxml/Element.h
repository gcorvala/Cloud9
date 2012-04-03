#ifndef __XML_ELEMENT_H__
#define __XML_ELEMENT_H__

#include "Node.h"
#include "Attr.h"
#include "NodeList.h"
#include "NamedNodeMap.h"

namespace XML {
  class Element : public Node {
    public:
      Element (const std::string& tag_name);
      virtual ~Element ();

      // DOM Level 1
      std::string getTagName () const;
      std::string getAttribute (const std::string& name) const;
      void setAttribute (const std::string& name, const std::string& value);
      void removeAttribute (const std::string& name);
      Attr* getAttributeNode (const std::string& name) const;
      Attr* setAttributeNode (Attr* attribute);
      Attr* removeAttributeNode (Attr* attribute);
      NodeList getElementsByTagName (const std::string& name) const;
      void setAttributeNS (const std::string& namespace_uri, const std::string& qualified_name, const std::string& value);

      std::string getString () const;

    protected:
      std::string m_tag_name;
      NamedNodeMap m_attributes;
  };
}

#endif