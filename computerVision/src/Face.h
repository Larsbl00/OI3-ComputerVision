#ifndef FACE_H
#define FACE_H

#include "Point.h"
#include "Size.h"

struct Face
{
  public:
    const Point center;
    const Size size;

    Face(const Point center, const Size size);
};

#endif