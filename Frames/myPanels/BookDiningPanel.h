#ifndef COASTALOASIS_BOOKDININGPANEL_H
#define COASTALOASIS_BOOKDININGPANEL_H
#include <wx/wx.h>


class BookDiningPanel : public wxPanel {
public:
    BookDiningPanel(wxWindow *parent, const wxString& text, const wxFont& font)
            : wxPanel(parent) {

        wxBoxSizer *sizer = new wxBoxSizer(wxVERTICAL);
        wxStaticText *label = new wxStaticText(this, wxID_ANY, text);
        label->SetFont(font);
        sizer->Add(label, 1, wxEXPAND);
        SetSizer(sizer);
        SetBackgroundColour(wxColour(255, 0, 0));
    }
};


#endif
