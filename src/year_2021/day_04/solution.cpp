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
using std::tuple;
using std::vector;

tuple<vector<int>, vector<vector<int>>> parse(string contents) {
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

bool bingo(const std::vector<int> &card, int idx) {
  int row = idx / 5;
  int col = idx % 5;
  for (int i = 0; i < 5; ++i) {
    if (card[row * 5 + i] != -1) {
      break;
    }
    if (i == 4) {
      return true;
    }
  }
  for (int i = 0; i < 5; ++i) {
    if (card[i * 5 + col] != -1) {
      break;
    }
    if (i == 4) {
      return true;
    }
  }
  return false;
}

int solution_1(std::string contents) {
  auto [numbers, bingoCards] = parse(contents);
  int round = 0;
  for (auto curNum : numbers) {
    round++;
    for (auto &curCard : bingoCards) {
      for (int i = 0; i < curCard.size(); ++i) {
        if (curCard[i] == curNum) {
          curCard[i] = -1;
          if (bingo(curCard, i)) {
            int cardSum = 0;
            for (auto cardNum : curCard) {
              if (cardNum != -1) {
                cardSum += cardNum;
              }
            }
            return cardSum * curNum;
          }
          break;
        }
      }
    }
  }
  return 0;
}

int solution_2(std::string contents) {
  auto [numbers, bingoCards] = parse(contents);
  int round = 0;
  for (auto curNum : numbers) {
    round++;
    for (auto &curCard : bingoCards) {
      for (int i = 0; i < curCard.size(); ++i) {
        if (curCard[i] == curNum) {
          curCard[i] = -1;
          if (bingo(curCard, i)) {
            int cardSum = 0;
            for (auto cardNum : curCard) {
              if (cardNum != -1) {
                cardSum += cardNum;
              }
            }
            return cardSum * curNum;
          }
          break;
        }
      }
    }
  }
  return 0;
}
