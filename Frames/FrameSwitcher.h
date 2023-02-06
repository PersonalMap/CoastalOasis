#ifndef COASTALOASIS_FRAMESWITCHER_H
#define COASTALOASIS_FRAMESWITCHER_H
#include <memory>
#include <wx/wx.h>
#include "../Hotel.h"

class Login;
class Home;
class ClientDashBoard;

enum class FrameType {
    HOME,
    LOGIN,
    CLIENT_DASHBOARD
};

class FrameSwitcher : public wxFrame {
public:
    FrameSwitcher(Hotel* hotel);
    void SwitchToFrame(FrameType frameType);
    void setHotel(Hotel* hotel){myHotel = hotel;}

private:
    wxWindow* currentWindow;
    std::unique_ptr<wxWindow> lastWindow;
    Hotel* myHotel;
    FrameType currentFrame;
    std::unique_ptr<Home> homeWindow;
    std::unique_ptr<Login> loginWindow;
    std::unique_ptr<ClientDashBoard> clientDashBoardWindow;
};

#endif //COASTALOASIS_FRAMESWITCHER_H

