#include "Size.h"

Size Size::Add(const Size& other)
{
    return (Size){(uint16_t)(this->width + other.width), (uint16_t)(this->height + other.height)};
}

Size Size::Subtract(const Size& other)
{
    return (Size){(uint16_t)(this->width - other.width), (uint16_t)(this->height - other.height)};
}

Size Size::operator+ (const Size& other)
{
    return Add(other);
}

Size Size::operator- (const Size& other)
{
    return Subtract(other);
}