#include <advent_of_code_2021_day_02/solution.h>
#include <limits.h>
#include <sstream>
#include <string>
#include <vector>

enum class Direction { Up, Down, Forward };

struct Action {
  int amount;
  Direction direction;
};

int solution_1(std::string contents) {
  std::stringstream ss(contents);
  std::string line;
  auto last = INT_MAX;
  int vertical = 0;
  int horizontal = 0;
  while (std::getline(ss, line, '\n')) {
    std::stringstream lineStream(line);
    std::string splitLine;
    std::getline(lineStream, splitLine, ' ');
    auto direction = Direction::Forward;
    if (splitLine == "up") {
      direction = Direction::Up;
    } else if (splitLine == "down") {
      direction = Direction::Down;
    }
    std::getline(lineStream, splitLine, ' ');
    auto amount = std::stoi(splitLine);
    if (direction == Direction::Up) {
      vertical += amount;
    } else if (direction == Direction::Down) {
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
