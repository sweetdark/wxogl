#ifndef _CIRCLE_INCLUDED_H
#define _CIRCLE_INCLUDED_H
#include "primitive.h"

class Circle : public Primitive
{
public:
  Circle(int type, const unsigned char *color, float width);
  ~Circle();
  virtual void DrawPrimitive();
};

#endif