#include "Point.h"

Point Point::Add(const Point& other)
{
    return Point{this->x + other.x, this->y + other.y};
}

Point Point::Subtract(const Point& other)
{
    return Point{this->x - other.x, this->y - other.y};
}

Point Point::operator+ (const Point& other)
{
    return Add(other);
}

Point Point::operator- (const Point& other)
{
    return Subtract(other);
}