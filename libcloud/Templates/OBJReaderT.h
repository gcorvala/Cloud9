#ifndef __OBJ_READER_T_H__
#define __OBJ_READER_T_H__

#include "PointCloudT.h"
#include "Point3D.h"
#include "../Common/Utils.h"
#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <stdlib.h>

template <typename T>
class OBJReaderT {
  public:
    OBJReaderT ();
    ~OBJReaderT ();
    int read (const std::string& file_name, PointCloudT < Point3D <T> >& cloud, bool binary = false);
};

template <typename T>
OBJReaderT <T>::OBJReaderT ()
{
}

template <typename T>
OBJReaderT <T>::~OBJReaderT ()
{
}

template <typename T>
int
OBJReaderT <T>::read (const std::string& file_name, PointCloudT < Point3D <T> >& cloud, bool binary)
{
  std::ifstream input (file_name.c_str () , std::ifstream::in);
  std::string line;
  std::vector <std::string> st;
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
      cloud.push_back (Point3D <T> (strtod (st[1].c_str (), NULL),
                                    strtod (st[2].c_str (), NULL),
                                    strtod (st[3].c_str (), NULL)));
      st.clear ();
    }
  }
  return 0;
}

#endif