#include <utility>

using namespace std;

#ifndef FRONT_PANEL_H
#define FRONT_PANEL_H

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