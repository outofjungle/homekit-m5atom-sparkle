#ifndef __INC_SPARKLE_LIGHT_H
#define __INC_SPARKLE_LIGHT_H

#include "HomeSpan.h"
#include "LedMatrix.h"

struct SparkleLight : Service::LightBulb
{
    LEDMatrix *matrix;
    SpanCharacteristic *power;
    SpanCharacteristic *H;
    SpanCharacteristic *S;
    SpanCharacteristic *V;

    SparkleLight(LEDMatrix *);
    bool update();
};

#endif
