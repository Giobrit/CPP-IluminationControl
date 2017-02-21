#include "Button.h"
#include "ButtonUtils.h"

bool ButtonUtils::anyButtonPressed(Button *button) {
    if (button == nullptr) {
        return false;
    }

    if (button->isAtivo()) {
        Serial.println("ativar");
        return true;
    }

    return anyButtonPressed(button->next);
}

unsigned int ButtonUtils::howManyButtonesPressed(Button *button) {
    if (button == nullptr) {
        return 0;
    }

    if (button->isAtivo()) {
        return howManyButtonesPressed(button->next) + 1;
    } else {
        return howManyButtonesPressed(button->next);
    }

}

Button *ButtonUtils::findLastButton(Button *button) {
    if (button->next != nullptr) {
        return findLastButton(button->next);
    }

    return button;
}

Button *ButtonUtils::registerButton(Button *root, Button *button) {
    if (root == nullptr) {
        return  button;
    }

    findLastButton(root)->next = button;

    return root;
}
