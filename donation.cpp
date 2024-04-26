#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
#include <exception>

using namespace std;

class Donation {
private:
    string name;
    string phoneNumber;
    double amount;
    string donationDate;

public:
    // Constructor
    Donation(string n, string ph, double amt, string date) {
        name = n;
        phoneNumber = ph;
        amount = amt;
        donationDate = date;
    }

    void saveToFile() {
        ofstream outFile("donations.txt", ios::app);
        if (outFile.is_open()) {
            outFile << name << "," << phoneNumber << "," << amount << "," << donationDate << endl;
            outFile.close();
        } else {
            cout << "Unable to open file for saving donation." << endl;
        }
    }

    static double getTotalDonation() {
        ifstream inFile("donations.txt");
        if (!inFile) {
            cout << "Unable to open file for reading donations." << endl;
            return 0.0;
        }

        double total = 0.0;
        string line;
        while (getline(inFile, line)) {
            size_t pos = 0;
            string token;
            int count = 0;
            while ((pos = line.find(",")) != string::npos) {
                token = line.substr(0, pos);
                if (count == 2) {
                    total += stod(token);
                }
                line.erase(0, pos + 1);
                count++;
            }
        }
        inFile.close();
        return total;
    }
};

bool validatePhoneNumber(const string& phoneNumber) {
    if (phoneNumber.length() != 12) {
        return false;
    }
    for (char c : phoneNumber) {
        if (!isdigit(c) && c != '-') {
            return false;
        }
    }
    return true;
}

bool validateDate(const string& date) {
    // format DD-MM-YYYY
    // string dayStr = date.substr(0, 2);
    // string monthStr = date.substr(3, 2);

    string dayStr;
    string monthStr;
    string yearStr;

    int i = 0;
    while (date[i] != '/') {
        if(date[i] > '9') {
            return false;
        }
        dayStr += date[i];
        i++;
    }
    i++;
    while (date[i] != '/') {
        if(date[i] > '9') {
            return false;
        }
        monthStr += date[i];
        i++;
    }
    i++;
    while (i < date.length()) {
        if(date[i] > '9') {
            return false;
        }
        yearStr += date[i];
        i++;
    }

    int day = stoi(dayStr);
    int month = stoi(monthStr);
    if(month==2 && (day<1 || day>29))
    {
        return false;
    }
    else if((month==4 || month==6 || month==9 || month==11) && (day<1 || day>30)){
        return false;
    }

    else if (day < 1 || day > 31 || month < 1 || month > 12) {
        return false;
    }
    return true;
}


int donation() {
    string name, phoneNumber, donationDate;
    double amount;
    cin.ignore();
    cout << "Enter donor's name                       : ";
    getline(cin >> ws, name);

    bool validPhoneNumber = false;
    while (!validPhoneNumber) {
        cout << "Enter donor's phone number (XXX-XXX-XXXX): ";
        getline(cin, phoneNumber);

        validPhoneNumber = validatePhoneNumber(phoneNumber);
        if (!validPhoneNumber) {
            cout << "Invalid phone number. Please enter a valid phone number (XXX-XXX-XXXX)." << endl;
        }
    }

    bool validDate = false;
    while (!validDate) {
        cout << "Enter donation date (DD/MM/YYYY)         : ";
        getline(cin, donationDate);
        validDate = validateDate(donationDate);
        if (!validDate) {
            cout << "Invalid date. Please enter a valid date (DD/MM/YYYY)." << endl;
        }
    }

    int flag = 1;

    while (flag == 1) {
        try {
            cout << "Enter donation amount                    : ";
            cin >> amount;
            if (cin.fail()) {
                throw amount;
            }
            else {
                flag = 0;
            }
        }
        catch (const double x) {
            cin.clear();
			cin.ignore(50, '\n');
            cout << "Please type in a number\n";
        }
    }

    if (amount <= 0) {
        cout << "Invalid donation amount. Please enter a positive value." << endl;
        return 1;
    }

    char confirm;
    cout << "Confirm donation (y/n)                   : ";
    cin >> confirm;
    if (confirm != 'y' && confirm != 'Y') {
        cout << "Donation canceled." << endl;
        return 1;
    }

    cin.ignore();

    // object
    Donation donation(name, phoneNumber, amount, donationDate);

    donation.saveToFile();

    cout << "Thank you for your donation!" << endl;

    // display total
    cout << "All donations received by the Foundation: ฿ " << Donation::getTotalDonation() << endl;
    cout << "                      /^--^\\     /^--^\\     /^--^\\" << endl;
    cout << "                      \\____/     \\____/     \\____/" << endl;
    cout << "                     /      \\   /      \\   /      \\" << endl;
    cout << "                    |        | |        | |        |" << endl;
    cout << "| | | | | | | | | | | | |\\ \\| | |/ /| | | | | | \\ \\ | | | | | | | | | | |" << endl;
    cout << "| | | | | | | | | | | | / / | | |\\ \\| | | | | |/ /| | | | | | | | | | | |" << endl;
    cout << "| | | | | | | | | | | | \\/| | | | \\/| | | | | |\\/ | | | | | | | | | | | |" << endl;
    cout << "#########################################################################" << endl;
    cout << "| | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | |" << endl;
    cout << "| | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | |" << endl;

    return 0;
}