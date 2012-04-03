#include "NamedNodeMap.h"

namespace XML {
  NamedNodeMap::NamedNodeMap ()
  {
  }

  NamedNodeMap::~NamedNodeMap ()
  {
  }

  Node*
  NamedNodeMap::getNamedItem (const std::string& name) const
  {
    std::map <std::string, Node*>::const_iterator it;
    it = m_nodes.find (name);
    if (it == m_nodes.end ()) {
      return NULL;
    }
    else {
      return it->second;
    }
  }

  Node*
  NamedNodeMap::setNamedItem (Node* arg)
  {
    bool already_exists = m_nodes.count (arg->getNodeName ());
    m_nodes[arg->getNodeName ()] = arg;
    if (already_exists == true) {
      return arg;
    }
    else {
      return NULL;
    }
  }

  Node*
  NamedNodeMap::removeNamedItem (const std::string& name)
  {
    std::map <std::string, Node*>::iterator it;
    Node* node;

    it = m_nodes.find (name);
    node = it->second;
    m_nodes.erase (it);

    return node;
  }

  Node*
  NamedNodeMap::item (unsigned long index) const
  {
    std::map <std::string, Node*>::const_iterator it;

    it = m_nodes.begin ();
    std::advance (it, index);

    return it->second;
  }

  unsigned long
  NamedNodeMap::getLength () const
  {
    return m_nodes.size ();
  }
}