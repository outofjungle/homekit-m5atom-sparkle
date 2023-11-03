#include "sparkleLight.h"

SparkleLight::SparkleLight(LEDMatrix *matrix) : Service::LightBulb()
{
    power = new Characteristic::On();
    H = new Characteristic::Hue(0);
    S = new Characteristic::Saturation(0);
    V = new Characteristic::Brightness(100);
    V->setRange(0, 100, 1);

    this->matrix = matrix;
}

bool SparkleLight::update()
{
    bool p;
    float h, s, v;

    h = H->getVal<float>();
    s = S->getVal<float>();
    v = V->getVal<float>();
    p = power->getVal();

    if (power->updated())
    {
        p = power->getNewVal();
    }

    if (H->updated())
    {
        h = H->getNewVal<float>();
    }

    if (S->updated())
    {
        s = S->getNewVal<float>();
    }

    if (V->updated())
    {
        v = V->getNewVal<float>();
    }

    matrix->SetPower(p);
    matrix->SetValues(h, s, v);
    return matrix->On();
}
