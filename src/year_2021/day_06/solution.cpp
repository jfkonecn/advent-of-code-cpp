#include "../../common/BigInt.hpp"
#include <advent_of_code_2021_day_06/solution.h>
#include <algorithm>
#include <array>
#include <cmath>
#include <iostream>
#include <limits.h>
#include <numeric>
#include <sstream>
#include <string>
#include <tuple>
#include <vector>

using std::string;
using std::vector;

vector<int> parse(string contents) {
  std::stringstream ss(contents);
  std::string fishStr;

  std::vector<int> fish;

  while (std::getline(ss, fishStr, ',')) {
    fish.push_back(std::stoi(fishStr));
  }
  return fish;
}

string simulate(vector<int> *fish, int totalRounds) {
  auto fishRound = new BigInt[9];

  for (int i = 0; i < 9; i++) {
    fishRound[i] = 0;
  }

  for (auto life : *fish) {
    fishRound[life]++;
  }

  for (int i = 0; i < totalRounds; i++) {
    auto resetFish = fishRound[0];
    for (int j = 1; j < 9; j++) {
      fishRound[j - 1] = fishRound[j];
    }
    fishRound[8] = resetFish;
    fishRound[6] += resetFish;
  }

  BigInt total = 0;
  for (int i = 0; i < 9; i++) {
    total += fishRound[i];
  }

  return total.to_string();
}

string solution_1(std::string contents) {
  auto fish = parse(contents);
  int totalRounds = 80;
  // int totalRounds = 8;
  return simulate(&fish, totalRounds);
}

string solution_2(std::string contents) {
  auto fish = parse(contents);
  int totalRounds = 256;
  return simulate(&fish, totalRounds);
}
