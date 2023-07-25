#include <wx/wx.h> //includes commonly needed libs.
#include <wx/sizer.h>

#include "MainFrame.hpp"

topPanel::topPanel(wxWindow* parent) 
: wxPanel(parent, wxID_ANY, wxDefaultPosition, wxSize(1220, 550), wxWANTS_CHARS) {
    this->SetBackgroundColour(wxColor(63, 63, 63));

    // Buttons.
    wxButton* previousMonthButton = new wxButton(this, wxID_ANY, "<", wxPoint(0,0), wxSize(20, 500));
    wxButton* nextMonthButton = new wxButton(this, wxID_ANY, ">", wxPoint(1200,0), wxSize(20, 500));

    wxBoxSizer* s1 = new wxBoxSizer(wxHORIZONTAL);
    s1->Add(previousMonthButton, 0, wxALIGN_CENTER_VERTICAL);
    s1->AddStretchSpacer(); 
    s1->Add(nextMonthButton, 0, wxALIGN_CENTER_VERTICAL);

    this->SetSizerAndFit(s1);

    // Dinamic buttons events. Handeled by the buttons. (The events can propagate with evt.Skip() method.).
    previousMonthButton->Bind(wxEVT_BUTTON, &topPanel::OnLeftButtonClicked, this);
    nextMonthButton->Bind(wxEVT_BUTTON, &topPanel::OnRightButtonClicked, this);
}

bottomPanel::bottomPanel(wxWindow* parent) 
: wxPanel(parent, wxID_ANY, wxDefaultPosition, wxSize(1220, 70), wxWANTS_CHARS){}

// Main window. constructor.
MainFrame::MainFrame(const wxString& title, const wxPoint& position, const wxSize& size) 
: wxFrame(nullptr, wxID_ANY, title, position, size) {
    // Main Panels.
    topPanel* panelTop = new topPanel(this);
    bottomPanel* panelBottom = new bottomPanel(this);
    
    // // Sizer at MainFrame for the panels.
    wxBoxSizer* sizer = new wxBoxSizer(wxVERTICAL);
    sizer->Add(panelTop, 1, wxEXPAND);
    sizer->Add(panelBottom, 0, wxEXPAND);

    // Set sizer.
    this->SetSizerAndFit(sizer);

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

    // // Dinamic events in MainFrame.
    Bind(wxEVT_MENU, &MainFrame::OnAbout, this, wxID_ABOUT);
    Bind(wxEVT_MENU, &MainFrame::OnExit, this, wxID_EXIT);
}

// Keyboard events.
void MainFrame::OnKeyEvent(wxKeyEvent& event){}

void MainFrame::OnExit(wxCommandEvent& event) {
    Close(true);
}

// dinamic event 'OnAbout'
void MainFrame::OnAbout(wxCommandEvent& event) {
    wxMessageBox("This is a personal proyect for college", "About The Proyect");
}

void topPanel::OnLeftButtonClicked(wxCommandEvent& evt){
    wxLogStatus("Left click.");
}

void topPanel::OnRightButtonClicked(wxCommandEvent& evt){
    wxLogStatus("Right click.");
}