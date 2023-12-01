#ifndef ROTOR_H
#define ROTOR_H

class Rotor
{

private:
    int rotorNumber;
    int currentPosition;
    int rotorConfig[26];
    int reverseRotorConfig[26];
    int notchPosition;

public:
    Rotor(int rotorNumber, int rotorConfig[26], int notchPosition);
    int getRotorNumber();
    int getCurrentPosition();
    bool isNotchPosition();
    void setCurrentPosition(int position);
    void rotateRotor();
    int getForwardMapping(int input);
    int getReverseMapping(int input);
    void printRotor();
};

#endif