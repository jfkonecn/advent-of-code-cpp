#include <advent_of_code_2021_day_01/solution.h>
#include <limits.h>
#include <sstream>
#include <string>
#include <vector>

int solution(std::string contents) {
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
