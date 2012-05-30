#ifndef __PLY_READER_H__
#define __PLY_READER_H__

#include "Reader.h"

class PLYReader : public Reader {
  public:
    PLYReader ();
    ~PLYReader ();

  protected:
    enum Format {
      ASCII,
      BINARY_LITTLE_ENDIAN,
      BINARY_BIG_ENDIAN
    };
    void readHeader (std::ifstream& file, PointCloud3D& cloud, Header& header) const;
    void readBody (std::ifstream& file, PointCloud3D& cloud, const Header& header) const;
    void parseMagic (std::string& line) const;
    void parseFormat (std::string& line, Format& format) const;
    void parseHeaderLine (std::string& line) const;
};

#endif