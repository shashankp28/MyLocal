#ifndef PARSER_H
#define PARSER_H

#include <vector>
#include <string>
#include <map>
#include <utility>
using namespace std;

vector<string> split(string s, string delimiter);
map<string, string> parseConfig(string file_path);
vector<pair<int, int>> parseReflector(string reflectorConf);

#endif