#ifndef __INC_DEVICE_H
#define __INC_DEVICE_H

#include "Esp.h"

#define DEV_NAME "Sparkle"

struct Device
{
    char id[14]; // can this variable be immutable?

    Device();
    char *ID();
    char *Name();
    char *SW();
    char *Light(int);
    char *concat(const char *, const char *);
};

#endif
