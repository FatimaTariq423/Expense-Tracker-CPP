#include <wx/wx.h>
#include <vector>
#include <fstream>
#include <sstream>
#include "GUI.h"
#include "Classes.h"

using namespace std;

// --- FILE HELPERS ---
// FIX: Removed 'const' so we can call the getters without error
void saveAllToFile(vector<Expense>& expenses) {
    ofstream outFile("expenses.txt"); 
    if (outFile.is_open()) {
        for (size_t i = 0; i < expenses.size(); i++) {
            outFile << expenses[i].getAmount() << "|" 
                    << expenses[i].getCategory() << "|" 
                    << expenses[i].getDescription() << endl;
        }
        outFile.close();
    }
}

void appendToFile(double amount, string desc, string category) {
    ofstream outFile("expenses.txt", ios::app);
    if (outFile.is_open()) {
        outFile << amount << "|" << category << "|" << desc << endl;
        outFile.close();
    }
}

double calculateTotal() {
    ifstream inFile("expenses.txt");
    double total = 0;
    string line;
    if (inFile.is_open()) {
        while (getline(inFile, line)) {
            if (line.empty()) continue;
            size_t pipePos = line.find('|');
            if (pipePos != string::npos) {
                try {
                    string amtStr = line.substr(0, pipePos);
                    total += stod(amtStr);
                } catch(...) {}
            }
        }
        inFile.close();
    }
    return total;
}

// --- SCREEN 4: HISTORY & DELETE ---
class MyHistory : public HistoryFrame {
    vector<Expense> currentList;

public:
    MyHistory(wxWindow* parent) : HistoryFrame(parent) {
        this->SetBackgroundColour(*wxWHITE);
        btnDelete->Bind(wxEVT_BUTTON, &MyHistory::OnDeleteClicked, this);
        btnBack->Bind(wxEVT_BUTTON, &MyHistory::OnBackClicked, this);
        loadData();
    }

    void loadData() {
        listExpenses->Clear();
        currentList.clear();

        ifstream inFile("expenses.txt");
        string line;
        
        if (inFile.is_open()) {
            while (getline(inFile, line)) {
                if (line.empty()) continue;
                stringstream ss(line);
                string segment;
                vector<string> parts;
                
                while(getline(ss, segment, '|')) {
                    parts.push_back(segment);
                }

                if (parts.size() >= 3) {
                    double amt = stod(parts[0]);
                    string cat = parts[1];
                    string desc = parts[2];

                    Expense e(1, amt, "2025", desc, cat);
                    currentList.push_back(e);

                    wxString display = wxString::Format("[%s] %s - Rs. %.2f", cat, desc, amt);
                    listExpenses->Append(display);
                }
            }
            inFile.close();
        }
    }

    void OnDeleteClicked(wxCommandEvent& event) {
        int sel = listExpenses->GetSelection();
        if (sel == wxNOT_FOUND) {
            wxMessageBox("Select an item to delete.");
            return;
        }
        // Remove from memory
        currentList.erase(currentList.begin() + sel);
        // Remove from screen
        listExpenses->Delete(sel);
        // Update file
        saveAllToFile(currentList);
        
        wxMessageBox("Deleted!");
    }

    void OnBackClicked(wxCommandEvent& event) { Close(); }
};

// --- SCREEN 3: ADD EXPENSE ---
class MyAddExpense : public AddExpenseFrame {
public:
    MyAddExpense(wxWindow* parent) : AddExpenseFrame(parent) {
        btnSave->Bind(wxEVT_BUTTON, &MyAddExpense::OnSaveClicked, this);
        btnCancel->Bind(wxEVT_BUTTON, &MyAddExpense::OnCancelClicked, this);
        this->SetBackgroundColour(*wxWHITE);
    }

    void OnSaveClicked(wxCommandEvent& event) {
        wxString amtStr = txtAmount->GetValue();
        if(!amtStr.IsNumber()) { wxMessageBox("Invalid Amount"); return; }
        
        double amount = wxAtof(amtStr);
        string desc = txtDesc->GetValue().ToStdString();
        string category = rbCategory->GetStringSelection().ToStdString();

        appendToFile(amount, desc, category);
        wxMessageBox("Saved!");
        Close();
    }

    void OnCancelClicked(wxCommandEvent& event) { Close(); }
};

// --- SCREEN 2: DASHBOARD ---
class MyDashboard : public DashboardFrame {
public:
    MyDashboard(wxWindow* parent = NULL) : DashboardFrame(parent) {
        this->SetBackgroundColour(wxColour(240, 240, 240));
        btnSaveClose->Bind(wxEVT_BUTTON, &MyDashboard::OnCloseClicked, this);
        btnShowTotal->Bind(wxEVT_BUTTON, &MyDashboard::OnShowTotalClicked, this);
        btnAddExpenseScreen->Bind(wxEVT_BUTTON, &MyDashboard::OnAddClicked, this);
        btnViewHistory->Bind(wxEVT_BUTTON, &MyDashboard::OnHistoryClicked, this);
    }

    void OnAddClicked(wxCommandEvent& event) {
        MyAddExpense* addScreen = new MyAddExpense(this);
        addScreen->Show(true);
    }

    void OnHistoryClicked(wxCommandEvent& event) {
        MyHistory* historyScreen = new MyHistory(this);
        historyScreen->Show(true);
    }

    void OnShowTotalClicked(wxCommandEvent& event) {
        double total = calculateTotal();
        wxMessageBox(wxString::Format("Total: Rs. %.2f", total));
    }

    void OnCloseClicked(wxCommandEvent& event) { Close(); }
};

// --- SCREEN 1: WELCOME ---
class MyWelcome : public WelcomeFrame {
public:
    MyWelcome(wxWindow* parent = NULL) : WelcomeFrame(parent) {
        this->SetBackgroundColour(*wxWHITE);
        btnAgreed->SetBackgroundColour(*wxGREEN);
        btnAgreed->Bind(wxEVT_BUTTON, &MyWelcome::OnAgreedClicked, this);
    }

    void OnAgreedClicked(wxCommandEvent& event) {
        MyDashboard* dashboard = new MyDashboard();
        dashboard->Show(true);
        this->Destroy();
    }
};

class MyApp : public wxApp {
public:
    virtual bool OnInit();
};

wxIMPLEMENT_APP(MyApp);

bool MyApp::OnInit() {
    MyWelcome* frame = new MyWelcome(NULL);
    frame->Show(true);
    return true;
}