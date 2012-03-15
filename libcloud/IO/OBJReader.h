#ifndef __OBJ_READER_H__
#define __OBJ_READER_H__

#include "FileReader.h"
#include "../Templates/PointCloudT.h"

class OBJReader : FileReader {
  public:
    OBJReader ();
    ~OBJReader ();
    int read (const std::string& file_name, PointCloud& cloud, bool binary = false);
};

#endif