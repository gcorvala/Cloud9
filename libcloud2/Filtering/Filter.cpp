#include "Filter.h"

Filter::Filter ()
{
}

Filter::~Filter ()
{
}

void
Filter::compute (const PointCloud3D& input, PointCloud3D& output)
{
  setInputCloud (input);
  compute (output);
}

const PointCloud3D&
Filter::getInputCloud () const
{
  return *m_input_cloud;
}

void
Filter::setInputCloud (const PointCloud3D& cloud)
{
  m_input_cloud = &cloud;
}

const Indices&
Filter::getInputIndices () const
{
  return m_input_indices;
}

void
Filter::setInputIndices (const Indices& indices)
{
  m_input_indices = indices;
}

UInt32
Filter::getInputSize () const
{
  if (m_input_indices.size () == 0) {
    return m_input_cloud->size ();
  }
  else {
    return m_input_indices.size ();
  }
}

UInt32
Filter::getInputIndex (UInt32 i) const
{
  if (m_input_indices.size () == 0) {
    return i;
  }
  else {
    return m_input_indices[i];
  }
}

const Point3D&
Filter::operator[] (UInt32 i) const
{
  if (m_input_indices.size () > 0) {
    return m_input_cloud->at (m_input_indices[i]);
  }
  else {
    return m_input_cloud->at (i);
  }
}