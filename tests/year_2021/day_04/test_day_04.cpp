#include "../../common/utils.h"
#include <advent_of_code_2021_day_04/solution.h>
#include <gtest/gtest.h>

TEST(Test_2021_Day_04, Example_1) {
  auto str = get_file_contents("example.txt");
  const auto expected = 4512;
  const auto actual = solution_1(str);
  ASSERT_EQ(expected, actual);
}

TEST(Test_2021_Day_04, REAL_1) {
  auto str = get_file_contents("real.txt");
  const auto expected = 45031;
  const auto actual = solution_1(str);
  ASSERT_EQ(expected, actual);
}

TEST(Test_2021_Day_04, Example_2) {
  auto str = get_file_contents("example.txt");
  const auto expected = 1924;
  const auto actual = solution_2(str);
  ASSERT_EQ(expected, actual);
}

TEST(Test_2021_Day_04, REAL_2) {
  auto str = get_file_contents("real.txt");
  const auto expected = 2568;
  const auto actual = solution_2(str);
  ASSERT_EQ(expected, actual);
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
