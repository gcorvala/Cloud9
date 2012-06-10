%module example

%{
	#include "Common/Types.h"
	#include "Common/Interval.h"
	#include "Common/ModelCoefficients.h"
	#include "Common/PointCloud3D.h"
	#include "Common/Range.h"
	#include "Common/Timer.h"

	#include "Geometry/BoundingBox3D.h"
	#include "Geometry/Box2D.h"
	#include "Geometry/Box3D.h"
	#include "Geometry/Line2D.h"
	#include "Geometry/Point2D.h"
	#include "Geometry/Point3D.h"
	#include "Geometry/Vector2D.h"
	#include "Geometry/Vector3D.h"

	#include "IO/Reader.h"
	#include "IO/PLYReader.h"
%}

%include "std_string.i"
%include "std_vector.i"

%template(Indices) std::vector<UInt32>;

%include "Common/Interval.h"
%include "Common/ModelCoefficients.h"
%include "Common/PointCloud3D.h"
%include "Common/Range.h"
%include "Common/Timer.h"
%include "Common/Types.h"

%include "Geometry/BoundingBox3D.h"
%include "Geometry/Box2D.h"
%include "Geometry/Box3D.h"
%include "Geometry/Line2D.h"
%include "Geometry/Point2D.h"
%include "Geometry/Point3D.h"
%include "Geometry/Vector2D.h"
%include "Geometry/Vector3D.h"

%include "IO/Reader.h"
%include "IO/PLYReader.h"

%extend PointCloud3D
{
	Point3D& __getitem__ (UInt32 n) 
	{
		return (*self)[n];
	}
}