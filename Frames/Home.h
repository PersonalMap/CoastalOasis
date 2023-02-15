#ifndef COASTALOASIS_HOME__H
#define COASTALOASIS_HOME__H
#include <wx/wxprec.h>
#ifndef WX_PRECOMP
#include <wx/wx.h>
#endif
#include "../Hotel.h"
#include <string>
#include "FrameSwitcher.h"

class Home: virtual public wxFrame {
public:
    Home();
    Home(Hotel* hotel);
    ~Home();
private:
    Hotel* myHotel;
};

#endif
