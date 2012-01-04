find_package (GTest REQUIRED)

include_directories(${GTEST_INCLUDE_DIRS})

add_executable(GaussianEstimatorTest GaussianEstimator_test.cpp)
add_executable(MatrixTest Matrix_test.cpp)
add_executable(LineTest Line_test.cpp)

target_link_libraries(GaussianEstimatorTest ${GTEST_BOTH_LIBRARIES} cloud)
target_link_libraries(MatrixTest ${GTEST_BOTH_LIBRARIES} cloud)
target_link_libraries(LineTest ${GTEST_BOTH_LIBRARIES} cloud)

add_test(GaussianEstimator GaussianEstimatorTest)
add_test(Matrix MatrixTest)
add_test(Line LineTest)