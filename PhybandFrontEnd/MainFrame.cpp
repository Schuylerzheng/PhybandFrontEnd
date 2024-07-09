#include "MainFrame.h"
#include <wx/wx.h>
#include <string>

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

	//Create a panel and give it some settings
	panel = new wxPanel(this);
	panel->SetFont(mainFont);

	//Create test button
	testButton = new wxButton(panel, wxID_ANY, "TEST");
	testButton->Show(false);

	//Create naviagtion controls
	dashboardNavigationControl = new wxButton(panel, wxID_ANY, "Dashboard");
	healthNavigationControl = new wxButton(panel, wxID_ANY, "Health");
	doctorsNavigationControl = new wxButton(panel, wxID_ANY, "Doctors");
	systemNavigationControl = new wxButton(panel, wxID_ANY, "Systems");
	aboutNavigationControl = new wxButton(panel, wxID_ANY, "About");

	//Create some welcome text for the dashboard and set its font
	welcomeText = new wxStaticText(panel, wxID_ANY, "Welcome! Have a look around!");
	welcomeText->SetFont(titleFont);

	//Create quik controls
	systemQuikControl = new wxButton(panel, wxID_ANY, "system");
	healthQuikControl = new wxButton(panel, wxID_ANY, "health");
	aboutQuikControl = new wxButton(panel, wxID_ANY, "about");
}

void MainFrame::BindControls()
{
	//Bind navigation controls
	dashboardNavigationControl->Bind(wxEVT_BUTTON, &MainFrame::OnDashboardNavigaionPressed, this);
	healthNavigationControl->Bind(wxEVT_BUTTON, &MainFrame::OnHealthNavigaionPressed, this);
	doctorsNavigationControl->Bind(wxEVT_BUTTON, &MainFrame::OnDoctorsNavigaionPressed, this);
	systemNavigationControl->Bind(wxEVT_BUTTON, &MainFrame::OnSystemNavigaionPressed, this);
	aboutNavigationControl->Bind(wxEVT_BUTTON, &MainFrame::OnAboutNavigaionPressed, this);

	//Bind tab specific controls
	systemQuikControl->Bind(wxEVT_BUTTON, &MainFrame::OnSystemNavigaionPressed, this);
	healthQuikControl->Bind(wxEVT_BUTTON, &MainFrame::OnHealthNavigaionPressed, this);
	aboutQuikControl->Bind(wxEVT_BUTTON, &MainFrame::OnAboutNavigaionPressed, this);
}

void MainFrame::SetupSizers()
{
	//Create sizers
	wxBoxSizer* mainSizer = new wxBoxSizer(wxVERTICAL);
	wxBoxSizer* navigationControlsSizer = new wxBoxSizer(wxHORIZONTAL);
	wxGridSizer* outputSizer = new wxGridSizer(1);
	//Navigation tab specific sizers
	wxBoxSizer* dashboardSizer = new wxBoxSizer(wxVERTICAL);
	wxBoxSizer* dashboardQuikControlSizer = new wxBoxSizer(wxHORIZONTAL);

	//Add items to navigationControlSizer
	navigationControlsSizer->Add(dashboardNavigationControl, wxSizerFlags().Proportion(1));
	navigationControlsSizer->Add(healthNavigationControl, wxSizerFlags().Proportion(1));
	navigationControlsSizer->Add(doctorsNavigationControl, wxSizerFlags().Proportion(1));
	navigationControlsSizer->Add(systemNavigationControl, wxSizerFlags().Proportion(1));
	navigationControlsSizer->Add(aboutNavigationControl, wxSizerFlags().Proportion(1));

	//Add items to dashboardQuikControlSizer
	dashboardQuikControlSizer->Add(healthQuikControl, wxSizerFlags().Proportion(1));
	dashboardQuikControlSizer->Add(systemQuikControl, wxSizerFlags().Proportion(1));
	dashboardQuikControlSizer->Add(aboutQuikControl, wxSizerFlags().Proportion(1));
	//Add items to dashboardSizer
	dashboardSizer->AddSpacer(150);
	dashboardSizer->Add(welcomeText, wxSizerFlags().CenterHorizontal());
	dashboardSizer->AddSpacer(25);
	dashboardSizer->Add(dashboardQuikControlSizer, wxSizerFlags().CenterHorizontal());

	//Add items to mainSizer
	mainSizer->Add(navigationControlsSizer, wxSizerFlags().Expand());
	mainSizer->Add(dashboardSizer, wxSizerFlags().Expand());
	//Add items to outputSizer
	outputSizer->Add(mainSizer, wxSizerFlags().Expand());

	//Apply output sizer as the main sizer
	panel->SetSizer(outputSizer);
	outputSizer->SetSizeHints(this);
}

//*****************
//CONTROL FUNCTIONS
//*****************

//Navigation controls
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

//Tab specific controls


//****************
//HELPER FUNCTIONS
//****************

void MainFrame::SwitchToTab(std::string tabToSwitchTo)
{
	std::string formatedString = std::format("[Insert {} tab here]", tabToSwitchTo);
	wxString outputString = formatedString;
	
	wxLogMessage(outputString);
}
