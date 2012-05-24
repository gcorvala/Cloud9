#include <libcloud2/Hough/Accumulator.h>
#include <libcloud2/Hough/AccumulatorVote.h>
#include <libcloud2/Hough/HoughTransform3D.h>
#include <libcloud2/Common/PointCloud.h>
#include <libcloud2/Common/Range.h>
#include <libcloud2/IO/PLYReader.h>

#include <iostream>
#include <vector>

int
main (int argc, char** argv)
{
  std::vector <Float32> min, max, bin_size;
  std::vector <Float32> maxima_values;
  std::vector < std::vector <UInt32> > maxima_voter_ids;
  Range theta (1, 10, 1);
  Range phi (2, 11, 1);
  Range rho (3, 12, 1);
  std::vector <Range> parameters;
  parameters.push_back (theta);
  parameters.push_back (phi);
  parameters.push_back (rho);

  min.push_back (1);
  min.push_back (2);
  min.push_back (3);

  max.push_back (10);
  max.push_back (11);
  max.push_back (12);
  
  bin_size.push_back (1);
  bin_size.push_back (1);
  bin_size.push_back (1);
  
  //Accumulator accu (min, max, bin_size);
  Accumulator accu (parameters);
  std::cout << "ok" << std::endl;
  std::vector <Float32> params;
  params.push_back (1);
  params.push_back (2);
  params.push_back (3);
  
  accu.vote (AccumulatorVote (params, 1));
  accu.vote (AccumulatorVote (params, 2));
  params[1] = 3;
  accu.vote (AccumulatorVote (params, 3));
  params[1] = 2;
  accu.vote (AccumulatorVote (params, 4));
  params[1] = 3;
  accu.vote (AccumulatorVote (params, 5));
  accu.vote (AccumulatorVote (params, 6));
  accu.vote (AccumulatorVote (params, 7));
  std::cout << "ok2" << std::endl;

  accu.findMaxima (3, maxima_values, maxima_voter_ids);
  std::cout << "ok3" << std::endl;

  for (UInt32 i = 0; i < maxima_values.size (); ++i) {
    std::cout << "max: " << maxima_values[i] << std::endl;
    for (UInt32 j = 0; j < maxima_voter_ids[i].size (); ++j) {
      std::cout << "  id: " << maxima_voter_ids[i][j] << std::endl;
    }
  }

  PLYReader reader;
  PointCloud cloud;

  try {
    reader.read (argv[1], cloud);
    std::cout << "cloud size: " << cloud.size () << std::endl;
  } catch (char const* msg) {
    std::cout << "Exception: " << msg << " !" << std::endl;
  }
  
  HoughTransform3D hough;

  hough.setInput (cloud);
  hough.run ();
  return 0;
}
