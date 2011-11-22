#include "Utils.h"

void
StringSplit(std::string str, std::string delim, std::vector<std::string> &results) {
  size_t cutAt;
  while( (cutAt = str.find_first_of(delim)) != str.npos ) {
    if(cutAt > 0) {
      results.push_back(str.substr(0,cutAt));
    }
    str = str.substr(cutAt+1);
  }
  if(str.length() > 0) {
    results.push_back(str);
  }
}

bool comparePointsByXAxis (Point x, Point y) {
  return (x.x < y.x);
}

bool comparePointsByYAxis (Point x, Point y) {
  return (x.y < y.y);
}

bool comparePointsByZAxis (Point x, Point y) {
  return (x.z < y.z);
}