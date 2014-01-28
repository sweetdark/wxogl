///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Sep  8 2010)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "linedialog.h"
#include "controller.h"

///////////////////////////////////////////////////////////////////////////

LineDialog::LineDialog( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
  this->SetSizeHints( wxDefaultSize, wxDefaultSize );

  m_validator.SetStyle(wxFILTER_NUMERIC);
  wxBoxSizer* bSizer13;
  bSizer13 = new wxBoxSizer( wxVERTICAL );

  wxGridSizer* gSizer1;
  gSizer1 = new wxGridSizer( 4, 4, 0, 0 );

  m_staticText13 = new wxStaticText( this, wxID_ANY, wxT("x1"), wxDefaultPosition, wxDefaultSize, 0 );
  m_staticText13->Wrap( -1 );
  gSizer1->Add( m_staticText13, 1, wxALIGN_RIGHT|wxALL, 5 );

  m_txtX1 = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
  gSizer1->Add( m_txtX1, 1, wxALIGN_LEFT, 5 );

  m_staticText14 = new wxStaticText( this, wxID_ANY, wxT("y1"), wxDefaultPosition, wxDefaultSize, 0 );
  m_staticText14->Wrap( -1 );
  gSizer1->Add( m_staticText14, 0, wxALIGN_RIGHT|wxALL, 5 );

  m_txtY1 = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
  gSizer1->Add( m_txtY1, 1, wxALIGN_LEFT, 5 );

  m_staticText19 = new wxStaticText( this, wxID_ANY, wxT("x2"), wxDefaultPosition, wxDefaultSize, 0 );
  m_staticText19->Wrap( -1 );
  gSizer1->Add( m_staticText19, 0, wxALIGN_RIGHT|wxALL, 5 );

  m_txtX2 = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
  gSizer1->Add( m_txtX2, 0, wxLEFT, 5 );

  m_staticText20 = new wxStaticText( this, wxID_ANY, wxT("y2"), wxDefaultPosition, wxDefaultSize, 0 );
  m_staticText20->Wrap( -1 );
  gSizer1->Add( m_staticText20, 0, wxALIGN_RIGHT|wxALL, 5 );

  m_txtY2 = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
  gSizer1->Add( m_txtY2, 0, wxALIGN_LEFT, 5 );

  bSizer13->Add( gSizer1, 1, wxALIGN_LEFT|wxALL|wxEXPAND, 5 );

  wxBoxSizer* bSizer24;
  bSizer24 = new wxBoxSizer( wxHORIZONTAL );

  m_OkBtn = new wxButton( this, wxID_ANY, wxT("&Ok"), wxDefaultPosition, wxDefaultSize, 0 );
  bSizer24->Add( m_OkBtn, 0, wxALL, 5 );

  m_cancelBtn = new wxButton( this, wxID_ANY, wxT("&Cancel"), wxDefaultPosition, wxDefaultSize, 0 );
  bSizer24->Add( m_cancelBtn, 0, wxALL, 5 );

  bSizer13->Add( bSizer24, 0, wxALIGN_RIGHT, 5 );

  this->SetSizer( bSizer13 );
  this->Layout();

  this->Centre( wxBOTH );

  m_txtX1->SetValidator(m_validator);
  m_txtX2->SetValidator(m_validator);
  m_txtY1->SetValidator(m_validator);
  m_txtY2->SetValidator(m_validator);

  // Connect Events
  m_OkBtn->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( LineDialog::OnOKClick ), NULL, this );
  m_cancelBtn->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( LineDialog::OnCancelClick ), NULL, this );
}

LineDialog::~LineDialog()
{
  // Disconnect Events
  m_OkBtn->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( LineDialog::OnOKClick ), NULL, this );
  m_cancelBtn->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( LineDialog::OnCancelClick ), NULL, this );

}

void LineDialog::OnOKClick(wxCommandEvent &event)
{
  double x1, x2, y1, y2;
  m_txtX1->GetValue().ToDouble(&x1);
  m_txtX2->GetValue().ToDouble(&x2);
  m_txtY1->GetValue().ToDouble(&y1);
  m_txtY2->GetValue().ToDouble(&y2);

  Controller::Get().AddLine(Vertex((float)x1, (float)y1), Vertex((float)x2, (float)y2));
  Close();
}

void LineDialog::OnCancelClick(wxCommandEvent &event)
{
  Close();
}