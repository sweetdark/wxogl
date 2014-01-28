#ifndef _PRIMITIVE_INCLUDED_H
#define _PRIMITIVE_INCLUDED_H
#include "typedef.h"
#include <vector>
#include <wx/glcanvas.h>
using namespace std;


class Primitive : public ByteColor
{
  typedef vector<Vertex> Vertices;
  typedef Vertices::iterator VerItr;
public:
  Primitive(int type, const unsigned char *color, float width);
  virtual ~Primitive();
  
  int GetType();

  void Draw();

  void GenerateList();

  void Active(bool isActive = true)
  {
    m_isActive = isActive;
  }

  bool IsActive()
  {
    return m_isActive;
  }
  void AddVertex(const Vertex &vertex);
  void RemoveLastVertex();
protected:
  virtual void DrawPrimitive() = 0;
  
  void SetColorAndWidth();

  Vertices m_vertices;
private:
  int m_type;
  bool m_isActive;
  float m_width;
};
#endif