#pragma once

#include <wx/wx.h>
#include <wx/notebook.h>
#include <string>
#include <vector>
#include "EWindows.h"
#include "DeviceStats.h"

class MainFrame : public wxFrame
{
public:
	//MainFrame constructor
	MainFrame(const wxString& title);

protected:
	//*********
	//VARIABLES
	//*********
	//Devices
	//DeviceStats Devices[];

	// Create the notebook
	wxNotebook* MainTabs;

	/* Dashboard */
	wxPanel* Dashboard;
	wxPanel* DashboardPanel;
	wxBoxSizer* DashboardSizer;
	wxStaticText* WelcomeText;
	wxButton* SystemQuikControl;
	wxButton* HealthQuikControl;
	wxButton* AboutQuikControl;

	/* Health */
	wxPanel* Health;
	wxPanel* HealthPanel;
	wxBoxSizer* HealthSizer;

	/* Doctors */
	wxPanel* Doctors;
	wxPanel* DoctorsPanel;
	wxBoxSizer* DoctorsSizer;

	/* System */
	wxPanel* System;
	wxPanel* SystemPanel;
	wxBoxSizer* SystemSizer;

	/* About */
	wxPanel* About;
	wxPanel* AboutPanel;
	wxBoxSizer* AboutSizer;

	//***************
	//SETUP FUNCTIONS
	//***************
	void MakeNotebookTabs();
	void CreateControls();
	void BindControls();
	void SetupSizers();

	//*****************
	//CONTROL FUNCTIONS
	//*****************
	void OnTestButtonPressed(wxCommandEvent& evt)	{ wxLogMessage("Test button pressed"); }
	void OnDashboardNavigaionPressed(wxCommandEvent& evt) { MainTabs->SetSelection(EWindows::Dashboard); }
	void OnHealthNavigaionPressed(wxCommandEvent& evt) { MainTabs->SetSelection(EWindows::Health); }
	void OnDoctorsNavigaionPressed(wxCommandEvent& evt) { MainTabs->SetSelection(EWindows::Doctors); }
	void OnSystemNavigaionPressed(wxCommandEvent& evt) { MainTabs->SetSelection(EWindows::System); }
	void OnAboutNavigaionPressed(wxCommandEvent& evt) { MainTabs->SetSelection(EWindows::About); }

	//****************
	//HELPER FUNCTIONS
	//****************
	void SwitchToTab(int tabToSwitchTo);

	//********
	//CONTROLS
	//********
	wxPanel* panel;
	wxButton* testButton;

	//Dynamic Sizers
	wxBoxSizer* dynamicSizer;

	//Window sizers
	wxBoxSizer* dashboardSizer;
	wxBoxSizer* healthSizer;
	wxBoxSizer* doctorsSizer;
	wxBoxSizer* systemSizer;
	wxBoxSizer* aboutSizer;

	//Health tab controls
	wxStaticText* healthTestText;

	//Doctors tab controls
	wxStaticText* doctorsTestText;

	//System tab controls
	wxStaticText* systemTestText;

	//About tab contorls
	wxStaticText* aboutTestText;

	//Navigation controls
	wxButton* dashboardNavigationControl;
	wxButton* healthNavigationControl;
	wxButton* doctorsNavigationControl;
	wxButton* systemNavigationControl;
	wxButton* aboutNavigationControl;

	// Fonts
	wxFont TitleFont = wxFont(wxFontInfo(wxSize(0, 52)).Bold());
	wxFont MainFont = wxFont(wxFontInfo(wxSize(0, 24)));
};

