#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <vector>
#include <unordered_set>
#include "controller.h"
#include "rotor.h"
#include "reflector.h"
#include "panel.h"
#include "parser.h"

using namespace std;

int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        cout << "Usage: ./bin/enigma <config_path> <rotor_path>" << endl;
        return 1;
    }
    map<string, string> generalConfig = parseConfig(argv[1]);
    map<string, string> specificConfig = parseConfig(argv[2]);
    vector<pair<int, int>> reflectorConfig = parseReflector(generalConfig["REFLECTOR"]);
    
    Reflector *reflecor = new Reflector(reflectorConfig);
    return 0;
}