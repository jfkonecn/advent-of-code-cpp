#include "utils.h"
#include <fstream>
#include <sstream>
#include <string>

using std::ifstream;

std::string get_file_contents(const char *filename) {
  std::ifstream inFile;
  inFile.open(filename);

  std::stringstream strStream;
  strStream << inFile.rdbuf();
  inFile.close();
  std::string str = strStream.str();

  return str;
}
