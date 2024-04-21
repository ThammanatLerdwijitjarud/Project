#include<iostream>
#include<fstream>
#include<sstream>
#include"donation.cpp"
#include"add_on_func.cpp"
// #include"p_file.h"
using namespace std;

void donate();

int main () {
    LL L_cat, L_dog;
    int i;
    char choice;
    string name;
    while(1)
    {
        i=menu();

        if(i==1)
        {
            create_cat_ll(L_cat);

            L_cat.set_hol(L_cat.merge_sort((L_cat.get_hol())));
            
            L_cat.show_all('c');
            decide('c');
            
            
        }
        else if(i==2)
        {
            create_dog_ll(L_dog);

            L_dog.set_hol(L_dog.merge_sort((L_dog.get_hol())));
        
            L_dog.show_all('d');
            decide('d');
        }
        else if(i==3)
        {
            donate();
        }
        cout<<"Do you want to do it again ? (y/n):  ";
        cin>>choice;
        if(choice=='n' || choice == 'N')
        {
            break;
        }
    }

    return 0;
}

//plan 1. option 2. show ll cat or dog 3. choose cat or dog to adopt (จอง) 4. guidline คำแนะนำสำหรับการเลี้ยง 5. confirm เลี้ยงแน่ๆ 6. ask for name and telephone number (option เสริม ทำก็ได้ ไม่ทำก็ได้)

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