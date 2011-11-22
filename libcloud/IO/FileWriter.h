#ifndef __FILE_WRITER__
#define __FILE_WRITER__

#include "../Common/PointCloud.h"
#include <string>

class FileWriter {
  public:
    FileWriter ();
    virtual ~FileWriter ();
    virtual int write (const std::string& file_name, const PointCloud& cloud, const bool binary = false) = 0;
};

#endif