#ifndef COASTALOASIS_CLIENTDASHBOARD_H
#define COASTALOASIS_CLIENTDASHBOARD_H
#include <wx/wx.h>
#include "../Hotel.h"
#include "FrameSwitcher.h"

class Home;

class ClientDashBoard : public wxFrame
{
public:
    ClientDashBoard();
    ClientDashBoard(Hotel *hotel, FrameSwitcher* frameSwitcher);

private:
    Hotel *myHotel;
    FrameSwitcher* myFrameSwitcher;
};


#endif //COASTALOASIS_CLIENTDASHBOARD_H
