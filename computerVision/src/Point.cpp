#include "Point.h"

Point Point::Add(const Point& other)
{
    return (Point){(uint16_t)(this->x + other.x), (uint16_t)(this->y + other.y)};
}

Point Point::Subtract(const Point& other)
{
    return (Point){(uint16_t)(this->x - other.x), (uint16_t)(this->y - other.y)};
}

Point Point::operator+ (const Point& other)
{
    return Add(other);
}

Point Point::operator- (const Point& other)
{
    return Subtract(other);
}