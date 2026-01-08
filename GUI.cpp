///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version 4.2.1-0-g80c4cb6)
// http://www.wxformbuilder.org/
//
// PLEASE DO *NOT* EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "GUI.h"

///////////////////////////////////////////////////////////////////////////

MainFrame::MainFrame( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxFrame( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );

	wxBoxSizer* bSizer1;
	bSizer1 = new wxBoxSizer( wxVERTICAL );

	m_staticText1 = new wxStaticText( this, wxID_ANY, _("Amount:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText1->Wrap( -1 );
	bSizer1->Add( m_staticText1, 0, wxALL, 5 );

	txtAmount = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer1->Add( txtAmount, 0, wxALL, 5 );

	m_staticText2 = new wxStaticText( this, wxID_ANY, _("Description:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText2->Wrap( -1 );
	bSizer1->Add( m_staticText2, 0, wxALL, 5 );

	txtDesc = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer1->Add( txtDesc, 0, wxALL, 5 );

	btnAdd = new wxButton( this, wxID_ANY, _("Add Expense"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer1->Add( btnAdd, 0, wxALL, 5 );

	listExpenses = new wxListBox( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0, NULL, 0 );
	bSizer1->Add( listExpenses, 0, wxALL, 5 );


	this->SetSizer( bSizer1 );
	this->Layout();

	this->Centre( wxBOTH );
}

MainFrame::~MainFrame()
{
}

WelcomeFrame::WelcomeFrame( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxFrame( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );

	wxBoxSizer* bSizer2;
	bSizer2 = new wxBoxSizer( wxVERTICAL );

	m_staticText3 = new wxStaticText( this, wxID_ANY, _("EXPENSE TRACKER"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText3->Wrap( -1 );
	m_staticText3->SetFont( wxFont( 20, wxFONTFAMILY_SWISS, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxT("Arial Rounded MT Bold") ) );

	bSizer2->Add( m_staticText3, 0, wxALL, 5 );

	btnAgreed = new wxButton( this, wxID_ANY, _("Agreed to Continue"), wxDefaultPosition, wxDefaultSize, 0 );
	btnAgreed->SetForegroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_CAPTIONTEXT ) );
	btnAgreed->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_ACTIVECAPTION ) );

	bSizer2->Add( btnAgreed, 0, wxALL, 5 );


	this->SetSizer( bSizer2 );
	this->Layout();

	this->Centre( wxBOTH );
}

WelcomeFrame::~WelcomeFrame()
{
}

DashboardFrame::DashboardFrame( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxFrame( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	this->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_ACTIVEBORDER ) );

	wxBoxSizer* bSizer3;
	bSizer3 = new wxBoxSizer( wxVERTICAL );

	btnShowTotal = new wxButton( this, wxID_ANY, _("Show Total Expenditure"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer3->Add( btnShowTotal, 0, wxALL, 5 );

	btnAddExpenseScreen = new wxButton( this, wxID_ANY, _("Add New Expense"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer3->Add( btnAddExpenseScreen, 0, wxALL, 5 );

	btnViewHistory = new wxButton( this, wxID_ANY, _("View History & Delete"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer3->Add( btnViewHistory, 0, wxALL, 5 );

	btnSaveClose = new wxButton( this, wxID_ANY, _("Save & Close"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer3->Add( btnSaveClose, 0, wxALL, 5 );


	this->SetSizer( bSizer3 );
	this->Layout();

	this->Centre( wxBOTH );
}

DashboardFrame::~DashboardFrame()
{
}

AddExpenseFrame::AddExpenseFrame( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxFrame( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );

	wxBoxSizer* bSizer4;
	bSizer4 = new wxBoxSizer( wxVERTICAL );

	m_staticText4 = new wxStaticText( this, wxID_ANY, _("Amount:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText4->Wrap( -1 );
	bSizer4->Add( m_staticText4, 0, wxALL, 5 );

	txtAmount = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer4->Add( txtAmount, 0, wxALL, 5 );

	lblDescription = new wxStaticText( this, wxID_ANY, _("Description:"), wxDefaultPosition, wxDefaultSize, 0 );
	lblDescription->Wrap( -1 );
	bSizer4->Add( lblDescription, 0, wxALL, 5 );

	txtDesc = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer4->Add( txtDesc, 0, wxALL, 5 );

	wxString rbCategoryChoices[] = { _("Food"), _("Transport"), _("Utilities"), _("Others"), wxEmptyString };
	int rbCategoryNChoices = sizeof( rbCategoryChoices ) / sizeof( wxString );
	rbCategory = new wxRadioBox( this, wxID_ANY, _("Select Category"), wxDefaultPosition, wxDefaultSize, rbCategoryNChoices, rbCategoryChoices, 1, wxRA_SPECIFY_COLS );
	rbCategory->SetSelection( 0 );
	bSizer4->Add( rbCategory, 0, wxALL, 5 );

	btnSave = new wxButton( this, wxID_ANY, _("Save Expense"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer4->Add( btnSave, 0, wxALL, 5 );

	btnCancel = new wxButton( this, wxID_ANY, _("Cancel"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer4->Add( btnCancel, 0, wxALL, 5 );


	this->SetSizer( bSizer4 );
	this->Layout();

	this->Centre( wxBOTH );
}

AddExpenseFrame::~AddExpenseFrame()
{
}

HistoryFrame::HistoryFrame( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxFrame( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );

	wxBoxSizer* bSizer7;
	bSizer7 = new wxBoxSizer( wxVERTICAL );

	listExpenses = new wxListBox( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0, NULL, 0 );
	bSizer7->Add( listExpenses, 1, wxEXPAND, 5 );

	btnDelete = new wxButton( this, wxID_ANY, _("Delete Selected Item"), wxDefaultPosition, wxDefaultSize, 0 );
	btnDelete->SetForegroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_BTNTEXT ) );
	btnDelete->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_BTNHIGHLIGHT ) );

	bSizer7->Add( btnDelete, 0, wxALL, 5 );

	btnBack = new wxButton( this, wxID_ANY, _("Back to Dashboard"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer7->Add( btnBack, 0, wxALL, 5 );


	this->SetSizer( bSizer7 );
	this->Layout();

	this->Centre( wxBOTH );
}

HistoryFrame::~HistoryFrame()
{
}
