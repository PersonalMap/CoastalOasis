#include <wx/panel.h>
#include <wx/splitter.h>
#include <iostream>

#include "../Hotel.h"
#include "Home.h"
#include "Hourly.h"


Home::Home() : wxFrame(NULL, wxID_ANY, "Home Frame", wxDefaultPosition, wxDefaultSize)
{
    _debugString = "";
    Hotel myHotel = Hotel();
    this->SetSize(800,600);
    this->SetTitle("My Frame");
    this->Centre();
    this->SetBackgroundColour(wxColour(28, 37, 65));

    wxSplitterWindow *splitter = new wxSplitterWindow(this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxSP_BORDER | wxSP_LIVE_UPDATE);


    wxPanel *left = new wxPanel(splitter);
    wxPanel *right = new wxPanel(splitter);

        left->SetBackgroundColour(wxColour(251, 139, 36));
        right->SetBackgroundColour(wxColour(255, 255, 255));

    splitter->SetMinimumPaneSize(200);
    splitter->SplitVertically(left,right,200);
    splitter->SetSashGravity(0.0);

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
    wxStaticText *Login_label = new wxStaticText(header_Panel, wxID_ANY, "Login");

    wxFont font = Header_label->GetFont();
    font.SetPointSize(20);
    Header_label->SetFont(font);

    header_sizer->AddStretchSpacer();
    header_sizer->Add(Header_label, 0, wxALIGN_CENTER);
    header_sizer->AddStretchSpacer();
    header_sizer->Add(Contact_label, 0, wxALIGN_CENTER);
    header_sizer->AddStretchSpacer();
    header_sizer->Add(Login_label, 0, wxALIGN_CENTER);
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