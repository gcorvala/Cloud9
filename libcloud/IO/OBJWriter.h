#ifndef __OBJ_WRITER_H__
#define __OBJ_WRITER_H__

#include "FileWriter.h"

class OBJWriter : FileWriter {
  public:
    OBJWriter();
    ~OBJWriter();
    int write (const std::string& file_name, const PointCloud& cloud, const bool binary = false);
};

#endif