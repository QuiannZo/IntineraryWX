#pragma once

#include <wx/wx.h>

// Main window. Must inherit from wxFrame.
class MainFrame : public wxFrame {
public:
    // the main frame. uses wxFrame constructor.
    MainFrame();
private:
    // dinamic events. 
    void OnExit(wxCommandEvent& event);
    void OnAbout(wxCommandEvent& event);
};

// enum for tags.
enum {
    ID_Hello = 1
};