#include "XYZWriter.h"

#include <fstream>
#include <iostream> // FIXME

XYZWriter::XYZWriter () {
}

XYZWriter::~XYZWriter () {
}

int
XYZWriter::write (const std::string& file_name, const PointCloud& cloud, const bool binary)
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

  for (it = cloud.begin (); it != cloud.end (); ++it) {
    if (binary) {
      double x = (*it).x;
      double y = (*it).y;
      double z = (*it).z;
      output.write ((char*) &x, sizeof (x));
      output.write ((char*) &y, sizeof (y));
      output.write ((char*) &z, sizeof (z));
    }
    else {
      output << (*it).x << " " << (*it).y << " " << (*it).z << std::endl;
    }
  }

  return 0;
}