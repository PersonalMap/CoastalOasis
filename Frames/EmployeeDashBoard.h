#ifndef COASTALOASIS_EMPLOYEEDASHBOARD_H
#define COASTALOASIS_EMPLOYEEDASHBOARD_H
#include <wx/wx.h>
#include "../Hotel.h"
#include "FrameSwitcher.h"

class Home;

class EmployeeDashBoard : public wxFrame
{
public:
    EmployeeDashBoard();
    EmployeeDashBoard(Hotel *hotel);

private:
    Hotel *myHotel;
};


#endif
