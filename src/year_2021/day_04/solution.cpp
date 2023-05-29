#include <advent_of_code_2021_day_04/solution.h>
#include <algorithm>
#include <array>
#include <cmath>
#include <iostream>
#include <limits.h>
#include <sstream>
#include <string>
#include <tuple>
#include <vector>

using std::string;
using std::vector;

std::tuple<vector<int>, vector<vector<int>>> parse(string contents) {
  std::stringstream ss(contents);
  std::string line;
  std::getline(ss, line, '\n');
  std::vector<int> numbers;
  std::stringstream numbersStream(line);
  while (std::getline(numbersStream, line, ',')) {
    numbers.push_back(std::stoi(line));
  }

  std::vector<std::vector<int>> bingoCards;

  std::vector<int> currentBingoCard;

  std::getline(ss, line, '\n');
  while (std::getline(ss, line, '\n')) {
    if (line.length() == 0) {
      bingoCards.push_back(std::vector<int>(currentBingoCard));
      currentBingoCard.clear();
    } else {
      std::stringstream numbersStream(line);
      std::string numStr;
      while (std::getline(numbersStream, numStr, ' ')) {
        if (numStr != " " && numStr != "") {
          currentBingoCard.push_back(std::stoi(numStr));
        }
      }
    }
  }
  bingoCards.push_back(std::vector<int>(currentBingoCard));
  return std::make_tuple(numbers, bingoCards);
}

int solution_1(std::string contents) {
  auto [numbers, bingoCards] = parse(contents);
  return 0;
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
