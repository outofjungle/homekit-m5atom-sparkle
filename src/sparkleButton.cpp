#include "sparkleButton.h"

SparkleButton::SparkleButton(int buttonPin) : Service::StatelessProgrammableSwitch()
{
    switchEvent = new Characteristic::ProgrammableSwitchEvent();
    new Characteristic::ServiceLabelIndex();

    new SpanButton(buttonPin);
}

void SparkleButton::button(int pin, int pressType)
{
    switchEvent->setVal(pressType);
}
