#include "FrameSwitcher.h"
#include "Home.h"
#include "Login.h"
#include "UserDashBoard.h"
#include "EmployeeDashBoard.h"
#include "../Hotel.h"

FrameSwitcher* FrameSwitcher::lastActiveInstance = nullptr;

FrameSwitcher::FrameSwitcher(Hotel* hotel) : currentFrame(FrameType::LOGIN) {
    this->SetSize(800,600);
    this->SetTitle("My Frame");
    this->Centre();
    this->SetBackgroundColour(wxColour(28, 37, 65));
    myHotel = hotel;
    homeWindow = std::make_unique<Home>(myHotel);
    loginWindow = std::make_unique<Login>(myHotel);
    userDashBoardWindow = std::make_unique<UserDashBoard>(myHotel);
    employeeDashBoardWindow = std::make_unique<EmployeeDashBoard>(myHotel);
    SwitchToFrame(currentFrame);
}

void FrameSwitcher::SwitchToFrame(FrameType frameType) {
    if (currentFrame == frameType) return; // If the current frame is already the desired frame, return without doing anything

    lastWindow.reset(); // Reset lastWindow before switching to a new frame
    switch (frameType) {
        case FrameType::HOME:
            if (homeWindow) {
                currentWindow = homeWindow.get();
            } else {
                homeWindow = std::make_unique<Home>(myHotel);
                currentWindow = homeWindow.get();
            }
            break;
        case FrameType::LOGIN:
            if (loginWindow) {
                currentWindow = loginWindow.get();
            } else {
                loginWindow = std::make_unique<Login>(myHotel);
                currentWindow = loginWindow.get();
            }
            break;
        case FrameType::USER_DASHBOARD:
            if (userDashBoardWindow) {
                currentWindow = userDashBoardWindow.get();
            } else {
                userDashBoardWindow = std::make_unique<UserDashBoard>(myHotel);
                currentWindow = userDashBoardWindow.get();
            }
            break;
        case FrameType::EMPLOYEE_DASHBOARD:
            if (employeeDashBoardWindow) {
                currentWindow = employeeDashBoardWindow.get();
            } else {
                employeeDashBoardWindow = std::make_unique<EmployeeDashBoard>(myHotel);
                currentWindow = employeeDashBoardWindow.get();
            }
            break;
    }

    // Store the old frame in lastWindow before switching to the new one
    switch (currentFrame) {
        case FrameType::HOME:
            if (homeWindow) {
                lastWindow = std::move(homeWindow);
            }
            break;
        case FrameType::LOGIN:
            if (loginWindow) {
                lastWindow = std::move(loginWindow);
            }
            break;
        case FrameType::USER_DASHBOARD:
            if (userDashBoardWindow) {
                lastWindow = std::move(userDashBoardWindow);
            }
            break;
        case FrameType::EMPLOYEE_DASHBOARD:
            if (employeeDashBoardWindow) {
                lastWindow = std::move(employeeDashBoardWindow);
            }
            break;
    }

    // Hide the previous window before resetting it
    if (lastWindow) {
        lastWindow->Show(false);
    }

    lastWindow.reset();
    currentWindow->Show(true); //show current window
    currentFrame = frameType;
    UpdateForm(); //update labels
}

FrameSwitcher::~FrameSwitcher()
{
    currentWindow->Show(false);

    if (lastActiveInstance == this) {
        // If this is the last active instance, hide all frames
        if (homeWindow) {
            homeWindow->Show(false);
        }
        if (loginWindow) {
            loginWindow->Show(false);
        }
        if (userDashBoardWindow) {
            userDashBoardWindow->Show(false);
        }
        if (employeeDashBoardWindow) {
            employeeDashBoardWindow->Show(false);
        }
    }
}

void FrameSwitcher::UpdateForm() {
    switch (currentFrame) {
        case FrameType::HOME:
            // Call the appropriate method on the homeWindow pointer
            if (homeWindow) {
                homeWindow->UpdateHome();
            }
            break;
        case FrameType::LOGIN:
            // Call the appropriate method on the loginWindow pointer
            if (loginWindow) {
                loginWindow->UpdateLogin();
            }
            break;
        case FrameType::USER_DASHBOARD:
            // Call the appropriate method on the userDashBoardWindow pointer
            if (userDashBoardWindow) {
                userDashBoardWindow->UpdateUserDashboard();
            }
            break;
        case FrameType::EMPLOYEE_DASHBOARD:
            // Call the appropriate method on the employeeDashBoardWindow pointer
            if (employeeDashBoardWindow) {
                employeeDashBoardWindow->UpdateEmployeeDashboard();
            }
            break;
    }
}

