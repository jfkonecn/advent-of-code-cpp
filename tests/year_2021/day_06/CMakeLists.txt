add_executable(test_advent_of_code_2021_day_06 test_day_06.cpp ../../common/utils.cpp)

target_link_libraries(test_advent_of_code_2021_day_06
 PRIVATE
  GTest::GTest
  advent_of_code_2021_day_06)

add_test(test_2021_day_06 test_advent_of_code_2021_day_06)

configure_file(example.txt ${CMAKE_CURRENT_BINARY_DIR}/example.txt COPYONLY)
configure_file(real.txt ${CMAKE_CURRENT_BINARY_DIR}/real.txt COPYONLY)

