#include "panel.h"
#include "reflector.h"
#include "rotor.h"
#include "controller.h"

using namespace std;

Controller::Controller(Rotor *rotor1, Rotor *rotor2, Rotor *rotor3,
                       Reflector *reflector, FrontPanel *frontPanel)
{
    this->rotor1 = rotor1;
    this->rotor2 = rotor2;
    this->rotor3 = rotor3;
    this->reflector = reflector;
    this->frontPanel = frontPanel;
}