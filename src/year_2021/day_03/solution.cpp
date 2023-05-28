#include <advent_of_code_2021_day_03/solution.h>
#include <algorithm>
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

    auto val = std::pow(2, i);
    if (numbers[i] > 0) {
      gamma += std::pow(2, i);
    } else {
      epsilon += std::pow(2, i);
    }
  }

  return gamma * epsilon;
}

int bin_string_to_int(std::string s) {
  int total = 0;
  for (std::size_t i = 0; i < s.length(); ++i) {
    if (s[i] == '1') {
      total += std::pow(2, s.length() - 1 - i);
    }
  }
  return total;
}

int solution_2(std::string contents) {
  std::stringstream ss(contents);
  std::string line;
  auto oxygen = std::vector<std::string>();
  while (std::getline(ss, line, '\n')) {
    oxygen.push_back(line);
  }

  auto lineLength = oxygen[0].length();
  auto carbon = std::vector<std::string>(oxygen);

  for (int i = 0; i < lineLength; ++i) {
    if (oxygen.size() == 1) {
      break;
    }
    int total = 0;
    for (auto cur : oxygen) {
      if (cur[i] == '1') {
        total++;
      } else {
        total--;
      }
    }
    auto charToRemove = total < 0 ? '1' : '0';
    auto remove = [i, charToRemove](std::string s) {
      return s[i] == charToRemove;
    };
    oxygen.erase(std::remove_if(oxygen.begin(), oxygen.end(), remove),
                 oxygen.end());
  }

  auto oxygenVal = bin_string_to_int(oxygen[0]);

  for (int i = 0; i < lineLength; ++i) {
    if (carbon.size() == 1) {
      break;
    }
    int total = 0;
    for (auto cur : carbon) {
      if (cur[i] == '1') {
        total++;
      } else {
        total--;
      }
    }
    auto charToRemove = total < 0 ? '0' : '1';
    auto remove = [i, charToRemove](std::string s) {
      return s[i] == charToRemove;
    };
    carbon.erase(std::remove_if(carbon.begin(), carbon.end(), remove),
                 carbon.end());
  }
  auto carbonVal = bin_string_to_int(carbon[0]);

  return oxygenVal * carbonVal;
}
