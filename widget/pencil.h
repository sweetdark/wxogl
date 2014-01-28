#ifndef _PENCIL_INCLUDED_H
#define _PENCIL_INCLUDED_H
#include "primitive.h"

class Pencil : public Primitive
{
public:
  Pencil(int type, const unsigned char*color, float width);
  ~Pencil();

  virtual void DrawPrimitive();
};
#endif