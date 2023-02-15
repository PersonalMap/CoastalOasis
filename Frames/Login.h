#ifndef COASTALOASIS_LOGIN_H
#define COASTALOASIS_LOGIN_H
#include <wx/wxprec.h>
#ifndef WX_PRECOMP
#include <wx/wx.h>
#endif

#include "../Hotel.h"
#include "FrameSwitcher.h"

class Home;
class ClientDashBoard;

class Login : public wxFrame {

private:
    Hotel* myHotel;
    FrameSwitcher* myFrameSwitcher;
    bool CheckCredentials(const wxString& phone, const wxString& password);
public:
    Login();
    Login(Hotel* hotel, FrameSwitcher* frameSwitcher);
    ~Login();

};


#endif