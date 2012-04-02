#ifndef __XML_NODE_H__
#define __XML_NODE_H__

// FIXME

#include <string>
#include <vector>
#include <map>
#include "Types.h"

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
      Type getNodeType () const;
      Node* getParentNode () const;
      std::vector <Node*> getChildNodes () const;
      Node* getFirstChild () const;
      Node* getLastChild () const;
      Node* getPreviousSibling () const;
      Node* getNextSibling () const;
      std::map <std::string, std::string>* getAttributes () const;
      XML::Document* getOwnerDocument () const;
      Node* cloneNode (Boolean deep) const;
      Node* insertChildBefore (Node* child, Node* ref);
      Node* replaceChild (Node* child, Node* old);
      Node* removeChild (Node* child);
      Node* appendChild (Node* child);
      Boolean hasChildNodes () const;
      void setNodeValue (const std::string& value);
      
    protected:
      std::string m_node_name;
      std::string m_node_value;
      XML::Document* m_owner_document;
      Type m_node_type;
      std::vector <Node*> m_child_nodes;
  };
}

#endif