#include "primitive.h"

Primitive::Primitive(int type, const unsigned char *color, float width) : m_type(type), m_isActive(true), m_width(width)
{
  if (color != NULL)
  {
    m_color[0] = color[0];
    m_color[1] = color[1];
    m_color[2] = color[2];
  }
}

Primitive::~Primitive()
{
  m_vertices.clear();
}

void Primitive::Draw()
{
  if (!m_isActive)
  {
    return;
  }
  SetColorAndWidth();
  DrawPrimitive();
}

void Primitive::AddVertex(const Vertex &vertex)
{
  m_vertices.push_back(vertex);
}

void Primitive::RemoveLastVertex()
{
  m_vertices.pop_back();
}

int Primitive::GetType()
{
  return m_type;
}

void Primitive::SetColorAndWidth()
{
  glColor3ub(m_color[0], m_color[1], m_color[2]);
  glLineWidth(m_width);
}
