#include "../../Clients/External/user.h"
#include "../Hotel.h"
#include <wx/string.h>

class SettingsPanel : public wxPanel {
public:
    SettingsPanel(wxWindow *parent, const wxFont &font, std::shared_ptr<User> user, Hotel* hotel)
            : wxPanel(parent), myHotel(hotel),m_user(user),m_phoneValue(new wxStaticText(this, wxID_ANY, wxString::FromUTF8(user->getPhone().c_str()))),
              m_emailValue(new wxStaticText(this, wxID_ANY, wxString::FromUTF8(user->getMail().c_str()))),
              m_passwordValue(new wxStaticText(this, wxID_ANY, wxString::FromUTF8(user->getPassword().c_str())))

    {
        wxBoxSizer *sizer = new wxBoxSizer(wxVERTICAL);

        // Phone number
        wxBoxSizer *phoneSizer = new wxBoxSizer(wxHORIZONTAL);
        wxStaticText *phoneLabel = new wxStaticText(this, wxID_ANY, "Phone number:");
        phoneLabel->SetFont(font);
        phoneSizer->Add(phoneLabel, 1, wxEXPAND);
        wxStaticText *phoneValue = new wxStaticText(this, wxID_ANY, wxString::FromUTF8(m_user->getPhone().c_str()));
        phoneValue->SetForegroundColour(wxColour(0,0,0));
        phoneValue->SetFont(font);
        phoneLabel->SetForegroundColour(wxColour(0, 0, 0)); // set text color to black
        phoneSizer->Add(phoneValue, 1, wxEXPAND);
        wxButton *phoneEditBtn = new wxButton(this, wxID_ANY, "Edit");
        phoneEditBtn->SetBackgroundColour(wxColour(0,0,0));
        phoneEditBtn->Bind(wxEVT_BUTTON, &SettingsPanel::OnEditBtnClicked, this);
        phoneSizer->Add(phoneEditBtn, 0, wxLEFT, 10);
        sizer->Add(phoneSizer, 0, wxEXPAND | wxLEFT | wxRIGHT | wxTOP, 10);

        // Email
        wxBoxSizer *emailSizer = new wxBoxSizer(wxHORIZONTAL);
        wxStaticText *emailLabel = new wxStaticText(this, wxID_ANY, "Email:");
        emailLabel->SetFont(font);
        emailSizer->Add(emailLabel, 1, wxEXPAND);
        wxStaticText *emailValue = new wxStaticText(this, wxID_ANY, wxString::FromUTF8(m_user->getMail().c_str()));
        emailValue->SetForegroundColour(wxColour(0,0,0));
        emailValue->SetFont(font);
        emailLabel->SetForegroundColour(wxColour(0, 0, 0)); // set text color to black
        emailSizer->Add(emailValue, 1, wxEXPAND);
        wxButton *emailEditBtn = new wxButton(this, wxID_ANY, "Edit");
        emailEditBtn->SetBackgroundColour(wxColour(0,0,0));
        emailEditBtn->Bind(wxEVT_BUTTON, &SettingsPanel::OnEditBtnClicked, this);
        emailSizer->Add(emailEditBtn, 0, wxLEFT, 10);
        sizer->Add(emailSizer, 0, wxEXPAND | wxLEFT | wxRIGHT | wxTOP, 10);

        // Password
        wxBoxSizer *passwordSizer = new wxBoxSizer(wxHORIZONTAL);
        wxStaticText *passwordLabel = new wxStaticText(this, wxID_ANY, "Password:");
        passwordLabel->SetFont(font);
        passwordSizer->Add(passwordLabel, 1, wxEXPAND);
        wxStaticText *passwordValue = new wxStaticText(this, wxID_ANY, wxString::FromUTF8(m_user->getPassword().c_str()));
        passwordValue->SetForegroundColour(wxColour(0,0,0));
        passwordValue->SetFont(font);
        passwordLabel->SetForegroundColour(wxColour(0, 0, 0)); // set text color to black
        passwordSizer->Add(passwordValue, 1, wxEXPAND);
        wxButton *passwordEditBtn = new wxButton(this, wxID_ANY, "Edit");
        passwordEditBtn->SetBackgroundColour(wxColour(0,0,0));
        passwordEditBtn->Bind(wxEVT_BUTTON, &SettingsPanel::OnEditBtnClicked, this);
        passwordSizer->Add(passwordEditBtn, 0, wxLEFT, 10);
        sizer->Add(passwordSizer, 0, wxEXPAND | wxLEFT | wxRIGHT | wxTOP, 10);

        SetSizer(sizer);
        SetBackgroundColour(wxColour(255, 255, 255));

        // Store the labels and values in member variables for later use
        m_phoneLabel = phoneLabel;
        m_phoneValue = phoneValue;
        m_phoneEditBtn = phoneEditBtn;

        m_emailLabel = emailLabel;
        m_emailValue = emailValue;
        m_emailEditBtn = emailEditBtn;

        m_passwordLabel = passwordLabel;
        m_passwordValue = passwordValue;
        m_passwordEditBtn = passwordEditBtn;
    }

private:
    Hotel* myHotel;
    std::shared_ptr<User> m_user;
    wxStaticText *m_phoneLabel;
    wxStaticText *m_phoneValue;
    wxButton *m_phoneEditBtn;

    wxStaticText *m_emailLabel;
    wxStaticText *m_emailValue;
    wxButton *m_emailEditBtn;

    wxStaticText *m_passwordLabel;
    wxStaticText *m_passwordValue;
    wxButton *m_passwordEditBtn;

    void OnEditBtnClicked(wxCommandEvent &event) {
        wxButton *btn = dynamic_cast<wxButton *>(event.GetEventObject());
        if (btn == m_phoneEditBtn) {
            wxTextEntryDialog dialog(this, "Enter new phone number:", "Phone number", m_phoneValue->GetLabel());
            if (dialog.ShowModal() == wxID_OK) {
                wxString phoneValue = dialog.GetValue();
                std::string phoneValueStr = std::string(phoneValue.mb_str());
                m_phoneValue->SetLabel(phoneValue);
                m_user->setPhone(phoneValueStr);
                myHotel->writeHotel(); //write to hotel
                myHotel->getFrameSwitcher()->UpdateForm(); //update frames
            }
        } else if (btn == m_emailEditBtn) {
            wxTextEntryDialog dialog(this, "Enter new email:", "Email", m_emailValue->GetLabel());
            if (dialog.ShowModal() == wxID_OK) {
                wxString emailValue = dialog.GetValue();
                std::string emailValueStr = std::string(emailValue.mb_str());
                m_emailValue->SetLabel(emailValue);
                m_user->setMail(emailValueStr);
                myHotel->writeHotel(); //write to hotel
                myHotel->getFrameSwitcher()->UpdateForm(); //update frames
            }
        } else if (btn == m_passwordEditBtn) {
            wxPasswordEntryDialog dialog(this, "Enter new password:", "Password");
            if (dialog.ShowModal() == wxID_OK) {
                wxString passwordValue = dialog.GetValue();
                std::string passwordValueStr = std::string(passwordValue.mb_str());
                m_passwordValue->SetLabel(passwordValue);
                m_user->setPassword(passwordValueStr);
                myHotel->writeHotel(); //write to hotel
                myHotel->getFrameSwitcher()->UpdateForm(); //update frames
            }
        }
    }

};