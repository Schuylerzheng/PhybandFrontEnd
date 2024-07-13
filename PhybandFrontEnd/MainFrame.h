#pragma once

#include <wx/wx.h>
#include <string>

class MainFrame : public wxFrame
{
public:
	//MainFrame constructor
	MainFrame(const wxString& title);
private:
	//*********
	//VARIABLES
	//*********
	//Devices
	

	//Windows
	//*******WINDOW TABLE*******
	//0 = dash
	//1 = health
	//2 = doctors
	//3 = system
	//4 = about
	int currentWindow = 0;

	//***************
	//SETUP FUNCTIONS
	//***************
	void CreateControls();
	void BindControls();
	void SetupSizers();

	//*****************
	//CONTROL FUNCTIONS
	//*****************
	void OnTestButtonPressed(wxCommandEvent& evt);
	 
	//For navigation controls
	void OnDashboardNavigaionPressed(wxCommandEvent& evt);
	void OnHealthNavigaionPressed(wxCommandEvent& evt);
	void OnDoctorsNavigaionPressed(wxCommandEvent& evt);
	void OnSystemNavigaionPressed(wxCommandEvent& evt);
	void OnAboutNavigaionPressed(wxCommandEvent& evt);

	//For tab specific controls
	

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
	

	//Tab specific controls
	wxStaticText* welcomeText;
	wxButton* healthQuikControl;
	wxButton* systemQuikControl;
	wxButton* aboutQuikControl;

	//Navigation controls
	wxButton* dashboardNavigationControl;
	wxButton* healthNavigationControl;
	wxButton* doctorsNavigationControl;
	wxButton* systemNavigationControl;
	wxButton* aboutNavigationControl;
};

