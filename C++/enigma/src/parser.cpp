#include <vector>
#include <string>
#include <map>
#include <fstream>
#include <unordered_set>
#include <stdexcept>
#include "parser.h"
using namespace std;

vector<string> split(string s, string delimiter)
{
    size_t pos_start = 0, pos_end, delim_len = delimiter.length();
    string token;
    vector<string> res;
    while ((pos_end = s.find(delimiter, pos_start)) != string::npos)
    {
        token = s.substr(pos_start, pos_end - pos_start);
        pos_start = pos_end + delim_len;
        res.push_back(token);
    }
    res.push_back(s.substr(pos_start));
    return res;
}

map<string, string> parseConfig(string file_path)
{
    map<string, string> config;
    ifstream inputFile(file_path);
    bool fail = false;
    if (!inputFile.is_open())
    {
        throw invalid_argument("Could not open file: " + file_path);
    }
    try
    {
        string line;
        while (getline(inputFile, line))
        {
            vector<string> tokens = split(line, "=");
            config[tokens[0]] = tokens[1];
        }
    }
    catch (const exception &e)
    {
        fail = true;
    }
    inputFile.close();
    if (fail)
    {
        throw invalid_argument("Invalid config file: " + file_path);
    }
    return config;
}

vector<pair<int, int>> parseReflector(string reflectorConf)
{
    unordered_set<char> used;
    vector<pair<int, int>> reflectorConfig;
    for (int i = 0; i < 26; i++)
    {
        int first = i, second = reflectorConf[i] - 'A';
        if (first < 0 || first > 25 || second < 0 || second > 25 || first == second)
        {
            throw invalid_argument("Invalid reflector configuration: " + reflectorConf);
        }
        if (used.find(first) == used.end() && used.find(second) == used.end())
        {
            reflectorConfig.push_back(make_pair(first, second));
            used.insert(first);
            used.insert(second);
        }
        else if (used.find(first) != used.end() && used.find(second) != used.end())
        {
            continue;
        }
        else
        {
            throw invalid_argument("Invalid reflector configuration: " + reflectorConf);
        }
    }
    if (reflectorConfig.size() != 13)
    {
        throw invalid_argument("Invalid reflector configuration: " + reflectorConf);
    }
    return reflectorConfig;
}

vector<pair<int, int>> parsePanel(string panelConf)
{
    vector<string> tokens = split(panelConf, " ");
    vector<pair<int, int>> panelConfig;
    if (tokens.size() != 10)
    {
        throw invalid_argument("Invalid panel configuration: " + panelConf);
    }
    unordered_set<char> used;
    for (int i = 0; i < 10; i++)
    {
        int first = tokens[i][0] - 'A', second = tokens[i][1] - 'A';
        if (first < 0 || first > 25 || second < 0 || second > 25 || first == second)
        {
            throw invalid_argument("Invalid panel configuration: " + panelConf);
        }
        if (used.find(first) == used.end() && used.find(second) == used.end())
        {
            panelConfig.push_back(make_pair(first, second));
            used.insert(first);
            used.insert(second);
        }
        else if (used.find(first) != used.end() && used.find(second) != used.end())
        {
            continue;
        }
        else
        {
            throw invalid_argument("Invalid panel configuration: " + panelConf);
        }
    }
    return panelConfig;
}