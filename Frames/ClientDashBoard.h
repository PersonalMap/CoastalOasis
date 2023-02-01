#ifndef COASTALOASIS_CLIENTDASHBOARD_H
#define COASTALOASIS_CLIENTDASHBOARD_H
#include <wx/wx.h>
#include "../Hotel.h"

class ClientDashBoard : public wxFrame
{
public:
    ClientDashBoard();
    ClientDashBoard(Hotel *hotel);

private:
    Hotel *myHotel;
};


#endif //COASTALOASIS_CLIENTDASHBOARD_H
