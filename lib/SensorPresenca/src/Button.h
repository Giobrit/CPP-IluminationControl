#ifndef Button_h
#define Button_h

#include "Arduino.h"

enum ButtonType
{
    automatic,
    manual
};

class Button
{
public:
    Button(int inputPin);
    Button(int inputPin, ButtonType tipo);
    Button* next = nullptr;
    bool isAtivo();
    const ButtonType tipo;
private:
    int _inputPin;

};

#endif
