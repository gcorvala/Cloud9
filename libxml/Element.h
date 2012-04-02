#ifndef __XML_ELEMENT_H__
#define __XML_ELEMENT_H__

#include "Node.h"
#include <map>
#include <vector>

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
      //Attr* getAttributeNode (const std::string& name) const;
      //Attr* setAttributeNode (Attr* attribute);
      //Attr* removeAttributeNode (Attr* attribute);
      std::vector <Node*> getElementsByTagName (const std::string& name) const;

      std::string getString () const;

    protected:
      std::string m_tag_name;
      std::map <std::string, std::string> attributes;
  };
}

#endif