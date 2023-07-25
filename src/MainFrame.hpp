#pragma once

#include <wx/wx.h>

// Main window. Must inherit from wxFrame.
class MainFrame : public wxFrame {
public:
    // the main frame. uses wxFrame constructor.
    MainFrame(const wxString& title, const wxPoint& position, const wxSize& size);
private:
    // Keyboard.
    void OnKeyEvent(wxKeyEvent& event);
    // dinamic events for widgets.
    void OnExit(wxCommandEvent& event);
    void OnAbout(wxCommandEvent& event);
    void OnLeftButtonClicked(wxCommandEvent& evt);
    void OnRightButtonClicked(wxCommandEvent& evt);
};