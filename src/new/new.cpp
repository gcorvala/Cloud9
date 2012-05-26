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
  try {
    std::vector <Float32> min, max, bin_size;
    std::vector <Float32> maxima_values;
    std::vector < std::vector <UInt32> > maxima_voter_ids;
    Range theta (0, 10, 10);
    Range phi (0, 10, 10);
    Range rho (0, 10, 10);
    std::vector <Range> parameters;
    parameters.push_back (theta);
    parameters.push_back (phi);
    parameters.push_back (rho);

    Accumulator accu (parameters);

    /*params.push_back (1);
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
    std::cout << "ok2" << std::endl;*/
    for (int i = 0; i < 100; ++i) {
      std::vector <Float32> params;
      params.push_back (1./10.*i);
      params.push_back (1./10.*i);
      params.push_back (1./10.*i);
      accu.vote (AccumulatorVote (params, i));
    }

    accu.findMaxima (3, maxima_values, maxima_voter_ids);

    for (UInt32 i = 0; i < maxima_values.size (); ++i) {
      std::cout << "max: " << maxima_values[i] << std::endl;
      for (UInt32 j = 0; j < maxima_voter_ids[i].size (); ++j) {
        std::cout << "  id: " << maxima_voter_ids[i][j] << std::endl;
      }
    }

    PLYReader reader;
    PointCloud cloud;

    reader.read (argv[1], cloud);
    std::cout << "cloud size: " << cloud.size () << std::endl;
  
    HoughTransform3D hough;

    hough.setInput (cloud);
    hough.run ();
    accu = hough.getAccumulator ();
    accu.findMaxima (1, maxima_values, maxima_voter_ids);
    for (UInt32 i = 0; i < maxima_values.size (); ++i) {
      std::cout << "max: " << maxima_values[i] << std::endl;
      for (UInt32 j = 0; j < maxima_voter_ids[i].size (); ++j) {
        std::cout << "  id: " << maxima_voter_ids[i][j] << std::endl;
      }
    }
  } catch (char const* msg) {
    std::cout << "Exception: " << msg << " !" << std::endl;
  } catch (std::string& msg) {
    std::cout << "Exception: " << msg << " !" << std::endl;
  }

  return 0;
}
