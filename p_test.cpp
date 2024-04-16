#include<iostream>
#include<fstream>
#include<sstream>
#include "main_donate.cpp"
#include "add_on_func.cpp"
#include "p_file.h"

using namespace std;


int main () {
    int i;
    i=menu();

    LL L_cat, L_dog;

    if(i==1)
    {
        create_cat_ll(L_cat);
        
        L_cat.show_all('c');
        decide('c');
        
    }
    else if(i==2)
    {
        create_dog_ll(L_dog);
    
        L_dog.show_all('d');
        decide('d');
    }
    else
    {
        donate();
    }

    return 0;
}

//plan 1. option 2. show ll cat or dog 3. choose cat or dog to adopt (จอง) 4. guidline คำแนะนำสำหรับการเลี้ยง 5. confirm เลี้ยงแน่ๆ 6. ask for name and telephone number (option เสริม ทำก็ได้ ไม่ทำก็ได้)