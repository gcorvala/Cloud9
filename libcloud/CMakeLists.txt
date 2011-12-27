aux_source_directory (Common libcloud_sources)
aux_source_directory (Features libcloud_sources)
aux_source_directory (Filters libcloud_sources)
aux_source_directory (IO libcloud_sources)
aux_source_directory (Kdtree libcloud_sources)
aux_source_directory (Octree libcloud_sources)
aux_source_directory (Search libcloud_sources)
aux_source_directory (2D libcloud_sources)

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

add_library (cloud SHARED ${libcloud_sources})

target_link_libraries (cloud ${FLANN_LIBRARIES})

install (DIRECTORY . DESTINATION include/libcloud FILES_MATCHING PATTERN "*.h")
install (TARGETS cloud LIBRARY DESTINATION lib)