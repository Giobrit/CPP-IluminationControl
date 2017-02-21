#ifndef ButtonUtils_h
#define ButtonUtils_h

#include "Button.h"

class ButtonUtils
{
public:
    static bool anyButtonPressed(Button *button);
    static unsigned int howManyButtonesPressed(Button *button);
    static Button *findLastButton(Button *button);
    static Button *registerButton(Button *root, Button *button);
};

#endif
