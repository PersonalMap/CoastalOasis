#ifndef COASTALOASIS_ACTIVITIESPANEL_H
#define COASTALOASIS_ACTIVITIESPANEL_H
#include <wx/wx.h>

class ActivitiesPanel : public wxPanel {
public:
    ActivitiesPanel(wxWindow* parent, const wxString& text, const wxFont& font)
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
