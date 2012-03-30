#ifndef __NODE_H__
#define __NODE_H__

// FIXME

#include <string>
#include <vector>
#include <map>
#include "Types.h"

namespace XML {
  class Node {
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
      
      Node ();
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
      //XMLDocument* getOwnerDocument () const;
      Node* cloneNode (Boolean deep) const;
      Node* insertChildBefore (Node* child, Node* ref);
      Node* replaceChild (Node* child, Node* old);
      Node* removeChild (Node* child);
      Node* appendChild (Node* child);
      Boolean hasChildNodes () const;
      void setNodeValue (const std::string& value);

    protected:
      std::string m_node_name;
  };
}

#endif