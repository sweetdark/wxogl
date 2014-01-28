#include "line.h"

Line::Line(int type, const unsigned char *color, float width) : Primitive(type, color, width)
{

}

Line::~Line()
{

}

void Line::DrawPrimitive()
{
  glEnableClientState(GL_VERTEX_ARRAY);
  glVertexPointer(2, GL_FLOAT, 0, &m_vertices[0]);
  glDrawArrays(GL_LINES, 0, m_vertices.size());
  glDisableClientState(GL_VERTEX_ARRAY);
}