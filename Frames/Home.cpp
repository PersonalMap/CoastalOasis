#include <wx/panel.h>
#include <wx/stattext.h>

#include <iostream>
#include "Home.h"
#include "Intern.h"
#include "employee_scheduleitem.h"
#include "HotelEnums.h"


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
    Intern viktor(MyEnums::Department::Security, HTime("202309230800"),
                  32000, 5, "Viktor", "0733589217", 19);


    Employee_scheduleitem activity(viktor, MyEnums::HotelArea::ConferenceRooms,
                                   "Möte", HTime("202312121200"), HTime("202312121400"));

    Employee_scheduleitem activity2(viktor, MyEnums::HotelArea::ConferenceRooms,
                                   "Möte", HTime("202311121200"), HTime("202311121400"));


    viktor.getScheduleP().addActivity(activity);
    viktor.getScheduleP().addActivity(activity2);
    viktor.getScheduleP().debug();


}

Home::~Home()
{

}