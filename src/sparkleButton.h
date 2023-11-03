#ifndef __INC_SPARKLE_BUTTON_H
#define __INC_SPARKLE_BUTTON_H

#include "HomeSpan.h"

struct SparkleButton : Service::StatelessProgrammableSwitch
{

    SpanCharacteristic *switchEvent;

    SparkleButton(int);
    void button(int, int) override;
};

#endif
