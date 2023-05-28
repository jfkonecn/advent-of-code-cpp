#include <advent_of_code_2021_day_01/solution.h>
#include <gtest/gtest.h>

TEST(MultiplyTests, TestIntegerOne_One)
{
    const auto expected = 1;
    const auto actual = multiply(1, 1);
    ASSERT_EQ(expected, actual);
}
