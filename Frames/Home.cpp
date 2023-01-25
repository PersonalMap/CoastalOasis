#include <wx/panel.h>
#include <wx/stattext.h>

#include <iostream>

#include "../Hotel.h"
#include "Home.h"
#include "Hourly.h"


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

    Hotel myHotel = Hotel();

    HTime start = HTime("202303092100");
    auto viktor = std::make_unique<Contractor>(start,MyEnums::Department::Security, start, 20000, 5, "Viktor", "0733589217", 18);
   // myHotel.addEmployee(std::move(viktor));


    ///Debug
    myHotel.printEmployees();

}

Home::~Home()
{

}