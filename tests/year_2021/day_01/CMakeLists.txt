
add_executable(test_advent_of_code_2021_day_01 test_day_01.cpp ../../common/utils.cpp)

target_link_libraries(test_advent_of_code_2021_day_01
 PRIVATE
  GTest::GTest
  advent_of_code_2021_day_01)

add_test(test_2021_day_01 test_advent_of_code_2021_day_01)

configure_file(example.txt ${CMAKE_CURRENT_BINARY_DIR}/example.txt COPYONLY)
configure_file(real.txt ${CMAKE_CURRENT_BINARY_DIR}/real.txt COPYONLY)

