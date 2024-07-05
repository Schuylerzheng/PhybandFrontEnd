#include "MainFrame.h"
#include <wx/wx.h>

//***********
//CONSTRUCTOR
//***********

MainFrame::MainFrame(const wxString& title) : wxFrame(nullptr, wxID_ANY, title)
{
	//Run setup functions
	CreateControls();
	BindControls();
	SetupSizers();
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

	//Create test button
	testButton = new wxButton(panel, wxID_ANY, "TEST", wxDefaultPosition, wxDefaultSize);
	testButton->Show(false);

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

void MainFrame::BindControls()
{
	//Bind navigation controls
	dashboardNavigationButton->Bind(wxEVT_BUTTON, &MainFrame::OnDashboardNavigaionPressed, this);
	healthNavigationButton->Bind(wxEVT_BUTTON, &MainFrame::OnHealthNavigaionPressed, this);
	doctorsNavigationButton->Bind(wxEVT_BUTTON, &MainFrame::OnDoctorsNavigaionPressed, this);
	systemNavigationButton->Bind(wxEVT_BUTTON, &MainFrame::OnSystemNavigaionPressed, this);
	aboutNavigationButton->Bind(wxEVT_BUTTON, &MainFrame::OnAboutNavigaionPressed, this);
}

void MainFrame::SetupSizers()
{
	//Create sizers
	wxBoxSizer* mainSizer;
	wxBoxSizer* navigationControlsSizer;
	//Navigation tab specific sizers
	wxBoxSizer* dashboardQuikControlSizer;
}

//*****************
//CONTROL FUNCTIONS
//*****************

void MainFrame::OnTestButtonPressed(wxCommandEvent& evt)
{
	wxLogMessage("Test button pressed");
}

void MainFrame::OnDashboardNavigaionPressed(wxCommandEvent& evt)
{
	SwitchToTab("dashboard");
}

void MainFrame::OnHealthNavigaionPressed(wxCommandEvent& evt)
{
	SwitchToTab("health");
}

void MainFrame::OnDoctorsNavigaionPressed(wxCommandEvent& evt)
{
	SwitchToTab("doctors");
}

void MainFrame::OnSystemNavigaionPressed(wxCommandEvent& evt)
{
	SwitchToTab("system");
}

void MainFrame::OnAboutNavigaionPressed(wxCommandEvent& evt)
{
	SwitchToTab("about");
}

//****************
//HELPER FUNCTIONS
//****************

void MainFrame::SwitchToTab(std::string tabToSwitchTo)
{
	std::string formatedString = std::format("[Insert {} tab here]", tabToSwitchTo);
	wxString outputString = formatedString;
	
	wxLogMessage(outputString);
}
