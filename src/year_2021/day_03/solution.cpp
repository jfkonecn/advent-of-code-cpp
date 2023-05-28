#include <advent_of_code_2021_day_03/solution.h>
#include <array>
#include <cmath>
#include <iostream>
#include <limits.h>
#include <sstream>
#include <string>
#include <vector>

int solution_1(std::string contents) {
  std::stringstream ss(contents);
  std::string line;
  std::getline(ss, line, '\n');
  auto lineLength = line.length();
  int *numbers = new int[lineLength];
  std::fill(numbers, numbers + lineLength, 0);
  int totalNumbers = 0;
  do {
    totalNumbers++;
    for (std::size_t i = 0; i < lineLength; ++i) {
      char c = line[i];
      if (c == '1') {
        numbers[lineLength - 1 - i]++;
      } else {
        numbers[lineLength - 1 - i]--;
      }
    }
  } while (std::getline(ss, line, '\n'));

  int gamma = 0;
  int epsilon = 0;

  for (std::size_t i = 0; i < lineLength; ++i) {

    // std::cout << "numbers[" << i << "]: " << numbers[i] << std::endl;
    auto val = std::pow(2, i);
    if (numbers[i] > 0) {
      gamma += std::pow(2, i);
    } else {
      epsilon += std::pow(2, i);
    }
  }
  // print gamma and epsilon
  // std::cout << "gamma: " << gamma << std::endl;
  // std::cout << "epsilon: " << epsilon << std::endl;

  return gamma * epsilon;
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
