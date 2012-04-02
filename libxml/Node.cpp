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
  Node::appendChild (Node* child)
  {
    m_child_nodes.push_back (child);
    return child;
  }
}