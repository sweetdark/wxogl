#ifndef _LINE_INCLUDED_H
#define _LINE_INCLUDED_H
#include "primitive.h"

class Line : public Primitive
{
public:
  Line(int type, const unsigned char *color, float width);
  virtual ~Line();
protected:
  virtual void DrawPrimitive();
};
#endif