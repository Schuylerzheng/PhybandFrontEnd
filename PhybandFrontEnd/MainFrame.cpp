#include "MainFrame.h"
#include <wx/wx.h>

//***********
//CONSTRUCTOR
//***********

MainFrame::MainFrame(const wxString& title) : wxFrame(nullptr, wxID_ANY, title)
{
	//Set mainFrame color (for some reason it doesn't work in App.cpp)
	//this->SetBackgroundColour(wxColour(255, 255, 255));

	//Run setup functions
	CreateControls();
}

//***************
//SETUP FUNCTIONS
//***************

void MainFrame::CreateControls()
{
	//Create fonts
	wxFont titleFont(wxFontInfo(wxSize(0, 52)).Bold());
	wxFont mainFont(wxFontInfo(wxSize(0, 24)));

	//Create sizes
	wxSize navigationControlSize(160, 50);
	float navigationGap = 160;
	//Dashboard sizes
	wxSize quikControlSize(180, 50);
	float quikControlGap = 180;

	//Create a panel and give it some settings
	panel = new wxPanel(this);
	panel->SetFont(mainFont);

	//Create naviagtion controls
	dashboardNavigationButton = new wxButton(panel, wxID_ANY, "Dashboard", wxPoint(navigationGap * 0, 0), navigationControlSize);
	healthNavigationButton = new wxButton(panel, wxID_ANY, "Health", wxPoint(navigationGap * 1, 0), navigationControlSize);
	doctorsNavigationButton = new wxButton(panel, wxID_ANY, "Doctors", wxPoint(navigationGap * 2, 0), navigationControlSize);
	systemNavigationButton = new wxButton(panel, wxID_ANY, "Systems", wxPoint(navigationGap * 3, 0), navigationControlSize);
	aboutNavigationButton = new wxButton(panel, wxID_ANY, "About", wxPoint(navigationGap * 4, 0), navigationControlSize);

	//Create some welcome text for the dashboard and set its font
	welcomeText = new wxStaticText(panel, wxID_ANY, "Welcome! Have a look around!", wxPoint(0, 250), wxSize(800, -1), wxALIGN_CENTER);
	welcomeText->SetFont(titleFont);

	//Create quik controls
	systemQuikControl = new wxButton(panel, wxID_ANY, "About", wxPoint(quikControlGap * 1, 500), quikControlSize);
	aboutNavigationButton = new wxButton(panel, wxID_ANY, "About", wxPoint(quikControlGap * 2, 500), quikControlSize);
	aboutNavigationButton = new wxButton(panel, wxID_ANY, "About", wxPoint(quikControlGap * 3, 500), quikControlSize);
}
