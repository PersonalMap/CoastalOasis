#ifndef COASTALOASIS_USERDASHBOARD_H
#define COASTALOASIS_USERDASHBOARD_H
#include <wx/wx.h>
#include "../Hotel.h"
#include "FrameSwitcher.h"

class Home;

class UserDashBoard : public wxFrame
{
public:
    UserDashBoard();
    UserDashBoard(Hotel *hotel);

private:
    Hotel *myHotel;
};


#endif //COASTALOASIS_USERDASHBOARD_H
