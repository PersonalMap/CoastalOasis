#include <wx/panel.h>
#include <wx/splitter.h>
#include <wx/statline.h>
#include <iostream>

#include "../Hotel.h"
#include "Home.h"
#include "ClientDashBoard.h"
#include "Hourly.h"


Home::Home(Hotel* hotel) : wxFrame(NULL, wxID_ANY, "Home Frame", wxDefaultPosition, wxDefaultSize)
{
    myHotel = hotel;
    this->SetSize(800,600);
    this->SetTitle("My Frame");
    this->Centre();
    this->SetBackgroundColour(wxColour(28, 37, 65));

    wxBoxSizer *body = new wxBoxSizer(wxHORIZONTAL);
    wxPanel *right = new wxPanel(this);
    right->SetSizerAndFit(body);
    right->SetBackgroundColour(wxColour(255, 255, 255));


/// right side of splitter
    wxPanel *header_Panel = new wxPanel(right);
    header_Panel->SetBackgroundColour(wxColour(91, 192, 190));
    wxPanel *body_Panel = new wxPanel(right);
    body_Panel->SetBackgroundColour(wxColour(233, 227, 230));
    wxPanel *footer_Panel = new wxPanel(right);
    footer_Panel->SetBackgroundColour(wxColour(89, 65, 87));

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

    wxBoxSizer *s1 = new wxBoxSizer(wxVERTICAL);
    s1->Add(header_Panel, 1, wxEXPAND);
    s1->Add(body_Panel, 4, wxEXPAND);
    s1->Add(footer_Panel, 1, wxEXPAND);

    right->SetSizerAndFit(s1);

}

Home::~Home()
{

}