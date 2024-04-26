#include<iostream>
#include<fstream>
#include<sstream>
#include"donation.cpp"
#include"add_on_func.cpp"
using namespace std;

#define GREEN_TEXT "\033[32m"
#define DEFAULT_COLOR "\033[0m"

int main () {

    LL L_cat, L_dog;

    create_cat_ll(L_cat);
    L_cat.sort_name();
    create_dog_ll(L_dog);
    L_dog.sort_name();
    //welcome();

    system("clear");

    int i;
    string choice;
    string name;
    while(1)
    {
        i=menu();

        if(i==1)
        {

            L_cat.show_all();

            Choose_sort(L_cat);
          
            decide(L_cat, 'c');
            
        }
        else if(i==2)
        {

            L_dog.show_all();

            Choose_sort(L_dog);
        
            decide(L_dog, 'd');

        }
        else if(i==3)
        {
            int d;
            d=donation();
        }
        cout<<"Do you want to do it again ? (y/n):  ";
        cin>>choice;
        if(choice=="y" || choice == "Y")
        {
            system("clear");
        }
        else { 
            cout<<GREEN_TEXT<<"-----Exit the program-----"<<DEFAULT_COLOR<<endl;
            break;
        }
    }

    return 0;
}

//plan 1. option 2. show ll cat or dog 3. choose cat or dog to adopt (จอง) 4. guidline คำแนะนำสำหรับการเลี้ยง 5. confirm เลี้ยงแน่ๆ 6. ask for name and telephone number (option เสริม ทำก็ได้ ไม่ทำก็ได้)