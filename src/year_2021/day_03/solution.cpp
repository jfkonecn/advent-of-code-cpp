#include <advent_of_code_2021_day_03/solution.h>
#include <cmath>
#include <limits.h>
#include <sstream>
#include <string>
#include <vector>

int solution_1(std::string contents) {
  std::stringstream ss(contents);
  std::string line;
  int vertical = 0;
  int horizontal = 0;
  while (std::getline(ss, line, '\n')) {
    std::stringstream lineStream(line);
    std::string direction;
    std::string amountStr;
    std::getline(lineStream, direction, ' ');
    std::getline(lineStream, amountStr, ' ');
    auto amount = std::stoi(amountStr);
    if (direction == "up") {
      vertical += amount;
    } else if (direction == "down") {
      vertical -= amount;
    } else {
      horizontal += amount;
    }
  }
  return -1 * vertical * horizontal;
}

int solution_2(std::string contents) {
  std::stringstream ss(contents);
  std::string line;
  int vertical = 0;
  int horizontal = 0;
  int aim = 0;
  while (std::getline(ss, line, '\n')) {
    std::stringstream lineStream(line);
    std::string direction;
    std::string amountStr;
    std::getline(lineStream, direction, ' ');
    std::getline(lineStream, amountStr, ' ');
    auto amount = std::stoi(amountStr);
    if (direction == "up") {
      aim -= amount;
    } else if (direction == "down") {
      aim += amount;
    } else {
      horizontal += amount;
      vertical -= std::abs(aim * amount);
    }
  }
  return -1 * vertical * horizontal;
}
