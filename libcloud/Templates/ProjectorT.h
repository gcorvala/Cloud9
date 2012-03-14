#ifndef __PROJECTOR_T_H__
#define __PROJECTOR_T_H__

template <class PointT>
class ProjectorT : public FilterT <PointT> {
  public:
    ProjectorT ();
    virtual ~ProjectorT ();

    void compute (const PointCloudT <PointT>& input, PointCloudT <PointT>& output) const;

  protected:
    virtual PointT project (const PointT& point) const = 0;
};

template <class PointT>
ProjectorT <PointT>::ProjectorT ()
{
}

template <class PointT>
ProjectorT <PointT>::~ProjectorT ()
{
}

template <class PointT>
void
ProjectorT <PointT>::compute (const PointCloudT <PointT>& input, PointCloudT <PointT>& output) const
{
  typename PointCloudT <PointT>::const_iterator it;

  output.clear ();

  for (it = input.begin (); it != input.end (); ++it) {
    output.push_back (project (*it));
  }
}

#endif