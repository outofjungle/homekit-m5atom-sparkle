#include "ledMatrix.h"

LEDMatrix::LEDMatrix()
{
    this->leds = (CRGB *)malloc(LED_LENGTH * sizeof(CRGB));

    FastLED.addLeds<WS2812, DATA_PIN, GRB>(leds, LED_LENGTH);
    FastLED.setBrightness(0x14);

    this->fastled = &FastLED;
    this->state = true;
    this->hue = 0;
    this->saturation = 0;
    transformSetV(100);

    fill_solid(leds, LED_LENGTH, CRGB::Black);
    fastled->show();
}

void LEDMatrix::SetPower(bool state)
{
    this->state = state;
}

void LEDMatrix::transformSetV(int brightness)
{
    float transfrom = float(LED_LENGTH * brightness) / 100;
    this->onLength = (uint8_t)ceil(transfrom);
    this->trimmedVal = (uint8_t)((transfrom - onLength) * 0xFF);
}

void LEDMatrix::SetValues(float H, float S, float V)
{
    this->hue = (uint8_t)(H * 255 / 360);
    this->saturation = (uint8_t)(S * 2.55);
    transformSetV(V);
}

bool LEDMatrix::On()
{
    if (state)
    {
        fill_solid(leds, LED_LENGTH, CRGB::Black);
        fill_solid(leds, onLength, CHSV(hue, saturation, 0xFF));
        if (trimmedVal > 0)
        {
            leds[onLength - 1] = CHSV(hue, saturation, trimmedVal);
        }
    }
    else
    {
        fill_solid(leds, LED_LENGTH, CRGB::Black);
    }

    fastled->show();
    return (true);
}
