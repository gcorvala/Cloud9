#include "TextContent.h"

namespace SVG {
  TextContent::TextContent (const std::string& id, const std::string& xml_base)
    :Element ("text", id, xml_base)
  {
  }

  TextContent::~TextContent ()
  {
  }
}