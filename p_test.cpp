#include<iostream>
#include<fstream>
#include<sstream>
#include "p_file.h"
using namespace std;

int menu()
{
    int i;
    cout<<R"(Choose option :
    1. Adopt cat
    2. Adopt dog
    3. Donate
Enter menu : )";
    cin>>i;
    return i;
}

void guide(char c)
{
    int g;
    if(c=='c')
    {
        cout<<"Guideline for cat"<<"\n"; //call from guideline.txt
    }
    else
    {
        cout<<"Guideline for dog"<<"\n"; //call from guideline.txt
    }
}

void decide(char c)
{
    string name;
    if(c=='c')
    {
        cout<<R"(Which cat do ypu want to adopt ?
        Enter name : )";
        cin>>name;
        guide('c');
    }
    else
    {
        cout<<R"(Which dog do ypu want to adopt ?
        Enter name : )";
        cin>>name;
        guide('d');  
    }
}


int main () {
    int i;
    i=menu();

    LL L_cat, L_dog;

    if(i==1)
    {
        create_cat_ll(L_cat);
        cout << "done" << endl;
        L_cat.show_all('c');
        decide('c');
        
    }
    else if(i==2)
    {
        create_dog_ll(L_dog);
        cout << "done1" << endl;
        L_dog.show_all('d');
        decide('d');
    }

    return 0;
}

//plan 1. option 2. show ll cat or dog 3. choose cat or dog to adopt (จอง) 4. guidline คำแนะนำสำหรับการเลี้ยง 5. confirm เลี้ยงแน่ๆ 6. ask for name and telephone number