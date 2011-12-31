set(2D_SRCS 
	2D/CannyEstimator.cpp
	2D/HoughEstimator.cpp
	2D/Image.cpp
	2D/Line.cpp
	2D/SobelEstimator.cpp
	2D/ThresholdEstimator.cpp
	)

set(2D_INCS
	2D/CannyEstimator.h
	2D/Estimator.h
	2D/HoughEstimator.h
	2D/Image.h
	2D/Line.h
	2D/Matrix.h
	2D/SobelEstimator.h
	2D/ThresholdEstimator.h
	)

set(COMMON_SRCS
	Common/Color.cpp
	Common/Point.cpp
	Common/PointCloud.cpp
	Common/Utils.cpp
	)

set(COMMON_INCS
	Common/Color.h
	Common/Point.h
	Common/PointCloud.h
	Common/Types.h
	Common/Utils.h
	)

set(FEATURES_SRCS
	Features/Feature.cpp
	Features/NormalEstimator.cpp
	)

set(FEATURES_INCS
	Features/Feature.h
	Features/NormalEstimator.h
	)

set(FILTERS_SRCS
	Filters/Filter.cpp
	Filters/ScaleFilter.cpp
	Filters/TranslateFilter.cpp
	)

set(FILTERS_INCS
	Filters/Filter.h
	Filters/ScaleFilter.h
	Filters/TranslateFilter.h
	)

set(IO_SRCS
	IO/FileReader.cpp
	IO/FileWriter.cpp
	IO/OBJReader.cpp
	IO/OBJWriter.cpp
	IO/PCDReader.cpp
	IO/PCDWriter.cpp
	IO/XYZReader.cpp
	IO/XYZWriter.cpp
	)

set(IO_INCS
	IO/FileReader.h
	IO/FileWriter.h
	IO/OBJReader.h
	IO/OBJWriter.h
	IO/PCDReader.h
	IO/PCDWriter.h
	IO/XYZReader.h
	IO/XYZWriter.h
	)

set(KDTREE_SRCS
	Kdtree/Kdtree.cpp
	Kdtree/KdtreeNode.cpp
	)

set(KDTREE_INCS
	Kdtree/Kdtree.h
	Kdtree/KdtreeNode.h
	)

set(OCTREE_SRCS
	Octree/Octree.cpp
	Octree/OctreeBranch.cpp
	Octree/OctreeIterator.cpp
	Octree/OctreeKey.cpp
	Octree/OctreeLeaf.cpp
	Octree/OctreeNode.cpp
	)

set(OCTREE_INCS
	Octree/Octree.h
	Octree/OctreeBranch.h
	Octree/OctreeIterator.h
	Octree/OctreeKey.h
	Octree/OctreeLeaf.h
	Octree/OctreeNode.h
	)

set(SEARCH_SRCS
	Search/FlannSearch.cpp
	Search/LinearSearch.cpp
	Search/Search.cpp
	)

set(SEARCH_INCS
	Search/FlannSearch.h
	Search/LinearSearch.h
	Search/Search.h
	)

set(SRCS ${2D_SRCS} ${COMMON_SRCS} ${FEATURES_SRCS} ${FILTERS_SRCS} ${IO_SRCS} ${KDTREE_SRCS} ${OCTREE_SRCS} ${SEARCH_SRCS})
set(INCS ${2D_INCS} ${COMMON_INCS} ${FEATURES_INCS} ${FILTERS_INCS} ${IO_INCS} ${KDTREE_INCS} ${OCTREE_INCS} ${SEARCH_INCS})

# FIXME : add new cmake module
find_library (FLANN_LIBRARY flann_cpp)
find_path (FLANN_INCLUDE_DIR flann)
set (FLANN_LIBRARIES ${FLANN_LIBRARY})
set (FLANN_INCLUDE_DIRS ${FLANN_INCLUDE_DIR})
include (FindPackageHandleStandardArgs)
find_package_handle_standard_args (Flann DEFAULT_MSG FLANN_LIBRARY FLANN_INCLUDE_DIR)
mark_as_advanced (FLANN_INCLUDE_DIR FLANN_LIBRARY)

#find_package (flann)
include_directories (${FLANN_INCLUDE_DIRS})

add_library (cloud SHARED ${libcloud_sources} ${SRCS} ${INCS})

target_link_libraries (cloud ${FLANN_LIBRARIES})

install (DIRECTORY . DESTINATION include/libcloud FILES_MATCHING PATTERN "*.h")
install (TARGETS cloud LIBRARY DESTINATION lib)