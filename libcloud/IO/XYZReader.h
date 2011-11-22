#ifndef __XYZ_READER_H__
#define __XYZ_READER_H__

#include "FileReader.h"

class XYZReader : FileReader {
  public:
    XYZReader ();
    ~XYZReader ();
    int read (const std::string& file_name, PointCloud& cloud, bool binary = false);
};

#endif