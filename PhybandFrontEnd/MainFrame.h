#pragma once

#include <wx/wx.h>

class MainFrame : public wxFrame
{
public:
	//MainFrame constructor
	MainFrame(const wxString& title);
private:
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
	void SwitchToTab(std::string tabToSwitchTo);

	//********
	//CONTROLS
	//********
	wxPanel* panel;
	wxButton* testButton;

	//Tab specific controls
	wxStaticText* welcomeText;
	wxButton* healthQuikControl;
	wxButton* systemQuikControl;
	wxButton* aboutQuikControl;

	//Navigation controls
	wxButton* dashboardNavigationButton;
	wxButton* healthNavigationButton;
	wxButton* doctorsNavigationButton;
	wxButton* systemNavigationButton;
	wxButton* aboutNavigationButton;
};

