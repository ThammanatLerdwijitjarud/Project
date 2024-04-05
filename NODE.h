#include <iostream>
#include <string>
using namespace std;

class Animal {
    private:
        string name, color;
        char gender;
        int age, weight;
    public:
        // string find_color(string); //use sorting
        // string set_color(string);
        // string get_color();
        Animal(string = "noname", char = 'F', int = 1, int = 5);
        string get_name();
        char get_gender();
        int get_age();
        void display();
};

class cat : public Animal{
private :
    int no_cat=0;
public:
    cat(string,char,int,int);
};

class dog : public Animal{
private:
    int no_dog=0;
public:
    dog(string,char,int,int);
};

Animal::Animal(string n, char g, int a, int w)
{
    name = n;
    gender = g;
    age = a;
    cout<<"Create animal"<<endl;
}


cat::cat(string n,char g, int a ,int w) : Animal(n,g,a,w)
{
    no_cat++;
    cout<<"Number of cat = "<<no_cat<<endl;
}


dog::dog(string n,char g, int a ,int w) : Animal(n,g,a,w)
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

void Animal::display()
{
    cout<<"Name : "<<get_name()<<endl;
    cout<<"Gender : "<<get_gender()<<endl;
    cout<<"Age : "<<get_age()<<" years old"<<endl;
}


