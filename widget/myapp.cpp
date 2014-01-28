#include "wx/wx.h"
#include "myapp.h"
#include "myframe.h"

IMPLEMENT_APP(MyApp)

bool MyApp::OnInit()
{
	myFrame = new MyFrame1((wxFrame*)NULL, wxID_ANY, _T("OGL Painter"));
	myFrame->Show(true);
	SetTopWindow(myFrame);
	return true;
}

wxSize MyApp::GetPaintSize()
{
  return myFrame->GetPanelSize();
}





