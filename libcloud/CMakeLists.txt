aux_source_directory (Common libcloud_sources)
aux_source_directory (Features libcloud_sources)
aux_source_directory (Filters libcloud_sources)
aux_source_directory (IO libcloud_sources)
aux_source_directory (Kdtree libcloud_sources)
aux_source_directory (Octree libcloud_sources)
aux_source_directory (Search libcloud_sources)

add_library (cloud SHARED ${libcloud_sources})

install (DIRECTORY . DESTINATION include/libcloud FILES_MATCHING PATTERN "*.h")
install (TARGETS cloud LIBRARY DESTINATION lib)