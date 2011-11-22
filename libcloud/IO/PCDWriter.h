#ifndef __PCD_WRITER_H__
#define __PCD_WRITER_H__

#include "FileWriter.h"
#include "../Common/PointCloud.h"

class PCDWriter : public FileWriter {
  public:
    PCDWriter();
    ~PCDWriter();
    int write (const std::string& file_name, const PointCloud& cloud, const bool binary = false);
};

#endif