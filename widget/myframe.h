///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Sep  8 2010)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#ifndef _MYFRAME_INCLUDED_H
#define _MYFRAME_INCLUDED_H

#include <wx/string.h>
#include <wx/menu.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/panel.h>
#include <wx/sizer.h>
#include <wx/frame.h>
#include <wx/glcanvas.h>
#include "typedef.h"

///////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////
/// Class MyFrame1
///////////////////////////////////////////////////////////////////////////////
class GLCanvas;
class GLContext;
class Primitive;

class PaintPanel : public wxPanel
{

};
class MyFrame1 : public wxFrame 
{
private:

protected:
  wxMenuBar* m_menubar1;
  wxMenu* m_fileMenu;
  wxMenu* m_editMenu;
  wxMenu* m_modeMenu;
  wxPanel* m_panel1;
  GLCanvas *m_canvas;
  GLContext *m_glContext;

  Vertex m_v1;
  Vertex m_v2;
  Primitive *m_curPrimitive;
public:

  MyFrame1( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxEmptyString, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 500,300 ), long style = wxDEFAULT_FRAME_STYLE|wxTAB_TRAVERSAL );
  ~MyFrame1();
  
  void OnPaint(wxPaintEvent& event);

  GLContext *GetGLContext(wxGLCanvas *canvas);

  wxSize GetPanelSize();

  void ClickSetting(wxCommandEvent &event);

  void AddLine(wxCommandEvent &event);
protected:
  void OnLeftDown(wxMouseEvent &event);

  void OnMouseMove(wxMouseEvent &event);

  void OnLeftUp(wxMouseEvent &event);

  void ClearAll(wxCommandEvent &event);

  void SetLineMode(wxCommandEvent &event);

  void SetCircleMode(wxCommandEvent &event);

  void SetPencilMode(wxCommandEvent &event);

  void Undo(wxCommandEvent &event);

  void Redo(wxCommandEvent &event);

  void OnSave(wxCommandEvent &event);

  void OnExit(wxCommandEvent &event);

private:
  void Paint();
  DECLARE_EVENT_TABLE()
};


#endif //__noname__
