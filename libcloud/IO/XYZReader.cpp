#include "XYZReader.h"

#include "../Common/Utils.h"
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <stdlib.h>

XYZReader::XYZReader ()
{
}

XYZReader::~XYZReader ()
{
}

int
XYZReader::read (const std::string& file_name, PointCloud& cloud, bool binary) {
  std::ios_base::openmode mode = std::ifstream::in;
  if (binary) {
    mode |= std::ifstream::binary;
  }
  std::ifstream input (file_name.c_str (), mode);
  std::string line;
  std::vector<std::string> st;
  if (!input.is_open ()) {
    std::cerr << "Failed to open file " << file_name << std::endl;
    return -1;
  }
  while (!input.eof()) {
    if (binary) {
      double x, y, z;
      input.read ((char*) &x, sizeof (x));
      input.read ((char*) &y, sizeof (y));
      input.read ((char*) &z, sizeof (z));
      if (!input.eof ()) {
        cloud.push_back (Point (x, y, z));
      }
    }
    else {
      // FIXME : use '>>' instead
      getline (input, line);
      if (line.length () != 0) {
        StringSplit (line, " ", st);
        cloud.push_back (Point (strtod (st[0].c_str(), NULL),
                                strtod (st[1].c_str(), NULL),
                                strtod (st[2].c_str(), NULL)));
        st.clear ();
      }
    }
  }
  return 0;
}