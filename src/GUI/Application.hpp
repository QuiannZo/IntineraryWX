#pragma once

#include <wx/wx.h>

// Application class. OnInit calls everything needed for the program.
class Application : public wxApp {
public:
    bool OnInit() override;
};