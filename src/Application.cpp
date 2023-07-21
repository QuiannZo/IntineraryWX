#include <wx/wx.h>

#include "Application.hpp"
#include "MainFrame.hpp"

// A macro that runs the program. It runs MyApp, which has OnInit.
wxIMPLEMENT_APP(Application);

// Function that runs the program until false.
// Creates an instance of the main window and shows it.
bool Application::OnInit() {
    MainFrame* frame = new MainFrame();
    frame->Show(true);
    return true;
}