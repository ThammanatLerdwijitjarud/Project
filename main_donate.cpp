#include <iostream>
#include <string>
#include "donation.cpp"

using namespace std;

void donate(){
    donation donation;

    char choice;
    do{
        string name;
        double amount;

        cout << "Enter donor's name: ";
        cin >> name;

        cout << "Enter donation amount: ";
        cin >> amount;

        donation.adddonation(Donor(name, amount));

        cout << "Do you want to add another donation? (y/n): ";
        cin >> choice;
    } while (choice == 'y' || choice == 'Y');

    donation.display();


    cout << "Total Donations: ฿" << donation.total() << endl;

}