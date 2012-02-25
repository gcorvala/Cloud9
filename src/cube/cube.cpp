#include <libcloud/Common/PointCloud.h>
#include <libcloud/IO/OBJWriter.h>
#include <iostream>
#include <stdlib.h>
#include <math.h>

void
normalNoise (Point& point, Float64 sigma)
{
  Float64 noise;
  Float64 random = (Float64) (rand () % 100)/100;
  noise = Float64 (rand () % 10000)/1000-5;
  point.x += noise;
  noise = Float64 (rand () % 10000)/1000-5;
  point.y += noise;
  noise = Float64 (rand () % 10000)/1000-5;
  point.z += noise;
}

int
main (int argc, char** argv)
{
  OBJWriter writer;
  PointCloud cloud;
  PointCloud::iterator it;

  if (argc != 5) {
    std::cout << "Usage : " << argv[0] << " nb_points_per_faces gaussian_sigma width output.obj" << std::endl;
    return -1;
  }

  UInt32 nb = atoi (argv[1]);
  Float64 sigma = strtod (argv[2], NULL);
  UInt32 width = atoi (argv[3]);
  char* output = argv[4];

  srand (time (NULL));

  // face 1
  for (UInt32 i = 0; i < nb; ++i) {
    Float64 x = rand ()%width;
    Float64 y = rand ()%width;
    Float64 z = (Float64) width/2;
    Point p (x-z, y-z, z);
    p.m_color = Color (127+(rand () % 127), 127+(rand () % 127), 127+(rand () % 127));
    cloud.push_back (p);
  }

  // face 2
  for (UInt32 i = 0; i < nb; ++i) {
    Float64 x = rand ()%width;
    Float64 y = rand ()%width;
    Float64 z = (Float64) width/2;
    Point p (x-z, y-z, -z);
    p.m_color = Color (127+(rand () % 127), 127+(rand () % 127), 127+(rand () % 127));
    cloud.push_back (p);
  }

  // face 3
  for (UInt32 i = 0; i < nb; ++i) {
    Float64 x = rand ()%width;
    Float64 y = (Float64) width/2;
    Float64 z = rand ()%width;
    Point p (x-y, y, z-y);
    p.m_color = Color (127+(rand () % 127), 127+(rand () % 127), 127+(rand () % 127));
    cloud.push_back (p);
  }

  // face 4
  for (UInt32 i = 0; i < nb; ++i) {
    Float64 x = rand ()%width;
    Float64 y = (Float64) width/2;
    Float64 z = rand ()%width;
    Point p (x-y, -y, z-y);
    p.m_color = Color (127+(rand () % 127), 127+(rand () % 127), 127+(rand () % 127));
    cloud.push_back (p);
  }

  // face 5
  for (UInt32 i = 0; i < nb; ++i) {
    Float64 x = (Float64) width/2;
    Float64 y = rand ()%width;
    Float64 z = rand ()%width;
    Point p (x, y-x, z-x);
    p.m_color = Color (127+(rand () % 127), 127+(rand () % 127), 127+(rand () % 127));
    cloud.push_back (p);
  }

  // face 6
  for (UInt32 i = 0; i < nb; ++i) {
    Float64 x = (Float64) width/2;
    Float64 y = rand ()%width;
    Float64 z = rand ()%width;
    Point p (-x, y-x, z-x);
    p.m_color = Color (127+(rand () % 127), 127+(rand () % 127), 127+(rand () % 127));
    cloud.push_back (p);
  }

  for (it = cloud.begin (); it != cloud.end (); ++it) {
    normalNoise (*it, sigma);
  }


  writer.write (output, cloud);

  return 0;
}
