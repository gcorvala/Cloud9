#include "NodeList.h"

namespace XML {
  NodeList::NodeList ()
  {
  }

  NodeList::~NodeList ()
  {
  }

  Node*
  NodeList::item (unsigned long index) const
  {
    return m_nodes[index];
  }

  unsigned long
  NodeList::getLength () const
  {
    return m_nodes.size ();
  }
}