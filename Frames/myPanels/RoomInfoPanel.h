#ifndef COASTALOASIS_ROOMINFOPANEL_H
#define COASTALOASIS_ROOMINFOPANEL_H
#include <wx/wx.h>
#include "myPanel.h"


class RoomInfoPanel : public MyPanel {
public:
    RoomInfoPanel(wxWindow *parent, const wxString& text, const wxFont& font)
            : MyPanel(parent, text, font) {
        SetBackgroundColour(wxColour(123, 255, 0));
        // ... panel-specific initialization ...
    }
};

#endif //COASTALOASIS_ROOMINFOPANEL_H
