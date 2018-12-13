#ifndef SIZE_H
#define SIZE_H

#include <cstdint>

struct Size
{
    uint16_t width;
    uint16_t height;

    Size Add(const Size& other);
    Size Subtract(const Size& other);
    Size operator+ (const Size& other);
    Size operator- (const Size& other);
};

#endif