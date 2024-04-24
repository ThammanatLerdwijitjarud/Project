#include<iostream>
#include<fstream>
#include<sstream>
#include"donation1.cpp"
#include"add_on_func.cpp"
using namespace std;

int main () {

    LL L_cat, L_dog;

    create_cat_ll(L_cat);
    create_dog_ll(L_dog);
    //welcome();

    system("clear");

    int i;
    char choice;
    string name;
    while(1)
    {
        i=menu();

        if(i==1)
        {
            Choose_sort(L_cat,'c');
          
            decide(L_cat, 'c');

            
        }
        else if(i==2)
        {
            Choose_sort(L_dog,'d');
        
            decide(L_dog, 'd');

        }
        else if(i==3)
        {
            int d;
            d=donation();
        }
        cout<<"Do you want to do it again ? (y/n):  ";
        cin>>choice;
        if(choice=='n' || choice == 'N')
        {
            system("clear");
            break;
        }
        else { system("clear"); }
    }

    return 0;
}

//plan 1. option 2. show ll cat or dog 3. choose cat or dog to adopt (จอง) 4. guidline คำแนะนำสำหรับการเลี้ยง 5. confirm เลี้ยงแน่ๆ 6. ask for name and telephone number (option เสริม ทำก็ได้ ไม่ทำก็ได้)