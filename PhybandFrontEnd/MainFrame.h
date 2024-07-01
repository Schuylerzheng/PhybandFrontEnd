#pragma once

#include <wx/wx.h>

class MainFrame : public wxFrame
{
public:
	//MainFrame constructor
	MainFrame(const wxString& title);
private:
	//Setup functions
	void CreateControls();

	//Controls
	wxPanel* panel;
	wxStaticText* testText;
};

