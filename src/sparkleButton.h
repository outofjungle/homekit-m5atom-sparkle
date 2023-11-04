#ifndef __INC_SPARKLE_BUTTON_H
#define __INC_SPARKLE_BUTTON_H

#include "HomeSpan.h"

#define BUTTON_PIN 39

struct SparkleButton : Service::StatelessProgrammableSwitch
{
    SpanCharacteristic *switchEvent;

    SparkleButton();
    void button(int, int) override;
};

#endif
