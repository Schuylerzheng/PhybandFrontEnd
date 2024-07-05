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

	//****************
	//HELPER FUNCTIONS
	//****************
	void SwitchToTab(std::string tabToSwitchTo);

	//********
	//CONTROLS
	//********
	wxPanel* panel;

	//Dashboard tab specific controls
	wxStaticText* welcomeText;
	wxButton* systemQuikControl;
	wxButton* HealthQuikControl;
	wxButton* aboutQuikControl;

	//Navigation controls
	wxButton* dashboardNavigationButton;
	wxButton* healthNavigationButton;
	wxButton* doctorsNavigationButton;
	wxButton* systemNavigationButton;
	wxButton* aboutNavigationButton;
};

