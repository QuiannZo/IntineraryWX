#pragma once

#include <wx/wx.h>

// Top panel in the main frame.
class topPanel : public wxPanel{
  public:
    topPanel(wxWindow* parent);
  private:
    void OnLeftButtonClicked(wxCommandEvent& evt);
    void OnRightButtonClicked(wxCommandEvent& evt);
};

// Bottom panel in the main frame.
class bottomPanel : public wxPanel{
  public:
    bottomPanel(wxWindow* parent);
};

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
};