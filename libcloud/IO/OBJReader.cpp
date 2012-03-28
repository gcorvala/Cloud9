#include "OBJReader.h"

#include "../Common/Utils.h"
#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <stdlib.h>

OBJReader::OBJReader ()
{
}

OBJReader::~OBJReader ()
{
}

int
OBJReader::read (const std::string& file_name, PointCloud& cloud, bool binary) {
  std::ifstream input (file_name.c_str () , std::ifstream::in);
  std::string line;
  std::vector<std::string> st;
  if (binary) {
    std::cerr << "Binary mode not supported by OBJ file format" << std::endl;
    return -1;
  }
  if (!input.is_open ()) {
    std::cerr << "Failed to open file " << file_name << std::endl;
    return -1;
  }
  while (!input.eof ()) {
    getline (input, line);
    if (line[0] == 'v') {
      StringSplit (line, " ", st);
      cloud.push_back (Point (strtod (st[1].c_str (), NULL),
                              strtod (st[2].c_str (), NULL),
                              strtod (st[3].c_str (), NULL)
                              /*,
                              Color (atoi (st[4].c_str ()),
                                     atoi (st[5].c_str ()),
                                     atoi (st[6].c_str ()))*/
                                     ));
      st.clear ();
    }
  }
  return 0;
}
