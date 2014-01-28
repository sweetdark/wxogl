#ifndef _CANVASSETTING_INCLUDED_H
#define _CANVASSETING_INCLUDED_H
#include "typedef.h"

class CanvasSetting : public ByteColor
{
private:
  CanvasSetting();

  ~CanvasSetting();
public:

  static CanvasSetting& Get()
  {
    if (!m_setting)
    {
      m_setting = new CanvasSetting();
    }
    return *m_setting;
  }
  float GetLineWidth() { return m_lineWidth; }

  int GetType() { return m_type; }

  void SetLineWidth(float width) { m_lineWidth = width; }


  void SetType(int type) 
  {
    m_type = type; 
  }
private:
  float m_lineWidth;
  int m_type;

  static CanvasSetting *m_setting;
};

#endif