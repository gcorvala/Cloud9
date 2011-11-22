#ifndef __UTILS_H__
#define __UTILS_H__

#include <string>
#include <vector>
#include "Point.h"

void StringSplit(std::string str, std::string delim, std::vector<std::string> &results);
bool comparePointsByXAxis (Point x, Point y);
bool comparePointsByYAxis (Point x, Point y);
bool comparePointsByZAxis (Point x, Point y);

#endif