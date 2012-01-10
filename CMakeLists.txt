project (cloud9)

cmake_minimum_required (VERSION 2.8)

#set (CMAKE_CXX_FLAGS "-Wall -Wextra")

include_directories (.)

enable_testing ()

add_subdirectory (libcloud)
add_subdirectory (libcloudui)
add_subdirectory (src)
add_subdirectory (test)

include (CPack)
