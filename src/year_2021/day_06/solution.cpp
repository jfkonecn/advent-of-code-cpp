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

BigInt simulate(vector<int> *fish, int totalRounds) {
  auto fishRound = new long long[9];

  for (int i = 0; i < 9; i++) {
    fishRound[i] = 0;
  }

  for (auto life : *fish) {
    fishRound[life]++;
  }
  // std::cout << "         " << 0 << " " << 1 << " " << 2 << " " << 3 << " " <<
  // 4
  //<< " " << 5 << " " << 6 << " " << 7 << " " << 8 << std::endl;

  for (int i = 0; i < totalRounds; i++) {
    auto resetFish = fishRound[0];
    for (int j = 1; j < 9; j++) {
      fishRound[j - 1] = fishRound[j];
    }
    fishRound[8] = resetFish;
    fishRound[6] += resetFish;
    // label arr
    // print round
    // std::cout << "Round " << i + 1 << ": ";
    // for (int j = 0; j < 9; j++) {
    // std::cout << fishRound[j] << " ";
    //}
    // std::cout << std::endl;
    // std::cout << std::accumulate(fishRound, fishRound + 9, 0) << std::endl;
  }

  BigInt total = 0;
  for (int i = 0; i < 9; i++) {
    total += fishRound[i];
  }
  std::cout << total << std::endl;

  return total;
}

BigInt solution_1(std::string contents) {
  auto fish = parse(contents);
  int totalRounds = 80;
  // int totalRounds = 8;
  return simulate(&fish, totalRounds);
}

BigInt solution_2(std::string contents) {
  auto fish = parse(contents);
  int totalRounds = 256;
  return simulate(&fish, totalRounds);
}
