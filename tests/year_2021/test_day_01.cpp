#include "../common/utils.h"
#include <advent_of_code_2021_day_01/solution.h>
#include <gtest/gtest.h>

TEST(Test_2021_Day_01, Example) {
  auto str = get_file_contents("example.txt");
  const auto expected = 7;
  const auto actual = solution(str);
  ASSERT_EQ(expected, actual);
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
