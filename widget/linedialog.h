///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Sep  8 2010)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#ifndef _LINEDIALOG_INCLUDED_H
#define _LINEDIALOG_INCLUDED_H

#include <wx/string.h>
#include <wx/stattext.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/textctrl.h>
#include <wx/sizer.h>
#include <wx/button.h>
#include <wx/dialog.h>
#include <wx/valtext.h>

///////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////
/// Class MyDialog4
///////////////////////////////////////////////////////////////////////////////
class LineDialog : public wxDialog 
{
private:

protected:
  wxStaticText* m_staticText13;
  wxTextCtrl* m_txtX1;
  wxStaticText* m_staticText14;
  wxTextCtrl* m_txtY1;
  wxStaticText* m_staticText19;
  wxTextCtrl* m_txtX2;
  wxStaticText* m_staticText20;
  wxTextCtrl* m_txtY2;
  wxButton* m_OkBtn;
  wxButton* m_cancelBtn;
  wxTextValidator m_validator;

  // Virtual event handlers, overide them in your derived class
  virtual void OnOKClick( wxCommandEvent& event );
  virtual void OnCancelClick( wxCommandEvent& event );


public:

  LineDialog( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("ÃÌº”÷±œﬂ"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 426,173 ), long style = wxDEFAULT_DIALOG_STYLE );
  ~LineDialog();

};

#endif //__noname__
