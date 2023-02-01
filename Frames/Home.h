#ifndef COASTALOASIS_HOME_H
#define COASTALOASIS_HOME_H
#include <wx/wxprec.h>
#ifndef WX_PRECOMP
#include <wx/wx.h>
#endif
#include "../Hotel.h"
#include "ClientDashBoard.h"

#include <string>

class Home: public wxFrame {

private:
    Hotel* myHotel;
    ClientDashBoard* _clientDash;
public:
    Home(Hotel* hotel);
   ~Home();
};

#endif //COASTALOASIS_HOME_H
