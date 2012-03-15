#ifndef __POINT_CLOUD_T_H__
#define __POINT_CLOUD_T_H__

#include "../Common/Types.h"
#include <vector>

template <class PointT>
class PointCloudT {
  public:
    typedef typename std::vector <PointT>::iterator iterator;
    typedef typename std::vector <PointT>::const_iterator const_iterator;

    PointCloudT ();
    PointCloudT (const PointCloudT& cloud);
    virtual ~PointCloudT ();

    iterator begin ();
    iterator end ();
    const_iterator begin () const;
    const_iterator end () const;
    UInt32 size () const;
/*    void reserve (UInt32 n);
    void resize (UInt32 n);
    bool empty ();*/
    const PointT& operator[] (UInt32 n) const;
    PointT& operator[] (UInt32 n);
    PointCloudT& operator+= (const PointCloudT& cloud);
/*    const Point& at (UInt32 n) const;
    Point& at (UInt32 n);
    const Point& front () const;
    Point& front ();
    const Point& back () const;
    Point& back ();*/
    void push_back (const PointT& p);
/*    iterator insert (iterator position, const Point& p);
    void insert (iterator position, UInt32 n, const Point& p);
    iterator erase (iterator position);
    iterator erase (iterator first, iterator last);*/
    void clear ();

  protected:
    std::vector <PointT> m_points;
};

template <class PointT>
PointCloudT <PointT>::PointCloudT ()
{
}

template <class PointT>
PointCloudT <PointT>::PointCloudT (const PointCloudT& cloud)
  :m_points (cloud.m_points)
{
}

template <class PointT>
PointCloudT <PointT>::~PointCloudT ()
{
}

template <class PointT>
typename std::vector <PointT>::iterator
PointCloudT <PointT>::begin ()
{
  return m_points.begin ();
}

template <class PointT>
typename std::vector <PointT>::iterator
PointCloudT <PointT>::end ()
{
  return m_points.end ();
}

template <class PointT>
typename std::vector <PointT>::const_iterator
PointCloudT <PointT>::begin () const
{
  return m_points.begin ();
}

template <class PointT>
typename std::vector <PointT>::const_iterator
PointCloudT <PointT>::end () const
{
  return m_points.end ();
}

template <class PointT>
UInt32
PointCloudT <PointT>::size () const
{
  return m_points.size ();
}

template <class PointT>
const PointT&
PointCloudT <PointT>::operator[] (UInt32 n) const
{
  return m_points[n];
}

template <class PointT>
PointT&
PointCloudT <PointT>::operator[] (UInt32 n)
{
  return m_points[n];
}

template <class PointT>
PointCloudT <PointT>&
PointCloudT <PointT>::operator+= (const PointCloudT& cloud)
{
  UInt32 s = m_points.size ();

  m_points.resize (s+cloud.m_points.size ());

  for (UInt32 i = s; i < m_points.size (); ++i) {
    m_points[i] = cloud.m_points[i-s];
  }
}

template <class PointT>
void
PointCloudT <PointT>::push_back (const PointT& p)
{
  m_points.push_back (p);
}

template <class PointT>
void
PointCloudT <PointT>::clear ()
{
  m_points.clear ();
}

#endif