#include "PCDWriter.h"

#include <fstream>
#include <iostream> // FIXME

PCDWriter::PCDWriter() : FileWriter()
{
}

PCDWriter::~PCDWriter()
{
}

int
PCDWriter::write (const std::string& file_name, const PointCloud& cloud, const bool binary)
{
  std::ios_base::openmode mode = std::ofstream::out;
  if (binary) {
    mode |= std::ofstream::binary;
  }
  std::ofstream output (file_name.c_str (), mode);
  PointCloud::const_iterator it;
  if (!output.is_open ()) {
    std::cerr << "Failed to open file " << file_name << std::endl;
    return -1;
  }
  output << "VERSION .7" << std::endl;
  output << "FIELDS x y z" << std::endl;
  output << "SIZE 8 8 8" << std::endl;
  output << "TYPE F F F" << std::endl;
  output << "COUNT 1 1 1" << std::endl;
  output << "WIDTH " << cloud.size () << std::endl;
  output << "HEIGHT 1" << std::endl;
  output << "VIEWPOINT 0 0 0 1 0 0 0" << std::endl;
  output << "POINTS " << cloud.size () << std::endl;
  output << "DATA " << (binary ? "binary" : "ascii") << std::endl;

  for (it = cloud.begin (); it != cloud.end (); ++it) {
    if (binary) {
      float x = (*it).x;
      float y = (*it).y;
      float z = (*it).z;
      output.write ((char*) &x, 4);
      output.write ((char*) &y, 4);
      output.write ((char*) &z, 4);
    }
    else {
      output << (*it).x << " " << (*it).y << " " << (*it).z << std::endl;
    }
  }

  return 0;
}