#include <iostream>
#include "NODE.h"
using namespace std;

Animal::Animal(string n, string g, int a, int w)
{
    name = n;
    gender = g;
    age = a;
    cout<<"Create animal"<<endl;
}


cat::cat(string n,string g, int a ,int w) : Animal(n,g,a,w)
{
    no_cat++;
    cout<<"Number of cat = "<<no_cat<<endl;
}


dog::dog(string n,string g, int a ,int w) : Animal(n,g,a,w)
{
    no_dog++;
    cout<<"Number of dog = "<<no_dog<<endl;
}


string Animal::get_name()
{
    return name;
}

char Animal::get_gender()
{
    return gender;
}

int Animal::get_age()
{
    return age;
}

void Animal::show_node()
{   
    cout<<"-------------------------"<<endl;
    cout<<"Name : "<<get_name()<<endl;
    cout<<"Gender : "<<get_gender()<<endl;
    cout<<"Age : "<<get_age()<<" years old"<<endl;
}