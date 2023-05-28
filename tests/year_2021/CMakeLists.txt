
add_executable(test_advent_of_code_2021_day_01 test_day_01.cpp)

target_link_libraries(test_advent_of_code_2021_day_01
 PRIVATE
  GTest::GTest
  advent_of_code_2021_day_01)

add_test(test_2021_day_01 test_advent_of_code_2021_day_01)

