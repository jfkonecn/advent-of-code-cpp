#include <advent_of_code_2021_day_05/solution.h>
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

// line struct
struct Point {
  int x;
  int y;
};
struct Line {
  Point start;
  Point end;
};

Point parse_as_point(string str) {
  std::stringstream ss(str);
  std::string line;

  std::getline(ss, line, ',');
  int x = std::stoi(line);
  std::getline(ss, line, ',');
  int y = std::stoi(line);

  return Point{x, y};
}

vector<std::string> splitString(const string &input, const string &delimiter) {
  std::vector<std::string> parts;
  std::size_t start = 0;
  std::size_t end = input.find(delimiter);

  while (end != std::string::npos) {
    parts.push_back(input.substr(start, end - start));
    start = end + delimiter.length();
    end = input.find(delimiter, start);
  }

  parts.push_back(input.substr(start));

  return parts;
}

vector<Line> parse(string contents) {
  std::stringstream ss(contents);
  std::string line;

  std::vector<Line> lines;

  while (std::getline(ss, line, '\n')) {
    auto pointStrs = splitString(line, " -> ");
    auto start = parse_as_point(pointStrs[0]);
    auto end = parse_as_point(pointStrs[1]);
    lines.push_back(Line{start, end});
  }
  return lines;
}

int get_result(const std::vector<Line> &points) {
  auto maxX =
      std::max_element(points.begin(), points.end(),
                       [](Line a, Line b) { return a.start.x < b.start.x; })
          ->start.x +
      1;
  auto maxY =
      std::max_element(points.begin(), points.end(),
                       [](Line a, Line b) { return a.start.y < b.start.y; })
          ->start.y +
      1;

  int arr[maxX][maxY];
  for (int i = 0; i < maxX; i++) {
    for (int j = 0; j < maxY; j++) {
      arr[i][j] = 0;
    }
  }

  for (auto point : points) {
    int startX = std::min(point.start.x, point.end.x);
    int endX = std::max(point.start.x, point.end.x) + 1;
    int startY = std::min(point.start.y, point.end.y);
    int endY = std::max(point.start.y, point.end.y) + 1;
    int i = startX;
    int j = startY;
    bool shouldContinue = true;
    bool isDiagonalUp = (startX == point.start.x && startY != point.start.y) ||
                        (startX == point.end.x && startY != point.end.y);
    if (isDiagonalUp) {
      j = endY - 1;
    }
    while (shouldContinue) {
      shouldContinue = false;
      arr[i][j]++;
      if (i < endX - 1) {
        shouldContinue = true;
        i++;
      }
      if (j < endY - 1 && !isDiagonalUp) {
        shouldContinue = true;
        j++;
      } else if (j > startY && isDiagonalUp) {
        shouldContinue = true;
        j--;
      }
    }
  }
  int result = 0;
  for (int i = 0; i < maxX; i++) {
    for (int j = 0; j < maxY; j++) {
      if (arr[i][j] > 1) {
        result++;
      }
    }
  }
  return result;
}

int solution_1(std::string contents) {
  auto points = parse(contents);
  auto remove = [](Line line) {
    return !(line.start.x == line.end.x || line.start.y == line.end.y);
  };
  points.erase(std::remove_if(points.begin(), points.end(), remove),
               points.end());
  return get_result(points);
}

int solution_2(std::string contents) {
  auto points = parse(contents);
  return get_result(points);
}
