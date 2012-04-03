#ifndef __XML_DOCUMENT_H__
#define __XML_DOCUMENT_H__

#include "Node.h"
#include "DocumentType.h"
#include "DOMImplementation.h"
#include "Element.h"
#include <string>

namespace XML {
  class DOMImplementation;
  class Document : public Node {
    friend class DOMImplementation;
    public:
      Document ();
      Document (XML::DocumentType& doc_type);
      virtual ~Document ();

      // DOM Level 1
      XML::Element* getDocumentElement () const;
      XML::Element* createElement (const std::string& tag_name);
//      DocumentFragment* createDocumentFragment ();
//      Text* createTextNode (const std::string& data);
//      Comment* createComment (const std::string& data);
//      CDATASection* createCDATASection (const std::string& data);
//      ProcessingInstruction* createProcessingInstruction (const std::string& target, const std::string& data);
//      Attr* createAttribute (const std::string& name);
//      EntityReference* createEntityReference (const std::string& name);
//      NodeList* getElementsByTagName (const std::string& tag_name);

      std::string getString () const;

    protected:
      XML::DocumentType* m_doc_type;
      XML::DOMImplementation* m_implementation;
      XML::Element* m_document_element;
      bool m_xml_standalone;
      std::string m_xml_version;
  };
}

#endif