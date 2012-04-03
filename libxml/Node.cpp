#include "Node.h"

namespace XML {
  Node::Node (Type type)
    :m_node_type (type)
    ,m_owner_document (NULL)
  {
  }

  Node::~Node ()
  {
  }

  std::string
  Node::getNodeName () const
  {
    return m_node_name;
  }

  std::string
  Node::getNodeValue () const
  {
    return m_node_value;
  }

  Node::Type
  Node::getNodeType () const
  {
    return m_node_type;
  }

  Node*
  Node::getParentNode () const
  {
    return m_parent_node;
  }

  NodeList
  Node::getChildNodes () const
  {
    return m_child_nodes;
  }

  Node*
  Node::getFirstChild () const
  {
    if (m_child_nodes.getLength () == 0) {
      return NULL;
    }
    else {
      return m_child_nodes.item (0);
    }
  }

  Node*
  Node::getLastChild () const
  {
    unsigned long s = m_child_nodes.getLength ();
    if (s == 0) {
      return NULL;
    }
    else {
      return m_child_nodes.item (s-1);
    }
  }

  Node*
  Node::appendChild (Node* child)
  {
    child->m_parent_node = this;
    m_child_nodes.m_nodes.push_back (child);
    return child;
  }

  bool
  Node::hasChildNodes () const
  {
    if (m_child_nodes.getLength () != 0) {
      return true;
    }
    else {
      return false;
    }
  }
}