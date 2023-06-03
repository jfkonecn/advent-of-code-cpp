#include <advent_of_code_2021_day_06/solution.h>
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

vector<int> parse(string contents) {
  std::stringstream ss(contents);
  std::string fishStr;

  std::vector<int> fish;

  while (std::getline(ss, fishStr, ',')) {
    fish.push_back(std::stoi(fishStr));
  }
  return fish;
}

int solution_1(std::string contents) {
  auto fish = parse(contents);
  for (int round = 0; round < 80; round++) {
    int fishToAdd = 0;
    for (auto &life : fish) {
      if (life == 0) {
        life = 6;
        fishToAdd++;
      } else {
        life--;
      }
    }
    for (int i = 0; i < fishToAdd; i++) {
      fish.push_back(8);
    }
    //// print all fish
    // for (auto &life : fish) {
    // std::cout << life << ",";
    //}
    // std::cout << std::endl;
  }

  return fish.size();
}

int solution_2(std::string contents) {
  auto fish = parse(contents);
  return fish.max_size();
}
