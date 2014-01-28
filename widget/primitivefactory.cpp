#include "primitivefactory.h"
#include "canvassetting.h"
#include "Line.h"
#include "circle.h"
#include "pencil.h"

Primitive* PrimitiveFactory::GetPrimitive(int type)
{
  CanvasSetting& setting = CanvasSetting::Get();
  Primitive *p = NULL;
  if (type == PT_Line)
  {
    p = new Line(type, setting.GetColor(), setting.GetLineWidth()); 
  }
  else if (type == PT_Circle)
  {
    p = new Circle(type, setting.GetColor(), setting.GetLineWidth());
  }
  else if (type == PT_Pencil)
  {
    p = new Pencil(type, setting.GetColor(), setting.GetLineWidth());
  }

  return p;
}