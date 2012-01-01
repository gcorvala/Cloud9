find_package (GTest REQUIRED)

include_directories(${GTEST_INCLUDE_DIRS})

add_executable(MatrixTest Matrix_test.cpp)

target_link_libraries(MatrixTest ${GTEST_BOTH_LIBRARIES} cloud)

add_test(Matrix MatrixTest)