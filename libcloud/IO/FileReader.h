#ifndef __FILE_READER_H__
#define __FILE_READER_H__

#include "../Common/PointCloud.h"
#include <string>

class FileReader {
  public:
    FileReader ();
    virtual ~FileReader ();
    //virtual int readHeader (const std::string& file_name, PointCloud& cloud) = 0;
    virtual int read (const std::string& file_name, PointCloud& cloud, bool binary = false) = 0;
};

#endif
