#ifndef __PCD_READER_H__
#define __PCD_READER_H__

#include "FileReader.h"

class PCDReader : FileReader {
  public:
    PCDReader ();
    ~PCDReader ();
    int read (const std::string& file_name, PointCloud& cloud, bool binary = false);
};

#endif