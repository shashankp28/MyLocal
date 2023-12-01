#include <iostream>
#include <stdexcept>
#include "rotor.h"

using namespace std;

Rotor::Rotor(int rotorNumber, int rotorConfig[26], int notchPosition)
{
    this->rotorNumber = rotorNumber;
    this->currentPosition = 0;
    if (notchPosition < 0 || notchPosition > 25)
    {
        throw invalid_argument("Notch position is invalid");
    }
    this->notchPosition = notchPosition;
    for (int i = 0; i < 26; i++)
    {
        this->rotorConfig[i] = -1;
    }
    for (int i = 0; i < 26; i++)
    {
        if (rotorConfig[i] < 0 || rotorConfig[i] > 25)
        {
            throw invalid_argument("Rotor configuration is invalid");
        }
        if (this->rotorConfig[rotorConfig[i]] != -1)
        {
            throw invalid_argument("Rotor configuration is invalid");
        }
        this->rotorConfig[i] = rotorConfig[i];
        this->reverseRotorConfig[rotorConfig[i]] = i;
    }
}

int Rotor::getRotorNumber()
{
    return this->rotorNumber;
}

int Rotor::getCurrentPosition()
{
    return this->currentPosition;
}

bool Rotor::isNotchPosition()
{
    return this->currentPosition == this->notchPosition;
}

void Rotor::setCurrentPosition(int position)
{
    if (position < 0 || position > 25)
    {
        throw invalid_argument("Position is invalid");
    }
    this->currentPosition = position;
}

void Rotor::rotateRotor()
{
    this->currentPosition = (this->currentPosition + 1) % 26;
}

int Rotor::getForwardMapping(int input)
{
    if (input < 0 || input > 25)
    {
        throw invalid_argument("Input is invalid");
    }
    return this->rotorConfig[input];
}

int Rotor::getReverseMapping(int input)
{
    if (input < 0 || input > 25)
    {
        throw invalid_argument("Input is invalid");
    }
    return this->reverseRotorConfig[input];
}

void Rotor::printRotor()
{
    cout << "Rotor number: " << this->rotorNumber << endl;
    cout << "Current position: " << this->currentPosition << endl;
    cout << "Notch position: " << this->notchPosition << endl;
    cout << "Rotor configuration: ";
    for (int i = 0; i < 26; i++)
    {
        cout << this->rotorConfig[i] << " ";
    }
    cout << "Reverse rotor configuration: ";
    for (int i = 0; i < 26; i++)
    {
        cout << this->reverseRotorConfig[i] << " ";
    }
    cout << endl;
}