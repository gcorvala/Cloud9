set (2D_SRCS 
	2D/CannyEstimator.cpp
	2D/FourierEstimator.cpp
	2D/GaussianEstimator.cpp
	2D/GradientEstimator.cpp
	2D/HilbertEstimator.cpp
	2D/HoughEstimator.cpp
	2D/HysteresisThresholdEstimator.cpp
	2D/Image.cpp
	2D/ImageDrawer.cpp
	2D/Line.cpp
	2D/MeanShiftEstimator.cpp
	2D/PhaseCongruencyEstimator.cpp
	2D/RemoveDCEstimator.cpp
	2D/ScharrEstimator.cpp
	2D/SobelEstimator.cpp
	2D/ThresholdEstimator.cpp
	)

set (2D_INCS
	2D/CannyEstimator.h
	2D/Estimator.h
	2D/FourierEstimator.h
	2D/GaussianEstimator.h
	2D/GradientEstimator.h
	2D/HilbertEstimator.h
	2D/HoughEstimator.h
	2D/HysteresisThresholdEstimator.h
	2D/Image.h
	2D/ImageDrawer.h
	2D/Line.h
	2D/Matrix.h
	2D/MeanShiftEstimator.h
	2D/PhaseCongruencyEstimator.h
	2D/RemoveDCEstimator.h
	2D/ScharrEstimator.h
	2D/SobelEstimator.h
	2D/ThresholdEstimator.h
	)

set (COMMON_SRCS
	Common/Box.cpp
	Common/Color.cpp
	Common/Plane.cpp
	Common/Point.cpp
	Common/PointCloud.cpp
	Common/Utils.cpp
	Common/Vector.cpp
	)

set (COMMON_INCS
	Common/Box.h
	Common/Color.h
	Common/Plane.h
	Common/Point.h
	Common/PointCloud.h
	Common/Types.h
	Common/Utils.h
	Common/Vector.h
	)

set (FEATURES_SRCS
	Features/Feature.cpp
	Features/NormalEstimator.cpp
	)

set (FEATURES_INCS
	Features/Feature.h
	Features/NormalEstimator.h
	)

set (FILTERS_SRCS
	Filters/CropBoxFilter.cpp
	Filters/Filter.cpp
	Filters/HoughFilter.cpp
	Filters/ScaleFilter.cpp
	Filters/TranslateFilter.cpp
	)

set (FILTERS_INCS
	Filters/CropBoxFilter.h
	Filters/Filter.h
	Filters/HoughFilter.h
	Filters/ScaleFilter.h
	Filters/TranslateFilter.h
	)

set (IO_SRCS
	IO/FileReader.cpp
	IO/FileWriter.cpp
	IO/OBJReader.cpp
	IO/OBJWriter.cpp
	IO/PCDReader.cpp
	IO/PCDWriter.cpp
	IO/XYZReader.cpp
	IO/XYZWriter.cpp
	)

set (IO_INCS
	IO/FileReader.h
	IO/FileWriter.h
	IO/OBJReader.h
	IO/OBJWriter.h
	IO/PCDReader.h
	IO/PCDWriter.h
	IO/XYZReader.h
	IO/XYZWriter.h
	)

set (KDTREE_SRCS
	Kdtree/Kdtree.cpp
	Kdtree/KdtreeNode.cpp
	)

set (KDTREE_INCS
	Kdtree/Kdtree.h
	Kdtree/KdtreeNode.h
	)

set (OCTREE_SRCS
	Octree/Octree.cpp
	Octree/OctreeBranch.cpp
	Octree/OctreeIterator.cpp
	Octree/OctreeKey.cpp
	Octree/OctreeLeaf.cpp
	Octree/OctreeNode.cpp
	)

set (OCTREE_INCS
	Octree/Octree.h
	Octree/OctreeBranch.h
	Octree/OctreeIterator.h
	Octree/OctreeKey.h
	Octree/OctreeLeaf.h
	Octree/OctreeNode.h
	)

set (SEARCH_SRCS
	Search/FlannSearch.cpp
	Search/LinearSearch.cpp
	Search/Search.cpp
	)

set (SEARCH_INCS
	Search/FlannSearch.h
	Search/LinearSearch.h
	Search/Search.h
	)

set (SLICERS_SRCS
	Slicers/Slicer.cpp
	Slicers/XYSlicer.cpp
	)

set (SLICERS_INCS
	Slicers/Slicer.h
	Slicers/XYSlicer.h
	)

set (SRCS
	${2D_SRCS}
	${COMMON_SRCS}
	${FEATURES_SRCS}
	${FILTERS_SRCS}
	${IO_SRCS}
	${KDTREE_SRCS}
	${OCTREE_SRCS}
	${SEARCH_SRCS}
	${SLICERS_SRCS}
	)

set (INCS
	${2D_INCS}
	${COMMON_INCS}
	${FEATURES_INCS}
	${FILTERS_INCS}
	${IO_INCS}
	${KDTREE_INCS}
	${OCTREE_INCS}
	${SEARCH_INCS}
	${SLICERS_INCS}
	)

include (../cmake/FindFlann.cmake)
include (../cmake/FindFftw3.cmake)

#find_package (flann)
#include_directories (${FLANN_INCLUDE_DIRS})

add_library (cloud SHARED ${libcloud_sources} ${SRCS} ${INCS})

#target_link_libraries (cloud ${FLANN_LIBRARIES} ${FFTW3_LIBRARIES})
target_link_libraries (cloud ${FFTW3_LIBRARIES})

install (DIRECTORY . DESTINATION include/libcloud FILES_MATCHING PATTERN "*.h")
install (TARGETS cloud DESTINATION lib)