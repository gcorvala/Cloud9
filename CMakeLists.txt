project (cloud9)

cmake_minimum_required (VERSION 2.8)

#set (CMAKE_CXX_FLAGS "-Wall -Wextra")
# FIXME : pthread for linux (ubuntu)
set (CMAKE_CXX_FLAGS "-pthread")

include_directories (.)

enable_testing ()

add_subdirectory (3rdparty)
#add_subdirectory (docs)
add_subdirectory (libcloud)
add_subdirectory (libcloud2)
add_subdirectory (libcloudui)
add_subdirectory (libsvg)
add_subdirectory (libxml)
add_subdirectory (src)
add_subdirectory (test)

include (CPack)
