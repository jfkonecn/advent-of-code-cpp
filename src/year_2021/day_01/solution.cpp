#include <advent_of_code_2021_day_01/solution.h>
#include <limits.h>
#include <sstream>
#include <string>
#include <vector>

int solution_1(std::string contents) {
  std::stringstream ss(contents);
  std::string line;
  int count = 0;
  auto last = INT_MAX;
  while (std::getline(ss, line, '\n')) {
    auto current = std::stoi(line);
    if (current > last) {
      count++;
    }
    last = current;
  }
  return count;
}

int solution_2(std::string contents) {
  std::stringstream ss(contents);
  std::string line;

  std::getline(ss, line, '\n');
  auto first = std::stoi(line);

  std::getline(ss, line, '\n');
  auto second = std::stoi(line);

  std::getline(ss, line, '\n');
  auto third = std::stoi(line);

  int count = 0;
  auto last = first + second + third;

  while (std::getline(ss, line, '\n')) {
    auto current = std::stoi(line);
    auto currentSum = std::stoi(line) + second + third;
    if (currentSum > last) {
      count++;
    }
    last = currentSum;
    first = second;
    second = third;
    third = current;
  }
  return count;
}
