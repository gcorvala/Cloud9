#ifndef __XML_NODE_H__
#define __XML_NODE_H__

// FIXME

#include <string>
#include <map>
#include "NodeList.h"

namespace XML {
  class Document;
  class Node {
    friend class Document;
    public:
      enum Type {
        Element,
        Attribute,
        Text,
        CDataSection,
        EntityReference,
        Entity,
        ProcessingInstruction,
        Comment,
        Document,
        DocumentType,
        DocumentFragment,
        Notation
      };
      
      Node (Type type);
      virtual ~Node ();

      // DOM Level 1
      std::string getNodeName () const;
      std::string getNodeValue () const;
      void setNodeValue (const std::string& value);
      Type getNodeType () const;
      Node* getParentNode () const;
      NodeList getChildNodes () const;
      Node* getFirstChild () const;
      Node* getLastChild () const;
      //Node* getPreviousSibling () const;
      //Node* getNextSibling () const;
      std::map <std::string, std::string>* getAttributes () const;
      XML::Document* getOwnerDocument () const;
      Node* cloneNode (bool deep) const;
      Node* insertChildBefore (Node* child, Node* ref);
      Node* replaceChild (Node* child, Node* old);
      Node* removeChild (Node* child);
      Node* appendChild (Node* child);
      bool hasChildNodes () const;
      
    protected:
      std::string m_node_name;
      std::string m_node_value;
      Type m_node_type;
      Node* m_parent_node;
      NodeList m_child_nodes;      
      
      XML::Document* m_owner_document;
  };
}

#endif