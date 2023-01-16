#ifndef COASTALOASIS_HOME_H
#define COASTALOASIS_HOME_H
#include <wx/wxprec.h>
#ifndef WX_PRECOMP
#include <wx/wx.h>
#endif

#include <string>

class Home: public wxFrame {

private:
    std::string _debugString;
public:
    Home();
   ~Home();
};

#endif //COASTALOASIS_HOME_H
