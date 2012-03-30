#ifndef __NODE_H__
#define __NODE_H__

// FIXME

#include <string>

namespace XML {
  class Node {
    public:
      Node (const std::string& name);
      virtual ~Node ();

    protected:
      std::string m_name;
      std::string m_text_content;
  };
}

#endif