#include "pencil.h"

Pencil::Pencil(int type, const unsigned char*color, float width) : Primitive(type, color, width)
{

}

Pencil::~Pencil()
{

}

void Pencil::DrawPrimitive()
{
  glEnableClientState(GL_VERTEX_ARRAY);
  glVertexPointer(2, GL_FLOAT, 0, &m_vertices[0]);
  glDrawArrays(GL_LINE_STRIP, 0, m_vertices.size());
  glDisableClientState(GL_VERTEX_ARRAY);
  //glBegin(GL_LINE_STRIP);
  //  for (int i = 0; i < m_vertices.size(); ++i)
  //  {
  //    glVertex2f(m_vertices[i].x, m_vertices[i].y);
  //  }
  //glEnd();

}