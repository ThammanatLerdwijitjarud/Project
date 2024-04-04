#include <iostream>
#include<cstdlib>
#include"NODE.h"

using namespace std;
int main()
{
    cat cat1;
    cat1.set_name("Garfield");
    cat1.set_gender('F');
    cat1.set_age(1);

    cout<<"Name : "<<cat1.get_name()<<endl;
    cout<<"Gender : "<<cat1.get_gender()<<endl;
    cout<<"Age : "<<cat1.get_age()<<" years old"<<endl;
}