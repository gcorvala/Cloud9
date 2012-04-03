#ifndef __XML_NODE_LIST_H__
#define __XML_NODE_LIST_H__

#include <vector>

namespace XML {
  class Node;
  class NodeList {
    friend class Node;
    public:
      NodeList ();
      virtual ~NodeList ();

      Node* item (unsigned long index) const;
      unsigned long getLength () const;

    protected:
      std::vector <Node*> m_nodes;
  };
}

#endif