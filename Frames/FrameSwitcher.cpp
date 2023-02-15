#include "FrameSwitcher.h"
#include "Home.h"
#include "Login.h"
#include "ClientDashBoard.h"
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
    clientDashBoardWindow = std::make_unique<ClientDashBoard>(myHotel);
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
        case FrameType::CLIENT_DASHBOARD:
            if (clientDashBoardWindow) {
                currentWindow = clientDashBoardWindow.get();
            } else {
                clientDashBoardWindow = std::make_unique<ClientDashBoard>(myHotel);
                currentWindow = clientDashBoardWindow.get();
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
        case FrameType::CLIENT_DASHBOARD:
            if (clientDashBoardWindow) {
                lastWindow = std::move(clientDashBoardWindow);
            }
            break;
    }

    // Hide the previous window before resetting it
    if (lastWindow) {
        lastWindow->Show(false);
    }

    lastWindow.reset();
    currentWindow->Show(true);
    currentFrame = frameType;
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
        if (clientDashBoardWindow) {
            clientDashBoardWindow->Show(false);
        }
    }
}


