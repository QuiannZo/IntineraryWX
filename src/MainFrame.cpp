#include <wx/wx.h> //includes commonly needed libs.
#include <wx/sizer.h>

#include "MainFrame.hpp"

// Main window. constructor.
MainFrame::MainFrame(const wxString& title, const wxPoint& position, const wxSize& size) 
: wxFrame(nullptr, wxID_ANY, title, position, size) {
    // Main Panel.
    wxPanel* panel = new wxPanel(this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxWANTS_CHARS);
    
    // // Sizer.
    

    // // Menu bar.
    // creates wxMenu's menuFile and menuHelp.
    wxMenu *menuFile = new wxMenu;
    menuFile->Append(wxID_EXIT);
    wxMenu *menuHelp = new wxMenu;
    menuHelp->Append(wxID_ABOUT);
    // Adds both to the menuBar.
    wxMenuBar *menuBar = new wxMenuBar;
    menuBar->Append(menuFile, "&File");
    menuBar->Append(menuHelp, "&Help");
    // sets menuBar to the one created.
    SetMenuBar(menuBar);
    
    // // Status bar.
    CreateStatusBar();
    SetStatusText("Version 1.0");

    // // Dinamic events.
    Bind(wxEVT_MENU, &MainFrame::OnAbout, this, wxID_ABOUT);
    Bind(wxEVT_MENU, &MainFrame::OnExit, this, wxID_EXIT);

    wxButton* previousMonthButton = new wxButton(panel, wxID_ANY, "<", wxPoint(0,0), wxSize(20, 500));
    wxButton* nextMonthButton = new wxButton(panel, wxID_ANY, ">", wxPoint(1000,0), wxSize(20, 500));

    // Dinamic buttons events. Handeled by the buttons. (The events can propagate with evt.Skip() method.).
    previousMonthButton->Bind(wxEVT_BUTTON, &MainFrame::OnLeftButtonClicked, this);
    nextMonthButton->Bind(wxEVT_BUTTON, &MainFrame::OnRightButtonClicked, this);
}

// Keyboard events.
void MainFrame::OnKeyEvent(wxKeyEvent& event){
    //
}

void MainFrame::OnExit(wxCommandEvent& event) {
    Close(true);
}

// dinamic event 'OnAbout'
void MainFrame::OnAbout(wxCommandEvent& event)
{
    wxMessageBox("This is a personal proyect for college", "About The Proyect");
}

void MainFrame::OnLeftButtonClicked(wxCommandEvent& evt){
    wxLogStatus("Left click.");
}

void MainFrame::OnRightButtonClicked(wxCommandEvent& evt){
    wxLogStatus("Right click.");
}