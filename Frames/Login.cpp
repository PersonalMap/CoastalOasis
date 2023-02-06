#include "Login.h"
#include "Home.h"
#include "ClientDashBoard.h"
Login::Login() = default;

Login::Login(Hotel* hotel, FrameSwitcher* frameSwitcher) : wxFrame(NULL, wxID_ANY, "Login Frame", wxDefaultPosition, wxDefaultSize)
{
    myHotel = hotel;
    myFrameSwitcher = frameSwitcher;
    this->SetSize(800,600);
    this->SetTitle("My Hotel");
    this->Centre();
    this->SetBackgroundColour(wxColour(28, 37, 65));

    wxBoxSizer *body = new wxBoxSizer(wxHORIZONTAL);
    wxPanel *right = new wxPanel(this);
    right->SetSizerAndFit(body);
    right->SetBackgroundColour(wxColour(255, 255, 255));


/// rmy content
    wxPanel *header_Panel = new wxPanel(right);
    header_Panel->SetBackgroundColour(wxColour(91, 192, 190));
    wxPanel *body_Panel = new wxPanel(right);
    body_Panel->SetBackgroundColour(wxColour(233, 227, 230));
    wxPanel *footer_Panel = new wxPanel(right);
    footer_Panel->SetBackgroundColour(wxColour(89, 65, 87));

    ///Body panel
    wxBoxSizer *body_sizer = new wxBoxSizer(wxVERTICAL);
    wxBoxSizer *login_sizer = new wxBoxSizer(wxVERTICAL);
    wxPanel *login_panel = new wxPanel(body_Panel, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxBORDER_SIMPLE | wxTAB_TRAVERSAL );

    body_sizer->AddSpacer(80);

    wxStaticText *phone_label = new wxStaticText(login_panel, wxID_ANY, "Phone Number");
    wxTextCtrl *phone_text = new wxTextCtrl(login_panel, wxID_ANY, "", wxDefaultPosition, wxSize(200, -1));
    wxStaticText *password_label = new wxStaticText(login_panel, wxID_ANY, "Password");
    wxTextCtrl *password_text = new wxTextCtrl(login_panel, wxID_ANY, "", wxDefaultPosition, wxSize(200, -1), wxTE_PASSWORD);
    wxButton *login_button = new wxButton(login_panel, wxID_ANY, "Login");

    login_sizer->Add(phone_label, 0, wxALIGN_CENTER | wxALL, 10);
    login_sizer->Add(phone_text, 0, wxALIGN_CENTER | wxALL, 10);
    login_sizer->Add(password_label, 0, wxALIGN_CENTER | wxALL, 10);
    login_sizer->Add(password_text, 0, wxALIGN_CENTER | wxALL, 10);
    login_sizer->Add(login_button, 0, wxALIGN_CENTER | wxALL, 10);

    login_panel->SetSizerAndFit(login_sizer);
    login_panel->SetBackgroundColour(wxColour(192,192,192));

    body_sizer->Add(login_panel, 0, wxALIGN_CENTER | wxALL, 10);
    body_Panel->SetSizerAndFit(body_sizer);

    phone_label->SetForegroundColour(*wxBLACK);
    password_label->SetForegroundColour(*wxBLACK);



///nav bar
    wxBoxSizer *header_sizer = new wxBoxSizer(wxHORIZONTAL);
    wxStaticText *Header_label = new wxStaticText(header_Panel, wxID_ANY, "CoastalOasis");
    wxStaticText *Contact_label = new wxStaticText(header_Panel, wxID_ANY, "Contact us");
    wxStaticText *Login_label = new wxStaticText(header_Panel, wxID_ANY, "Log in");
    wxFont font = Header_label->GetFont();
    font.SetPointSize(20);
    wxFont font2 = font;
    font2.SetPointSize(18);
    Contact_label->SetFont(font2);
    Login_label->SetFont(font2);
    Header_label->SetFont(font);
    header_sizer->AddStretchSpacer(5);
    header_sizer->Add(Header_label, 1, wxALIGN_CENTER);
    header_sizer->AddStretchSpacer();
    header_sizer->Add(Contact_label, 1, wxALIGN_CENTER);
    header_sizer->AddStretchSpacer();
    header_sizer->Add(Login_label, 1, wxALIGN_CENTER);
    header_sizer->AddStretchSpacer();
    header_Panel->SetSizerAndFit(header_sizer);

    /// Add all the content
    wxBoxSizer *s1 = new wxBoxSizer(wxVERTICAL);
    s1->Add(header_Panel, 1, wxEXPAND);
    s1->Add(body_Panel, 4, wxEXPAND);
    s1->Add(footer_Panel, 1, wxEXPAND);

    right->SetSizerAndFit(s1);



    ///EVENT HANDLERS
    Header_label->Bind(wxEVT_LEFT_UP, [this](wxMouseEvent& event)
    {
        myFrameSwitcher->SwitchToFrame(FrameType::HOME);
    });
}

Login::~Login() = default;