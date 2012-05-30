#include "HoughTransform2D.h"

#include <math.h>

HoughTransform2D::HoughTransform2D ()
{
  std::vector <Range> parameters;

  Range rho (-5000., 5000., 1000);
  Range theta (0., 2.*M_PI, 1000);

  parameters.push_back (rho);
  parameters.push_back (theta);

  m_accumulator = Accumulator (parameters);
}

HoughTransform2D::~HoughTransform2D ()
{
}

void
HoughTransform2D::run ()
{
  Float32 diag = m_cloud->getBoundingBox ().getDiagonalLength ();

  std::vector <Range> parameters;

  Range rho (-diag, diag, 1000);
  Range theta (0., M_PI, 1000);

  parameters.push_back (rho);
  parameters.push_back (theta);

  m_accumulator = Accumulator (parameters);

  PRINT (diag);

  for (UInt32 vertex_id = 0; vertex_id < m_cloud->size (); ++vertex_id) {
    const Point3D& p = m_cloud->at(vertex_id);
    PRINT (vertex_id);
    for (UInt32 i = 0; i < m_accumulator.getRanges ()[1].getSteps (); ++i) {
      Float32 theta = m_accumulator.getRanges ()[1][i].getCenter ();
      Float32 rho = p.x * cos (theta) + p.y * sin (theta);
      std::vector <Float32> parameters;
      parameters.push_back (rho);
      parameters.push_back (theta);
      m_accumulator.vote (AccumulatorVote (parameters, vertex_id));
    }
  }
}