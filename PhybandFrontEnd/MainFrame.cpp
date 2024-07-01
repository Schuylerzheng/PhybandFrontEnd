#include "MainFrame.h"
#include <wx/wx.h>

MainFrame::MainFrame(const wxString& title) : wxFrame(nullptr, wxID_ANY, title)
{
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

	//Create a panel
	panel = new wxPanel(this);
	//Create some test text and set its font
	testText = new wxStaticText(panel, wxID_ANY, "Test text", wxPoint(0, 22), wxSize(800, -1), wxALIGN_CENTER);
	testText->SetFont(titleFont);
}
