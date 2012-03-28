#ifndef __OBJ_WRITER_T_H__
#define __OBJ_WRITER_T_H__

#include "PointCloudT.h"
#include "Point3D.h"
#include <string>
#include <fstream>

template <typename T>
class OBJWriterT {
  public:
    OBJWriterT ();
    ~OBJWriterT ();

    int write (const std::string& file_name, const PointCloudT < Point3D <T> >& cloud, const bool binary = false);
};

template <typename T>
OBJWriterT <T>::OBJWriterT ()
{
}

template <typename T>
OBJWriterT <T>::~OBJWriterT ()
{
}

template <typename T>
int
OBJWriterT <T>::write (const std::string& file_name, const PointCloudT < Point3D <T> >& cloud, const bool binary)
{
  std::ofstream output (file_name.c_str (), std::ofstream::out);
  typename PointCloudT < Point3D <T> >::const_iterator it;

  if (binary) {
    std::cerr << "Binary mode not supported by OBJ file format" << std::endl;
    return -1;
  }
  if (!output.is_open ()) {
    std::cerr << "Failed to open file " << file_name << std::endl;
    return -1;
  }

  output << "# File generated by libcloud" << std::endl;
  output << "g Point_Model" << std::endl;

  for (it = cloud.begin (); it != cloud.end (); ++it) {
    output << "v " << (*it).x << " " << (*it).y << " " << (*it).z << std::endl;
  }

  return 0;
}

#endif