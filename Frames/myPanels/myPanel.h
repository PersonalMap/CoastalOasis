#ifndef COASTALOASIS_MYPANEL_H
#define COASTALOASIS_MYPANEL_H
#include <wx/wx.h>

class MyPanel : public wxPanel
{
public:
    MyPanel(wxWindow *parent, const wxString& text, const wxFont& font)
            : wxPanel(parent)
    {
        wxBoxSizer *sizer = new wxBoxSizer(wxVERTICAL);
        wxStaticText *label = new wxStaticText(this, wxID_ANY, text);
        label->SetFont(font);
        sizer->Add(label, 1, wxEXPAND);
        SetSizer(sizer);
    }
};


#endif //COASTALOASIS_MYPANEL_H