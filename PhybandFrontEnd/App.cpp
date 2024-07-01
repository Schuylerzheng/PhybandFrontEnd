#include "App.h"
#include "MainFrame.h"
#include <wx/wx.h>

wxIMPLEMENT_APP(App);

bool App::OnInit()
{
    //Make mainFrame
    MainFrame* mainFrame = new MainFrame("To-Do List");

    //Set settings for mainFrame
    mainFrame->SetClientSize(800, 600);
    mainFrame->Center();
    mainFrame->Show();

    //Start program
    return true;
}
