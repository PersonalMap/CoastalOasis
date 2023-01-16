#include <wx/panel.h>
#include <wx/stattext.h>

#include <iostream>
#include "Home.h"
#include "../Clients/Internal/employee.h"
#include "../HotelClasses/Clients/External/user.h"
#include "../HotelClasses/Schedule/room_scheduleitem.h"
#include "../HotelClasses/Schedule/employee_scheduleitem.h"


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

    //a worker
    Employee viktor(MyEnums::Department::HouseKeeping, "2023-01-09",
                25500, 3 ,  "Viktor", "0733589217", 19);

    std::cout << viktor;

}

Home::~Home()
{

}