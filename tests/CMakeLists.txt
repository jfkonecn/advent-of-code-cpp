include(FetchContent)

FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG        release-1.11.0
)
FetchContent_MakeAvailable(googletest)
add_library(GTest::GTest INTERFACE IMPORTED)
target_link_libraries(GTest::GTest INTERFACE gtest_main)

add_executable(advent_of_code_tests tests_main.cpp)

target_link_libraries(advent_of_code_tests
 PRIVATE
  GTest::GTest
  advent_of_code_2021_day_01)

add_subdirectory(year_2021)
