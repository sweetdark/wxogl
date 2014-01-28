#ifndef _PRIMITIVEFACTORY_INCLUDED_H
#define _PRIMITIVEFACTORY_INCLUDED_H
#include "primitive.h"

class PrimitiveFactory
{
public:
  static Primitive* GetPrimitive(int type);
};
#endif