#include <string.h>
#include "device.h"

Device::Device()
{
    uint64_t chipid = ESP.getEfuseMac();
    sprintf(id, "%04llx-%04llx-%04llx",
            (chipid >> 32) & 0xffff,
            (chipid >> 16) & 0xffff,
            chipid & 0xffff);
}

char *Device::concat(const char *str1, const char *str2)
{
    size_t len1 = strlen(str1);
    size_t len2 = strlen(str2);

    char *result = (char *)malloc(len1 + len2 + 1);
    if (result == NULL)
    {
        Serial.println("unable to allocate memory");
        exit(1);
    }

    strcpy(result, str1);
    strcat(result, str2);

    return result;
}

char *Device::ID()
{
    return id;
}

char *Device::Name()
{
    return concat(concat(DEV_NAME, "-"), id);
}

char *Device::SW()
{
    return concat(DEV_NAME, "Switch");
}

char *Device::Light(int index)
{
    char indexStr[3];
    itoa(index, indexStr, 10);
    index++;

    return concat(concat(DEV_NAME, "Light-"), indexStr);
}
