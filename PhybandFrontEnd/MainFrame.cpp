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
	MakeNotebookTabs();
	BindControls();
	SetupSizers();
}

//***************
//SETUP FUNCTIONS
//***************

void MainFrame::MakeNotebookTabs()
{
	// Set the value for the notebook
	MainTabs = new wxNotebook(this, wxID_ANY);

	// Set the values for the tabs
	Health = new wxPanel(MainTabs, wxID_ANY);
	Doctors = new wxPanel(MainTabs, wxID_ANY);
	System = new wxPanel(MainTabs, wxID_ANY);
	About = new wxPanel(MainTabs, wxID_ANY);

	// Set up Dashboard
	Dashboard = new wxPanel(MainTabs, wxID_ANY);
	DashboardPanel = new wxPanel(Dashboard, wxID_ANY);
	DashboardSizer = new wxBoxSizer(wxVERTICAL);
	WelcomeText = new wxStaticText(DashboardPanel, wxID_ANY, "Welcome! Have a look around!");
	WelcomeText->SetFont(TitleFont);
	SystemQuikControl = new wxButton(DashboardPanel, wxID_ANY, "System");
	HealthQuikControl = new wxButton(DashboardPanel, wxID_ANY, "Health");
	AboutQuikControl = new wxButton(DashboardPanel, wxID_ANY, "About");
	DashboardPanel->SetSizer(DashboardSizer);
	DashboardSizer->Add(WelcomeText);
	DashboardSizer->Add(SystemQuikControl);
	DashboardSizer->Add(HealthQuikControl);
	DashboardSizer->Add(AboutQuikControl);
}

void MainFrame::CreateControls()
{
	//Create a panel and give it some settings
	panel = new wxPanel(this);
	panel->SetFont(MainFont);

	//Create test button
	testButton = new wxButton(panel, wxID_ANY, "TEST");
	testButton->Show(false);

	//Create naviagtion controls
	dashboardNavigationControl = new wxButton(panel, wxID_ANY, "Dashboard");
	healthNavigationControl = new wxButton(panel, wxID_ANY, "Health");
	doctorsNavigationControl = new wxButton(panel, wxID_ANY, "Doctors");
	systemNavigationControl = new wxButton(panel, wxID_ANY, "Systems");
	aboutNavigationControl = new wxButton(panel, wxID_ANY, "About");

	//Create health controls
	healthTestText = new wxStaticText(panel, wxID_ANY, "HEALTH TEST TEXT");
	doctorsTestText = new wxStaticText(panel, wxID_ANY, "DOCTORS TEST TEXT");
	systemTestText = new wxStaticText(panel, wxID_ANY, "DOCTORS TEST TEXT");
	aboutTestText = new wxStaticText(panel, wxID_ANY, "DOCTORS TEST TEXT");
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
	SystemQuikControl->Bind(wxEVT_BUTTON, &MainFrame::OnSystemNavigaionPressed, this);
	HealthQuikControl->Bind(wxEVT_BUTTON, &MainFrame::OnHealthNavigaionPressed, this);
	AboutQuikControl->Bind(wxEVT_BUTTON, &MainFrame::OnAboutNavigaionPressed, this);
}

void MainFrame::SetupSizers()
{
	//Create sizers
	wxBoxSizer* mainSizer = new wxBoxSizer(wxVERTICAL);
	wxBoxSizer* navigationControlsSizer = new wxBoxSizer(wxHORIZONTAL);
	wxGridSizer* outputSizer = new wxGridSizer(1);
	dynamicSizer = new wxBoxSizer(wxVERTICAL);
	//Navigation tab specific sizers
	dashboardSizer = new wxBoxSizer(wxVERTICAL);
	wxBoxSizer* dashboardQuikControlSizer = new wxBoxSizer(wxHORIZONTAL);
	//Health tab sizers
	healthSizer = new wxBoxSizer(wxVERTICAL);
	//Doctors tab sizer
	doctorsSizer = new wxBoxSizer(wxVERTICAL);
	//System tab sizer
	systemSizer = new wxBoxSizer(wxVERTICAL);
	//About tab sizer
	aboutSizer = new wxBoxSizer(wxVERTICAL);

	//Add items to navigationControlSizer
	navigationControlsSizer->Add(dashboardNavigationControl, wxSizerFlags().Proportion(1));
	navigationControlsSizer->Add(healthNavigationControl, wxSizerFlags().Proportion(1));
	navigationControlsSizer->Add(doctorsNavigationControl, wxSizerFlags().Proportion(1));
	navigationControlsSizer->Add(systemNavigationControl, wxSizerFlags().Proportion(1));
	navigationControlsSizer->Add(aboutNavigationControl, wxSizerFlags().Proportion(1));

	//Add items to healthSizer
	healthSizer->Add(healthTestText, wxSizerFlags().CenterHorizontal());

	//Add items to doctorsSizer
	doctorsSizer->Add(doctorsTestText, wxSizerFlags().CenterHorizontal());

	//Add items to systemSizer
	systemSizer->Add(systemTestText, wxSizerFlags().CenterHorizontal());

	//Add items to aboutSizer
	aboutSizer->Add(aboutTestText, wxSizerFlags().CenterHorizontal());

	//Show dashboardSizer
	dashboardSizer->Show(true);

	//Hide other window sizers
	healthSizer->Show(false);
	doctorsSizer->Show(false);
	systemSizer->Show(false);
	aboutSizer->Show(false);

	//Add items to dynamicSizer
	dynamicSizer->Add(dashboardSizer, wxSizerFlags().Expand());

	//Add items to mainSizer
	mainSizer->Add(navigationControlsSizer, wxSizerFlags().Expand());
	mainSizer->Add(dynamicSizer, wxSizerFlags().Expand());
	//Add items to outputSizer
	outputSizer->Add(mainSizer, wxSizerFlags().Expand());

	//Apply output sizer as the main sizer
	panel->SetSizer(outputSizer);
	outputSizer->SetSizeHints(this);
}

//*****************
//CONTROL FUNCTIONS
//*****************



//****************
//HELPER FUNCTIONS
//****************

void MainFrame::SwitchToTab(int tabToSwitchTo)
{
	
}
