#ifndef PresenceSensor_h
#define PresenceSensor_h

#include "Arduino.h"
#include "Button.h"

class PresenceSensor
{
public:
    PresenceSensor(int outputPin);
    PresenceSensor(int outputPin, unsigned int cicloLigado);
    void run();
    void registerButton(Button *button);
private:
    Button *_automaticButtones = NULL;
    Button *_manualButtones = NULL;
    unsigned int _numberAutomaticButtonesPressed;
    unsigned int _ciclosPermaneceLigado;
    unsigned int _cicloRestante = 0;
    byte _status = LOW;
    bool _forceActivation = false;
    int _outputPin;
    void turnOn();
    void scanButtons();
    void executarCiclo();
};

#endif
