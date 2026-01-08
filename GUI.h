///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version 4.2.1-0-g80c4cb6)
// http://www.wxformbuilder.org/
//
// PLEASE DO *NOT* EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#pragma once

#include <wx/artprov.h>
#include <wx/xrc/xmlres.h>
#include <wx/intl.h>
#include <wx/string.h>
#include <wx/stattext.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/textctrl.h>
#include <wx/button.h>
#include <wx/bitmap.h>
#include <wx/image.h>
#include <wx/icon.h>
#include <wx/listbox.h>
#include <wx/sizer.h>
#include <wx/frame.h>
#include <wx/radiobox.h>

///////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
/// Class MainFrame
///////////////////////////////////////////////////////////////////////////////
class MainFrame : public wxFrame
{
	private:

	protected:
		wxStaticText* m_staticText1;
		wxTextCtrl* txtAmount;
		wxStaticText* m_staticText2;
		wxTextCtrl* txtDesc;
		wxButton* btnAdd;
		wxListBox* listExpenses;

	public:

		MainFrame( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = _("Expense Tracker"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 500,300 ), long style = wxDEFAULT_FRAME_STYLE|wxTAB_TRAVERSAL );

		~MainFrame();

};

///////////////////////////////////////////////////////////////////////////////
/// Class WelcomeFrame
///////////////////////////////////////////////////////////////////////////////
class WelcomeFrame : public wxFrame
{
	private:

	protected:
		wxStaticText* m_staticText3;
		wxButton* btnAgreed;

	public:

		WelcomeFrame( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = _("Welcome"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 500,300 ), long style = wxDEFAULT_FRAME_STYLE|wxTAB_TRAVERSAL );

		~WelcomeFrame();

};

///////////////////////////////////////////////////////////////////////////////
/// Class DashboardFrame
///////////////////////////////////////////////////////////////////////////////
class DashboardFrame : public wxFrame
{
	private:

	protected:
		wxButton* btnShowTotal;
		wxButton* btnAddExpenseScreen;
		wxButton* btnViewHistory;
		wxButton* btnSaveClose;

	public:

		DashboardFrame( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = _(" Dashboard"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 500,300 ), long style = wxDEFAULT_FRAME_STYLE|wxTAB_TRAVERSAL );

		~DashboardFrame();

};

///////////////////////////////////////////////////////////////////////////////
/// Class AddExpenseFrame
///////////////////////////////////////////////////////////////////////////////
class AddExpenseFrame : public wxFrame
{
	private:

	protected:
		wxStaticText* m_staticText4;
		wxTextCtrl* txtAmount;
		wxStaticText* lblDescription;
		wxTextCtrl* txtDesc;
		wxRadioBox* rbCategory;
		wxButton* btnSave;
		wxButton* btnCancel;

	public:

		AddExpenseFrame( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = _("Add New Expense"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 500,404 ), long style = wxDEFAULT_FRAME_STYLE|wxTAB_TRAVERSAL );

		~AddExpenseFrame();

};

///////////////////////////////////////////////////////////////////////////////
/// Class HistoryFrame
///////////////////////////////////////////////////////////////////////////////
class HistoryFrame : public wxFrame
{
	private:

	protected:
		wxListBox* listExpenses;
		wxButton* btnDelete;
		wxButton* btnBack;

	public:

		HistoryFrame( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = _("Expense History"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 500,300 ), long style = wxDEFAULT_FRAME_STYLE|wxTAB_TRAVERSAL );

		~HistoryFrame();

};

