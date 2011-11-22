add_executable (test test.cpp)

find_library (FLANN_LIBRARY flann_cpp)
find_path (FLANN_INCLUDE_DIR flann)
set (FLANN_LIBRARIES ${FLANN_LIBRARY})
set (FLANN_INCLUDE_DIRS ${FLANN_INCLUDE_DIR})
include (FindPackageHandleStandardArgs)
find_package_handle_standard_args (Flann DEFAULT_MSG FLANN_LIBRARY FLANN_INCLUDE_DIR)
mark_as_advanced (FLANN_INCLUDE_DIR FLANN_LIBRARY)
include_directories (${FLANN_INCLUDE_DIRS})


target_link_libraries (test cloud)
target_link_libraries (test ${FLANN_LIBRARIES})