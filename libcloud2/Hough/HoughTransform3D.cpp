#include "HoughTransform3D.h"

#include "../Common/Range.h"
#include <math.h>

HoughTransform3D::HoughTransform3D ()
{
  std::vector <Range> parameters;

  Range rho (-2000., 2000., 200);
  Range phi (0., M_PI*2., 45);
  Range theta (0., M_PI*2., 45);

  parameters.push_back (rho);
  parameters.push_back (phi);
  parameters.push_back (theta);

  m_accumulator = Accumulator (parameters);
}

HoughTransform3D::~HoughTransform3D ()
{
}

void
HoughTransform3D::run ()
{
  for (UInt32 vertex_id = 0; vertex_id < m_cloud->size (); ++vertex_id) {
    const Point3D& p = m_cloud->at(vertex_id);
    for (UInt32 i = 0; i < m_accumulator.getRanges ()[2].getSteps (); ++i) {
      for (UInt32 j = 0; j < m_accumulator.getRanges ()[1].getSteps (); ++j) {
        Float32 theta = m_accumulator.getRanges ()[2][i].getCenter ();
        Float32 phi = m_accumulator.getRanges ()[1][j].getCenter ();
        Float32 rho = p.x * cos (theta) * sin (phi);
        rho += p.y * sin (phi) * sin (theta);
        rho += p.z * cos (phi);
        std::vector <Float32> parameters;
        parameters.push_back (rho);
        parameters.push_back (phi);
        parameters.push_back (theta);
        m_accumulator.vote (AccumulatorVote (parameters, vertex_id));
      }
    }
  }
}