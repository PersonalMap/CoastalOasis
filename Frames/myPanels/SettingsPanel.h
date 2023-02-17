class SettingsPanel : public MyPanel {
public:
    SettingsPanel(wxWindow *parent, const wxString& text, const wxFont& font)
            : MyPanel(parent, text, font) {
        SetBackgroundColour(wxColour(0, 0, 255));

        // Create a vertical sizer for laying out the controls
        wxBoxSizer* sizer = new wxBoxSizer(wxVERTICAL);

        // Add a text label for the phone number field
        wxStaticText* phoneNumberLabel = new wxStaticText(this, wxID_ANY, "Phone number:");
        sizer->Add(phoneNumberLabel, 0, wxALL, 5);

        // Add a text control for entering the phone number
        wxTextCtrl* phoneNumberField = new wxTextCtrl(this, wxID_ANY);
        sizer->Add(phoneNumberField, 0, wxEXPAND | wxLEFT | wxRIGHT | wxBOTTOM, 5);

        // Add a text label for the email field
        wxStaticText* emailLabel = new wxStaticText(this, wxID_ANY, "Email:");
        sizer->Add(emailLabel, 0, wxALL, 5);

        // Add a text control for entering the email
        wxTextCtrl* emailField = new wxTextCtrl(this, wxID_ANY);
        sizer->Add(emailField, 0, wxEXPAND | wxLEFT | wxRIGHT | wxBOTTOM, 5);

        // Add a text label for the password field
        wxStaticText* passwordLabel = new wxStaticText(this, wxID_ANY, "Password:");
        sizer->Add(passwordLabel, 0, wxALL, 5);

        // Add a text control for entering the password
        wxTextCtrl* passwordField = new wxTextCtrl(this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_PASSWORD);
        sizer->Add(passwordField, 0, wxEXPAND | wxLEFT | wxRIGHT | wxBOTTOM, 5);

        // Add a button for updating the information
        wxButton* updateButton = new wxButton(this, wxID_ANY, "Update");
        sizer->Add(updateButton, 0, wxALL, 5);

        // Set the sizer for the panel
        SetSizer(sizer);
    }
};

