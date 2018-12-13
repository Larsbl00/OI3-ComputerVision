#ifndef POINT_H
#define POINT_H

#include <cstdint>

struct Point
{
    uint16_t x;
    uint16_t y;

    Point Add(const Point& other);
    Point Subtract(const Point& other);
    Point operator+ (const Point& other);
    Point operator- (const Point& other);
};

#endif