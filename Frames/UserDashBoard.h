#ifndef COASTALOASIS_USERDASHBOARD_H
#define COASTALOASIS_USERDASHBOARD_H
#include <wx/wx.h>
#include "wx/splitter.h"
#include "../Hotel.h"
#include "FrameSwitcher.h"

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
    void UpdateUserDashboard();


private:
    Hotel *myHotel;
    wxPanel *right;
    wxPanel *body_Panel;
    wxPanel *footer_Panel;
    wxPanel *header_Panel;
    BodyPanelType bodyPanelOption = DEFAULT;

    wxStaticText *Name_label;


};


#endif //COASTALOASIS_USERDASHBOARD_H
