// wxWidgets "Hello World" Program

// For compilers that support precompilation, includes "wx/wx.h".
#include <wx/wxprec.h>
#ifndef WX_PRECOMP
#include <wx/wx.h>
#endif

//frames
#include "Frames/Home.h"

class MyApp : public wxApp
{
private:
    std::unique_ptr<Hotel> myHotel;

public:
    virtual bool OnInit();
};

enum
{
    ID_Hello = 1
};

wxIMPLEMENT_APP(MyApp);

bool MyApp::OnInit()
{
    myHotel = std::make_unique<Hotel>();
    myHotel->getFrameSwitcher()->SwitchToFrame(FrameType::HOME);

    return true;
}

