#include "circle.h"
#include <math.h>
#include "typedef.h"

#define PI 3.14159

Circle::Circle(int type, const unsigned char *color, float width) : Primitive(type, color, width)
{

}

Circle::~Circle()
{

}

void Circle::DrawPrimitive()
{
  if (m_vertices.size() < 2)
  {
    return;
  }
  Vertex v1 = m_vertices[0];
  Vertex v2 = m_vertices[1];

  float centerX = (float)(v1.x + v2.x)/2;
  float centerY = (float)(v1.y + v2.y)/2;

  float radiusX = fabs((float)(v2.x - v1.x))/2;
  float radiusY = fabs((float)(v2.y - v1.y))/2;

  float angle = 0.0;
  glBegin(GL_LINE_STRIP);
    for(; angle < 2 * PI; angle += 0.01)
    {
      glVertex2f(centerX + radiusX * cos(angle), centerY + radiusY * sin(angle));
    }
    glVertex2f(centerX + radiusX, centerY);
  glEnd();

}