#ifndef COASTALOASIS_FRAMESWITCHER_H
#define COASTALOASIS_FRAMESWITCHER_H

#include <memory>
#include <wx/wx.h>

class Login;
class Home;
class UserDashBoard;
class EmployeeDashBoard;
class Hotel;

enum class FrameType {
    HOME,
    LOGIN,
    USER_DASHBOARD,
    EMPLOYEE_DASHBOARD
};

class FrameSwitcher : public wxFrame {
public:
    explicit FrameSwitcher(Hotel* hotel);
    ~FrameSwitcher();
    void SwitchToFrame(FrameType frameType);
    void setHotel(Hotel* hotel) { myHotel = hotel; }

    static FrameSwitcher*& GetLastActiveInstance() {
        static FrameSwitcher* lastActiveInstance = nullptr;
        return lastActiveInstance;
    }
    static FrameSwitcher* lastActiveInstance;
    void HideCurrentForm();


private:
    wxWindow* currentWindow;
    std::unique_ptr<wxWindow> lastWindow;
    Hotel* myHotel;
    FrameType currentFrame;
    std::unique_ptr<Home> homeWindow;
    std::unique_ptr<Login> loginWindow;
    std::unique_ptr<UserDashBoard> userDashBoardWindow;
    std::unique_ptr<EmployeeDashBoard> employeeDashBoardWindow;
};

#endif //COASTALOASIS_FRAMESWITCHER_H


