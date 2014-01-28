#ifndef _TYPEDEF_INCLUDED_H
#define _TYPEDEF_INCLUDED_H

enum PrimitiveType
{
  PT_Line,
  PT_Circle,
  PT_Pencil,
  PT_Max
};

struct Vertex
{
  float x;
  float y;

  Vertex(float x1, float y1) : x(x1), y(y1) {}
  Vertex() : x(0), y(0) {}

  Vertex(const Vertex &other)
  {
    x = other.x;
    y = other.y;
  }

  Vertex &operator =(const Vertex& other)
  {
    if (this == &other)
    {
      return *this;
    }

    x = other.x;
    y = other.y;
    return *this;
  }
};

class ByteColor
{
public:
  ByteColor()
  {
    m_color[0] = 0;
    m_color[1] = 0;
    m_color[2] = 0;
  }

  void SetColor(unsigned char r, unsigned char g, unsigned char b) 
  {
    m_color[0] = r; m_color[1] = g; m_color[2] = b;
  }

  void SetColor(unsigned char color[3])
  {
    m_color[0] = color[0]; m_color[1] = color[1]; m_color[2] = color[2];
  }

  const unsigned char* GetColor() { return m_color; }

  unsigned char GetR() { return m_color[0]; }
  unsigned char GetG() { return m_color[1]; }
  unsigned char GetB() { return m_color[2]; }

protected:
  unsigned char m_color[3];
};

#endif