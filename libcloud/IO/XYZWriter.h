#ifndef __XYZ_WRITER_H__
#define __XYZ_WRITER_H__

#include "FileWriter.h"

class XYZWriter : FileWriter {
  public:
    XYZWriter ();
    ~XYZWriter ();
    int write (const std::string& file_name, const PointCloud& cloud, const bool binary = false);
};

#endif