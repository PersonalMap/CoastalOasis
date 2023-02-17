#ifndef COASTALOASIS_BOOKDININGPANEL_H
#define COASTALOASIS_BOOKDININGPANEL_H
#include <wx/wx.h>
#include "myPanel.h"


class BookDiningPanel : public MyPanel {
public:
    BookDiningPanel(wxWindow *parent, const wxString& text, const wxFont& font)
            : MyPanel(parent, text, font) {
        SetBackgroundColour(wxColour(233, 255, 0));
        // ... panel-specific initialization ...
    }
};


#endif
