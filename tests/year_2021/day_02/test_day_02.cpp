#include "../../common/utils.h"
#include <advent_of_code_2021_day_02/solution.h>
#include <gtest/gtest.h>

TEST(Test_2021_Day_02, Example_1) {
  auto str = get_file_contents("example.txt");
  const auto expected = 150;
  const auto actual = solution_1(str);
  ASSERT_EQ(expected, actual);
}

TEST(Test_2021_Day_02, REAL_1) {
  auto str = get_file_contents("real.txt");
  const auto expected = 1962940;
  const auto actual = solution_1(str);
  ASSERT_EQ(expected, actual);
}

TEST(Test_2021_Day_02, Example_2) {
  auto str = get_file_contents("example.txt");
  const auto expected = 900;
  const auto actual = solution_2(str);
  ASSERT_EQ(expected, actual);
}

TEST(Test_2021_Day_02, REAL_2) {
  auto str = get_file_contents("real.txt");
  const auto expected = 1813664422;
  const auto actual = solution_2(str);
  ASSERT_EQ(expected, actual);
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
