#ifndef _MYAPP_H
#define _MYAPP_H
#include "wx/wx.h"
class MyFrame1;


class MyApp : public wxApp
{
public:
	virtual bool OnInit();

  wxSize GetPaintSize();

private:
  MyFrame1 *myFrame;
};

DECLARE_APP(MyApp)
#endif