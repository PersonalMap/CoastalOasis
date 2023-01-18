#include <wx/panel.h>
#include <wx/stattext.h>

#include <iostream>
#include "Home.h"
#include "GlobalFunctions.h"


Home::Home() : wxFrame(NULL, wxID_ANY, "Home Frame")
{
    _debugString = "";
    wxPanel *panel = new wxPanel(this, wxID_ANY);
    wxStaticText *label = new wxStaticText(panel, wxID_ANY, "Hello World!", wxPoint(10, 10));

    //wxFrame Color
    this->SetSize(800,600);
    this->SetTitle("My Frame");
    this->Centre();
    this->SetBackgroundColour(wxColour(0,0,255));


    //
    // debug
    //

    std::cout << myGlobalFunctions::getCurrentDateTime() << std::endl;

}

Home::~Home()
{

}