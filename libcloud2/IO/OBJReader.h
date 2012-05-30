#ifndef __OBJ_READER_H__
#define __OBJ_READER_H__

#include "Reader.h"

class OBJReader : public Reader {
  public:
    OBJReader ();
    ~OBJReader ();

  protected:
    void readHeader (std::ifstream& file, PointCloud3D& cloud) const;
    void readBody (std::ifstream& file, PointCloud3D& cloud) const;
};

#endif