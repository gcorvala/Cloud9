#include "Reader.h"

Reader::Reader ()
{
}

Reader::~Reader ()
{
}

void
Reader::read (const std::string& file_name, PointCloud& cloud) const
{
  Header header;
  std::ifstream file (file_name.c_str (), std::ifstream::in);

  if (!file) {
    throw ("File read failed");
  }
  
  cloud.clear ();

  readHeader (file, cloud, header);
  readBody (file, cloud, header);
}
