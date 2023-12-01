#ifndef FRONT_PANEL_H
#define FRONT_PANEL_H
#include <utility>
using namespace std;

class FrontPanel
{

private:
    int frontPanelConfig[26];

public:
    FrontPanel(pair<int, int> frontPanelConfig[10]);
    int getPatch(int index);
    void printFrontPanel();
};

#endif