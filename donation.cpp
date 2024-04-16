#include <iostream>
#include <string>

class Donor {
public:
    std::string name;
    double amount;
    Donor* next;

    Donor(std::string donorName, double donationAmount);
};

Donor::Donor(std::string donorName, double donationAmount){
    name = donorName;
    amount = donationAmount;
    next = NULL;
}

class donation {
private:
    Donor* head;

public:
    donation();
    void adddonation(const Donor& donor);
    double total();
    void display();
    ~donation();
};

donation::donation(){
    head = NULL;
}

void donation::adddonation(const Donor& donor){
    Donor* newDonor = new Donor(donor.name, donor.amount);
    if (head == NULL){
        head = newDonor;
    } else{
        Donor* currentptr = head;
        while (currentptr->next != NULL){
            currentptr = currentptr->next;
        }
        currentptr->next = newDonor;
    }
}

double donation::total(){
    double total = 0.0;
    Donor* currentptr = head;
    while (currentptr != NULL) {
        total += currentptr->amount;
        currentptr = currentptr->next;
    }
    return total;
}

void donation::display(){
    std::cout << "List of Donors:" << std::endl;
    Donor* currentptr = head;
    while (currentptr != NULL){
        std::cout << "Name: " << currentptr->name << ", Amount: ฿" << currentptr->amount << std::endl;
        currentptr = currentptr->next;
    }
}

donation::~donation(){
    Donor* currentptr = head;
    while (currentptr != NULL) {
        Donor* temp = currentptr;
        currentptr = currentptr->next;
        delete temp;
    }
    head = NULL;
}