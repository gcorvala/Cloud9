#ifndef __READER_H__
#define __READER_H__

#include "../Common/PointCloud.h"
#include <string>
#include <fstream>

class Reader {
  public:
    Reader ();
    virtual ~Reader ();

    void read (const std::string& file_name, PointCloud& cloud) const;

  protected:
    struct Header {
      UInt32 n_vertices;
    };
    
    virtual void readHeader (std::ifstream& file, PointCloud& cloud, Header& header) const = 0;
    virtual void readBody (std::ifstream& file, PointCloud& cloud, const Header& header) const = 0;
};

#endif
