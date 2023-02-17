#ifndef COASTALOASIS_USERDASHBOARD_H
#define COASTALOASIS_USERDASHBOARD_H
#include <wx/wx.h>
#include "wx/splitter.h"
#include "../Hotel.h"
#include "FrameSwitcher.h"
#include "myPanels/myPanel.h"

class Home;


class UserDashBoard : public wxFrame
{
public:
    enum BodyPanelType {
        DEFAULT, // default rendering
        Settings, // rendering option 1
        Activities, // rendering option 2
        BookDining,
        Reservations,
        RoomInfo
    };
    UserDashBoard();
    UserDashBoard(Hotel *hotel);
    void SwitchBodyPanel(BodyPanelType panelType);


private:
    Hotel *myHotel;
    wxPanel *right;
    wxPanel *body_Panel;
    BodyPanelType bodyPanelOption = DEFAULT;


};


#endif //COASTALOASIS_USERDASHBOARD_H
