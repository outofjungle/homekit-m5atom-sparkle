#include <Arduino.h>
#include <M5Unified.h>
#include "HomeSpan.h"
#include "device.h"
#include "sparkleButton.h"
#include "sparkleLight.h"
#include "LedMatrix.h"

#define BUTTON_PIN 39

void setup()
{
    Serial.begin(115200);
    M5.begin();

    Device *dev = new Device();
    LEDMatrix *matrix = new LEDMatrix();

    homeSpan.setApSSID(dev->Name());
    homeSpan.enableAutoStartAP();
    homeSpan.begin(Category::Bridges, dev->Name());

    new SpanAccessory();
    new Service::AccessoryInformation();
    new Characteristic::Identify();

    new SpanAccessory();
    new Service::AccessoryInformation();
    new Characteristic::Identify();
    new Characteristic::Name(dev->SW());
    new SparkleButton(BUTTON_PIN);

    new SpanAccessory();
    new Service::AccessoryInformation();
    new Characteristic::Identify();
    new Characteristic::Name(dev->Light(1));
    new SparkleLight(matrix);
}

void loop()
{
    homeSpan.poll();
}
