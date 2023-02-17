#ifndef COASTALOASIS_ACTIVITIESPANEL_H
#define COASTALOASIS_ACTIVITIESPANEL_H
#include "myPanel.h"
#include <wx/wx.h>

class ActivitiesPanel : public MyPanel {
public:
    ActivitiesPanel(wxWindow* parent, const wxString& text, const wxFont& font)
            : MyPanel(parent, text, font) {
        SetBackgroundColour(wxColour(255, 0, 0));
        // ... panel-specific initialization ...
    }
};


#endif
