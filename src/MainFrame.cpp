#include <wx/wx.h> //includes commonly needed libs.

#include "MainFrame.hpp"

// Main window. constructor.
MainFrame::MainFrame() : wxFrame(nullptr, wxID_ANY, "Intinerary") {
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
    SetMenuBar( menuBar );
    
    // // Status bar.
    CreateStatusBar();
    SetStatusText("Version 1.0");

    // // Dinamic events.
    Bind(wxEVT_MENU, &MainFrame::OnAbout, this, wxID_ABOUT);
    Bind(wxEVT_MENU, &MainFrame::OnExit, this, wxID_EXIT);
}
 
// dinamic event 'OnExit'
void MainFrame::OnExit(wxCommandEvent& event) {
    Close(true);
}

// dinamic event 'OnAbout'
void MainFrame::OnAbout(wxCommandEvent& event)
{
    wxMessageBox("This is a personal proyect for college", "About The Proyect", wxOK | wxICON_INFORMATION);
}