///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Sep  8 2010)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "settingdialog.h"
#include "canvassetting.h"
#include <Windows.h>
#include <stdlib.h>

///////////////////////////////////////////////////////////////////////////

SettingDialog::SettingDialog( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style ), m_setting(CanvasSetting::Get())
{
  this->SetSizeHints( wxDefaultSize, wxDefaultSize );

  wxBoxSizer* bSizer1;
  bSizer1 = new wxBoxSizer( wxVERTICAL );

  wxBoxSizer* bSizer2;
  bSizer2 = new wxBoxSizer( wxHORIZONTAL );

  m_staticText1 = new wxStaticText( this, wxID_ANY, wxT("RGB:"), wxDefaultPosition, wxDefaultSize, 0 );
  m_staticText1->Wrap( -1 );
  bSizer2->Add( m_staticText1, 0, wxALL, 5 );

  m_colourPicker1 = new wxColourPickerCtrl( this, wxID_ANY, *wxBLACK, wxDefaultPosition, wxDefaultSize, wxCLRP_DEFAULT_STYLE );
  bSizer2->Add( m_colourPicker1, 0, wxALL, 5 );

  bSizer1->Add( bSizer2, 0, wxEXPAND, 5 );

  wxBoxSizer* bSizer6;
  bSizer6 = new wxBoxSizer( wxHORIZONTAL );

  m_staticText11 = new wxStaticText( this, wxID_ANY, wxT("线宽:"), wxDefaultPosition, wxDefaultSize, 0 );
  m_staticText11->Wrap( -1 );
  bSizer6->Add( m_staticText11, 0, wxALL, 5 );

  m_textWidth = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
  bSizer6->Add( m_textWidth, 0, wxALL, 5 );

  m_staticText21 = new wxStaticText( this, wxID_ANY, wxT(" 线宽为浮点数，根据OpenGL实现有不同的范围"), wxDefaultPosition, wxDefaultSize, 0 );
  m_staticText21->Wrap( -1 );
  m_validator.SetStyle(wxFILTER_NUMERIC);
  m_textWidth->SetValidator(m_validator);
  bSizer6->Add( m_staticText21, 0, wxALL, 5 );

  bSizer1->Add( bSizer6, 0, wxALIGN_TOP|wxEXPAND|wxLEFT, 5 );

  wxBoxSizer* bSizer10;
  bSizer10 = new wxBoxSizer( wxHORIZONTAL );

  m_ok = new wxButton( this, wxID_ANY, wxT("确定&Y"), wxDefaultPosition, wxDefaultSize, 0 );
  bSizer10->Add( m_ok, 0, wxALIGN_RIGHT|wxALL, 5 );

  m_cancel = new wxButton( this, wxID_ANY, wxT("取消&N"), wxDefaultPosition, wxDefaultSize, 0 );
  bSizer10->Add( m_cancel, 0, wxALL, 5 );

  bSizer1->Add( bSizer10, 0, wxALIGN_RIGHT, 5 );

  this->SetSizer( bSizer1 );
  this->Layout();

  this->Centre( wxBOTH );

  float lineWidth = m_setting.GetLineWidth();
  char width[10] = {0,};
  gcvt(lineWidth, 3, width);
  m_textWidth->SetValue(width);
  wxColour color(m_setting.GetR(), m_setting.GetG(), m_setting.GetB());
  m_colourPicker1->SetColour(color);

  // Connect Events
  m_colourPicker1->Connect( wxEVT_COMMAND_COLOURPICKER_CHANGED, wxColourPickerEventHandler( SettingDialog::ColorChange ), NULL, this );
  m_ok->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( SettingDialog::OnOkClick ), NULL, this );
  m_cancel->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( SettingDialog::OnCancelClick), NULL, this);
}

SettingDialog::~SettingDialog()
{
  // Disconnect Events
  m_ok->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( SettingDialog::OnOkClick ), NULL, this );
  m_cancel->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( SettingDialog::OnCancelClick), NULL, this);
  m_colourPicker1->Disconnect( wxEVT_COMMAND_COLOURPICKER_CHANGED, wxColourPickerEventHandler( SettingDialog::ColorChange ), NULL, this );
}

void SettingDialog::OnOkClick( wxCommandEvent& event )
{
  wxColour clr = m_colourPicker1->GetColour();
  m_setting.SetColor(clr.Red(), clr.Green(), clr.Blue());
  double width;
  wxString str = m_textWidth->GetValue();
  str.ToDouble(&width);
  ::OutputDebugStr(str.c_str());
  m_setting.SetLineWidth((float)width);
  Close(); 
}

void SettingDialog::OnCancelClick( wxCommandEvent& event )
{
  Close();
}

void SettingDialog::ColorChange( wxColourPickerEvent& event )
{
}