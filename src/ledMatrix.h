#ifndef __INC_LED_MATRIX_H
#define __INC_LED_MATRIX_H

#include <FastLED.h>
#include <colorutils.h>
#include <math.h>

#define DATA_PIN 27
#define LED_LENGTH 25

struct LEDMatrix
{
    CFastLED *fastled;
    CRGB *leds;
    bool state;
    uint8_t hue,
        saturation,
        value,
        onLength,
        trimmedVal;

    LEDMatrix();
    void SetPower(bool);
    void transformSetV(int);
    void SetValues(float, float, float);
    bool On();
    bool Blink();
};

#endif
