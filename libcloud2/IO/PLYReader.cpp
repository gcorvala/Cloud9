#include "PLYReader.h"

#include <fstream>
#include <string>
#include <sstream>

PLYReader::PLYReader ()
{
}

PLYReader::~PLYReader ()
{
}

void
PLYReader::readHeader (std::ifstream& file, PointCloud& cloud, Header& header) const
{
  std::string line;
  std::string token;
  Format format;
  UInt32 n;

  getline (file, line);
  parseMagic (line);
  getline (file, line);
  parseFormat (line, format);

  while (!file.eof ()) {
    getline (file, line);
    std::istringstream iss (line);

    iss >> token;

    if (token == "comment") {
    }
    else if (token == "element") {
      iss >> token;
      
      if (token == "vertex") {
        iss >> header.n_vertices;
      }
      else if (token == "face") {
        
      }
      else {
        throw "PLY format not yet implemented!";
      }
    }
    else if (token == "property") {
      
    }
    else if (token == "end_header") {
      break;
    }
    else {
      throw "PLY format not yet implemented!";
    }
  }
}

void
PLYReader::readBody (std::ifstream& file, PointCloud& cloud, const Header& header) const
{
  Float32 x, y, z;
  UInt32 empty;

  //for (UInt32 i = 0; i < header.n_vertices; ++i) {
  for (UInt32 i = 0; i < 200; ++i) {
    file.read ((char*) &x, sizeof (x));
    file.read ((char*) &y, sizeof (x));
    file.read ((char*) &z, sizeof (x));
    file.read ((char*) &empty, 4);

    cloud += Point (x, y, z);
  }
}

void
PLYReader::parseMagic (std::string& line) const
{
  if (line != "ply") {
    throw "PLY magic not found";
  }
}

void
PLYReader::parseFormat (std::string& line, Format& format) const
{
  std::string token;
  std::istringstream stream (line);

  stream >> token;

  if (token != "format") {
    throw "PLY format not found";
  }

  stream >> token;

  if (token == "ascii") {
    format = ASCII;
  }
  else if (token == "binary_little_endian") {
    format = BINARY_LITTLE_ENDIAN;
  }
  else if (token == "binary_big_endian") {
    format = BINARY_BIG_ENDIAN;
  }
  else {
    throw "PLY format not recognised";
  }
}

void
PLYReader::parseHeaderLine (std::string& line) const
{
  
}