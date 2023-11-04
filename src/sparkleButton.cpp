#include "sparkleButton.h"

SparkleButton::SparkleButton() : Service::StatelessProgrammableSwitch()
{
    switchEvent = new Characteristic::ProgrammableSwitchEvent();
    new Characteristic::ServiceLabelIndex();

    new SpanButton(BUTTON_PIN);
}

void SparkleButton::button(int pin, int pressType)
{
    switchEvent->setVal(pressType);
}
