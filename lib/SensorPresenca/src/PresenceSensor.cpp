#include "Arduino.h"
#include "PresenceSensor.h"
#include "Button.h"
#include "ButtonUtils.h"

PresenceSensor::PresenceSensor(int outputPin) : PresenceSensor(outputPin, 20) {}

PresenceSensor::PresenceSensor(int outputPin, unsigned int cicloLigado) {
    pinMode(outputPin, OUTPUT);

    _outputPin = outputPin;
    _ciclosPermaneceLigado = cicloLigado;
}

void PresenceSensor::run() {
    scanButtons();

    if (_forceActivation || ButtonUtils::anyButtonPressed(_automaticButtones)) {
        turnOn();
    } else {
        executarCiclo();
    }

    digitalWrite(_outputPin, _status);
}

void PresenceSensor::executarCiclo() {
    if (_status == HIGH) {
        _cicloRestante--;

        if (_cicloRestante == 0){
            _status = LOW;
        }
    }
}

void PresenceSensor::scanButtons() {
    unsigned int switchesPressed = ButtonUtils::howManyButtonesPressed(_manualButtones);

    if (switchesPressed != _numberAutomaticButtonesPressed) {
        _forceActivation = !_forceActivation;
        _numberAutomaticButtonesPressed = switchesPressed;
    }
}

void PresenceSensor::turnOn() {
    _status = HIGH;
    _cicloRestante = _ciclosPermaneceLigado;
}

void PresenceSensor::registerButton(Button *button) {
    switch(button->tipo) {
        case manual:
        _manualButtones = ButtonUtils::registerButton(_manualButtones, button);
        break;
        case automatic:
        _automaticButtones = ButtonUtils::registerButton(_automaticButtones, button);
        break;
    }
}
