#include "PCDReader.h"

#include "../Common/Utils.h"
#include <fstream>
#include <iostream>
#include <stdlib.h>

PCDReader::PCDReader ()
{
}

PCDReader::~PCDReader ()
{
}

int
PCDReader::read (const std::string& file_name, PointCloud& cloud, bool) {
  std::ifstream input (file_name.c_str (), std::ifstream::in);
  std::string line;
  std::vector<std::string> st;
  if (!input.is_open ()) {
    std::cerr << "Failed to open file " << file_name << std::endl;
    return -1;
  }
  for (int i = 0; i < 10; ++i) {
    getline (input, line);
  }
  while (!input.eof()) {
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
  return 0;
}
