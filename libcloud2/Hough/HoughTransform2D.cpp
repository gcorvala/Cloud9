#include "HoughTransform2D.h"

#include "../Geometry/Line2D.h"
#include <math.h>

HoughTransform2D::HoughTransform2D (UInt32 n_rho, UInt32 n_theta)
{
  m_n_values.push_back (n_rho);
  m_n_values.push_back (n_theta);
}

HoughTransform2D::~HoughTransform2D ()
{
}

HoughTransform::ptr
HoughTransform2D::copy () const
{
  return new HoughTransform2D (*this);
}

void
HoughTransform2D::setInput (const PointCloud3D& cloud)
{
  HoughTransform::setInput (cloud);

  std::vector <Range> parameters;

  Box3D box = m_cloud->getBoundingBox ();
  m_min = box.getMin ();

  Float32 diag = box.getDiagonalLength ();

  Range rho (-diag, diag, m_n_values[0]);
  Range theta (0., M_PI, m_n_values[1]);

  parameters.push_back (rho);
  parameters.push_back (theta);

  delete m_accumulator;
  m_accumulator = new Accumulator2D (parameters);
}

void
HoughTransform2D::run ()
{
  ModelCoefficients model (2);

  Float32 theta_step = m_accumulator->getRanges ()[1].getStep ();

  UInt32 m = m_accumulator->getRanges ()[1].getSteps ();

  for (UInt32 vertex_id = 0; vertex_id < m_cloud->size (); ++vertex_id) {
    const Point3D p = m_cloud->at (vertex_id) - m_min;
    if (vertex_id % 1000 == 0) PRINT (vertex_id);
    for (UInt32 i = 0; i < m; ++i) {
      // FIXME : aliasing problem
      model[1] = theta_step*(i+0.5);
      //model[1] = theta_step * (i + 1e-10);
      model[0] = p.x * cos (model[1]) + p.y * sin (model[1]);
      m_accumulator->vote (model);
    }
  }
}

UInt32
HoughTransform2D::getNRho () const
{
  return m_n_values[0];
}

UInt32
HoughTransform2D::getNTheta () const
{
  return m_n_values[1];
}

void
HoughTransform2D::getInliers (const PointCloud3D& cloud, const Indices& max, Indices& inliers) const
{
  const std::vector <Range>& ranges = m_accumulator->getRanges ();
  Interval rho = ranges[0][max[0]];
  Interval theta = ranges[1][max[1]];

  Line2D line_1 (rho.getMin (), theta.getMin ());
  Line2D line_2 (rho.getMin (), theta.getMax ());
  Line2D line_3 (rho.getMax (), theta.getMin ());
  Line2D line_4 (rho.getMax (), theta.getMax ());

  inliers.clear ();

  Point3D o (0, 0, 0);

  for (UInt32 vertex_id = 0; vertex_id < cloud.size (); ++vertex_id) {
    const Point3D p = cloud[vertex_id] - m_min;
    Boolean l1 = (line_1.valueAt (p) >= 0) ^ (line_1.valueAt (o) > 0);
    Boolean l2 = (line_2.valueAt (p) >= 0) ^ (line_2.valueAt (o) > 0);
    Boolean l3 = (line_3.valueAt (p) >= 0) ^ (line_3.valueAt (o) < 0);
    Boolean l4 = (line_4.valueAt (p) >= 0) ^ (line_4.valueAt (o) < 0);
    
    if ((l3 || l4) && (l1 || l2)) {
      inliers.push_back (vertex_id);
    }
  }
}