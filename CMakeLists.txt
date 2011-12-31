project (cloud9)

cmake_minimum_required(VERSION 2.8)

include_directories (.)

add_subdirectory (libcloud)
add_subdirectory (libcloudui)
add_subdirectory (src)
add_subdirectory (test)

include (CPack)
