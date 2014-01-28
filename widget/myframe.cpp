///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Sep  8 2010)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "myapp.h"
#include "myframe.h"
#include "ogl.h"
#include "settingdialog.h"
#include "linedialog.h"
#include <gl/glu.h>
#include "canvassetting.h"
#include "controller.h"
#include "wx\glcanvas.h"
#include "wx\event.h"
#include "primitivefactory.h"
#include <wx\bitmap.h>
#include <wx\filepicker.h>
///////////////////////////////////////////////////////////////////////////
BEGIN_EVENT_TABLE(MyFrame1, wxFrame)
EVT_PAINT(MyFrame1::OnPaint)
END_EVENT_TABLE()
MyFrame1::MyFrame1( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxFrame( parent, id, title, pos, size, style )
{
  m_curPrimitive = NULL;
  this->SetSizeHints( wxSize( 800,480 ), wxDefaultSize );
  m_menubar1 = new wxMenuBar( 0 );
  m_fileMenu = new wxMenu();
  wxMenuItem *saveItem = new wxMenuItem(m_fileMenu, wxID_ANY, wxString(wxT("Save")) + wxT("\t") + wxT("Ctrl+S"));
  m_fileMenu->Append(saveItem);

  wxMenuItem *exitItem = new wxMenuItem(m_fileMenu, wxID_ANY, wxT("&Exit"));
  m_fileMenu->Append(exitItem);
  m_menubar1->Append( m_fileMenu, wxT("&File") ); 

  m_editMenu = new wxMenu();
  m_menubar1->Append( m_editMenu, wxT("&Edit") ); 
  wxMenuItem *settingItem = new wxMenuItem(m_editMenu, wxID_ANY, wxT("&setting"));
  m_editMenu->Append(settingItem);

  wxMenuItem *addLineItem = new wxMenuItem(m_editMenu, wxID_ANY, wxT("&Add Line"));
  m_editMenu->Append(addLineItem);

  wxMenuItem *clearItem = new wxMenuItem(m_editMenu, wxID_ANY, wxT("&Clear"));
  m_editMenu->Append(clearItem);

  wxMenuItem *undoItem = new wxMenuItem(m_editMenu, wxID_ANY, wxString( wxT("Undo") ) + wxT('\t') + wxT("Ctrl+Z"));
  m_editMenu->Append(undoItem);

  wxMenuItem *redoItem = new wxMenuItem(m_editMenu, wxID_ANY, wxString(wxT("Redo")) + wxT('\t') + wxT("Ctrl+R"));
  m_editMenu->Append(redoItem);

  m_modeMenu = new wxMenu();
  m_menubar1->Append(m_modeMenu, wxT("&Mode"));
  wxMenuItem *lineItem = new wxMenuItem(m_modeMenu, wxID_ANY, wxT("Line"));
  wxMenuItem *circleItem = new wxMenuItem(m_modeMenu, wxID_ANY, wxT("circle"));
  wxMenuItem *pencilItem = new wxMenuItem(m_modeMenu, wxID_ANY, wxT("Pencil"));
  m_modeMenu->Append(lineItem);
  m_modeMenu->Append(circleItem);
  m_modeMenu->Append(pencilItem);

  this->SetMenuBar( m_menubar1 );

  wxBoxSizer* bSizer1;
  bSizer1 = new wxBoxSizer( wxVERTICAL );

  m_panel1 = new wxPanel( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
  bSizer1->Add( m_panel1, 1, wxEXPAND | wxALL, 5);
  //m_panel1->SetMinSize( wxSize( 300,300 ) );

  this->SetSizer( bSizer1 );
  this->Layout();

  this->Centre( wxBOTH );
  m_canvas = new GLCanvas(m_panel1, m_panel1->GetSize());
  m_glContext = new GLContext(m_canvas);

  //event
  this->Connect(saveItem->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler(MyFrame1::OnSave), NULL, this);
  this->Connect(exitItem->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler(MyFrame1::OnExit), NULL, this);
  this->Connect(settingItem->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler(MyFrame1::ClickSetting), NULL, this);
  this->Connect(addLineItem->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler(MyFrame1::AddLine), NULL, this);
  this->Connect(clearItem->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler(MyFrame1::ClearAll), NULL, this);
  this->Connect(lineItem->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler(MyFrame1::SetLineMode), NULL, this);
  this->Connect(circleItem->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler(MyFrame1::SetCircleMode), NULL, this);
  this->Connect(pencilItem->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler(MyFrame1::SetPencilMode), NULL, this);

  this->Connect(undoItem->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler(MyFrame1::Undo), NULL, this);
  this->Connect(redoItem->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler(MyFrame1::Redo), NULL, this);

  m_canvas->Connect(wxEVT_LEFT_DOWN, wxMouseEventHandler(MyFrame1::OnLeftDown), NULL, this);
  m_canvas->Connect(wxEVT_LEFT_UP, wxMouseEventHandler(MyFrame1::OnLeftUp), NULL, this);
  m_canvas->Connect(wxEVT_MOTION, wxMouseEventHandler(MyFrame1::OnMouseMove), NULL, this);
}


MyFrame1::~MyFrame1()
{
}

wxSize MyFrame1::GetPanelSize()
{
  return m_panel1->GetSize();
}

void MyFrame1::ClickSetting(wxCommandEvent &event)
{
  SettingDialog dialog(this);
  dialog.ShowModal();
  wxPaintEvent e;
  OnPaint(e);
}

void MyFrame1::AddLine(wxCommandEvent &event)
{
  LineDialog dialog(this);
  dialog.ShowModal();
  wxPaintEvent e;
  OnPaint(e);
}

GLContext * MyFrame1::GetGLContext(wxGLCanvas *canvas)
{
  if (!m_glContext)
  {
    m_glContext = new GLContext(canvas);
  }
  m_glContext->SetCurrent(*canvas);
  return m_glContext;
}




void MyFrame1::OnPaint(wxPaintEvent& event)
{
  wxPaintDC dc(this);

  GetGLContext(m_canvas);
  wxSize paintSize = m_panel1->GetSize();
  m_canvas->SetSize(paintSize);
  glViewport(0, 0, paintSize.x, paintSize.y);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluOrtho2D(0, paintSize.x, 0, paintSize.y);

  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  glClear(GL_COLOR_BUFFER_BIT);
  if (m_curPrimitive)
  {
    m_curPrimitive->Draw();

  }
  Controller &control = Controller::Get();
  control.Draw(); 
  m_canvas->SwapBuffers();
}

void MyFrame1::OnLeftDown(wxMouseEvent &event)
{
  wxCoord x, y;
  event.GetPosition(&x, &y);
  m_v1.x = (float)x;
  m_v1.y = (float)(m_panel1->GetSize().y - y);
  m_curPrimitive = PrimitiveFactory::GetPrimitive(CanvasSetting::Get().GetType());
  m_curPrimitive->AddVertex(m_v1);
}

void MyFrame1::OnMouseMove(wxMouseEvent &event)
{
  if (event.LeftIsDown())
  {
    wxCoord x, y;
    event.GetPosition(&x, &y);
    m_v2.x = (float)x;
    m_v2.y = (float)(m_panel1->GetSize().y - y);
    m_curPrimitive->AddVertex(m_v2);
    Paint();  
    if (CanvasSetting::Get().GetType() != PT_Pencil)
    {
      m_curPrimitive->RemoveLastVertex();
    }
  }
}

void MyFrame1::OnLeftUp(wxMouseEvent &event)
{
  //if (event.Moving())
  {
    wxCoord x, y;
    event.GetPosition(&x, &y);
    m_v2.x = (float)x;
    m_v2.y = (float)(m_panel1->GetSize().y - y);
    m_curPrimitive->AddVertex(m_v2);
    Controller::Get().AddPrimitive(m_curPrimitive);
    m_curPrimitive = NULL;
    Paint();
  }
}

void MyFrame1::Paint()
{
  wxPaintEvent e;
  OnPaint(e);
}

void MyFrame1::ClearAll(wxCommandEvent &WXUNUSED(event))
{
  Controller::Get().ClearAll(); 
  Paint();
}

void MyFrame1::SetLineMode(wxCommandEvent &WXUNUSED(event))
{
  CanvasSetting::Get().SetType(PT_Line);
}

void MyFrame1::SetCircleMode(wxCommandEvent &WXUNUSED(event))
{
  CanvasSetting::Get().SetType(PT_Circle);
}

void MyFrame1::Undo(wxCommandEvent &WXUNUSED(event))
{
  Controller::Get().Undo();
  Paint();
}

void MyFrame1::Redo(wxCommandEvent &WXUNUSED(event))
{
  Controller::Get().Redo();
  Paint();
}
void MyFrame1::SetPencilMode(wxCommandEvent &WXUNUSED(event))
{
  CanvasSetting::Get().SetType(PT_Pencil);
}

void MyFrame1::OnSave(wxCommandEvent &WXUNUSED(event))
{
  wxFileDialog saveDialog(this, wxT("Save tga file"), "", "", "tga file (*.tga)|*.tga", wxFD_SAVE | wxFD_OVERWRITE_PROMPT);
  if (saveDialog.ShowModal() == wxID_CANCEL)
    return;
  wxString fileName = saveDialog.GetPath();
  Controller::Get().SaveToTgaFile(fileName);
}

void MyFrame1::OnExit(wxCommandEvent &WXUNUSED(event))
{
  Destroy();
}