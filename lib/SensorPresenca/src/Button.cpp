#include "Arduino.h"
#include "Button.h"

Button::Button(int inputPin) : Button(inputPin, manual) {}

Button::Button(int inputPin, ButtonType tipo) : tipo(tipo) {
    pinMode(inputPin, INPUT);
    _inputPin = inputPin;
}

bool Button::isAtivo() {
    return digitalRead(_inputPin) == HIGH;
}
