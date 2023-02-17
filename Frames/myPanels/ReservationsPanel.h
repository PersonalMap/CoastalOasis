#ifndef COASTALOASIS_RESERVATIONSPANEL_H
#define COASTALOASIS_RESERVATIONSPANEL_H
#include "myPanel.h"
#include <wx/wx.h>

class ReservationsPanel : public MyPanel {
public:
    ReservationsPanel(wxWindow *parent, const wxString& text, const wxFont& font)
            : MyPanel(parent, text, font) {
        SetBackgroundColour(wxColour(0, 253, 123));
        // ... panel-specific initialization ...
    }
};


#endif //COASTALOASIS_RESERVATIONSPANEL_H
