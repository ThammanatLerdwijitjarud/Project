#include <iostream>
#include <string>
using namespace std;

class Animal {
    private:
        string name, color;
        char gender;
        int age;
    public:
        // string find_color(string); //use sorting
        // string set_color(string);
        // string get_color();
        void set_name(string);
        string get_name();
        void set_gender(char);
        char get_gender();
        void set_age(int);
        int get_age();

};

class cat : public Animal{
public:
    cat() {
        cout<<"Create Cat"<<endl;
    }
};

class dog : public Animal{
public:
    dog() {
        cout<<"Create Dog"<<endl;
    }
};

void Animal::set_name(string n)
{
    name = n;
}

string Animal::get_name()
{
    return name;
}

void Animal::set_gender(char g)
{
    gender = g;
}

char Animal::get_gender()
{
    return gender;
}

void Animal::set_age(int a)
{
    age = a;
}

int Animal::get_age()
{
    return age;
}

