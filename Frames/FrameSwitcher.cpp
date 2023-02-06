#include "FrameSwitcher.h"
#include "Home.h"
#include "Login.h"
#include "ClientDashBoard.h"

FrameSwitcher::FrameSwitcher(Hotel* hotel) : currentFrame(FrameType::LOGIN) {
    this->SetSize(800,600);
    this->SetTitle("My Frame");
    this->Centre();
    this->SetBackgroundColour(wxColour(28, 37, 65));
    myHotel = hotel;
    homeWindow = std::make_unique<Home>(myHotel,this);
    loginWindow = std::make_unique<Login>(myHotel,this);
    clientDashBoardWindow = std::make_unique<ClientDashBoard>(myHotel, this);
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
                homeWindow = std::make_unique<Home>(myHotel, this);
                currentWindow = homeWindow.get();
            }
            break;
        case FrameType::LOGIN:
            if (loginWindow) {
                currentWindow = loginWindow.get();
            } else {
                loginWindow = std::make_unique<Login>(myHotel, this);
                currentWindow = loginWindow.get();
            }
            break;
        case FrameType::CLIENT_DASHBOARD:
            if (clientDashBoardWindow) {
                currentWindow = clientDashBoardWindow.get();
            } else {
                clientDashBoardWindow = std::make_unique<ClientDashBoard>(myHotel, this);
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

    currentWindow->Show(true);
    lastWindow.reset();
    currentFrame = frameType;
}

