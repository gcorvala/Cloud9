#ifndef __META_TYPES_H__

#include <libcloud/2D/Image.h>
#include <libcloud/2D/Matrix.h>
#include <libcloud/Common/PointCloud.h>

Q_DECLARE_METATYPE (Image*);
Q_DECLARE_METATYPE (Matrix<UInt8>*);
Q_DECLARE_METATYPE (PointCloud*);

#endif