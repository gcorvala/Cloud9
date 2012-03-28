#include <libcloud/Templates/PointCloudT.h>
#include <libcloud/Templates/OBJReaderT.h>
#include <libcloud/Templates/OBJWriterT.h>
#include <libcloud/Templates/SlicerT.h>
#include <libcloud/Templates/XYSlicerT.h>
#include <libcloud/Templates/XZSlicerT.h>
#include <libcloud/Templates/YZSlicerT.h>
#include <libcloud/Templates/Point3D.h>
#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <sstream>

int
main (int argc, char** argv)
{
  char* exec = argv[0];
  char* ori;
  char* input;
  char* output;
  Float64 thickness;
  OBJReaderT <Float32> reader;
  OBJWriterT <Float32> writer;
  PointCloudT < Point3D <Float32> > cloud;
  SlicerT < Point3D <Float32> >* slicer;
  std::vector < PointCloudT < Point3D <Float32> > > slices;
  

  if (argc != 5) {
    std::cerr << "1 Usage : " << exec << " -[xy|xz|yz] thickness input.obj output" << std::endl;
    return -1;
  }

  ori = argv[1];
  thickness = strtod (argv[2], NULL);
  input = argv[3];
  output = argv[4];

  reader.read (input, cloud);

  if (strcmp ("-xy", ori) == 0) {
    slicer = new XYSlicerT < Point3D <Float32> > (thickness);
  }
  else if (strcmp ("-xz", ori) == 0) {
    slicer = new XZSlicerT < Point3D <Float32> > (thickness);
  }
  else if (strcmp ("-yz", ori) == 0) {
    slicer = new YZSlicerT < Point3D <Float32> > (thickness);
  }
  else {
    std::cerr << "Direction could be -xy, -xz or -yz" << std::endl;
    return -1;
  }

  slicer->compute (cloud, slices);

  cloud.clear ();

  for (UInt32 i = 0; i < slices.size (); ++i) {
    std::ostringstream out;

    out << output << "_" << i << ".obj";
    std::cout << "output: " << out.str () << std::endl;
    writer.write (out.str (), slices[i]);
  }

  delete slicer;

  return 0;
}