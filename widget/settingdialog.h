///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Sep  8 2010)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#ifndef _SETTINGDIALOG_INCLUDED_H
#define _SETTINGDIALOG_INCLUDED_H

#include <wx/string.h>
#include <wx/stattext.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/textctrl.h>
#include <wx/valtext.h>
#include <wx/sizer.h>
#include <wx/button.h>
#include <wx/dialog.h>
#include <wx/clrpicker.h>
#include <wx/valtext.h>

///////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////
/// Class MyDialog1
///////////////////////////////////////////////////////////////////////////////
class CanvasSetting;
class SettingDialog : public wxDialog 
{
private:

protected:
  wxStaticText* m_staticText1;
  wxColourPickerCtrl* m_colourPicker1;
  wxStaticText* m_staticText11;
  wxTextCtrl* m_textWidth;
  wxStaticText* m_staticText21;
  wxButton* m_ok;
  wxButton* m_cancel;
  wxTextValidator m_validator;
  CanvasSetting &m_setting;
  // Virtual event handlers, overide them in your derived class
  virtual void ColorChange( wxColourPickerEvent& event );
  virtual void OnOkClick( wxCommandEvent& event );
  virtual void OnCancelClick( wxCommandEvent& event );
  
public:

  SettingDialog( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT(" Ù–‘…Ë÷√"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 544,243 ), long style = wxDEFAULT_DIALOG_STYLE );
  ~SettingDialog();


};

#endif //__noname__
