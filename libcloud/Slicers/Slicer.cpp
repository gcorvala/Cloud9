#include "Slicer.h"

Slicer::Slicer (Float64 thickness, UInt32 resolution)
  :m_thickness(thickness)
  ,m_resolution(resolution)
{
}

Slicer::~Slicer ()
{
}

Float64
Slicer::getThickness () const
{
  return m_thickness;
}

void
Slicer::setThickness (Float64 thickness)
{
  m_thickness = thickness;
}