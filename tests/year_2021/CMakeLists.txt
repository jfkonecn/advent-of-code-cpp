
add_executable(advent_of_code_2021_day_01_tests day_01_tests.cpp)

target_link_libraries(advent_of_code_2021_day_01_tests
 PRIVATE
  GTest::GTest
  advent_of_code_2021_day_01)

add_test(multiply_gtest advent_of_code_2021_day_01_tests)

