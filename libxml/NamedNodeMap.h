#ifndef __XML_NAMED_NODE_MAP_H__
#define __XML_NAMED_NODE_MAP_H__

#include "Node.h"
#include <string>

namespace XML {
  class NamedNodeMap {
    public:
      NamedNodeMap ();
      virtual ~NamedNodeMap ();

      Node* getNamedItem (const std::string& name) const;
      Node* setNamedItem (Node* arg);
      Node* removeNamedItem (const std::string& name);
      Node* item (unsigned long index) const;
      unsigned long getLength () const;

    protected:
      std::map <std::string, Node*> m_nodes;
  };
}

#endif