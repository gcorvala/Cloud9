#include <libcloud/Common/PointCloud.h>
#include <libcloud/IO/OBJWriter.h>
#include <iostream>
#include <stdlib.h>
#include <math.h>

/*
  Box-Muller method
*/

Float64
gaussianRand (double mu, double sigma) {
  Float64 u = ((Float64) rand ())/((Float64) RAND_MAX);
  Float64 b = ((Float64) rand ())/((Float64) RAND_MAX);

  Float64 g = sqrt (-2.0*log(u))*cos (2.*M_PI*b);

  return (mu+sigma*g);
}

void
normalNoise (Point& point, Float64 sigma)
{
  point.x = gaussianRand (point.x, sigma);
  point.y = gaussianRand (point.y, sigma);
  point.z = gaussianRand (point.z, sigma);
}

int
main (int argc, char** argv)
{
  OBJWriter writer;
  PointCloud cloud;
  PointCloud::iterator it;

  if (argc != 5) {
    std::cout << "Usage : " << argv[0] << " n sigma w output.obj" << std::endl;
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
    p.m_color = Color (rand () % 256, rand () % 256, rand () % 256);
    cloud.push_back (p);
  }

  // face 2
  for (UInt32 i = 0; i < nb; ++i) {
    Float64 x = rand ()%width;
    Float64 y = rand ()%width;
    Float64 z = (Float64) width/2;
    Point p (x-z, y-z, -z);
    p.m_color = Color (rand () % 256, rand () % 256, rand () % 256);
    cloud.push_back (p);
  }

  // face 3
  for (UInt32 i = 0; i < nb; ++i) {
    Float64 x = rand ()%width;
    Float64 y = (Float64) width/2;
    Float64 z = rand ()%width;
    Point p (x-y, y, z-y);
    p.m_color = Color (rand () % 256, rand () % 256, rand () % 256);
    cloud.push_back (p);
  }

  // face 4
  for (UInt32 i = 0; i < nb; ++i) {
    Float64 x = rand ()%width;
    Float64 y = (Float64) width/2;
    Float64 z = rand ()%width;
    Point p (x-y, -y, z-y);
    p.m_color = Color (rand () % 256, rand () % 256, rand () % 256);
    cloud.push_back (p);
  }

  // face 5
  for (UInt32 i = 0; i < nb; ++i) {
    Float64 x = (Float64) width/2;
    Float64 y = rand ()%width;
    Float64 z = rand ()%width;
    Point p (x, y-x, z-x);
    p.m_color = Color (rand () % 256, rand () % 256, rand () % 256);
    cloud.push_back (p);
  }

  // face 6
  for (UInt32 i = 0; i < nb; ++i) {
    Float64 x = (Float64) width/2;
    Float64 y = rand ()%width;
    Float64 z = rand ()%width;
    Point p (-x, y-x, z-x);
    p.m_color = Color (rand () % 256, rand () % 256, rand () % 256);
    cloud.push_back (p);
  }

  for (it = cloud.begin (); it != cloud.end (); ++it) {
    normalNoise (*it, sigma);
  }


  writer.write (output, cloud);

  return 0;
}
