#include "UserDashBoard.h"
#include "../Hotel.h"

UserDashBoard::UserDashBoard(): wxFrame(NULL, wxID_ANY, "My Frame") {};
UserDashBoard::UserDashBoard(Hotel *hotel): wxFrame(NULL, wxID_ANY, "My Frame") {
this->myHotel = hotel;
this->SetSize(800,600);
this->SetTitle("My Frame");
this->Centre();
this->SetBackgroundColour(wxColour(28, 37, 65));

wxSplitterWindow *splitter = new wxSplitterWindow(this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxSP_BORDER | wxSP_LIVE_UPDATE);


wxPanel *left = new wxPanel(splitter);
right = new wxPanel(splitter);

left->SetBackgroundColour(wxColour(251, 139, 36));
right->SetBackgroundColour(wxColour(255, 255, 255));

splitter->SetMinimumPaneSize(200);
splitter->SplitVertically(left,right,200);
splitter->SetSashGravity(0.0);

/// right side of splitter
wxPanel *header_Panel = new wxPanel(right);
header_Panel->SetBackgroundColour(wxColour(91, 192, 190));
body_Panel = new wxPanel(right);
body_Panel->SetBackgroundColour(wxColour(233, 227, 230));
wxPanel *footer_Panel = new wxPanel(right);
footer_Panel->SetBackgroundColour(wxColour(89, 65, 87));

///nav bar
wxBoxSizer *header_sizer = new wxBoxSizer(wxHORIZONTAL);
wxStaticText *Header_label = new wxStaticText(header_Panel, wxID_ANY, "CoastalOasis");
wxStaticText *Contact_label = new wxStaticText(header_Panel, wxID_ANY, "Contact us");
wxStaticText *Login_label = new wxStaticText(header_Panel, wxID_ANY, "Logout");
wxFont font = Header_label->GetFont();
font.SetPointSize(20);
wxFont font2 = font;
font2.SetPointSize(18);
Contact_label->SetFont(font2);
Login_label->SetFont(font2);
Header_label->SetFont(font);
header_sizer->AddStretchSpacer();
header_sizer->Add(Header_label, 0, wxALIGN_CENTER);
header_sizer->AddStretchSpacer();
header_sizer->Add(Contact_label, 0, wxALIGN_CENTER);
header_sizer->AddStretchSpacer();
header_sizer->Add(Login_label, 0, wxALIGN_CENTER);
header_sizer->AddStretchSpacer();
header_Panel->SetSizerAndFit(header_sizer);

///Left side of splitter
wxBoxSizer *leftsizer = new wxBoxSizer(wxVERTICAL);
wxStaticText *settings_label = new wxStaticText(left, wxID_ANY, "Settings");
wxFont font1 = settings_label->GetFont();
font1.SetPointSize(18);
font1.SetWeight(wxFONTWEIGHT_MEDIUM);
settings_label->SetFont(font1);
wxStaticText *Name_label = new wxStaticText(left, wxID_ANY, "Viktor");
Name_label->SetFont(font1);
wxStaticText *Room_label = new wxStaticText(left, wxID_ANY, "Room Info");
Room_label->SetFont(font1);
wxStaticText *bookDining_label = new wxStaticText(left, wxID_ANY, "Book Dining");
bookDining_label->SetFont(font1);
wxStaticText *bookActivity_label = new wxStaticText(left, wxID_ANY, "Our Activities");
bookActivity_label->SetFont(font1);
wxStaticText *reservation_label = new wxStaticText(left, wxID_ANY, "Reservations");
reservation_label->SetFont(font1);
leftsizer->AddStretchSpacer(1);
leftsizer->Add(Name_label, 1, wxALIGN_LEFT | wxALL, 15);
leftsizer->AddStretchSpacer(3);
leftsizer->Add(Room_label, 2, wxALIGN_LEFT | wxLEFT, 15);
leftsizer->Add(bookDining_label, 2, wxALIGN_LEFT | wxLEFT, 15);
leftsizer->Add(bookActivity_label, 2, wxALIGN_LEFT| wxLEFT, 15);
leftsizer->Add(reservation_label, 2, wxALIGN_LEFT| wxLEFT, 15);
leftsizer->Add(settings_label, 2, wxALIGN_LEFT| wxLEFT, 15);
leftsizer->AddStretchSpacer(4);
left->SetSizerAndFit(leftsizer);



wxBoxSizer *s1 = new wxBoxSizer(wxVERTICAL);
s1->Add(header_Panel, 1, wxEXPAND);
s1->Add(body_Panel, 4, wxEXPAND);
s1->Add(footer_Panel, 1, wxEXPAND);

right->SetSizerAndFit(s1);


    ///EVENT HANDLERS
    Login_label->Bind(wxEVT_LEFT_DOWN, [this](wxMouseEvent& event) { this->myHotel->getFrameSwitcher()->SwitchToFrame(FrameType::HOME);});

    Room_label->Bind(wxEVT_LEFT_DOWN, [this](wxMouseEvent& event) { this->SwitchBodyPanel(BodyPanelType::RoomInfo); });

    bookActivity_label->Bind(wxEVT_LEFT_DOWN, [this](wxMouseEvent& event) { this->SwitchBodyPanel(BodyPanelType::Activities); });

    reservation_label->Bind(wxEVT_LEFT_DOWN, [this](wxMouseEvent& event) { this->SwitchBodyPanel(BodyPanelType::Reservations); });

    settings_label->Bind(wxEVT_LEFT_DOWN, [this](wxMouseEvent& event) { this->SwitchBodyPanel(BodyPanelType::Settings); });

    bookDining_label->Bind(wxEVT_LEFT_DOWN, [this](wxMouseEvent& event) { this->SwitchBodyPanel(BodyPanelType::BookDining); }, wxID_ANY);




}

void UserDashBoard::SwitchBodyPanel(BodyPanelType panelType) {
    wxPanel *newBodyPanel;
    wxColour newBodyColor;

    switch (panelType) {
        case BodyPanelType::DEFAULT:
            newBodyPanel = new wxPanel(this->right);
            newBodyColor = wxColour(233, 227, 230);
            break;
        case BodyPanelType::Activities:
            newBodyPanel = new wxPanel(this->right);
            newBodyColor = wxColour(255, 0, 0);
            break;
        case BodyPanelType::BookDining:
            newBodyPanel = new wxPanel(this->right);
            newBodyColor = wxColour(233, 255, 0);
            break;
        case BodyPanelType::Reservations:
            newBodyPanel = new wxPanel(this->right);
            newBodyColor = wxColour(0, 253, 123);
            break;
        case BodyPanelType::RoomInfo:
            newBodyPanel = new wxPanel(this->right);
            newBodyColor = wxColour(123, 255, 0);
            break;
        case BodyPanelType::Settings:
            newBodyPanel = new wxPanel(this->right);
            newBodyColor = wxColour(0, 255, 23);
            break;
        default:
            newBodyPanel = new wxPanel(this->right);
            newBodyColor = wxColour(233, 227, 230);
            break;
    }

    // Remove the current body panel from the sizer and delete it
    wxSizer *sizer = this->right->GetSizer();
    sizer->Detach(this->body_Panel);
    delete this->body_Panel;

    // Set the new body panel and add it to the sizer
    this->body_Panel = newBodyPanel;
    this->body_Panel->SetBackgroundColour(newBodyColor);
    sizer->Add(this->body_Panel, 4, wxEXPAND);

    // Refresh the layout
    sizer->Layout();
}
