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
    Home *frame = new Home();

    frame->Show(true);
    return true;
}

